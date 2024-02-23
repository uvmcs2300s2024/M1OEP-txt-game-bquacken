cmake_minimum_required(VERSION 3.8)
project(TXT-GAME-BQUACKEN)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp SubArea.cpp player.cpp input.cpp LevelFromFile.cpp inventory.cpp
        input.cpp
        Area.cpp
        item.cpp)

add_executable(Test Test.cpp SubArea.cpp player.cpp input.cpp LevelFromFile.cpp inventory.cpp
        input.cpp
        Area.cpp
        item.cpp)