#include <iostream>
#include "Stanar.h"
// #include "Stan.h"

namespace SpisakStanara
{
    //Constructors
    Stanar::Stanar()
    {
        ime = "";
        prezime = "";
        tel_broj = "";
        email = "";
        stan = nullptr;
    }


    //Getters
    std::string Stanar::getIme() const
    {
        return ime;
    }

    std::string Stanar::getPrezime() const
    {
        return prezime;
    }

    std::string Stanar::getTelBroj() const
    {
        return tel_broj;
    }

    std::string Stanar::getEmail() const
    {
        return email;
    }

    Stan &Stanar::getStan() const
    {
        // if(stan != nullptr)
        // {
            return *stan;
        // }
        // else
        // {
        //     Stan temp_stan;
        //     return temp_stan;
        // }
    }


    //Setters
    void Stanar::setIme(const std::string &n_ime)
    {
        ime = n_ime;
    }

    void Stanar::setPrezime(const std::string &n_prezime)
    {
        prezime = n_prezime;
    }

    void Stanar::setTelBroj(const std::string &n_tel_broj)
    {
        tel_broj = n_tel_broj;
    }

    void Stanar::setEmail(const std::string &n_email)
    {
        email = n_email;
    }

    void Stanar::setStan(Stan &new_stan)
    {
        stan = &new_stan;
    }

    //Operator << overload
    std::ostream &operator<<(std::ostream &out, const Stanar &stanar)
    {
        if(stanar.getIme() != "")
        {
            out << stanar.getIme() << std::endl;
        }
        else
        {
            out << "0" << std::endl;
        }

        if (stanar.getPrezime() != "")
        {
            out << stanar.getPrezime() << std::endl;
        }
        else
        {
            out << "0" << std::endl;
        }

        if (stanar.getTelBroj() != "")
        {
            out << stanar.getTelBroj() << std::endl;
        }
        else
        {
            out << "0" << std::endl;
        }

        if (stanar.getEmail() != "")
        {
            out << stanar.getEmail() << std::endl;
        }
        else
        {
            out << "0" << std::endl;
        }

        return out;
    }
}
