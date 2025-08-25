# pragma once

// This program prints the C++ language standard your compiler is currently using
// Freely redistributable, courtesy of learncpp.com (https://www.learncpp.com/cpp-tutorial/what-language-standard-is-my-compiler-using/)

#include <iostream>

constexpr int numStandards = 7;

// The C++26 stdCode is a placeholder since the exact code won't be determined until the standard is finalized
constexpr long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L };
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

namespace {
	long getCppCompilerStandard()
	{
		// Visual Sutdio is non-conforming in support for _cplusplus (unless you set a specific compiler flag,
		// which you probably haven't).
		// In Visual Sutdio 2015 or newer we can use _MSVC_LANG instead
		// See https://devblogs.microsoft.com/cppblog/msv-now-correctly-reports-__cplusplus/
#if defined (_MSVC_LANG)
		return _MSVC_LANG;
#elif defined (_MSV_VER)
	// If we're using an older version of Visual Studio, bail out
		return -1;
#else
	// __cplusplus is the intended way to query the language standard code (as defined by the language standards)
		return __cplusplus;
#endif
	}

	void print(const char* name, long code, bool isPreview)
	{
		std::cout << "Your compiler is using " << (isPreview ? "a preview/pre-release of " : "") << ":: \"" << name
			<< "\" (language standard code :: " << code << "L)\n";
	}
}

void print_cpp_compiler_standard()
{
	long standard = getCppCompilerStandard();

	if (standard == -1)
	{
		std::cout << "Error: Unable to determine your language standard. Sorry.\n";
	}

	for (int i = 0; i < numStandards; ++i)
	{
		// If the reported version is one of the finalized standard codes then we know what version the compiler is running
		if (standard == stdCode[i])
		{
			print(stdName[i], standard, false);
			break;
		}

		// If the reported version is between two finalized standard codes, this must be a preview/experimental support for the
		// next upcoming version
		if (standard < stdCode[i])
		{
			print(stdName[i], standard, true);
			break;
		}
	}
}