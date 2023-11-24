/*
Fazer um programa que a cada toque no botão (PD2) mude o estados de dois leds
colocados na porta PC0 e PC1, na seguinte sequência:
▪ 1  Led PC0 aceso
▪ 2  Led PC1 aceso
▪ 3  Led PC0 piscando em 5 Hz
▪ 4  Led PC0 apagado
▪ 5  Led PC1 piscando em 2 Hz
▪ 6  Leds apagados 

Obs: usar interrupção externa, configurando para borda de descida.
*/

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

enum{
    LED_PC0_ON = 0,
    LED_PC1_ON,
    LED_PC0_5HZ,
    LED_PC0_OFF,
    LED_PC1_2HZ,
    ALL_OFF
};

int state = ALL_OFF;

void configPins(){
//SAÍDAS E ENTRADAS:
DDRC = (DDRC | (1<<0)) | (1<<1);

DDRD &= ~(1<<2);
PORTD |= (1<<2);
}
void configInterrupt(){
    EIMSK |= (1<<0);
    EICRA = (EICRA | (1<<1)) & ~(1<<0);
    SREG |= (1<<7);
    sei();
}

ISR(INT0_vect){
    if(state == 5){
        state = 0;
    }
    else{
        state++;
    }
}

int main(){
    configPins();
    configInterrupt();
    while(1){
        switch(state){
            case ALL_OFF:
                PORTC = (PORTC & ~(1<<0)) & ~(1<<1);
            case LED_PC0_ON:
                PORTC |= (1<<0);
        }

    }
}