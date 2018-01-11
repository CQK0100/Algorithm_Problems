/*
�����д��ϵ��´�ӡ������(�������)
*/
#include"predefines.h"
#include<queue>

using namespace std;

// ����ͼ��һ�������˻���ʽ�����ʾ��ǹ�����ȱ���������
void PrintByLevelOrder(BinaryNode<int>* root) {
	queue<BinaryNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		std::cout << cur->value << ' ';
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	std::cout << std::endl;
}

int main() {
	BinaryNode<int>* root = new BinaryNode<int>;
	vector<int> arr{ 8,6,10,5,7,9,11 };
	BuildBTree(&root, arr);
	PrintByLevelOrder(root);
	DestoryBTree(&root);
	return 0;
}