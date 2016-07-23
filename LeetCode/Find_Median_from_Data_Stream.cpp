//Median is the middle value in an ordered integer list.If the size of the list is even, there is no middle value.So the median is the mean of the two middle value.
//
//Examples:
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations :
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//For example :
//
//add(1)
//add(2)
//findMedian() -> 1.5
//add(3)
//findMedian() -> 2

#include <queue>

using namespace std;

class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num)
	{
		int smallnum = m_smallpart.size(), largenum = m_largepart.size();
		if (smallnum == largenum)
		{
			if (m_smallpart.empty() || num < m_largepart.top())
				m_smallpart.push(num);
			else
			{
				m_smallpart.push(m_largepart.top());
				m_largepart.pop();
				m_largepart.push(num);
			}
		}
		else
		{
			if (num < m_smallpart.top())
			{
				m_largepart.push(m_smallpart.top());
				m_smallpart.pop();
				m_smallpart.push(num);
			}
			else
				m_largepart.push(num);
		}
	}

	// Returns the median of current data stream
	double findMedian()
	{
		int smallnum = m_smallpart.size(), largenum = m_largepart.size();
		if (smallnum == largenum)
			return ((double)m_smallpart.top() + (double)m_largepart.top()) / 2;
		else
			return (double)m_smallpart.top();
	}

private:
	priority_queue<int, vector<int> > m_smallpart;
	priority_queue<int, vector<int>, greater<int> > m_largepart;
};