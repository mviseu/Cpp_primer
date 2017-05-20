#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> vec;
    std::string s;
    while (std::cin >> s) {
        vec.push_back(s);
    }
    if (vec.empty()) {
        std::cout << "The vector is empty\n";
	    return 0;
    }
    auto longest_strike = 1;
    auto longest_strike_iterator = vec.cbegin();
    auto current_strike = 1;
    for (auto current_iterator = vec.cbegin(); current_iterator != vec.cend() - 1; ++current_iterator) {
    	if (*current_iterator == *(current_iterator + 1)) {
            ++current_strike;
        } else {
            current_strike = 1;
        }
        if (current_strike >= longest_strike) {
            longest_strike = current_strike;
            longest_strike_iterator = current_iterator;
       }
    }
    if (longest_strike == 1) {
        std::cout << "There are no repeated words\n";    
    } else {
        std::cout << "The word: " << *longest_strike_iterator << " is repeated " << longest_strike << " times, which is the (or one of the) longest sequential strike(s)\n";
    }
    return 0;
}
