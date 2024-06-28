/* 
 * File:   ecu_7_segment.h
 * Author: Asem
 *
 * Created on January 28, 2024, 4:00 PM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H
/*section : includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_7_seg_cfg.h"
/*section : macro declarations*/

/*section : macro functions*/

/*section : data type declarartion*/
typedef enum{
    segment_common_anode,segment_common_cathode
}segment_type_t;
typedef struct{
    pin_config segment_pins[4]; 
    segment_type_t sement_type;
}segment_t;
/*section :functions declaration*/
std_returntype seven_segment_initialize(const segment_t *seg);
std_returntype seven_segment_write_number(const segment_t *seg,uint8 number);
#endif	/* ECU_7_SEGMENT_H */

