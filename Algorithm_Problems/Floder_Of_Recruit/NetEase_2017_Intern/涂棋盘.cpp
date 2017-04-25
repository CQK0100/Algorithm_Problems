//
//[�����] Ϳ����
//С����һ��n*n�����̣����̵�ÿһ�����Ӷ�Ϊ��ɫ���߰�ɫ��С������Ҫ����ϲ���ĺ�ɫȥͿ�����̡�
//С�׻��ҳ�������ĳһ����ӵ����ͬ��ɫ����������ȥͿ��������С����������Ϳ�����ٸ����
//�������� :
//�������ݰ���n + 1�У�
//
//��һ��Ϊһ������n(1 �� n �� 50), �����̵Ĵ�С
//
//��������n��ÿ��һ���ַ�����ʾ��i�����̵���ɫ��'W'��ʾ��ɫ��'B'��ʾ��ɫ
//
//
//������� :
//���С�׻�Ϳ���������С
//
//�������� :
//3
//BWW
//BBB
//BWB
//
//������� :
//3


#include<iostream>
//#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
//#include<cmath>
//#include<set>
using namespace std;
const int MAX_SIZE = 51;

vector<string> ChessBoard(MAX_SIZE);
int n, paint_num;
int solve(vector<string>& CB) {
	vector<int> count_w(MAX_SIZE, 1), count_b(MAX_SIZE, 1);
	int flag_w, flag_b;
	for (int i = 0; i < n; ++i) {	//i����
		flag_b = flag_w = 0;
		for (int j = 0; j < n; ++j) {    //j����
			if (CB[j][i] == 'W') {
				++flag_w; flag_b = 0;
				if (flag_w > count_w[j])count_w[j] = flag_w;
			}
			else if (CB[j][i] == 'B') {
				++flag_b; flag_w = 0;
				if (flag_b > count_b[j])count_b[j] = flag_b;
			}
		}
	}
	sort(count_w.rbegin(), count_w.rend());
	sort(count_b.rbegin(), count_b.rend());
	return max(count_w[0], count_b[0]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> ChessBoard[i];
	int result = solve(ChessBoard);
	cout << result << endl;
	return 0;
}

