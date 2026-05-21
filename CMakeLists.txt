cmake_minimum_required(VERSION 3.14)

project(ball-physics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} src/main.cpp src/ball.cpp src/utils.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE src)