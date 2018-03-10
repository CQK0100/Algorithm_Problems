/*
  ��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ�����п��ܵ�ֵ�ĸ��ʡ�
*/
#include<vector>

using namespace std;

constexpr int kMaxDiceValue = 6;

void PrintProbability(int number) {
	if (number < 1)
		return;
	vector<vector<int>> probability(2, vector<int>(kMaxDiceValue*number + 1, 0));
	int flag = 0;
	std::fill(probability[0].begin(), probability[0].begin() + kMaxDiceValue, 1); // ��һ��0...6������һ��
	for (int k = 2; k <= number; ++k) {
		std::fill(probability[1 - flag].begin(), probability[1 - flag].begin() + k, 0);  // ��ʼ��
		for (int i = k; i < k*kMaxDiceValue; ++i) {
			probability[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= kMaxDiceValue; ++j) {
				// ��ǰ�ĺ�Ϊn������ֵĴ���ӦΪ֮ǰ��Ϊn-1,n-2...n-6�Ĵ������ܺ�
				// ��Ϊ��ǰ�ĺ�Ϊn�����������¼�������ӳ���1����n=1+(n-1),������
				// ����2����n=2+(n-1)...�Դ�����
				probability[1 - flag][i] += probability[flag][i - j];
			}
		}
		flag = 1 - flag;
	}
	double total = std::pow(kMaxDiceValue, number);
	for (auto beg = probability[flag].begin() + kMaxDiceValue; beg + kMaxDiceValue != probability[flag].end(); ++beg) {
		std::printf("%.6f\n", static_cast<double>(*beg) / total);
	}
}

int main() {
	PrintProbability(6);
	return 0;
}