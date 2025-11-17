########################################
# Project settings 
########################################

cmake_minimum_required(VERSION 3.15.0)

project(${{cookiecutter.project_name}} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "This variable is needed by conan.cmake." FORCE)
endif()

add_subdirectory({{cookiecutter.main_module_name}})

add_subdirectory(logging EXCLUDE_FROM_ALL)
