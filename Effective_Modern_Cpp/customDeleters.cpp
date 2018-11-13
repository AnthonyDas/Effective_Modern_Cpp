#include <memory>

class Widget {};

// Custom deleter
auto del = [](Widget *pw) { delete pw; };

// For unique_ptr customer deleter becomes part of the pointer type
std::unique_ptr<Widget, decltype(del)> upw(new Widget, del);

// For shared_ptr customer deleter doesn't change pointer type
std::shared_ptr<Widget> upw(new Widget, del);