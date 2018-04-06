#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char state;
//state 01->11->01->00
int main()
 { 
   // Write your code here
    DDRC = 0xff;
    TIMSK0 = 0x01;
    TCCR0A = 0x00; //0000 0000
    TCCR0B = 0x05; //0000 0101
    TCNT0 = 223;
    PORTC = 0x02;
    state = 1;
    sei();
   while (1);
   return 0;
 } 
 ISR(TIMER0_OVF_vect)
 {
    if(state == 1)
    {
       TCNT0 = 223;
       PORTC = 0x02;
       state = 2;
    }
    else if(state == 2)
    {
       TCNT0 = 223;
       PORTC = 0x03;
       state = 3;
    }
    else if(state == 3)
    {
       TCNT0 = 223;
       PORTC = 0x01;
       state = 4;
    }
    else
    {
       TCNT0 = 223;
       PORTC = 0x00;
       state = 1;
    }
 }
