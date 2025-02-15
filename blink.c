/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
 #include "pico/stdlib.h"
 // Pico W devices use a GPIO on the WIFI chip for the LED,
 // so when building for Pico W, CYW43_WL_GPIO_LED_PIN will be defined
 #ifdef CYW43_WL_GPIO_LED_PIN
 #include "pico/cyw43_arch.h"
 #endif
 
 #define BUTTON_A 5    
 
 int velocidade = 0;      
 bool led_ligado = false;
 
 // Perform initialisation
 int pico_led_init(void) {
 #if defined(PICO_DEFAULT_LED_PIN)
     // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
     // so we can use normal GPIO functionality to turn the led on and off
     gpio_init(PICO_DEFAULT_LED_PIN);
     gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
     return PICO_OK;
 #elif defined(CYW43_WL_GPIO_LED_PIN)
     // For Pico W devices we need to initialise the driver etc
     return cyw43_arch_init();
 #endif
 }
 
 // Turn the led on or off
 void pico_set_led(bool led_on) {
 #if defined(PICO_DEFAULT_LED_PIN)
     // Just set the GPIO on or off
     gpio_put(PICO_DEFAULT_LED_PIN, led_on);
 #elif defined(CYW43_WL_GPIO_LED_PIN)
     // Ask the wifi "driver" to set the GPIO on or off
     cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
 #endif
 }
 
 void controlar_led(int velocidade) {
     if (led_ligado && velocidade > 0) {
         pico_set_led(true);          
         sleep_ms(1000 / velocidade); 
         pico_set_led(false);        
         sleep_ms(1000 / velocidade); 
     } else {
         pico_set_led(false);         
     }
 }
 
 int main() {
     stdio_init_all();
 
     
     int rc = pico_led_init();
     hard_assert(rc == PICO_OK);
 
     
     gpio_init(BUTTON_A);
     gpio_set_dir(BUTTON_A, GPIO_IN);
     gpio_pull_up(BUTTON_A);
 
     bool botao_pressionado = false;
     while (true) {
         if (gpio_get(BUTTON_A) == 0) { 
             if (!botao_pressionado) { 
                 botao_pressionado = true;
                 if (velocidade == 0) {
                     velocidade = 1;     
                     led_ligado = true;
                 } else if (velocidade < 5) {
                     velocidade++;       
                 } else {
                     velocidade = 0;     
                     led_ligado = false;
                 }
                 sleep_ms(200);          
             }
         } else {
             botao_pressionado = false; 
         }
 
         
         controlar_led(velocidade);
     }
 }