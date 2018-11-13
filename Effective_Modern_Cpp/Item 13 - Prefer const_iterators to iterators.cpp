// (Item 13, p.86)

// The standard practice of using const wherever possible dictates that
// you should use const_iterators any time you need an iterator, yet
// have no need to modify what ther iterator point to.

// In maximally generic code, prefer non-member versions of begin(),
// end(), rbegin() etc. over their member function counterparts.

#include <iterator>
#include <algorithm>

template<typename C, typename V>
void findAndInsert(C& container, const V &targetVal, const V &insertVal) {

	using std::cbegin;
	using std::cend;

	// Uses non-member cbegin() and cend()
	auto it = std::find(cbegin(container, cend(container), targetVal);

	container.insert(it, insertVal);
}

// C++11 added non-member function begin() and end(), but it failed to
// add cbegin(), cend() etc. C++14 rectified the situation. But it's 
// easy to write one's own implementation:

template <class C>
auto cbegin(const C& container)
-> decltype(std::begin(container)) // C++11
{
	return std::begin(container); // Yes, used std::begin()! See below.
}

// If C is a conventional container, then container param will be a
// reference to a const version of that container. Invoking the non-member
// begin function (provided by C++11) on a const container yields a
// const_iterator. This approach works for containers which offer a
// begin member function (which, for containers, is what C++11's non-member
// begin calls) but fail to offer a cbegin member function.
