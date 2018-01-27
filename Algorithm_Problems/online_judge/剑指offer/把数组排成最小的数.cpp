/*
  ����һ�����������飬����������������ƴ�������ų�һ������
  ��ӡ����ƴ�ӳ���������������С��һ����
*/
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

std::string GetMinNumber(const std::vector<int>& arr) {
	if (arr.empty())
		return "";
	std::vector<std::string> num_strs;
	for (const int& i : arr)  // �Ƚ���������ת��Ϊ�ַ�����ʾ
		num_strs.push_back(std::to_string(i));
	std::sort(num_strs.begin(), num_strs.end(), [](const std::string& lhs, const std::string& rhs) {
		// �����ַ�����ӣ�λ��һ����ͬ��ֱ��Ӧ���ַ����ıȽϹ���
		return (lhs + rhs) < (rhs + lhs);  
	});
	std::string ans;
	for (const std::string& str : num_strs)
		ans.append(str);
	return ans;
}

int main() {
	std::vector<int> sample{ 3,32,321,1 };
	std::cout << GetMinNumber(sample) << std::endl;
	return 0;
}
