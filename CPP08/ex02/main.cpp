#include "MutantStack.hpp"
#include <list>

# define RESET	"\e[0m"
# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

static int subjectTests(void)
{
    std::cout << GREEN "##### SUBJECT TEST #####\n" RESET;

    MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

    std::cout << std::endl;
    return 0;
}

static int listCompare(void)
{
    std::cout << GREEN "##### COMPARE LIST #####\n" RESET;

    std::list<int> list;
	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
//[...]
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

    std::cout << std::endl;
    return 0;
}

static void assignementTests()
{
    std::cout << GREEN "##### ASSIGNEMENT #####\n" RESET;

    MutantStack<std::string> mstack;

    mstack.push("Hello");
    mstack.push("im");
    mstack.push("OG");

    MutantStack<std::string> mstackCopy(mstack);

    std::cout << YELLOW "After modifying copy : \n" RESET;
    mstackCopy.pop();
    mstackCopy.push("the Copy");

    for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;

    for (MutantStack<std::string>::iterator it = mstackCopy.begin(); it != mstackCopy.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
}

int main()
{
    subjectTests();
    listCompare();
    assignementTests();
}
