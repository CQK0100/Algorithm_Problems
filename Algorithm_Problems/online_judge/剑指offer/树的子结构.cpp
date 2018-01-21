/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ��
*/
#include"predefines.h"

using namespace std;


// ����double��������
bool IsEqual(const double& lhs, const double& rhs) {
	if (std::abs(lhs - rhs) < 0.0000001)
		return true;
	return false;
}

bool DoesOneHasAnother(BinaryNode<double>* first, BinaryNode<double>* second) {
	if (!first)  // �����Ѿ������˵���С����û�У���ƥ��
		return false;
	if (!second)  // С���Ѿ������ˣ�ƥ��
		return true;
	if (!IsEqual(first->value, second->value))
		return false;
	return DoesOneHasAnother(first->left, second->left) &&
		DoesOneHasAnother(first->right, second->right);
}

bool HasSubTree(BinaryNode<double>* first, BinaryNode<double>* second) {
	bool ans = false;
	if (first&&second) {
		if (IsEqual(first->value, second->value)) {
			ans = DoesOneHasAnother(first, second);
		}
		if (!ans)
			ans = HasSubTree(first->left, second);
		if (!ans)
			ans = HasSubTree(first->right, second);
	}
	return ans;
}


int main() {
	BinaryNode<double>* big = new BinaryNode<double>;
	vector<double> arr{ 8,8,7,9,2,4,7 };
	BuildBTree(&big, arr);
	BinaryNode<double>* small = new BinaryNode<double>;
	vector<double> arr2{ 8,9,2 };
	BuildBTree(&small, arr2);
	cout << HasSubTree(big, small) << endl;
	DestoryBTree(&small);
	DestoryBTree(&big);
	return 0;
}