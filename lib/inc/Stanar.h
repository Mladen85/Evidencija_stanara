#ifndef STANAR_H
#define STANAR_H

#include <iostream>
// #include "Stan.h"



namespace SpisakStanara
{
    class Stan;

    class Stanar
    {
    private:
        std::string ime;
        std::string prezime;
        std::string tel_broj;
        std::string email;
        Stan *stan;

    public:
        // friend Stan;
        //Constructors
        Stanar();

        //Destructor
        // ~Stanar() = default;

        //Getters
        std::string getIme() const;
        std::string getPrezime() const;
        std::string getTelBroj() const;
        std::string getEmail() const;
        Stan &getStan() const;

        //Setters
        void setIme(const std::string &n_ime);
        void setPrezime(const std::string &n_prezime);
        void setTelBroj(const std::string &n_tel_broj);
        void setEmail(const std::string &n_email);
        void setStan(Stan &new_stan);
    };

    std::ostream &operator<<(std::ostream &out, const Stanar &stanar);
}

#endif //STANAR_H
