/*
 * ssd.h
 *
 * Created: 17-10-2025 11:08:29 AM
 *  Author: brand
 */ 


#ifndef SSD_H
#define SSD_H
#include <stdint.h>

void ssd_init(void);
void ssd_show(char id, uint8_t time);
void ssd_clear(void);


#endif /* SSD_H */