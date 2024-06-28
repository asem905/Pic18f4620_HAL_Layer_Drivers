/* 
 * File:   ecu_lcd.h
 * Author: Asem
 *
 * Created on January 31, 2024, 6:04 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*section : includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_lcd_cfg.h"

/*section : macro declarations*/
#define _lcd_clear 0x01
#define _lcd_return_home 0x02
#define _lcd_entry_mode 0x06
#define _lcd_cursor_off_display_on 0x0C
#define _lcd_cursor_off_display_off 0x08
#define _lcd_cursor_on_blink_on 0x0F
#define _lcd_cursor_on_blink_off 0x0E
#define _lcd_display_shift_right 0x1C
#define _lcd_display_shift_left 0x18
#define _lcd_8bit_mode_2_line 0x38
#define _lcd_4bit_mode_2_line 0x28
#define _lcd_cgram_start 0x40
#define _lcd_ddram_start 0x80
/*section : macro functions*/

/*section : data type declarartion*/
typedef struct{
    pin_config lcd_rs;
    pin_config lcd_en;
    pin_config lcd_data[4];
}chr_lcd_4bit_t;
typedef struct{
    pin_config lcd_rs;
    pin_config lcd_en;
    pin_config lcd_data[8];
}chr_lcd_8bit_t;
/*section :functions declaration*/
std_returntype lcd_4bit_initialize(const chr_lcd_4bit_t *lcd);
std_returntype lcd_4bit_send_command(const chr_lcd_4bit_t *lcd,uint8 command);
std_returntype lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd,uint8 data);
std_returntype lcd_4bit_send_char_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,uint8 data);
std_returntype lcd_4bit_send_string(const chr_lcd_4bit_t *lcd,uint8 *str);
std_returntype lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,uint8 *str);
std_returntype lcd_4bit_send_custome_char(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,const uint8 _char[],uint8 mem_pos);

std_returntype lcd_8bit_initialize(const chr_lcd_8bit_t *lcd);
std_returntype lcd_8bit_send_command(const chr_lcd_8bit_t *lcd,uint8 command);
std_returntype lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd,uint8 data);
std_returntype lcd_8bit_send_char_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,uint8 data);
std_returntype lcd_8bit_send_string(const chr_lcd_8bit_t *lcd,uint8 *str);
std_returntype lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,uint8 *str);
std_returntype lcd_8bit_send_custome_char(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,const uint8 _char[],uint8 mem_pos);

std_returntype convert_byte_to_string(uint8 value,uint8 *str);
std_returntype convert_short_to_string(uint16 value,uint8 *str);
std_returntype convert_int_to_string(uint32 value,uint8 *str);
#endif	/* ECU_LCD_H */

