/* 
 * File:   ecu_dc_motor.c
 * Author: Asem
 *
 * Created on January 24, 2024, 4:32 PM
 */
#include "ecu_dc_motor.h"
// here we made global static but then we remove as if two motors second overwrite first
std_returntype dc_motor_initialize(const dc_motor_t *dc_motor){
    std_returntype ret=E_OK;
    if(NULL==dc_motor){
        ret=E_NOT_OK;
    }else{
        //here was every thing concern first pin global i had made 
        gpio_pin_initilaize(&(dc_motor->dc_motor_pin[0]));
        gpio_pin_initilaize(&(dc_motor->dc_motor_pin[1]));
    }
    return ret;
}
std_returntype dc_motor_move_right(const dc_motor_t *dc_motor){
    std_returntype ret=E_OK;
    if(NULL==dc_motor){
        ret=E_NOT_OK;
    }else{
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),high);
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),low);
    }
    return ret;
}
std_returntype dc_motor_move_left(const dc_motor_t *dc_motor){
    std_returntype ret=E_OK;
    if(NULL==dc_motor){
        ret=E_NOT_OK;
    }else{
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),low);
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),high);
    }
    return ret;
}
std_returntype dc_motor_stop(const dc_motor_t *dc_motor){
    std_returntype ret=E_OK;
    if(NULL==dc_motor){
        ret=E_NOT_OK;
    }else{
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),low);
         gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),low);
    }
    return ret;
}