# DPS368 Barometric Pressure Sensor 

[![Build Status](https://travis-ci.org/Infineon/DPS368-Library-Arduino.svg?branch=dps368)](https://travis-ci.org/Infineon/DPS368-Library-Arduino)

<img src="https://www.infineon.com/export/sites/default/media/products/Small_Signal_Discretes/lowres-DPS368_VLGA-8-2_Combi.tif.png_1864837327.png" width=150><img src="https://github.com/Infineon/Assets/blob/master/Pictures/DPS368-Pressure-Shield2Go_Top.jpg" width=300>

Library of Infineon's highly sensitive [DPS368 sensor](https://www.infineon.com/cms/en/product/sensor/barometric-pressure-sensor-for-consumer-applications/dps368/) for Arduino.
The DPS368 is an ultra small waterproof pressure sensor, environmentally protected against water (IPx8), dust & humidity.

## Summary

The [DPS368](https://www.infineon.com/cms/en/product/sensor/barometric-pressure-sensor-for-consumer-applications/dps368/) is a miniaturized digital barometric air pressure sensor with ultra-high precision (±2 cm) and a low current consumption, capable of measuring both pressure and temperature. Due to its robust package, it can withstand 50 m under water for one hour (IPx8). The pressure sensor element is based on a capacitive sensing principle which guarantees high precision during temperature changes. The small package (2.0 x 2.5 x 1.1 mm³) makes the DPS368 ideal for mobile applications and wearable devices. 

### Summary of Features:

* Package dimensions: 8-pin LGA, 2.0 x 2.5 x 1.1 mm³
* Operation range:
 * Pressure: 300–1200 hPa
 * Temperature: -40–85°C
* Precision: ± 0.002 hPa (or ±0.02 m)
* Rel. accuracy: ± 0.06 hPa (or ±0.5 m)
* Abs. accuracy: ± 1 hPa (or ±8 m)
* Temperature accuracy: ± 0.5°C
* Avg. current consumption: 1.7 µA (pressure measurement@1 Hz sampling rate, standby: 0.5 µA)
* Integrated FIFO
* Interface: I2C and SPI (both with optional interrupt)

### Benefits

* Fast, ultra-low noise read-out allows for precise measurement of altitude, air flow and body movements
* Small package size ideal for wearable devices & mobile applications
* Sensor can be used in harsh environment (water, dust & humidity)
* Environmentally resistant package facilitates handling in assembly line

### Target Applications

* Smart watches & wearables (e.g. fitness tracking)
* Smart phone (e.g. navigation)
* Home appliances (e.g. air flow control)
* Drones (e.g. flight stability)

## Installation

### Integration of Library

The master branch is always release ready; therefore, you can just download this library by downloading it from GitHub directly:

Please download this repository from GitHub by clicking on the above button `Clone or download` of this repository:

![Download Library](https://github.com/Infineon/Assets/blob/master/Pictures/Download_Repo.png)

To install the DPS368 pressure sensor library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **DPS368 Barometric Pressure Sensor**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please see the example sketches in the `/examples` directory in this library to learn more about the usage of the library. Especially, take care of the respective SPI and I²C configuration of the sensor. 
For more information, please consult the datasheet [here](https://www.infineon.com/dgdl/Infineon-DPS368-DS-v01_00-EN.pdf?fileId=5546d46269e1c019016a0c45105d4b40).

Currently, there exists the DPS368 Pressure Shield2Go evaluation board as a break out board:

* [DPS368 Pressure Shield2Go](https://www.infineon.com/cms/en/product/evaluation-boards/s2go-pressure-dps368)

### DPS368 Pressure Shield2Go
The DPS368 Pressure Shield2Go is a standalone break out board with Infineon's Shield2Go formfactor and pin out. You can connect it easily to any microcontroller of your choice which is Arduino compatible and has 3.3 V logic level (please note that the Arduino UNO has 5 V logic level and cannot be used without level shifting).
Please consult the [wiki](https://github.com/Infineon/DPS368-Library-Arduino/wiki) for additional details about the board.

Each sensor can only work either SPI or I2C. To convert from SPI to I2C, for example, you have to re-solder the resistors on the Shield2Go. Please take care that every Shield2Go for the DPS368 is shipped as I2C configuration right now.

* [Link](https://github.com/Infineon/DPS368-Library-Arduino/wiki) to the wiki with more information

However, every Shield2Go is directly compatible with Infineon's XMC2Go and the recommended quick start is to use an XMC2Go for evaluation. Therefore, please install (if not already done) also the [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) implementation and choose afterwards **XMC1100 XMC2Go** from the **Tools**>**Board** menu in the Arduino IDE if working with this evaluation board. To use it, please plug the DPS368 Pressure Shield2Go onto the XMC2Go as shown below.

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/DPS368_S2Go_w_XMC2Go.jpg" width=250>

### Additional Information
Please find the datasheet of the DPS368 [here](https://www.infineon.com/dgdl/Infineon-DPS368-DS-v01_00-EN.pdf?fileId=5546d46269e1c019016a0c45105d4b40). It depends on the evaluation board which you are using or the respective configuration of the sensor on your PCB which communication protocol as well as addresses you need to use for communicating with the sensor.
