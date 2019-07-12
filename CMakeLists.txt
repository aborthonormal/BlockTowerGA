cmake_minimum_required (VERSION 3.7)
project (BlockTowerGA)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(./Box2D)

add_executable(BlockTowerGA ${SRC_DIR}/main.cpp)
target_link_libraries(BlockTowerGA ${SDL2_LIBRARIES})