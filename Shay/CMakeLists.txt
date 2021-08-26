# CMakeList.txt : CMake project for Shay, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source files to this project
file(GLOB SOURCE_FILES *.cpp)

# Add header files to this project
file(GLOB HEADER_FILES *.h)

add_executable(Shay ${HEADER_FILES} ${SOURCE_FILES} "DisplayEXTRAShaysWorld.cpp" "DisplayEXTRAShaysWorld.h")

# TODO: Add tests and install targets if needed.
