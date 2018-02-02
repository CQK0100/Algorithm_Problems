/*
  ���ǰ�ֻ��������2,3,5������Ϊ�������󰴴�С����˳��ĵ�1500��������
  ������ϰ���ϰ�1���ɵ�һ��������
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
bool IsUgly(int number) {
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
*/

/*
  ˳��߲��ұ߼����Ƿǳ���ʱ�ġ�
  ֱ�Ӵ����еĳ����Ƴ���һ�������������м�ķǳ�������һ������һ��������ĳ��������2/3/5����
  ��ô�����г�����2/3/5�����ҳ���һ����������������������
  Ϊ�˱����ظ����㣬ά��3���±�ֱ�ָ������ĳ������2/3/5����С�ڵ��ڵ�ǰ������������±꣬
  ��һ��ֱ�Ӵ���Щ�±������ҡ�
*/
long long GetUglyNumber(const int& index) {
	if (index <= 0)
		return 0;
	vector<long long> ugly_numbers(index, 0);
	ugly_numbers[0] = 1;
	int next = 1;
	int mul2_idx, mul3_idx, mul5_idx;
	mul2_idx = mul3_idx = mul5_idx = 0;
	while (next < index) {
		long long min = std::min(std::min(ugly_numbers[mul2_idx] * 2, ugly_numbers[mul3_idx] * 3), ugly_numbers[mul5_idx] * 5);
		ugly_numbers[next] = min;
		while (ugly_numbers[mul2_idx] * 2 <= ugly_numbers[next])
			++mul2_idx;
		while (ugly_numbers[mul3_idx] * 3 <= ugly_numbers[next])
			++mul3_idx;
		while (ugly_numbers[mul5_idx] * 5 <= ugly_numbers[next])
			++mul5_idx;
		++next;
	}
	return ugly_numbers[index - 1];
}


int main() {
	std::printf("%d\n", GetUglyNumber(1500));
	return 0;
}