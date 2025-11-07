#include <am.h>
#include <klib-macros.h>

// register addr and and the handler
#define UART_ADDR 0x10000008

static void __am_uart_config(AM_UART_CONFIG_T *cfg) {
    cfg->present = true;
}

static void __am_uart_tx(AM_UART_TX_T *tx) {
    putch(tx->data);
}

static void __am_uart_rx(AM_UART_RX_T *rx) {
    if ((*(volatile unsigned char *)(0x10000000 + 5) & 0x01) == 0)
        rx->data = (char)-1;
    else
        rx->data = *(volatile unsigned char *)(0x10000000 + 0);
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
    [AM_UART_RX] = __am_uart_rx,
    [AM_UART_TX] = __am_uart_tx,
    [AM_UART_CONFIG] = __am_uart_config,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  return true;
}


void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }