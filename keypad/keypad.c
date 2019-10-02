#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<library/lcd.h>

unsigned int r=0;
unsigned char keypad()
{
while(1)
	{
	PORTC=0xFE;
	_delay_ms(5);

if((PINA&0x01)==0x00)
	{
	while(!(PINA&0x01));
	return '/';
	}
	if((PINA&0x02)==0x00)
	{
	while(!(PINA&0x02));
	return '9';
	}
	if((PINA&0x04)==0x00)
	{
	while(!(PINA&0x04));
	return '8';
	}
	if((PINA&0x08)==0x00)
	{
	while(!(PINA&0x08));
	return '7';
	}

	PORTC=0xFD;
	_delay_ms(5);

	if((PINA&0x01)==0x00)
	{
	while(!(PINA&0x01));
	return '*';
	}
	if((PINA&0x02)==0x00)
	{
	while(!(PINA&0x02));
	return '6';
	}
	if((PINA&0x04)==0x00)
	{
	while(!(PINA&0x04));
	return '5';
	}
	if((PINA&0x08)==0x00)
	{
	while(!(PINA&0x08));
	return '4';
	}

	PORTC=0xFB;
	_delay_ms(5);

	if((PINA&0x01)==0x00)
	{
	while(!(PINA&0x01));
	return '-';
	}
	if((PINA&0x02)==0x00)
	{
	while(!(PINA&0x02));
	return '3';
	}
	if((PINA&0x04)==0x00)
	{
	while(!(PINA&0x04));
	return '2';
	}
	if((PINA&0x08)==0x00)
	{
	while(!(PINA&0x08));
	return '1';
	}
	
	_delay_ms(5);
	
	PORTC=0xF7;
	if((PINA&0x01)==0x00)
	{
	while(!(PINA&0x01));
	return '+';
	}
	if((PINA&0x02)==0x00)
	{
	while(!(PINA&0x02));
	return '=';
	}
	if((PINA&0x04)==0x00)
	{
	while(!(PINA&0x04));
	return '0';
	}
	if((PINA&0x08)==0x00)
	{
	while(!(PINA&0x08));
	if(r==0){
	return 19;
	}
	else{
	return 20;
	}
	
	_delay_ms(5);
}

}}
void main()
{
DDRA=0x00;
PORTA=0X0F;
DDRC=0xFF;

int set1=0,set2=0;
unsigned int ans=0,value1=0,value2=0;
unsigned char z=0,x=0,y=0;

while(1)
{while(1){
n:	
	z=keypad();
	if(z==20)
	{
	lcd_command(1);
	r=0;
	set1=0,set2=0,ans=0,value1=0,value2=0,z=0,x=0,y=0;
	goto n;
	}
	if(z==19){
	r=1;
	DDRD=0xFF;
	
	lcd_init();
	lcd_string("Enter value");
	lcd_command(0xc0);
	while(set1==0)
	{
	x=keypad();
	
	if(x==20)
	{
	lcd_command(0xc0);
	lcd_string("                       ");
	r=0;
	set1=0,set2=0,ans=0,value1=0,value2=0,z=0,x=0,y=0;
	goto n;
	}
	if(x=='+')
	{
	lcd_data(x);
	set1=1;
	goto levela1;
	}

	else if(x=='-')
	{
	lcd_data(x);
	set1=1;
	goto levels1;
	}
	
	else if(x=='/')
	{
	lcd_data(x);
	set1=1;
	goto leveld1;
	}

	else if(x=='*')
	{
	lcd_data(x);
	set1=1;
	goto levelm1;
	}
	value1=(x-48)+(value1*10);
	lcd_data(x);
	}

	levela1:
	while(set2==0)
	{
	y=keypad();
	
	if(y==20)
	{
	lcd_command(0xc0);
	lcd_string("                       ");
	r=0;
	set1=0,set2=0,ans=0,value1=0,value2=0,z=0,x=0,y=0;
	goto n;
	}
	if(y=='=')
	{
	lcd_data(y);
	set2=1;
	goto levela2;
	}
	value2=(y-48)+(value2*10);
	lcd_data(y);
	}

	levels1:
	while(set2==0)
	{
	y=keypad();
	if(y=='=')
	{
	lcd_data(y);
	set2=1;
	goto levels2;
	}
	value2=(y-48)+(value2*10);
	lcd_data(y);
	}
	
	leveld1:
	while(set2==0)
	{
	y=keypad();
	if(y=='=')
	{
	lcd_data(y);
	set2=1;
	goto leveld2;
	}
	value2=(y-48)+(value2*10);
	lcd_data(y);
	}
	
	levelm1:
	while(set2==0)
	{
	y=keypad();
	if(y=='=')
	{
	lcd_data(y);
	set2=1;
	goto levelm2;
	}
	value2=(y-48)+(value2*10);
	lcd_data(y);
	}

	levela2:

	ans=value1+value2;
	lcd_command(0xc4);

	lcd_num(ans);	
	break;

	levels2:

	ans=value1-value2;
	lcd_command(0xc4);
	lcd_num(ans);	
	break;
	leveld2:

	ans=value1/value2;
	lcd_command(0xc4);
	lcd_num(ans);	
	break;	

	levelm2:

	ans=value1*value2;
	lcd_command(0xc0);
	lcd_string("                       ");

	lcd_command(0xc4);
	lcd_num(ans);	
	break;	

}}
}}
