/*
 * Atividade - Semáforo Offline
 * VERSÃO ATUALIZADA: Amarelo pisca 3x
 *
 * Conexões (Pinos do Arduino):
 * - Pino 12: LED Vermelho
 * - Pino 13: LED Amarelo
 * - Pino 10: LED Verde
 * - Pino 8:  Buzzer (conectar o outro pino do buzzer ao GND)
 */

// --- Definição dos Pinos (como variáveis) ---
int pinoLedVermelho = 12;
int pinoLedAmarelo  = 13;
int pinoLedVerde    = 10;
int pinoBuzzer      = 8;

// --- Ponteiros para os Pinos ---
int *ptrLedVermelho = &pinoLedVermelho;
int *ptrLedAmarelo  = &pinoLedAmarelo;
int *ptrLedVerde    = &pinoLedVerde;
int *ptrBuzzer      = &pinoBuzzer;

// --- Definição dos Tempos (em milissegundos) ---
#define TEMPO_VERMELHO 6000
#define TEMPO_VERDE    4000
#define TEMPO_AMARELO  2000

// A função setup() é executada uma vez
void setup() {
  // Configura os pinos como SAÍDA (OUTPUT)
  pinMode(*ptrLedVermelho, OUTPUT);
  pinMode(*ptrLedAmarelo, OUTPUT);
  pinMode(*ptrLedVerde, OUTPUT);
  pinMode(*ptrBuzzer, OUTPUT); // Configura o pino do buzzer
}

// A função loop() é executada continuamente
void loop() {
  // --- Fase 1: VERMELHO ---
  digitalWrite(*ptrLedVermelho, HIGH);
  digitalWrite(*ptrLedAmarelo, LOW);
  digitalWrite(*ptrLedVerde, LOW);
  
  // Lógica do Buzzer por 2s (ATUALIZADO)
  tone(*ptrBuzzer, 500); // Toca o buzzer (tom mais grave)
  delay(2000); // ...por 2 segundos (ATUALIZADO)
  noTone(*ptrBuzzer); // Para o buzzer
  
  // Espera o restante do tempo do vermelho
  // (2000ms + 4000ms = 6000ms, que é o TEMPO_VERMELHO)
  delay(4000); // ATUALIZADO

  // --- Fase 2: VERDE ---
  digitalWrite(*ptrLedVermelho, LOW);
  digitalWrite(*ptrLedAmarelo, LOW);
  digitalWrite(*ptrLedVerde, HIGH);
  noTone(*ptrBuzzer); // Para o buzzer no VERDE
  delay(TEMPO_VERDE);

  // --- Fase 3: AMARELO (PISCANDO 3x) ---
  digitalWrite(*ptrLedVermelho, LOW);
  digitalWrite(*ptrLedVerde, LOW); // Garante que o verde está apagado
  noTone(*ptrBuzzer); // Garante que o buzzer está parado

  // Lógica para piscar 3x dentro dos 2 segundos (2000ms)
  // 2000ms / 3 piscadas = ~666ms por pisca
  // 666ms / 2 (metade aceso, metade apagado) = 333ms
  int tempoPisca = 333;
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(*ptrLedAmarelo, HIGH); // Acende Amarelo
    delay(tempoPisca);
    digitalWrite(*ptrLedAmarelo, LOW);  // Apaga Amarelo
    delay(tempoPisca);
  }
  // Total: 3 * (333 + 333) = 1998ms (perto dos 2000ms)
  // O loop termina com o LED amarelo APAGADO, pronto para o vermelho.
}


