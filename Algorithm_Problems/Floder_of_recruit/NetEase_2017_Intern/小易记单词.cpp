//[�����] С�׼ǵ���
//С�ײ�����һ���ǵ��ʵ�С��Ϸ����Ϸ��ʼϵͳ�ṩ��m����ͬ�ĵ��ʣ�С�׼���һ��ʱ��֮����Ҫ��ֽ��д������ס�ĵ��ʡ�
//С��һ��д����n�����ܼ�ס�ĵ��ʣ����С��д���ĵ�������ϵͳ�ṩ�ģ������������ʳ��ȵ�ƽ���ķ�����
//ע��С��д���ĵ��ʿ����ظ������Ƕ���ÿ����ȷ�ĵ���ֻ�ܼƷ�һ�Ρ�
//�������� :
//�������ݰ������У�
//
//��һ��Ϊ��������n(1 �� n �� 50)��m(1 �� m �� 50)���Կո�ָ�
//
//�ڶ���Ϊn���ַ�������ʾС���ܼ�ס�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��
//
//������Ϊm���ַ�����ϵͳ�ṩ�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��
//
//
//������� :
//���һ��������ʾС���ܻ�õķ���
//
//�������� :
//3 4
//apple orange strawberry
//strawberry orange grapefruit watermelon
//
//������� :
//136

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
//#include<numeric>
//#include<cmath>
#include<set>
using namespace std;
//const int MAX_SIZE = 51;
int n, m;
vector<string> Sys;
set<string> Rem;

int solve(set<string>& rem, vector<string>& sys) {
	int result = 0;
	auto flag = sys.end();
	auto sbegin = rem.begin(), send = rem.end();
	for (; sbegin != send; ++sbegin) {
		if (find(sys.begin(), sys.end(), *sbegin) != flag)result += ((*sbegin).size()*(*sbegin).size());
	}
	return result;
}
int main() {
	cin >> n >> m;
	int result;
	string item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Rem.insert(item);
	}
	for (int i = 0; i < m; ++i) {
		cin >> item;
		Sys.push_back(item);
	}
	result = solve(Rem, Sys);
	cout << result << endl;
	return 0;
}

