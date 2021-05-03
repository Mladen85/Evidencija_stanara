#ifndef STAN_H
#define STAN_H

#include <iostream>
#include <vector>
#include "Stanar.h"

namespace Stan
{
    class Stan
    {
    private:
        int broj_stan;
        int broj_stanara;
        std::vector<Stanar> stanari;
        float povrsina_stan;

    public:
        //Constructor
        Stan();

        //Getters
        int getBrojStan() const;
        int getBrojStanara() const;
        std::vector<Stanar> getStanari() const;
        float getPovrsinaStan() const;

        //Setters
        void setBrojStan(int br_stan);
        void setBrojStanara(int br_stanara);
        std::vector<Stanar> &setStanari();
        void setPovrsina(float povrsina);
    };
}

#endif //STAN_H