//[�����] �ֱ���
//����ʦ������һ�б��ɣ�������һ����k����ɣ���������k��Щ��λ���ģ���ˣ�����������־����Ƕ����ˡ�
//����ʦ��Ҫ���æ����k�����ƽ�ָ�n��С���ѣ�����ʦ��֤��б�����ƽ�ָ�n��С���ѡ�
//��������Ҫ�����k�ж����ֿ��ܵ���ֵ
//�������� :
//����������У�
//
//��һ��Ϊ�����ϵ���ֵk��ģ������λ��X��ʾ������С��18(�����ж��ģ������λ)
//
//�ڶ���ΪС���ѵ�����n
//
//������� :
//���k���ܵ���ֵ��������֤����Ϊ1
//
//�������� :
//9999999999999X
//3
//
//������� :
//	4

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
		for (int j = 0; j < n; j++) {       //��һλ����ȡ�������Ŀ����ԣ�0...n-1��
			for (int k = 0; k < 10; k++) {    //��һλ��ȡ��������Ȼ��0~9��
				if (isdigit(s[i]) && s[i] - '0' != k) continue;
				//isdigit �ж��Ƿ�Ϊ0~9������
				//����λΪk,��������п���ȡֵ������ֻ������һ��ȡֵ
				remain[((j * 10) + k) % n] += sync[j];
				//���㵱ǰֵ��ǰһλ������ȡֵ��ϲ���������
			}
		}
		memcpy(sync, remain, sizeof(sync));  //��������Ӧ��ȡֵͬ��
	}
	cout << sync[0] << endl;  //���һλ����Ϊ0�ĵ�ȡֵ
}