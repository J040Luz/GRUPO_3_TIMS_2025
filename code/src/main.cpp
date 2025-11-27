#include <Arduino.h>
#include <PS4Controller.h>

// ======= PINAGEM ======= //
const unsigned int buzzer = 12;

const unsigned int IN1 = 5;   // Motor Esquerdo
const unsigned int IN2 = 18;  // Motor Esquerdo
const unsigned int IN3 = 2;   // Motor Direito
const unsigned int IN4 = 4;   // Motor Direito


// ======= CALLBACKS ======= //
void onConnect() {
    Serial.println("Controle PS4 conectado!");
    PS4.setLed(255, 0, 0);      // Vermelho
    PS4.sendToController();     // Atualiza o LED
}

void onDisconnect() {
    Serial.println("Controle PS4 desconectado!");
}

// ======= DEBUG DO CONTROLE ======= //
void MAPCONTROL() {
    if (PS4.L1())          Serial.println("L1");
    if (PS4.R1())          Serial.println("R1");
    if (PS4.L2())          Serial.printf("L2: %d\n", PS4.L2Value());
    if (PS4.R2())          Serial.printf("R2: %d\n", PS4.R2Value());
    if (PS4.LStickX())     Serial.printf("LX: %d\n", PS4.LStickX());
    if (PS4.LStickY())     Serial.printf("LY: %d\n", PS4.LStickY());
    if (PS4.RStickX())     Serial.printf("RX: %d\n", PS4.RStickX());
    if (PS4.RStickY())     Serial.printf("RY: %d\n", PS4.RStickY());
}

// ======= MOVIMENTAÇÃO ======= //
void controlMovent() {

    // ======= 1. GIRO NO EIXO (PRIORIDADE MÁXIMA) ======= //
    if (PS4.L1()) {  
        // Giro à esquerda
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        return;
    }

    if (PS4.R1()) {
        // Giro à direita
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        return;
    }

    // ======= 2. PARAR SE NENHUM GATILHO ESTIVER APERTADO ======= //
    if (PS4.R2Value() == 0 && PS4.L2Value() == 0) {

        // Zona morta dos analógicos
        if (abs(PS4.LStickX()) < 20 && abs(PS4.LStickY()) < 20) {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            return;
        }
    }

    // ======= 3. MOVIMENTO PARA FRENTE ======= //
    if (PS4.R2Value() > 0) {

        // Virar para a direita
        if (PS4.LStickX() > 40) {
            digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); // Motor Esquerdo
            digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW); // Motor Direito parado
        }

        // Virar para a esquerda
        else if (PS4.LStickX() < -40) {
            digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW); // Motor Esquerdo parado
            digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); // Motor Direito
        }

        // Frente reta
        else {
            digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
        }
        return;
    }

    // ======= 4. MOVIMENTO PARA TRÁS ======= //
    if (PS4.L2Value() > 0) {

        // Virar para a direita
        if (PS4.LStickX() > 40) {
            digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);  // Esquerdo parado
            digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH); // Direito ré
        }

        // Virar para a esquerda
        else if (PS4.LStickX() < -40) {
            digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH); // Esquerdo ré
            digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);  // Direito parado
        }

        // Ré reta
        else {
            digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
            digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
        }
        return;
    }

}

// ======= SETUP ======= //
void setup() {
    Serial.begin(115200);

    pinMode(buzzer, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Inicia o Bluetooth da ESP32 e espera pelo PS4
    PS4.begin("0a:62:30:31:2f:e2");

    // Eventos
    PS4.attach(MAPCONTROL);          // Debug das entradas
    PS4.attachOnConnect(onConnect);  // LED e aviso
    PS4.attachOnDisconnect(onDisconnect);

    Serial.println("Aguardando o controle PS4...");
}


// ======= LOOP ======= //
void loop() {

    // Só executa comandos se o controle estiver conectado
    if (!PS4.isConnected()) return;

    // Movimentação principal
    controlMovent();
}