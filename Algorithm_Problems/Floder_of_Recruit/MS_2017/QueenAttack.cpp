/*
����
There are N queens in an infinite chessboard.We say two queens may attack each other if they are in the same vertical line,
horizontal line or diagonal line even if there are other queens sitting between them.

Now given the positions of the queens, find out how many pairs may attack each other ?

����
The first line contains an integer N.

Then N lines follow.Each line contains 2 integers Ri and Ci indicating there is a queen in the Ri - th row and Ci - th column.

No two queens share the same position.

For 80 % of the data, 1 <= N <= 1000

For 100 % of the data, 1 <= N <= 100000, 0 <= Ri, Ci <= 1000000000

���
One integer, the number of pairs may attack each other.

��������
5
1 1
2 2
3 3
1 3
3 1
�������

10

*/

#include<iostream>
#include<map>
using namespace std;

map<int, int > row;				//��
map<int, int > column;			//��		
map<int, int > leftAngle;			//��Խ� "/"
map<int, int > rightAngle;			//�ҶԽ� "\"

//ĳ�е�����Ϊn������1+2+3...(n-1)��Quenn .

int main() {
	int n; cin >> n;
	int r, c;
	long long int result = 0;
	for (int i = 0; i < n; ++i) {
		cin >> r >> c;
		result += row[r]++;
		result += column[c]++;
		result += leftAngle[r + c]++;
		result += rightAngle[c - r]++;
	}
	cout << result << endl;
	return 0;
}
