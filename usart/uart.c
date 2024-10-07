#include "uart.h"

// Initialize UART
void uart_init(unsigned int ubrr) {
    // Set baud rate
    UBRRH = (unsigned char)(ubrr >> 8);
    UBRRL = (unsigned char)ubrr;

    // Enable receiver and transmitter
    UCSRB = (1 << RXEN) | (1 << TXEN);

    // Set frame format: 8 data bits, 1 stop bit
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

// Transmit a single character
void uart_transmit(unsigned char data) {
    // Wait for the transmit buffer to be empty
    while (!(UCSRA & (1 << UDRE)));

    // Put data into the buffer, sends the data
    UDR = data;
}

// Receive a single character
unsigned char uart_receive(void) {
    // Wait for data to be received
    while (!(UCSRA & (1 << RXC)));

    // Get and return received data from the buffer
    return UDR;
}

// Send a string via UART
void uart_send_string(const char *str) {
    while (*str) {
        uart_transmit(*str++);
    }
}
