#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Stan.h"
#include "Stanar.h"
#include "Load_data.h"

namespace
{
    int OpenFile(std::fstream &file, const std::string &file_name)
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

        // file.open(file_path, std::ios::in | std::ios::out);
        file.open(file_path, std::fstream::in | std::fstream::out | std::fstream::trunc);    // Clear file
        // file.open(file_path, std::ios::in | std::ios::out | std::ios::ate);      // Append to file
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

    int CloseFile(std::fstream &file)
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

    // void FormatWriteStan(std::ostream &out, const SpisakStanara::Stan &stan)
    std::ostream &operator<<(std::ostream &out, const std::vector<SpisakStanara::Stan> &v_zgrada)
    {
        for (int i = 0; i < v_zgrada.size(); i++)
        {
            out << v_zgrada[i];
            for (int j = 0; j < v_zgrada[i].getStanari().size(); j++)
            {
                out << v_zgrada[i].getStanari()[j];
                if (j < (v_zgrada[i].getStanari().size() - 1))
                {
                    out << "--" << std::endl;
                }
            }
            out << "END_STAN";
            out << std::endl;
        }
    }

    void OverwriteEqualStan(
        std::ostream &file,
        std::vector<SpisakStanara::Stan> write_stan,
        std::vector<SpisakStanara::Stanar> v_equal_stanar)
    {
        ;
    }

    void WriteData(std::fstream &file, std::vector<SpisakStanara::Stan> &v_zgrada)
    {
        // std::fstream::pos_type pos_end_of_file = file.tellp();
        file.seekp(0, std::ios::end);
        const std::fstream::pos_type pos_end_of_file = file.tellp();
        file.seekp(0);
        int tmp_br_stan;
        float tmp_povrsina;
        std::string tmp_ime;
        std::string tmp_prezime;
        std::string tmp_tel;
        std::string tmp_email;
        // std::string tmp_string;
        std::string end_stan;

        // std::ostream print_stan = " ";

        int index = 0;
        // Current position of stan in file
        std::fstream::pos_type pos = file.tellp();
        // Position to write stan to file if br_stan in vector is less than br_stan in file
        std::fstream::pos_type pos_less = pos;
        // Position to write stan to file if br_stan is equal
        std::fstream::pos_type pos_equal = pos;
        // unsigned char first_enter_less = 1;

        // If file is empty, write entire vector
        if (pos_end_of_file == pos)
        {
            // for (int i = 0; i < v_zgrada.size(); i++)
            // {
            //     // FormatWriteStan(print_stan, v_zgrada[i]);
            //     // std::cout << print_stan << std::endl;
            //     file << v_zgrada << std::endl;
            // }

            // try
            // {
                file << v_zgrada;
               
                // file << std::endl;
            // }
            // catch(const std::exception& e)
            // {
            //     std::cerr << e.what() << '\n';
            // }

            //File was empty, just print vector to file and exit
            return;
        }

        #if 1
        // std::vector<SpisakStanara::Stan>::iterator write_begin = v_zgrada.begin();
        // std::vector<SpisakStanara::Stan>::iterator write_end = v_zgrada.begin();
        int write_begin = 0;
        int write_end = 0;
        // 0 - dont write, 1 - write
        unsigned char write_flag = 0;

        while(file >> tmp_br_stan >> tmp_povrsina)
        {
            // Check if br_stan_v is less than br_stan_f
            if (v_zgrada[index].getBrojStan() < tmp_br_stan)
            {
                // if (first_enter_less == 1)
                if (write_flag == 0)
                {
                    // first_enter_less = 0;
                    write_flag = 1;
                    pos_less = pos;
                    write_begin = index;
                    write_end = index;
                }
                else
                {
                    write_end++;
                }
                
            }
            else
            {
                // write only once, not every time in else
                if (write_flag == 1)
                {
                    write_flag = 0;
                    file.seekp(pos_less);
                    std::vector<SpisakStanara::Stan> write_zgrada(v_zgrada.begin() + write_begin, v_zgrada.end() + write_end);
                    file << write_zgrada;
                }

                // Check if br_stan_v is equal to br_stan_f
                if (v_zgrada[index].getBrojStan() == tmp_br_stan)
                {
                    std::vector<SpisakStanara::Stanar> v_equal_stanar;
                    // SpisakStanara::Stanar tmp_equal_stanar;
                    while (file >> tmp_ime >> tmp_prezime >> tmp_tel >> tmp_email >> end_stan)
                    {
                        SpisakStanara::Stanar tmp_equal_stanar;

                        if (tmp_ime != "0")
                        {
                            tmp_equal_stanar.setIme(tmp_ime);
                        }

                        if (tmp_prezime != "0")
                        {
                            tmp_equal_stanar.setPrezime(tmp_prezime);
                        }

                        if (tmp_tel != "0")
                        {
                            tmp_equal_stanar.setTelBroj(tmp_tel);
                        }

                        if (tmp_email != "0")
                        {
                            tmp_equal_stanar.setEmail(tmp_email);
                        }

                        v_equal_stanar.push_back(tmp_equal_stanar);

                        if (end_stan == "END_STAN")
                        {
                            break;
                        }
                    }
                    // write_begin = v_zgrada.begin() + index;
                    // write_end = v_zgrada.begin() + index;
                    std::vector<SpisakStanara::Stan> write_stan(v_zgrada.begin() + index, v_zgrada.begin() + index);
                    file.seekp(pos);

                    OverwriteEqualStan(file, write_stan, v_equal_stanar);
                    // write_flag = 1;
                }
                else
                {
                    while ((file >> end_stan) && (end_stan != "END_STAN"))
                    {
                        // do nothing
                    }
                }
            }

            index++;
            pos = file.tellp();
            // if(pos_end_of_file == pos)
            // {
            //     index--;
            //     break;
            // }
        }

        index--;    // Undo last increment in while loop (last increment is false)
        int temp_size = v_zgrada.size();
        if (index < v_zgrada.size())
        {
            // std::cout << std::endl;
            std::vector<SpisakStanara::Stan> write_stan(v_zgrada.begin() + index, v_zgrada.end());
            file << write_stan;
        }
        #endif
    }
}

namespace SpisakStanara
{
    int WriteZgradaToFile(std::vector<Stan> &v_zgrada)
    {
        std::fstream file_ld;
        std::string file_name = "Spisak_stanara.txt";

        std::cout << std::endl;
        if (OpenFile(file_ld, file_name) == 1)
        {
        }
        else
        {
            return -1;
        }

        WriteData(file_ld, v_zgrada);

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