#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

template<typename T>
inline bool ioInt(T *a)
{
    register char c=0;
    while (c<33 && c != EOF) c=getchar_unlocked();
	if(c==EOF)
		return false;
    *a=0;
    while (c > 47 && c < 58)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
	return true;
}

const int encodingOffset = 'a' - 1;
vector<unsigned long long> commands;//[100000];
const bool debug = false;
const int MAX_COMMAND_LEN = 8;
char decodedCommand[MAX_COMMAND_LEN+1];

inline unsigned long long readCommand()
{
    register char c = 0;
	while(c < 'a' || c > 'z')
	{
		c = getchar_unlocked();
	}
	unsigned long long command = 0;
	int bitshift = 64 - 8;
    while (c >= 'a' && c <= 'z')
	{
		// if(bitshift < 0)
		// {
		// 	cout << "About to abort - bitshift " << bitshift << " char read=" << (int)c << endl;
		// 	abort();
		// }
		command |= ((unsigned long long)(c-encodingOffset)) << bitshift;
		c = getchar_unlocked();
		bitshift -= 8;
	}
	return command;
}

void decodeCommand(unsigned long long encoded)
{
	int bitshift = 56;
	int tmp;
	int i;
	for(i = 0; i < MAX_COMMAND_LEN; ++i)
	{
		tmp = (encoded >> bitshift) & 0xFF;
		// cout << hex << encoded << " ; " << hex << tmp << endl;
		if(tmp == 0) break;
		decodedCommand[i] = tmp + encodingOffset;
		bitshift-=8;
	}
	decodedCommand[i] = '\0';
}

bool startsWith(unsigned long long a, unsigned long long prefix)
{
	while(prefix != 0)
	{
		if((prefix >> 56) != (a >> 56)) // compare highest octet
		{
			return false;
		}
		// lose highest octet (second highest becomes highest)
		prefix <<= 8;
		a <<= 8;
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	commands.reserve(100000);
	unsigned long ops, listLimit;
	ioInt<unsigned long>(&ops);
	ioInt<unsigned long>(&listLimit);

	char operation[MAX_COMMAND_LEN+1];
	bool needToSort = true;
	unsigned long long command;
	char op;
	for(unsigned long i = 0; i < ops; ++i)
	{
		op = getchar_unlocked();
		while(op < 'a' || op > 'z')
		{
			op = getchar_unlocked();
		}
		while(getchar_unlocked() != ' ') { }
		command = readCommand();

		if(op == 'a')
		{
			// add
			commands.push_back(command);
			needToSort = true;
		}
		else if(op == 'r')
		{
			// remove
			if(needToSort)
			{
				needToSort = false;
				sort(commands.begin(), commands.end());
			}
			auto it = lower_bound(commands.begin(), commands.end(), command);
			if(it != commands.end())
			{
				commands.erase(it);
			}
		}
		else if(op == 'l')
		{
			// list
			if(needToSort)
			{
				needToSort = false;
				sort(commands.begin(), commands.end());
			}
			decodeCommand(command);
			printf("%s: ", decodedCommand);
			auto it = lower_bound(commands.begin(), commands.end(), command);
			unsigned long matchCount = 0;
			while(it != commands.end() && startsWith(*it, command))
			{
				if(matchCount < listLimit)
				{
					if(matchCount < listLimit)
					{
						decodeCommand(*it);
						if(matchCount == 0)
							printf("%s", decodedCommand);
						else
							printf(" %s", decodedCommand);
					}
					++matchCount;
					++it;
				}
				else
				{
					int bitshift = 0;
					unsigned long long x = command;
					while(x > 0xFF)
					{
						bitshift += 8;
						x<<=8;
						// cout << "x is " << hex << x << " after bitshift " << dec << bitshift << endl;
					}
					// now the last letter is left on the highest octet

					bitshift = 64 - bitshift; // convert bitshift from right side to left side
					x = ((command >> bitshift) & 0xFF) + 1; // extract the rightmost non-zero octet and add 1
					unsigned long long commandPlus1 = command & (~(((unsigned long long)0xFF) << bitshift)); // zero the last non-zero rightmost octet
					commandPlus1 |= (x << bitshift);
					// cout << "command " << hex << command << " +1 " << hex << commandPlus1 << endl;
					auto it2 = lower_bound(it, commands.end(), commandPlus1);
					matchCount += std::distance(it, it2);
					break;
				}
			}
			if(matchCount > listLimit)
			{
				printf(" and %d other(s)\n", matchCount-listLimit);
			}
			else
			{
				printf("\n");
			}
		}

	}
	return 0;
}
