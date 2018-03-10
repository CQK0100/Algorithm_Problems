/*
  ���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
  2~10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13����С��Ϊ�������֣���С����ʾΪ0����
*/
#include<vector>
#include<algorithm>

using namespace std;

bool IsContinuous(const vector<int>& nums) {
	if (nums.empty())
		return false;
	std::sort(nums.begin(), nums.end());
	int zero_num = 0, gap_num = 0;
	for (const int& num : nums)  // ͳ��������0�ĸ���
		if (num == 0)
			++zero_num;
	int small = zero_num;
	int big = small + 1;
	while (big < nums.size()) {
		if (nums[small] == nums[big]) // �ж���
			return false;
		gap_num += nums[big] - nums[small] - 1;  // ��������Ŀ
		small = big++;
	}
	return gap_num <= zero_num;
}