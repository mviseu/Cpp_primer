#include "TreeNode.h"
#include "BinStrTree.h"

int main() {
	TreeNode tn, tn1(tn), tn2;
	tn1 = tn2;
	BinStrTree bstr(tn), bstr2(bstr);
	bstr2 = bstr2;
	bstr2 = bstr;
	return 0;
}