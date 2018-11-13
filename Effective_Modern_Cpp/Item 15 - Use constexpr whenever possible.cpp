// (Item 15, p.97)
#include <array>

// constexpre objects are const and they have values that are known at
// compile time. Integral values that are constexpr are "integral constant
// expressions" and can be used to specify array sizes, integral template
// arguments, enumerator values and more.

int sz; // non-constexpr variable

constexpr auto arraySize1 = sz; // error! sz's value not known at compilation

std::array<int, sz> data1; // error! same problem

constexpr auto arraySize2 = 10; // fine, 10 is a compile time constant

std::array<int, arraySize2> data1; // fine, arraySize2 is constexpr

// constexpr functions produce compile-time constants when they are called
// with compile-time constants arguments. If they're called with values
// not known until runtime, they produce runtime values.

// In C++11, constexpr functions may contain no more than a single executable
// statement: a return. But the conditional ternary operator "?:" can be used
// as well as recursion:

constexpr int powC11(int base, int exp) noexcept {
	return (exp == 0 ? 1 : base * pow(base, exp - 1)); // C++11
}

constexpr int powC14(int base, int exp) noexcept {
	auto result = 1;
	for (int i = 0; i < exp; ++i) result *= base;

	return result;
}

// constexpr functions are limited to taking and returning "literal types",
// which essentially means types that can have values determined during compilation.
// In C++11, all builtin types except void qualify. User-defined types may also
// be literal because constructors and other member functions may be constexpr:

class Point {
	double x, y;

public:
	constexpr Point(double xVal = 0, double yVal = 0) noexcept
		: x(xVal), y(yVal) {};
};

constexpr Point p(9.4, 27.7); // "Runs" constexpr constructor during compilation 
