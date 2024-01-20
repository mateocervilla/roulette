cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(roulette)
add_executable(roulette main.cpp Roulette.cpp Player.cpp Game.cpp)
target_include_directories(roulette PUBLIC)
target_link_libraries(roulette)
