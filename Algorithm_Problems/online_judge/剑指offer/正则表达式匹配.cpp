/*
 ʵ��һ��������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����
 '*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
 ����"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"��ƥ�䡣
 */

#include<string>
#include<iostream>
#include<vector>

using namespace std;

/*
 ���ݹ�汾������ƥ��ģʽ�ǷǷǳ���ʱ
*/
bool IsMatch(const string& str, const string& pattern) {
	if (pattern.empty())
		return str.empty();
	if (pattern[1] == '*') {
		if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty()))
			return IsMatch(str.substr(1), pattern.substr(2)) ||
			IsMatch(str.substr(1), pattern) ||
			IsMatch(str, pattern.substr(2));
		else
			return IsMatch(str, pattern.substr(2));
	}
	if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty()))
		return IsMatch(str.substr(1), pattern.substr(1));
	return false;
}

/*
 ��̬�滮�汾���ռ任ʱ��
 https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations
 �����������
 dp[i][j] = true����str[0...i]��pattern[0...j]�ɹ�ƥ��
 P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
 P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
 P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
*/

bool IsMatchDp(const string& str, const string& pattern) {
	int ssize = str.size(), psize = pattern.size();
	vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= ssize; ++i)
		for (int j = 1; j <= psize; ++j) {
			if (pattern[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (i > 0 && str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j];
			else
				dp[i][j] = i > 0 && dp[i - 1][j - 1] &&  (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
		}
	return dp[ssize][psize];
}



int main() {
	string str = "aaaaaaaaaaaaab";
	string pattern = "a*a*a*a*a*a*a*a*a*a*c";
	cout << IsMatchDp(str, pattern) << endl;
	return 0;
}