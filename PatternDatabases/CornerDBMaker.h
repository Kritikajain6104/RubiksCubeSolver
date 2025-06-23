//
// Created by kriti on 23-06-2025.
//

#ifndef CORNERDBMAKER_H
#define CORNERDBMAKER_H

#include "CornerPatternDatabase.h"
#include "../Model/RubiksCube3dArray.cpp"
using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};



#endif //CORNERDBMAKER_H
