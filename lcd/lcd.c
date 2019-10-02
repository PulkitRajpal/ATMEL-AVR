#include<avr/io.h>
#include<util/delay.h>
void lcd_init()
{
lcd_command(0x02);//where to start
lcd_command(0x28);//4 bit mode
lcd_command(0x0c);//display on cursor off to ON use 0E to off use 0C
lcd_command(0x06);// Auto increment
}
void lcd_command(unsigned char cmd)
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
void main()
{
DDRC=0b11111111;
lcd_init();
while(1)
{
dis_cmd(0X80);
dis_data('A');
dis_data('N');
dis_data('U');
dis_data('S');
dis_data('H');
dis_data('A');
}
}

