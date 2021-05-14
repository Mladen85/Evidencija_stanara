#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Stan.h"
#include "Stanar.h"


// extern std::vector<SpisakStanara::Stan> zgrada;

namespace SpisakStanara
{
    int WriteZgradaToFile(std::vector<Stan> &v_zgrada);
}

#endif //SAVE_DATA_H
