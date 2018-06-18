#include<vector>
#include<memory>
#include<unordered_map>

template<typename T>
class DisjointNode {

	using NodePtr = std::shared_ptr<DisjointNode>;

public:
	DisjointNode(T&& val)
		:value_(std::forward<T>(val)), depth_(0), parent_(nullptr) {}

	void setParent(const NodePtr& p) {
		parent_.reset();
		parent_ = p;
	}

	NodePtr getParent() const {
		return parent_.lock();
	}

	T getValue() const {
		return value_;
	}

	size_t getDepth() const {
		return depth_;
	}

	void increaseDepth() {
		++depth_;
	}

private:
	std::weak_ptr<DisjointNode<T>> parent_;
	T value_;
	size_t depth_;
};

// ���鼯����ʵ��
template<typename T>
class DisjointSet {

	using NodeMap = std::unordered_map<T, std::shared_ptr<DisjointNode<T>>>;
	using NodePtr = DisjointNode::NodePtr;

public:

	// ����һ��ֻ��x�ļ���, x��Ӧ�����������κ�һ��������.
	void makeSet(const T& ele) {
		node_map_.clear();
		node_map_.insert({ ele,std::make_shared<T>(ele) });
	}

	// ��Ԫ��x���ڵļ���S(x), ��Ԫ��y���ڵļ���S(y)���кϲ�, ��S(x) != S(y).
	void setUnion(const int& x, const int& y) {
		int px = findSet(x); int py = findSet(y);
		if (px != py)
			path[py] = px;
	}

	NodePtr findSet(const NodePtr& ptr) {
		auto parent = ptr->getParent();
		std::vector<NodePtr> path;
		while (parent->getParent() != nullptr) {
			// һֱ�ҵ����ڵ�Ϊֹ
			path.push_back(parent);
			parent = parent->getParent();
		}

		for (auto&& each : path)
			each->setParent(parent);
		return parent;
	}

	// ����Ԫ��x���ڼ��ϵĴ���.
	int findSet(const T& ele) {
		
	}

private:
	NodeMap node_map_;
};