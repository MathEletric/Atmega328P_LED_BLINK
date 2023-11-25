#define F_CPU 16000000
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

/*
//Teste com interrupção externa PCINT:

char ledEstado = 0;

ISR(PCINT2_vect){
    if(~PIND & (1<<7)){
        while(~PIND & (1<<7));
        _delay_ms(1000);
        ledEstado = !ledEstado;
        if(ledEstado){
            PORTC |= (1<<1); 
        }else{
            PORTC &= ~(1<<1);
        }
    }
}
void pinConfig(){
    //CONFIGURAÇÃO SAÍDA
    DDRC |= (1<<1);
    //CONFIGURAÇÃO ENTRADA
    DDRD &= ~(1<<7);
    PORTD |= (1<<7);
}
void interruptConfig(){
    //CINFIGURAÇÃO INTERRUPÇÃO
    PCICR |= (1<<2); //Configura o conjunto PORTD -> PCINT[23:16]
    PCMSK2 |= (1 << 7);
    sei();
}
int main(){
    pinConfig();
    interruptConfig();
    while(1){
    }
}
*/


/*
//Teste simples com INT0:


ISR(INT0_vect){
    PORTC ^= (1<<0);
}

int main(){
    DDRD &= ~(1<<2);
    PORTD |= (1<<2);
    DDRC |= (1<<0);

    EIMSK |= (1<<0);
    EICRA = (EICRA | (1<<1)) & ~(1<<0);
    sei();
    //SREG |= (1<<7);
    sei();

    while(1){
    
    
    }

}
*/

















