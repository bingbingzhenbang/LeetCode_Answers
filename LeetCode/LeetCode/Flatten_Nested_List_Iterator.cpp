//Given a nested list of integers, implement an iterator to flatten it.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Example 1:
//Given the list[[1, 1], 2, [1, 1]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 1, 2, 1, 1].
//
//
//Example 2 :
//Given the list[1, [4, [6]]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 4, 6].
/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/

#include <vector>
#include <stack>
#include <utility>

using namespace std;

class NestedInteger
{
   public:
	   // Return true if this NestedInteger holds a single integer, rather than a nested list.
	   bool isInteger() const
	   {
		   return false;
	   }
	   // Return the single integer that this NestedInteger holds, if it holds a single integer
	   // The result is undefined if this NestedInteger holds a nested list
	   int getInteger() const
	   {
		   return 0;
	   }
	   // Return the nested list that this NestedInteger holds, if it holds a nested list
	   // The result is undefined if this NestedInteger holds a single integer
	   const vector<NestedInteger> &getList() const;
};

static const vector<NestedInteger> g_vec = vector<NestedInteger>();

const vector<NestedInteger>& NestedInteger::getList() const
{
	return g_vec;
}

class NestedIterator
{
public:
	NestedIterator(vector<NestedInteger> &nestedList)
		: m_nestedList(nestedList), m_nextInteger(0)
	{
		m_listStack.push(pair<int, const vector<NestedInteger> *>(0, &m_nestedList));
	}

	int next()
	{
		return m_nextInteger;
	}

	bool hasNext()
	{
		if (m_listStack.empty())
			return false;
		while (!m_listStack.empty())
		{
			pair<int, const vector<NestedInteger> *> &top_pair = m_listStack.top();
			int current_index = top_pair.first;
			const vector<NestedInteger> *current_vec = top_pair.second;
			if (current_index == current_vec->size())
				m_listStack.pop();
			else
			{
				const NestedInteger &current_nested = current_vec->at(current_index);
				++top_pair.first;
				if (current_nested.isInteger())
				{
					m_nextInteger = current_nested.getInteger();
					return true;
				}
				else
					m_listStack.push(pair<int, const vector<NestedInteger> *>(0, &current_nested.getList()));
			}
		}
		return false;
	}

private:
	vector<NestedInteger> &m_nestedList;
	stack< pair<int, const vector<NestedInteger> *> > m_listStack;
	int m_nextInteger;
};