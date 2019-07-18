cmake_minimum_required (VERSION 3.7)
project (BlockTowerGA)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_CXX_STANDARD 11)

set(BOX2D_INCLUDES "${PROJECT_SOURCE_DIR}/../Box2D")
include_directories(${BOX2D_INCLUDES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(BlockTowerGA ${SRC_DIR}/main.cpp)
target_link_libraries(BlockTowerGA ${SDL2_LIBRARIES})
target_link_libraries(BlockTowerGA ${CMAKE_CURRENT_SOURCE_DIR}/../Box2D/build/bin/x86_64/Debug/libBox2D.a)

#target_link_libraries(BlockTowerGA ${BOX2D_LIB})