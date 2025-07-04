//
// Created by kriti on 23-06-2025.
//

#include "CornerDBMaker.h"

#include<bits/stdc++.h>
using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    RubiksCube3dArray cube;
    queue<RubiksCube3dArray> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
    	cout << "Processing depth " << curr_depth << " with " << n << " states in queue...\n";
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++) {
            RubiksCube3dArray node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}