// (Item 7, p.49)

// Initialisation is not assignment

class Widget {};

Widget w1; // default constructed

Widget w2 = w1; // copy constructed

w1 = w2; // copy assignment

// Braced initialisation prohibits implicit narrowing
#include <limits>
double x = std::numeric_limits<double>::max(), y = x, z = x;

int sum1 { x + y + z }; // error! sum of double not expressible as int

// Most vexing parse - C++'s rule that anything that can be
// interpreted as a declaration must be interpreted as one

Widget w3(); // Most vexing parse - declares a function w3 that return a Widget
Widget w4{}; // Calls default constructor

// Main drawback of braced initialisation is that auto declared variables with a
// braced initialiser will be deduced as a std::initializer_list.

// Class constructor overload resolution: If one of more class constructors declare
// a std::initializer_list parameter, calls using braced initialisation syntax
// will strongly prefer the overload taking std::initializer_list if there is any way
// for the compiler to construe such a call.

// Edge case: suppose a class supports default construction and also std::initializer_list
// construction. Using an empty set of braces to construct an object will call the default
// constructor. Empty braces means no arguments, not an empty std::initializer_list.

// If you want to call a constructor with an emprt std::initializer_list, do it by the 
// empty braces a constructor arg:
Widget w5({});
Widget w6{ {} };

// Be aware that some templates treat () and {} initialisation differently:
#include <vector>
std::vector<int> v1(10, 20); // 10 elements all having value 20
std::vector<int> v2{ 10, 20 }; // 2 elements with values 10 and 20