/*
 ���һ�������а�����������ҳ�������ڽڵ㣿
*/
#include"predefines.h"

// �ҵ������������Ľ��
ListNode* MeetingNode(ListNode* head) {
	if (!head || !head->next)
		return nullptr;
	ListNode* pslow = head->next;
	ListNode* pfast = pslow->next;
	while (pslow&&pfast) {
		if (pfast == pslow)
			return pfast;
		pslow = pslow->next;
		if (pfast->next)
			pfast = pfast->next;
	}
	return nullptr;  // ������û�л�
}

// �ó����нڵ�ĸ����������ҵ����
ListNode* EntryOfLoop(ListNode* head) {
	auto meet = MeetingNode(head);
	if (!meet)
		return nullptr;
	size_t count = 1;
	auto start = meet;
	while (start->next != meet) {
		++count;
		start = start->next;
	}
	/*
	  ��ͷ��㿪ʼwalk,��һ���������count��,
	  ֮�������ڵ�ͬ���ߣ������㼴�������
	*/
	ListNode* fast = head;
	for (size_t i = 0; i < count; ++i)
		fast = fast->next;
	ListNode* slow = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
