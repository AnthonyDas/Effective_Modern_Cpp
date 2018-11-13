// (Item 14, p.90)

// Whether a function is noexcept is as an important piece of information
// as whether a member function is const. It is part of a function's
// interface and callers may depend on it.

// In a noexcept function, optimisers need not keep the runtime stack
// in an unwindable state if an exception would propogate out of the 
// function, nor must they ensure that objects in a noexcept function
// are destroyed in the inverse order of construction shoud an exception
// leave the function.

int f(int x); // less optimisable

int f1(int x) throw(); // less optimisable, no exceptions, C++98 style

int f2(int x) noexcept; // most optimisable, no exceptions, C++11 style

// swap is a key component of many STL algorithm implementations.
// Its widespread use renders the optimisations that noexcept affords
// especially worthwhile. Moreover, the fact that swapping higher-level
// data structures can generally be noexcept only if swapping their 
// lower-lever constituents is noexcept should motivate you to offer
// noexcept swap functions whenever you can.

// Swapping arrays

// We need templated N because we are passing an array by reference
// and must fully specify it including its size, which is unknown.
template <class T, size_t N>
void swap(T(&a)[N], T(&b)[N]) noexcept(noexcept(swap(*a, *b)));

// Swapping a pair

template <class T1, class T2>
struct pair {
	void swap(pair &p) noexcept(noexcept(swap(first, p.first)) &&
								noexcept(swap(second, p.second)));
};

// By default, all memory deallocation functions and all destructors
// (both user-defined and compiler-generated) are implicitly noexcept.