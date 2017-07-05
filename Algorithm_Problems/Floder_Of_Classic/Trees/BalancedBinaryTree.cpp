/*
Balanced Binary Tree (Adelson-Velskii-Landis Tree)
Based on the Binary Search Tree
*/
// http://blog.csdn.net/xiajun07061225/article/details/8292505
// http://blog.csdn.net/niteip/article/details/11840691/
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::max;
using std::min;

template<typename Type>
class TreeNode {
public:
	TreeNode() :
		height(1), leftChild(make_shared<TreeNode>(nullptr)), 
		rightChild(make_shared<TreeNode>(nullptr)) {}
	Type data;
	size_t height;
	shared_ptr<TreeNode> leftChild;
	shared_ptr<TreeNode> rightChild;
};


template<typename Type>
class AVLTree {
	using TNode = shared_ptr<TreeNode<Type>>;
	using TType = TreeNode<Type>;
public:
	AVLTree() :
		root(make_shared<TType>(new TType())) {}
	~AVLTree() = default;
	//��������ƽ����
	void createAVLTree(TNode node, const vector<Type>& data);
	//����ڵ�
	TNode insertNode(TNode node, const Type& value);
	//ɾ���ض�ֵ�Ľڵ�
	TNode deleteNode(TNode node,const Type& value);
	//�����ض�ֵ�Ľڵ㣬�����ظýڵ�
	TNode searchNode(TNode node, const Type& value);
	//ǰ����������
	void preOrdered(TNode node);
	//�������ֵ�Ľڵ�
	TNode maxNode();
	//������Сֵ�ڵ�
	TNode minNode();
private:
	TNode root;  //���ڵ�

