/*
  �ַ����е�һ��ֻ����һ�ε��ַ���
*/

/*
  ASIIC�ַ���ֻ��256���ַ������Կ���ֱ�ӿռ任ʱ�䣬ά��һ���򵥵�hash table
  �������ַ����ֵĴ�����
*/
#include<string>
#include<vector>

using namespace std;

char FirstNonRepeating(const string& str) {
	constexpr int table_size = 256;
	vector<int> hash(table_size, 0);
	for (const char& ch : str)
		hash[ch]++;
	for (const char& ch : str)
		if (hash[ch] == 1)
			return ch;
	return '\0';
}

int main() {
	string s = "abaccdeff";
	std::printf("%c\n", FirstNonRepeating(s));
	return 0;
}