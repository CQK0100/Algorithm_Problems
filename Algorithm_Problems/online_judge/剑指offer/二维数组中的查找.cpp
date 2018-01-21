/*
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

// �����Ͻǻ������½ǿ�ʼ���ң�����С���ҷ�Χ
// ���ܴ����ϻ������¿�ʼ����Χ���ص�

class Solution {
public:
	bool Find(int target, vector<vector<int>> matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		// �ж��Ƿ�Ϊ����
		for (const auto& each : matrix) {
			if (each.size() != col)
				return false;
		}
		for (int i = 0, j = col - 1; i >= 0 && i < row;){
			if (target == matrix[i][j])
				return true;
			else if (target < matrix[i][j])
				i--;
			else			
				j++;
		}
		return false;
	}
};