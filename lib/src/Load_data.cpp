#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Load_data.h"
#include "Stanar.h"
#include "Stan.h"

//Global variables
std::vector<Stan::Stan> zgrada;

//Explanation: Unnamed namespace is equivalent to static func in C
//             Static keyword can also be used (but be carefull not to mix with static member functions)
namespace
{
    int OpenFile(std::ifstream file, std::string file_name)
    {
        std::string file_path = "../../data_file/";
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
}