/* 
 * File:   ecu_7_segment.c
 * Author: Asem
 *
 * Created on January 28, 2024, 4:00 PM
 */
#include "ecu_7_segment.h"

std_returntype seven_segment_initialize(const segment_t *seg){
    std_returntype ret=E_OK;
    if(NULL==seg){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_initilaize(&(seg->segment_pins[0]));
        ret=gpio_pin_initilaize(&(seg->segment_pins[1]));
        ret=gpio_pin_initilaize(&(seg->segment_pins[2]));
        ret=gpio_pin_initilaize(&(seg->segment_pins[3]));
    }
    return ret;
}
std_returntype seven_segment_write_number(const segment_t *seg,uint8 number){
    std_returntype ret=E_OK;
    if((NULL==seg)&& (number<10)){
        ret=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&(seg->segment_pins[0]), number & 0x01);//so like that we reach first pin and write on it logic as what is in number
        gpio_pin_write_logic(&(seg->segment_pins[1]), (number>>1) & 0x01);// like tah we shifted so that it reached to first bit and know loic on it
        gpio_pin_write_logic(&(seg->segment_pins[2]), (number>>2) & 0x01);
        gpio_pin_write_logic(&(seg->segment_pins[3]), (number>>3) & 0x01);
    }
    return ret;
}