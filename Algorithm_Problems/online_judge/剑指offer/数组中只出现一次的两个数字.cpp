/*
  һ����������������������⣬�������ֶ����������Ρ�
  ���ҳ�������ֻ����һ�ε����֣�Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1).
*/
#include<vector>
#include<tuple>

using namespace std;

/*
  ���ֻ���ҳ�һ��ֻ����һ�ε����֣���ô�����������ʣ���ͷ��β���һ�飬�������
  Ҫ�ҵ������ˡ��������������������֣���ôȫ�����һ��õ��������������������Ľ����
  ����������һ������ͬ����ô������Ķ����Ʊ�ʾ���棬�ض���ĳλ��1���ѵ�һλΪ1��λ��
  ��Ϊ���ֱ�׼����ԭ���黮�ֳ����������飬Ȼ���������ֱ����һ���OK�ˡ�
*/
size_t IndexOfFirstBitOne(int num) {
	size_t index = 0, upper = 8 * sizeof(int);
	while ((num & 0x1) == 0 && (index < upper)) {
		++index;
		num >>= 1;
	}
	return index;
}

bool IsIndexBitOne(int num, const size_t& index) {
	num >>= index;
	return num & 0x1;
}

tuple<int,int> NumsAppearOnce(const vector<int>& nums) {
	if (nums.size() < 2)
		throw std::exception("Invalid nums passed in");
	int xor_ans = 0;
	for (const int& num : nums)
		xor_ans ^= num;
	size_t index = IndexOfFirstBitOne(xor_ans);
	int num_one = 0, num_two = 0;
	for (const int& num : nums) {
		if (IsIndexBitOne(num, index))
			num_one ^= num;
		else
			num_two ^= num;
	}
	return make_tuple(num_one, num_two);
}

int main() {
	vector<int> nums{ 2,4,3,6,3,2,5,5 };
	auto ans = NumsAppearOnce(nums);
	std::printf("%d\n", get<0>(ans));
	std::printf("%d\n", get<1>(ans));
	return 0;
}