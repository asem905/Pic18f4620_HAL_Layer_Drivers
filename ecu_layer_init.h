/* 
 * File:   ecu_layer_init.h
 * Author: Asem
 *
 * Created on January 29, 2024, 4:14 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/*section : includes*/
#include "LED/ecu_led.h"
#include "../MCAL_Layer/GPIO/hal_gpio.h"
#include "button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "7_segment/ecu_7_segment.h"
#include "keypad/ecu_keypad.h"
#include "lcd/ecu_lcd.h"

/*section : macro declarations*/
//#define _XTAL_FREQ 8000000UL
/*section : macro functions*/

/*section : data type declarartion*/

/*section :functions declaration*/
void ecu_layer_initialize(void);
#endif	/* ECU_LAYER_INIT_H */

