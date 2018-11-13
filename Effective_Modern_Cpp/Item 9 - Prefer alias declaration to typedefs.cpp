// (Item 9, p.63)

#include <memory>
#include <unordered_map>
#include <string>

// Old typedef
typedef std::unique_ptr<std::unordered_map<std::string, std::string> > UPtrMapSS;

// Alias declaration
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string> >;

// And for function pointers

// Old typedef
typedef void(*FP)(int, const std::string&);

// Alias declaration
using FP = void(*)(int, const std::string&);


// Much easier to create templates from aliases than from typedefs
#include <list>

template <typename T>
using myAllocList = std::list<T, myAlloc<T> >;

template <typename T>
struct myAllocList {
	typedef std::list<T, myAlloc<T> > type;
};
