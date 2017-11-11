cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/cpp/main.cpp src/cpp/largeMon/LargeMon.cpp src/include/largeMonHeader/LargeMon.h
        src/cpp/LargeMonGenerator.cpp src/include/LargeMonGenerator.h src/cpp/BattleInstance.cpp
        src/include/BattleInstance.h src/cpp/DescriptGen.cpp src/include/DescriptGen.h src/cpp/Controller.cpp
        src/include/Controller.h src/cpp/largeMon/WaterLM.cpp src/include/largeMonHeader/WaterLM.h
        src/cpp/largeMon/FireLM.cpp src/include/largeMonHeader/FireLM.h src/cpp/largeMon/WoodLM.cpp
        src/include/largeMonHeader/WoodLM.h src/cpp/Observer.cpp src/include/Observer.h src/cpp/ViewObserver.cpp
        src/include/ViewObserver.h src/cpp/LargeMonMainView.cpp src/cpp/LargeMonMainView.h src/cpp/LTexture.cpp
        src/include/LTexture.h src/cpp/ButtonTexture.cpp src/include/ButtonTexture.h)
add_executable(LargeMon ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

