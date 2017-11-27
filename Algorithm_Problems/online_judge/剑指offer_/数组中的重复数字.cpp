/*
����Ϊn�����飬�������ַ�Χ��0~n-1�ڡ�ĳЩ�����ظ����ҳ�����һ���ظ������֡�
�ⷨ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1).
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;;

bool Duplicate(vector<int>& arr, int& duplication) {
	if (arr.empty())
		return false;
	// �жϷ�Χ�Ƿ�Ϸ�
	int size = arr.size();
	for (auto& num : arr)
		if (num<0 || num>size - 1)
			return false;
	for (int i = 0; i < size; ++i) {
		while (arr[i] != i) {
			if (arr[i] == arr[arr[i]]) {
				duplication = arr[i];
				return true;
			}
			std::swap(arr[i], arr[arr[i]]);
		}
	}
	return false;
}

int main() {
	vector<int> test{ 3,2,1,0,2,5,3 };
	int ans;
	if (Duplicate(test, ans))
		cout << "Find target -> " << ans << endl;
	else
		cout << "No such number." << endl;
	return 0;
}