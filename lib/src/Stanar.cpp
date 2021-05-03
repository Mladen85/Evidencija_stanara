#include <iostream>
#include "Stanar.h"
#include "Stan.h"

namespace Stan
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
        if(stan != nullptr)
        {
            return *stan;
        }
        else
        {
            Stan temp_stan;
            return temp_stan;
        }
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

    Stan *Stanar::setStan()
    {
        return stan;
    }
}
