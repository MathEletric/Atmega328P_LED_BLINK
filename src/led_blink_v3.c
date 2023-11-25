/*
Fazer um programa que a cada toque no botão (PD2) mude o estados de dois leds
colocados na porta PC0 e PC1, na seguinte sequência:
▪ 1  Led PC0 aceso
▪ 2  Led PC1 aceso
▪ 3  Led PC0 piscando em 5 Hz
▪ 4  Led PC0 apagado
▪ 5  Led PC1 piscando em 2 Hz
▪ 6  Leds apagados 

Obs: usar interrupção externa, configurando para borda de subida.
*/
#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

enum{
    ALL_OFF = 0,
    LED_PC0_ON,
    LED_PC1_ON,
    LED_PC0_5HZ,
    LED_PC0_OFF,
    LED_PC1_2HZ,  
};

int state = ALL_OFF;

ISR(INT0_vect){
    _delay_ms(50);
    if(!(PIND & (1<<2))){
        state++;
        //while(!(PIND & (1<<2)));
    }
    if(state > LED_PC1_2HZ){
        state = 0;
    }
}
void led_blink(){   
    if(state == LED_PC0_5HZ){
        PORTC ^= (1<<0);
        _delay_ms(200);
    }
    else{
        PORTC ^= (1<<1);
        _delay_ms(500);
    }
}
void pinConfig(){
    DDRD &= ~(1<<2);
    PORTD |= (1<<2);
    DDRC = ((DDRC | (1<<0)) | (1<<1));
}
void interruptConfig(){
    EIMSK |= (1<<0);
    EICRA = ((EICRA | (1<<1)) | (1<<0));
    sei();
}
int main(){
    pinConfig();
    interruptConfig();
    while(1){
        switch(state){
            case ALL_OFF:
                PORTC = (PORTC & ~(1<<0)) & ~(1<<1);
                break; 
            case LED_PC0_ON:
                PORTC |= (1<<0);
                break;
            case LED_PC1_ON:
                PORTC |= (1<<1);
                break;
            case LED_PC0_5HZ:
                led_blink();
                break;
            case LED_PC0_OFF:
                PORTC &= ~(1<<0);
                break;
            case LED_PC1_2HZ:
                led_blink();
                break;                       
        }
    }
}