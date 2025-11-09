# Diagrama Eletrônico
---
![Visualização Rápida do Diagrama](Diagrama_Eletrônico(Equipe_3).png)

## Descrição Geral
O robô será controlado pelo **microcontrolador ESP32**, responsável pela conexão com o **controle via Bluetooth** e por todo o gerenciamento do sistema.  

O **ESP32** será alimentado por uma **bateria de 7,4 V**, cuja tensão será reduzida para **5 V** por meio de um **regulador de tensão**, evitando danos à placa.  
O circuito conta também com uma **chave alavanca (switch)** para ligar e desligar o sistema.

---

## 🔌 Notas Importantes
- Não é obrigatório seguir fielmente a pinagem mostrada no diagrama — alterações nos pinos podem ser feitas conforme a necessidade.  
- A **ponte H L298N** é utilizada apenas **para fins genéricos de diagramação**, sendo que o módulo definitivo será o **L9110S**.

---

## 💡 Conexões e Controle
As portas do **ESP32** serão responsáveis pelo controle de:
- **LEDs**, utilizados para indicar o estado do robô (ligado, conectado, etc.);  
- **Buzzer**, que emitirá respostas sonoras de acordo com as ações do sistema;  
- **Módulo Ponte H**, responsável pela movimentação dos motores.

A **ponte H** será a responsável por controlar os **motores N20**.  
Ela será alimentada pela **saída OUT+ do regulador de tensão**, ou opcionalmente pelo **pino 3.3 V da ESP32** (conforme ilustrado no diagrama, o regulador é a fonte principal de alimentação).

---

## ⚙️ Detalhamento das Portas
- **L298N (modelo genérico no diagrama):**  
  - 6 portas da ESP32 são utilizadas.  
  - 2 portas controlam a **velocidade (PWM)**.  
  - 4 portas funcionam como **entradas de controle (IN)** para os motores.

- **L9110S (módulo definitivo):**  
  - Utiliza **4 portas da ESP32**, sendo **2 para PWM**, mesmo que não sejam oficialmente portas PWM.

---

