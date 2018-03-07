/*
  1.�������ڵ����ֵ
  ����һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ��
  һ���������ڿ��Կ�����һ�����У����ڻ���ʱ�����ڴ��ڵĵ�һ�������ȱ�ɾ����ͬʱ��
  ���ڵ�ĩβ���һ���µ����֡��Ƚ��ȳ���
*/
#include<vector>
#include<deque>
#include<iostream>

using namespace std;

vector<int> MaxInWindows(const vector<int>& nums, int size) {
	vector<int> max_in_win;
	if (nums.size() > size&&size >= 1) {
		deque<int> index;  // ��������Ǵ������ֵ�����������±�
		for (int i = 0; i < size; ++i) {
			while (!index.empty() && nums[index.back()] < nums[i])
				index.pop_back();
			index.push_back(i);
		}
		for (int i = size; i < nums.size(); ++i) {
			max_in_win.push_back(index.front());  // ���ֵ��Զ�ڶ���ͷ
			while (!index.empty() && nums[index.back()] < nums[i])  // ���������������ֵ����
				index.pop_back();
			if (!index.empty() && index.front() + size <= i)
				index.pop_front();  // �������ں���
			index.push_back(i);
		}
		max_in_win.push_back(nums[index.front()]);
	}
	return std::move(max_in_win);
}