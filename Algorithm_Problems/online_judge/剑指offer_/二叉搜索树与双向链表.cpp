/*
  ����һ�ö��������������ö���������ת����һ�������˫������
  Ҫ���ܴ����κ��½ڵ�(�ռ临�Ӷ�ΪO(1))��ֻ�ܵ������нڵ�ָ���ָ��
*/
#include"predefines.h"

/*
  ����������ʵ���Ƕ��������������������������ͬʱҪ����ǰ���ͺ���
*/
void ConverNode(BinaryNode<int>* node, BinaryNode<int>** last) {
	if (!node)
		return;
	auto cur = node;
	if (cur->left)
		ConverNode(cur->left, last);
	cur->left = *(last);
	if (*last)
		(*last)->right = cur;
	(*last) = cur;
	if (cur->right)
		ConverNode(cur->right, last);
}

BinaryNode<int>* ConvertToDuLinkedList(BinaryNode<int>* root) {
	if (!root)
		return nullptr;
	BinaryNode<int>* last = nullptr;  // �����������null
	ConverNode(root, &last);
	auto head = last;
	while (head&&head->left)
		head = head->left;
	return head;
}

int main() {
	vector<int> tree{ 10,6,14,4,8,12,16 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root,tree);
	auto head = ConvertToDuLinkedList(root);
	while (head) {
		cout << head->value << "->";
		head = head->right;
	}
	cout << "null" << endl;
	auto copy = head;
	while (head) {
		head = head->left;
		delete copy; copy = nullptr;
		copy = head;
	}
	return 0;
}