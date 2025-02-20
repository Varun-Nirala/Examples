cmake_minimum_required(VERSION 3.31)

SET(PROJECT "OpenGlLoadingLibraries_ex1")

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
#message(STATUS "Src_DIR : ${Src_DIR}")

# REQUIRED - Compiler will include these folders while finding header files.
include_directories(${Src_DIR})

# REQUIRED - Collect all the files which should be included while creating executable.
# NOTE - Headers are not required, but good if included helps in intellisense & other similar setup.
file(GLOB Src "${Src_DIR}/*.h" "${Src_DIR}/*.hpp" "${Src_DIR}/*.cpp")
file(GLOB Model "${Model_DIR}/*.h" "${Model_DIR}/*.hpp" "${Model_DIR}/*.cpp")

# OPTIONAL - Create group of the files collected. These we be displayed as group/folder in IDE like Visual studio.
source_group("" FILES ${Src})
source_group("Model" FILES ${Model})

# REQUIRED - This is the step where executable is get created. So here we are mentioning all collected files.
add_executable(${PROJECT} ${Src} ${Model})

############################################################
############## freeglut Library setup - START ##############
############################################################

# freeglut download URL - https://github.com/freeglut/freeglut/releases

# This is where I have all the libraries.
set(CommonLibs_DIR D:/GitHubRepos/CommonLibs)
# This is where I have GLFW library. It is inside CommonLibs => CommonLibs/GLFW.
set(Freeglut_DIR ${CommonLibs_DIR}/FREEGLUT)

# REQUIRED - Compiler will include these folders while finding header files.
include_directories(${Freeglut_DIR}/include)

# REQUIRED - Add the required libraries.

find_library(Freeglut_LIB
    NAMES freeglut
    PATHS ${Freeglut_DIR}/lib ${Freeglut_DIR}/bin
)

find_library(FreeglutDebug_LIB
    NAMES freeglutd
    PATHS ${Freeglut_DIR}/lib ${Freeglut_DIR}/bin
)

#message(STATUS "Freeglut_LIB : ${Freeglut_LIB}")

# REQUIRED - Link the libraries with executable.
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT} OpenGL::GL ${Freeglut_LIB} ${FreeglutDebug_LIB})

# Remove static lib linking, "freeglut_static.lib"
add_compile_definitions(-FREEGLUT_STATIC)
add_compile_definitions(FREEGLUT_LIB_PRAGMAS=1)

# REQUIRED - Copy the dll files as they are required by GLUT.
add_custom_command(TARGET ${PROJECT} 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${Freeglut_DIR}/bin
    "$(ProjectDir)\\$(Configuration)"
)

############################################################
############## freeglut Library setup - END ################
############################################################

set_target_properties(${PROJECT} PROPERTIES LINK_FLAGS "/NODEFAULTLIB:MSVCRT")
set_target_properties(${PROJECT} PROPERTIES VS_DEBUGGER_ENVIRONMENT "${MY_PATH}")


# REQUIRED - Visual Studio specific. Setting this project as "statup project".
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT})