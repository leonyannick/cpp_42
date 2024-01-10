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

template <typename C>
static void	printPairContainer(C& arr_pair) {
	typename C::const_iterator it = arr_pair.begin();
	typename C::const_iterator ite = arr_pair.end();

	for (; it != ite; it++) {
		std::cout << "[" << it->first << ", " << it->second << "]" << " ";
	}
	std::cout << std::endl;
}

template <typename C>
static void	printContainer(C &arr) {
	typename C::const_iterator	it = arr.begin();
	typename C::const_iterator	ite = arr.end();

	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename C>
static void merge(C &B, int iBegin, int iMiddle,
	int iEnd, C &A) {
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

template <typename C>
static void splitMerge(C &B, int iBegin, int iEnd,
	C &A) {
	int iMiddle;
	
	if (iEnd - iBegin <= 1)
		return;
	
	iMiddle = (iEnd + iBegin) / 2;

	splitMerge(A, iBegin, iMiddle, B);
	splitMerge(A, iMiddle, iEnd, B);

	merge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * Top down merge sort:
 * https://en.wikipedia.org/wiki/Merge_sort
*/
template <typename C>
static void	mergeSort(C& arr) {
	// std::vector<std::pair<int, int> > B(_pairs);
	C	B(arr);
	splitMerge(arr, 0, arr.size(), B);
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "pairs sorted with respect to first number");
	if (LOG_DEBUG)
		printPairContainer(arr);
}

/**
 * https://en.wikipedia.org/wiki/Binary_search_algorithm
 * @param A container of n elements
 * @param T target value
*/
template <typename C>
static int	binarySearch(C& A, int n, int T) {
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

template <typename C>
static bool isSorted(const C& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

/*----------------PRIVATE METHODS--------------*/

template <typename C, typename C_pair>
void	PmergeMe::_PairwiseComparison(C& arr, C_pair& arr_pair) {

	for (size_t i = 0; i < (arr.size() - 1); i += 2) {
		if (arr[i] < arr[i + 1]) {
			arr_pair.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
		else {
			arr_pair.push_back(std::make_pair(arr[i], arr[i + 1]));
		}
    }
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "sorted pairs (within)");
	if (LOG_DEBUG)
		printPairContainer(arr_pair);

	mergeSort(arr_pair);
}

template <typename C_pair, typename T, typename U>
void	PmergeMe::_createChains(C_pair& arr_pair, T& mainchain, U& pend) {
	typename C_pair::const_iterator it;

	for (it = arr_pair.begin(); it != arr_pair.end(); it++) {
		mainchain.push_back(it->first);
		pend.push_back(it->second);
	}

	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "mainchain");
	if (LOG_DEBUG)
		printContainer(mainchain);
	LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "pend");
	if (LOG_DEBUG)
		printContainer(pend);
}

/**
 * understand insertion with jacobsthal:
 * https://stackoverflow.com/questions/27751132/how-does-merge-insertion-sort-work
*/
template <typename T, typename U>
void	PmergeMe::_insertion(T& mainchain, U& pend) {
	size_t	pos;
	size_t	batch = 0;
	int		candidate;
	int		k;

	//first element can be inserted in the mainchain without comparison
	if (pend.size())
		mainchain.insert(mainchain.begin(), pend[0]);

	LOG_MSG(LOG_DEBUG, BG_BOLD_YELLOW, "inserting first pend:");
	if (LOG_DEBUG)
		printContainer(mainchain);

	k = jacobsthalIndeces[batch];
	for (size_t nInsertions = 1; nInsertions < pend.size();) {
		if (k == 0 || k == jacobsthalIndeces[batch - 1]) {
			batch++;
			k = jacobsthalIndeces[batch];
		}
		if (k >= static_cast<int>(pend.size())) {
			k--;
			continue;
		}
		candidate = pend[k];
		pos = binarySearch(mainchain, mainchain.size(), candidate);
		mainchain.insert(mainchain.begin() + pos, candidate);

		LOG_MSG(LOG_DEBUG, BG_BOLD_YELLOW, "k:" << k << " candidate: " << candidate
			<< " pos:" << pos << " sequence after insertion:");
		if (LOG_DEBUG)
			printContainer(mainchain);
		nInsertions++;
		k--;
	}

	//insert stray element if present
	if (_stray != -1) {
		pos = binarySearch(mainchain, mainchain.size(), _stray);
		mainchain.insert(mainchain.begin() + pos, _stray);
	}
}

/*------------------PUBLIC METHODS -----------------*/

int	PmergeMe::fillContainers(int argc, char *argv[]) {
	int num;
	int i;

	for (i = 1; i < argc; i++) {
		num = convertToInt(argv[i]);
		if (num == -1)
			return (-1);
		_vector.push_back(num);
		_deque.push_back(num);
	}
	//uneven so there is a stray number
	if ((i - 1) % 2)
		_stray = num;

	std::cout << "Before:\t";
	printContainer(_vector);

	return (0);
}

void	PmergeMe::FJvec() {
	_startTimeVec = clock();
	_PairwiseComparison(_vector, _pairsVec);
	_createChains(_pairsVec, _mainchainVec, _pendVec);
	_insertion(_mainchainVec, _pendVec);

	_endTimeVec = clock();
	if (LOG_DEBUG && isSorted(_mainchainVec)) {
		LOG_MSG(LOG_DEBUG, BG_BOLD_GREEN, "sorting successfull");
	} else {
		LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "sorting failed");
	}
	std::cout << "After:\t";
	printContainer(_mainchainVec);
}

void	PmergeMe::FJdeq() {
	_startTimeDeq = clock();
	_PairwiseComparison(_deque, _pairsDeq);
	_createChains(_pairsDeq, _mainchainDeq, _pendDeq);
	_insertion(_mainchainDeq, _pendDeq);

	_endTimeDeq = clock();
	if (LOG_DEBUG && isSorted(_mainchainDeq)) {
		LOG_MSG(LOG_DEBUG, BG_BOLD_GREEN, "sorting successfull");
	} else {
		LOG_MSG(LOG_DEBUG, BG_BOLD_RED, "sorting failed");
	}
}

void	PmergeMe::displayRuntime() const {
	double elapsedTimeVec = static_cast<double>(_endTimeVec - _startTimeVec) / static_cast<double>(CLOCKS_PER_SEC);
	double elapsedTimeDeq = static_cast<double>(_endTimeDeq - _startTimeDeq) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout << "Time to process a range of " << _mainchainVec.size()
		<< " elements with std::vector : "  << elapsedTimeVec  << " us" << std::endl;
	std::cout << "Time to process a range of " << _mainchainDeq.size()
		<< " elements with std::deque : "  << elapsedTimeDeq  << " us" << std::endl;
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

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

/**
 * stray initialized to -1 to check later whether there is a stray element
*/
PmergeMe::PmergeMe(void) : _stray(-1), _startTimeVec(0), _endTimeVec(0),
	_startTimeDeq(0), _endTimeDeq(0)//, _itSize(1)
{}

PmergeMe::PmergeMe(const PmergeMe& src)
{
//assign attributes
//or use definition from copy assignment operator
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_stray = rhs._stray;
		_startTimeVec = rhs._startTimeVec;
		_startTimeDeq = rhs._startTimeDeq;
		_endTimeDeq = rhs._endTimeDeq;
		_endTimeVec = rhs._endTimeVec;
		_vector = rhs._vector;
		_pairsVec = rhs._pairsVec;
		_mainchainVec = rhs._mainchainVec;
		_pendVec = rhs._pendVec;
		_deque = rhs._deque;
		_pairsDeq = rhs._pairsDeq;
		_mainchainDeq = rhs._mainchainDeq;
		_pendDeq = rhs._pendDeq;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {
}

/*----------------OPERATOR OVERLOAD---------------*/

// std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
// {
// 	//o << <fill ostream with attributes>
// 	return (o);
// }
