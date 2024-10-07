#ifndef IO_H
#define IO_H

#include <avr/io.h>

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

void pinMode(uint8_t port, uint8_t pin, uint8_t mode);
void writePort(uint8_t port);
void digitalWrite(uint8_t port, uint8_t pin, uint8_t value);
uint8_t digitalRead(uint8_t port, uint8_t pin);

#endif
