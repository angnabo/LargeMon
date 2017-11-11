cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/cpp/main.cpp src/cpp/largeMon/LargeMon.cpp src/include/largeMonHeader/LargeMon.h src/cpp/LargeMonGenerator.cpp src/include/LargeMonGenerator.h src/cpp/BattleInstance.cpp src/include/BattleInstance.h src/cpp/DescriptGen.cpp src/include/DescriptGen.h src/cpp/Controller.cpp src/include/Controller.h src/cpp/largeMon/WaterLM.cpp src/include/largeMonHeader/WaterLM.h src/cpp/largeMon/FireLM.cpp src/include/largeMonHeader/FireLM.h src/cpp/largeMon/WoodLM.cpp src/include/largeMonHeader/WoodLM.h src/cpp/Observer.cpp src/include/Observer.h src/cpp/ViewObserver.cpp src/include/ViewObserver.h)
add_executable(LargeMon ${SOURCE_FILES})

