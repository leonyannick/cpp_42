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

static void	vecPrintPair(std::vector<std::pair<int, int> > &vec) {
	std::vector<std::pair<int, int> >::const_iterator it = vec.begin();
	std::vector<std::pair<int, int> >::const_iterator ite = vec.end();

	for (; it != ite; it++) {
		std::cout << "[" << it->first << ", " << it->second << "]" << " ";
	}
	std::cout << std::endl;
}

static void	vecPrint(std::vector<int> &vec) {
	std::vector<int>::const_iterator	it = vec.begin();
	std::vector<int>::const_iterator	ite = vec.end();

	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static void merge(std::vector<std::pair<int, int> > &B, int iBegin, int iMiddle,
	int iEnd, std::vector<std::pair<int, int> > &A) {
	int i = iBegin;
	int j = iMiddle;

	for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

static void splitMerge(std::vector<std::pair<int, int> > &B, int iBegin, int iEnd,
	std::vector<std::pair<int, int> > &A) {
	int iMiddle;
	
	if (iEnd - iBegin <= 1)
		return;
	
	iMiddle = (iEnd + iBegin) / 2;

	splitMerge(A, iBegin, iMiddle, B);
	splitMerge(A, iMiddle, iEnd, B);

	merge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * https://en.wikipedia.org/wiki/Binary_search_algorithm
 * @param A container of n elements
 * @param T target value
*/
static int	binarySearch(std::vector<int> A, int n, int T) {
	int L = 0;
	int R = n - 1;
	int m;

	while (L < R) {
		m = L + (R - L) / 2;
		if (A[m] < T)
			L = m + 1;
		else
			R = m;
    }

    return L;
}

static bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true;
}


/*------------------PUBLIC METHODS -----------------*/

int	PmergeMe::vecFill(int argc, char *argv[]) {
	int num;
	int i;

	for (i = 1; i < argc; i++) {
		num = convertToInt(argv[i]);
		if (num == -1)
			return (-1);
		_vector.push_back(num);
	}
	//uneven so there is a stray number
	if ((i - 1) % 2)
		_stray = num;

	std::cout << "Before:\t";
	vecPrint(_vector);
	return (0);
}

void	PmergeMe::vecPairwiseComparison() {
	_startTimeVec = clock();

	for (size_t i = 0; i < (_vector.size() - 1); i += 2) {
		if (_vector[i] < _vector[i + 1]) {
			_pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
		}
		else {
			_pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		}
    }
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "sorted pairs (within)");
	if (LOG_DEBUG)
		vecPrintPair(_pairs);
}

// void	PmergeMe::sortPairs(std::size_t itSize) {

// 	if (itSize >= _pairs.size())
// 		return;

// 	for (size_t i = 0; i < _pairs.size(); i += (2* itSize)) {
// 		std::cout << _pairs[i].first << std::endl;
// 		std::cout << _pairs[i + itSize].first << std::endl;
// 		if (_pairs[i].first > _pairs[i + itSize].first)
// 			std::swap(_vector[i], _vector[i + itSize]);
// 	}
// 	sortPairs(++itSize);
// }

/**
 * Top down merge sort:
 * https://en.wikipedia.org/wiki/Merge_sort
*/
void	PmergeMe::mergeSort() {
	std::vector<std::pair<int, int> > B(_pairs);
	splitMerge(_pairs, 0, _pairs.size(), B);
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "pairs sorted with respect to first number");
	if (LOG_DEBUG)
		vecPrintPair(_pairs);
}

void	PmergeMe::createChains() {
	std::vector<std::pair<int, int> >::const_iterator it;

	for (it = _pairs.begin(); it != _pairs.end(); it++) {
		_mainchain.push_back(it->first);
		_pend.push_back(it->second);
	}

	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "mainchain");
	if (LOG_DEBUG)
		vecPrint(_mainchain);
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "pend");
	if (LOG_DEBUG)
		vecPrint(_pend);

}


/**
 * understand insertion with jacobsthal:
 * https://stackoverflow.com/questions/27751132/how-does-merge-insertion-sort-work
*/
void	PmergeMe::insertion() {
	size_t	pos;
	size_t	batch = 0;
	int		candidate;
	int		k;

	//first element can be inserted in the mainchain without comparison
	_mainchain.insert(_mainchain.begin(), _pend[0]);

	LOG_MSG(LOG_DEBUG, BG_BOLD_YELLOW, "inserting first pend:");
	if (LOG_DEBUG)
		vecPrint(_mainchain);

	k = jacobsthalIndeces[batch];
	for (size_t nInsertions = 1; nInsertions < _pend.size();) {
		if (k == 0 || k == jacobsthalIndeces[batch - 1]) {
			batch++;
			k = jacobsthalIndeces[batch];
		}
		if (k >= static_cast<int>(_pend.size())) {
			k--;
			continue;
		}
		candidate = _pend[k];
		pos = binarySearch(_mainchain, _mainchain.size(), candidate);
		_mainchain.insert(_mainchain.begin() + pos, candidate);

		LOG_MSG(LOG_DEBUG, BG_BOLD_YELLOW, "k:" << k << " candidate: " << candidate
			<< " pos:" << pos << " sequence after insertion:");
		if (LOG_DEBUG)
			vecPrint(_mainchain);
		nInsertions++;
		k--;
	}

	//insert stray element if present
	if (_stray != -1) {
		pos = binarySearch(_mainchain, _mainchain.size(), _stray);
		_mainchain.insert(_mainchain.begin() + pos, _stray);
	}

	_endTimeVec = clock();
	
	if (LOG_DEBUG && isSorted(_mainchain)) {
		LOG_MSG(LOG_DEBUG, BG_BOLD_GREEN, "sorting successfull");
	} else {
		LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "sorting failed");
	}
	std::cout << "After:\t";
	vecPrint(_mainchain);
}

void	PmergeMe::displayRuntime() const {
	double elapsedTimeVec = static_cast<double>(_endTimeVec - _startTimeVec) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout << "Time to process a range of " << _mainchain.size()
		<< " elements with std::vector : "  << elapsedTimeVec  << " us" << std::endl;
}




/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

PmergeMe::PmergeMe(void) : _stray(-1), _itSize(1)
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

PmergeMe::~PmergeMe(void) {}

/*----------------OPERATOR OVERLOAD---------------*/

// std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
// {
// 	//o << <fill ostream with attributes>
// 	return (o);
// }