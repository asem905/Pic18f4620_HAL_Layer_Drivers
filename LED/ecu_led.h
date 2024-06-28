

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ECU_LED_H
#define	ECU_LED_H
/*section : includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/*section : macro declarations*/

/*section : macro functions*/

/*section : data type declarartion*/
typedef enum{
    led_off,led_on
}led_status;


typedef struct{
    unsigned port_name: 4;
    unsigned pin:3;
    unsigned led_status:1;
}led_t;
/*section :functions declaration*/
std_returntype led_initialize(const led_t *led);
std_returntype led_turn_on(const led_t *led);
std_returntype led_turn_off(const led_t *led);
std_returntype led_turn_toggle(const led_t *led);
#endif	/* ECU_LED_H */

