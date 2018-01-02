#pragma once
#ifndef OFFER_LIST_NODE_H
#define OFFER_LIST_NODE_H
#include<vector>
using std::vector;

struct ListNode
{
	int value;
	ListNode* next;

	ListNode()
		:next(nullptr) {}

	ListNode(const int& val)
		:value(val), next(nullptr) {}
};

void BuildLinkedList(ListNode** head, const vector<int>& arr) {
	if (head == nullptr || *head == nullptr||arr.empty())
		return;
	for (const int& i : arr) {
		(*head)->next = new ListNode(i);
		head = &(*head)->next;
	}
}

void PrintLinkedList(ListNode* head) {
	if (!head)
		return;
	while (head->next) {
		head = head->next;
		std::printf("%d ", head->value);
	}
}

void DestoryLinkedList(ListNode* head) {
	if (!head||!head->next)
		return;
	ListNode* cur = head;
	ListNode* next = head->next;
	while (next) {
		delete cur; cur = nullptr;
		cur = next;
		next = next->next;
	}
}

#endif // !OFFER_LIST_NODE_H
