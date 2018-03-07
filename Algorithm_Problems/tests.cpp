#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

/*
����:
�������� ������һ��NxK�Ķ�ά����N��ʾ�м������飬K��ʾ�ж�������ɫ��
�������cost[0][0]��ʾ����0��Ϳ��0����ɫ�Ļ��ѡ� ����ĵ�һ����N,K ��������ÿһ�е�����
���:
��С�Ļ���
���뷶��:
4 3
2 3 2
9 1 4
7 8 1
2 8 3
�������:
6
*/

/** ������������������ʵ����ĿҪ��Ĺ��� **/
/** ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^  **/
int minCost(vector<vector<int>>& costs)
{
	if (costs.empty() || costs[0].empty())
		return 0;
	vector<bool> color_hash(costs[0].size(), false);
	int min=(1<<10);
	for (int i = 0; i < costs[0].size(); ++i) {
		vector<int> dp(costs.size(), (1<<31));
		dp[0] = costs[0][i];
		color_hash[0] = true;
		for (int j = 1; j < costs.size(); ++j) {
			// ��ǰ������С�������ڲ�ͬɫ�Ļ���
			int cur_min = 1<<31;
			int color_inex = 0;
			for (int n = 0; n < costs[j].size();++n) {
				if (!color_hash[j - 1] && costs[j][n] < cur_min) {
					cur_min = costs[j][n];
					color_inex = n;
				}
			}
			// ѡ����ɫ����ɫ
			color_hash[color_inex] = true;
			dp[j] = (cur_min < dp[j]) ? cur_min : dp[j];
		}
		// ��ǰ��С���ѵĺ�
		int sum = 0;
		for (auto item : dp)
			sum += item;
		min = (sum < min) ? sum : min;
		dp.resize(costs.size(), (1 << 31));
		color_hash.resize(costs[0].size(), false);
	}
	return min;
}

int main()
{
	int N, K;
	int cost;
	vector<vector<int> > costs;
	string s;
	istringstream is;

	getline(cin, s);
	is.str(s);
	is >> N >> K;
	for (int i = 0; i < N; i++)
	{
		vector<int> t;
		getline(cin, s);
		is.clear();
		is.str(s);
		for (int j = 0; j < K; j++) {
			is >> cost;
			t.push_back(cost);
		}
		costs.push_back(t);
	}
	cout << minCost(costs) << endl;
	return 0;
}