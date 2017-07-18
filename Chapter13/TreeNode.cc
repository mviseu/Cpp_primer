#include "TreeNode.h"

TreeNode::TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(nullptr), right(nullptr) {
	if(rhs.left) {left = new TreeNode(*rhs.left);}
	if(rhs.right) {right = new TreeNode(*rhs.right);}
}

TreeNode::~TreeNode() {
	if(left) {delete left;}
	if(right) {delete right;}
}

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
	auto left_copy = (rhs.left ? new TreeNode(*rhs.left) : nullptr);
	auto right_copy = (rhs.right ? new TreeNode(*rhs.right) : nullptr);
	if(left) {delete left;}
	if(right) {delete right;}
	left = left_copy;
	right = right_copy;
	count = rhs.count;
	value = rhs.value;
	return *this;
}
