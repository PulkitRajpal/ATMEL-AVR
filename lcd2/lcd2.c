#include <avr/io.h> 
#include <util/delay.h> 
void dis_command(unsigned char cmd)
{
lcd=cmd&0xF0;
lcd|=0x04;
_delay_ms(1);
lcd=lcd&0xF0;
_delay_ms(1);
lcd=(cmd<<4)&0xF0;
lcd|=0x04;
_delay_ms(1);
lcd=lcd&0xF0;
_delay_ms(1);
}
void dis_data(unsigned char data)
{
lcd=data&0xF0;
lcd|=0x05;
_delay_ms(1);
lcd=lcd&0xF0;
_delay_ms(1);
lcd=(data<<4)&0xF0;
lcd|=0x05;
_delay_ms(1);
lcd=lcd&0xF1;
_delay_ms(1);
}
void dis_init()
{
lcd_command(0x02);//where to start
lcd_command(0x28);//4 bit mode
lcd_command(0x0c);//display on cursor off to ON use 0E to off use 0C
lcd_command(0x06);// Auto increment
}
 
void main() 
{ 
    DDRC = 0xff; 
    lcd_init(); 
    dis_cmd(0x8a); 
    dis_data(':'); 
    dis_cmd(0x8d); 
    dis_data(':'); 
    int i,j=0; 
    while(1){ 
    dis_cmd(0x8f); 
    dis_num(i); 
    _delay_ms(10); 
    i++; 
    if(i==60){ 
    j++; 
    dis_cmd(0x8c); 
    dis_num(j); 
    i=0; 
    } 
 
    } 
    } 
