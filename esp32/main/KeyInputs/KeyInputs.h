#ifndef KEYINPUTS_H
#define KEYINPUTS_H

#include "../common.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"


//LEFT_HAND_KEYS_PINOUT 35, 36, 37, 38, 39, 40, 41
#define LEFT_HAND_SHIFT 35
#define LEFT_HAND_SIZE 7

//RIGHT_HAND_KEYS_PINOUT 13, 14, 15, 16, 17, 18
#define RIGHT_HAND_SHIFT 13
#define RIGHT_HAND_SIZE 6

void init_keyboard();
uint32_t update_keyboard();


#endif