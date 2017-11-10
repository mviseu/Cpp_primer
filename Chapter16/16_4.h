#pragma once

namespace fd {
	template <typename T, typename V> T find(const T &start_it, const T &end_it, const V &val) {
		T i = start_it;
		for(; i != end_it; ++i) {
			if(*i == val) {
				return i;
			}
		}
		return i;
	} 
}
