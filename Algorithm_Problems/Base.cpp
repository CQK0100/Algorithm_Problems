/*
//�����������
����n������A������m���ж�A�����⼸��Ԫ������Ƿ��ܵõ�m,A��ÿ��Ԫ��ֻ����һ�Ρ�
����һ���ݹ麯���жϣ�

int solve(int i,int m){
	if(m==0)return 1;
	if(i>=n)return 0;
	int result=solve(i+1,m)||solve(i+1,m-A[i]);
	return result;
	}
	//	��������n�ϴ����⣬���Ӷ�ΪO��2^n�������ö�̬�滮�Ż�
*/

/*
//	��������/���η�
int Partiton(int A[], int p, int r) {
int pivot = A[r];
int i = p - 1;
for (int j = p; j < r ; ++j) {
if (A[j] <= pivot) { i += 1; std::swap(A[i], A[j]); }
}
std::swap(A[i + 1], A[r]);
return i + 1;
}

void Quick_Sort(int A[], int p, int r) {
int q;
if (p < r) {
q = Partiton(A, p, r);
Quick_Sort(A, p, q - 1);
Quick_Sort(A, q+1,r);
}
}

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main() {
	
	return 0;
}