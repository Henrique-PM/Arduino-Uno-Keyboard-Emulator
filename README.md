# Emulador de Teclado com Arduino e Python

Este projeto usa um Arduino para emular um teclado com três botões e um script Python para ler e interpretar a saída da porta serial. Siga as instruções abaixo para configurar o hardware e o software.

## Componentes Necessários

- **Arduino Uno** (ou uma placa Arduino compatível)
- **3 Botões** (push buttons)
- **Resistores de Pull-down**
- **Fios de Conexão**
- **Protoboard** (opcional, para montagem dos componentes)
- **Computador** com **Python** instalado

## Esquema de Conexão

1. **Conecte os Botões ao Arduino**:
   - **Botão 1**: Conecte um terminal ao pino digital 7 e o outro ao GND.
   - **Botão 2**: Conecte um terminal ao pino digital 3 e o outro ao GND.
   - **Botão 3**: Conecte um terminal ao pino digital 4 e o outro ao GND.

![Esquema de Conexão Arduíno](esquema-arduino.png)
## Código Arduino

```cpp
const int botao1 = 7;  // Botão para 'w'
const int botao2 = 3;  // Botão para 'Esc'
const int botao3 = 4;  // Botão para 'Espaço'

// Variáveis
int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;
int estadoBotao3 = HIGH;
int ultimoEstadoBotao1 = HIGH;
int ultimoEstadoBotao2 = HIGH;
int ultimoEstadoBotao3 = HIGH;

void setup() {
  Serial.begin(9600); 
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
}

void loop() {
  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);
  estadoBotao3 = digitalRead(botao3);

  if (estadoBotao1 == LOW && ultimoEstadoBotao1 == HIGH) {
    Serial.println("w");
    delay(200); 
  }

  if (estadoBotao2 == LOW && ultimoEstadoBotao2 == HIGH) {
    Serial.println("Esc");
    delay(200); 
  }

  if (estadoBotao3 == LOW && ultimoEstadoBotao3 == HIGH) {
    Serial.println("Espaco");
    delay(200); 
  }

  ultimoEstadoBotao1 = estadoBotao1;
  ultimoEstadoBotao2 = estadoBotao2;
  ultimoEstadoBotao3 = estadoBotao3;

  delay(50); 
}
```

## Instruções para Configuração e Upload do Código no Arduino

1. **Instale o Arduino IDE**:
   - **Baixe o Arduino IDE**: Acesse [a página de downloads do Arduino](https://www.arduino.cc/en/software) e baixe a versão apropriada para seu sistema operacional.
   - **Instale o Arduino IDE**: Siga as instruções fornecidas pelo instalador.

2. **Conecte o Arduino ao Computador**:
   - Use um cabo USB para conectar a placa Arduino ao seu computador.

3. **Abra o Arduino IDE**:
   - Inicie o Arduino IDE.

4. **Configure a Placa e a Porta**:
   - No menu **"Tools"** (Ferramentas), selecione **"Board"** (Placa) e escolha **"Arduino Uno"** (ou a placa que você está usando).
   - Em **"Port"** (Porta), selecione a porta à qual o Arduino está conectado (geralmente é algo como **"COM3"** no Windows ou **"/dev/ttyUSB0"** no Linux).

5. **Carregue o Código no Arduino**:
   - Copie o código acima e cole-o na área de edição do Arduino IDE.
   - Clique no botão **"Upload"** (Seta para a direita) na barra de ferramentas do IDE.
   - Aguarde até que a mensagem **"Done uploading"** (Carregamento concluído) apareça na parte inferior da janela.

6. **Verifique a Comunicação Serial**:
   - Após o upload, abra o Monitor Serial clicando no ícone de lupa na parte superior direita ou vá para **"Tools"** > **"Serial Monitor"**.
   - Certifique-se de que a taxa de transmissão (baud rate) está configurada para **9600**.

## Código Python para Leitura da Porta Serial

Instale a biblioteca `pyserial` se ainda não a tiver:

```bash
pip install pyserial
```
Instale a biblioteca `pynput` se ainda não a tiver:

```bash
pip install pynput
```

O script Python a seguir lê os dados da porta COM3 e simula a pressão das teclas com base na entrada recebida:

```python
import serial
from pynput.keyboard import Controller, Key


COM_PORT = 'COM3'
BAUD_RATE = 9600


keyboard = Controller()
with serial.Serial(COM_PORT, BAUD_RATE, timeout=1) as ser:
    print(f"Conectado à porta {COM_PORT} com baud rate {BAUD_RATE}")

    while True:
        try:
            line = ser.readline().decode('utf-8').strip()

            if line:
                print(f"Recebido: {line}")

                if line == 'w':
                    keyboard.press('w')
                    keyboard.release('w')
                elif line == 'Esc':
                    keyboard.press(Key.esc)
                    keyboard.release(Key.esc)
                elif line == 'Espaco':
                    keyboard.press(Key.space)
                    keyboard.release(Key.space)
        except KeyboardInterrupt:
            print("Encerrando...")
            break
```

## Observações

- **Porta Serial**: Certifique-se de que a porta serial configurada no Python (`COM3` no exemplo) corresponde à porta à qual o Arduino está conectado.
- **Dependências**: O script Python utiliza as bibliotecas `pyserial` e `pynput`. Instale-as usando `pip` se ainda não o fez.

## Contribuições

Se você encontrar problemas ou tiver sugestões de melhorias, sinta-se à vontade para abrir uma *issue* ou enviar um *pull request*.
