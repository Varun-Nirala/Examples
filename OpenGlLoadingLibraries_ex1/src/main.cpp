#include <iostream>
#pragma warning(disable:4505)
#include "freeglut_1.h"
#pragma warning(default:4505)

int main(int argc, char *argv[])
{
	std::cout << "Hello, World!\n";
	Freeglut_1 f(argc, argv);

	f.init();

	f.startGameLoop();

	return 0;
}