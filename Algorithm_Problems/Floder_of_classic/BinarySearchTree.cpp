
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
typedef int ElemType;
//�������ڵ�
class BTNode   //Binary Tree Node
{
public:
	ElemType data;
	BTNode* lchild;   //����
	BTNode* rchild;   //�Һ���
	BTNode(ElemType d, BTNode* left = nullptr, BTNode* right = nullptr)
		:data(d), lchild(left), rchild(right) {}
};
//����������
class BinarySearchTree
{
private:
	//����
	BTNode* Root;
	//�ڵ�����
	size_t size;
public:
	//���췽��
	BinarySearchTree();
	//�������캯��
	BinarySearchTree(const BinarySearchTree& T);
	//��ֵ���캯��
	BinarySearchTree& operator=(const BinarySearchTree& T);
	//��������
	~BinarySearchTree();
	//�ж�����
	bool empty()
	{
		return Root == nullptr;
	}
	//��ڵ�����
	size_t getSize()
	{
		return size;
	}
	//��Ҷ�ӽڵ���
	int leaf();
	//����
	bool search(ElemType);
	//��ȡ���ڵ�
	BTNode* parent(ElemType);
	//��ȡǰ��
	BTNode* predecessor(ElemType);
	//��ȡ���
	BTNode* successor(ElemType);
	//��ȡ��С�ڵ�
	BTNode* minimum();
	//��ȡ���ڵ�
	BTNode* maximum();
	//�����½ڵ�
	bool insertNode(ElemType);
	//ɾ���ڵ�
	bool deleteNode(ElemType);
	//�������
	void traverse()
	{
		inOrderWithoutRecursion();
	}
	void inOrderWithoutRecursion();
};
//���췽��
BinarySearchTree::BinarySearchTree()
{
	size = 0;
	Root = nullptr;
	ElemType data;
	cout << " Build the Binary Search Tree and input the nodes (int type)��\n"
		<< " End up inputting with \'Ctrl\' + \'z\'  " << endl;
	while (cin >> data)
		insertNode(data);
}
//�������캯��
BinarySearchTree::BinarySearchTree(const BinarySearchTree& T) {
	BTNode* Root = new BTNode(T.Root->data);
	Root = T.Root;
	size = T.size;
}
//��ֵ���캯��
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& T) {
	BTNode* Root = new BTNode(T.Root->data);
	Root = T.Root;
	size = T.size;
	return *this;
}
//��������
BinarySearchTree::~BinarySearchTree()
{
	if (!empty())
	{
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = nullptr;
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			//���Ӳ�Ϊ�գ����������
			if (p->lchild)
				q.push(p->lchild);
			//�Һ��Ӳ�Ϊ�գ����Һ������
			if (p->rchild)
				q.push(p->rchild);
			//�ͷ��ڴ�
			delete p;
		}
	}
}
//��Ҷ�ӽڵ���
int BinarySearchTree::leaf()
{
	int num = 0;
	//���������
	if (!empty())
	{
		stack<BTNode*> s;
		BTNode* p = Root;
		while (!s.empty() || p)
		{
			if (p)
			{
				s.push(p);
				p = p->lchild;
			}
			else
			{
				p = s.top();
				s.pop();
				//����������Ϊ�գ���ΪҶ�ӽڵ�
				if (p->lchild == nullptr && p->rchild == nullptr)
					num++;
				p = p->rchild;
			}
		}
	}
	return num;
}
//����
bool BinarySearchTree::search(ElemType data)
{
	if (!empty())
	{
		BTNode* p = Root;
		while (p)
		{
			if (data == p->data)
				return true;
			else if (data < p->data)
				p = p->lchild;
			else
				p = p->rchild;
		}
	}
	//���ջ����ʧ��
	return false;
}
BTNode* BinarySearchTree::parent(ElemType data)
{
	if (!empty())
	{
		//���ڵ�ĸ��ڵ�Ϊ��
		if (Root->data == data)
			return nullptr;
		stack<BTNode*> s;
		BTNode* p = Root;
		while (!s.empty() || p)
		{
			if (p)
			{
				if ((p->lchild && p->lchild->data == data) || (p->rchild && p->rchild->data == data))
					return p;
				s.push(p);
				p = p->lchild;
			}
			else
			{//������������󣬷���������
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
	return nullptr;
}
//��ȡǰ��
BTNode* BinarySearchTree::predecessor(ElemType data)
{
	BTNode* pcur, *plastVisit;
	pcur = plastVisit = nullptr;
	if (!empty())
	{
		stack<BTNode*> s;
		pcur = Root;
		while (!s.empty() || pcur)
		{
			if (pcur)
			{
				//plastVisit = pcur;
				s.push(pcur);
				pcur = pcur->lchild;
			}
			else
			{
				pcur = s.top();
				s.pop();
				if (pcur->data == data)
					return plastVisit;
				else
					plastVisit = pcur;
				pcur = pcur->rchild;
			}
		}
	}
	return plastVisit;
}
//��ȡ���
BTNode* BinarySearchTree::successor(ElemType data)
{
	BTNode* pcur = nullptr;
	pcur = Root;
	if (!empty())
	{
		stack<BTNode*> s;
		while (!s.empty() || pcur)
		{
			if (pcur)
			{
				s.push(pcur);
				pcur = pcur->lchild;
			}
			else
			{
				pcur = s.top();
				s.pop();
				if (pcur->data == data)
					return pcur->rchild;
				pcur = pcur->rchild;
			}
		}
	}
	//����
	return nullptr;
}
//��ȡ��С�ڵ�
BTNode* BinarySearchTree::minimum()
{
	//��С�ڵ������������±�
	if (!empty())
	{
		BTNode* p = Root;
		while (p->lchild)
			p = p->lchild;
		return p;
	}
	//����
	return nullptr;
}
//��ȡ���ڵ�
BTNode* BinarySearchTree::maximum()
{
	//���ڵ������������±�
	if (!empty())
	{
		BTNode* p = Root;
		while (p->rchild)
			p = p->rchild;
		return p;
	}
	//����
	return nullptr;
}
//�����½ڵ�
bool BinarySearchTree::insertNode(ElemType data)
{
	/*
	�½ڵ㶼�ᱻ���뵽Ҷ�Ӵ�
	����һ�㲻��ʧ�ܣ������ǲ������ظ��ڵ㡣
	*/
	if (Root == nullptr)
	{
		Root = new BTNode(data);
		size++;
		return true;
	}
	else
	{
		BTNode* p = Root;
		while (true)
		{
			if (data < p->data)
			{
				//����������������������������
				if (p->lchild)
					p = p->lchild;
				else
				{//���򣬲���ڵ㣬��ͬ
					p->lchild = new BTNode(data);
					break;
				}
			}
			else if (data > p->data)
			{
				if (p->rchild)
					p = p->rchild;
				else
				{
					p->rchild = new BTNode(data);
					break;
				}
			}
			else//�����ظ��ڵ�
				return false;
		}
		//�����½ڵ�ɹ����ڵ�������һ
		size++;
		return true;
	}
}
//ɾ���ڵ�
bool BinarySearchTree::deleteNode(ElemType data)
{
	/*
	ɾ������
	1.����ɾ�ڵ������������������������ĸ��ڵ��滻����
	2.����ɾ�ڵ�����������������������Ѱ��������������һ���ڵ㣬�øýڵ��滻����
	*/
	if (!empty())
	{
		//�����޴˽ڵ㣬ɾ��ʧ��
		if (!search(data))
			return false;
		/*
		p:��ɾ���
		Parent:��ɾ���ڵ�ĸ��ڵ�
		temp:�滻�ڵ�
		tempp:�滻�ڵ�ĸ��ڵ�
		*/
		BTNode* p, *Parent, *temp, *tempp;
		p = Parent = temp = tempp = nullptr;
		//��ȡ��ɾ���ڵ�ĸ��ڵ�
		Parent = parent(data);
		//���ݸ��ڵ㣬ȷ����ɾ���
		if (Parent->lchild && Parent->lchild->data == data)
			p = Parent->lchild;
		else
			p = Parent->rchild;
		//�����������Ϊ�գ�������������������һ���ڵ�
		if (p->lchild)
		{
			temp = p->lchild;
			while (temp->rchild)
			{
				tempp = temp;
				//���ϱ���������
				temp = temp->rchild;
			}
			//���p�����Ӽ����滻�ڵ�
			if (tempp == nullptr)
				p->lchild = temp->lchild;
			else//�滻�ڵ����������Ϊ�丸�ڵ��������(���������⣬��Ҫ������)
				tempp->rchild = temp->lchild;
			//�滻�ڵ�̳д�ɾ�������Һ���
			temp->lchild = p->lchild;
			temp->rchild = p->rchild;
		}
		else
			temp = p->rchild;
		//�滻�ڵ��滻����ɾ���(��Ҳ��Ϊʲô��Ҫ�ҵ���ɾ���ĸ��ڵ�)
		if (Parent == nullptr)  //��ɾ���ǡΪ���ڵ�
			Root = temp;
		else if (Parent->lchild == p)  //��ɾ��㱾����������
			Parent->lchild = temp;
		else//��ɾ��㱾����������
			Parent->rchild = temp;
		//ɾ����ɾ���
		delete p;
		//�ڵ�������һ
		size--;
		return true;
	}
	//����
	return false;
}
//�������
void BinarySearchTree::inOrderWithoutRecursion()
{
	if (!empty())
	{
		stack<BTNode*> s;
		BTNode* p = Root;
		while (!s.empty() || p)
		{
			if (p)
			{
				s.push(p);
				p = p->lchild;
			}
			else
			{
				p = s.top();
				s.pop();
				cout << setw(4) << p->data;
				p = p->rchild;
			}
		}
		cout << endl;
	}
}
int main()
{
	cout << "******����������*******" << endl;
	BinarySearchTree tree;
	cout << "�������" << endl;
	tree.traverse();
	cout << "���нڵ����� " << tree.getSize() << endl;
	cout << "Ҷ�ӽڵ��� " << tree.leaf() << endl;
	BTNode* p = nullptr;
	p = tree.minimum();
	p ? cout << "��С�ڵ��� " << p->data << endl : cout << "���գ�" << endl;
	p = tree.maximum();
	p ? cout << "���ڵ��� " << p->data << endl : cout << "���գ�" << endl;
	ElemType data = 2;
	cout << endl << "���ҽڵ� " << data << endl;
	if (tree.search(data))
	{
		cout << "�ڵ� " << data << " ���ҳɹ���" << endl;
		p = tree.predecessor(data);
		p ? cout << "�ڵ� " << data << " ��ǰ���� " << p->data << endl : cout << "��ǰ����" << endl;
		p = tree.successor(data);
		p ? cout << "�ڵ� " << data << " �ĺ���� " << p->data << endl : cout << "�޺�̣�" << endl;
	}
	else
		cout << "�ڵ� " << data << "�������У�" << endl;
	data = 6;
	cout << endl << "ɾ���ڵ� " << data << endl;
	if (tree.deleteNode(data))
	{
		cout << "ɾ���ɹ���" << endl;
		cout << "�������" << endl;
		tree.traverse();
		cout << "���нڵ����� " << tree.getSize() << endl;
		cout << "Ҷ�ӽڵ��� " << tree.leaf() << endl;
		data = 5;
		cout << endl << "���ҽڵ� " << data << endl;
		if (tree.search(data))
		{
			cout << "�ڵ� " << data << " ���ҳɹ���" << endl;
			p = tree.predecessor(data);
			p ? cout << "�ڵ� " << data << " ��ǰ���� " << p->data << endl : cout << "��ǰ����" << endl;
			p = tree.successor(data);
			p ? cout << "�ڵ� " << data << " �ĺ���� " << p->data << endl : cout << "�޺�̣�" << endl;
		}
		else
			cout << "�ڵ� " << data << "�������У�" << endl;
	}
	else
		cout << "ɾ��ʧ�ܣ�" << endl;
	cout << endl;
	system("pause");
	return 0;
}

