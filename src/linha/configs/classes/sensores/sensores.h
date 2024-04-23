#ifndef sensor_h
#define sensor_h

#include<Arduino.h>

class Sensores {
    public:
        
        double getDistancia(int echo, int trig) {

            pinMode(trig,OUTPUT);
            digitalWrite(trig,LOW);
            delayMicroseconds(2);
            digitalWrite(trig,HIGH);
            delayMicroseconds(10);
            digitalWrite(trig,LOW);
            pinMode(echo, INPUT);
            return pulseIn(echo, HIGH)/58.0;

        }
        
        int cor_direita(
            int s0,
            int s1,
            int s2,
            int s3,
            int out,
            int led) {

            pinMode(s0, OUTPUT);
            pinMode(s1, OUTPUT);
            pinMode(s2, OUTPUT);
            pinMode(s3, OUTPUT);
            pinMode(led, OUTPUT);
            pinMode(out, INPUT);

            digitalWrite(s0, true);
            digitalWrite(s1, false);

            digitalWrite(s2, LOW);
            digitalWrite(s3, LOW);
            int CorVermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
            digitalWrite(s2, HIGH);
            int CorBranco = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
            
            digitalWrite(s2, LOW);
            digitalWrite(s3, HIGH);
            int CorAzul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
            
            digitalWrite(s2, HIGH);
            int CorVerde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

            if ((CorVerde < CorAzul) && (CorVerde < CorVermelho) && (CorBranco < 50)) {
                return (CorAzul > 50) || (CorVermelho > 50);
            }
            return false;
        }

    int cor_esquerda(        
        int s0,
        int s1,
        int s2,
        int s3,
        int out,
        int led) {
            return cor_direita(
            s0,
            s1,
            s2,
            s3,
            out,
            led);
    }

    //se for 1 quer dizer que esta na linha
    int infra_direita(int out) {

        pinMode(out, INPUT);

        return digitalRead(out) == LOW;
    }

    int infra_esquerda(int out) {
        return infra_direita(out);
    }

};

#endif