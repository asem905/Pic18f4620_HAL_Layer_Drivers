/* 
 * File:   ecu_relay.c
 * Author: Asem
 *
 * Created on January 15, 2024, 6:14 PM
 */
#include "ecu_relay.h"

std_returntype relay_initialize(const relay_t *_relay){
     std_returntype ret=E_OK;
    if(NULL==_relay){
        ret=E_NOT_OK;
    }else{
         pin_config pin_obj={.port=_relay->relay_port,.pin=_relay->relay_pin,.logic=_relay->relay_status,.direction=gpio_Direction_output};
         gpio_pin_initilaize(&pin_obj);
    }
    return ret;
}

std_returntype relay_turn_on(const relay_t *_relay){
     std_returntype ret=E_OK;
    if(NULL==_relay){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=_relay->relay_port,.pin=_relay->relay_pin,.logic=_relay->relay_status,.direction=gpio_Direction_output};
        gpio_pin_write_logic(&pin_obj,high);
    }
    return ret;
}

std_returntype relay_turn_off(const relay_t *_relay){
     std_returntype ret=E_OK;
    if(NULL==_relay){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=_relay->relay_port,.pin=_relay->relay_pin,.logic=_relay->relay_status,.direction=gpio_Direction_output};
        gpio_pin_write_logic(&pin_obj,low);
    }
    return ret;
}