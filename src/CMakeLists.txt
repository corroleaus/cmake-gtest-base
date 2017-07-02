## inspired by https://rix0r.nl/blog/2015/08/13/cmake-guide/

# Require 3.2
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(PROJECT_NAME_STR cmake-base)
project(${PROJECT_NAME_STR} VERSION 0.1 LANGUAGES CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

if(MSVC)
    #vc 2012 fix for vararg templates
    set(MSVC_COMPILER_DEFS "-D_VARIADIC_MAX=10")
endif()

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

set(VENDOR_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/vendor)

# Include Boost as an imported target
# find_package(Boost REQUIRED)
# add_library(boost INTERFACE IMPORTED)
# set_property(TARGET boost PROPERTY
#     INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

# Some other library that we import that was also built using CMake
# and has an exported target.
# find_package(MyOtherLibrary REQUIRED)

# Targets 
add_subdirectory(${VENDOR_PROJECTS_DIR}/gtest)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()
add_subdirectory(my_library)
add_subdirectory(app)