#pragma once

namespace ar {
template <typename T, unsigned D> T *begin(T (&arr) [D]) {
	return arr;
}

template <typename T, unsigned D> T *end(T (&arr) [D]) {
	return &arr[D];
}

} // namespace ar
