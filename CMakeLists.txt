cmake_minimum_required(VERSION 3.13)
project(speller)

set(CMAKE_CXX_STANDARD 17)

add_executable(speller main.cpp
            "DataStructures/ChainHashTable.cpp"
            "DataStructures/BinaryTree.cpp"
            "DataStructures/VectorWrapper.cpp"
            "DataStructures/UnorderedSetWrapper.cpp"
            Speller.cpp
            Timer.cpp
            )

target_link_libraries(speller PRIVATE stdc++fs)