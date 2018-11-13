// (Item 3, p.25-28)

#include <utility> // std::forward

// Note the use of auto to indicate trailing return type given after the "->".
// Type deduction does not occur for this auto but rather at the location of decltype.
// Perfect forwarding is employed via std::forward.
template<typename Container, typename Index>
auto authAndAccessC11(Container &&c, Index i)
-> decltype(std::forward<Container>(c)[i])
{
	// authenticateUser();

	return std::forward<Container>(c)[i];
}


// Note the use of dectype(auto) to indicate type deduction for return type.
// Perfect forwarding is employed via std::forward.
template<typename Container, typename Index>
decltype(auto) authAndAccessC14(Container &&c, Index i) {

	// authenticateUser();

	return std::forward<Container>(c)[i];
}


// Applying decltype to a name yields a type for that name. Names are typically lvalue expressions,
// but that doesn't affect decltype's behaviour. For lvalue expressions more complicated than names,
// however, decltype generally ensures that the type reported is an lvalve reference.

decltype(auto) f1() {
	int x = 0;
	return x; // decltype(x) is int, so f1 returns int
}

decltype(auto) f2() {
	int x = 0;
	return (x); // decltype((x)) is int&, so f2 returns int&
}
