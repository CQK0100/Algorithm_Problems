//[�����] ��ֵı��ʽ��ֵ
//����ı��ʽ��ֵ�����Ƕ�����ݼ�������ȼ������㡣����*, / �����ȼ��͸��� + -������С�������������ı��ʽ����ܼ򵥣������������μ��㼴�ɣ�����С�����ڵ�����û�г�������ζ�ű��ʽ��û�� / ��ֻ��(+, -�� *)�����ڸ���һ�����ʽ����Ҫ���æ�����С�����ڵ�����������ʽ��ֵΪ����
//�������� :
//����Ϊһ���ַ�������һ�����ʽ�����������ֻ�� - , +, *��������������ֻ��0~9.
//��֤���ʽ���ǺϷ��ģ����й�����������ʾ��
//
//
//������� :
//���һ�����������ʽ��ֵ
//
//�������� :
//3 + 5 * 7
//
//������� :
//	56

#include<iostream>
//#include<map>
#include<algorithm>
#include<string>
//#include<vector>
//#include<cmath>
//#include<set>

using namespace std;

int main() {

	string expression;
	int result;
	cin >> expression;
	auto it = expression.begin();
	result = *(it++) - '0';
	while (it != expression.end()) {
		if (*it == '+') {
			result = result + (*(++it) - '0');
			++it; continue;
		}
		else if (*it == '*') {
			result = result *(*(++it) - '0');
			++it; continue;
		}
		else if (*it == '-') {
			result = result - (*(++it) - '0');
			++it; continue;
		}
	}
	cout << result << endl;
	return 0;
}
