/* 
 * File:   ecu_button.c
 * Author: Asem
 *
 * Created on December 18, 2023, 10:45 PM
 */
#include "ecu_button.h"

std_returntype button_initialize(const button_t *btn){
    std_returntype ret=E_OK;
    if(NULL==btn){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_direction_initilaize(&(btn->button_pin));
    }
    return ret;
}
std_returntype button_read_state(const button_t *btn,button_state_t *btnstate){
    std_returntype ret=E_OK;
    _logic pin_logic_status=low;
    if(NULL==btn || NULL== btnstate){
        ret=E_NOT_OK;
    }else{
        gpio_pin_read_logic(&(btn->button_pin),&pin_logic_status);//he takes btn->button_pin because parameter og this function takes type pin_config
        if(button_active_high == btn->buttonconnection){
           if(high==pin_logic_status){
               *btnstate=button_pressed;
           }else{
               *btnstate=button_released;
           } 
        }else if(button_active_low == btn->buttonconnection){
            if(high==pin_logic_status){
               *btnstate=button_released;
           }else{
               *btnstate=button_pressed;
           } 
        }else{
            /* nothing */
        }
        ret=E_OK;
    }
    return ret;
}