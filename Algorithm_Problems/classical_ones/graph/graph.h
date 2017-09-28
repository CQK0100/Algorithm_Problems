#pragma once
#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<stack>
#include<queue>
#include<numeric>

using std::vector;
using std::stack;
using std::queue;
using std::cin;
using std::cout;
using std::endl;

enum class Flags
{
	unvisited,
	be_visiting,
	visited,
	finish_visit
};

template<typename Type>
class Edge final
{
	template<typename Type>
	friend class Graph;

public:
	explicit Edge(const size_t& start, const size_t& end = 0, const Type& value = Type())
		:start_idx(start), end_idx(end), value(value), flag(Flags::unvisited) {}
	size_t getEnd() const { return end_idx; }
	size_t getValue() const { return value; }
	~Edge() = default;
private:
	size_t start_idx;
	size_t end_idx;
	Type value;
	Flags flag; // search for next_edge unvisied edge.
};

template<typename Type>
class Graph
{
	using Node = vector<Edge<Type>>;
	int INFTY = (1 << 20);
public:
	Graph() :
		num_edges(0) {}
	explicit Graph(const size_t& size);
	~Graph() = default;
	void init();
	void showAdjMatrix() const;
	vector<vector<int>> getAdjMatrix() const;
	size_t getNumOfNodes() const;
	size_t getNumOfEdges() const;
	size_t getDegreeIn(const size_t& vertex_idx) const;
	size_t getDegreeOut(const size_t& vertex_idx) const;
	size_t getDegree(const size_t& vertex_idx) const;
	Type getVertexValue(const size_t& vertex_idx) const;

	// return iterator points to the specific edge.
	decltype(auto) findEdge(const size_t& vertex_idx, const size_t& end) const;

	void addEdge(const size_t& vertex_idx, const size_t& end, const Type& value);
	void removeEdge(const size_t& vertex_idx, const size_t& end);

	void DFS();
	void BFS(const size_t& vertex_idx);
	int MST(); // minimum spanning tree.
private:
	vector<Node> vertexs;
	size_t num_edges;
	void DFS_visit(const int& idx, vector<Flags>& flags);
	size_t findMinEdge(Node& node);
	int next_edge(const int& idx);
};

template<typename Type>
inline Graph<Type>::Graph(const size_t & size)
	:num_edges(0)
{
	assert(size > 0);
	vertexs.resize(size);
}

template<typename Type>
inline void Graph<Type>::init()
{
	for (auto& edges : vertexs)
		for (auto& edge : edges) {
			edge.flag = Flags::unvisited;
		}
}

