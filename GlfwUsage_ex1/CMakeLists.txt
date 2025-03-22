cmake_minimum_required(VERSION 3.20...3.31)

SET(PROJECT "GlfwUsage_ex1")

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")

SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")

project( ${PROJECT} VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

if (MSVC)	# For Visual Studio
    # W4 = warning level 4
	# WX = Treat all warnings as errors
	# permissive- = C/C++ -> Language -> Conformance mode -> Yes (means, disable language extensions)
	#						i.e, Disable everything which is provided by visual studio as extension but is not c++ standard.
    add_compile_options(/W4 /WX /permissive-)
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

########################################################
############## GLFW Library setup - START ##############
########################################################
# GLFW download URL - https://www.glfw.org/download

# This is where I have all the libraries.
set(CommonLibs_DIR D:/GitHubRepos/_CommonLibs)
# This is where I have GLFW library. It is inside CommonLibs => CommonLibs/GLFW.
set(Glfw_DIR ${CommonLibs_DIR}/GLFW)

# REQUIRED - Compiler will include these folders while finding header files.
include_directories(${Glfw_DIR}/include)

# REQUIRED - Append & Set the PATH of different libraries used to the PATH variable. lib-vc2022 is for Visual Studio 2022 version.
list(APPEND Glfw_LIB "${Glfw_DIR}/lib-vc2022/glfw3.lib")
set(MY_PATH "PATH=%PATH%" "${Glfw_DIR}/lib-vc2022")

# REQUIRED - Link the libraries with executable.
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT} OpenGL::GL ${Glfw_LIB})

########################################################
############## GLFW Library setup - END ################
########################################################

# REQUIRED - Visual Studio specific
#set_target_properties(${PROJECT} PROPERTIES LINK_FLAGS "/NODEFAULTLIB:MSVCRT")
#set_target_properties(${PROJECT} PROPERTIES VS_DEBUGGER_ENVIRONMENT "${MY_PATH}")

# REQUIRED - Visual Studio specific. Setting this project as "statup project".
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT})