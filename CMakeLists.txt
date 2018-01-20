cmake_minimum_required(VERSION 3.8)
project(LargeMon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES src/model/largemon/LargeMon.cpp src/model/largemon/LargeMon.h
        src/main.cpp src/main.h
        src/model/LargeMonGenerator.cpp src/model/LargeMonGenerator.h
        src/utility/DescriptGen.cpp src/utility/DescriptGen.h src/controller/Controller.cpp
        src/controller/Controller.h src/model/largemon/WaterLM.cpp src/model/largemon/WaterLM.h
        src/model/largemon/FireLM.cpp src/model/largemon/FireLM.h src/model/largemon/WoodLM.cpp
        src/model/largemon/WoodLM.h src/utility/Observer.cpp src/utility/Observer.h src/utility/HealthObserver.cpp
        src/utility/HealthObserver.h src/utility/HealthBarObserver.h src/utility/HealthBarObserver.cpp
        src/utility/ContrObserver.h src/utility/ContrObserver.cpp test/Test.cpp test/Test.h
        src/utility/FileWriter.h src/utility/FileWriter.cpp src/view/LargeMonMainView.cpp src/view/LargeMonMainView.h src/graphics/GTexture.cpp
        src/graphics/GTexture.h src/graphics/GButtonTexture.cpp src/graphics/GButtonTexture.h src/model/BattleInstance.cpp src/model/BattleInstance.h src/graphics/GProgressBar.cpp src/graphics/GProgressBar.h)
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
