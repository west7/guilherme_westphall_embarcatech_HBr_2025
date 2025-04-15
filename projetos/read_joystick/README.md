# Leitor Joystick

> Ler os valores dos eioxs X e Y do Joystick e imprimir no terminal.

## Objetivo 🎯

O objetivo deste projeto é ler os valores dos eixos X e Y de um joystick analógico e imprimir esses valores no terminal. 

## Componentes Utilizados 🛠️

| Componente | Descrição          | Pinagem         |
| ---------- | ------------------ | --------------- |
| Joystick   | Joystick analógico | GPIO26 e GPIO27 |

## Execução 🧪

1. Faça o clone do projeto:

```bash
git clone https://github.com/west7/guilherme_westphall_embarcatech_HBr_2025.git
```

2. Compile e Embarque o firmware na Raspberry:

```bash
mkdir build
cd build
cmake ..
ninja
cp read_joystick.uf2 /media/$USER/RPI-RP2/
```