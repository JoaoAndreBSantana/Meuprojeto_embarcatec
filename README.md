Controle de LED com Botão - Desafio EmbarcaTech

DESCRIÇÃO
Este projeto foi desenvolvido para o Desafio EmbarcaTech e tem como objetivo demonstrar o uso da placa BitDogLab com C/C++. O sistema controla o LED embutido da placa de acordo com a interação do usuário via um botão. O LED inicia desligado e, a cada pressionamento do botão, sua velocidade de piscar aumenta até um limite de 5 níveis. Quando o botão é pressionado novamente após atingir o limite, o LED se apaga e o ciclo recomeça.

COMPONENTES UTILIZADOS
O projeto utiliza dois componentes principais da placa BitDogLab: o LED embutido e um botão conectado ao GPIO 5. O botão é responsável por alterar a velocidade do LED, proporcionando uma interação dinâmica com o usuário.

FUNCIONAMENTO
Ao iniciar o sistema, o LED permanece apagado. Quando o usuário pressiona o botão pela primeira vez, o LED começa a piscar em uma velocidade mínima. Com cada nova pressão, a frequência do piscar aumenta até atingir o nível máximo de 5. Caso o botão seja pressionado novamente nesse nível, o LED se apaga e o ciclo reinicia. Esse comportamento garante um controle intuitivo e simples do LED.

DEMONSTRAÇÃO
Assista ao vídeo demonstrativo do funcionamento do projeto no YouTube:
[Link para o vídeo]()

