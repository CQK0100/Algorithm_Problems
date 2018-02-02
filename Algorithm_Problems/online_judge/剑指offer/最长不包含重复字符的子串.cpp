/*
  ����ַ������ҳ�һ����Ĳ������ظ��ַ����Ӵ���������ַ����ĳ��ȣ�
  ������ַ�����ֻ����'a'~'z'���ַ���
*/
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int LongestNonrepeatingSubstring(const string& str) {
	int size = str.size();
	vector<int> dp(size, 0);
	dp[0] = 1;
	vector<int> map(26, -1); // ��¼��Ӧ�ַ��ϴγ��ֵ�λ��
	int max_len = 0;
	map[str[0] - 'a'] = 0;
	for (int i = 1; i < size; ++i) {
		int pre = map[str[i] - 'a'];
		if (pre<0 || (i - pre)>dp[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			max_len = std::max(max_len, dp[i - 1]);
			dp[i] = i - pre;
		}
		map[str[i] - 'a'] = i;
	}
	max_len = std::max(max_len, dp[size - 1]);
	return max_len;
}

int main() {
	string s = "arabcacfr";
	std::printf("%d\n", LongestNonrepeatingSubstring(s));
	return 0;
}