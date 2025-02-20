#pragma once

#include <GL/freeglut.h>	// Should be 1st to be included
#include <GL/GL.h>
#include <iostream>
#include <functional>

// Linker Issue: https://stackoverflow.com/questions/29110985/why-is-visual-studio-trying-to-link-freeglutd-lib

typedef void (*DisplayFuncPtr)();
typedef void (*ReshapeFuncPtr)(GLsizei, GLsizei);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//
	// Insert user display code
	//

	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
	{
		height = 1; // to avoid divide by 0 error
	}

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

class Freeglut_1
{
public:
	~Freeglut_1();

	Freeglut_1(int argc, char* argv[]);

	void init(
		const std::string &title = "Freeglut demo",
		int width = 640, int height = 480,
		int posX = 0, int posY = 0);

	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	
	void registerDisplayFunc(DisplayFuncPtr funcptr);
	void registerReshapeFunc(ReshapeFuncPtr funcptr);

	void startGameLoop();

private:
	void initOpenGL();

private:
	std::string						m_title;
	int								m_windowWidth{};
	int								m_windowHeight{};
	int								m_windowPosX{};
	int								m_windowPosY{};

	std::vector<GLfloat>			m_clearColor{ 0.93f, 0.0f, 0.0f, 1.0f };

	DisplayFuncPtr					m_displayFuncPtr{};
	ReshapeFuncPtr					m_reshapeFuncPtr{};
};

Freeglut_1::~Freeglut_1()
{
}

Freeglut_1::Freeglut_1(int argc, char* argv[])
{
	glutInit(&argc, argv);
	m_displayFuncPtr = &display;
	m_reshapeFuncPtr = &reshape;
}

void Freeglut_1::startGameLoop()
{
	glutMainLoop();
}

void Freeglut_1::init(
	const std::string& title,
	int width, int height,
	int posX, int posY)
{
	m_title = title;
	m_windowWidth = width;
	m_windowHeight = height;
	m_windowPosX = posX;
	m_windowPosY = posY;

	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(m_windowWidth, m_windowHeight);
	glutInitWindowPosition(m_windowPosX, m_windowPosY);

	glutCreateWindow(m_title.c_str());

	glutDisplayFunc(m_displayFuncPtr);

	glutReshapeFunc(m_reshapeFuncPtr);

	initOpenGL();
}

void Freeglut_1::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	m_clearColor[0] = r;
	m_clearColor[1] = g;
	m_clearColor[2] = b;
	m_clearColor[3] = a;
}

void Freeglut_1::initOpenGL()
{
	glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]);
	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);	// Enable for z-culling

	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Freeglut_1::registerDisplayFunc(DisplayFuncPtr funcptr)
{
	if (funcptr == nullptr)
	{
		std::cout << "ERROR: Nullptr passed as `display` function pointer!\n";
		return;
	}
	m_displayFuncPtr = funcptr;
}

void Freeglut_1::registerReshapeFunc(ReshapeFuncPtr funcptr)
{
	if (funcptr == nullptr)
	{
		std::cout << "ERROR: Nullptr passed as `reshape` function pointer!\n";
		return;
	}
	m_reshapeFuncPtr = funcptr;
}