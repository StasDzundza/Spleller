cmake_minimum_required(VERSION 3.13)
project(speller)

set(CMAKE_CXX_STANDARD 14)
#boost dependencies
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(BOOST_ROOT "../cpp_libs/boost_1_72_0")
#find_package(Boost)

#if(Boost_FOUND)
 #   include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

    add_executable(speller main.cpp "data structures/checker.h"
        "data structures/ChainHashTable.h" "data structures/ChainHashTable.cpp"
        "data structures/BinaryTree.h" "data structures/BinaryTree.cpp"
        "data structures/VectorFacade.cpp" "data structures/VectorFacade.h"
        "data structures/HashMapFacade.cpp" "data structures/HashMapFacade.h" Speller.cpp Speller.h Timer.cpp Timer.h)

 #   target_link_libraries(speller ${Boost_LIBRARIES})
#endif()