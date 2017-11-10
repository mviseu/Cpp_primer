#pragma once

namespace ar {

template <typename T, unsigned D> constexpr unsigned size(T (&arr) [D]) {
	return D;
}

} // namespace ar
