#pragma once
#include "TreeNode.h"

class BinStrTree {
public:
	BinStrTree(const TreeNode &tn = TreeNode()) : root(new TreeNode(tn)) {}
	BinStrTree(const BinStrTree &rhs) : root(new TreeNode(*rhs.root)) {} 
	BinStrTree &operator =(const BinStrTree &rhs) {
		auto root_copy = new TreeNode(*rhs.root);
		delete root;
		root = root_copy;
		return *this;
	}
	~BinStrTree() {delete root;}
private:
	TreeNode *root;
};