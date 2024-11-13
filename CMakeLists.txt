cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(EXTRA_COMPONENT_DIRS core application)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(PMS)