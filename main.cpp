#include <iostream>
using namespace  std;

#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCube3dArray.cpp"

int main() {
    // RubiksCube3dArray object3DArray;
    //
    // object3DArray.print();
    //
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    //
    // object3DArray.u();
    // object3DArray.uPrime();
    //
    //
    // object3DArray.print();
    //
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";


    RubiksCube1dArray object1dArray;

    object1dArray.print();
    object1dArray.u();
    object1dArray.print();
    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    return 0;
}