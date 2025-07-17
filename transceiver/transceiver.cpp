#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/time.h"
#include "pico/binary_info.h"
#include "pico/rand.h"

#include "Lora.h"
#include "ws2812.h"

#define LED_GPIO   25
#define BUTTON      2


Lora *lora;
char payload[100];

uint32_t value = 0;

int main(){

stdio_init_all(); sleep_ms(2000);
 
    uint32_t time_ms = 0;
  
ws2812_init();
  
gpio_init(BUTTON);
gpio_set_dir(BUTTON,GPIO_IN);
gpio_pull_up(BUTTON);
  
gpio_init(LED_GPIO);
gpio_set_dir(LED_GPIO, 1);
gpio_put(LED_GPIO, 1);
printf("[Main] Setting up Lora Chip");
  
lora = new Lora();
printf("[Main] Done");

while (1){
  hal_gpio_put(LED_GPIO, 0);
  time_ms = time_us_32();

  if(!gpio_get(BUTTON)){
    value = get_rand_32();
    sprintf(payload,"temp is %" PRIu32 "\r\n",value);
    lora->SetTxEnable();
    lora->SendData(22, payload, strlen(payload));
    ws2812_display(0x00100010);
    sleep_ms(50);}
   // sleep_ms(100);}
    //lora->ProcessIrq();
    //lora->CheckDeviceStatus();}
    
  ws2812_display(0x00001000);
  lora->SetRxEnable();
  lora->SetToReceiveMode();
  lora->ProcessIrq();
  lora->CheckDeviceStatus();
  sleep_ms(50);

  hal_gpio_put(LED_GPIO, 1);
  ws2812_display(0x10101010);
  sleep_ms(50);}
 // sleep_ms(50);}

  return 0;}

