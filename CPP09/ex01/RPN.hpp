#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		static void Calculate(char *argv);
		~RPN();
	private:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &rhs);
};
