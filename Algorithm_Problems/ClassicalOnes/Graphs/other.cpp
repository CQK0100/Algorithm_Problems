// C++ code
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>      // for std::setw()

class Graph {
private:
	int num_vertex;
	std::vector< std::list<int> > AdjList;
	int *color,             // 0:white, 1:gray, 2:black
		*predecessor,
		*discover,
		*finish;
public:
	Graph() :num_vertex(0) {};
	Graph(int N) :num_vertex(N) {
		// initialize Adj List
		AdjList.resize(num_vertex);
	};
	void AddEdgeList(int from, int to);
	void BFS(int Start);    // ���xҊ��һƪ����
	void DFS(int Start);
	void DFSVisit(int vertex, int &time);
};

void Graph::DFS(int Start) {
	color = new int[num_vertex];           // ����ӛ���wλ��
	discover = new int[num_vertex];
	finish = new int[num_vertex];
	predecessor = new int[num_vertex];

	int time = 0;                          // ��ʼ��, ��D��(b)
	for (int i = 0; i < num_vertex; i++) {
		color[i] = 0;
		discover[i] = 0;
		finish[i] = 0;
		predecessor[i] = -1;
	}

	int i = Start;
	for (int j = 0; j < num_vertex; j++) { // �z������Graph�е�vertex��Ҫ���ь���
		if (color[i] == 0) {               // ��vertex���ǰ�ɫ, �t�M����ԓvertex�������c֮�ь�
			DFSVisit(i, time);
		}
		i = j;                             // j����AdjList�������^һ��, �_������vertex�����ь��^
	}
}

void Graph::DFSVisit(int vertex, int &time) {   // һ����vertex���l�F�����ǰ�ɫ, ���M��DFSVisit()
	color[vertex] = 1;                         // ��vertex�T�ɻ�ɫ
	discover[vertex] = ++time;                 // ����vertex��discover�r�g
	for (std::list<int>::iterator itr = AdjList[vertex].begin();   // for loop����̫�L
		itr != AdjList[vertex].end(); itr++) {                    // �ֳɃɶ�
		if (color[*itr] == 0) {                // ���ь�����ɫ��vertex
			predecessor[*itr] = vertex;        // ������predecessor
			DFSVisit(*itr, time);              // �������������µ��ь����c, �M���µ�DFSVisit()
		}
	}
	color[vertex] = 2;                         // ��vertex�ѽ��ь��^�����c֮���B��vertex��, ����T��
	finish[vertex] = ++time;                   // �K����finish�r�g
}

int main() {
	// ���xһ�����а˂�vertex��Graph
	Graph g2(8);
	// ������D��֮Graph
	g2.AddEdgeList(0, 1); g2.AddEdgeList(0, 2);
	g2.AddEdgeList(1, 3);
	g2.AddEdgeList(2, 1); g2.AddEdgeList(2, 5);
	g2.AddEdgeList(3, 4); g2.AddEdgeList(3, 5);
	// AdjList[4] is empty
	g2.AddEdgeList(5, 1);
	g2.AddEdgeList(6, 4); g2.AddEdgeList(6, 7);
	g2.AddEdgeList(7, 6);

	g2.DFS(0);    // ��vertex(0), Ҳ����vertex(A����DFS()�����c

	return 0;
}