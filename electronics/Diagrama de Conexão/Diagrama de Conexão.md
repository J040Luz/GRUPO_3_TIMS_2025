## Diagrama de Conexão
---
## ⚙️ Detalhes das Ligações
O **microcontrolador ESP32** é o elemento central da conexão, sendo responsável por interligar os seguintes módulos e dispositivos:

- **Ponte H (L9110S):** conecta-se às portas digitais da ESP32 responsáveis pelo controle de direção e velocidade dos motores N20;  
- **Motores N20:** recebem alimentação e controle diretamente da ponte H;  
- **Regulador de Tensão:** fornece a saída de 5V a partir das baterias de 7,4V para alimentar a ESP32 e os demais módulos;  
- **LEDs e Buzzer:** conectados a portas digitais do microcontrolador, utilizados como indicadores de estado e alertas sonoros;  
- **Interruptor (Switch):** posicionado entre a bateria e o regulador de tensão, permitindo ligar e desligar o circuito.
---
## Visualização

![Diagrama de Conexão do Robô Mini Sumo](Diagrama_de_Conexão.jpeg)
