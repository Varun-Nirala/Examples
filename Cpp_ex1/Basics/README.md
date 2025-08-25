# Cpp basic concepts and examples.

## Program
Collection of instructions that manipulate data to accompalish some task and produce result.

## Statements
Statement are the smallest independent unit of computation in the `C++` language.
Most of them end with semicolon `;`. Different kinds are:
1. Declaration
2. Jump
3. Expression
4. Compound
5. Selection aka conditionals
6. Iteration aka loops
7. Try-catch

## Variable and Object
In `C++` we access memory indirectly through an object. An `object` represent a storage region typically in RAM or CPU register.
`Variable` is an `object` with a name(identifier). `Object` in `C++` can be anonymous(unnamed).

Variable declaration example:
```
int a;			// correct
double b;		// correct

int a, char c;	// wrong (compile error). Notice comma ','

```

## Variable **initialization**
1. *Default-initialization*: No initialization is performed and variable will contain `garbage value`.
	`int a;`

2. *Copy-initialization*: Value is provided after an `=` sign. Inherited from `C`.
	Used at the time of implicit copy. For argument at time of function call.
	`int b = 5;`

3. *Direct-initialization*: Value is provided inside paranthesis.
	Used at time of casting.
	`int c (5);`

4. *List-initialization*: Modern `C++` way. Uses curly braces `{}`. Also, called `uniform` or `brace` initialization.
	`int d {5};`	// direct list
	`int e = {5};`	// copy list
	`int f{};`		// value-initialization, will implicitly initialize to zero. aka zero-initialization

	It disallows narrowing conversions. Example:
	`int pi { 3.14 };`	// compile error

	[!NOTE]
	> List-initialization is preferred way.

5. Aggregate initialization
2. Copy-list initialization
3. Reference initialization
4. Static-initialization, constant-initialization, and dynamic-initialization
5. zero-initialization

**As of C++17: copy-initialization, direct-initialization and list-initialization behave identical.**


## C++17 Attribute
1. [[maybe_unused]] : To get rid of compiler complaining about variable not getting used.
```
	[[maybe_unused]] int maxVal = 20;
```

##


[!NOTE]
> Every `C++` program must have a `main` function.
> `C++` is case-sensitive.
> The `C++` I/O lib does not provide a way to accept keyboard input without the user having to press enter.
	For that use 3rd party like `pdcurses`, `FXTUI`, `cpp-terminal` or notcurses`.
> std::cin is buffered. The data from output operation is added to the end of an output buffer.
	Later, that buffer is flsuhed to output device.
