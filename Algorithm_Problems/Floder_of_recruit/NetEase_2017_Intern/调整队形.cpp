//[�����] ��������
//���׶�԰��n��С��������Ϊһ�����飬������һ������һ�����Ϊ(0~n - 1)��������һЩ����������һЩ��Ů����������'B'��ʾ��Ů����'G'��ʾ��С�����Ƕ�����Ƥ����һ���������ŵ���Ů����ʱ��ͻᷢ��ì�ܡ���Ϊ�׶�԰����ʦ������Ҫ����������Ů������Ů������������������١���ֻ����ԭ�����Ͻ��е�����ÿ�ε���ֻ�������ڵ�����С���ѽ���λ�ã�������Ҫ������ɶ������������Ҫ�����������Ҫ�������ٴο���������������١����磺
//GGBBG->GGBGB->GGGBB
//������ʹ֮ǰ��������Ů���ڱ�Ϊһ�����ڣ���Ҫ��������2��
//�������� :
//�������ݰ���һ������Ϊn��ֻ����G��B���ַ���.n������50.
//
//
//������� :
//	���һ����������ʾ������Ҫ�ĵ�������Ĵ���
//
//	�������� :
//GGBBG
//
//������� :
//2

#include<iostream>
//#include<map>
#include<algorithm>
#include<string>
#include<vector>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;

string QUEUE;
int result, Num_G = 0, Num_B = 0;
vector<int>Result_G, Result_B;
int main() {
	cin >> QUEUE;
	size_t len = QUEUE.size();
	int i = 0;
	int sum_G = 0, sum_B = 0;
	//auto it = QUEUE.begin(), END = QUEUE.end();
	while (i < len) {
		if (QUEUE[i] == 'G') {
			++Num_G; Result_G.push_back(i);
		}
		if (QUEUE[i] == 'B') {
			++Num_B; Result_B.push_back(i);
		}
		++i;
	}
	for (i = 0; i < Num_G; ++i)sum_G += (Result_G[i] - i);
	for (i = 0; i < Num_B; ++i)sum_B += (Result_B[i] - i);
	result = min(sum_B, sum_G);
	cout << result << endl;
	return 0;
}