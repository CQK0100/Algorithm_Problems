/*
  ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
  ����һ����������������һ����ת�������ת�������СԪ�ء�
*/

int FindMin(const std::vector<int>& arr) {
	if (arr.empty())
		throw std::exception("Invalid array.");
	if (arr.size() == 1)
		return arr[0];
	int begin = 0, end = arr.size();
	while (begin < end) {
		int mid = (begin + end) / 2;
		if (arr[mid] > arr[begin])
			begin = mid + 1;
		else if (arr[mid] < arr[begin])
			end = mid;
		else
			--end;  // ��С��Χ���൱��˳�����
	}
	return arr[begin];
}