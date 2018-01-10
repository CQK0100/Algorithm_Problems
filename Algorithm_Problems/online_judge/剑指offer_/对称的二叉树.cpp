/*
 ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�
 ���һ�������������ľ���һ������ô���ǶԳƵġ�
*/
#include"predefines.h"

bool IsSymmetrical(BinaryNode<int>* lhs, BinaryNode<int>* rhs);

bool IsSymmetrical(BinaryNode<int>* root) {
	return IsSymmetrical(root, root);
}

bool IsSymmetrical(BinaryNode<int>* lhs, BinaryNode<int>* rhs) {
	if (!lhs && !rhs)
		return true;
	if (!lhs || !rhs)
		return false;
	if (lhs->value != rhs->value)
		return false;
	return IsSymmetrical(lhs->left, rhs->right) &&
		IsSymmetrical(lhs->right, rhs->left);
}

int main() {
	vector<int> arr{ 8,6,6,5,7,7,5};
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree<int>(&root,arr);
	std::cout << IsSymmetrical(root) << std::endl;
	DestoryBTree(&root);
	return 0;
}