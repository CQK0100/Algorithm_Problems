/*
  ����n�������ҳ�������С��k����
*/
#include<vector>
#include<random>
#include<queue>

using namespace std;


int Partition(vector<int>& nums, const int& start, const int& end) {
	if (nums.empty() || start < 0 || end >= nums.size())
		throw std::exception("Invalid parameters passed in.");
	std::swap(nums[(start + end) / 2], nums[end]);  // ��pivot��nums[mid]���û������
	int pos = start - 1;
	for (int i = start; i < end; ++i) {
		if (nums[i] < nums[end]) {
			++pos;
			if (pos != i)
				std::swap(nums[pos], nums[i]);
		}
	}
	++pos;
	std::swap(nums[pos], nums[end]);
	return pos;
}

vector<int> GetKMinNumbers(vector<int> nums, const int& k) {
	nums = std::move(nums);
	if (nums.size() <= k)
		return nums;
	int start = 0, end = nums.size() - 1;
	int index = Partition(nums, start, end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = Partition(nums, start, end);
		}
		else {
			start = index + 1;
			index = Partition(nums, start, end);
		}
	}
	return vector<int>(nums.begin(), nums.begin() + k);
}

// priority_queue �ĵײ�������
// ���Կ�����priority queue��ά��
vector<int> GetKMinNumbers_MaxHeap(const vector<int>& nums, const int& k) {
	if (nums.size() <= k)
		return nums;
	std::priority_queue<int> heap;
	for (auto start = nums.cbegin(); start != nums.cend(); ++start) {
		if (heap.size() < k)
			heap.push(*start);
		else {
			// �ҵ���һ����*start�������ɾ��֮
			if ((*start) < heap.top()) {
				heap.pop();
				heap.push(*start);
			}
		}
	}
	vector<int> ans;
	while (!heap.empty()) {
		ans.push_back(heap.top());
		heap.pop();
	}
	return std::move(ans);
}

int main() {
	vector<int> nums = { 4,5,1,6,2,7,3,8 };
	auto ans = GetKMinNumbers_MaxHeap(nums, 3);
	for (auto&& i : ans)
		std::printf("%d\n", i);
	return 0;
}