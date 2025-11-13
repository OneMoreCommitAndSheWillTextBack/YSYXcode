#ifndef SOC_IOE_H
#define SOC_IOE_H

// register addr and and the handler
#define UART_ADDR 0x10000008
#define INPUT_ADDR 0x10011000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *keybrd);
#endif
