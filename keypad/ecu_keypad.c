/* 
 * File:   ecu_keypad.c
 * Author: Asem
 *
 * Created on January 28, 2024, 6:45 PM
 */
#include "ecu_keypad.h"
#define _XTAL_FREQ 8000000UL
static const uint8 btn_values[ecu_keypad_row][ecu_keypad_column]={
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'}
};
/**
 * 
 * @param keypad_obj
 * @return 
 */
std_returntype keypad_initialize(const keypad_t *keypad_obj){
    std_returntype ret=E_OK;
    uint8 rows_counter=0,columns_counter=0;
    if(NULL==keypad_obj){
        ret=E_NOT_OK;
    }else{
        for(rows_counter=0;rows_counter<ecu_keypad_row;rows_counter++){
            ret=gpio_pin_initilaize(&(keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter=0;columns_counter<ecu_keypad_column;columns_counter++){
            ret=gpio_pin_direction_initilaize(&(keypad_obj->keypad_column_pins[columns_counter]));
        }
    }
    return ret;
}
/**
 * 
 * @param keypad_obj
 * @param value
 * @return 
 */
std_returntype keypad_get_value(const keypad_t *keypad_obj,uint8 *value){
    std_returntype ret=E_OK;
    uint8 lrows_counter=0,lcolumns_counter=0,l_counter=0;
    _logic column_logic=low;
    if(NULL==keypad_obj || NULL==value){
        ret=E_NOT_OK;
    }else{
        for(lrows_counter=0;lrows_counter<ecu_keypad_row;lrows_counter++){
            for(l_counter=0;l_counter<ecu_keypad_row;l_counter++){
                ret=gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[l_counter]),low);                                              
            }
            gpio_pin_write_logic (&(keypad_obj->keypad_row_pins[lrows_counter]),high);
            __delay_ms(50);
            for(lcolumns_counter=0;lcolumns_counter<ecu_keypad_column;lcolumns_counter++){
                ret=gpio_pin_read_logic(&(keypad_obj->keypad_column_pins[lcolumns_counter]),&column_logic); 
                if(high==column_logic){
                    *value=btn_values[lrows_counter][lcolumns_counter];
                }
            }
            
        }
    }
    return ret;
}