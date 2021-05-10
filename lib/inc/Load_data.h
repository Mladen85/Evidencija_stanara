#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"


// extern std::vector<SpisakStanara::Stan> zgrada;

namespace SpisakStanara
{
    int ReadZgradaFromFile(std::vector<Stan> &v_zgrada);
}

#endif //LOAD_DATA_H
