cmake_minimum_required(VERSION 3.31.0)
project(Snake VERSION 0.0.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD_REQUIRED 23)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

set(raylibVersion 5.5)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${raylibVersion}.tar.gz
  FIND_PACKAGE_ARGS ${raylibVersion}
)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE sourceSet CONFIGURE_DEPENDS ./src/*.cpp ./src/*.h)

add_executable(${PROJECT_NAME} ${sourceSet})

target_include_directories(${PROJECT_NAME} PUBLIC ./src)
target_link_libraries(${PROJECT_NAME} raylib)
