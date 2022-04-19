cmake_minimum_required(VERSION 3.0.0)
project(NeveshtAfzaar VERSION 0.1.0)

include(CTest)
enable_testing()

set(SDL2_DIR "C:\\libs\\SDL2")
set(SDL2_ttf_DIR "C:\\libs\\SDL2_ttf")
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_ttf_INCLUDE_DIRS})

add_executable(vima main.c)
target_link_libraries(vima ${SDL2_LIBRARIES})
target_link_libraries(vima ${SDL2_ttf_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
