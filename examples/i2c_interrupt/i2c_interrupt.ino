#include <Dps368.h>

// Dps368 Opject
Dps368 Dps368PressureSensor = Dps368();

void onFifoFull();

const unsigned char pressureLength = 50;
unsigned char pressureCount = 0;
float  pressure[pressureLength];
unsigned char temperatureCount = 0;
const unsigned char temperatureLength = 50;
float temperature[temperatureLength];



void setup()
{
  Serial.begin(9600);
  while (!Serial);

  //Call begin to initialize Dps368PressureSensor
  //The parameter 0x76 is the bus address. The default address is 0x77 and does not need to be given.
  //Dps368PressureSensor.begin(Wire, 0x76);
  //Use the commented line below instead to use the default I2C address.
  Dps368PressureSensor.begin(Wire);
  
  //int16_t ret = Dps368PressureSensor.setInterruptPolarity(1);
  int16_t ret = Dps368PressureSensor.setInterruptSources(1, 0);
  //clear interrupt flag by reading
  Dps368PressureSensor.getIntStatusFifoFull();

  //initialization of Interrupt for Controller unit
  //SDO pin of Dps368 has to be connected with interrupt pin
  int16_t interruptPin = 3;
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), onFifoFull, RISING);

  //start of a continuous measurement just like before
  int16_t temp_mr = 3;
  int16_t temp_osr = 2;
  int16_t prs_mr = 1;
  int16_t prs_osr = 3;
  ret = Dps368PressureSensor.startMeasureBothCont(temp_mr, temp_osr, prs_mr, prs_osr);
  if (ret != 0)
  {
    Serial.print("Init FAILED! ret = ");
    Serial.println(ret);
  }
  else
  {
    Serial.println("Init complete!");
  }
}


void loop()
{
  //do other stuff
  Serial.println("loop running");
  delay(500);


  //if result arrays are full
  //This could also be in the interrupt handler, but it would take too much time for a proper ISR
  if (pressureCount == pressureLength && temperatureCount == temperatureLength)
  {
    //print results
    Serial.println();
    Serial.println();
    Serial.print(temperatureCount);
    Serial.println(" temperature values found: ");
    for (int16_t i = 0; i < temperatureCount; i++)
    {
      Serial.print(temperature[i]);
      Serial.println(" degrees of Celsius");
    }
    Serial.println();
    Serial.print(pressureCount);
    Serial.println(" pressure values found: ");
    for (int16_t i = 0; i < pressureCount; i++)
    {
      Serial.print(pressure[i]);
      Serial.println(" Pascal");
    }
    Serial.println();
    Serial.println();
    //reset result counters
    pressureCount = 0;
    temperatureCount = 0;
  }
}


//interrupt handler
void onFifoFull()
{
  //message for debugging
  Serial.println("Interrupt handler called");

  //clear interrupt flag by reading
  Dps368PressureSensor.getIntStatusFifoFull();

  //calculate the number of free indexes in the result arrays
  uint8_t prs_freespace = pressureLength - pressureCount;
  uint8_t temp_freespace = temperatureLength - temperatureCount;
  //read the results from Dps368, new results will be added at the end of the arrays
  Dps368PressureSensor.getContResults(&temperature[temperatureCount], temp_freespace, &pressure[pressureCount], prs_freespace);
  //after reading the result counters are increased by the amount of new results
  pressureCount += prs_freespace;
  temperatureCount += temp_freespace;
}
