#ifndef SensorCor_h
#define SensorCor_h

#include<Arduino.h>

class SensorCor {

    private:

        int s0;
        int s1;
        int s2;
        int s3;
        int out;
        int led;

    public:

        SensorCor 
        (
            int s_0,
            int s_1,
            int s_2,
            int s_3,
            int out_,
            int led_
        ) {
            s0 = s_0;
            s1 = s_1;
            s2 = s_2;
            s3 = s_3;
            out = out_;
            led = led_;

            pinMode(s0, OUTPUT);
            pinMode(s1, OUTPUT);
            pinMode(s2, OUTPUT);
            pinMode(s3, OUTPUT);
            pinMode(led, OUTPUT);
            pinMode(out, INPUT);
        };

        bool CorVerde() {

            digitalWrite(s0, true);
            digitalWrite(s1, false);

            digitalWrite(s2, LOW);
            digitalWrite(s3, LOW);
            float CorVermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    
            digitalWrite(s2, HIGH);
            float CorBranco = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
                
            digitalWrite(s2, LOW);
            digitalWrite(s3, HIGH);
            float CorAzul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
                
            digitalWrite(s2, HIGH);
            float CorVerde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

            if ((CorVerde < CorAzul) && (CorVerde < CorVermelho) && (CorBranco < 50)) {
                return (CorAzul > 50) || (CorVermelho > 50);
            }
            return false;
        }
};

#endif