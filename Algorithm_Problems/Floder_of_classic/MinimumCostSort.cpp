/*
������w(i)(i=0,1......n-1)��n�������ų�һ�С���Ҫ�û�е�۽���Щ��������
��е��ÿ�β��������������i��j����������λ�ã�ͬʱ����w(i)+w(j)�ĳɱ���
��е�۵Ĳ�������û�����ơ�
���룺��һ����������n���ڶ�������n������w(i),�ÿո����,w(i)ֵ���ظ���
*/

#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1000;
const int VMAX = 10000;
#define loop(n) for (int i = 0; i < n; ++i) 
int n, min_elem;//min_elem������w(i)�е���СԪ�أ�nΪ����
int A[MAX], B[MAX], T[MAX + 1];

int Solve() {
	int ans = 0;
	bool V[MAX];
	loop(n) { B[i] = A[i]; V[i] = false; }
	sort(B, B + n);		      //������̬��sorted B[]
	loop(n)T[B[i]] = i;       //T[]��¼B[i]��Ӧ���±�i
	loop(n) {
		if (V[i])continue;
		int cur = i;
		int s = 0, m = VMAX, an = 0;
		while (true) {
			V[cur] = true;    //�����Ǵ�V[i]
			++an;             //an=����Բ�е�Ԫ�ظ���
			int v = A[cur];
			m = min(m, v);    //m=����Բ�е���СԪ��
			s += v;		      //s=����ԲԪ��֮��
			cur = T[v];        //cur=T[A[i]] ��A[]�������(B[])��A[i]��Ӧ���±�
			if (V[cur])break;  //�ص��Լ��������γ�һ������Բ��break while_loop��
		}
		ans += min(s + (an - 2)*m, m + s + (an + 1)*min_elem);   //ÿ�αȽϣ���������СԪ�أ��ͣ�����Ԫ�أ���ȡ��Сֵ
	}
	return ans;
}

int main() {
	cin >> n;
	min_elem = VMAX;
	loop(n) { cin >> A[i]; min_elem = min(min_elem, A[i]); }
	int answer = Solve();
	cout << answer << endl;
	return 0;
}