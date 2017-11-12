cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES src/cpp/main.cpp src/cpp/largeMon/LargeMon.cpp src/include/largeMonHeader/LargeMon.h
        src/cpp/LargeMonGenerator.cpp src/include/LargeMonGenerator.h src/cpp/BattleInstance.cpp
        src/include/BattleInstance.h src/cpp/DescriptGen.cpp src/include/DescriptGen.h src/cpp/Controller.cpp
        src/include/Controller.h src/cpp/largeMon/WaterLM.cpp src/include/largeMonHeader/WaterLM.h
        src/cpp/largeMon/FireLM.cpp src/include/largeMonHeader/FireLM.h src/cpp/largeMon/WoodLM.cpp
        src/include/largeMonHeader/WoodLM.h src/cpp/Observer.cpp src/include/Observer.h src/cpp/ViewObserver.cpp
        src/include/ViewObserver.h src/cpp/LargeMonMainView.cpp src/include/LargeMonMainView.h src/cpp/LTexture.cpp
        src/include/LTexture.h src/cpp/ButtonTexture.cpp src/include/ButtonTexture.h src/cpp/ControllerBattleInstance.cpp src/include/ControllerBattleInstance.h)
add_executable(LargeMon ${SOURCE_FILES})

target_link_libraries(LargeMon SDL2 SDL2_ttf SDL2_image)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}  ${SDL2_TTF_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}  ${SDL2_TTF_LIBRARIES})




#INCLUDE(FindPkgConfig)
#
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
#PKG_SEARCH_MODULE(SDL_ttf REQUIRED sdl_tff)
#
#
#
#
#
#include_directories(${SDL2_INCLUDE_DIR}        ${SDL2_IMAGE_INCLUDE_DIR}        ${SDL2_TTF_INCLUDE_DIR}        ${SDL2_MIXER_INCLUDE_DIR})
#target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY}        ${SDL2_IMAGE_LIBRARIES}        ${SDL2_TTF_LIBRARIES}        ${SDL2_MIXER_LIBRARIES})
