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
