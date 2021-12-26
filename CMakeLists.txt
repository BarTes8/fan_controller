cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(FanController)

add_compile_options(-Wall -Wextra -Wpedantic -g)
include_directories(.)
add_library(SlowThermometer-lib SlowThermometer/SlowThermometer.cpp)

set(SRC_LIST
    Controller.hpp
    Controller.cpp
    Fan.hpp
    Fan.cpp
    LcdDisplay.hpp
    LcdDisplay.cpp
    IThermometer.hpp
)

add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib SlowThermometer-lib pthread)

set(TEST_SRC_LIST
    tests/FanTests.cpp
    tests/ControllerTests.cpp
)

add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib pthread)
