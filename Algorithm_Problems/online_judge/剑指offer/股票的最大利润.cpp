/*
  �����ĳ��Ʊ�ļ۸�ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ��������
  �Ƕ��٣�
  �����������������Ԫ�ص�����ֵ��
*/
#include<vector>

using namespace std;

int MaxProfit(const vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	int min = nums[0];
	int max_profit = nums[1] - min;
	for (int i = 2; i < nums.size(); ++i) {
		min = (nums[i - 1] < min) ? (nums[i - 1]) : min;
		max_profit = (nums[i] - min) > max_profit ? (nums[i] - min) : max_profit;
	}
	return max_profit;
}

int main() {
	vector<int> nums{ 9,11,8,5,7,12,16,14 };
	std::printf("%d\n", MaxProfit(nums));
	return 0;
}