## Demo
Include logo/demo screenshot etc.

## Muscle Sensor LED Display
This micro-controller project detects muscle contractions and displays it on to a 32x32 LED screen. The harder you contract your muscle, the larger the wave! Any large enough muscle is compatible, such as the biceps, forearms, or even forehead muscles!

## Motivation
The MyoWare Muscle Sensor. 
A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.
 
## Tech/framework used
## Materials
The schematic and board files were made to work with the Atmega164p and the SPX-14633 32x32 LED screen. Another microcontroller can be used, and the schematic should make a good reference. Because of the fast clock and refresh rate needed to drive the 32x32 LED screen, I would not use a micro controller any slower than the atmega164p (1 MHz). A RS-232 serial interface is included for debugging and a JTAG interface is included for programming of the Atmega 164P.
In fact, the ATmega328 would be optimal for this project.

Muscle Sensor:      sparkfun.com/products/13723

Atmega164p: 	   microchip.com/wwwproducts/en/ATmega164P

32x32 LED Panel: 	    sparkfun.com/products/retired/14633

Debugging (optional):
* RS-232 serial interface:
* Max232:                   digikey.com/product-detail/en/texas-instruments/MAX232N/296-1402-5-ND/277048
On-board Programming:
* 2x5 Pinhead

<b>Built with</b>
- [Electron](https://electron.atom.io)

## Features
What makes your project stand out?

## Code Example
Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Installation
Provide step by step series of examples and explanations about how to get a development env running.
This 


## API Reference

Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.

## How to use?
If people like your project they’ll want to learn how they can use it. To do so include step by step guide to use your project.

#### Anything else that seems useful

## License
A short snippet describing the license (MIT, Apache etc)

MIT © [Yourname]()
