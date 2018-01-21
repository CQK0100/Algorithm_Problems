//������ջʵ��һ���ӡ��������£���֧����β������ڵ�Ͷ���ͷ��ɾ���ڵ�Ĺ��ܡ�

/*
��������ջstack_one / stack_two.
��stack_one�������ݣ�ɾ������ʱ����stack_twoΪ�գ���stack_one
�е��������ε�����ѹ��stack_two��ջ����Ԫ�ؼ����ף���stack_two
��Ϊ�գ���ǰջ��Ԫ�ؼ�����
*/

#include<stack>

using std::stack;

template<typename T>
class StackQueue {
public:
	StackQueue() = default;
	void appendTail(const T& node);
	T deleteHead();
	~StackQueue() = default;
private:
	stack<T> stack_one;
	stack<T> stack_two;
};

template<typename T>
void StackQueue<T>::appendTail(const T & node)
{
	stack_one.push(node);
}

template<typename T>
T StackQueue<T>::deleteHead()
{
	if (stack_one.empty() && stack_two.empty())
		throw std::exception("The queue is empty.");
	if (stack_two.empty()) {
		while (!stack_one.empty()) {
			stack_two.push(stack_one.top());
			stack_one.pop();
		}
	}

	T node = stack_two.top();
	stack_two.pop();
	return node;
}
