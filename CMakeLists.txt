cmake_minimum_required(VERSION 3.16)
project(Koffieboon)

# Set the C++ standard if needed
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for each project
add_subdirectory(Engine)
add_subdirectory(Playground)
