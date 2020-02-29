cmake_minimum_required(VERSION 3.13)
project(speller)

set(CMAKE_CXX_STANDARD 14)
#boost dependencies
set(Boost_USE_MULTITHREADED ON)
set(BOOST_ROOT "/home/stas/stas/cpp_libs/boost_1_72_0/bin")
find_package(Boost COMPONENTS filesystem REQUIRED)

if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

    add_executable(speller main.cpp
            "data structures/ChainHashTable.cpp"
            "data structures/BinaryTree.cpp"
            "data structures/VectorFacade.cpp"
            "data structures/HashMapFacade.cpp"
            "data structures/checker.cpp"
            Speller.cpp
            Timer.cpp
            )

    target_link_libraries(speller PRIVATE Boost::filesystem)
endif()