cmake_minimum_required(VERSION 3.13)
project(speller)

set(CMAKE_CXX_STANDARD 14)

add_executable(speller main.cpp "data structures/checker.h"
        "data structures/ChainHashTable.h" "data structures/ChainHashTable.cpp"
        "data structures/BinaryTree.h" "data structures/BinaryTree.cpp"
        "data structures/VectorFacade.cpp" "data structures/VectorFacade.h"
        "data structures/HashMapFacade.cpp" "data structures/HashMapFacade.h" Speller.cpp Speller.h Timer.cpp Timer.h)


