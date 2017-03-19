//Priority Queue
//����HeapSortʵ��
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define INFTY (1<<30)
using namespace std;

//ȷ����/��/�ҽ����±�
int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }


// *REMARK:���±�i=1��ʼ�洢
void BuildCBT(vector<int>& CBT, int N) {
	CBT.resize(2 * N + 2);
	cout << "Input the nodes : " << endl;
	for (int i = 1; i <= N; ++i) { cin >> CBT[i]; }
}

void MaxHeapify(vector<int>& CBT, int N, int i) {
	int L = left(i); int R = right(i);
	int largest;
	//����/����/���ӽ����ѡ�����Ľ��
	if (L <= N&&CBT[L] > CBT[i])largest = L;
	else largest = i;
	if (R <= N&&CBT[R] > CBT[largest])largest = R;
	if (largest != i) {//i���ӽ��ֵ����
		std::swap(CBT[i], CBT[largest]);
		MaxHeapify(CBT, N, largest);
	}
}

void BuildMaxHeap(vector<int>& BCT, int N) {
	for (int i = N / 2; i >= 1; --i) {
		MaxHeapify(BCT, N, i);
	}
}

void HeapIncreaseKey(vector<int>& CBT, int N, const int key) {
	if (key < CBT[N]) { cout << "Error Inputting! \n"; return; }
	CBT[N] = key;
	while (N > 1 && CBT[parent(N)] < CBT[N]) {
		std::swap(CBT[parent(N)], CBT[N]);
		N = parent(N);
	}
}

int ExtractMax(vector<int>& CBT, int N) {
	if (N < 1) { return -INFTY; }
	int maxitem = CBT[1];
	CBT[1] = CBT[N];
	--N;
	MaxHeapify(CBT, N, 1);
	return maxitem;
}

void Insert(const int key, vector<int>& CBT, int N) {
	++N;
	CBT[N] = -INFTY;
	HeapIncreaseKey(CBT, N, key);
}
int main() {
	int key;
	string cmd;
	vector<int> CBT;
	int N;
	cout << "Input the number of CBT nodes :";
	cin >> N;
	BuildCBT(CBT, N);
	cout << "Input the commands , \'end\' to exit " << endl;
	while (true) {
		cin >> cmd;
		if (cmd == "end")break;
		if (cmd == "insert") {
			cin >> key;
			Insert(key, CBT, N);
		}
		else if (cmd == "extract") {
			cout << "Extract and delete the max element " << ExtractMax(CBT, N) << endl;
		}
		else break;
	}
	return 0;
}

