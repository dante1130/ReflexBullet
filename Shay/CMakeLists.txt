# CMakeList.txt : CMake project for Shay, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source files to this project
file(GLOB SOURCE_FILES *.cpp)

# Add header files to this project
file(GLOB HEADER_FILES *.h)

add_executable(Shay ${HEADER_FILES} ${SOURCE_FILES} "LoadTexturesGameWorld.h" "LoadTexturesGameWorld.cpp" "definesGW.h" "Leaderboards.h" "Leaderboards.cpp" "UI.h" "UI.cpp" "Boss.h" "Boss.cpp" "BossArea.h" "BossArea.cpp" "AStar.cpp" "AStart.h" "AStartInterface.cpp" "AStartInterface.h")

add_custom_command(TARGET Shay PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/dlls 
                    ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET Shay PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/Shay/data 
                    ${CMAKE_CURRENT_BINARY_DIR}/data)

add_custom_command(TARGET Shay PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/Shay/sounds 
                    ${CMAKE_CURRENT_BINARY_DIR}/sounds)

                    
add_custom_command(TARGET Shay PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/Shay/music 
                    ${CMAKE_CURRENT_BINARY_DIR}/music)

# MSVC compiler flags
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/W4>)

target_link_libraries(Shay ${PROJECT_SOURCE_DIR}/lib/x86/SDL2.lib)
target_link_libraries(Shay ${PROJECT_SOURCE_DIR}/lib/x86/SDL2main.lib)
target_link_libraries(Shay ${PROJECT_SOURCE_DIR}/lib/x86/SDL2_mixer.lib)
target_link_libraries(Shay ${PROJECT_SOURCE_DIR}/lib/x86/glut32.lib)