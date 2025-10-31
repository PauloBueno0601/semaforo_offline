### Atividade - Semáforo Offline (Butantã)

&emsp; Este repositório contém todos os entregáveis para a atividade "Semáforo Offline" do Departamento de Engenharia de Trânsito. O projeto consiste em um semáforo funcional controlado por Arduino, incluindo a montagem física, o código de controle e as implementações avançadas.



#### Vídeo de Demonstração

&emsp; O vídeo abaixo demonstra o circuito em funcionamento, mostrando a sequência correta das luzes, os tempos de cada fase e o funcionamento dos componentes. 

**[Link para o Vídeo de Demonstração](https://drive.google.com/drive/folders/138Ia3vJ5Ci67BKkkTLruIByMfejZzIeD?usp=sharing)**

#### Tabela de Componentes

&emsp; A tabela a seguir lista todos os componentes utilizados na montagem.

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
#### Tutorial: Montagem e Conexões

&emsp; O circuito foi montado seguindo um diagrama padrão de semáforo, com a adição de um buzzer.

Diagrama de Conexões (Pinagem)

As conexões entre o Arduino e a protoboard foram feitas da seguinte maneira:

- Pino 12 (Arduino) -> Resistor (220Ω) -> Perna Positiva (+) do LED Vermelho

- Pino 13 (Arduino) -> Resistor (220Ω) -> Perna Positiva (+) do LED Amarelo

- Pino 10 (Arduino) -> Resistor (220Ω) -> Perna Positiva (+) do LED Verde

- Pino 8 (Arduino) -> Perna Positiva (+) do Buzzer

- GND (Arduino) -> Barramento Ppositivo (+) da Protoboard

Justificativas e Passo a Passo

**Alimentação (GND):** Um fio foi conectado do pino GND do Arduino ao barramento positivo (linha vermelha) da protoboard. As pernas negativas (-) (as mais curtas) de todos os três LEDs e a perna negativa do buzzer foram conectadas a este barramento comum.

**LEDs e Resistores:** Para cada LED, o pino de sinal do Arduino (10, 12, 13) foi conectado a um resistor. O resistor, por sua vez, foi conectado à perna positiva (+) (a mais longa) do LED. Isso é crucial para evitar que o LED queime.

**Buzzer:** O buzzer foi adicionado como o componente para uma nova implementação, conectado entre o pino 8 e o GND.

Imagens da Montagem



![](/assets/gnd.jpeg)
<sup>Fonte: Material produzido pelo autor (2025)</sup>

</div>

![](/assets/conexão.jpeg)
<sup>Fonte: Material produzido pelo autor (2025)</sup>

</div>

![](/assets/buzzer.jpeg)
<sup>Fonte: Material produzido pelo autor (2025)</sup>

</div>
Abaixo está a foto da montagem física finalizada.

![](/assets/completo.jpeg)
<sup>Fonte: Material produzido pelo autor (2025)</sup>

</div>


####  Lógica do Software

&emsp; O código de controle foi escrito em C++ para Arduino e pode ser encontrado neste repositório no arquivo: [**Arduino/codigo-arduino/codigo-arduino.ino**](./Arduino/codigo-arduino/codigo-arduino.ino)


&emsp; A lógica segue os tempos estipulados e implementa as funcionalidades avançadas.

- Lógica de Tempo (Ciclo Padrão)

- Sinal Vermelho: 6 segundos no total (TEMPO_VERMELHO = 6000)

- Sinal Verde: 4 segundos no total (TEMPO_VERDE = 4000)

- Sinal Amarelo: 2 segundos no total (TEMPO_AMARELO = 2000)

**Implementações Adicionais**

&emsp; O código cumpre os desafios avançados da seguinte forma:

**Componente Adicional (Buzzer):**

 - Durante a Fase Vermelha, o buzzer (conectado ao pino 8) é ativado por 2 segundos com o comando tone(*ptrBuzzer, 500); e delay(2000);.

- O semáforo então permanece em silêncio pelos 4 segundos restantes (delay(4000); ), completando os 6 segundos do ciclo.

**Uso de Ponteiros:**

- Para cumprir o requisito de programação, o código declara ponteiros para os pinos (ex: int *ptrLedVermelho = &pinoLedVermelho;).

- Todas as funções de controle (como pinMode() e digitalWrite()) usam esses ponteiros (ex: digitalWrite(*ptrLedVermelho, HIGH); ) para acessar e modificar o estado dos pinos.

**Funcionalidade Bônus (Amarelo Piscante):**

- Para um comportamento mais realista, a Fase Amarela (pino 13) foi programada para piscar 3 vezes antes de passar para o vermelho.

- Isso foi feito usando um loop for que acende e apaga o LED rapidamente, mantendo o tempo total da fase em 2 segundos.

### Avaliação em pares


 #### Avaliador 1

* **Nome:** Cristian Santos

* **Resultados da Avaliação (Barema):**

    * **Montagem (até 4 pontos):** Contempla (4/4). A montagem está de fácil entendimento. Os LEDs estão nas cores corretas e os resistores foram usados corretamente. O buzzer foi bem integrado de maneira correta. Notei que o GND foi ligado na linha positiva, mas como foi feito de forma consistente, o circuito funciona perfeitamente.

    * **Temporização (até 3 pontos):** Contempla (3/3). Usei o cronômetro do celular e os tempos estão exatos: 6s no vermelho, 4s no verde e 2s no amarelo (piscando). O buzzer também tocou por exatos 2 segundos, como programado.

    * **Código e Lógica (até 3 pontos):** Contempla (3/3). O código está muito bem estruturado e comentado. Foi além teve funcionalidade implementada: usou ponteiros corretamente, o buzzer foi adicionado na fase vermelha, e a lógica do amarelo piscando 3 vezes foi um ótimo e interessante.

### Avaliador 2

* **Nome:** Vitor Lucena

* **Resultados da Avaliação (Barema):**

    * **Montagem (até 4 pontos):** Contempla (4/4). Montagem muito boa, todos os componentes estão bem conectados, os fios poderiam estar um pouco mais organizados, mas esta claro as ligações e o uso dos resistores está correto.

    * **Temporização (até 3 pontos):** Contempla (3/3). Os tempos medidos batem exatamente com o que foi pedido na atividade (6s, 4s, 2s). A temporização do buzzer (2s) e das piscadas (totalizando 2s) também está correta.

    * **Código e Lógica (até 3 pontos):** Contempla (3/3). O código não só funciona, como cumpre todos os requisitos do "Ir Além" (ponteiros e componente extra). A lógica das fases está perfeita, e a estrutura do código é fácil de entender. Parabéns.