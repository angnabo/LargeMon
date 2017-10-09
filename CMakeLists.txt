cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/LargeMon.cpp src/LargeMon.h src/LargeMonGenerator.cpp src/LargeMonGenerator.h src/BattleInstance.cpp src/BattleInstance.h)
add_executable(LargeMon ${SOURCE_FILES})

