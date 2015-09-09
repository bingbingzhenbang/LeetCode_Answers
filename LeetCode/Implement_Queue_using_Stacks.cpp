//Implement the following operations of a queue using stacks. 
//	push(x) -- Push element x to the back of queue. 
//	pop() -- Removes the element from in front of queue. 
//	peek() -- Get the front element. 
//	empty() -- Return whether the queue is empty. 
//Notes:
//You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//	Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//	You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

#include <stack>

using namespace std;

class Queue
{
public:
	// Push element x to the back of queue.
	void push(int x) 
	{
		if (empty())
			m_stack.push(x);
		else
		{
			int y = m_stack.top();
			m_stack.pop();
			push(x);
			m_stack.push(y);
		}
	}

	// Removes the element from in front of queue.
	void pop(void) 
	{
		m_stack.pop();
	}

	// Get the front element.
	int peek(void)
	{
		return m_stack.top();
	}

	// Return whether the queue is empty.
	bool empty(void)
	{
		return m_stack.empty();
	}

private:
	stack<int> m_stack;
};

void testQueue()
{
	Queue q1;
	q1.push(1);
	int rt = q1.peek();
}