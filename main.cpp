#include <iostream>

#include "Solver/IDDFSSolver.h"
using namespace  std;

#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"

int main() {
    RubiksCube3dArray object3DArray;

    object3DArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    vector<RubiksCube::MOVE>moveToshuffle=object3DArray.randomShuffleCube(5);
    for (auto move : moveToshuffle) {
        cout<<object3DArray.getMove(move)<<endl;
    }
    // object3DArray.uPrime();


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
    IDDFSSolver<RubiksCube3dArray,Hash3d>solver(object3DArray);

    vector<RubiksCube::MOVE>moves=solver.solve();
    for (auto move : moves) {
        cout << RubiksCube::getMove(move) << "\n";
    }
    solver.rubiksCube.print();


    return 0;
}