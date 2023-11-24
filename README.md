# Atmega328P_LED_BLINK

Para todas as versões, é importante filtrar o contact bounce com um capacitor de 100 nF (código 104 p/ cerâmico)

led_blink_v1:
Fazer um programa que a cada toque no botão (INT0) mude o estado do led da 
placa.

led_blink_v2:
Fazer um programa que a cada toque no botão (PB4) mude o estados de dois leds
colocados na porta PC0 e PC1, na seguinte sequência:
▪ 1  Led PC0 aceso
▪ 2  Led PC1 aceso
▪ 3  Led PC0 piscando em 5 Hz
▪ 4  Led PC0 apagado
▪ 5  Led PC1 piscando em 2 Hz
▪ 6  Leds apagados 

led_blink_v3:
Fazer um programa que a cada toque no botão (PD2) mude o estados de dois leds
colocados na porta PC0 e PC1, na seguinte sequência:
▪ 1  Led PC0 aceso
▪ 2  Led PC1 aceso
▪ 3  Led PC0 piscando em 5 Hz
▪ 4  Led PC0 apagado
▪ 5  Led PC1 piscando em 2 Hz
▪ 6  Leds apagados 

Obs: usar interrupção externa, configurando para borda de descida.

led_blink_v4:
Fazer um programa que troque o estado do led da placa (PB5) a cada toque no 
botão conectado ao pino PB4 (PORTB – bit 4). Você deve usar a interrupção da 
mudança do pino para fazer a máquina de estados avançar (somar 1 na variável 
de estado). Os estados que você deve implementar são os seguintes:
▪ 1 Led acesso
▪ 2 Led piscando 20 Hz
▪ 3 Led piscando 10 Hz
▪ 4 Led apagado
▪ 5 Led piscando 1 Hz





