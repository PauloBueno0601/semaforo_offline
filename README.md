## Atividade - Semáforo Offline 

&emsp; Repositório do projeto de semáforo com Arduino, desenvolvido para a atividade do Departamento de Engenharia de Trânsito.

&emsp; O projeto cumpre todos os requisitos básicos e os desafios complementares:

- Controlo de tempo exato (Vermelho 6s, Verde 4s, Amarelo 2s).

- Componente extra: Buzzer toca por 2 segundos durante a fase vermelha.

- Lógica extra: LED Amarelo pisca 3 vezes antes de mudar para vermelho.

- Programação: Uso de ponteiros para gestão dos pinos.

 ### Vídeo de Demonstração

**[Link para o Vídeo de Demonstração](https://drive.google.com/drive/folders/138Ia3vJ5Ci67BKkkTLruIByMfejZzIeD?usp=sharing)**

&emsp; O vídeo demonstra o circuito completo em funcionamento.

###  Hardware e Montagem

| Componente | Quantidade | Especificação | Justificativa |
| :--- | :---: | :--- | :--- |
| Arduino Uno | 1 | R3 (ou similar) | Placa microcontroladora para programar a lógica. |
| LED Vermelho | 1 | 5mm, Alto Brilho | Representa a fase "Pare" do semáforo. |
| LED Amarelo | 1 | 5mm, Alto Brilho | Representa a fase "Atenção" do semáforo. |
| LED Verde | 1 | 5mm, Alto Brilho | Representa a fase "Siga" do semáforo. |
| Resistor | 3 | 220Ω | Para limitar a corrente e proteger os LEDs. |
| Buzzer Ativo | 1 | 5V | Componente, usado para alerta sonoro. |
| Protoboard | 1 | 400 furos | Placa de prototipagem para montar o circuito. |
| Fios Jumper | ~10 | Macho-Macho e macho-femea | Para realizar as conexões elétricas. |

- Diagrama de Conexões (Pinagem)

- Pino 12 -> Resistor -> LED Vermelho (+)

- Pino 13 -> Resistor -> LED Amarelo (+)

- Pino 10 -> Resistor -> LED Verde (+)

- Pino 8 -> Buzzer (+)

- GND -> Barramento Comum (Linha Vermelha + na protoboard)

- (Todas as pernas negativas (-) dos LEDs e do Buzzer ligam neste barramento)

### Código-Fonte

&emsp; O código completo, incluindo os comentários e a lógica dos ponteiros, pode ser encontrado no seguinte ficheiro:

[**Arduino/codigo-arduino/codigo-arduino.ino**](./Arduino/codigo-arduino/codigo-arduino.ino)