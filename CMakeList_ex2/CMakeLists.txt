cmake_minimum_required(VERSION 3.31)

# Solution name
project(CMakeList_ex2)

# Add all sub directories where we have CMakeLists.txt files.
# These all will be separate self contained projects.
add_subdirectory(Project_1)
add_subdirectory(Project_2)