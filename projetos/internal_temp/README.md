# Leitor de temperatura interna

> Ler o sensor de temperatura interna da Raspberry Pi Pico e exibir o valor em graus Celsius.

## Objetivo 🎯

Fazer a leitura do sensor de temperatura interna da Raspberry Pi Pico e exibir o valor em graus Celsius no terminal via UART.


## Componentes Utilizados 🛠️

| Componente | Descrição           | Pinagem                 |
| ---------- | ------------------- | ----------------------- |
| Raspberry Pi Pico | Microcontrolador | -                     |
| Sensor de temperatura | Sensor de temperatura interna da Raspberry Pi Pico | Interno, utiliza o canal ADC 4                    | 


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
cp internal_temp.uf2 /media/$USER/RPI-RP2/
```