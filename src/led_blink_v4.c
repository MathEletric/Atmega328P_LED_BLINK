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

