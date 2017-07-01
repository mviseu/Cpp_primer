#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

std::map<std::string, std::vector<std::string>> &addFamily(std::map<std::string, std::vector<std::string>> &families, 
														   const std::pair<std::string, std::vector<std::string>> &family) {
	families[family.first] = family.second; 
	return families;
}

std::map<std::string, std::vector<std::string>> &addChildren(std::map<std::string, std::vector<std::string>> &families, 
														    const std::string &surname, const std::vector<std::string> &children) {
	std::copy(children.cbegin(), children.cend(), std::back_inserter(families[surname])); 
	return families;
}

void printFamilies(std::ostream_iterator<std::string> out, const std::map<std::string, std::vector<std::string>>&families) {
	std::vector<std::string> family;
	for_each(families.cbegin(), families.cend(), [&](const std::pair<std::string, std::vector<std::string>>&family) {
		out = family.first;
		std::copy(family.second.cbegin(), family.second.cend(), out);
		out = "\n";
	});

}

int main() {
	//empty map
	std::map<std::string, std::vector<std::string>>families;
	//add a family
	const std::vector<std::string> children = {"Ella", "Beth", "John"};
	const std::string surname = "Smith";
	const std::vector<std::string> children2 = {"Michelle", "Barack"};
	const std::string surname2 = "Obama";
	addFamily(families, std::make_pair(surname, children));
	std::ostream_iterator<std::string> out(std::cout, " ");
	std::vector<std::string> new_children = {"Mary", "William"};
	addChildren(families, surname, new_children);
	addFamily(families, std::make_pair(surname2, children2));
	const std::vector<std::string> new_children2 = {"someone"};
	addChildren(families, surname2, new_children2);
	printFamilies(out, families);
	return 0;
}