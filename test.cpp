// #include "lib/inc/Stan.h"
// #include "lib/inc/Stanar.h"
// #include "lib/inc/Load_data.h"
#include <iostream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"
#include "Load_data.h"

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

    stan.setBrojStan(10);
    stan.setPovrsina(25.0);
    stanar.setStan(stan);

    // PrintStan(stan);

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
    // PrintStan(stan);

    PrintZgrada(v_zgrada);
    std::cout << std::endl;

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