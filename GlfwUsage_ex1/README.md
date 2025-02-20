# GlfwUsage_ex1
To show how to use GLFW library in C/C++.
CMakeList file on how to create a simple project with all linking.

// Guide - https://www.glfw.org/docs/latest/intro_guide.html
// Download - https://www.glfw.org/download

# Downloaded zip will extract to something like below:
	- docs/
	- include/GLFW/
		/glfw3.h
		/glfw3nativ.h
	- lib-mingw-x64/
	- lib-static-ucrt/
	- lib-vc2022/
		/glfw3.dll
		/glfw3.lib
		/glfw3_mt.lib
		/glfw3dll.lib
	
For Visual Studio 2022, we use lib-vc2022/.

# Description
GLFW is a free, Open Source, multi-platform lib for OpenGL, OpenGLES & Vulkan app dev.
It provides:
	simple platform indepent API for
		* creating windows
		* context & surfaces
		* reading i/p
		* handling events
etc.

# Coordinate system

Top left is (0, 0).
X increase in left.
Y increase in down.