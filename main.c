#include "usart/uart.h"
#include "io/io.h"

void setup(){
    uart_init(MY_UBRR);
    pinMode('A', 2, OUTPUT);
    pinMode('C', 2, OUTPUT);
    pinMode('C', 7, OUTPUT);
}

int main()
{
    setup();

    while(1)
    {
        unsigned char data = uart_receive();
        if(data == 'A')
        {
            digitalWrite('C', 2, HIGH);
        }
        else if(data == 'B')
        {
            digitalWrite('C', 7, HIGH);
        }
        else if(data == 'C')
        {
            digitalWrite('A', 2, HIGH);
        }
        else if(data == 'a')
        {
            digitalWrite('C', 7, LOW);
        }
        else if(data == 'b')
        {
            digitalWrite('C', 7, LOW);
        }
        else if(data == 'c')
        {
            digitalWrite('A', 2, LOW);
        }
        else if(data == 'X')
        {
            digitalWrite('C', 7, HIGH);
            digitalWrite('C', 2, HIGH);
            digitalWrite('A', 2, HIGH);
        }
        else if(data == 'x')
        {
            digitalWrite('C', 7, LOW);
            digitalWrite('C', 2, LOW);
            digitalWrite('A', 2, LOW);
        }

    }

    return 0;
}
