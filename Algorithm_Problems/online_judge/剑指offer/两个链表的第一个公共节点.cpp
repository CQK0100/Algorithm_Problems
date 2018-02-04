/*
  �������������ҳ����ǵĵ�һ�������ڵ㡣
*/

/*
  ��ǰ�����������Ѷȵģ����Ի���˼·���Ӻ���ǰ�ң�ֱ����һ���ֲ�Ľ�㡣
  1.������2��ջ������������������нڵ㣬Ȼ���ջ����ʼ�Ƚϡ�
  ��Ȼ�й����ڵ㣬��ô�����ڵ㵽���һ���ڵ㶼����ͬ�ģ��ռ任ʱ�䡣
  2.�ȱ���һ��õ����������ȣ�Ȼ�󳤵��������ɲ���Ȼ��һ���������ͬ��walk
  ֱ���ҵ���һ�������㡣
*/
#include<iostream>
#include<stack>
#include"predefines.h"

using namespace std;

// �ⷨһ
ListNode* FirstPublicNode_solu_one(ListNode* first, ListNode* second) {
	if (!first || !second)
		return nullptr;
	stack<ListNode*> first_stk, second_stk;
	while (first->next) {
		first = first->next;
		first_stk.push(first);
	}
	while (second->next) {
		second = second->next;
		second_stk.push(second);
	}
	ListNode* last_public = nullptr;
	while (!first_stk.empty() && !second_stk.empty() && (first_stk.top() == second_stk.top())) {
		last_public = first_stk.top();
		first_stk.pop(); second_stk.pop();
	}
	return last_public;
}

// �ⷨ��
ListNode* FirstPublicNode_solu_two(ListNode* first, ListNode* second) {
	if (!first || !second)
		return nullptr;
	ListNode *first_copy = first, *second_copy = second;
	int first_len = GetLinkedListLength(first);
	int second_len = GetLinkedListLength(second);
	if (first_len > second_len) {
		int space = first_len - second_len;
		while (space-- > 0)
			first_copy = first_copy->next;
	}
	else {
		int space = second_len - first_len;
		while (space-- > 0)
			second_copy = second_copy->next;
	}
	while (first_copy != second_copy) {
		first_copy = first_copy->next;
		second_copy = second_copy->next;
	}
	return first_copy;
}

int main() {
	vector<int> sample1{ 1,2,3 }, sample2{ 4,5 };
	ListNode* head = new ListNode, *head2 = new ListNode;
	BuildLinkedList(&head, sample1);
	BuildLinkedList(&head2, sample2);
	ListNode* node = new ListNode(6);
	node->next = new ListNode(7);
	head->next->next->next->next = node;
	head2->next->next->next = node;
	auto ans = FirstPublicNode_solu_one(head, head2);
	std::printf("%d\n", ans->value);
	ans = FirstPublicNode_solu_one(head, head2);
	std::printf("%d\n", ans->value);
	return 0;
}
