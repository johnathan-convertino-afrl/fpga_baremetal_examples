//#include "stddefs.h"
#include <stdint.h>

#define UART_TX   ((volatile uint32_t *)(0x44A10004))
#define GPIO_DATA ((volatile uint32_t *)(0x44A00000))
#define GPIO_DIR  ((volatile uint32_t *)(0x44A00004))
#define VGA_OFF   ((volatile uint32_t *)(0x44A60000))
#define DDR_RAM   ((volatile uint32_t *)(0x90000000))

void irqCallback();
void delay(uint32_t loops);

int main() {

  uint32_t ascii  = 0x41;
  uint32_t offset = 0;
  volatile uint32_t data   = 0;

  *GPIO_DIR  = 0x00000000;
  *GPIO_DATA = 0x0000F00F;

  delay(20000);

  for(;;)
  {
    *GPIO_DIR = 0x0000FFFF;
    data = *GPIO_DATA;

    *GPIO_DIR = 0x00000000;
    *GPIO_DATA = data;

    *UART_TX = ascii;

    *(DDR_RAM + offset) = ascii + (offset << 8);

    ascii++;

    if(ascii > 0x7A)
    {
      ascii = 0x41;
      *UART_TX = '\n';
      *UART_TX = '\r';
    }

    offset = (offset > 262144*2 ? 0 : offset + 1);

    delay(2000);
  }
}

void irqCallback()
{
  return;
}

void delay(uint32_t loops)
{
  for(uint32_t index = 0; index < loops ; index++)
  {
    int tmp = *VGA_OFF;
  }
}
