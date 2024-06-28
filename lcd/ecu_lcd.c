/* 
 * File:   ecu_lcd_cfg.h
 * Author: Asem
 *
 * Created on January 31, 2024, 6:04 PM
 */
#include "ecu_lcd.h"
static std_returntype lcd_send_4bits(const chr_lcd_4bit_t *lcd,uint8 _data_command){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_data[0]),(_data_command>>0)& (uint8)0x01);
        ret=gpio_pin_write_logic(&(lcd->lcd_data[1]),(_data_command>>1)& (uint8)0x01);
        ret=gpio_pin_write_logic(&(lcd->lcd_data[2]),(_data_command>>2)& (uint8)0x01);
        ret=gpio_pin_write_logic(&(lcd->lcd_data[3]),(_data_command>>3)& (uint8)0x01);
    }
    return ret;
}
static std_returntype lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_en),high);
        __delay_us(5);
        ret=gpio_pin_write_logic(&(lcd->lcd_en),low);
        
    }
    return ret;
}
static std_returntype lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_en),high);
        __delay_us(5);
        ret=gpio_pin_write_logic(&(lcd->lcd_en),low);
        
    }
    return ret;
}
std_returntype lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column){
     std_returntype ret=E_OK;
     column--;//we start from column zero at 0x80 address so 0x80+0 at column1
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        switch (row){
            case 1 :ret=lcd_8bit_send_command(lcd,(0x80+column));//we will send command about place as when we send this commnad through pins it goes to address counter to set where we are at
            break;
            case 2 :ret=lcd_8bit_send_command(lcd,(0xc0+column));
            break;
            case 3 :ret=lcd_8bit_send_command(lcd,(0x94+column));
            break;
            case 4 :ret=lcd_8bit_send_command(lcd,(0xd4+column));
            break;
            default:  ;
        } 
    }
    return ret;
}

std_returntype lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column){
     std_returntype ret=E_OK;
     column--;//we start from column zero at 0x80 address so 0x80+0 at column1
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        switch (row){
            case 1 :ret=lcd_4bit_send_command(lcd,(0x80+column));//we will send command about place as when we send this commnad through pins it goes to address counter to set where we are at
            break;
            case 2 :ret=lcd_4bit_send_command(lcd,(0xc0+column));
            break;
            case 3 :ret=lcd_4bit_send_command(lcd,(0x94+column));
            break;
            case 4 :ret=lcd_4bit_send_command(lcd,(0xd4+column));
            break;
            default:  ;
        } 
        
    }
    return ret;
}



std_returntype lcd_4bit_initialize(const chr_lcd_4bit_t *lcd){
    std_returntype ret=E_OK;
    uint8 l_data_pins_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_initilaize(&(lcd->lcd_rs));
        ret=gpio_pin_initilaize(&(lcd->lcd_en));
        for(l_data_pins_counter=0;l_data_pins_counter<4;l_data_pins_counter++){
            ret=gpio_pin_initilaize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);//this is in steps of making as after power on delay by more than 15ms
        ret=lcd_4bit_send_command(lcd,_lcd_8bit_mode_2_line);
        __delay_ms(5);
        ret=lcd_4bit_send_command(lcd,_lcd_8bit_mode_2_line);
        __delay_us(150);
        ret=lcd_4bit_send_command(lcd,_lcd_8bit_mode_2_line);
        
        ret=lcd_4bit_send_command(lcd,_lcd_clear);
        ret=lcd_4bit_send_command(lcd,_lcd_return_home);//cursor goes to first address as these are things happen inside datasheet of lcd so by sending this address it makes address counter becomes 0
        ret=lcd_4bit_send_command(lcd,_lcd_entry_mode);
        ret=lcd_4bit_send_command(lcd,_lcd_cursor_off_display_on);
        ret=lcd_4bit_send_command(lcd,_lcd_4bit_mode_2_line);
        ret=lcd_4bit_send_command(lcd,0x80);
    }
    return ret;
}

std_returntype lcd_4bit_send_command(const chr_lcd_4bit_t *lcd,uint8 command){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_rs),low);
        ret=lcd_send_4bits(lcd,command>>4);//here we send higher data bits first
        ret=lcd_4bit_send_enable_signal(lcd);
        ret=lcd_send_4bits(lcd,command);//here we send lower data bits
        ret=lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

std_returntype lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd,uint8 data){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_rs),high);
        ret=lcd_send_4bits(lcd,data>>4);//here we send higher data bits first
        ret=lcd_4bit_send_enable_signal(lcd);
        ret=lcd_send_4bits(lcd,data);//here we send lower data bits
        ret=lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

std_returntype lcd_4bit_send_char_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,uint8 data){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=lcd_4bit_set_cursor(lcd,row,column);
        ret=lcd_4bit_send_char_data(lcd,data);
    }
    return ret;
}

std_returntype lcd_4bit_send_string(const chr_lcd_4bit_t *lcd,uint8 *str){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        while(*str != NULL){
            ret=lcd_4bit_send_char_data(lcd,*str);
            str++;
        }
    }
    return ret;
}

std_returntype lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,uint8 *str){
    std_returntype ret=E_OK;
    
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=lcd_4bit_set_cursor(lcd,row,column);
        while(*str != NULL){
            ret=lcd_4bit_send_char_data(lcd,*str);
            str++;
        }
    }
    return ret;
}

