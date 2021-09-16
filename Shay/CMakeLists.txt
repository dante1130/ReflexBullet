# CMakeList.txt : CMake project for Shay, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source files to this project
file(GLOB SOURCE_FILES *.cpp)

# Add header files to this project
file(GLOB HEADER_FILES *.h)

add_executable(Shay ${HEADER_FILES} ${SOURCE_FILES} "GameManager.h" "GameManager.cpp" "DisplayGameWorld.h" "DisplayGameWorld.cpp" "Lighting.h" "Lighting.cpp" "ProcessShaysWorld.h" "ProcessShaysWorld.cpp")

target_link_libraries(Shay ${CMAKE_CURRENT_SOURCE_DIR}/../lib/x86/SDL2.lib)
target_link_libraries(Shay ${CMAKE_CURRENT_SOURCE_DIR}/../lib/x86/SDL2main.lib)
target_link_libraries(Shay ${CMAKE_CURRENT_SOURCE_DIR}/../lib/x86/SDL2_mixer.lib)
target_link_libraries(Shay ${CMAKE_CURRENT_SOURCE_DIR}/../lib/x86/glut32.lib)

# TODO: Add tests and install targets if needed.
