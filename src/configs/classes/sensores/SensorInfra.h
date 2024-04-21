#ifndef infra_h
#define infra_h

#include<Arduino.h>

class InfraVermelho {
    private:

        int out;
        
    public:

        InfraVermelho (int out_) {
            out = out_;
            pinMode(out, INPUT);
        };

        bool detectar() {
            return digitalRead(out) == LOW;
    }        

};

#endif