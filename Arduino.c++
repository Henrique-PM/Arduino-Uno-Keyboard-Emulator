const int botao1 = 7;  // Botão para 'w'
const int botao2 = 3;  // Botão para 'Esc'
const int botao3 = 4;  // Botão para 'Espaço'

// Variáveis para armazenar o estado atual e anterior dos botões
int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;
int estadoBotao3 = HIGH;
int ultimoEstadoBotao1 = HIGH;
int ultimoEstadoBotao2 = HIGH;
int ultimoEstadoBotao3 = HIGH;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
}

void loop() {
  // Lê o estado dos botões
  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);
  estadoBotao3 = digitalRead(botao3);

  // Verifica o botão 1
  if (estadoBotao1 == LOW && ultimoEstadoBotao1 == HIGH) {
    Serial.println("w");
    delay(200); // Debounce e evita múltiplos envios
  }

  // Verifica o botão 2
  if (estadoBotao2 == LOW && ultimoEstadoBotao2 == HIGH) {
    Serial.println("Esc");
    delay(200); // Debounce e evita múltiplos envios
  }

  // Verifica o botão 3
  if (estadoBotao3 == LOW && ultimoEstadoBotao3 == HIGH) {
    Serial.println("Espaco");
    delay(200); // Debounce e evita múltiplos envios
  }

  // Atualiza o estado anterior dos botões
  ultimoEstadoBotao1 = estadoBotao1;
  ultimoEstadoBotao2 = estadoBotao2;
  ultimoEstadoBotao3 = estadoBotao3;

  delay(50); // Adiciona um atraso para reduzir a carga no processador
}
