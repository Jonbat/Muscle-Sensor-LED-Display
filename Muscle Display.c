/*
 * Muscle Sensor.c
 *
 * Created: 12/6/2018 10:24:02 AM
 * Author : Jonathan Batchelder
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define DATAPORT PORTA
#define CLK PB4
#define OE  PB6
#define LAT PB5
#define A  PB0
#define B  PB1
#define C  PB2

#define R1 PA2
#define R2 PA5
#define G1 PA3
#define G2 PA6 
#define B1 PA4
#define B2 PA7

void matrix_init () {
	DDRA = 0xFC;  		// all bits outputs, except PA0 (sensor) and PA1 (unused)
	DDRB = 0xFF;
	PORTA = (1 << PA0);	// pull-up resistor
}

void ADC_init () {
	ADCSRA = (1 << ADEN);    				// enable ADC
	ADCSRA |= (1 << ADATE) | (1 << ADSC);   // start conversation
	ADMUX = (1 << REFS0);
}

uint16_t ReadADC() {
	uint8_t LS_data = ADCL; 
	uint8_t MS_data = ADCH;
	uint16_t adc_data = (MS_data << 8) | LS_data;
	return adc_data;
}


int main(void) {
	uint8_t C1 = B1;		// blue on default
	uint8_t C2 = B2;
	uint8_t addramask = ~(1 << A);
	uint8_t addrbmask = ~(1 << B);
	uint8_t addrcmask = ~(1 << C);
	matrix_init();
	ADC_init();
	
	uint16_t wave_multiplier;
	uint8_t row = 8;				   		// keep track of which row
	
	while (1) {
		uint16_t wave_val = ReadADC() / 2;	// currently configured for 0 - 1696
		for (int row_line = 8; row_line > 0; row_line--) {

			for (int i = 63; i > -1; i--) { // Display needed to be flipped: for (int i = 0; i < 64; i++) 

				DATAPORT &= ~(1 << C1);
				DATAPORT &= ~(1 << C2);
				 
				//  1010 (Display Algorithm)
				if (i >= 16 && i <= 47) {    // 1000
					if ( wave_val > ( (i - 16) * row_line ) ) {
						DATAPORT |= (1 << C2);
					} 					     // 0010
					if ( wave_val > ( (i - 16) * (row_line + 18) ) ) {
						DATAPORT |= (1 << C1);
					}
				}
				// 0101
				else {
					if ( i > 47 ) {
						wave_multiplier = i - 32;
					} else {
						wave_multiplier = i;
					}						// 0100
					if ( wave_val > (wave_multiplier * (row_line + 8)) ) {
						DATAPORT |= (1 << C2);
					}						// 0001
					if ( wave_val > ( wave_multiplier * (row_line + 24)) ) {
						DATAPORT |= (1 << C1);
					}
				}
				PORTB &= ~(1 << CLK); // tick, clock lo
				PORTB |= (1 << CLK);  // tock, clock hi
			}
			// Update row
			if (++row >= 8) {		  // reset row to 0 every 8 times
				row = 0;
			}
			
			PORTB |= (1 << OE);		 // disable output when loading
			PORTB |= (1 << LAT);     // latch data loaded
			
			// next row
			if(row & 0x1)   PORTB |= (1 << A);
			else          	PORTB &= addramask;   
			if(row & 0x2)   PORTB |= (1 << B);
			else            PORTB &= addrbmask;
			if(row & 0x4)   PORTB |= (1 << C);
			else            PORTB &= addrcmask;
			
			PORTB &= ~(1 << OE);	// output enabled
			PORTB &= ~(1 << LAT);	// latch down, ready for more
		}
	}
}
