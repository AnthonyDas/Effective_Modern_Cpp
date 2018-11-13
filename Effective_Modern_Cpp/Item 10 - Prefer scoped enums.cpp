// (Item 10, p.71)

// Generally, declaring a name inside curly braces limits the visibility of that name to
// the scope defined by the braces. Not so for unscoped (C++ 98) enums. The names of such
// enumerators belong to the scope containing the enum, and that means nothing else in that
// scope may have the same name.

#include <string>
#include <tuple>

// name, email, reputation
using UserInfo = std::tuple<std::string, std::string, size_t>;

UserInfo uInfo;

// Client code then contains
auto val = std::get<1>(uInfo); // But what is field 1?

// Introduce an unscoped enum
enum UserInfoFields1 { uiName, uiEmail, uiReputation };

auto val2 = std::get<uiEmail>(uInfo);

// But a class/scoped enum is preferable
enum class UserInfoFields2 { uiName, uiEmail, uiReputation };

// But unfortunately leads to more verbose code
auto val3 = std::get<static_cast<size_t>(UserInfoFields2::uiEmail)>(uInfo);

// Helper function
template <typename E>
constexpr typename std::underlying_type<E>::type enumToUTypeC11(E enumerator) noexcept {
	return static_cast<typename std::underlying_type<E>::type>(enumerator);
}


template <typename E>
constexpr auto enumToUTypeC14(E enumerator) noexcept {
	return static_cast<typename std::underlying_type_t<E>>(enumerator);
}

// Then we have
auto val4 = std::get<enumToUTypeC11(UserInfoFields2::uiEmail)>(uInfo);

auto val5 = std::get<enumToUTypeC14(UserInfoFields2::uiEmail)>(uInfo);