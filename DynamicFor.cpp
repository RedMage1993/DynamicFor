// Author: Fritz Ammon
// Date: 9 December 2014
// Description:
// Implementing a for loop that can be nested
// a variable number of times.

#include <iostream>

using namespace std;

struct forLoopData
{
	int iterator;
	int limit;

	forLoopData()
	{
		iterator = 0;
		limit = 10;
	}
};

void dynamicLoop(forLoopData* loops, int noLoops);

int main()
{
	int noLoops = 0;
	forLoopData* loops = NULL;

	cout << "How many for-loops? " << endl;
	cin >> noLoops;
	cout << endl;

	loops = new forLoopData[noLoops];

	dynamicLoop(loops, noLoops);

	delete [] loops;

	return 0;
}

void dynamicLoop(forLoopData* loops, int noLoops)
{
	int loop = 0;

	while (loops[0].iterator < loops[0].limit)
	{
		// Go to inner loop if there.
		while (loops[loop].iterator < loops[loop].limit &&
			loop < noLoops - 1)
			loop++;

		// Before for loop:

		// Check if loop is done.
		while (loops[loop].iterator < loops[loop].limit)
		{
			// For loop body:

			// For test, print out all iterators.
			for (int i = 0; i < noLoops; i++)
				cout << loops[i].iterator;
			cout << endl;

			loops[loop].iterator++; // Increment at current loop.
		}

		// After for loop:

		// Current loop done, variables lost (so reset).
		loops[loop].iterator = 0;

		loop--; // Go back to outer loop.

		loops[loop].iterator++; // Increment outer loop.
	}
}