std_returntype lcd_4bit_send_custome_char(const chr_lcd_4bit_t *lcd,uint8 row,uint8 column,const uint8 _char[],uint8 mem_pos){
    std_returntype ret=E_OK;
    uint8 lcd_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
         ret=lcd_4bit_send_command(lcd,(_lcd_cgram_start+(mem_pos*8)));//to move by 8bytes i want and here i sent to 8bit that i was at address of cgram
        for(lcd_counter=0;lcd_counter<=7;lcd_counter++){
            ret=lcd_4bit_send_char_data(lcd,_char[lcd_counter]);
        }
        ret=lcd_4bit_send_char_pos(lcd,row,column,mem_pos);//mem_pos means to position i want in cgram after iam at it
    }
    return ret;
}

std_returntype lcd_8bit_initialize(const chr_lcd_8bit_t *lcd){
    std_returntype ret=E_OK;
    uint8 l_data_pins_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_initilaize(&(lcd->lcd_rs));
        ret=gpio_pin_initilaize(&(lcd->lcd_en));
        for(l_data_pins_counter=0;l_data_pins_counter<8;l_data_pins_counter++){
            ret=gpio_pin_initilaize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);//this is in steps of making as after power on delay by more than 15ms
        ret=lcd_8bit_send_command(lcd,_lcd_8bit_mode_2_line);
        __delay_ms(5);
        ret=lcd_8bit_send_command(lcd,_lcd_8bit_mode_2_line);
        __delay_us(150);
        ret=lcd_8bit_send_command(lcd,_lcd_8bit_mode_2_line);
        ret=lcd_8bit_send_command(lcd,_lcd_clear);
        ret=lcd_8bit_send_command(lcd,_lcd_return_home);//cursor goes to first address as these are things happen inside datasheet of lcd so by sending this address it makes address counter becomes 0
        ret=lcd_8bit_send_command(lcd,_lcd_entry_mode);
        ret=lcd_8bit_send_command(lcd,_lcd_cursor_off_display_on);
        ret=lcd_8bit_send_command(lcd,0x80);
    }
}


std_returntype lcd_8bit_send_command(const chr_lcd_8bit_t *lcd,uint8 command){
    std_returntype ret=E_OK;
    uint8 l_pin_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_rs),low);
        for(l_pin_counter=0;l_pin_counter<8;l_pin_counter++){
            ret=gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]),(command>>l_pin_counter)& (uint8)0x01);
        }
        ret=lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}

std_returntype lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd,uint8 data){
    std_returntype ret=E_OK;
    uint8 l_pin_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=gpio_pin_write_logic(&(lcd->lcd_rs),high);
        for(l_pin_counter=0;l_pin_counter<8;l_pin_counter++){
            ret=gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]),(data>>l_pin_counter)& (uint8)0x01);
        }
        ret=lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}

std_returntype lcd_8bit_send_char_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,uint8 data){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=lcd_8bit_set_cursor(lcd,row,column);
        ret=lcd_8bit_send_char_data(lcd,data);
    }
    return ret;
}

std_returntype lcd_8bit_send_string(const chr_lcd_8bit_t *lcd,uint8 *str){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        while(*str != NULL){
            ret=lcd_8bit_send_char_data(lcd,*str);
            str++;
        }
    }
    return ret;
}

std_returntype lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,uint8 *str){
    std_returntype ret=E_OK;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=lcd_8bit_set_cursor(lcd,row,column);
        while(*str != NULL){
            ret=lcd_8bit_send_char_data(lcd,*str);
            str++;
        }
    }
    return ret;
}

std_returntype lcd_8bit_send_custome_char(const chr_lcd_8bit_t *lcd,uint8 row,uint8 column,const uint8 _char[],uint8 mem_pos){
    std_returntype ret=E_OK;
    uint8 lcd_counter=0;
    if(NULL==lcd){
        ret=E_NOT_OK;
    }else{
        ret=lcd_8bit_send_command(lcd,(_lcd_cgram_start+(mem_pos*8)));//to move by 8bytes i want and here i sent to 8bit that i was at address of cgram
        for(lcd_counter=0;lcd_counter<=7;lcd_counter++){
            ret=lcd_8bit_send_char_data(lcd,_char[lcd_counter]);
        }
        ret=lcd_8bit_send_char_pos(lcd,row,column,mem_pos);//mem_pos means to position i want in cgram after iam at it
    }
    return ret;
}

std_returntype convert_byte_to_string(uint8 value,uint8 *str){
    std_returntype ret=E_OK;
    if(NULL==str){
        ret=E_NOT_OK;
    }else{
        memset(str,'\0',4);
        sprintf(str,"%i",value);
    }
    return ret;
}

std_returntype convert_short_to_string(uint16 value,uint8 *str){
    std_returntype ret=E_OK;
    uint8 temp_string[6]={0};
    uint8 datacounter=0;
    if(NULL==str){
        ret=E_NOT_OK;
    }else{
        memset(str,' ',5);
        str[5]='\0';
        sprintf((char*)temp_string,"%i",value);//convert value to string and put null at end
        while(temp_string[datacounter]!='\0'){
            str[datacounter]=temp_string[datacounter];
            datacounter++;
        }
    }
    return ret;
}

std_returntype convert_int_to_string(uint32 value,uint8 *str){
    std_returntype ret=E_OK;
    if(NULL==str){
        ret=E_NOT_OK;
    }else{
        memset(str,'\0',11);
        sprintf(str,"%i",value);
    }
    return ret;
}

