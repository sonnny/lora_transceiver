#include "transmit.h"

#define LED_GPIO 25
#define BUTTON 2


Lora *lora;
char payload[100];

uint32_t value = 0;

int main(){

stdio_init_all(); sleep_ms(2000);
 
//ws2812_init();

    uint32_t time_ms = 0;
  
gpio_init(BUTTON);
gpio_set_dir(BUTTON,GPIO_IN);
gpio_pull_up(BUTTON);
  
gpio_init(LED_GPIO);
gpio_set_dir(LED_GPIO, 1);
gpio_put(LED_GPIO, 1);
printf("[Main] Setting up Lora Chip");
  
lora = new Lora();
lora->SetTxEnable();
printf("[Main] Done");
while (1){
  hal_gpio_put(LED_GPIO, 0);
  time_ms = time_us_32();
  value = get_rand_32();
  sprintf(payload,"temp is %" PRIu32 "\r\n",value);

  if(!gpio_get(BUTTON)){
    lora->SendData(22, payload, strlen(payload));
    sleep_ms(100);
  
     // sleep_ms(1000);
    lora->ProcessIrq();
    lora->CheckDeviceStatus();}

  hal_gpio_put(LED_GPIO, 1);
  sleep_ms(50);}

  return 0;}

