
//[�����] ����
//С���������ѧ����ѧϰ���˼��ϵĸ���, ����������������1.ȷ���� 2.������ 3.������.
//С�׵���ʦ����С������һ�����ϣ�
//S = { p / q | w �� p �� x, y �� q �� z }
//��Ҫ���ݸ�����w��x��y��z, ���������һ���ж��ٸ�Ԫ�ء�С�ײ�ѧϰ�˼��ϻ��������������ӵ�����, ��Ҫ������������
//�������� :
//�������һ�У�
//һ��4�������ֱ���w(1 �� w �� x)��x(1 �� x �� 100)��y(1 �� y �� z)��z(1 �� z �� 100).�Կո�ָ�
//
//
//������� :
//���������Ԫ�صĸ���
//
//�������� :
//1 10 1 1
//
//������� :
//	10
//
#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<vector>
//#include<cmath>
#include<set>
using namespace std;

set<pair<int, int>> SET;
int w, x, y, z;
int gcd(int x, int y) //��շת������������������Լ��
{
	int r;
	while (y > 0)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	cin >> w >> x >> y >> z;
	for (int i = w; i <= x; ++i)
		for (int j = y; j <= z; ++j) {
			int p = i, q = j;
			int div = gcd(i, j);
			SET.insert(make_pair(i / div, j / div));
		}
	int set_size = SET.size();
	cout << set_size << endl;
	return 0;
}