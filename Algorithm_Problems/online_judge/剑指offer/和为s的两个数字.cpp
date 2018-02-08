/*
  ����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
  �������һ�Լ��ɡ�
*/
#include<vector>

using namespace std;

/*
  O(n^2)�ķ���̫���ˡ�
  �����ǵ�������ģ���ô�ֱ�������ָ�룬һ����ǰ����һ���Ӻ���ǰ�����ݵ�ǰ��
  �Ĵ�С��Ŀ��ͱȽϣ���̬����ָ��λ�þͿ����ˡ�
*/
bool FindSumPair(const vector<int>& nums, const int& sum, int& first, int& second) {
	if (nums.size() < 2)
		return false;
	int start = 0, last = nums.size() - 1;
	int cur_sum;
	while (start < last) {
		cur_sum = nums[start] + nums[last];
		if (cur_sum == sum) {
			first = nums[start];
			second = nums[last];
			return true;
		}
		else if (cur_sum < sum)
			++start;
		else
			--last;
	}
	return false;
}

int main() {
	vector<int> nums{ 1,2,4,7,11,15 };
	int fir, sec;
	if (FindSumPair(nums, 15, fir, sec)) {
		std::printf("%d + %d = 15\n", fir, sec);
	}
	else
		std::printf("Can't find 2 numbers whose sum is 15.");
	return 0;
}