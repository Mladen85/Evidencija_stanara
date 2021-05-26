#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"
#include "Load_data.h"
#include <windows.h>
// #include <winerror.h>
// #include <fileapi.h>

//Global variables
// std::vector<SpisakStanara::Stan> zgrada;

//Explanation: Unnamed namespace is equivalent to static func in C
//             Static keyword can also be used (but be carefull not to mix with static member functions)
namespace
{
    int OpenFile(std::ifstream &file, const std::string &file_name)
    {
        std::string file_path = "data_file/";
        if ((CreateDirectory(file_path.c_str(), NULL)) || (ERROR_ALREADY_EXISTS == GetLastError()))
        {
            file_path.append(file_name);
            std::cout << "File path: " << file_path << std::endl;
        }
        else
        {
            std::cout << "ELSE - File path: " << file_path << std::endl;
        }

        file.open(file_path);
        if (file.is_open())
        {
            std::cout << "FILE " << file_name << " in folder " << file_path << " is open!" << std::endl;
            return 1;
        }
        else
        {
            std::cout << "FILE " << file_name << " in folder " << file_path << " is NOT open!" << std::endl;
            return -1;
        }
    }

    int CloseFile(std::ifstream &file)
    {
        file.close();
        if (file.is_open())
        {
            std::cout << "File is still open!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "File is closed!" << std::endl;
            return 1;
        }
    }

    bool IsEmptyFile(std::ifstream &file)
    {
        return file.peek() == std::ifstream::traits_type::eof();
    }

    void LoadData(std::ifstream &file, std::vector<SpisakStanara::Stan> &v_zgrada)
    {
        SpisakStanara::Stan tmp_stan;
        SpisakStanara::Stanar tmp_stanar;
        int tmp_br_stan;
        float tmp_povrsina;
        std::string tmp_ime;
        std::string tmp_prezime;
        std::string tmp_tel;
        std::string tmp_email;
        std::string end_stan;

        while (!IsEmptyFile(file))
        {
            if (file >> tmp_br_stan >> tmp_povrsina)
            {
                tmp_stan.setBrojStan(tmp_br_stan);
                std::cout << "povrsina je: " << tmp_povrsina << std::endl;
                tmp_stan.setPovrsina(tmp_povrsina);
                std::cout << "povrsina je: " << tmp_stan.getPovrsinaStan() << std::endl;
            }
            else
            {
                return;
            }

            while (file >> tmp_ime >> tmp_prezime >> tmp_tel >> tmp_email >> end_stan)
            {
                if (tmp_ime != "0")
                {
                    tmp_stanar.setIme(tmp_ime);
                }

                if (tmp_prezime != "0")
                {
                    tmp_stanar.setPrezime(tmp_prezime);
                }

                if (tmp_tel != "0")
                {
                    tmp_stanar.setTelBroj(tmp_tel);
                }

                if (tmp_email != "0")
                {
                    tmp_stanar.setEmail(tmp_email);
                }

                // tmp_stanar.setStan(tmp_stan);
                tmp_stan.setStanari().push_back(tmp_stanar);

                if (end_stan == "END_STAN")
                {
                    break;
                }
            }

            v_zgrada.push_back(tmp_stan);
            int tmp_last = v_zgrada.size() - 1;
            for (int i = 0; i < v_zgrada[tmp_last].getStanari().size(); i++)
            {
                v_zgrada[tmp_last].setStanari()[i].setStan(v_zgrada[tmp_last]);
            }
            tmp_stan.setStanari().resize(0);
        }

        tmp_stan.setStanari().resize(0);
        // tmp_stanar.setStan(*((SpisakStanara::Stan *)0));
    }

    // void ConectStanAndStanar(std::vector<SpisakStanara::Stan> &v_zgrada)
    // {
    //     if(v_zgrada.size() <= 0)
    //     {
    //         return;
    //     }

    //     for (int i = 0; i < v_zgrada.size(); i++)
    //     {
    //         for (int j = 0; j < v_zgrada[i].getStanari().size(); j++)
    //         {
    //             v_zgrada[i].setStanari()[j].setStan(v_zgrada[i]);
    //         }
    //     }
    // }
}

namespace SpisakStanara
{
    int ReadZgradaFromFile(std::vector<Stan> &v_zgrada)
    {
        std::ifstream file_ld;
        std::string file_name = "Spisak_stanara.txt";

        std::cout << std::endl;
        if (OpenFile(file_ld, file_name) == 1)
        {
        }
        else
        {
            return -1;
        }

        LoadData(file_ld, v_zgrada);

        if (CloseFile(file_ld) == 1)
        {
        }
        else
        {
            return -2;
        }
        std::cout << std::endl;
    }
}
