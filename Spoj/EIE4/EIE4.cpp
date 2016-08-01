#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const bool debug = false;

inline bool isTrue(const string& s)
{
	return s.compare("True") == 0;
}

string data[1000000];

int main() {
	ios_base::sync_with_stdio(false);

	string tmp, naText;
	cin >> tmp;
	bool printRowNum = isTrue(tmp);
	cin >> tmp;
	bool printHeader = isTrue(tmp);
	char delimiter;
	cin >> naText >> delimiter;
	cin.ignore(1, '\n');

	string header;
	getline(cin, header);
	int columnsCount = 1 + std::count(header.begin(), header.end(), delimiter);

	unsigned long* columnsSize = new unsigned long[columnsCount];
	std::fill(columnsSize, columnsSize+columnsCount, 0);

	// read in data
	unsigned int dataElementCount = 0;
	while(std::getline(cin, data[dataElementCount], dataElementCount%columnsCount==(columnsCount-1) ? '\n' : delimiter))
	{
		unsigned long column = dataElementCount%columnsCount;
		if(data[dataElementCount] == "")
		{
			data[dataElementCount] = naText;
		}
		columnsSize[column] = max(columnsSize[column], (unsigned long)data[dataElementCount].size());
		++dataElementCount;
	}

	unsigned int rowCounterStrLength = 1, rowNum = dataElementCount/columnsCount;
	if(rowNum > 999999)
		rowCounterStrLength = 7;
	else if(rowNum > 99999)
		rowCounterStrLength = 6;
	else if(rowNum > 9999)
		rowCounterStrLength = 5;
	else if(rowNum > 999)
		rowCounterStrLength = 4;
	else if(rowNum > 99)
		rowCounterStrLength = 3;
	else if(rowNum > 9)
		rowCounterStrLength = 2;

	if(debug)
	{
		cout << "Print row num = " << printRowNum << "; Print header = " << printHeader << "; Delimiter=" << delimiter << endl;
		cout << "ColumnsCount=" << columnsCount << "; dataElementCount=" << dataElementCount << endl;
		cout << "DataCtrStrLength=" << rowCounterStrLength << "; Columns sizes: ";
		for(int i = 0; i < columnsCount; ++i)
		{
			cout << columnsSize[i] << ", ";
		}
		cout << endl;
		for(int i = 0; i < dataElementCount; ++i)
		{
			// cout << i << ":"<<data[i] << endl;
		}
	}

	if(printHeader)
	{
		unsigned long rowNumPadding = 0;
		if(printRowNum)
			rowNumPadding = rowCounterStrLength + 2;

		stringstream ss(header);
		for(unsigned long i = 0; i < columnsCount; ++i)
		{
			getline(ss,tmp, i==columnsCount-1?'\n':delimiter);
			if(tmp.size() > columnsSize[i])
				columnsSize[i] = tmp.size();
			unsigned long padding = columnsSize[i];
			if(i==0) padding += rowNumPadding;
			else padding += 2;
			cout << setw(padding) << tmp;
		}
		cout << '\n';
	}

	for(unsigned long i = 0; i < dataElementCount; ++i)
	{
		unsigned long column = i%columnsCount;
		int padding = 2;
		if(column == 0)
		{
			if(printRowNum)
			{
				cout << setw(rowCounterStrLength) << (i/columnsCount)+1;
			}
			else
			{
				padding = 0;
			}
		}

		cout << setw(padding+columnsSize[column]) << data[i];
		if(column == columnsCount-1)
			cout << '\n';
	}

	delete[] columnsSize;
	return 0;
}
