#include <stdio.h>
#include <delay.h>
#include <mega128.h>

int ad_val;


void IO()
{
    DDRA = 0xFF;
    DDRF = 0x00;
    DDRE = 0b10101010;
    DDRB = 0xFF;    
}
void ADC()
{
    ADMUX = 0x00;
    ADCSRA = 0xC6;   
}
void USART()
{
    UCSR0A = 0x0;
    UCSR0B = 0b00001000;
    UCSR0C = 0b00000110;
    UBRR0H = 0;
    UBRR0L = 103;
}

interrupt[TIM1_COMPA] void TIMER0_COM0(void)
{
   PORTB = 0xFF;
    //if(ad_val >= 1000) OCR1A = 1000;
}
// (1/16)us * (64 prescaler) * (1000000) = 40ms


void main(void)
{   
    IO();
    ADC();    
    USART(); 
    
    TIMSK = (1 << TICIE1)|(1 << OCIE1A) | (1 << TOIE1);            
    TIFR = (1 << ICF1) | (1 << OCF1A) | (1 << TOV1);
    TCCR1A = (2 << WGM10);
    TCCR1B = (3 << WGM12)| (1 << CS11) | (1 << CS10); //64 ºÐÁÖºñ
    TCCR1C = 0x00;
        
    
    PORTE = 0x10001000;   
    ICR1 = 1000000;
    SREG = 0x80;  
    OCR1A = 800000; 
    
    while(1)
    {
       PORTB = 0x00; 
    }
        
   //4.8 385    2 999      
}

