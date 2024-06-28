/* 
 * File:   ecu_layer_init.c
 * Author: Asem
 *
 * Created on January 29, 2024, 4:14 PM
 */
#include "ecu_layer_init.h"
//#define _XTAL_FREQ 4000000UL
//keypad_t keypad1={
//    .keypad_row_pins[0].port=portc_index,
//    .keypad_row_pins[0].direction=gpio_Direction_output,
//    .keypad_row_pins[0].pin=pin0,
//    .keypad_row_pins[0].logic=low,
//    .keypad_row_pins[1].port=portc_index,
//    .keypad_row_pins[1].direction=gpio_Direction_output,
//    .keypad_row_pins[1].pin=pin1,
//    .keypad_row_pins[1].logic=low,
//    .keypad_row_pins[2].port=portc_index,
//    .keypad_row_pins[2].direction=gpio_Direction_output,
//    .keypad_row_pins[2].pin=pin2,
//    .keypad_row_pins[2].logic=low,
//    .keypad_row_pins[3].port=portc_index,
//    .keypad_row_pins[3].direction=gpio_Direction_output,
//    .keypad_row_pins[3].pin=pin3,
//    .keypad_row_pins[3].logic=low,
//    .keypad_column_pins[0].port=portc_index,
//    .keypad_column_pins[0].direction=gpio_Direction_input,
//    .keypad_column_pins[0].pin=pin4,
//    .keypad_column_pins[0].logic=low,
//    .keypad_column_pins[1].port=portc_index,
//    .keypad_column_pins[1].direction=gpio_Direction_input,
//    .keypad_column_pins[1].pin=pin5,
//    .keypad_column_pins[1].logic=low,
//    .keypad_column_pins[2].port=portc_index,
//    .keypad_column_pins[2].direction=gpio_Direction_input,
//    .keypad_column_pins[2].pin=pin6,
//    .keypad_column_pins[2].logic=low,
//    .keypad_column_pins[3].port=portc_index,
//    .keypad_column_pins[3].direction=gpio_Direction_input,
//    .keypad_column_pins[3].pin=pin7,
//    .keypad_column_pins[3].logic=low
//};

//led_t led10={.port_name=portd_index,.pin=pin0,.led_status=high};

chr_lcd_4bit_t lcd_1={
    .lcd_rs.port=portc_index,
    .lcd_rs.pin=pin0,
    .lcd_rs.direction=gpio_Direction_output,
    .lcd_rs.logic=low,
    .lcd_en.port=portc_index,
    .lcd_en.pin=pin1,
    .lcd_en.direction=gpio_Direction_output,
    .lcd_en.logic=low,
    .lcd_data[0].port=portc_index,
    .lcd_data[0].pin=pin2,
    .lcd_data[0].direction=gpio_Direction_output,
    .lcd_data[0].logic=low,
    .lcd_data[1].port=portc_index,
    .lcd_data[1].pin=pin3,
    .lcd_data[1].direction=gpio_Direction_output,
    .lcd_data[1].logic=low,
    .lcd_data[2].port=portc_index,
    .lcd_data[2].pin=pin4,
    .lcd_data[2].direction=gpio_Direction_output,
    .lcd_data[2].logic=low,
    .lcd_data[3].port=portc_index,
    .lcd_data[3].pin=pin5,
    .lcd_data[3].direction=gpio_Direction_output,
    .lcd_data[3].logic=low,
};
chr_lcd_8bit_t lcd_2={
    .lcd_rs.port=portc_index,
    .lcd_rs.pin=pin6,
    .lcd_rs.direction=gpio_Direction_output,
    .lcd_rs.logic=low,
    .lcd_en.port=portc_index,
    .lcd_en.pin=pin7,
    .lcd_en.direction=gpio_Direction_output,
    .lcd_en.logic=low,
    .lcd_data[0].port=portd_index,
    .lcd_data[0].pin=pin0,
    .lcd_data[0].direction=gpio_Direction_output,
    .lcd_data[0].logic=low,
    .lcd_data[1].port=portd_index,
    .lcd_data[1].pin=pin1,
    .lcd_data[1].direction=gpio_Direction_output,
    .lcd_data[1].logic=low,
    .lcd_data[2].port=portd_index,
    .lcd_data[2].pin=pin2,
    .lcd_data[2].direction=gpio_Direction_output,
    .lcd_data[2].logic=low,
    .lcd_data[3].port=portd_index,
    .lcd_data[3].pin=pin3,
    .lcd_data[3].direction=gpio_Direction_output,
    .lcd_data[3].logic=low,
    .lcd_data[4].port=portd_index,
    .lcd_data[4].pin=pin4,
    .lcd_data[4].direction=gpio_Direction_output,
    .lcd_data[4].logic=low,
    .lcd_data[5].port=portd_index,
    .lcd_data[5].pin=pin5,
    .lcd_data[5].direction=gpio_Direction_output,
    .lcd_data[5].logic=low,
    .lcd_data[6].port=portd_index,
    .lcd_data[6].pin=pin6,
    .lcd_data[6].direction=gpio_Direction_output,
    .lcd_data[6].logic=low,
    .lcd_data[7].port=portd_index,
    .lcd_data[7].pin=pin7,
    .lcd_data[7].direction=gpio_Direction_output,
    .lcd_data[7].logic=low
};
void ecu_layer_initialize(void){
    std_returntype ret=E_NOT_OK;
//    ret=keypad_initialize(&keypad1);
//    ret=led_initialize(&led10);
    ret=lcd_4bit_initialize(&lcd_1);
    ret=lcd_8bit_initialize(&lcd_2);
}