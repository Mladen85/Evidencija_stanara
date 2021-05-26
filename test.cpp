// #include "lib/inc/Stan.h"
// #include "lib/inc/Stanar.h"
// #include "lib/inc/Load_data.h"
#include <iostream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"
#include "Load_data.h"
#include "Save_data.h"

// #include <fstream>

void PrintStan(const SpisakStanara::Stan &stan);
void PrintZgrada(const std::vector<SpisakStanara::Stan> &v_zgrada);
// extern int OpenFile(std::ifstream &file, std::string file_name);

int main()
{
    std::vector<SpisakStanara::Stan> v_zgrada;
    SpisakStanara::Stan stan;
    SpisakStanara::Stanar stanar;

    //This call will cause Error -1073741819 when try to access pointer to 'stan' (which is not yet initialized)
    // PrintStan(stan);


    SpisakStanara::ReadZgradaFromFile(v_zgrada);

    // Look if stan_br 9 is already added if previously stan_br 10 was added
    bool is_stan9 = false;
    for (int i = 0; i < v_zgrada.size(); i++)
    {
        if(v_zgrada[i].getBrojStan() == 9)
        {
            is_stan9 = true;
        }
        if ((v_zgrada[i].getBrojStan() == 10) && (!is_stan9))
        {
            is_stan9 = true;
        }
    }

    if(is_stan9)
    {
        SpisakStanara::Stan stan9;
        SpisakStanara::Stanar stanar9;
        // Add stan_br 9
        stan9.setBrojStan(9);
        stan9.setPovrsina(20.0);
        stanar9.setStan(stan9);

        stanar9.setIme("Ime9");
        stanar9.setPrezime("Prezime9");
        stanar9.setTelBroj("009/11-11-111");
        stanar9.setEmail("ime9@mail.com");

        stan9.setStanari().push_back(stanar9);

        stanar9.setIme("Ime9_2");
        stanar9.setPrezime("Prezime9_2");
        stanar9.setTelBroj("009/22-22-222");
        stanar9.setEmail("ime9_2@mail.com");

        stan9.setStanari().push_back(stanar9);

        v_zgrada.push_back(stan9);
        // Added stan_br 9
    }

    // Add stan_br 10
    stan.setBrojStan(10);
    stan.setPovrsina(25.0);
    stanar.setStan(stan);

    stanar.setIme("Ime1");
    stanar.setPrezime("Prezime1");
    stanar.setTelBroj("001/11-11-111");
    stanar.setEmail("ime1@mail.com");

    stan.setStanari().push_back(stanar);

    stanar.setIme("Ime2");
    stanar.setPrezime("Prezime2");
    stanar.setTelBroj("002/22-22-222");
    stanar.setEmail("ime2@mail.com");

    stan.setStanari().push_back(stanar);

    v_zgrada.push_back(stan);
    // Added stan_br 10

    PrintZgrada(v_zgrada);
    std::cout << std::endl;

    SpisakStanara::WriteZgradaToFile(v_zgrada);

    std::cout << "END_OF_PROGRAM\n";
    // std::ifstream file;
    // OpenFile(file, "data_file/Spisak_stanara.txt");

    return 0;
}

void PrintStan(const SpisakStanara::Stan &stan)
{
    std::cout << "Stan broj " << stan.getBrojStan() << " ima " << stan.getStanari().size() << " stanara." << std::endl;
    std::cout << "Stanari su:\n";
    for (int i = 0; i < stan.getStanari().size();i++)
    {
        std::cout << stan.getStanari()[i].getIme() << " ";
        std::cout << stan.getStanari()[i].getPrezime() << " ";
        std::cout << stan.getStanari()[i].getTelBroj() << " ";
        std::cout << "\"" << stan.getStanari()[i].getEmail() << "\"" << std::endl;
    }
    if(stan.getStanari().size() > 0)
    {
        std::cout << "Povrsina stana je: " << stan.getStanari()[0].getStan().getPovrsinaStan() << std::endl;
    }
    std::cout << "Povrsina stana je: " << stan.getPovrsinaStan() << std::endl;
    std::cout << std::endl;
}

void PrintZgrada(const std::vector<SpisakStanara::Stan> &v_zgrada)
{
    std::cout << std::endl;
    std::cout << "Print Zgrada:" << std::endl;
    if(v_zgrada.size() <= 0)
    {
        return;
    }

    for (int i = 0; i < v_zgrada.size(); i++)
    {
        PrintStan(v_zgrada[i]);
    }

    std::cout << std::endl;
}