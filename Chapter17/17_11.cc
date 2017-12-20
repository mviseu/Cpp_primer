#include <bitset>
#include <stdexcept>
#include <iostream>

template <std::size_t S> struct Quiz {
	Quiz &setAnswer(std::size_t pos, bool answer = true) {
		check_pos(--pos);
		answers.set(pos, answer);
		return *this;
	}

	std::size_t gradeAnswers(const std::bitset<S> &solutions) const {
		std::bitset<S> compare = solutions ^ answers;
		compare.flip();
		return compare.count();

	}

	void check_pos(std::size_t pos) const {
		if(pos < 0 || pos > S - 1) {
			throw std::invalid_argument("Index position is not in range");
		}
	}
	std::bitset<S> answers;
};

template <std::size_t S> 
std::ostream &reportAnswers(std::ostream &os, const Quiz<S> &quiz) {
	return os << quiz.answers << std::endl;
}



int main() {
	std::bitset<10> bs;

	Quiz<10> qz;
	qz.setAnswer(2).setAnswer(10).setAnswer(1);
	//qz.setAnswer(0, false);

	reportAnswers(std::cout, qz);

	std::string sol("1000000001");
	std::bitset<10> solBit(sol);
	std::cout << qz.gradeAnswers(solBit) << std::endl;

	return 0;
}