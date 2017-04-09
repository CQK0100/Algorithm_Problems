/*
[�����] ��������
������nλ����ʦ��6���(���Ϊ0��5)�����ڸ���ÿ�����ܹ�ʤ�εĹ�����ű�(��һ���ַ�����ʾ��
���磺045����ʾĳλ����ʦ�ܹ�ʤ��0�ţ�4�ţ�5�Ź���)��������Ҫ���й������ţ�
ÿλ����ʦֻ�ܱ����ŵ��Լ��ܹ�ʤ�εĹ�������ȥ����λ����ʦ���ܰ��ŵ�ͬһ�������ȥ��
������ֹ�����������һ���˱������ڵĹ�����Ų�һ���ͱ���Ϊ��ͬ�Ĺ������ţ�������Ҫ������ж����ֲ�ͬ�������żƻ���
��������:
����������n+1�У�
��һ��Ϊ����ʦ����n(1 �� n �� 6)
��������n�У�ÿ��һ���ַ�����ʾ��i(1 �� i �� n)�����ܹ�ʤ�εĹ���(�ַ�����һ���ȳ���)


�������:
���һ����������ʾ�ж����ֲ�ͬ�Ĺ������ŷ���

��������:
6
012345
012345
012345
012345
012345
012345

�������:
720
*/

//����������ֱ����DFS����ö��
//���ݴ��˾�GG��...

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool workable[6][6];
bool arranged[6];			//��¼�����Ƿ��ѱ����ţ���������ݹ�ʱ�ظ�����.
int n;
int dfs(int now) {
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		if (workable[now][i] && !arranged[i]) {
			arranged[i] = true;
			if (now == 0)
				++ans;
			else
				ans += dfs(now - 1);
			arranged[i] = false;
		}
	}
	return ans;
}
int main() {
	cin >> n;
	memset(workable, 0, sizeof(workable));
	memset(arranged, 0, sizeof(arranged));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int s_size = s.size();
		for (int j = 0; j < s_size; ++j)
			workable[i][s[j] - '0'] = true;
	}
	cout << dfs(n - 1) << endl;
	return 0;
}
