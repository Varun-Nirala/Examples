#pragma once

#include <iostream>

// struct without ctor are aggregates.
// That is we can directly use list initialization.
// We can create instance of be low struct as below:
// Aggregrate s { 'a', 12, 3.14 };
struct Aggregrate
{
	char char_val{};
	int int_val{};
	double double_val{};
};

struct Aggregrate_Not
{
	char char_val{};
	int int_val{};
	double double_val{};

	Aggregrate_Not() = default;
};

void create_aggregate_struct_instance()
{
	Aggregrate sA(
		'a',
		12,
		3.14
	);

	Aggregrate_Not sNA(
		'a',
		12,
		3.14
	);
}