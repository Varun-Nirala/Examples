#pragma once

#include <iostream>

class Data
{
public:
	Data()
	{
		m_id++;
	}

	void print()
	{
		std::cout << "Data class with ID: " << m_id << "\n";
	}

private:
	static int		m_id;
};

int Data::m_id = 0;