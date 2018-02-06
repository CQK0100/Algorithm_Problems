/*
  ����һ�����ĸ��ڵ㣬�жϸ����Ƿ���ƽ���������
*/
#include"predefines.h"
#include<algorithm>
/*
  ��������<�����������>�Ľ������������ÿ�����ڵ�ʱ������һ��DepthOfBinaryTree,
  �����������д����ڵ���ظ����㣬�����ܵ���
*/

/*
  ��ô�Զ����ϣ����ú���������ڱ���ĳ���ڵ�ʱ�����������������Ѿ����������ˡ�
*/
bool IsBalanceTree(BinaryNode<int>* root, int& depth) {
	if (!root) {
		depth = 0;
		return true;
	}
	int left, right;
	if (IsBalanceTree(root->left, left) && IsBalanceTree(root->right, right)){
		if (std::abs(left - right) <= 1) {
			depth = (left > right) ? left : right;
			return true;
		}
	}
	return false;
}