/*
���һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ���������,��,��,���ƶ�һ��
���һ��·�������˾����ĳһ�������ٴν��롣

���ݷ���������

*/
#include<vector>
#include<string>
#include<iostream>

using namespace std;

bool HasPathCore(const vector<vector<char>>& matrix, int rows, int cols, int row, int col, const string& path, int& path_len, vector<vector<bool>>& visited) {
	if (path_len == path.size())
		return true;
	bool haspath = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row][col] == path[path_len] && !visited[row][col]) {
		++path_len;
		visited[row][col] = true;
		haspath = HasPathCore(matrix, rows, cols, row, col - 1, path, path_len, visited)  // ������
			|| HasPathCore(matrix, rows, cols, row - 1, col, path, path_len, visited)  // ����ϱ�
			|| HasPathCore(matrix, rows, cols, row, col + 1, path, path_len, visited)  // ����ұ�
			|| HasPathCore(matrix, rows, cols, row + 1, col, path, path_len, visited);  // ����±�
		if (!haspath) {  // �����·���������⣬����
			--path_len;
			visited[row][col] = false;
		}
		return haspath;
	}
}


bool HasPath(const vector<vector<char>>& matrix, int rows, int cols, const string& path) {
	if (rows < 1 || cols < 1)
		return false;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	int path_len = 0;
	for (int row = 0; row < rows; ++row)
		for (int col = 0; col < cols; ++col) {
			if (HasPathCore(matrix, rows, cols, row, col, path, path_len, visited))
				return true;
		}
	return false;
}


int main() {
	vector<vector<char>> matrix = {
		{'a','b','t','g'},
		{'c','f','c','s'},
		{'j','d','e','h'}
	};
	string path = "bfce";
	cout << HasPath(matrix, 3, 4, path) << endl;
	return 0;
}