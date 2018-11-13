// Compile Time Diagnostics (Item 4, p.31) 

// Declaration of class template which ISN'T defined
template <typename T>
class TD; // Type Displayer

// Then suppose we have some unknown type x
auto x = 1;

// Attempts to instantiate the above template will elicit an
// error message that generally contains useful type information 
TD<decltype(x)> xType;

// Runtime Output (Item 4, p.34) 

// To produce accurate type information at runtime use Boost.TypeIndex

#include <boost/type_index.hpp>

template <typename T>
void outputTypeInfo(const T &param) {

	// cvr = const, volatile and reference qualifiers
	using boost:typeindex::type_id_with_cvr; 

	std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;

	std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}