# Contador Decrescente com Interrupções

## Objetivo 🎯

Implementar um contador decrescente de 9 a 0, que registra o número de pressões no botão 'B' e reinicia o contador, através de uma interrupção, sempre que o botão 'A' for pressionado. O contador é exibido no display OLED.

## Componentes Utilizados 

| Componente | Descrição           | Pinagem                 |
| ---------- | ------------------- | ----------------------- |
| OLED       | Display OLED 128x64 | SDA: GPIO14, SCL:GPIO15 |
| Botão A    | Botão de reinício   | GPIO5                   |
| Botão B    | Botão de contagem   | GPIO6                   |

## Execução 

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
cp countdown_with_irq.uf2 /media/$USER/RPI-RP2/
```