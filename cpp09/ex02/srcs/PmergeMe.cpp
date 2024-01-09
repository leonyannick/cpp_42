#include "PmergeMe.hpp"

static int	convertToInt(char *arg) {
	double num;
	char *endptr;

	num = std::strtod(arg, &endptr);

	if (*endptr != '\0' || num > std::numeric_limits<int>::max() || num < 0) {
		std::cout << "Error: arguments have to be positive integers" << std::endl;
		return (-1);
	}

	return (static_cast<int>(num));
}

/*------------------PUBLIC METHODS -----------------*/

int	PmergeMe::vecFill(int argc, char *argv[]) {
	int num;

	for (int i = 1; i < argc; i++) {
		num = convertToInt(argv[i]);
		if (num == -1)
			return (-1);
		_vector.push_back(num);
	}
	return (0);
}

void	PmergeMe::vecPrint() const {
	std::vector<int>::const_iterator	it;

	for (it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vecPairwiseComparison() {
	for (size_t i = 0; i < (_vector.size() - 1); i += 2) {
		if (_vector[i] < _vector[i + 1])
			std::swap(_vector[i], _vector[i + 1]);
    }
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

PmergeMe::PmergeMe(void)
{}

// PmergeMe::PmergeMe(const PmergeMe& src)
// {
// //assign attributes
// //or use definition from copy assignment operator
// // *this = src;
// }

// PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
// {
// 	if (this != &rhs)
// 		{
// 		//copying of member attributes here
// 		}
// 	return (*this);
// }

PmergeMe::~PmergeMe(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

// std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
// {
// 	//o << <fill ostream with attributes>
// 	return (o);
// }