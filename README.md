Controle de LED com Botão
Descrição
Este projeto permite o controle de um LED embutido, onde o usuário pode ajustar a velocidade de piscar do LED por meio de um botão. A velocidade do LED pode ser alterada entre 1 e 5 ciclos por segundo, e ao atingir a velocidade máxima, o LED é desligado. O sistema funciona por meio de interações com pinos GPIO, e o código foi desenvolvido para ser simples e eficiente.

Funcionalidades
Controle de Piscar do LED: O LED alterna entre aceso e apagado com diferentes velocidades de piscamento.
Ajuste de Velocidade: O botão permite ao usuário aumentar a velocidade de piscamento do LED, variando entre 1 e 5 ciclos por segundo. Após atingir a velocidade 5, o LED é desligado.
Interação com GPIO: O botão está conectado ao pino GPIO 5, e o controle do LED é feito através de simples verificações de estado do botão.
Componentes
LED embutido.
Botão de controle (conectado ao pino GPIO 5 com resistência de pull-up).
Como Usar
Instalar Dependências

Configure o ambiente de desenvolvimento adequado para compilar o código.
Compilação e Upload

Clone este repositório e use uma ferramenta como CMake para compilar e enviar o código para o dispositivo.
Operação

O LED inicia desligado.
Pressione o botão para começar o piscar do LED com uma velocidade de 1 ciclo por segundo.
A cada pressionamento do botão, a velocidade de piscamento aumenta.
Quando a velocidade atinge o valor 5, o LED é desligado.
