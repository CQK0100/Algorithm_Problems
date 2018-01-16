/*
  ����һ�ö�������һ����������ӡ���������ڵ�ֵ�ĺ�Ϊ��������������·����
  ��������·�����Ӹ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γɵ�һ��·����
*/

#include"predefines.h"

// �ݹ�汾

void FindPaths(BinaryNode<int>* root, const int& expected,
	vector<int>& path, int cur_sum) {
	cur_sum += root->value;
	path.push_back(root->value);
	// �����Ҷ�ڵ���������������ӡ
	if (cur_sum == expected && ((!root->left) && (!root->right))) {
		std::printf("A path found:\n");
		for (auto& p : path)
			std::printf("%d -> ", p);
		cout << "null" << endl;
	}
	if (root->left)
		FindPaths(root->left, expected, path, cur_sum);
	if (root->right)
		FindPaths(root->right, expected, path, cur_sum);
	// ���ظ��ڵ㣬��·����ɾ����ǰ�ڵ�
	path.pop_back();
}

void FindPaths(BinaryNode<int>* root, const int& expected) {
	if (!root)
		return;
	vector<int> path;
	int cur_sum = 0;
	FindPaths(root, expected, path, cur_sum);
}

int main() {
	vector<int> tree{ 10,5,12,4,7 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	FindPaths(root, 22);
	DestoryBTree(&root);
	return 0;
}