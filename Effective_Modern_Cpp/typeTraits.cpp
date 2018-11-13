
// Recovering underlying type of iterator. (Item 5, p.37)
#include <iterator> 

template <typename It>
void f(It b) {
	
	// But try to emply auto instead anyway 
	typename std::iterator_traits<It>::value_type;
}

// (Item 9, p.66)

#include <type_traits>

template <typename T>
void f(T n) {
	
	std::remove_const<T>::type a; // C++ 11
	std::remove_const_t<T> b; // C++ 14

	std::remove_reference<T>::type c; // C++ 11
	std::remove_reference_t<T> d; // C++ 14

	std::add_lvalue_reference<T>::type e; // C++ 11
	std::add_lvalue_reference_t<T> f; // C++ 14
}
