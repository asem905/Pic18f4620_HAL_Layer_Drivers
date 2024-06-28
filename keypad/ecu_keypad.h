/* 
 * File:   ecu_keypad.h
 * Author: Asem
 *
 * Created on January 28, 2024, 6:44 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*section : includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"
/*section : macro declarations*/
#define ecu_keypad_row 4
#define ecu_keypad_column 4
/*section : macro functions*/

/*section : data type declarartion*/
typedef struct{
    pin_config keypad_row_pins[ecu_keypad_row];
    pin_config keypad_column_pins[ecu_keypad_column];
}keypad_t;
/*section :functions declaration*/
std_returntype keypad_initialize(const keypad_t *keypad_obj);
std_returntype keypad_get_value(const keypad_t *keypad_obj,uint8 *value);
#endif	/* ECU_KEYPAD_H */

