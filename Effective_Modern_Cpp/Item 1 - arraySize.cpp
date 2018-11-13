// (Item 1, p.16)

// Return size of an array as a compile-time constant. 
// The array parameter has no name because we only care
// about the number of elements it contains. We need
// templated N because we are passing an array by reference
// and must fully specify it including its size, which is
// unknown.
template <typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept {
	return N;
}
