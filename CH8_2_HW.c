#include <avr/io.h>
#include <avr/interrupt.h>

#define TIME 65048;//for 0.5s //64559; //for 1 s

unsigned char sec = 0;
unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};

int main()
 { 
    DDRC = 0xff;
    DDRB = 0xff;
    DDRD = 0xff;
    
    TIMSK1 = 0x01;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCNT1 = TIME;
    
    PORTC = ~TB7SEG[0];
    PORTB = ~TB7SEG[0];
    
    sei();
   // Write your code here
   while (1);
   return 0;
 }
 
 ISR(TIMER1_OVF_vect)
 {
    sec = (sec+1)%29;
    
    if(sec==0)
       PORTD = ~PORTD;
    
    PORTC = ~TB7SEG[sec/10];
    
    unsigned char temp;
    
    PORTB = ~TB7SEG[sec%10] ^ (0b10000000&PORTB) ;
    
    TCNT1 = TIME;
 }
