//[�����] ˫�˴���
//һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����������֪CPU��ÿ����1����Դ���1kb��
//ÿ����ͬʱֻ�ܴ���һ������n��������԰�������˳�����CPU���д���
//������Ҫ���һ��������CPU�������������������ʱ�����٣��������С��ʱ�䡣
//�������� :
//����������У�
//��һ��Ϊ����n(1 �� n �� 50)
//�ڶ���Ϊn������length[i](1024 �� length[i] �� 4194304)����ʾÿ������ĳ���Ϊlength[i]kb��ÿ������Ϊ1024�ı�����
//
//
//������� :
//���һ����������ʾ������Ҫ�����ʱ��
//
//�������� :
//5
//3072 3072 7168 3072 1024
//
//������� :
//	9216
//

#include<iostream>
//#include<map>
#include<algorithm>
//#include<string>
#include<vector>
#include<numeric>
//#include<cmath>
//#include<set>
using namespace std;
const int MAX_SIZE = 51;
vector<int> Length_n;

int n;

//ʹ��max(cpu_one_time,cpu_two_time)��С
//   =====> 01 bag ģ�ͣ�
//���Ϊsum/2������n�����壬����Ϊt[i]����ֵҲ��t[i]���������װ
//0-1 bag ˼·���䣺
//��N����Ʒ��һ������ΪV�ı�������i����Ʒ�ķ�����c[i],��ֵ��w[i],��⽫��Щ��Ʒ���뱳����ʹ��ֵ�ܺ����
//�ص㣺 ÿһ����Ʒ����һ�����ܹ�ѡ��Ż��߲��š� 
//����״̬��F[i][v]:��ʾǰi����Ʒǡ�÷���һ������Ϊv�ı����ܹ���õ����ļ�ֵ 
//ת�Ʒ��̣�F[i][v]=max(F[i-1][v],F[i-1][v-c[i]]+w[i]]); 
//�Ż��ռ临�Ӷȣ� ������ʱ��Ϳռ临�ӶȾ�ΪO(V*N),ʱ�临�ӶȲ������Ż��ˣ�Ȼ���ռ临�Ӷ��ܹ���һ���Ż�
//�����������ǣ�������һ������F[0..V],��֤��i��ѭ������������F[v]��ʾ���Ǿ��Ƕ����״̬F[i][v]


int solve(vector<int>& Len, int sum) {
	int halfsum = sum >> 1;
	vector<int> DP(halfsum + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = halfsum; j >= Len[i]; --j)
			DP[j] = max(DP[j], DP[j - Len[i]] + Len[i]);
	}
	return DP[halfsum];
}

int main() {
	cin >> n; int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Length_n.push_back(item / 1024);
	}
	//sort(Length_n.begin(), Length_n.end());
	int SUM = accumulate(Length_n.begin(), Length_n.end(), 0);
	int result = max(solve(Length_n, SUM), SUM - solve(Length_n, SUM));
	cout << result * 1024 << endl;
	return 0;
}
