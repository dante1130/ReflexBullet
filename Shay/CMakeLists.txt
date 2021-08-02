# CMakeList.txt : CMake project for Shay, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Shay "main.cpp" "AABB.cpp" "AABBLinkedList.cpp" "AABBNode.cpp" "camera.cpp" "cameraMap.cpp" "collision.cpp" "EasySound.cpp" "PlainLinkedList.cpp" "PlainNode.cpp" "Sound.cpp" "SoundTime.cpp" "texturedPolygons.cpp")

# TODO: Add tests and install targets if needed.
