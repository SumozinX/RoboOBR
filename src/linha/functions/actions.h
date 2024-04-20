#ifndef linha_actions
#define linha_actions

#include <configs/functions/motor/motor.h>
#include <configs/functions/sensores/sensores.h>
#include <Arduino.h>

class LinhaActions{

    int frente_direita;
    int frente_esquerda;
    int tras_direita;
    int tras_esquerda;
    int velocidade;

    int d_s0;
    int d_s1;
    int d_s2;
    int d_s3;
    int d_led;
    int d_out;

    int e_s0;
    int e_s1;
    int e_s2;
    int e_s3;
    int e_led;
    int e_out;

    int saida_infra_direita;
    int saida_infra_esquerdo;

    Motor motor{frente_direita, frente_esquerda, tras_direita, tras_esquerda, velocidade};
    Sensores sensor;

    public:
        void desviar_obstaculo() {
            
            motor.parar(0.1);
            motor.tras();
            delay(1000 * 0.5);
            motor.parar(0.1);
            motor.esquerda90graus();
            motor.parar(0.1);
            motor.frente();
            delay(1000 * 0.7);
            motor.parar(0.1);
            motor.direita90graus();
            motor.parar(0.1);
            motor.frente();
            delay(1000 * 1.4);
            motor.parar(0.1);
            motor.direita90graus();
            motor.frente();

            if (
                sensor.infra_direita(d_out) ||
                sensor.infra_esquerda(e_out)
            ) {
                motor.direita90graus();
            }

        }

        void manter_linha() {

            if (
                sensor.infra_direita(saida_infra_direita) &&
                sensor.infra_esquerda(saida_infra_esquerdo) == false
                ) {
                motor.parar(0);
                motor.esquerda();
            }
            else if (
                sensor.infra_esquerda(saida_infra_esquerdo) &&
                sensor.infra_direita(saida_infra_direita) == false
                ) {
                motor.parar(0);
                motor.direita();
            }
        }
        
        void virar_verde() {
            
            if (
                sensor.cor_direita(d_s0, d_s1, d_s2, d_s3, d_out, d_led) &&
                sensor.cor_esquerda(e_s0, e_s1, e_s2, e_s3, e_out, e_led) == false &&
                sensor.infra_direita(saida_infra_direita) 
            ) {
                motor.parar(0.2);
                motor.esquerda90graus();
            }

            else if (
                sensor.cor_esquerda(e_s0, e_s1, e_s2, e_s3, e_out, e_led) &&
                sensor.cor_direita(d_s0, d_s1, d_s2, d_s3, d_out, d_led) == false &&
                sensor.infra_esquerda(saida_infra_esquerdo)
            ){
                motor.parar(0.2);
                motor.direita90graus();
            } 
        }

        void sem_saida() {

            if (
                sensor.cor_direita(d_s0, d_s1, d_s2, d_s3, d_out, d_led) &&
                sensor.cor_esquerda(e_s0, e_s1, e_s2, e_s3, e_out, e_led)
                ) {
                    motor.parar(0);
                    motor.girar_eixo();
                }
            }
            
        void comecar() {
            motor.frente();
        }
   
};

#endif