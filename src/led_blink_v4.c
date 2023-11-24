/*
Fazer um programa que troque o estado do led da placa (PB5) a cada toque no 
botão conectado ao pino PB4 (PORTB – bit 4). Você deve usar a interrupção da 
mudança do pino para fazer a máquina de estados avançar (somar 1 na variável 
de estado). Os estados que você deve implementar são os seguintes:
▪ 1 Led acesso
▪ 2 Led piscando 20 Hz
▪ 3 Led piscando 10 Hz
▪ 4 Led apagado
▪ 5 Led piscando 1 Hz
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


enum{
	PB5_0N = 0,
	PB5_BLINK_20HZ,
	PB5_BLINK_10HZ,
	PB5_OFF,
	PB5_BLINK_1HZ
	};

int state;

ISR(PCINT0_vect){
	state++;
	if(state == PB5_BLINK_1HZ+1){
	state++;
	}	
}


int main(){
	//Configuração saida
	DDRB |= (1<<5);
	//Configuração entrada
	DDRB &= ~(1<<4);
	PORTB |= (1<<4);

	//Configuração interrupção
	PCMSK0 |= (1<<0);
	EICRA = (EICRA | (1<<1)) & ~(1<<0);
	sei();
	
	SREG |= (1<<7);
	
	state = PB5_0N;
    while (1){
		switch(state){
			case PB5_0N:
				PORTB |= (1<<5);
				break;
			case PB5_BLINK_20HZ:
				while(1){
					PORTB ^= (1<<5);
				_delay_ms(50);
				}
				break;
			case PB5_BLINK_10HZ:
				while(1){
					PORTB ^= (1<<5);
					_delay_ms(100);
				}	
				break;
			case PB5_OFF:
				PORTB &= ~(1<<5);
				break;
			case PB5_BLINK_1HZ:
				while(1){
					PORTB ^= (1<<5);
					_delay_ms(1000);
				}
				break;		
		}//FIM SWITCH.
		
    }//FIM WHILE(1).
}//FIM MAIN.