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


//#include<map>
#include<iostream>
#include<algorithm>
//#include<string>
#include<vector>
//#include<ctype.h>
//#include<sstream>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;
//const int MAX_SIZE = 51;
const int MAX_NUM = 500001;
int n;
vector<int> length;


int main() {
	cin >> n;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item; length.push_back(item);
	}
	
	return 0;
}



/*

#include <bits/stdc++.h>

using namespace std;

const int maxn = 500010;
int n;
vector<int> a;
int dp[2][maxn];
int solve(vector<int> v) {
int res = 0;
memset(dp, 0, sizeof(dp));
int p = 0;
for(int i = 0; i < v.size(); i++) {
dp[p][v[i]] = max(dp[1-p][v[i]] , v[i]);
for(int ix = 0; ix < maxn; ix++) {
if(dp[1 - p][ix]) {
if(dp[p][ix] < dp[1 - p][ix]) dp[p][ix] = dp[1-p][ix];
dp[p][ix + v[i]] = max(dp[p][ix + v[i]], max(dp[1 - p][ix + v[i]], dp[1 - p][ix] + v[i]));
dp[p][abs(ix - v[i])] = max(dp[p][abs(ix - v[i])], max(dp[1 - p][abs(ix - v[i])], max(dp[1-p][ix] - ix + v[i], dp[1 - p][ix])));
}
}
p = 1 - p;
}
if(dp[1 - p][0]) res = dp[1 - p][0];
else res = -1;
return res;
}
int main() {
cin >> n;
for(int i = 0; i < n; i++) {
int x; cin >> x;
a.push_back(x);
}
cout << solve(a) << endl;
return 0;
}
*/