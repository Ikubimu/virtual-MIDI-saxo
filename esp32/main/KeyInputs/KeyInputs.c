#include "KeyInputs.h"


//configute with pullup push buttons
void init_keyboard()
{
    uint64_t mask = 0;
    
    //left hand
    mask |= (((1ULL << LEFT_HAND_SIZE)- 1) << LEFT_HAND_SHIFT);

    //right hand
    mask |= (((1ULL << RIGHT_HAND_SIZE)- 1) << RIGHT_HAND_SHIFT);

    gpio_config_t io_conf = {
        .pin_bit_mask = mask,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);

}


uint32_t update_keyboard()
{

    static uint32_t left_mask = (((1ULL << LEFT_HAND_SIZE)- 1) << (LEFT_HAND_SHIFT-(uint32_t)32));
    static uint32_t right_mask = ((1ULL << RIGHT_HAND_SIZE)- 1) << RIGHT_HAND_SHIFT;

    uint32_t ret=0; 

    //right hand 
    ret |= (GPIO.in & right_mask) >> RIGHT_HAND_SHIFT;

    //left hand
    ret |= ((GPIO.in1.data & left_mask) >> (LEFT_HAND_SHIFT- (uint32_t)32)) << RIGHT_HAND_SIZE;

    // for (int i = 32 - 1; i >= 0; i--) {
    //     printf("%c", (ret & (1U << i)) ? '1' : '0');
    // }
    // printf("\n");

    return ret;
}