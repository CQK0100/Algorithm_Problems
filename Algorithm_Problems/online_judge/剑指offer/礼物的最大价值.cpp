/*
  ��һ��m*n��������ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ(��ֵ����0)
  ���Դ����̵����Ͻǿ�ʼ�ø�����������ÿ��������������ƶ�һ����ֱ���������̵�
  ���½ǡ�����һ�����̣������������õ����ټ�ֵ�����
 */

 // ���͵Ķ�̬�滮˼·
 // f(i,j)��������gifts[i][j]ʱ������ֵ����ô��
 // f(i,j)=max(f[i-1][j],f[i][j-1])+gifts[i][j]
#include<algorithm>
#include<vector>

using namespace std;

// �ռ临�Ӷ�ΪO(n^2)
int GetMaxGiftsValue(const vector<vector<int>>& gifts) {
	if (gifts.empty() || gifts[0].empty())  // ����gifts��֤��һ��Matrix
		return 0;
	int rows = gifts.size(), cols = gifts[0].size();
	vector<vector<int>> dp(rows, vector<int>(rows, 0));
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			int left = 0, up = 0;
			if (i > 0)
				left = dp[i - 1][j];
			if (j > 0)
				up = dp[i][j - 1];
			dp[i][j] = std::max(left, up) + gifts[i][j];
		}
	return dp[rows - 1][cols - 1];
}

// �Ż���ÿ����dp[i,j]��ʵ��ֻ�õ���dp[i-1,j]��dp[i,j-1]
// ��ô�ռ临�Ӷȿ��Խ�ΪO(n)
// ����f(i,j): ǰj������dp[0...j-1]�ֱ�Ϊf(i,0),f(i,1)...f(i,j-1),
// ��j��������������һ�ֵľ�ֵ����f(i-1,j),f(i-1,j+1)...f(i-1,n-1).
int GetMaxGiftsValue_Optimized(const vector<vector<int>>& gifts) {
	if (gifts.empty() || gifts[0].empty())  // ����gifts��֤��һ��Matrix
		return 0;
	int rows = gifts.size(), cols = gifts[0].size();
	vector<int> dp(cols, 0); 
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			int left = 0, up = 0;
			if (i > 0)
				left = dp[j];
			if (j > 0)
				up = dp[j - 1];
			dp[j] = std::max(left, up) + gifts[i][j];
		}
	return dp[cols - 1];
}

int main() {
	vector<vector<int>> gifts{
		{1,10,3,8},
		{12,2,9,8},
		{5,7,4,11},
		{3,7,16,5}
	};
	std::printf("%d\n", GetMaxGiftsValue(gifts));
	std::printf("%d\n", GetMaxGiftsValue_Optimized(gifts));
	return 0;
}