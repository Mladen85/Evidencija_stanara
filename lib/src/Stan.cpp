#include <iostream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"

namespace SpisakStanara
{
    //Constructor
    Stan::Stan()
    {
        broj_stan = -1;
        // broj_stanara = 0;
        stanari.resize(0);
        povrsina_stan = .0;
    }


    //Getters
    int Stan::getBrojStan() const
    {
        return broj_stan;
    }

    // int Stan::getBrojStanara() const
    // {
    //     return broj_stanara;
    // }

    std::vector<Stanar> Stan::getStanari() const
    {
        return stanari;
    }

    float Stan::getPovrsinaStan() const
    {
        return povrsina_stan;
    }


    //Setters
    void Stan::setBrojStan(int br_stan)
    {
        broj_stan = br_stan;
    }

    // void Stan::setBrojStanara(int br_stanara)
    // {
    //     broj_stanara = br_stanara;
    // }

    std::vector<Stanar> &Stan::setStanari()
    {
        return stanari;
    }

    void Stan::setPovrsina(float povrsina)
    {
        povrsina_stan = povrsina;
    }

    //Operator << overload
    std::ostream &operator<<(std::ostream &out, const Stan &stan)
    {
        out << stan.getBrojStan() << " " << stan.getPovrsinaStan() << std::endl;

        return out;
    }
}
