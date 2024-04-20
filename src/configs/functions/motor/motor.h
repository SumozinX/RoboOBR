#ifndef motor_h
#define motor_h

#include<Arduino.h>

//Velocidade normal 190
class Motor {
    private:

        int fre_dir;
        int fre_esq;
        int tra_dir;
        int tra_esq;
        int vel;
        int vel_max = 255;

    public:
        
        Motor(

            //passar o pino que se refere ao lado da roda
            int frente_dir,
            int frente_esq,
            int tras_dir,
            int tras_esq,
            int velocidade
        ){
            
            fre_dir = frente_dir;
            fre_esq = frente_esq;
            tra_dir = tras_dir;
            tra_esq = tras_esq;
            vel = velocidade;

            pinMode(fre_dir, OUTPUT);
            pinMode(fre_esq, OUTPUT);
            pinMode(tra_dir, OUTPUT);
            pinMode(tra_esq, OUTPUT);

        };

        void frente() {

            analogWrite(fre_dir, vel);
            analogWrite(fre_esq, vel);
        }

        void tras() {
            analogWrite(tra_dir, vel);
            analogWrite(tra_esq, vel);
        }

        void direita() {
            analogWrite(fre_esq, vel);
        }

        void esquerda() {
            analogWrite(fre_dir, vel);
        }

        void parar(double temp) {
            
            analogWrite(fre_dir, 0);
            analogWrite(fre_esq, 0);
            analogWrite(tra_dir, 0);
            analogWrite(tra_esq, 0);
            delay(temp * 1000);

        }

        void direita90graus() {
            analogWrite(fre_esq, vel_max);
            delay(2 * 1000);
            parar(0);
        }

        void esquerda90graus() {
            analogWrite(fre_dir, vel_max);
            delay(2 * 1000);
            parar(0);
        }

        void girar_eixo() {
            analogWrite(fre_dir, vel_max);
            analogWrite(tra_esq, vel_max);
            delay(1000 * 2);
            parar(0.2);

        }
};

#endif
