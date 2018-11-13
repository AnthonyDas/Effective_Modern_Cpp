// (Item 1, p.11)

// Suppose we have a template
template<typename T>
void f(ParamType param) {};

// And a function call from which both Param Type and T must be deduced
f(expr); 

// Case 1: ParamType is a Referenbce or Pointer (but not Universal Reference)
// - 1. If expr's type is a reference, ignore the reference part.
// - 2. Then pattern-match expr's type against ParamType to determine T.

// Case 2: ParamType is a Universal Reference
// - If expr is an lvalue, both ParamType and T are deduced to be lvalue references.
// - If expre is an rvalue, then Case 1 rules apply.

// Case 3: ParamType is by value
// - 1. As before, if expr's type is a reference, ignore the reference part.
// - 2. If expr is const, ignore that. If expr is volatile, ignore that. 

// Array arguments (p.15)
const char name[] = "Anthony Das"; // name's type is const char[12], 11 + '\0' terminator 

const char * ptrName = name; // array decays to pointer

// There is no such thing as a function parameter that's an array
void myFunc1(int param[]); // syntax is legal but the array is treated like a pointer declaration

// Hence above is equivalent to 
void myFunc2(int * param);

template<typename T>
void f2(T param) {};

f2(name); // name is array, but T deduced to be const char *

// Although functions can't declare parameters that are true arrays,
// they can declare parameters that are references to arrays.

template<typename T>
void f3(T &param) {};

f3(name); // name is array, T deduced to be const char[12]

// Function arguments (p.17)

// Function types decay to pointers like arrays decay to pointers.

void someFunc(int, double) {}; //type is void (int, double)

f2(someFunc); // param deduced to be ptr-to-func void (*)(int, double)

f3(someFunc); // param deduced to be ref-to-func void (&)(int, double)