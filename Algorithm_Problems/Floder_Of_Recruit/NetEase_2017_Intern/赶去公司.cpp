//[�����] ��ȥ��˾
//���ڵ���ĩ����С�����������Ľֵ���׼�������ѾۻᣬͻȻ��������������, С����Ҫ�����ع�˾�޸��������bug��
//����������һ�����޴������ÿ���ֵ�����������(X��Y)��С�׵�ǰ��(0��0)�ֵ����칫����(gx, gy)�ֵ��ϡ�
//С����Χ�ж�����⳵�򳵵㣬С�׸�ȥ�칫��������ѡ��һ�־�����·ȥ��˾������һ�־����ߵ�һ�����⳵�򳵵㣬
//Ȼ��Ӵ򳵵��λ�������⳵ȥ��˾��ÿ���ƶ������ڵĽֵ�(�����������)��·���Ứ��walkTimeʱ�䣬�򳵽�����taxiTimeʱ�䡣
//С����Ҫ����ϵ���˾ȥ������С����֪���������Ҫ���Ѷ���ʱ��ȥ��˾��
//�������� :
//�������ݰ�������:
//
//��һ��Ϊ��Χ���⳵�򳵵�ĸ���n(1 �� n �� 50)
//
//�ڶ���Ϊÿ�����⳵�򳵵�ĺ�����tX[i](-10000 �� tX[i] �� 10000)
//
//������Ϊÿ�����⳵�򳵵��������tY[i](-10000 �� tY[i] �� 10000)
//
//������Ϊ�칫������gx, gy(-10000 �� gx, gy �� 10000), �Կո�ָ�
//
//������Ϊ��·ʱ��walkTime(1 �� walkTime �� 1000)��taxiTime(1 �� taxiTime �� 1000), �Կո�ָ�
//
//
//������� :
//���һ��������ʾ��С������ܸϵ��칫�ҵ�ʱ��
//
//�������� :
//2
//- 2 - 2
//0 - 2
//- 4 - 2
//15 3
//
//������� :
//	42

#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
//#include<string>
#include<vector>
#define MAXSIZE 51
using namespace std;

#define LOOP(n) for(int i=0;i<n;++i)

struct TaxiLoc
{
	int Tx;
	int Ty;
};
int n, Gx, Gy;
int walktime, taxitime;

int main() {
	TaxiLoc TL[MAXSIZE];
	cin >> n;
	LOOP(n)cin >> TL[i].Tx;
	LOOP(n)cin >> TL[i].Ty;
	cin >> Gx >> Gy;
	cin >> walktime >> taxitime;
	int answer = walktime*(abs(Gx) + abs(Gy));
	LOOP(n) {
		int pivot = taxitime*(abs(Gx - TL[i].Tx) + abs(Gy - TL[i].Ty)) + walktime*(abs(TL[i].Tx) + abs(TL[i].Ty));
		answer = min(pivot, answer);
	}
	cout << answer << endl;
	return 0;
}