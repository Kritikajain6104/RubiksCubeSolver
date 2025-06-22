//
// Created by kriti on 22-06-2025.
//



//
// Created by kriti on 22-06-2025.
//

#ifndef BFSSOLVER_H
#define BFSSOLVER_H
#include "../Model/RubiksCube.h"


template<typename T,typename H>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T, RubiksCube::MOVE, H> move_done;
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube]=true;
        while (!q.empty()) {
            T cube = q.front();
            q.pop();
            if (cube.isSolved()) {
                return cube;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                T child = cube;
                child.move(curr_move);
                if (!visited[child]) {
                    visited[child] = true;
                    move_done[child] = curr_move;
                    q.push(child);
                }
            }

        }
        return rubiksCube;
    }
public:
    T rubiksCube;

     BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    //    Performs BFS and returns the vector of moves done to solve the cube
    vector<RubiksCube::MOVE> solve() {
        T solved_cube = bfs();
         if (!solved_cube.isSolved()) {
             cout << "ERROR: Cube is not solved after BFS!" << endl;
             exit(1);  // Or handle gracefully
         }

        T curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }


};



#endif //BFSSOLVER_H
