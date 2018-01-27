/*
  ����һ�����֣��������¹�������ַ�����
  0�����'a'��1�����'b'...25�����'z'��
  һ�����ֿ����ж����ַ��룿����12258���Է����:
  "bccfi","bwfi","bczi","mcfi","mzi"
*/
#include<string>
#include<vector>

using namespace std;

// �ݹ����϶��£������ظ�������
// �������ö�̬�滮����ĩβ��ʼ�����¶���
int GetTranslationCount(const int& num) {
	if (num < 0)
		return 0;
	string num_str = to_string(num);
	int size = num_str.size();
	vector<int> dp(size, 0);
	dp[size - 1] = 1;
	int count;
	for (int i = size - 2; i >= 0; --i) {
		count = dp[i + 1];
		int digit1 = num_str[i] - '0';
		int digit2 = num_str[i + 1] - '0';
		int converted = 10 * digit1 + digit2;
		if (converted >= 10 && converted <= 25)
			count += (i < size - 2) ? dp[i + 2] : 1;
		dp[i] = count;
	}
	return dp[0];
}

int main() {
	std::printf("%d\n", GetTranslationCount(12258));
	return 0;
}


