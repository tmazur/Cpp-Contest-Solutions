#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

inline bool startsWith( const string &str, const string &prefix )
{
    return str.size() >= prefix.size() &&
           std::equal(prefix.begin(), prefix.end(), str.begin());
}

std::set<string> commands;
const bool debug = false;
const int MAX_COMMAND_LEN = 8;

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long ops, listLimit;
	cin >> ops >> listLimit;

	char operation[MAX_COMMAND_LEN+1];
	string command;
	for(unsigned long i = 0; i < ops; ++i)
	{
		cin >> operation >> command;
		if(operation[0] == 'a')
		{
			// add
			commands.insert(command);
		}
		else if(operation[0] == 'r')
		{
			// remove
			commands.erase(command);
		}
		else if(operation[0] == 'l')
		{
			// list
			stringstream ss;
			ss << command << ": ";
			// printf("%s: ", command.c_str());
			auto it = commands.lower_bound(command);
			unsigned long matchCount = 0;
			while(it != commands.end() && startsWith(*it, command))
			{
				if(matchCount < listLimit)
				{
					if(0 == matchCount)
					{
						ss << *it;
						// printf("%s", it->c_str());
					}
					else
					{
						ss << " " << *it;
						// printf(" %s", it->c_str());
					}
					++matchCount;
					++it;
				}
				else
				{
					char x = command.back();
					command.pop_back();
					command.push_back(x+1);
					auto it2 = commands.lower_bound(command);
					// cout << "xxx " << command << ", " << std::distance(it, it2) << " xxx";
					matchCount += std::distance(it, it2);
					break;
				}
			}
			if(matchCount > listLimit)
			{
				// printf(" and %d other(s)\n", matchCount-listLimit);
				ss << " and " << matchCount-listLimit << " other(s)\n";
			}
			else
			{
				// printf("\n");
				ss << "\n";
			}
			cout << ss.rdbuf();
			// printf("%s", ss.str());
		}
		else
		{
			abort();
		}

	}
	return 0;
}
