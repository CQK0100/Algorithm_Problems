//[�����] �����ظ�Ԫ��
//С����һ������Ϊn���У�С�����Ƴ���������ظ�Ԫ�أ�����С�����Ƕ���ÿ��Ԫ�ر��������ֵ��Ǹ���С������������, ϣ��������������
//�������� :
//����������У�
//��һ��Ϊ���г���n(1 �� n �� 50)
//�ڶ���Ϊn����sequence[i](1 �� sequence[i] �� 1000)���Կո�ָ�
//
//
//������� :
//��������ظ�Ԫ��֮������У��Կո�ָ�����ĩ�޿ո�
//
//�������� :
//9
//100 100 100 99 99 99 100 100 100
//
//������� :
//	99 100

#include<iostream>
#include<map>
//#include<algorithm>
//#include<string>
#include<vector>
#define MAXSIZE 51
using namespace std;

int a[MAXSIZE];
map<int, int>COUNT;	//���Ԫ�س��ֵĴ���
vector<int>FINAL;	//�洢���յĲ��ظ�����

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)++COUNT[a[i]]; //��ʼ����
	for (int i = 0; i < n; ++i) {			  //�����һ�����ظ�Ԫ��push_back
		--COUNT[a[i]];
		if (!COUNT[a[i]]) {
			FINAL.push_back(a[i]);
		}
	}
	size_t sz = FINAL.size();
	for (int i = 0; i < sz; ++i) {          //��������еĲ��ظ�Ԫ�أ�ע���ʽ
		if (i == sz - 1)cout << FINAL[i];
		else cout << FINAL[i] << ' ';
	}
	cout << endl;
	return 0;
}