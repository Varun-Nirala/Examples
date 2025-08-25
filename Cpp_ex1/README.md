# Cpp basic concepts and examples.



## Resources<br/>
- [GitHub Readme format Synatx](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- [learncpp](https://www.learncpp.com/)



## C and C++

### C language

1. The `C` language was developed in `1972` by `Dennis Ritchie` at `Bell Telephone laboratories`, as a `systems programming language`.<br/>
	With primary goal as:
		1. a minimalistic language easy to compile,
		2. allowed efficient access to memory,
		3. produced efficient code, and
		4. was self-contained (not dependent on other programs).


2. For a high-level language, 'C' was designed to give the prgrammer a lot of control, while allowing dev to write platform agnostic code.
3. It ended up being so efficient and flexible that in 1973, `Ritchie` & `Ken Thompson` re-wrote most of the `Unix` OS using `C`. Many previous
	OS had been written in assembly.
4. In `1978`, `Brian Kernighan and Dennis Ritchie` published book called `The C Programming Language`, which became de-facto standard.
5. In `1983`, American National Standards Institute (`ANSI`) formed a standard committee for `C`, versions:
	- `C89` aka `ANSI C`
	- `C90` aka `ANSI C/C90`   (in `1990` International Organization for Standardization [`ISO`] adopted `ANSI C`)


### C++ language

Standard website: https://isocpp.org/std/the-standard
Standard drafts: https://www.open-std.org/jtc1/sc22/wg21/docs/standards

cppreference: https://en.cppreference.com/w/

Compiler supports: https://en.cppreference.com/w/cpp/compiler_support/23

1. The `C++` (pronounced "c plus plus") language was developed starting in `1979` by `Bjarne Stroustrup` at `Bell Labs`, as an extension to `C`.<br/>
	`C++` is a superset of `C`, though this not strictly true (`C99` as there few features in `C99` which are not in `C++`). Most notable feature of `C++`
	is support of `object oriented programming`. `C++` was standardized in `1998` by `ISO` committee. Versions:
		- `C++03` in `2003`,
		- `C++11` in `2011`,
		- `C++14` in `2014`,
		- `C++17` in `2017`,
	Basically, every 3 years.


## IDE, Compiler and useful info

As of Mar-2025
1. Min. absolute compiler versions with `C++17` support:
	- GCC/G++7
	- Clang++8
	- Visual Studio 2017 15.7

2. IDE setup examples [From learncpp](https://www.learncpp.com/cpp-tutorial/installing-an-integrated-development-environment-ide/)
	- Visual Studio (Windows)
	- Code::Blocks (Linux or Windows)
	- Visual Studio Codde (Linux, macOS, or Windows)

3. Online web-based compiler:
	- TutorialsPoint
	- Wandbox (can choose different versions of GCC or Clang)
	- Godbolt (can see assembly)


## g++ command line compile command
```
g++ -std=c++11 -o <executable_out_file_name> main.cpp
./<executable_out_file_name>
```
In above example default out file will be `main`.
To use some other than `C++11`, use `-std=c++14` or `-std=c++17` or try `-std=c++2c` for latest.

For `gcc` and `Clang`:
	1. Add `-ggdb` to the command line for debug builds and `-O2 -DNDEBUG` (it is "letter then digit in 02") for release builds.
	2. The `-O#` option is used to control optimization settings. Few are:
		- `O0` default for debug and it disables optimization. Recommended debug setting.
		- `O2` default for release and it beneficial optimization for all type of programs. Recommended release setting.
		- `O3` may or may not perform better than `O2` depending on specific program.
	For more in optimization options check: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html


## Visual Studio Settings
1. Disable compiler extensions to remain complaint with `C++` standards.
	- via IDE (per project):
		`Project`-> Right Click -> `Properties`
			Select `All Configurations` for `Configuration:`
		 Then, Go to => `C/C++` -> `Language` -> `Conformance mode`
			Set it to `Yes (/permissive-)`
	
	- via `CMakeLists.txt`:
		use `add_compile_options(/permissive-)` like below:
```
if (MSVC)
    # W4 = warning level 4
	# WX = Treat all warnings as errors
	# permissive- = C/C++ -> Language -> Conformance mode -> Yes (means, disable language extensions)
	#						i.e, Disable everything which is provided by visual studio as extension but is not c++ standard.
    add_compile_options(/W4 /WX /permissive-)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
```


## Formal language name, configuring compiler: Choosing language<br/>

| **Year**  | **Formal Name**     | **Conventional Name** | **Dev Name** |
|-----------|---------------------|-----------------------|--------------|
| 2011      | ISO/IEC 14882:2011  | C++11                 | C++0x        |
| 2014      | ISO/IEC 14882:2014  | C++14                 | C++1y        |
| 2017      | ISO/IEC 14882:2017  | C++17                 | C++1z        |
| 2020      | ISO/IEC 14882:2020  | C++20                 | C++2a        |
| 2024      | ISO/IEC 14882:2024  | C++24                 | C++2b        |


