########################
## Lineage CMakeLists ##
########################

################################
## Lineage Project CMakeLists ##
## Author: Jeremy Mallette    ##
## Version: 0.1				  ##
## Date: 31/03/2019			  ##
################################

cmake_minimum_required(VERSION 3.0)
project(lineage)

# BUILD FLAGS
set(CMAKE_BUILD_TYPE Debug)
set(SMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -std=c++17)

# SET OUTPUT DIRECTORY
set(CMAKE_BINARY_DIR /home/jeremy/projects/lineage/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# SET INCLUDE DIRECTORY
include_directories(include/lineage)

# ADD PROJECT LIBRARIES
add_library(
	linrandom
	src/lineage/linrandom.cpp
	)

add_library(
	trait
	src/lineage/trait.cpp
	)

add_library(
	character
	src/lineage/character.cpp
	)

add_library(
	cli
	src/lineage/cli.cpp
	)

# ADD EXECUTABLES
add_executable(
	main
	src/lineage/main.cpp
	)

# LINK LIBRARIES
target_link_libraries(main cli character trait linrandom)