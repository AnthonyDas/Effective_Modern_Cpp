// (Item 2, p.18)

// auto type deduction is template type deduction except when brace initialisers
// are involved, {...}. auto assumes that a braced initialiser represents a
// std::initializer_list, but tempalte type deduction does not.

template<typename T>
void f(ParamType param);

// auto plays the role of T in the template and the type specifier for the variable acts as ParamType

auto x = 27;

// Conceptual template for deducing x's type
template<typename T>
void fx(T param);

fx(27);

const auto cx = x;

// Conceptual template for deducing cx's type
template<typename T>
void fcx(const T param);

fcx(x);

const auto& rx = x;

// Conceptual template for deducing rx's type
template<typename T>
void frx(const T& param);

frx(x);

// auto and brace initialisers (p.21)
#include <initializer_list>

int x1 { 27 }; // int with value 27
auto x2 { 27 }; // std::initializer_list<int> { 27 }

auto x3 = { 11, 23, 9 }; // std::initializer_list<int> { 11, 23, 9  }

template<typename T>
void f1(T param) {};

f1({ 11, 23, 9 }); // error! can't deduce type for T

// However, if we specify that param is a std::initializer_list<T>

template<typename T>
void f2(std::initializer_list<T> param) {};

f2({ 11, 23, 9 }); // T deduced as int and param is std::initializer_list<int>