	size_t getHeight(TNode node);  //�������ĸ߶�
	void setHeight(TNode node,const size_t& newheight);  //�������ĸ߶�

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


template<typename Type>
size_t AVLTree<Type>::getHeight(TNode node)
{
	return (node.get() == nullptr) ? 0 : node->height;
}

template<typename Type>
inline void AVLTree<Type>::setHeight(TNode node, const size_t& newheight)
{
	node->height = newheight;
}

//���������ת����ƽ���Բ���
//����ƽ�⣬��-����ת : node - ʧȥƽ�����С�����ڵ�
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::singleRightRotate(TNode node)
{
	TNode xNode = node;
	TNode yNode = (*node)->leftChild;
	(*xNode)->leftChild = (*yNode)->rightChild;  //����ԭ�ڵ������
	(*yNode)->rightChild = xNode;	//����ԭ�ڵ����ӵ��Һ���
	//���¸߶�
	xNode->height = max(getHeight((*xNode)->leftChild), getHeight((*xNode)->rightChild)) + 1;
	yNode->height = max(getHeight((*yNode)->leftChild), getHeight((*yNode)->rightChild)) + 1;

	//ԭ�ڵ�����ӳ�Ϊ�������ĸ��ڵ�
	return yNode;
}

//���Ҳ�ƽ�⣬��-����ת
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::singleLeftRotate(TNode node)
{
	TNode xNode = node;
	TNode yNode = (*node)->rightChild;
	(*xNode)->rightChild = (*yNode)->leftChild;
	(*yNode)->leftChild = xNode;

	//���¸߶�
	xNode->height = max(getHeight((*xNode)->leftChild), getHeight((*xNode)->rightChild)) + 1;
	yNode->height = max(getHeight((*yNode)->leftChild), getHeight((*yNode)->rightChild)) + 1;

	//ԭ�ڵ�����ӳ�Ϊ�������ĸ��ڵ�
	return yNode;
}

//˫-����ת
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::doubleRightRotate(TNode node)
{
	//˫��ת����ͨ�����ε���תʵ��
	//�ȵ����ٵ���
	static_assert((*node)->leftChild.get() != nullptr, "Left Child should not be null pointer!");
	//������������һ�ε�-����ת
	(*node)->leftChild = singleLeftRotate((*node)->leftChild);
	//���²�����������һ�ε�-����ת
	return singleRightRotate(node);
}

//˫-����ת
template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::doubleLeftRotate(TNode node)
{
	//˫��ת����ͨ�����ε���תʵ��
	//�ȵ��ң��ٵ���
	static_assert((*node)->rightChild.get() != nullptr, "Right Child should not be null pointer!");
	//������������һ�ε�-����ת
	(*node)->rightChild = singleRightRotate((*node)->rightChild);
	//���²�����������һ�ε�-����ת
	return singleLeftRotate(node);
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::insertNode(TNode node, const Type& value)
{
	auto newNode = make_shared<TType>(new TType());
	newNode->data = value;
	if (!node.get()) {
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
		//�ж��Ƿ�ƽ��
		if (getHeight((*node)->leftChild) - getHeight((*node)->right) > 1)
		{
			//�����������ת
			//����������ӽڵ������������-����ת
			if (value < (*node)->leftChild->data)
				node = singleRightRotate(node);
			else
				//����������ӽڵ����������˫-����ת
				node = doubleRightRotate(node);
		}
	}
	//�����ֵ���ڽڵ��ֵ������������
	if (value > node->data)
	{
		(*node)->rightChild = insertNode((*node)->rightChild, value);
		//�ж��Ƿ�ƽ��
		if (getHeight((*node)->rightChild) - getHeight((*node)->leftChild > 1)
		{
			//ͬ���������
			//����������ӽڵ������������-����
			if (value > (*node)->rightChild->data)
				node = singleLeftRotate(node);
			else
				//����������ӽڵ����������˫-����
				node = doubleLeftRotate(node);
		}
	}
	//���½ڵ�ĸ߶�
	setHeight(node, max(getHeight((*node)->leftChild), getHeight((*node)->rightChild)) + 1);
	return node;
}

template<typename Type>
void AVLTree<Type>::createAVLTree(TNode node, const vector<Type>& data)
{
	if (node.get())
	{
		cout << "The AVL Tree has been created ." << std::endl;
		return;
	}
	if (!data.empty())
	{
		node.reset(nullptr);
		return;
	}
	for (auto i = data.cbegin(); i != data.cend(); ++i)
	{
		node = insertNode(node, *i);
	}

}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::searchNode(TNode node, const Type& value)
{
	if (!node.get())
	{
		return nullptr;
	}
	if (node->data == value)
	{
		return node;
	}
	else if (node->data < value)
	{
		return searchNode((*node)->leftChild, value);
	}
	else
	{
		return searchNode((*node)->rightChild, value);
	}
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::minNode()
{
	if (!root.get()) 
	{
		return nullptr;
	}
	TNode temp = root;
	while ((*temp)->leftChild)
	{
		temp = (*temp)->leftChild;
	}
	return temp;
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::maxNode()
{
	if (!root.get())
	{
		return nullptr;
	}
	TNode temp = root;
	while ((*temp)->rightChild)
	{
		temp = (*temp)->rightChild;
	}
	return temp;
}

template<typename Type>
void AVLTree<Type>::preOrdered(TNode node)
{
	if (!node.get())cout << "Empty Tree !" << std::endl;
	else
	{
		cout << node->data << " ";
		preOrdered((*node)->leftChild);
		preOrdered((*node)->rightChild);
	}
}

template<typename Type>
shared_ptr<TreeNode<Type>> AVLTree<Type>::deleteNode(TNode node, const Type& value)
{
	if (!node.get())
	{
		cout << "The Tree is empty...delete failed..." << std::endl;
		return node;
	}
	TNode searched = searchNode(node, value);
	//û���ҵ���Ӧ�ڵ㣬ɾ��ʧ��
	if (!searched.get())
	{
		cout << "Can not find the node to delete ." << std::endl;
		return node;
	}
	//�ҵ���Ҫɾ���Ľڵ�
	//����ǰ�������ڵ�
	if (node->data == value)
	{
		//���������Էǿ�
		if ((*node)->leftChild && (*node)->rightChild)
		{
			//�ڸ߶ȸ���������Ͻ���ɾ������
			if (getHeight((*node)->leftChild) > getHeight((*node)->rightChild))
			{
				//�������߶ȸ���ɾ����������Ԫ��ֵ���ĵ㣬ͬʱ������ֵ�������ڵ�
				node->data = maxNode((*node)->leftChild)->data;
				(*node)->leftChild = deleteNode((*node)->leftChild, node->data);
			}
			else
			{
				//ɾ����������ֵ��С�Ľڵ㣬ͬʱ������ֵ�������ڵ�
				node->data = minNode((*node)->rightChild)->data;
				(*node)->rightChild = deleteNode((*node)->rightChild, node->data);
			}
		}
		else
		{
			//������������һ����Ϊ�գ�ֱ�����ӽڵ��滻֮
			node = ((*node)->leftChild ? (*node)->leftChild : (*node)->rightChild);
		}
	}
	else if (value<node->data)	//Ҫɾ���Ľڵ���������
	{
		//���������еݹ�ɾ��
		(*node)->leftChild = deleteNode((*node)->leftChild, value);
		//�ж��Ƿ���Ȼ����ƽ������
		if (getHeight((*node)->rightChild) - getHeight((*node)->leftChild) > 1)
		{
			if (getHeight((*node)->rightChild->leftChild) - getHeight((*node)->rightChild->rightChild))
			{
				//˫-����ת
				node = doubleLeftRotate(node);
			}
			else
				node = singleLeftRotate(node);
		}
		else
		{
			//����ƽ������
			node->height = max(getHeight((*node)->leftChild), getHeight((*node)->rightChild)) + 1;
		}
	}
	else  //��Ҫɾ���Ľڵ���������
	{
		(*node)->rightChild = deleteNode((*node)->rightChild, value);
		//�ж��Ƿ���Ȼ����ƽ������
		if (getHeight((*node)->leftChild) - getHeight((*node)->rightChild) > 1)
		{
			if (getHeight((*node)->leftChild->rightChild) - getHeight((*node)->leftChild->leftChild))
			{
				//˫-����ת
				node = doubleRightRotate(node);
			}
			else
				node = singleRightRotate(node);
		}
		else
		{
			//����ƽ������
			node->height = max(getHeight((*node)->leftChild), getHeight((*node)->rightChild)) + 1;
		}
	}

	return node;
}
