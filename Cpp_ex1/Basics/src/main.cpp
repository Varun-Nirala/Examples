#include <iostream>
#include "include/print_cpp_compiler_standard.h"
#include "include/temp.h"

void cin_clear()
{
	// reset any previous clear flags
	std::cin.clear();

	// ignore any characters in the input buffer until we find a newline
	// for std::numeric_limits<> we need to include <limits>
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// get one more char from the user (waits for the user to press any key)
	std::cin.get();
}

int main()
{
	std::cout << "Hello, World!\n";

	print_cpp_compiler_standard();
	create_aggregate_struct_instance();

	return 0;
}