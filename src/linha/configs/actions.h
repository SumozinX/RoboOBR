#ifndef linha_actions
#define linha_actions

#include <linha/configs/classes/motor/motor.h>
#include <linha/configs/classes/sensores/sensores.h>
#include <linha/configs/classes/sensores/SensorCor.h>
#include <linha/configs/classes/sensores/SensorDistancia.h>
#include <linha/configs/classes/sensores/SensorInfra.h>
#include <Arduino.h>

class LinhaActions{

    const int frente_direita = 0;
    const int frente_esquerda = 0;
    const int tras_direita = 0;
    const int tras_esquerda = 0;
    const int velocidade = 0;

    const int echo = 0;
    const int trig = 0;

    const int d_s0 = 0;
    const int d_s1 = 0;
    const int d_s2 = 0;
    const int d_s3 = 0;
    const int d_led = 0;
    const int d_out = 0;

    const int e_s0 = 0;
    const int e_s1 = 0;
    const int e_s2 = 0;
    const int e_s3 = 0;
    const int e_led = 0;
    const int e_out = 0;

    const int saida_infra_direita = 0;
    const int saida_infra_esquerdo= 0;

    Motor motor{frente_direita, frente_esquerda, tras_direita, tras_esquerda, velocidade};
    SensorCor cor_direita {d_s0, d_s1, d_s2, d_s3, d_out, d_led};
    SensorCor cor_esquerda {e_s0, e_s1, e_s2, e_s3, e_out, e_led};
    InfraVermelho infra_esquerdo {saida_infra_esquerdo};
    InfraVermelho infra_direito {saida_infra_direita};
    Distancia distancia {echo, trig};

    public:
        void desviar_obstaculo() {
            if (distancia.getDistancia() <= 5) {
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

                while (! (infra_direito.detectar() || infra_esquerdo.detectar())) {}

                motor.esquerda90graus();   
            }
        }

        void manter_linha() {

            if (
                infra_direito.detectar() == false &&
                infra_esquerdo.detectar()
                ) {
                motor.parar(0);
                motor.esquerda();
            }
            else if (
                infra_esquerdo.detectar() == false &&
                infra_direito.detectar()
                ) {
                motor.parar(0);
                motor.direita();
            }
        }
        
        void virar_verde() {
            if (
                cor_direita.CorVerde() &&
                cor_esquerda.CorVerde() == false &&
                infra_direito.detectar()
            ) {
                motor.parar(0.2);
                motor.esquerda90graus();
            }
            else if (
                cor_esquerda.CorVerde() &&
                cor_direita.CorVerde() == false &&
                infra_esquerdo.detectar()
            ){
                motor.parar(0.2);
                motor.direita90graus();
            } 
        }

        void sem_saida() {
            if (
                cor_direita.CorVerde() &&
                cor_esquerda.CorVerde()
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