#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

class GlfwWrapper
{
public:
	GlfwWrapper(const std::string &title = "Glfw Wrapper", int width = 640, int height = 480);

	~GlfwWrapper();

	bool init();

	void startGameLoop();

private:
	void processInput();
	void update();
	void render();

	void destroy();

private:
	const int							m_FPS{ 60 };
	const double						m_inverseFPS{ 1.0 / (double)m_FPS };
	bool								m_bInitialized{ false };
	int									m_windowWidth{};
	int									m_windowHeight{};
	std::string							m_title{};

	std::shared_ptr<GLFWwindow>			m_pGlfwWindow;
};

static void error_callback(int error, const char* description)
{
	std::cout << "ERROR:: [" << error << "] - " << description << "\n";
}

static void key_callback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	(void)pWindow;
	std::cout << "Key [" << key << "], Scancode [" << scancode << "], " << ", Action [" << action << "], Mods [" << mods << "]\n";
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
}

static void cursor_position_callback(GLFWwindow* pWindow, double x, double y)
{
	(void)pWindow;
	std::cout << "Cursor Position: { " << x << ", " << y << " }\n";
}

static void mouse_button_callback(GLFWwindow* pWindow, int button, int action, int mods)
{
	(void)pWindow;
	std::cout << "Mouse Button [" << button << "], Action [" << action << "], Mods [" << mods << "]\n";
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right button clicked.\n";
	}
}

GlfwWrapper::~GlfwWrapper()
{
	destroy();
	std::cout << "GlfwWrapper:: Shutdown!\n";
}

GlfwWrapper::GlfwWrapper(const std::string& title, int width, int height)
	:m_title(title)
	,m_windowWidth(width)
	,m_windowHeight(height)
{
	std::cout << "GlfwWrapper:: Initializing!\n";
}

void GlfwWrapper::startGameLoop()
{
	if (!m_bInitialized)
	{
		std::cout << "ERROR:: GLFW not initialized!\n";
		return;
	}

	double lastTime = glfwGetTime();

	// Making the context as current context.
	glfwMakeContextCurrent(m_pGlfwWindow.get());

	while (!glfwWindowShouldClose(m_pGlfwWindow.get()))
	{
		while (glfwGetTime() < (lastTime + m_inverseFPS))
		{
			// wait
			;
		}
		lastTime += m_inverseFPS;

		// 1. Process Inputs
		processInput();

		// 2. Render logic
		render();
		
		// 3. Update
		update();

		
		// 2nd Last. Swap front & back buffers.
		//		GLFW windows by default use double buffering. That means that each window has two rendering buffers;
		//		a front buffer and a back buffer. The front buffer is the one being displayed and the back buffer the one you render to.
		glfwSwapBuffers(m_pGlfwWindow.get());

		// Last. Poll for & process events. There are 2 methods for processing pending events:
		//		1. Polling
		//		2. Waiting
		glfwPollEvents();
	}
}

void GlfwWrapper::processInput()
{
	double xpos{}, ypos{};
	glfwGetCursorPos(m_pGlfwWindow.get(), &xpos, &ypos);

	int state = glfwGetMouseButton(m_pGlfwWindow.get(), GLFW_MOUSE_BUTTON_LEFT);
	if (state == GLFW_PRESS)
	{
		std::cout << "Left mouse button pressed!\n";
	}
	else if (state == GLFW_RELEASE)
	{
		std::cout << "Left mouse button released!\n";
	}
}

void GlfwWrapper::update()
{
	std::cout << "Game update logic.\n";
}

void GlfwWrapper::render()
{
	std::cout << "Graphic rendering logic.\n";
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	int width{}, height{};
	glfwGetFramebufferSize(m_pGlfwWindow.get(), &width, &height);
	glViewport(0, 0, width, height);
}

bool GlfwWrapper::init()
{
	if (m_bInitialized)
	{
		std::cout << "Already initialized!\n";
		return m_bInitialized;
	}
	
	// Step 0. Setup Glfw Error callback.
	glfwSetErrorCallback(error_callback);

	// Step 1. Initialize GLFW.
	if (!glfwInit())
	{
		std::cout << "ERROR:: Initialization failed!\n";
		return false;
	}
	m_bInitialized = true;

	// Step 2.  Create Window & context.
	// OPTIONAL - By default, the OpenGL context GLFW creates may have any version.
	// You can require a minimum OpenGL version by setting the 
	// GLFW_CONTEXT_VERSION_MAJOR and GLFW_CONTEXT_VERSION_MINOR hints before creation.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);						// OPTIONAL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);						// OPTIONAL
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		// OPTIONAL
	m_pGlfwWindow = std::shared_ptr<GLFWwindow>(
		glfwCreateWindow(m_windowWidth, m_windowHeight, m_title.c_str(), nullptr, nullptr), 
		[](GLFWwindow* pWindow) 
		{
			glfwDestroyWindow(pWindow);
		});

	if (!m_pGlfwWindow)
	{
		std::cout << "ERROR:: Window or OpenGL context creation failed!\n";
		destroy();
		return m_bInitialized;
	}

	// Step 3. Setup different callbacks.
	glfwSetKeyCallback(m_pGlfwWindow.get(), key_callback);
	glfwSetCursorPosCallback(m_pGlfwWindow.get(), cursor_position_callback);
	glfwSetMouseButtonCallback(m_pGlfwWindow.get(), mouse_button_callback);


	// The swap interval indicates how many frames to wait until swapping the buffers, commonly known as vsync. 
	//		Default = 0, meaning immediately. On fast machines, on fast m/c this wastes a lot of CPU and GPU cycles.
	//					 because the buffers will be swapped in the middle of the screen update, leading to screen tearing.
	//		Vsynv = 1,
	glfwSwapInterval(1);

	return m_bInitialized;
}

void GlfwWrapper::destroy()
{
	// Terminate the GLFW. Just before the application exists.
	if (m_bInitialized)
	{
		if (m_pGlfwWindow)
		{
			// This destroys window.
			m_pGlfwWindow.reset();
		}

		// This destroys any remaining windows and releases any other resources allocated by GLFW.
		glfwTerminate();
		m_bInitialized = false;
	}
}