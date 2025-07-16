// ws2812.c
#include "ws2812.h"

void ws2812_init(){
  uint offset = pio_add_program(pio0, &ws2812_program);
  ws2812_program_init(pio0, 0, offset, 19, 800000, false);
  pio_sm_put_blocking(pio0, 0, 0x00000000);}

void ws2812_display(uint32_t color) {
  pio_sm_put_blocking(pio0, 0, color);}
