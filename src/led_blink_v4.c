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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

enum{
    LED_ON = 0,
    LED_20HZ,
    LED_10HZ,
    LED_OFF,
    LED_1HZ
};

int state = LED_ON;

void pinConfig(){
    DDRB = ((DDRB | (1<<5)) & ~(1<<4));
    PORTB |= (1<<4);
}

void interruptConfig(){
    PCICR |= (1<<0);
    PCMSK0 |= (1<<4);
    sei();
}

void led_blink(){
    if(state == LED_20HZ){
        PORTB ^= (1<<5);
        _delay_ms(50);
    }
    else if(state == LED_10HZ){
        PORTB ^= (1<<5);
        _delay_ms(100);
    }else{
        PORTB ^= (1<<5);
        _delay_ms(1000);
    }
}

ISR(PCINT0_vect){
    _delay_ms(50);
    if(!(PINB & (1<<4))){
        state++;
        //while(!(PINB & (1<<4)));
    }
    if(state > LED_1HZ){
        state = LED_ON;
    }
}

int main(){
    pinConfig();
    interruptConfig();
    while(1){
        switch(state){
            case LED_ON:
                PORTB |= (1<<5);
                break;
            case LED_20HZ:
                led_blink();
                break;
            case LED_10HZ:
                led_blink();
                break;
            case LED_OFF:
                PORTB &= ~(1<<5);
                break;
            case LED_1HZ:
                led_blink();
                break;   
        }
    }       
}

