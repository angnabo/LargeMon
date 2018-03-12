cmake_minimum_required(VERSION 3.8)
project(Largemon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/model/largemon/Largemon.cpp src/model/largemon/Largemon.h
        src/main.cpp src/main.h
        src/model/LargemonGenerator.cpp src/model/LargemonGenerator.h
        src/model/utility/DescriptGen.cpp src/model/utility/DescriptGen.h src/controller/Controller.cpp
        src/controller/Controller.h src/model/largemon/WaterLM.cpp src/model/largemon/WaterLM.h
        src/model/largemon/FireLM.cpp src/model/largemon/FireLM.h src/model/largemon/WoodLM.cpp
        src/model/largemon/WoodLM.h src/model/utility/Observer.cpp src/model/utility/Observer.h
        src/model/utility/HealthBarObserver.cpp src/model/utility/HealthBarObserver.h
        src/model/utility/ContrObserver.h src/model/utility/ContrObserver.cpp test/Test.cpp test/Test.h
        src/model/utility/RandomNumber.h src/model/utility/RandomNumber.cpp
        src/model/largemon/Type.h src/model/largemon/Type.cpp
        src/model/utility/FileWriter.h src/model/utility/FileWriter.cpp
        src/view/LargemonMainView.cpp src/view/LargemonMainView.h src/view/graphics/GTexture.cpp
        src/view/graphics/GTexture.h src/view/graphics/GButtonTexture.cpp src/view/graphics/GButtonTexture.h
        src/model/BattleInstance.cpp src/model/BattleInstance.h src/view/graphics/GProgressBar.cpp src/view/graphics/GProgressBar.h)
add_executable(Largemon ${SOURCE_FILES})

target_link_libraries(Largemon SDL2 SDL2_ttf SDL2_image)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}  ${SDL2_TTF_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}  ${SDL2_TTF_LIBRARIES})