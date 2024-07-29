cmake_minimum_required(VERSION 3.13.4)

project(Chess)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(external/SFML/include)

target_link_directories(${PROJECT_NAME})