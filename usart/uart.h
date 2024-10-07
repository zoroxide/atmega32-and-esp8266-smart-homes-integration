#ifndef UART_H
#define UART_H

#include <avr/io.h>

#define BAUD 9600
#define MY_UBRR F_CPU/16/BAUD-1

void uart_init(unsigned int ubrr);
void uart_transmit(unsigned char data);
unsigned char uart_receive(void);
void uart_send_string(const char *str);

#endif
