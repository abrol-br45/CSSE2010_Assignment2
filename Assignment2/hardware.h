/*
 * hardware.h
 *
 * Created: 17-10-2025 10:45:16 AM
 *  Author: brand
 */ 


#ifndef HARDWARE_H
#define HARDWARE_H
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

void hardware_init(void);
uint8_t read_mode_switch(void);
bool button_pressed(uint8_t pin);
void update_mode(uint8_t mode);
void update_power(uint8_t level);

#endif /* HARDWARE_H */