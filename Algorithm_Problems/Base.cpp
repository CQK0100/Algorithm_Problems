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


#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	return 0;
}