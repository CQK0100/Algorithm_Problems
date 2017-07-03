/*
Balanced Binary Tree (Adelson-Velskii-Landis Tree)
Based on the Binary Search Tree
*/
// http://blog.csdn.net/xiajun07061225/article/details/8292505
#include<iostream>
#include<memory>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;

template<class Type>
class TreeNode {
public:
	TreeNode():
		height(1),leftChild(nullptr),rightChild(nullptr){}
	Type data;
	size_t height;
	TreeNode* leftChild;
	TreeNode* rightChild;
};


template<class Type>
class AVLTree {
	using TNode = shared_ptr<TreeNode<Type>>;
	using TType = TreeNode<Type>;
public:
	AVLTree() :
		root(make_shared<TType>(new TType())) {}
	~AVLTree()=default;
	//��������ƽ����
	void createAVLTree(TNode node, const vector<Type>& data);
	//����ڵ�
	TNode insertNode(const Type& value);
	//ɾ���ض�ֵ�Ľڵ�
	TNode deleteNode(const Type& value);
	//�����ض�ֵ�Ľڵ㣬�����ظýڵ�
	TNode searchNode(const Type& value);
	//ǰ����������
	void preOrdered();
	//�������ֵ�Ľڵ�
	TNode maxNode();
	//������Сֵ�ڵ�
	TNode minNode();
private:
	TNode root;  //���ڵ�

	size_t getHeight();  //�������ĸ߶�
	void setHeight();  //�������ĸ߶�

	//��ת����
	//��������
	TNode singleRightRotate(TNode);
	//��������
	TNode singleLeftRotate(TNode);
	//˫����ת������
	TNode doubleRightRotate(TNode);
	//˫����ת������
	TNode doubleLeftRotate(TNode);

};


template<class Type>
TNode AVLTree<Type>::insertNode(TNode node, const Type& value) 
{
	auto newNode = make_shared<TType>(new TType());
	newNode->data = value;
	if (!node->get()) {
		node = newNode;
		return node;
	}
	//�����ֵ����ڵ��ֵһ��
	if (node->data == value)
	{
		cout << "AVL����������ͬ��Ԫ�ش��ڣ�����ڵ�ʧ�� ." << std::endl;
		return node;
	}

	//�����ֵС�ڽڵ��ֵ��������������
	if (value < node->data)
	{
		(*node)->leftChild = insertNode(*(node)->leftChild, value);
	}
}