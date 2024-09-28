#include <base.h>
#include <uart/uart.h>
#include <stdint.h>

#define UART_ADDR   0x44A10000
#define GPIO_DATA ((volatile uint32_t *)(0x44A00000))
#define GPIO_DIR  ((volatile uint32_t *)(0x44A00004))
#define VGA_OFF   ((volatile uint32_t *)(0x44A60000))
#define DDR_RAM   ((volatile uint32_t *)(0x90000000))

int main()
{
  struct s_uart *p_uart = initUart(UART_ADDR);

  delay(2000);

  for(;;)
  {
    delay(2000);

    if(p_uart->status.bits.rx_fifo_valid)
    {
      uint8_t temp;

      temp = getUartRxData(p_uart);

      setUartTxData(p_uart, temp);
    }
  }
}
