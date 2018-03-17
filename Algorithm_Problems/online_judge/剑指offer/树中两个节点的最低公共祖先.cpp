/*
  RT.
*/
#include"predefines.h"

/*
  ����Ƕ�������������ô�Ǿ�������ġ�
  �����ǰ�ڵ��ֵ�������ڵ��ֵ������ô��͹������ڵ�һ���ڵ�ǰ�ڵ���������¡�
  .............................С��................................��......
  ����ǰ�ڵ��ֵ�������ڵ��ֵ�м䣬��ô������͹������ڵ㡣
*/

template<typename T>
BinaryNode<T>* LowestCommonAncestorOfBST(BinaryNode<T>* root, BinaryNode<T>* lhs, BinaryNode<T>* rhs) {
	if (!root || !lhs || !rhs)
		return nullptr;
	if (lhs->value > rhs->value)
		std::swap(lhs, rhs);
	auto cur = root;
	while (cur && (cur->value > rhs->value || cur->value < lhs->value)) {
		if (cur->value > rhs->value)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return cur;
}

