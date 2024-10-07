#include "io.h"

void writePort(uint8_t port){
    switch(port){
    case 'A':
        DDRA = 0xFF;
        PORTA = 0xFF;
        break;
    case 'B':
        DDRB = 0xFF;
        PORTB = 0xFF;
        break;
    case 'C':
        DDRC = 0xFF;
        PORTC = 0xFF;
        break;
    case 'D':
        DDRD = 0xFF;
        PORTD = 0xFF;
        break;
    }
}

void pinMode(uint8_t port, uint8_t pin, uint8_t mode) {
    switch (port) {
        case 'A':
            if (mode == OUTPUT) {
                DDRA |= (1 << pin);
            } else {
                DDRA &= ~(1 << pin);
            }
            break;

        case 'B':
            if (mode == OUTPUT) {
                DDRB |= (1 << pin);
            } else {
                DDRB &= ~(1 << pin);
            }
            break;

        case 'C':
            if (mode == OUTPUT) {
                DDRC |= (1 << pin);
            } else {
                DDRC &= ~(1 << pin);
            }
            break;

        case 'D':
            if (mode == OUTPUT) {
                DDRD |= (1 << pin);
            } else {
                DDRD &= ~(1 << pin);
            }
            break;
    }
}

void digitalWrite(uint8_t port, uint8_t pin, uint8_t value) {
    switch (port) {
        case 'A':
            if (value == HIGH) {
                PORTA |= (1 << pin);
            } else {
                PORTA &= ~(1 << pin);
            }
            break;

        case 'B':
            if (value == HIGH) {
                PORTB |= (1 << pin);
            } else {
                PORTB &= ~(1 << pin);
            }
            break;

        case 'C':
            if (value == HIGH) {
                PORTC |= (1 << pin);
            } else {
                PORTC &= ~(1 << pin);
            }
            break;

        case 'D':
            if (value == HIGH) {
                PORTD |= (1 << pin);
            } else {
                PORTD &= ~(1 << pin);
            }
            break;
    }
}

uint8_t digitalRead(uint8_t port, uint8_t pin) {
    switch (port) {
        case 'A':
            return (PINA & (1 << pin)) ? HIGH : LOW;

        case 'B':
            return (PINB & (1 << pin)) ? HIGH : LOW;

        case 'C':
            return (PINC & (1 << pin)) ? HIGH : LOW;

        case 'D':
            return (PIND & (1 << pin)) ? HIGH : LOW;

        default:
            return LOW;
    }
}
