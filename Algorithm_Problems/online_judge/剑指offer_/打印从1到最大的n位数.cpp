/*
 ��������n,��˳���ӡ����1������nλʮ����������������3�����ӡ��1,2,3...999.
*/

/*
 n��λ���ܴ󣬺���������������ʹ��long long Ҳ���С�
 �������ַ���ģ������
*/
#include<string>
#include<iostream>

using namespace std;

void PrintNumber(const string& num) {
	if (num.empty())
		return;
	int i = 0;
	while (num[i] == '0')
		++i;
	for (; i < num.size(); ++i)
		printf("%c", num[i]);
	cout << endl;
}

// ���������򷵻�false.
// ���򷵻�true;
bool Increment(string& num) {
	bool success = true;
	int size = num.size();
	int carry = 0;
	for (int i = size - 1; i >= 0; --i) {
		int sum = num[i] - '0' + carry;
		if (i == size - 1)
			++sum;
		if (sum >= 10) {
			if (i == 0)
				success = false;
			else {
				sum -= 10;
				carry = 1;
				num[i] = '0' + sum;
			}
		}
		else {
			num[i] = '0' + sum;
			break;
		}
	}
	return success;
}

void PrintOneToNDigits(int n) {
	if (n <= 0)
		return;
	string num(n, '0');
	while (Increment(num))
		PrintNumber(num);
}


int main() {
	PrintOneToNDigits(3);
	return 0;
}