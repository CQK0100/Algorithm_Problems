/*
[�����] �����ظ�Ԫ��
С����һ������Ϊn���У�С�����Ƴ���������ظ�Ԫ�أ�����С�����Ƕ���ÿ��Ԫ�ر��������ֵ��Ǹ���С������������,ϣ��������������
��������:
����������У�
��һ��Ϊ���г���n(1 �� n �� 50)
�ڶ���Ϊn����sequence[i](1 �� sequence[i] �� 1000)���Կո�ָ�


�������:
��������ظ�Ԫ��֮������У��Կո�ָ�����ĩ�޿ո�

��������:
9
100 100 100 99 99 99 100 100 100

�������:
99 100
#include<iostream>
#include<map>
//#include<algorithm>
//#include<string>
#include<vector>
#define MAXSIZE 51
using namespace std;

int a[MAXSIZE];
map<int, int>COUNT;	//���Ԫ�س��ֵĴ���
vector<int>FINAL;	//�洢���յĲ��ظ�����

int main() {
int n; cin >> n;
for (int i = 0; i < n; ++i)cin >> a[i];
for (int i = 0; i < n; ++i)++COUNT[a[i]]; //��ʼ����
for (int i = 0; i < n; ++i) {			  //�����һ�����ظ�Ԫ��push_back
--COUNT[a[i]];
if (!COUNT[a[i]]) {
FINAL.push_back(a[i]);
}
}
size_t sz = FINAL.size();
for (int i = 0; i < sz; ++i) {          //��������еĲ��ظ�Ԫ�أ�ע���ʽ
if (i == sz - 1)cout << FINAL[i];
else cout << FINAL[i] << ' ';
}
cout << endl;
return 0;
}


[�����] ��ȥ��˾
���ڵ���ĩ����С�����������Ľֵ���׼�������ѾۻᣬͻȻ��������������,С����Ҫ�����ع�˾�޸��������bug������������һ�����޴������ÿ���ֵ�����������(X��Y)��С�׵�ǰ��(0��0)�ֵ����칫����(gx,gy)�ֵ��ϡ�С����Χ�ж�����⳵�򳵵㣬С�׸�ȥ�칫��������ѡ��һ�־�����·ȥ��˾������һ�־����ߵ�һ�����⳵�򳵵㣬Ȼ��Ӵ򳵵��λ�������⳵ȥ��˾��ÿ���ƶ������ڵĽֵ�(�����������)��·���Ứ��walkTimeʱ�䣬�򳵽�����taxiTimeʱ�䡣С����Ҫ����ϵ���˾ȥ������С����֪���������Ҫ���Ѷ���ʱ��ȥ��˾��
��������:
�������ݰ�������:

��һ��Ϊ��Χ���⳵�򳵵�ĸ���n(1 �� n �� 50)

�ڶ���Ϊÿ�����⳵�򳵵�ĺ�����tX[i] (-10000 �� tX[i] �� 10000)

������Ϊÿ�����⳵�򳵵��������tY[i] (-10000 �� tY[i] �� 10000)

������Ϊ�칫������gx,gy(-10000 �� gx,gy �� 10000),�Կո�ָ�

������Ϊ��·ʱ��walkTime(1 �� walkTime �� 1000)��taxiTime(1 �� taxiTime �� 1000),�Կո�ָ�


�������:
���һ��������ʾ��С������ܸϵ��칫�ҵ�ʱ��

��������:
2
-2 -2
0 -2
-4 -2
15 3

�������:
42
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
int pivot = taxitime*(abs(Gx-TL[i].Tx)+abs(Gy-TL[i].Ty)) + walktime*(abs(TL[i].Tx) + abs(TL[i].Ty));
answer = min(pivot, answer);
}
cout << answer << endl;
return 0;
}

[�����] ����
С���������ѧ����ѧϰ���˼��ϵĸ���,����������������1.ȷ���� 2.������ 3.������.
С�׵���ʦ����С������һ�����ϣ�
S = { p/q | w �� p �� x, y �� q �� z }
��Ҫ���ݸ�����w��x��y��z,���������һ���ж��ٸ�Ԫ�ء�С�ײ�ѧϰ�˼��ϻ��������������ӵ�����,��Ҫ������������
��������:
�������һ�У�
һ��4�������ֱ���w(1 �� w �� x)��x(1 �� x �� 100)��y(1 �� y �� z)��z(1 �� z �� 100).�Կո�ָ�


�������:
���������Ԫ�صĸ���

��������:
1 10 1 1

�������:
10

#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<vector>
//#include<cmath>
#include<set>
using namespace std;

set<pair<int,int>> SET;
int w, x, y, z;
int gcd(int x, int y) //��շת������������������Լ��
{
int r;
while (y>0)
{
r = x%y;
x = y;
y = r;
}
return x;
}

int main() {
cin >> w >> x >> y >> z;
for(int i=w;i<=x;++i)
for (int j = y; j <= z; ++j) {
int p = i, q = j;
int div = gcd(i, j);
SET.insert(make_pair(i/div, j/div));
}
int set_size = SET.size();
cout << set_size<<endl;
return 0;
}

[�����] ��ֵı��ʽ��ֵ
����ı��ʽ��ֵ�����Ƕ�����ݼ�������ȼ������㡣����*,/�����ȼ��͸��� + -������С�������������ı��ʽ����ܼ򵥣������������μ��㼴�ɣ�����С�����ڵ�����û�г�������ζ�ű��ʽ��û�� / ��ֻ��(+, -�� *)�����ڸ���һ�����ʽ����Ҫ���æ�����С�����ڵ�����������ʽ��ֵΪ����
�������� :
����Ϊһ���ַ�������һ�����ʽ�����������ֻ�� - , +, *��������������ֻ��0~9.
��֤���ʽ���ǺϷ��ģ����й�����������ʾ��


������� :
���һ�����������ʽ��ֵ

�������� :
3 + 5 * 7

������� :
	56

	#include<iostream>
	//#include<map>
	#include<algorithm>
	#include<string>
	//#include<vector>
	//#include<cmath>
	//#include<set>

	using namespace std;

	int main() {

	string expression;
	int result;
	cin >> expression;
	auto it = expression.begin();
	result = *(it++)-'0';
	while (it!=expression.end()) {
	if (*it == '+') {
	result = result + (*(++it)-'0');
	++it; continue;
	}
	else if (*it == '*') {
	result = result *(*(++it) - '0');
	++it; continue;
	}
	else if (*it == '-') {
	result = result - (*(++it) - '0');
	++it; continue;
	}
	}
	cout << result<<endl;
	return 0;
	}

	[�����] ��������
	���׶�԰��n��С��������Ϊһ�����飬������һ������һ�����Ϊ(0~n-1)��������һЩ����������һЩ��Ů����������'B'��ʾ��Ů����'G'��ʾ��С�����Ƕ�����Ƥ����һ���������ŵ���Ů����ʱ��ͻᷢ��ì�ܡ���Ϊ�׶�԰����ʦ������Ҫ����������Ů������Ů������������������١���ֻ����ԭ�����Ͻ��е�����ÿ�ε���ֻ�������ڵ�����С���ѽ���λ�ã�������Ҫ������ɶ������������Ҫ�����������Ҫ�������ٴο���������������١����磺
	GGBBG -> GGBGB -> GGGBB
	������ʹ֮ǰ��������Ů���ڱ�Ϊһ�����ڣ���Ҫ��������2��
	��������:
	�������ݰ���һ������Ϊn��ֻ����G��B���ַ���.n������50.


	�������:
	���һ����������ʾ������Ҫ�ĵ�������Ĵ���

	��������:
	GGBBG

	�������:
	2

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
	int result,Num_G=0,Num_B=0;
	vector<int>Result_G, Result_B;
	int main() {
	cin >> QUEUE;
	size_t len = QUEUE.size();
	int i = 0;
	int sum_G=0, sum_B=0;
	//auto it = QUEUE.begin(), END = QUEUE.end();
	while (i<len) {
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

	[�����] ħ���ֻ�
	С��ӵ��һ��ӵ��ħ�����ֻ�������n������(����һ����),�����ħ���ֻ�ÿ��ʹ��ħ����ʱ��ͻᷢ��һ�����صı仯��ÿ�����ֻ����Լ�������һ�����ֵĺ�(���һ�����ֵĺ���һ�������ǵ�һ��),һ��ĳ��λ�õ����ִ��ڵ���100�����϶�100ȡģ(����ĳ��λ�ñ�Ϊ103,�ͻ��Զ���Ϊ3).���ڸ������ħ���ֻ��Ĺ��ɣ���������ʹ��k��ħ��֮��ħ���ֻ���״̬��
	��������:
	�������ݰ������У�
	��һ��Ϊ��������n(2 �� n �� 50)��k(1 �� k �� 2000000000),�Կո�ָ�
	�ڶ���Ϊħ���ֻ���ʼ��n�������Կո�ָ�����Χ����0��99.


	�������:
	���ħ���ֻ�ʹ��k��֮���״̬���Կո�ָ�����ĩ�޿ո�

	��������:
	3 2
	1 2 3

	�������:
	8 9 7

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

	Matrix Matrix_init(MAX_SIZE,vector<int>(MAX_SIZE,0)) ;
	void Make_init(Matrix& Matrix_init) {
	for (int i = 0; i < n; ++i) {
	Matrix_init[i][i] =Matrix_init[i][(i + 1) % n] = 1;
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
/*
Matrix Matrix_mul(Matrix a, Matrix b) {
	Matrix temp(n, vector<int>(n, 0));
	for (int i = 0; i<n; ++i)
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

[�����] ˫�˴���
һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����������֪CPU��ÿ����1����Դ���1kb��
ÿ����ͬʱֻ�ܴ���һ������n��������԰�������˳�����CPU���д���
������Ҫ���һ��������CPU�������������������ʱ�����٣��������С��ʱ�䡣
�������� :
����������У�
��һ��Ϊ����n(1 �� n �� 50)
�ڶ���Ϊn������length[i](1024 �� length[i] �� 4194304)����ʾÿ������ĳ���Ϊlength[i]kb��ÿ������Ϊ1024�ı�����


������� :
���һ����������ʾ������Ҫ�����ʱ��

�������� :
5
3072 3072 7168 3072 1024

������� :
9216


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


[�����] Ϳ����
С����һ��n*n�����̣����̵�ÿһ�����Ӷ�Ϊ��ɫ���߰�ɫ��С������Ҫ����ϲ���ĺ�ɫȥͿ�����̡�
С�׻��ҳ�������ĳһ����ӵ����ͬ��ɫ����������ȥͿ��������С����������Ϳ�����ٸ����
��������:
�������ݰ���n+1�У�

��һ��Ϊһ������n(1 �� n �� 50),�����̵Ĵ�С

��������n��ÿ��һ���ַ�����ʾ��i�����̵���ɫ��'W'��ʾ��ɫ��'B'��ʾ��ɫ


�������:
���С�׻�Ϳ���������С

��������:
3
BWW
BBB
BWB

�������:
3


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


[�����] С�׼ǵ���
С�ײ�����һ���ǵ��ʵ�С��Ϸ����Ϸ��ʼϵͳ�ṩ��m����ͬ�ĵ��ʣ�С�׼���һ��ʱ��֮����Ҫ��ֽ��д������ס�ĵ��ʡ�
С��һ��д����n�����ܼ�ס�ĵ��ʣ����С��д���ĵ�������ϵͳ�ṩ�ģ������������ʳ��ȵ�ƽ���ķ�����
ע��С��д���ĵ��ʿ����ظ������Ƕ���ÿ����ȷ�ĵ���ֻ�ܼƷ�һ�Ρ�
��������:
�������ݰ������У�

��һ��Ϊ��������n(1 �� n �� 50)��m(1 �� m �� 50)���Կո�ָ�

�ڶ���Ϊn���ַ�������ʾС���ܼ�ס�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��

������Ϊm���ַ�����ϵͳ�ṩ�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��


�������:
���һ��������ʾС���ܻ�õķ���

��������:
3 4
apple orange strawberry
strawberry orange grapefruit watermelon

�������:
136


//#include<map>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
//#include<numeric>
//#include<cmath>
#include<set>
using namespace std;
//const int MAX_SIZE = 51;
int n, m;
vector<string> Sys;
set<string> Rem;

int solve(set<string>& rem, vector<string>& sys) {
	int result = 0;
	auto flag = sys.end();
	auto sbegin = rem.begin(), send = rem.end();
	for (; sbegin != send; ++sbegin) {
		if (find(sys.begin(), sys.end(), *sbegin) != flag)result += ((*sbegin).size()*(*sbegin).size());
	}
	return result;
}
int main() {
	cin >> n >> m;
	int result;
	string item;
	for (int i = 0; i < n; ++i) {
		cin >> item;
		Rem.insert(item);
	}
	for (int i = 0; i < m; ++i) {
		cin >> item;
		Sys.push_back(item);
	}
	result = solve(Rem, Sys);
	cout << result << endl;
	return 0;
}


[�����] �ֱ���
����ʦ������һ�б��ɣ�������һ����k����ɣ���������k��Щ��λ���ģ���ˣ�����������־����Ƕ����ˡ�
����ʦ��Ҫ���æ����k�����ƽ�ָ�n��С���ѣ�����ʦ��֤��б�����ƽ�ָ�n��С���ѡ�
��������Ҫ�����k�ж����ֿ��ܵ���ֵ
��������:
����������У�

��һ��Ϊ�����ϵ���ֵk��ģ������λ��X��ʾ������С��18(�����ж��ģ������λ)

�ڶ���ΪС���ѵ�����n

�������:
���k���ܵ���ֵ��������֤����Ϊ1

��������:
9999999999999X
3

�������:
4

//#include<map>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctype.h>
#include<sstream>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;

long long sync[10001], remain[10001];   //ÿһλ����Ӧ����ȡֵ�Ŀ�����
int main() {
	string s;
	int n;
	cin >> s;
	cin >> n;
	sync[0] = 1;
	int s_size = s.size();
	for (int i = 0; i < s_size; ++i) {
		memset(remain, 0, sizeof(remain));
		for (int j = 0; j < n; j++) {       //��һλ����ȡ�������Ŀ�����
			for (int k = 0; k < 10; k++) {    //��һλ��ȡ��������Ȼ��0~9��
				if (isdigit(s[i]) && s[i] - '0' != k) continue;
				//isdigit->�ж��Ƿ�Ϊ0~9������
				//����λΪk,��������п���ȡֵ������ֻ������һ��ȡֵ
				remain[((j * 10) + k) % n] += sync[j];
				//���㵱ǰֵ��ǰһλ������ȡֵ��ϲ���������
			}
		}
		memcpy(sync, remain, sizeof(sync));  //��������Ӧ��ȡֵͬ��
	}
	cout << sync[0] << endl;  //���һλ����Ϊ0�ĵ�ȡֵ
}


*/