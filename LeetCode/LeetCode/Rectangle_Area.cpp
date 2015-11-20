//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

#include <algorithm>

using namespace std;

int rectangleArea(int A, int B, int C, int D)
{
	return (D - B) * (C - A);
}

int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int leftBottom_x = max(A, E);
	int leftBottom_y = max(B, F);
	int rightUp_x = min(C, G);
	int rightUp_y = min(D, H);
	if (leftBottom_x > rightUp_x)
		return 0;
	if (leftBottom_y > rightUp_y)
		return 0;
	return rectangleArea(leftBottom_x, leftBottom_y, rightUp_x, rightUp_y);
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area1 = rectangleArea(A, B, C, D);
	int area2 = rectangleArea(E, F, G, H);
	int overlap = overlapArea(A, B, C, D, E, F, G, H);
	return area1 + area2 - overlap;
}

void testComputeArea()
{
	//int rt = computeArea(-3,0,3,4,0,-1,9,2);
	int rt = computeArea(-2, -2, 2, 2, 3, 3, 4, 4);
}