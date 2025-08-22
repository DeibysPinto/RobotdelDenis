#include "motores.h"
#include "Arduino.h"

void initMotors() {
    ledcSetup(3, 2000, 8);
    ledcSetup(4, 2000, 8);
    ledcSetup(5, 2000, 8);
    ledcSetup(6, 2000,  ledcAttachPin(12, 3));
    ledcAttachPin(13, 4);
    ledcAttachPin(14, 5);
    ledcAttachPin(15, 6);
}

void detenerMotores() {
    ledcWrite(3, 0);
    ledcWrite(4, 0);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
}

void moverAdelante(int velocidad) {
    ledcWrite(4, velocidad);
    ledcWrite(3, 0);
    ledcWrite(5, velocidad);
    ledcWrite(6, 0);
}

void moverAtras(int velocidad) {
    ledcWrite(4, 0);
    ledcWrite(3, velocidad);
    ledcWrite(5, 0);
    ledcWrite(6, velocidad);
}

void girarIzquierda(int velocidad) {
    ledcWrite(4, velocidad);
    ledcWrite(6, velocidad);
}

void girarDerecha(int velocidad) {
    ledcWrite(3, velocidad);
    ledcWrite(5, velocidad);
}
