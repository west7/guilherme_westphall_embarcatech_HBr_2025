# Galton Board

> O Galton Board é um dispositivo que demonstra o conceito de distribuição normal através de esferas que caem por uma série de pinos dispostos em um padrão triangular. À medida que as esferas caem, elas se desviam para a esquerda ou para a direita ao colidir com os pinos, resultando em uma distribuição normal na parte inferior.

## Objetivo 🎯

Desenvolver uma simulação digital do Galton Board utilizando uma placa Raspberry Pi Pico W (BitDogLab) e um display OLED SSD1306. O projeto tem como objetivo demonstrar o conceito de distribuição normal e a aleatoriedade dos resultados, além de trabalhar conceitos como colisão, movimento e renderização gráfica.

## Componentes Utilizados 🛠️

| Componente           | Descrição                              | Pinagem                         |
| -------------------- | -------------------------------------- | ------------------------------- |
| Raspberry Pi Pico W  | Através da BitDogLab                   | -                               |
| Display OLED SSD1306 | Display gráfico de 128x64 pixels       | I2C: SDA (GPIO14), SCL (GPIO15) |
| Botão B              | Botão de interação para trocar de tela | GPIO6                           |


## Execução 🧪

Compile e Embarque o firmware na Raspberry:

```bash
mkdir build
cd build
cmake ..
ninja
cp galton_board.uf2 /media/$USER/RPI-RP2/
# ou com a picotool
picotool load galton_board.uf2 --family rp2040
```