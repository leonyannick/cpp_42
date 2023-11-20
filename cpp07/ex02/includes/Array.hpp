#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<class T>
class Array
{
public:
	// public methods
	unsigned int	size() const {return _nElements;}
	//Getters and Setters

	// Constructors, Assignment, Destructors

	//new <var>() zero initializes the allocated memory
	//use array allocaiton here so we can use delete []
	//alternative: use only delete in destructor when _nElements == 0
	Array(void) throw (std::exception) : _mem(new T[0]()), _nElements(0) {
		if (!_mem)
			throw (std::bad_alloc());
	}

	//works also for arr allocation: new<var>[]()
	Array(unsigned int n) throw (std::exception) : _mem(new T[n]()), _nElements(n) {
		if (!_mem)
			throw (std::bad_alloc());
	};

	Array(const Array& src) throw (std::exception)
		: _mem(new T[src._nElements]()), _nElements(src._nElements) {
		if (!_mem)
			throw (std::bad_alloc());
		std::cout << "cp ct" << std::endl;
		for (size_t i = 0; i < src.size(); i++) {
				_mem[i] = src[i];
			}
	}

	Array& operator=(const Array& other) {
		std::cout << "cp assignment" << std::endl;
		if (this != &other) {
			delete [] _mem;
			_mem = new T[other.size()];
			for (size_t i = 0; i < other.size(); i++) {
				_mem[i] = other[i];
			}
		}
		return (*this);
	}

	T& operator[](unsigned int idx) throw (std::exception) {
		if (idx < 0 || idx >= _nElements)
			throw(std::out_of_range("Index out of range"));
		return (_mem[idx]);
		};

	const T& operator[](unsigned int idx) const throw (std::exception) {
		if (idx < 0 || idx >= _nElements)
			throw(std::out_of_range("Index out of range"));
		return (_mem[idx]);
	};

	~Array(void) {delete [] _mem;};

private:
	// Data
	T* _mem;
	unsigned int	_nElements;
};

template<class T>
std::ostream &		operator<<(std::ostream & o, Array<T> const & arr) {
	o << "{";
	for (unsigned int i = 0; i < arr.size(); i++) {
		o << arr[i];
		if (i < arr.size() - 1)
			o << ", ";
	}
	o << "}";
	return(o);
}


#endif

