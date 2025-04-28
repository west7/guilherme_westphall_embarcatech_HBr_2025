# LED Embutido com Arquitetura Modular

> Fazer o led interno da Raspberry Pi Pico piscar indefinidamente, utilizando a arquitetura modular.

## Objetivo 🎯

O objetivo deste projeto é desenvolver um firmware simples para a familiarização com a Arquitetura Modular, que é amplamente utilizada em projetos profissionais de sistemas embarcados. A Arquitetura foi definida da seguinte forma:

- `drivers/`: código de controle direto do hardware
- `hal/`: camada de abstração para a interface com o hardware
- `app/`: código de aplicação, onde a lógica do projeto é implementada
- `include/`: header files para os módulos 

## Componentes Utilizados 🛠️

| Componente  | Descrição             | Pinagem               |
| ----------- | --------------------- | --------------------- |
| LED interno | LED embutido na placa | CYW43_WL_GPIO_LED_PIN |

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
cp led_embutido.uf2 /media/$USER/RPI-RP2/
```