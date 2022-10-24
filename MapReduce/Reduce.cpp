#include "Reduce.h"
#include <iostream>

using namespace std;

// no file io
void exportAll(string key, int result)
{
	// write result out to the output directory
}

// reads out (string: the word, [1,1,1,1]), passes in "the word" and 4 to export to output file
void reduce(string key, int iterator[])
{
	int sum = 0;
	for (int i = 0; i < sizeof(iterator); i++)
	{
		sum += iterator[i];
	}

	exportAll(key, sum);
}