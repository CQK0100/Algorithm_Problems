//����������ʵ��һ��ջ���������£���֧�ֽ�ջ�ͳ�ջ������

/*
��ջ��
�������о�Ϊ�գ�������һ���С�
һ�����зǿգ���һ���գ���ǿյĶ��С�
��ջ��
�ǿն��е�Ԫ�����ν�����һ���ն��У�ʣ���һ��Ԫ�أ����䵯����
*/

#include<queue>

using std::queue;

template<typename T>
class QueueStack {
public:
	QueueStack() = default;
	void push(const T& node);
	T pop();
	~QueueStack() = default;
private:
	queue<T> queue_one;
	queue<T> queue_two;
};

template<typename T>
void QueueStack<T>::push(const T& node)
{
	if (queue_one.empty() && queue_two.empty())
		queue_one.push(node);
	else if (queue_one.empty() && !queue_two.empty())
		queue_two.push(node);
	else if (!queue_one.empty() && queue_two.empty())
		queue_one.push(node);
	else
		throw std::exception("Two queues can not be not empty at the same time.");
}

template<typename T>
T QueueStack<T>::pop()
{
	if (queue_one.empty() && queue_two.empty())
		throw std::exception("The stack is empty.");
	else if (queue_one.empty() && !queue_two.empty()) {
		while (queue_two.size() > 1) {
			queue_one.push(queue_two.front());
		}
		T node = queue_two.front();
		queue_two.pop();
		return node;
	}
	else if (!queue_one.empty() && queue_two.empty()) {
		while (queue_one.size() > 1) {
			queue_two.push(queue_one.front());
		}
		T node = queue_one.front();
		queue_one.pop();
		return node;
	}	
}


