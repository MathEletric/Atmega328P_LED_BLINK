/*
Fazer um programa que a cada toque no botão (PB4) mude o estados de dois leds
colocados na porta PC0 e PC1, na seguinte sequência:
▪ 1  Led PC0 aceso
▪ 2  Led PC1 aceso
▪ 3  Led PC0 piscando em 5 Hz
▪ 4  Led PC0 apagado
▪ 5  Led PC1 piscando em 2 Hz
▪ 6  Leds apagados 
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

enum{
	PC0_ON = 0,
	PC1_ON,
	PC0_BLINK_5HZ,
	PC0_OFF,
	PC1_BLINK_2HZ,
	ALL_OFF};

int state = ALL_OFF;

int main(void){
	//CONF SAÍDAS.
	DDRC = (DDRC | (1<<0)) | (1<<1);

	//CONF ENTRADAS.
	DDRB &= ~(1<<4);
	PORTB |= (1<<4);
	
	while(1){
		switch(state){
			case PC0_ON:
				PORTC |= (1<<0);
				if(!(PINB & (1<<4))){
                    state =	PC1_ON;
					while(!(PINB & (1<<4)));	
				}
			break;			
			case PC1_ON:
				PORTC |= (1<<1);
				if(!(PINB & (1<<4))){
                    state =	PC0_BLINK_5HZ;
					while(!(PINB & (1<<4)));	
				}
			break;
			case PC0_BLINK_5HZ:
				while(1){
					PORTC ^= (1<<0);
					_delay_ms(200);
					if(!(PINB & (1<<4))){
						while(!(PINB & (1<<4)));
						state =  PC0_OFF;
						break;
					}
				}
			break;
			case PC0_OFF:
				PORTC &= ~(1<<0);
				if(!(PINB & (1<<4))){
					while(!(PINB & (1<<4)));
					state =	PC1_BLINK_2HZ;
				}
			break;
			case PC1_BLINK_2HZ:
				while(1){
					PORTC ^= (1<<1);
					_delay_ms(200);
						if(!(PINB & (1<<4))){
							while(!(PINB & (1<<4)));
							state =  ALL_OFF;
							break;
						}
				}
				break;
			case ALL_OFF:
				PORTC = ((PORTC & ~(1<<0)) & ~(1<<1));
				if(!(PINB &(1<<4))){
                    state = PC0_ON;	
					while(!(PINB &(1<<4)));	
				}
			break;
				
			
			
		}//FIM SWITCH.
	}//FIM WHILE(1).
}//FIM MAIN.