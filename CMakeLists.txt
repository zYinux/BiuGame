cmake_minimum_required(VERSION 3.16)
project(BiuBiuBiu)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})

add_executable(BiuBiuBiu main.cpp src/includes/Logger.h src/includes/sdl_utils.h src/core/Game.cpp src/core/Game.h src/core/Window.cpp src/core/Window.h src/core/Scenes.cpp src/core/Scenes.h src/core/Resources.cpp src/core/Resources.h src/core/ResourcesMaganger.cpp src/core/ResourcesMaganger.h src/core/GameException.h src/core/GameWindow.cpp src/core/GameWindow.h)

target_link_libraries(BiuBiuBiu
        ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_MIXER_LIBRARIES}
        )