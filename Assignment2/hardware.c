/*
 * hardware.c
 *
 * Created: 17-10-2025 10:55:25 AM
 *  Author: brand
 */ 

void hardware_init(void){
	DDRC = 0xFF; //LEDs
	PORTC = 0x00;
	
	DDRD &= ~((1<<PD2) | (1<<PD3)); //Switches
	PORTD |= (1<<PD2) | (1<<PD3);
	
	PORTB|= 0x0F; //buttons
}

uint8_t read_mode_switch(void){
	uint8_t s0 = (PIND & (1<<PD2))?0:1;
	uint8_t s1 = (PIND & (1<<PD3))?0:1;
	return (s1<<1)|s0;
}

bool button_pressed(uint8_t pin){
	static uint8_t prev = 0xFF;
	uint8_t curr = PIND;
	bool pressed = ((prev & (1<<pin)) && !(curr & (1<<pin)));
	prev = curr;
	return pressed;
}

void update_mode(uint8_t mode){
	PORTC = (PORTC 0xF0) | (1 << mode);
}

void update_power(uint8_t level){
	PORTC = (PORTC & 0x1F) | (level << 5);
}