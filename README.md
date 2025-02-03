# Embarcatech_U4C4O12  
### TAREFA 3 - U4C4O12 - Unidade 4 - Capítulo 4
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

#### Vídeo de funcionamento
* link

#### Instruções de compilação
Certifique-se de que você tem o ambiente configurado conforme abaixo:
* Pico SDK instalado e configurado.
* VSCode com todas as extensões configuradas, CMake e Make instalados.
* Clone o repositório e abra a pasta do projeto, a extensão Pi Pico criará a pasta build
* Clique em Compile na barra inferior, do lado direito (ao lado esquerdo de RUN | PICO SDK)
* Verifique se gerou o arquivo .uf2
* Conecte a placa BitDogLab e ponha-a em modo BOOTSEL
* Arraste o arquivo até a placa, que o programa se iniciará

#### Manual do programa
Ao executar o programa, todos os leds serão ligados com a cor azul, indicando o início do programa:
* A lógica do programa é que ao apertar o botão A, serão desenhados os números de uma contagem crescente de 0 a 9 em cor vermelha na matriz de LEDs. 
* Ao apertar o botão B, os números serão desenhados de forma decrescente.
* Concomitantemente, o LED RGB vermelho está piscando num período de 200ms, isto é, 5Hz (ou ainda, 5 vezes por segundo, conforme estabelecido).
* Obs. I: o debounce foi implementado nos botões, de forma que não houvesse missclick (conforme estabelecido na questão).
* Obs. II: os LEDs da matriz estão configurados com o brilho mais baixo do que 100%, pois são muito fortes.
* Obs. III: o LED inicialmente fora pensado para alternar (pisca-pisca) com sleep_ms, mas depois revi a aula de timer e acabei implementando dessa forma.
* Obs. IV: documentei todo o código com doxygen, então ao passar o cursos do mouse em cima de qualquer uma das funções, será mostrada uma pequena descrição da implementação
