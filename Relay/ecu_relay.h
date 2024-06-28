/* 
 * File:   ecu_relay.h
 * Author: Asem
 *
 * Created on January 15, 2024, 6:14 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/*section : includes*/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*section : macro declarations*/
#define relay_on_status 0x01U
#define relay_off_status 0x00U
/*section : macro functions*/

/*section : data type declarartion*/
typedef struct{
    unsigned relay_port:4;
    unsigned relay_pin:3;
    unsigned relay_status:1;
}relay_t;
/*section :functions declaration*/
std_returntype relay_initialize(const relay_t *_relay);
std_returntype relay_turn_on(const relay_t *_relay);
std_returntype relay_turn_off(const relay_t *_relay);
#endif	/* ECU_RELAY_H */