template<typename Type>
inline void Graph<Type>::showAdjMatrix() const
{
	vector<vector<int>> matrix = getAdjMatrix();
	for (const auto& i : matrix) {
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}

template<typename Type>
inline vector<vector<int>> Graph<Type>::getAdjMatrix() const
{
	int size = vertexs.size();
	vector<vector<int>> matrix(size, vector<int>(size, 0));
	int i = 0;
	for (const auto& vertex : vertexs) {
		for (const auto& item : vertex) {
			matrix[i][item.end_idx] = item.value;
		}
		++i;
	}
	return matrix;
}

template<typename Type>
inline size_t Graph<Type>::getNumOfNodes() const
{
	return vertexs.size();
}

template<typename Type>
inline size_t Graph<Type>::getNumOfEdges() const
{
	return num_edges;
}

template<typename Type>
inline size_t Graph<Type>::getDegreeIn(const size_t & vertex_idx) const
{
	int degree_in = 0;
	int size = vertexs.size();
	for (int i = 0; i < size; ++i) {
		if (i == vertex_idx)
			continue;
		for (const auto& item : vertexs[i]) {
			if (item.end_idx == vertex_idx)
				++degree_in;
		}
	}
	return degree_in;
}

template<typename Type>
inline size_t Graph<Type>::getDegreeOut(const size_t & vertex_idx) const
{
	assert(vertex_idx >= 0 && vertex_idx < vertexs.size());
	return vertexs[vertex_idx].size();
}

template<typename Type>
inline size_t Graph<Type>::getDegree(const size_t & vertex_idx) const
{
	return getDegreeIn(vertex_idx) + getDegreeOut(vertex_idx);
}

template<typename Type>
inline Type Graph<Type>::getVertexValue(const size_t & vertex_idx) const
{
	if (!vertexs[vertex_idx].size()) {
		cout << "No Such Vertex." << endl;
		exit();
	}
	return vertexs[vertex_idx][0].value;
}

#endif // !GRAPH_MATRIX_H

template<typename Type>
inline decltype(auto) Graph<Type>::findEdge(const size_t & vertex_idx, const size_t & end) const
{
	assert(vertex_idx >= 0 && end >= 0);
	auto beg = vertexs[vertex_idx].begin(), ed = vertexs[vertex_idx].end();
	for (; beg != ed; ++beg) {
		if (beg->end_idx == end)
			return beg;
	}
	return ed;
}

template<typename Type>
inline void Graph<Type>::addEdge(const size_t & vertex_idx, const size_t & end, const Type & value)
{
	assert(vertex_idx >= 0 && end >= 0 && vertex_idx != end);
	if (vertex_idx > vertexs.size() || end > vertexs.size()) {
		vertexs.resize(max(vertex_idx, end) + 1);
	}
	vertexs[vertex_idx].push_back(Edge<Type>(vertex_idx, end, value));
	++num_edges;
}

template<typename Type>
inline void Graph<Type>::removeEdge(const size_t & vertex_idx, const size_t & end)
{
	assert(vertex_idx < vertexs.size() && end < vertexs.size());
	auto candi = findEdge(vertex_idx, end);
	if (candi != vertexs[vertex_idx])
		vertexs[vertex_idx].erase(candi);
}

template<typename Type>
inline void Graph<Type>::DFS()
{
	init();
	vector<Flags> flags(vertexs.size(), Flags::unvisited); // corresponding to the states of vertexs.
	cout << "Path is [always start from root index 0] :\n 0 ";
	int size = vertexs.size();
	for (int i = 0; i < size; ++i) {
		if (flags[i] == Flags::unvisited)
			DFS_visit(i, flags);
	}
	cout << endl;
}

template<typename Type>
inline void Graph<Type>::BFS(const size_t& vertex_idx)
{
	init();
	vector<int> distance(vertexs.size(), 0); // distance between root and node[index].
	vector<Flags> flags(vertexs.size(), Flags::unvisited);
	queue<int> queue;
	queue.push(vertex_idx);
	flags[vertex_idx] = Flags::be_visiting;
	int index;
	while (!queue.empty()) {
		int now = queue.front(); queue.pop();
		flags[now] = Flags::finish_visit;
		for (auto &edge : vertexs[now]) {
			index = edge.end_idx;
			if (flags[index] == Flags::unvisited) {
				flags[index] = Flags::be_visiting;
				distance[index] = distance[now] + 1;
				queue.push(index);
			}
		}
	}
	cout << "Distance between root and every node ." << endl;
	for (const auto& i : distance) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename Type>
inline int Graph<Type>::MST()  // return the sum value of MST [prim's algorithm].
{
	init();
	int size = vertexs.size();
	vector<Type> min_values(size, INFTY);  // [i] record min values of all edges connected to i_th vertex and (all-i) vertexs.
	vector<Type>  mst_edges(size);
	vector<Flags> flags(size, Flags::unvisited); // corresponding to the states of vertexs.
	int minv, idx;
	while (true) {
		minv = INFTY;
		idx = -1;
		for (int i = 0; i < size; ++i) {
			if (minv > min_values[i] && flags[i] != Flags::visited) { // find min value of all not-added vertexs.
				idx = i;
				minv = min_values[i];
			}
		}
		if (idx == -1)  // all vertexs have been travelled.
			break;
		flags[idx] = Flags::visited;
		for (int i = 0; i < size; ++i) {  // update min_values.
			if (flags[i] != Flags::visited) {  // find all not-added vertexs.
				if (min_values[i] > vertexs[idx][i].value) {
					min_values[i] = vertexs[idx][i].value;
					mst_edges[i] = vertexs[idx][i].value;
					flags[i] = Flags::be_visiting;
				}
			}
		}
	}

	Type sum = Type();
	for (auto& edge : mst_edges) {
		sum += edge;
	}
	return sum;
}

template<typename Type>
inline void Graph<Type>::DFS_visit(const int& idx, vector<Flags>& flags)
{
	stack<int> stack;
	stack.push(idx);  // push the index of node into stack, instead of the origin node.
	flags[idx] = Flags::be_visiting;
	while (!stack.empty()) {
		int node = stack.top();
		int next_vert = next_edge(node);
		if (next_vert != -1) {
			if (flags[next_vert] == Flags::unvisited) {
				flags[next_vert] = Flags::be_visiting;
				stack.push(next_vert);
				cout << next_vert << " ";
			}
		}
		else {
			stack.pop();
			flags[node] = Flags::visited;
		}

	}
}

template<typename Type>
inline size_t Graph<Type>::findMinEdge(Node & node)
{
	size_t min_idx = -1, size = node.size();
	int min = node[0].value;
	for (size_t i = 0; i < size; ++i) {
		if (node[i].value < min&&node[i].flag != Flags::visited) {
			min = node[i].value;
			min_idx = i;
		}
	}
	if (min_idx != -1)
		node[min_idx].flag = Flags::visited;
	return min_idx;
}

template<typename Type>
inline int Graph<Type>::next_edge(const int& idx)
{
	for (auto& i : vertexs[idx]) {
		if (i.flag == Flags::unvisited) {
			i.flag = Flags::finish_visit;
			return i.end_idx;
		}
	}
	return -1;
}
