/*
  ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
*/
#include"predefines.h"

bool VerifySequenceOfBST(const vector<int>& seq) {
	if (seq.empty())
		return false;
	int size = seq.size();
	int root = seq[size - 1];
	// ��������ֵ��С�ڸ��ڵ�,Ѱ��������
	int left = 0;
	for (; left < size - 1; ++left)
		if (seq[left] > root)
			break;
	int right = left;
	for (; right < size - 1; ++right)
		if (seq[right] < root)
			return false;
	// �ж��������Ƿ��Ƕ���������
	bool leftans = true;
	if (left > 0)
		leftans = VerifySequenceOfBST(vector<int>(seq.begin(), seq.begin() + left));
	// �ж��������Ƿ��Ƕ���������
	bool rightans = true;
	if (right < size - 1)
		rightans = VerifySequenceOfBST(vector<int>(seq.begin() + left, seq.begin() + right));
	return left && right;
}

int main() {
	//vector<int> sample{ 5,7,6,9,11,10,8 };
	vector<int> sample{ 7,4,5,6 };
	cout << VerifySequenceOfBST(sample) << endl;
	return 0;
}