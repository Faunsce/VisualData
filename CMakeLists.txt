# CMakeList.txt : CMake project for VisualData, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("VisualData")

# Add source to this project's executable.
add_executable (VisualData "Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VisualData PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
