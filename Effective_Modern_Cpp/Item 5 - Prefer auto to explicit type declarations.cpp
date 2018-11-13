// (Item 5, p.37)

// As auto variables require initialisation to perform type deduction, they 
// are safer than "int x;", say, whereby the x has forgotten to be initialised.

int x1; // potentially uninitialised

auto x2; // error! initialisation required


// Recovering underlying type of iterator.
#include <iterator> 

template <typename It>
void f(It b) {

	typename std::iterator_traits<It>::value_type currValue1 = *b;

	// Much easier approach
	auto currValue2 = *b;
}

// Issue - "type shortcuts" 
#include <vector>

std::vector<int> v;

unsigned sz1 = v.size(); // type should be std::vector<int>::size_type

auto sz2 = v.size(); // correctly std::vector<int>::size_type

// Issue - unintentional type mismatch
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> m;

for (const std::pair<std::string, int> &p : m) { // should be std::pair<const std::string, int>
	//...
}

for (const auto &p : m) { // correctly std::pair<const std::string, int>
	//...
}
