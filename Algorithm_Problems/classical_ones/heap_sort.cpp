#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//ȷ����/��/�ҽ����±�
int parent(const int& i) { return i / 2; }
int left_child(const int& i) { return 2 * i; }
int right_child(const int& i) { return 2 * i + 1; }

// ���±�i = 1��ʼ�洢
void BuildCBT(vector<int>& CBT, const int& N) {
	CBT.resize(2 * N + 2);
	cout << "Input the nodes : " << endl;
	for (int i = 1; i <= N; ++i) {
		cin >> CBT[i];
	}
}

void maxheapify(vector<int>& CBT, int N, int i) {
	int L = left_child(i); int R = right_child(i);
	int largest;
	//����/����/���ӽ����ѡ�����Ľ��
	if (L <= N&&CBT[L] > CBT[i])
		largest = L;
	else
		largest = i;
	if (R <= N&&CBT[R] > CBT[largest])
		largest = R;
	if (largest != i) {//i���ӽ��ֵ����
		std::swap(CBT[i], CBT[largest]);
		maxheapify(CBT, N, largest);
	}
}

void build_maxheap(vector<int>& BCT, int N) {
	for (int i = N / 2; i >= 1; --i) {
		maxheapify(BCT, N, i);
	}
}

void PrintHeap(const vector<int> CBT, int N) {
	for (int i = 1; i <= N; ++i)
		cout << CBT[i] << " ";
	cout << endl;
}
int main() {
	int N;
	cout << "Input the number of CBT nodes :";
	cin >> N;
	vector<int> CBT;
	BuildCBT(CBT, N);
	build_maxheap(CBT, N);
	PrintHeap(CBT, N);
	return 0;
}
