#include <stdio.h>
#include <string.h>
#include "Lora.h"
#include "sx126x_hal.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define LED_GPIO 25

Lora *lora;
char payload[50];

int main(){

  stdio_init_all();

  sleep_ms(2000);
  gpio_init(LED_GPIO);
  gpio_set_dir(LED_GPIO, 1);
  gpio_put(LED_GPIO, 1);
  sleep_ms(2000);
  printf("[Main] Setting up Lora Chip");
  
  lora = new Lora();
  lora->SetRxEnable();
  printf("[Main] Done");
  
while (1)
{
  hal_gpio_put(LED_GPIO, 0);
  lora->SetToReceiveMode();
 // char payload[50];
 // lora->SendData(22, payload, strlen(payload));
  lora->ProcessIrq();
  lora->CheckDeviceStatus();
  hal_gpio_put(LED_GPIO, 1);
  sleep_ms(300);
}

    return 0;
}


