/*
  ����һ���ַ�������ӡ�����ַ������ַ����������С�
  ��������abc�����ӡ��abc,acb,bca,bac....
*/
#include<string>
#include<algorithm>
#include<iostream>

using std::string;

void Permutation(string str, const int& index) {
	str = std::move(str);
	if (index == str.size())
		std::cout << str << std::endl;
	else {
		for (size_t i = index; i < str.size(); ++i) {
			auto tmp = str[index];
			std::swap(str[index], str[i]);
			Permutation(str, index + 1);
			std::swap(str[index], str[i]); // roll back to origin string
		}
	}
}

void Permutation(string str) {
	if (str.empty())
		return;
	Permutation(str, 0);
}

int main() {
	string s = "abcd";
	Permutation(s);
	return 0;
}