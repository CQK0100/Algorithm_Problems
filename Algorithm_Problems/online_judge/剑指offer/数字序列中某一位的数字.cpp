/*
  ������01234567891011121314...�ĸ�ʽ���л���һ���ַ������С�
  ���дһ���������������nλ��Ӧ�����֡�
*/
#include<cmath>
#include<iostream>

int CountOfInt(int digit) { // nλ�����ܹ��ж��ٸ�
	if (digit == 1)
		return 10;
	return 9 * static_cast<int>(std::pow(10, digit - 1));
}

int DigitAtIndex(int index, int digit) {  // digit: ������λ��
	int begin;
	if (digit == 1)
		begin = 0;
	else
		begin = static_cast<int>(std::pow(10, digit - 1));
	int number = begin + index / digit;
	int right_index = digit - index % digit;
	for (int i = 1; i < right_index; ++i)
		number /= 10;
	return number % 10;
}

int DigitAtIndex(int index) {
	if (index < 0)
		return -1;
	int digit = 1;
	while (true) {
		int number = CountOfInt(digit);
		if (index < digit*number)
			return DigitAtIndex(index, digit);
		index -= digit * number;
		++digit;
	}
	return -1;
}

int main() {
	std::cout << DigitAtIndex(1001) << std::endl;
	return 0;
}