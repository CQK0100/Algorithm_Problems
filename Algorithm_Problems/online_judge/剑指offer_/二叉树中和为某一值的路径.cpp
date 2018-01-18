/*
  ����һ�ö�������һ����������ӡ���������ڵ�ֵ�ĺ�Ϊ��������������·����
  ��������·�����Ӹ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γɵ�һ��·����
*/

#include"predefines.h"
using std::pair;
using std::array;
using std::make_pair;
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


// �ǵݹ�汾
void FindPaths_NonRecur(BinaryNode<int>* root, const int& expected) {
	int cur_sum = 0;
	const int LEFT = 0, RIGHT = 1;
	// �� vector(2) ��ʾ�Ƿ��ѷ��ʹ���/���ӽڵ�
	vector<pair<BinaryNode<int>*, vector<bool>>> path; 
	path.push_back({ root, { false,false } });
	cur_sum += root->value;
	while (!path.empty()) {
		auto cur = path.back();
		if (!cur.first->left && !cur.first->right) {
			if (cur_sum == expected) {
				std::printf("A path found:\n");
				for (auto& p : path)
					std::printf("%d -> ", p.first->value);
				cout << "null" << endl;
				cur_sum -= cur.first->value;
				path.pop_back();
			}
			else {
				cur_sum -= cur.first->value;
				path.pop_back();
			}
			continue;
		}
		if (cur.first->left && !cur.second[LEFT]) {
			path.back().second[LEFT] = true;  // ������cur.second[LEFT]=true, curֻ��һ�����������Ĳ�����Ч
			path.push_back({ cur.first->left ,{ false,false } });  // ������back()�ķ��ʱ�־����push_back�µ�ֵ
			cur_sum += cur.first->left->value;
		}
		else if (cur.first->right && !cur.second[RIGHT]) {
			path.back().second[RIGHT] = true;
			path.push_back({ cur.first->right,{ false,false } });
			cur_sum += cur.first->right->value;
		}
		else {
			path.pop_back();
			cur_sum -= cur.first->value;
		}
	}

}

int main() {
	vector<int> tree{ 10,5,12,4,7 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	FindPaths_NonRecur(root, 22);
	DestoryBTree(&root);
	return 0;
}