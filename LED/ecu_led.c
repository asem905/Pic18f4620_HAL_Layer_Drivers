



#include "ecu_led.h"
/**
 * @brief:initialize pin to be output and turn led off
 * @param led
 * @return 
 */
std_returntype led_initialize(const led_t *led){
     std_returntype ret=E_OK;
    if(NULL==led){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=led->port_name,.pin=led->pin,
        .direction=gpio_Direction_output,.logic=led->led_status};
        gpio_pin_initilaize(&pin_obj); 
    }
    return ret;
}
/**
 * @brief:turn led on
 * @param led
 * @return 
 */
std_returntype led_turn_on(const led_t *led){
    std_returntype ret=E_OK;
    if(NULL==led){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=led->port_name,.pin=led->pin,
        .direction=gpio_Direction_output,.logic=led->led_status};
        gpio_pin_write_logic(&pin_obj,high);
    }
    return ret;
}
/**
 * @brief:turn led off
 * @param led
 * @return 
 */
std_returntype led_turn_off(const led_t *led){
     std_returntype ret=E_OK;
    if(NULL==led){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=led->port_name,.pin=led->pin,
        .direction=gpio_Direction_output,.logic=led->led_status};
        gpio_pin_write_logic(&pin_obj,low);
    }
    return ret;
}
/**
 * @brief:toggle led
 * @param led
 * @return 
 */
std_returntype led_turn_toggle(const led_t *led){
     std_returntype ret=E_OK;
    if(NULL==led){
        ret=E_NOT_OK;
    }else{
        pin_config pin_obj={.port=led->port_name,.pin=led->pin,
        .direction=gpio_Direction_output,.logic=led->led_status};
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}