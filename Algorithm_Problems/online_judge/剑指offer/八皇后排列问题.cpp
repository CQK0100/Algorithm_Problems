/*
  8x8���������ϰڷ�8���ʺ�ʹ�䲻�ܻ��๥���������������ʺ󲻵ô���
  ͬһ�У�ͬһ�У�����ͬһ���Խ����ϡ��ܹ��ж������ŷ���
*/

/*
  ʵ���� ȫ���� ���⣬���Բο�<�ַ���������>�Ľⷨ��
  ��array[8]�����У�array[]�е�ֵ����
  �����ת������array[8]�е��� 0,1,2...7��ȫ��������
  ֻҪ���ж϶Խ����Ƿ�����ͬԪ��
*/
#include<array>

constexpr int kChessBoard = 8;

bool IsValid(const std::array<int, kChessBoard>& arr) {
	for (int i = 0; i < arr.size(); ++i) {  // i&j ��������size_t������ʽת�� & �������.
		int j = (i - arr[i]) >= 0 ? (i - arr[i]) : 0;
		for (; j < arr.size(); ++j) {  // �������-���¶Խ���
			if (arr[j] == (j + arr[i] - i) && j != i)
				return false;
		}
		j = (i + arr[i]) >= arr.size() ? arr.size() - 1 : (i + arr[i]);
		for (; j >= 0; --j) {  // �������-���϶Խ���
			if ((j + arr[j]) == i + arr[i] && j != i)
				return false;
		}
	}
	return true;
}

int QueenPermutation(const int& count = kChessBoard) {
	std::array<int, kChessBoard> queen;
	for (int i = 0; i < kChessBoard; ++i)
		queen[i] = i;  // ��ʼ��queen���飬ʹ����С�������С�
	int ans = 0;
	if (IsValid(queen))
		++ans;
	int end = kChessBoard - 1;
	int pos = end;
	int next, min;
	while (pos > 0) {
		next = pos;
		--pos;
		if (queen[pos] < queen[next]) {
			min = end;
			while (queen[min] <= queen[pos])
				--min;
			std::swap(queen[pos], queen[min]);
			std::reverse(queen.begin() + next, queen.end());
			if (IsValid(queen))
				++ans;
			pos = end;
		}
	}
	return ans;
}

int main() {
	std::printf("%d\n", QueenPermutation());
	return 0;
}