#include <stdio.h>
#include <delay.h>
#include <mega128.h>



void main(void)
{
    
    DDRB = 0xFF;
    DDRE = 0xFF;    
    
    
    SREG = 0xC8;
    TCCR1A = 0b10100010;
    TCCR1B = 0b00011101;
    TCCR1C = 0x00;
    TIMSK |= ((1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1)); 
    TIFR |= ((1 << OCF1A) | (1 << OCF1B) | (1 << TOV1));
    TCNT1 = 0x00;
    ICR1 = 50;
    
    PORTE = 0b10001000;
    PORTB = 0x00;
    while(1)
    {
        OCR1A = 0;
        OCR1B = 0;
    }
}