/*
Fazer um programa que a cada toque no botão (INT0) mude o estado do led da 
placa.
*/
#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT0_vect){
    PORTC ^= (1<<1);
}

void pinConfig(){
    //CONFIGURAÇÃO SAÍDA
    DDRC |= (1<<1);
    //CONFIGURAÇÃO ENTRADA
    DDRD &= ~(1<<2);
    PORTD |= (1<<2);
}

void interruptConfig(){
    //CINFIGURAÇÃO INTERRUPÇÃO
    EIMSK |= (1<<0);
    EICRA = (EICRA & ~(1<<0)) | (1<<1);
    SREG |= (1<<7);
    sei();
}

int main(){
    pinConfig();
    interruptConfig();
    while(1){
    }
}