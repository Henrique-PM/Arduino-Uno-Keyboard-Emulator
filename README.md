# Emulador de Teclado com Arduino e Python

Este projeto utiliza um Arduino para emular um teclado com três botões e um script Python para ler a saída da porta serial. A seguir estão as instruções para configurar e usar o sistema.

## Componentes Necessários

- **Arduino Uno** (ou qualquer placa Arduino compatível)
- **3 Botões** (push buttons)
- **Resistores de Pull-down**
- **Fios de Conexão**
- **Protoboard** (opcional, para montagem dos componentes)
- **Computador** com **Python** instalado

## Esquema de Conexão

1. **Conecte os botões ao Arduino**:
   - **Botão 1**: Conecte um terminal ao pino digital 2 e o outro ao GND.
   - **Botão 2**: Conecte um terminal ao pino digital 3 e o outro ao GND.
   - **Botão 3**: Conecte um terminal ao pino digital 4 e o outro ao GND.

![Esquema de conexão do Arduíno](static/esquema-arduino.png)


## Código Arduino


## Código Python



## Executando o Projeto

1. **Carregue o código Arduino** na sua placa utilizando o Arduino IDE.
2. **Conecte o Arduino** ao computador e verifique a porta serial (no exemplo acima, `COM3`).
3. **Execute o script Python**. Ele começará a ler os dados da porta serial e a imprimir o estado dos botões.

## Observações

- Certifique-se de que a porta serial configurada no Python (`COM3` no exemplo) corresponde à porta à qual o Arduino está conectado.
- O script Python foi escrito para uma configuração específica. Caso a configuração da sua porta serial ou o formato dos dados mude, ajuste o código Python conforme necessário.

## Contribuições

Se você encontrar algum problema ou quiser contribuir com melhorias, fique à vontade para abrir uma *issue* ou enviar um *pull request*.

---

Sinta-se à vontade para ajustar o README conforme necessário para se adequar ao seu projeto e às suas preferências!
