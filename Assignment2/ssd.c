/*
 * ssd.c
 *
 * Created: 17-10-2025 11:10:38 AM
 *  Author: brand
 */ 
#include "ssd.h"
#include <stdlib.h>

static const uint8_t digit[10] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111
};

static const uint8_t mode[]{
	0b01110011,
	0b01111100,
	0b01111001,
	0b01011110	
};


void ssd_init(void){
	DDRA = 0xFF;
	PORTA = 0x00;
}

void ssd_show(uint8_t time){
	uint8_t pattern = 0x00;
	if(time < 10) pattern = digit[time];
	PORTA = pattern;
}

void ssd_clear(void){
	PORTA = 0x00;
}

