#include <stdio.h>
#include <mega128.h>
/*
void IO()
{
    DDRA = 0xFF;        //LED
    DDRB = 0xFF;        //OC1A, OC1B
    DDRE = 0b10101010;  //PE1, PE3, PE5, PE7
    DDRF = 0x00;        //ADC
}


void main(void)
{
              IO();

//SREG = 0xC8;                        // 1/16 
    TCCR1A = 0b10100010;
    TCCR1B = 0b00011101;
    TCCR1C = 0x00;
    TIMSK |= ((1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1)); 
    TIFR |= ((1 << OCF1A) | (1 << OCF1B) | (1 << TOV1));
    TCNT1 = 0x00;
    ICR1 = 50;                                       
    
    while(1)
    {
    
     
        OCR1A = 30;
        OCR1B = 30;   
     }
    
}
*/
void putch(char DATA)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0 = DATA;

}

void main(void)
{
	UCSR0A = 0x0;
	UCSR0A = 0b00001000;
	UCSR0C = 0b00000110;
	UBRR0H = 0;
	UBRR0L = 103;		//9600
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		putchar
    }          
}