/* 
 * File:   ecu_dc_motor.h
 * Author: Asem
 *
 * Created on January 24, 2024, 4:32 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*section : includes*/
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*section : macro declarations*/
#define motor_on_status 0x01U
#define motor_off_status 0x00U
/*section : macro functions*/

/*section : data type declarartion*/
//typedef struct{
//    unsigned dc_motor_port:4;
//    unsigned dc_motor_pin:3;
//    unsigned dc_motor_status:1;
//}dc_motor_pin_t;

typedef struct{
    pin_config dc_motor_pin[2];//because it needs two pins to connect motor to microcontroller
    //we used pin config to directly define whatever things in motor
}dc_motor_t;
/*section :functions declaration*/
std_returntype dc_motor_initialize(const dc_motor_t *dc_motor);
std_returntype dc_motor_move_right(const dc_motor_t *dc_motor);
std_returntype dc_motor_move_left(const dc_motor_t *dc_motor);
std_returntype dc_motor_stop(const dc_motor_t *dc_motor);
#endif	/* ECU_DC_MOTOR_H */

