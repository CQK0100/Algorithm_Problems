/*
���һ������������һ�ö�������������ľ���
(��ת������)
*/
#include"predefines.h"
#include<queue>
using namespace std;

void ReverseBinaryTree(BinaryNode<int>* root) {
	if (!root||(!root->left&&!root->right))
		return;
	auto tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	ReverseBinaryTree(root->left);
	ReverseBinaryTree(root->right);
}

// �ǵݹ�汾
void ReverseBinaryTree_NoRecursive(BinaryNode<int>* root) {
	if (!root)
		return;
	queue<BinaryNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		auto tmp = cur->left;
		cur->left = cur->right;
		cur->right = tmp;
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
}

int main() {
	vector<int> tree{ 8,6,5,7,10,9,11 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree<int>(&root, tree);
	PrintBTree_Pre(root);
	ReverseBinaryTree_NoRecursive(root);
	PrintBTree_Pre(root);
	DestoryBTree(&root);
	return 0;
}
