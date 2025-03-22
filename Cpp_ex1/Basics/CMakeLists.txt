cmake_minimum_required(VERSION 3.31)

SET(PROJECT "Basic")

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")

SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")

project( ${PROJECT} VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

if (MSVC)	# For Visual Studio
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# OPTIONAL - Define different variable for different folder, easier for management.
set(Src_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(Include_DIR ${Src_DIR}/include)

message(STATUS "Src_DIR : ${Src_DIR}")
message(STATUS "Include_DIR : ${Include_DIR}")

# REQUIRED - Compiler will include these folders while finding header files.
include_directories(${Src_DIR})

# REQUIRED - Collect all the files which should be included while creating executable.
# NOTE - Headers are not required, but good if included helps in intellisense & other similar setup.
file(GLOB Src "${Src_DIR}/*.h" "${Src_DIR}/*.hpp" "${Src_DIR}/*.cpp")
file(GLOB Include "${Include_DIR}/*.h" "${Include_DIR}/*.hpp" "${Include_DIR}/*.cpp")

# OPTIONAL - Create group of the files collected. These we be displayed as group/folder in IDE like Visual studio.
source_group("" FILES ${Src})
source_group("include" FILES ${Include})

# REQUIRED - This is the step where executable is get created. So here we are mentioning all collected files.
add_executable(${PROJECT} ${Src} ${Include})

# REQUIRED - Visual Studio specific. Setting this project as "statup project".
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT})