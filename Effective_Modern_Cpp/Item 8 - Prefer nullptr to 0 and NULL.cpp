// (Item 8, p.58)

// Neither 0 nor NULL has a pointer type. 0 is an int and NULL is an integral type.

// Suppose we have overloaded function f:

void f(int x) {};
void f(void* x) {}; // Some pointer type

f(0); // calls f(int)
f(NULL); // might not compile, otherwise calls f(int)
f(nullptr); // call f(void*)