cmake_minimum_required(VERSION 3.20)
project(RubiksCubeSolver)  # ✅ This line was missing

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksCubeSolver
        main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/NibbleArray.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h
        PatternDatabases/math.cpp
        PatternDatabases/math.h
)
