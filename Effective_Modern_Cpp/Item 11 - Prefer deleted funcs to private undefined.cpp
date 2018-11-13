// (Item 11, p.74)

// A tactic to prevent calls to a function is to make them private and undefined:
class basic_ios : public ios_base {

private:

	basic_ios(const basic_ios&); // Private undefined
};

// Better to do the following:
class basic_ios : public ios_base {

public:

	basic_ios(const basic_ios&) = delete; // Deleted
};

// Private functions may still be called by class member functions
// and friends. The undefined function would only cause an error at
// linking time. However, deleted function may not be used in any way.

// By convention deleted function are declared public, not private.
// Some compilers will otherwise complain about accessibility which
// doesn't really affect whether the function can be used.

// Any function may be deleted while only member functions may be private.
// This makes it easy to delete class member template specialisations which
// must be delcared at namespace scope outside the class, to prevent access
// with undesirable parameter types. (As such template specialisations are 
// outside the class, they cannot be made private).

class Widget {
public:
	
	template <typename T>
	void processPointer(T* ptr) {};

private:

	template <>
	void processPointer(void*) = delete; // error
};

// Instead do the following
template <>
void Widget::processPointer(void*) = delete; // public and deleted


// Suppose we have: 
bool islucky(int number) {};

// Prevent other types from implicitly converting to int:
bool islucky(char) = delete;
bool islucky(bool) = delete;
bool islucky(double) = delete;
