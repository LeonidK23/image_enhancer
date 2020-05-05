cmake_minimum_required(VERSION 3.16)

project(image_enhancer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/catch")

add_library(image_handlers src/Image.cpp src/ImageReader.cpp)
target_include_directories(image_handlers PUBLIC "include/")

enable_testing()
add_subdirectory(tests)
