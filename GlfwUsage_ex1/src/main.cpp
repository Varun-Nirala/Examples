#include <iostream>

#include "GlfwWrapper.h"

// https://www.glfw.org/docs/latest/intro_guide.html
// GLFW is a free, Open Source, multi-platform lib for OpenGL, OpenGLES & Vulkan app dev.
// It provides:
//		simple platform indepent API for
//			* creating windows
//			* context & surfaces
//			* reading i/p
//			* handling events
// etc.

int main()
{
	GlfwWrapper glfwWrapper;
	glfwWrapper.init();
	glfwWrapper.startGameLoop();
	return 0;
}

// Coordinate system
//  -------
// | (0, 0)	x ---->
// | y
// | |
// | |