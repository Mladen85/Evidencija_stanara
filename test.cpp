#include "lib/inc/Stan.h"
#include "lib/inc/Stanar.h"
#include "lib/inc/Load_data.h"
#include <iostream>

void PrintStan(SpisakStanara::Stan &stan);

int main()
{
    SpisakStanara::Stan stan;
    SpisakStanara::Stanar stanar;

    //This call will cause Error -1073741819 when try to access pointer to 'stan' (which is not yet initialized)
    // PrintStan(stan);

    stan.setBrojStan(10);
    stan.setPovrsina(25.0);
    stanar.setStan((SpisakStanara::Stan*)&stan);

    PrintStan(stan);

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

    PrintStan(stan);

    std::cout << "END_OF_PROGRAM\n";
    return 0;
}

void PrintStan(SpisakStanara::Stan &stan)
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
    std::cout << std::endl;
}