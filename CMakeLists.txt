# add_compile_options(-std=c++17)
cmake_minimum_required(VERSION 3.13.4)

# Set the C++ standard specifically
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project(Chess)

set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON) # Graphics depends on Window
set(SFML_BUILD_SYSTEM ON) # Graphics and Window depend on System
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(external/SFML)

target_include_directories(${PROJECT_NAME} PRIVATE external/SFML/include)

target_link_directories(${PROJECT_NAME} PRIVATE external/SFML/src/SFML/Graphics)
