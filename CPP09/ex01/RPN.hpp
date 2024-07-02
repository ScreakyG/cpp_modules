#include <iostream>
#include <stack>

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
