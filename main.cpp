#include <iostream>
using namespace  std;

#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.cpp"

int main() {
    RubiksCube3dArray object3DArray;

    object3DArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    object3DArray.u();
    object3DArray.uPrime();


    object3DArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";


    // RubiksCube1dArray object1dArray;

    // object1dArray.print();
    // object1dArray.u();
    // object1dArray.uPrime();
    // object1dArray.print();
    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    DFSSolver<RubiksCube3dArray,Hash3d>solver(object3DArray,8);

    vector<RubiksCube::MOVE>moves=solver.solve();
    for (auto move : moves) {
        cout << RubiksCube::getMove(move) << "\n";
    }


    return 0;
}