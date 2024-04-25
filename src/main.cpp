#include<Arduino.h>
#include <linha/configs/actions.h>

void setup() {

}

LinhaActions linha;

void loop() {

    linha.comecar();
    linha.desviar_obstaculo();
    linha.sem_saida();
    linha.virar_verde();
    linha.manter_linha();

}
