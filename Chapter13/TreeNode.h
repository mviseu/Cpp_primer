#pragma once
#include <string>

using std::string;

class TreeNode {
public:
	TreeNode(const string &s = string(), int value = 0)
	 : value(s), count(value), left(nullptr), right(nullptr) {}
	 TreeNode(const TreeNode &rhs);
	 TreeNode &operator=(const TreeNode &rhs);
	 ~TreeNode();

private:
	//make the class act like a value (deep copies)
	string value;
	int count = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

};