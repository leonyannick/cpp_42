#include "MutantStack.hpp"
#include <stack>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "s top: " << s.top() << std::endl;
	s.pop();
	std::cout << "s top: " << s.top() << std::endl;
	std::cout << "mstack top: " << mstack.top() << std::endl;


	MutantStack<int> copy;

	copy = mstack;

	std::cout << "copy top: " << copy.top() << std::endl;

	return 0;
}

