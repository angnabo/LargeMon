cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/LargeMon.cpp src/LargeMon.h src/LargeMonGenerator.cpp src/LargeMonGenerator.h src/BattleInstance.cpp src/BattleInstance.h src/DescriptGen.cpp src/DescriptGen.h src/View.cpp src/View.h src/Controller.cpp src/Controller.h src/WaterLM.cpp src/WaterLM.h src/FireLM.cpp src/FireLM.h src/WoodLM.cpp src/WoodLM.h)
add_executable(LargeMon ${SOURCE_FILES})

