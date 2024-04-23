#ifndef Distancia_h
#define Distancia_h

#include<Arduino.h>

class Distancia {

    private:
        int echo;
        int trig;

    public:
        Distancia 
        (
            int pino_echo,
            int pino_trig
        ) {
            echo = pino_echo;
            trig = pino_trig;

            pinMode(trig, OUTPUT);
            pinMode(echo, INPUT);
        };

        float getDistancia() {

            digitalWrite(trig,LOW);
            delayMicroseconds(2);
            digitalWrite(trig,HIGH);
            delayMicroseconds(10);
            digitalWrite(trig,LOW);

            return pulseIn(echo, HIGH)/58.0;
        }
};

#endif