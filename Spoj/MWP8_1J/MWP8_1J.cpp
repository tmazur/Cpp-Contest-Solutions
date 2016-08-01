#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const bool debug = false;
typedef std::pair<long long, long long> Point;
typedef std::vector<Point> Polygon;
Point points[2500] = {};
std::pair<int, int> polygons[834] = {}; // defines <start, end> range in points array that define a polygon
enum Orientation
{
	colinear = 0,
	clockwise,
	counterclockwise
};

Point sortingPivot; // reference point for sorting

// square of distance between p1 and p2
inline long long distSq(const Point & p1, const Point & p2)
{
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

Orientation orientation(const Point & p, const Point & q, const Point & r)
{
	long long val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);

	if (val == 0) return colinear;
	return (val > 0)? clockwise: counterclockwise;
}

// Sort points with respect to the first point (larger polar angle in counterclockwise direction comes first).
bool compare(const Point & p1, const Point & p2)
{
   Orientation o = orientation(sortingPivot, p1, p2);
   if (o == colinear)
     return distSq(sortingPivot, p2) >= distSq(sortingPivot, p1);
   return o == counterclockwise;
}

double area(Point points[], const int start, const int end) {
    double area = 0.0;
    for(int i = start; i < end; ++i)
	{
		if(debug) cout << "calc: " << points[i].first << " * " << points[i+1].second << " - " << points[i].second << " * " << points[i+1].first << endl;
        area += points[i].first * points[i+1].second - points[i].second * points[i+1].first;
		if(debug) cout << i << "area: " << area << " ";
    }
	area += points[end].first * points[start].second - points[start].first * points[end].second;
	if(debug) cout << "final calc: " << points[end].first << " * " << points[start].second << " - " << points[end].second << " * " << points[start].first << endl;
	area/=2.0;
	if(debug) cout << "final area: " << area << endl;
	if(area<0) return -area;
    return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long polygonsCount;
	cin >> polygonsCount;

	unsigned long pointCount = 0;
	unsigned long ymin = ULONG_MAX, yminIdx = 0; // store bottom-most left-most point
	for(unsigned long t = 0; t < polygonsCount; ++t)
	{
		unsigned long vertexes;
		cin >> vertexes;

		unsigned long x,y;
		polygons[t] = make_pair(pointCount, pointCount + vertexes - 1);

		for(unsigned long i = 0; i < vertexes; ++i) {
			cin >> x >> y;

			// Pick the bottom-most or chose the left most point in case of tie
			if ((y < ymin) || (ymin == y && x < points[yminIdx].first))
			{
				ymin = y;
				yminIdx = pointCount;
			}

			points[pointCount++] = make_pair(x, y);
		}
	}

	double areaOfAllLots = 0.0;
	for(unsigned long t = 0; t < polygonsCount; ++t)
	{
		areaOfAllLots += area(points, polygons[t].first,  polygons[t].second);
	}

	// Place the bottom-most point at first position
	swap(points[0], points[yminIdx]);

	sortingPivot = points[0];
	sort(points + 1, points + pointCount, compare);

	// for colinear points, remove all middle points
	int mSize = 1;
	for (int i = 1; i < pointCount; i++)
	{
		// skip middle points
		while (i < pointCount-1 && orientation(sortingPivot, points[i], points[i+1]) == colinear)
		i++;

		points[mSize++] = points[i];
	}

	vector<Point> hull;
	hull.push_back(points[0]);
	hull.push_back(points[1]);
	hull.push_back(points[2]);

	// Process remaining n-3 points
	for (int i = 3; i < mSize; i++)
	{
		// Keep removing last point while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
		while (orientation(hull[hull.size()-2], hull[hull.size()-1], points[i]) != counterclockwise)
		{
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	double areaOfHull = area((Point*)&hull[0], 0, hull.size()-1);
	cout.precision(6);
	cout << std::fixed << areaOfHull-areaOfAllLots << '\n';

	if(debug)
	{
		cout << "Total points " << pointCount << endl;
		for(unsigned long t = 0; t < polygonsCount; ++t)
		{
			int startIdx = polygons[t].first, endIdx = polygons[t].second;
			cout << "Polygon #" << t+1 << " <" << polygons[t].first << ", " << polygons[t].second << ">: ";
			while(startIdx <= endIdx)
			{
				cout << "(" << points[startIdx].first << ", " << points[startIdx].second << ") ";
				++startIdx;
			}
			cout << " area=" << area(points, polygons[t].first,  polygons[t].second);
			cout << endl;
		}
		cout << "area of all lots: " << areaOfAllLots << "; area of hull: "<<areaOfHull << "; area need to buy=" << areaOfHull-areaOfAllLots << endl;

		// cout << "Hull: ";
		// for(auto &x : hull)
		// {
		// 	cout << "(" << x.first << ", " << x.second << ") ";
		// }
		cout << endl;
	}
	return 0;
}
