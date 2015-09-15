//Implement the following operations of a stack using queues. 
//	push(x) -- Push element x onto stack. 
//	pop() -- Removes the element on top of the stack. 
//	top() -- Get the top element. 
//	empty() -- Return whether the stack is empty. 
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
//	Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//	You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Stack {
public:
	Stack() : m_top(1), m_queues(2){}

	// Push element x onto stack.
	void push(int x)
	{
		if (!m_queues[m_top].empty())
		{
			int y = m_queues[m_top].front();
			m_queues[m_top].pop();
			m_queues[1- m_top].push(y);
		}
		m_queues[m_top].push(x);
	}

	// Removes the element on top of the stack.
	void pop()
	{
		m_queues[m_top].pop();
		while (m_queues[1 - m_top].size() > 1)
		{
			int y = m_queues[1 - m_top].front();
			m_queues[1 - m_top].pop();
			m_queues[m_top].push(y);
		}
		m_top = 1 - m_top;
	}

	// Get the top element.
	int top()
	{
		return m_queues[m_top].front();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return m_queues[0].empty() && m_queues[1].empty();
	}
private:
	int m_top;
	vector< queue<int> > m_queues;
};

void testStack()
{
	Stack s1;
	for (int i = 1; i < 10; ++i)
		s1.push(i);
	while (!s1.empty())
	{
		int x = s1.top();
		cout<<x<<endl;
		s1.pop();
	}
}