// (Item 1, p.16)

// Return size of an array as a compile-time constant. 
// The array parameter has no name because we only care
// about the number of elements it contains.
template <typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept {
	return N;
}
