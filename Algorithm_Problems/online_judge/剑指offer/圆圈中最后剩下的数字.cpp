/*
  0,1,2...n-1��n�������ų�һȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�
  ������ԲȦ���ʣ�µ����֡�
*/
#include<list>
// list��һ����������listģ��ѭ������������ĩβʱ������λ

using namespace std;

int LastRemaining(const int& n, const int& m) {
	if (n < 1 || m < 1)
		return -1;
	list<int> nums;
	for (int i = 0; i < n; ++i)
		nums.push_back(i);
	auto current = nums.begin();
	while (nums.size() > 1) {
		for (int i = 1; i < m; ++i) {  // ��m������,����ǰ��m-1�����ڵ�����
			++current;
			if (current == nums.end())
				current = nums.begin();
		}
		auto next = ++current;
		if (next == nums.end())
			next = nums.begin();
		--current;
		nums.erase(current);  // listִ��erase��������������ʧЧ
		current = next;
	}
	return (*current);
}

int main() {
	std::printf("%d\n", LastRemaining(5, 3));
	return 0;
}