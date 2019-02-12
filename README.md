## Demo
Include logo/demo screenshot etc.

## Muscle Sensor LED Display
This micro-controller project detects muscle contractions and displays it on to a 32x32 LED screen. The harder you contract your muscle, the larger the wave! Any large enough muscle is compatible, such as the biceps, forearms, or even forehead muscles!

## Motivation
The MyoWare Muscle Sensor. 
A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.
 
## Materials
The schematic and board files were designed for the Atmega164p and the SPX-14633 32x32 LED screen. Another microcontroller can be used, and this schematic should make a good reference. Because of the fast clock and refresh rate needed to drive the 32x32 LED screen, I would  recommend using a micro controller with a 1 MHz processor and higher. An optional RS-232 serial interface is included for debugging and JTAG interface for on-board programming of the Atmega 164P.

Muscle Sensor
* MyoWare Muscle Sensor  ($37.95)        https://www.adafruit.com/product/2699
* Surface EMG Electrodes ($4.95)         adafruit.com/product/2773
* 1x3 Pinhead

Atmega164p ($3.79): 	                    microchip.com/wwwproducts/en/ATmega164P

32x32 LED Panel- 1:8 scan rate ($14.95): sparkfun.com/products/14633
* 2x8 Pinhead

UART Debugging (optional):
* RS-232 serial interface
* Max232            

On-board Programming (optional):
* Any JTAG programmer to program micro controller
* 2x5 Pinhead

Buttons: 2

Capacitors: 

Power:
* 7805 voltage regulator
* 9-Volt Battery
* Barrel connector

## Code
The algorithm C code does not use any libraries, besides avr/io. Using adafruit's libraries, the slowest processor that can adequately run the 32x32 matrix is 16MHz ([32x32 LED Matrix](https://www.sparkfun.com/products/retired/14633)). By avoiding the libraries and driving each pin directly, the LED matrix can be adequately driven on a 1 MHz processor (atmega164p).

## Installation
Check out my youtube video for some step-by-step instructions 👌:

https://youtu.be/R8VW5WCSrXk

[Myoware muscle sensor set-up](https://learn.adafruit.com/getting-started-with-myoware-muscle-sensor)

[Matrix hook-up guide](https://learn.sparkfun.com/tutorials/rgb-panel-hookup-guide)

## How it works:

[1:8 Scan rate panels](https://www.sparkfun.com/sparkx/blog/2650)

## How to use?
If people like your project they’ll want to learn how they can use it. To do so include step by step guide to use your project.

#### Anything else that seems useful

## License
A short snippet describing the license (MIT, Apache etc)

MIT © [Jonbat]()
