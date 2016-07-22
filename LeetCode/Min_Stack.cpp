//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.

#include <stack>

using namespace std;

class MinStack
{
public:
	/** initialize your data structure here. */
	MinStack() : m_min(INT_MAX)
	{
	}

	void push(int x)
	{
		if (x <= m_min)
		{
			m_stack.push(m_min);
			m_min = x;
		}
		m_stack.push(x);
	}

	void pop()
	{
		if (m_min == m_stack.top())
		{
			m_stack.pop();
			m_min = m_stack.top();
			m_stack.pop();
		}
		else
			m_stack.pop();
	}

	int top()
	{
		return m_stack.top();
	}

	int getMin()
	{
		if (m_stack.empty())
			return INT_MAX;
		return m_min;
	}

private:
	stack<int> m_stack;
	int m_min;
};
