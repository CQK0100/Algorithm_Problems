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

// �ǵݹ�ⷨ��(����С�ַ�����ʼ)
// �Ӻ���ǰ�ң�ֱ���ҵ���һ�Ե�������AB,Ȼ����A����ı�A������е���С��������λ��
// �������ԭ��Aλ�ú�����ַ�����ת

void Permutation_NonRecur(string str) {
	str = std::move(str);
	std::sort(str.begin(), str.end()); // ȷ������С�ַ���
	std::cout << str << std::endl;
	int end = str.size() - 1;
	int pos = end; // ��Ҫ�����ĵ�
	int next, min; // ���������һ�㣬������֮����������С��
	while (pos > 0) {
		next = pos;
		--pos;
		if (str[pos] < str[next]) {
			// �ҵ�pos֮�����������е��е���С��
			// �Ӻ���ǰ�ҵ�һ����str[pos]�������������Ҫ�ҵ���
			min = end;
			while (str[min] <= str[pos])
				--min;
			std::swap(str[pos], str[min]);
			std::reverse(str.begin() + next, str.end());
			std::cout << str << std::endl;
			pos = end;  //�ص����
		}
	}
}

int main() {
	string s = "cba";
	Permutation_NonRecur(s);
	return 0;
}