/*
  һ������Ϊn-1�ĵ��������������������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0~n-1�ڡ�
  �ڷ�Χ0~n-1��n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�
*/
#include<vector>

using namespace std;

/*
  ��ֱ�ӵķ�����������n(n-1)/2�Ĺ�ʽ���n������֮�ͣ��ټ�ȥ������������֮�ͼ���ȱʧ�����֡�
  ʱ�临�Ӷ�ΪO(n)��û�����õ�����������ԡ�
  ��ȱʧ����Ϊk����0...k-1�����ּ��������±꣬��ô��ת��Ϊ��Ѱ�������е�һ��ֵ���±겻��ͬ�����֡�
  "�����������в�������"�ı��Ρ�
*/

int GetMissingNumber(const vector<int>& nums) {
	if (nums.empty())
		return -1;
	int start = 0, end = nums.size() - 1;
	int mid = (start + end) / 2;
	while (start < end) {
		if (nums[mid] != mid) {
			if (mid == 0 || nums[mid - 1] == mid - 1)
				break;
			else
				end = mid;
		}
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	return mid;
}

int main() {
	vector<int> nums{ 0,1,2,3,4,5,7,8,9 };
	std::printf("%d\n", GetMissingNumber(nums));
	return 0;
}