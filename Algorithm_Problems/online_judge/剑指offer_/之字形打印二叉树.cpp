/*
ʵ��һ����������֮����˳���ӡ������������һ�д�����˳���ӡ���ڶ��д��ҵ���
�������ٴ����ң��Դ����ơ�

                        1
					  2   3
					4  5 6  7
				8 9 10 11 12 13 14 15 
���϶���������ӡ˳��
1 
3 2
4 5 6 7
15 14 13 12 11 10 9 8

*/
#include"predefines.h"
#include<stack>

using namespace std;

void PrintInSpecialOrder(BinaryNode<int>* root) {
	if (!root)
		return;
	int cur = 0, next = 1;
	stack<BinaryNode<int>*> levels[2];
	levels[cur].push(root);
	while (!levels[0].empty() || !levels[1].empty()) {
		auto node = levels[cur].top();
		levels[cur].pop();
		std::printf("%d ", node->value);
		if (cur == 0) {  // �����ҵ�˳����ջ�����ҵ����˳���ӡ
			if (node->left)
				levels[next].push(node->left);
			if (node->right)
				levels[next].push(node->right);
		}
		else {  // ���ҵ����˳����ջ�������ҵ�˳���ӡ
			if (node->right) 
				levels[next].push(node->right);
			if (node->left)
				levels[next].push(node->left);
		}
		if (levels[cur].empty()) {
			printf("\n");
			cur = 1 - cur; // ��0��1֮��ת��
			next = 1 - next; // ͬ��
		}
	}
}

int main() {
	vector<int> tree{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	PrintInSpecialOrder(root);
	DestoryBTree(&root);
	return 0;
}