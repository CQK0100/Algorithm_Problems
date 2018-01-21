/*
 ����һ���������飬ʵ��һ�����������������������ֵ�˳��
 ʹ����������λ������ǰ�벿�֣�����ż��λ�������벿�֡�
*/

#include<vector>
#include<iostream>

using namespace std;

// O(n^2)�Ľⷨ
void ReorderOddEven(vector<int>& arr) {
	int size = arr.size();
	for (int i = 0; i < size; ++i) {
		if (!(arr[i] % 2)) {
			int cur = arr[i];
			for (int j = i; j < size - 1; ++j) {
				arr[j] = arr[j + 1];
			}
			arr[size - 1] = cur;
		}
	}
}

// O(n)�Ľⷨ
// ά������ָ�룬һ��ǰ->��һ����->ǰ
// ǰ==ż&&��==�棬����
void ReorderOddEven_Better(vector<int>& arr) {
	int i = 0, j = arr.size() - 1;
	while (i < j) {
		while (arr[i] % 2)
			++i;
		while (!(arr[j] % 2))
			--j;
		std::swap(arr[i], arr[j]);
	}
}

int main() {
	vector<int> arr{ 1,4,7,8,5,2,0,3,6,9,8,89,5,1,3,31,64,6,34 };
	ReorderOddEven(arr);
	for (auto& item : arr)
		cout << item << ' ';
	cout << endl;
	ReorderOddEven_Better(arr);
	for (auto& item : arr)
		cout << item << ' ';
	cout << endl;
	return 0;
}