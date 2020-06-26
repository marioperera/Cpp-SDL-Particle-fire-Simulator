cmake_minimum_required(VERSION 3.15)
project(SDL_App)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp)
add_executable(SDL_App main.cpp config/Screen.cpp config/Screen.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)