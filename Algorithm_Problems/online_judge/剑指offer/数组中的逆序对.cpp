/*
  �������е��������֣����ǰһ�����ں�һ���������������ֹ���һ������ԡ�
  ����һ�����飬����������е�����Ը�����
  ����{7,5,6,4},һ������5������ԡ�
*/
#include<vector>

using namespace std;


/*
  �ݹ飺�Ȱ����黮�ֳ������飬��������ͳ�ƣ�ͳ�Ƴ��������ڲ�������������Ŀ��
  ���ù鲢���򣨶��Ǵ����һ�����ֿ�ʼ����˼�룬1.��������ָ��ָ����������ұߣ�
  ��������ԣ���ĿΪ����������ʣ�����ֵĸ�����
*/
int InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}
	int mid = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + mid);     // ÿһ�εݹ鶼��ԭ����͸��������¾ɽ�����£�����
	int right = InversePairsCore(copy, data, start + mid + 1, end);  // copy��data��ÿ�ζ��ǽ���λ�ã�(����֮���¾ֲ�
	int i = start + mid, j = end;									 // ������copy��ͬ����һ�ε�ԭ����)
	int count = 0;
	int index = end;  // ָʾӦ������copy�е��±�
	while (i >= start && j >= start + mid + 1) {
		if (data[i] > data[j]) {
			count += j - start - mid; // j-(start+mid)
			copy[index--] = data[i--];
		}
		else
			copy[index--] = data[j--];
	}
	while (i >= start)
		copy[index--] = data[i--];
	while (j >= start + mid + 1)
		copy[index--] = data[j--];
	return left + right + count;
}


int InversePairs(vector<int> data) {  // ֵ���� + move�����Բ��ı�ԭ��������
	data = std::move(data);
	if (data.empty())
		return 0;
	vector<int> copy(data.cbegin(), data.cend());
	return InversePairsCore(data, copy, 0, data.size() - 1);
}

int main() {
	vector<int> data{ 7,5,6,4 };
	std::printf("%d\n", InversePairs(data));
	return 0;
}