/*
  ����һ���������飬������������Ҳ�и����������е�һ�����������
  �������һ�������飬������������ĺ͵����ֵ��
*/
#include<vector>
#include<algorithm>

using namespace std;

int FindGreatestSum(const vector<int>& nums) {
	if (nums.empty())
		std::exception("Empty array passed in");
	int cursum = 0, maxsum = nums[0];
	for (const int& i : nums) {
		if (cursum <= 0)  // cursum<=0,i��������i>cursum��i�Ǹ�����cursum+i<cursum�����¼�sum
			cursum = i;
		else
			cursum += i;
		maxsum = std::max(maxsum, cursum);
	}
	return maxsum;
}

int FindGreatestSum_Dp(const vector<int>& nums) {
	if (nums.empty())
		std::exception("Empty array passed in");
	// ��ʵ˼·���Ϸǳ�����
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	int max = dp[0];
	for (int i = 1; i < nums.size(); ++i) {
		if (dp[i - 1] <= 0)
			dp[i] = nums[i];
		else
			dp[i] = dp[i - 1] + nums[i];
		max = std::max(max, dp[i]);
	}
	return max;
}

int main() {
	vector<int> nums{ 1,-2,3,10,-4,7,2,-5 };
	std::printf("%d\n", FindGreatestSum_Dp(nums));
	return 0;
}