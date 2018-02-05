/*
  ���������������г��ֵĴ�����(ͳ��һ�����������������г��ֵĴ�����)
*/
#include<vector>

using namespace std;

/*
  ���ֶ�λ����k��Ȼ��˳��������ܱߵ�k�ĸ������ڼ�������»��ǻ��˻���˳����ң�
  ���Կ���ͬʱ���ζ��֣�ֱ�Ӷ�λ��һ��k�����һ��k���±�������Ǹ�����
*/

int GetNumberOfK(const vector<int>& nums, const int& k) {
	if (nums.empty())
		return 0;
	int first_mid = nums.size() / 2;
	int first_start = 0, first_end = nums.size() - 1;
	while (first_start < first_end) {
		if (nums[first_mid] == k) {
			if (first_mid > 0 && nums[first_mid - 1] != k || first_mid == 0)  // ����һ��k
				break;
			else
				first_end = first_mid - 1;
		}
		else if (nums[first_mid] > k)
			first_end = first_mid;
		else
			first_start = first_mid + 1;
		first_mid = (first_start + first_end) / 2;
	}
	int last_start = first_mid, last_end = nums.size() - 1;
	int last_mid = nums.size() / 2;
	while (last_start < last_end) {
		if (nums[last_mid] == k) {
			if (last_mid < nums.size() - 1 && nums[last_mid + 1] != k || last_mid == nums.size() - 1)  // �����һ��k
				break;
			else
				last_start = last_mid + 1;
		}
		else if (nums[last_mid] > k)
			last_end = last_mid;
		else
			last_start = last_mid + 1;
		last_mid = (last_start + last_end) / 2;
	}
	return last_mid - first_mid + 1;
}

int main() {
	vector<int> nums{ 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,7,7,8,9,9 };
	std::printf("%d\n", GetNumberOfK(nums, 5));
	return 0;
}