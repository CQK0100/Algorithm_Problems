//[�����] ħ���ֻ�
//С��ӵ��һ��ӵ��ħ�����ֻ�������n������(����һ����), �����ħ���ֻ�ÿ��ʹ��ħ����ʱ��ͻᷢ��һ�����صı仯��ÿ�����ֻ����Լ�������һ�����ֵĺ�(���һ�����ֵĺ���һ�������ǵ�һ��), һ��ĳ��λ�õ����ִ��ڵ���100�����϶�100ȡģ(����ĳ��λ�ñ�Ϊ103, �ͻ��Զ���Ϊ3).���ڸ������ħ���ֻ��Ĺ��ɣ���������ʹ��k��ħ��֮��ħ���ֻ���״̬��
//�������� :
//�������ݰ������У�
//��һ��Ϊ��������n(2 �� n �� 50)��k(1 �� k �� 2000000000), �Կո�ָ�
//�ڶ���Ϊħ���ֻ���ʼ��n�������Կո�ָ�����Χ����0��99.
//
//
//������� :
//	���ħ���ֻ�ʹ��k��֮���״̬���Կո�ָ�����ĩ�޿ո�
//
//	�������� :
//3 2
//1 2 3
//
//������� :
//	8 9 7
//
#include<iostream>
	//#include<map>
#include<algorithm>
	//#include<string>
#include<vector>
	//#include<numeric>
	//#include<cmath>
	//#include<set>
const int MAX_SIZE = 101;
using namespace std;
typedef vector<vector<int>> Matrix;

const int MOD = 100;
vector<int> Magic;
int n; long long int k;

Matrix Matrix_init(MAX_SIZE, vector<int>(MAX_SIZE, 0));
void Make_init(Matrix& Matrix_init) {
	for (int i = 0; i < n; ++i) {
		Matrix_init[i][i] = Matrix_init[i][(i + 1) % n] = 1;
	}
}
/*
k��������̫��ֱ��˦��һ��TLE
void Solve(vector<int>& Magic) {
int flag = Magic[0];
for (long long int i = 0; i < k; ++i) {
for (int j = 0; j < n; ++j) {
if (j == n - 1)Magic[j] += flag;
else Magic[j] += Magic[j + 1];
if (Magic[j] > 100)Magic[j] %= 100;
}
flag = Magic[0];
}
}
*/
//
//���յĽ���൱�� ħ�������ɵ�һά����[0...n-1]��
//	[1 1 0 0 ...]
//	[0 1 1 0 ...]
//	[0 0 1 1 ...]
//	[...........]
//	[1 0 0.....1]
//	�����ľ������
//  Ϊ���ڹ涨ʱ�������У����þ���Ŀ������Ż�  
//������blog�ο���http ://blog.csdn.net/hikean/article/details/9749391

Matrix Matrix_mul(Matrix a, Matrix b) {
	Matrix temp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= MOD;
			}

		}
	return temp;
}

Matrix Quick_pow(Matrix a, long long int k) {
	long long int N = k;
	Matrix ANS(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		ANS[i][i] = 1;
	while (N) {
		if (N & 1) {  //��n%2
			ANS = Matrix_mul(ANS, a);
		}
		N = N >> 1;   //��n=n/2
		a = Matrix_mul(a, a);
	}
	return ANS;
}

vector<int> Magic_mul(vector<int> Magic, Matrix BASE) {
	vector<int> temp;
	int flag;
	for (int i = 0; i < n; ++i) {
		flag = 0;
		for (int k = 0; k < n; ++k) {
			flag = (flag + Magic[k] * BASE[i][k]) % MOD;
		}
		temp.push_back(flag);
	}
	return temp;
}

int main() {
	cin >> n;
	cin >> k;
	int item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Magic.push_back(item);
	}
	Matrix BASE(n, vector<int>(n, 0));
	Make_init(Matrix_init);
	BASE = Quick_pow(Matrix_init, k);
	Magic = Magic_mul(Magic, BASE);
	for (int i = 0; i < n; ++i) {
		(i == n - 1) ? cout << Magic[i] : cout << Magic[i] << ' ';
	}
	cout << endl;
	return 0;
}
