# CMakeList.txt : CMake project for Shay, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
file(GLOB SRC_FILES *.cpp)
add_executable (Shay ${SRC_FILES}  "DisplayShaysWorld.h" "DisplayShaysWorld.cpp" "defines.h" "LoadTexturesShaysWorld.h" "LoadTexturesShaysWorld.cpp")

# TODO: Add tests and install targets if needed.
