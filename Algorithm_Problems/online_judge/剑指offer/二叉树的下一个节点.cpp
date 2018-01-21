/*
����һ��������������һ���ڵ㣬����ҳ�����������е���һ���ڵ㣿
���Ľڵ�����������ֱ�ָ�������ӽڵ��ָ�룬����һ��ָ�򸸽ڵ��ָ�롣
*/

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left, *right, *parent;
	BinaryTreeNode(const int& val)
		:value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

BinaryTreeNode* GetNextNode(BinaryTreeNode* node) {
	if (!node)
		return nullptr;
	BinaryTreeNode* pnext = nullptr;
	if (node->right) {
		BinaryTreeNode* pright = node->right;
		while (pright->left)
			pright = pright->left;
		pnext = pright;
	}
	else if (node->parent) {
		BinaryTreeNode* cur = node;
		BinaryTreeNode* parent = node->parent;
		while (parent&&cur == parent->right) {
			cur = parent;
			parent = parent->parent;
		}
		pnext = parent;
	}
	return pnext;
}