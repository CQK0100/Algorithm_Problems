/*
[�����] ��ש��
С����n��ש�飬ÿһ��ש����һ���߶ȡ�С��ϣ��������Щש�����������ͬ�߶ȵ�����
Ϊ��������򵥣�ש��������Ǽ򵥵ĸ߶���ӣ�ĳһ��שֻ��ʹ����һ������һ�Ρ�
С���������ܹ������������������ĸ߶Ⱦ����ߣ�С���ܷ�����ء�
��������:
����������У�
��һ��Ϊ����n(1 �� n �� 50)����һ����n��ש��
�ڶ���Ϊn����������ʾÿһ��ש��ĸ߶�height[i] (1 �� height[i] �� 500000)


�������:
���С���ܶ����������߶���ͬ��������������ƴ�յĸ߶ȣ�������������-1.
��֤�𰸲�����500000��

��������:
3
2 3 5

�������:
5
*/

//  ***********���Ǻ�*********
//  ������ĥ�Һܾ�...�Ͼ�DP�����ţ�Ȼ�����nowcoder�ϵ�ʾ���������������ѧУACM����
//  �Ŷ��˽���˼·...  (�s��t)

//  ��û��ש�鿪ʼ����������ÿ��ש�����ľ���,�������,�����ұߺͲ�ʹ�����ש���������
//  dp[p][gap]��ʾֻ��ǰp��ש�ѳɸ߶����gap���������Ľϸߵ�һ�������ĸ߶�
//  ����gap + height[i]���������������ש��
//  gap - height�����ұ�������ש�� �ұ�������ʱ�߶�Ҳ������
//  ������������ǰ��״̬,���������ֵ
//  ��Ϊֻ��Ҫ֪��[P-1][]�Ϳ������[P][]���԰�pѭ����0��1���������飩��ʡ�ռ�



#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int MAX_NUM = 500010;
int n;
int DP[2][MAX_NUM];

int solve(vector<int>& len) {
	memset(DP, 0, sizeof(DP));  //initialize the DP array
	int p = 0;
	auto len_size = len.size();
	for (int i = 0; i < len_size; ++i) {
		DP[p][len[i]] = max(DP[1 - p][len[i]], len[i]);
		for (int gap = 0; gap < MAX_NUM; ++gap) {
			if (DP[1 - p][gap]) {  //if the tower exsists
				if (DP[p][gap] < DP[1 - p][gap])DP[p][gap] = DP[1 - p][gap];
				DP[p][gap + len[i]] = max(DP[p][gap + len[i]], max(DP[1 - p][gap + len[i]], DP[1 - p][gap] + len[i]));
				DP[p][abs(gap - len[i])] = max(DP[p][abs(gap - len[i])], max(DP[1 - p][abs(gap - len[i])], max(DP[1 - p][gap] - gap + len[i], DP[1 - p][gap])));
			}
		}
		p = 1 - p;
	}
	int result = (DP[1 - p][0]) ? DP[1 - p][0] : -1;
	return result;
}

int main() {
	vector<int> length;
	cin >> n;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item; length.push_back(item);
	}
	int result = solve(length);
	cout << result << endl;
	return 0;
}

/*
//�����Ͽ�������һ���汾�ģ��ⷨ��ͬС�죬����Ҳ�������Ա�
//���Ǹо���һ�ֽⷨ�Ŀɶ��Ը���


#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int dp[2][2*N]; //��һά����״̬ �ڶ�ά�������Ĳ�ֵ
int height[55];
int main()
{
int n;
cin >> n;
for (int i = 1; i <= n; i++)
{
scanf("%d", &height[i]);
}
memset(dp, 0, sizeof(dp));
int p = 0;

for (int j = 0; j < 2*N; j++) dp[1-p][j] = INT_MIN; //��֤��һ��ȡ����
dp[1-p][N] = 0;//���
for (int i = 1; i <= n; i++)
{
for (int j = height[i]; j < 2*N; j++)
{
dp[p][j] = max(dp[1-p][j-height[i]]+height[i], dp[1-p][j]); //�ŵ��ұ߼�С��ಢ�������� �Լ�������ש��
}
for (int j = 0; j+height[i] < 2*N; j++)
{
dp[p][j] = max(dp[p][j], dp[1-p][j+height[i]]); //�ŵ�������Ӳ��
}
p = 1 - p;
}
if (dp[1-p][N]) cout << dp[1-p][N] << endl;
else cout <<-1;
return 0;
}


*/