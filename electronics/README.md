# Diretório de Eletrônica
---

Este diretório concentra toda a documentação referente à parte **eletrônica** do Robô Mini Sumô, incluindo o **esquema elétrico**, **layout da PCB**, **diagrama de conexão**, **componentes utilizados** e **datasheets** dos módulos empregados no projeto.

---

## Visão Geral
O sistema eletrônico foi projetado para controlar o robô de forma eficiente e modular.  
A estrutura geral é composta por:
- **ESP32** como unidade principal de controle;
- **Módulo Ponte H L9110S** para acionamento dos motores N20;
- **Regulador Buck** para conversão da tensão das baterias;
- **LEDs e buzzer** para indicação de status e respostas sonoras;
- **Interruptor principal** para controle de energia do sistema.

---

## ⚙️ Componentes Eletrônicos
Os principais componentes utilizados na montagem do robô são:

- Microcontrolador **ESP32**  
- Módulo Ponte H Dupla **L9110S**  
- **2 Motores N20**  
- **Regulador de Tensão Buck**  
- **Buzzer Passivo**  
- **2 LEDs Indicadores**  
- **Barramentos e fios de conexão**  
- **2 Pilhas Li-Ion 3,7V**  
- **Suporte de Bateria**  
- **Carregador e módulo de carga de bateria**  
- **Placa de Fenolite Perfurada Ilhada (7x9cm)**  

---

## 📄 Estrutura da Documentação

### [Diagrama Eletrônico](./Diagrama_Eletrônico)
Contém o esquema elétrico detalhado do circuito, mostrando as interconexões entre os módulos, sensores e atuadores utilizados no projeto.

### [Diagrama de Conexão](./Diagrama_de_Conexão)
Apresenta a disposição prática das ligações entre os componentes.  
> Caso haja dúvidas na montagem física, recomenda-se utilizar este diagrama como referência principal.

![Visualização do Diagrama de Conexão](Diagrama_de_Conexão/Diagrama_de_conexao.jpeg)

---

### [Layout PCB](./Layout_PCB)
Contém os arquivos e visualizações do **layout da placa de circuito impresso** (PCB), incluindo a versão 2D e a renderização 3D da montagem.

> Apesar da fabricação da placa ser **manual**, utilizando **placa perfurada de fenolite**, os arquivos **Gerber**, **SVG** e demais formatos estão anexados para documentação e referência futura.

![Visualização 2D e 3D da PCB](Layout_PCB/Visualizacao_2D_e_3D_PCB.jpeg)

---

### 📚 [Datasheet](./Datasheet)
Reúne os **datasheets** dos principais módulos e componentes eletrônicos empregados no projeto, contendo especificações, diagramas e características técnicas.

| Arquivo (Datasheet) | Componente | Tipo/Modelo | Função no Projeto |
| :--- | :--- | :--- | :--- |
| `esp32_datasheet.pdf` | Módulo Principal | ESP32-WROOM | Microcontrolador central com conectividade Wi-Fi e Bluetooth. |
| `LM2596.PDF` | Regulador de Tensão | LM2596 | Conversor DC-DC Step-Down para alimentar o módulo principal. |
| `l9110_2_channel_motor_driver.pdf` | Driver de Motor | L9110S | Módulo de acionamento para controle dos motores DC. |
| `N20-Micro-Speed-Gear-Motor.pdf` | Atuador | Motor N20 | Motor DC com caixa de redução para movimentação. |

---

## Conclusão

Esta documentação tem como objetivo centralizar todas as informações referentes à parte eletrônica do Robô Mini Sumô, oferecendo suporte completo à reprodução, manutenção e entendimento do sistema desenvolvido.

---
