#include<avr/io.h>
#include<util/delay.h>
#include<util/lcd.h>
void main()
{
DDRD=0xFF;
lcd_init();
while(1)
{
	lcd_command(0x83);
	lcd_string("Digital Clock");
	_delay_ms(1);
		lcd_command(0xcb);	
		lcd_data(':');
		lcd_command(0xc8);	
		lcd_data(':');
	
	for(int n = 0;n<=2;n++){
		lcd_command(0xc6);	
		lcd_data(48+n);
		for(int m = 0;m<9;m++){
			lcd_command(0xc7);	
			lcd_data(48+m);
			if(n==2){
			if(m==4){
			lcd_command(0xc9);	
			lcd_data(48+0);
			lcd_command(0xcd);	
			lcd_data(48+0);
			lcd_command(0xcc);	
			lcd_data(48+0);
			lcd_command(0xca);	
			lcd_data(48+0);
			lcd_command(0xc9);	
			lcd_data(48+0);
			lcd_command(0xce);	
			lcd_data(48+0);
			
			return;
			}
		}
			for(int l = 0;l<6;l++){
				lcd_command(0xc9);	
				lcd_data(48+l);
	//	_delay_ms(1000);
				for(int k = 0;k<=9;k++){
					lcd_command(0xca);	
					lcd_data(48+k);
		
					for(int j = 0;j<6;j++){
						lcd_command(0xcc);	
						lcd_data(48+j);
	//	_delay_ms(1000);
						for(int i = 0;i<=9;i++){
							lcd_command(0xcd);	
							lcd_data(48+i);
							_delay_us(1);
						}
					}
				}
			}
		}
	}
}
}

