// GrahamScan.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <math.h>

struct Point {

	Point() {
		//default constructor
		this->x = 0.0;
		this->y = 0.0;
	}

	Point(float inX, float inY) : x(inX), y(inY) {
		//initialization list
	}

	Point & operator=(const Point & p) {
		this->x = p.x;
		this->y = p.y;
		return *this;
	}

	float x;
	float y;
};

static Point base;

void readPointsIntoVector(const std::string & s, std::vector<Point> & points) {

	std::ifstream infile;
	infile.open(s);
	std::string line;

	float x;
	float y;

	while (true) {

		std::getline(infile, line);
		std::stringstream pointStream(line);
		if (infile.eof())
			break;

		pointStream >> x;
		pointStream >> y;
		//std::cout << "x: " << x << " Y: " << y << std::endl;
		points.push_back(Point(x, y));
	}


}

void swap(std::vector<Point> & points, int i, int j) {
	Point temp = points[i];
	points[i] = points[j];
	points[j] = temp;
}

int findMinYCoordinate(std::vector<Point> & points) {

	int minYIndex = 0;

	for (int i = 1; i < (int)points.size(); i++) {
		if (points[i].y < points[minYIndex].y || (points[i].y == points[minYIndex].y && points[i].x < points[minYIndex].x))
			minYIndex = i;
	}

	base = points[minYIndex];
	swap(points, 0, minYIndex);
	return minYIndex;
}

float crossProduct(Point p0, Point & p1, Point & p2) {
	float crossProduct = ((p1.x - p0.x) * (p2.y - p0.y)) - ((p2.x - p0.x) * (p1.y - p0.y));
	//float crossProduct = (p1.y - p0.y) * (p2.x - p1.x) - (p1.x - p0.x) * (p2.y - p1.y);
	return crossProduct;
}

bool operator<(Point & p1, Point & p2) {

	if (crossProduct(base, p1, p2) > 0.0) {
		return true;
	}

	return false;
}

float squareDist(Point & p1, Point & p2) {
	return ((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}



void clearDuplicateAngles(std::vector<Point> & pts) {
	for (int i = 1; i < (int)pts.size() - 1; i++){
		if (crossProduct(base, pts[i], pts[i + 1]) == 0.0) {
			if (squareDist(base, pts[i]) > squareDist(base, pts[i+1]))
				pts.erase(pts.begin() + i + 1);
			else
				pts.erase(pts.begin() + i);
		}
	}
}

void Merge(std::vector<Point> & points, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	Point * left = new Point[n1];
	Point * right = new Point[n2];

	for (int i = 0; i < n1; i++)
		left[i] = points[p + i];
	for (int j = 0; j < n2; j++)
		right[j] = points[q + j + 1];

	int i = 0;
	int j = 0;
	int k = p;

	while (i < n1 && j < n2) {
		if (left[i] < right[j])
			points[k] = left[i++];
		else
			points[k] = right[j++];

		k++;
	}

	while (i < n1)
	{
		points[k] = left[i++];
		k++;
	}

	while (j < n2)
	{
		points[k] = right[j++];
		k++;
	}
}

void MergeSort(std::vector<Point> & points, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(points, p, q);
		MergeSort(points, q + 1, r);
		Merge(points, p, q, r);
	}
}

Point nextToTop(std::stack<Point> & stack)
{
	Point top = stack.top();
	stack.pop();
	Point nextToTop = stack.top();
	stack.push(top);
	return nextToTop;
}

std::stack<Point> convexHull(std::vector<Point> & points) {

	std::stack<Point> stackPoints;
	int m = points.size();
	if (m < 3) {
		std::cout << "No convex hull, returning all points" << std::endl;
		for (int i = 0; i < (int)points.size(); i++)
			stackPoints.push(points[i]);
		return stackPoints;
	}

	stackPoints.push(points[0]); 
	stackPoints.push(points[1]);
	stackPoints.push(points[2]);

	for (int i = 3; i < m; i++) {
		while (crossProduct(nextToTop(stackPoints), stackPoints.top(), points[i]) <= 0.0)
			stackPoints.pop();

		stackPoints.push(points[i]);
	}

	return stackPoints;
}

std::vector<Point> stackToVector(std::stack<Point> & points) {

	std::vector<Point> vect;

	std::stack<Point> temp;

	while (!points.empty()) {
		Point p = points.top();
		temp.push(p);
		points.pop();
	}

	while (!temp.empty()) {
		Point p = temp.top();
		vect.push_back(p);
		temp.pop();
	}

	return vect;
}

void findConvexHulls(std::vector<std::string> files) {

	for (std::string & s : files) {
		std::vector<Point> points;

		readPointsIntoVector(s, points);
		int index = findMinYCoordinate(points);
		MergeSort(points, 1, points.size() - 1);
		clearDuplicateAngles(points);

		std::stack<Point> result = convexHull(points);
		std::vector<Point> vectorResult = stackToVector(result);

		std::cout << "Convex hull: for file " << s << std::endl;
		for (Point & p : vectorResult)
		{
			std::cout << "Point: " << "(" << p.x << ", " << p.y << ")" << std::endl;
		}
		std::cout << std::endl;


	}
}

int main()
{
	std::vector<std::string> files;
	files.push_back("case1.txt");
	files.push_back("case2.txt");
	files.push_back("case3.txt");
	files.push_back("case4.txt");
	files.push_back("case5.txt");
	files.push_back("case6.txt");

	findConvexHulls(files);

	/*std::string s = "case1.txt";
	std::vector<Point> points;

	readPointsIntoVector(s, points);
	int index = findMinYCoordinate(points);
	MergeSort(points, 1, points.size() - 1);
	clearDuplicateAngles(points);

	std::stack<Point> result = convexHull(points);
	std::vector<Point> vectorResult = stackToVector(result);

	std::cout << "Convex hull: " << std::endl;
	for (Point & p : vectorResult)
	{		
		std::cout << "Point: " << "(" << p.x << ", " << p.y << ")" << std::endl;
	}
	system("PAUSE");*/

    return 0;
}

