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
std::vector<SpisakStanara::Stan> zgrada;

//Explanation: Unnamed namespace is equivalent to static func in C
//             Static keyword can also be used (but be carefull not to mix with static member functions)
namespace
{
    int OpenFile(std::ifstream &file, std::string file_name)
    {
        std::string file_path = "../../data_file/";
        if((CreateDirectory(file_path.c_str(), NULL)) || (ERROR_ALREADY_EXISTS == GetLastError()))
        file_path.append(file_name);
        file.open(file_path);
        if(file.is_open())
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    void Load_Data()
    {
        std::ifstream file_ld;
        std::string file_name = "";
        OpenFile(file_ld, file_name);
    }
}
