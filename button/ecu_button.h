/* 
 * File:   ecu_button.h
 * Author: Asem
 *
 * Created on December 18, 2023, 10:45 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*section : includes*/
#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*section : macro declarations*/

/*section : macro functions*/

/*section : data type declarartion*/
typedef enum{
    button_pressed,button_released
}button_state_t;


typedef enum{
    button_active_high,button_active_low
}button_active_t;
typedef struct{
    pin_config button_pin;
    button_state_t buttonstate;
    button_active_t buttonconnection;
}button_t;
std_returntype button_initialize(const button_t *btn);
std_returntype button_read_state(const button_t *btn,button_state_t *btnstate);//to know state

/*section :functions declaration*/
#endif	/* ECU_BUTTON_H */

