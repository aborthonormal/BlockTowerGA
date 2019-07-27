cmake_minimum_required (VERSION 3.7)
project (BlockTowerGA)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_CXX_STANDARD 11)

set(BOX2D_INCLUDES "${PROJECT_SOURCE_DIR}/../Box2D")
include_directories(${BOX2D_INCLUDES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(GLEW 2.0 REQUIRED)

add_subdirectory(googletest)
add_subdirectory(test)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARIES ${SDL2_LIBRARIES} 
        ${CMAKE_CURRENT_SOURCE_DIR}/../Box2D/build/bin/x86_64/Debug/libBox2D.a 
        ${OPENGL_LIBRARY}
        GLEW::GLEW)

add_executable(BlockTowerGA ${SRC_DIR}/main.cpp)
target_link_libraries(BlockTowerGA ${LIBRARIES})