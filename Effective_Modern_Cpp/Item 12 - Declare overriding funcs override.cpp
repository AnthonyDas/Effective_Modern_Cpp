// (Item 12, p.79)
#include <vector>

// For overriding (where derived classes "override" the implementation of
// their base class - not to be confused with "overloading") to occer, we need:
// - Base class function to be virtual.
// - Based and derived functions names must be identical (except destructors).
// - Parameter types of the base and derived functions must be identical.
// - The constness of the base and derived function must be identical.
// - The return type and exception specifications must be compatible.
// C++ 11 adds one more constraint:
// - The functions reference qualifiers must be identical:

class Widget {
public:
	using DataType = std::vector<int>;

	// This version applies when *this is an lvalue
	DataType& data() &
	{ return values; }

	// This version applies when *this is an rvalue
	DataType&& data() &&
	{ return std::move(values); }

	virtual void func(); // To be overridden in derived classes

private:
	DataType values;
};

// Because declaring derived class overrides is easy to get wrong, make explicit
// that a derived class function is supposed to override a base class version:
class Derived_Widget : public Widget {
public:

	void func() override;
};

// "final" is a contextual keyword introduced in C++11. Applying final to a
// virtual function prevents it from being overridden in derived classes. final
// may also be applied to a class, in which case the class is prohibited from
// being used as a base clase.
