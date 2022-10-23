#include "Reduce.h"
#include <iostream>

using namespace std;

// no file io
void exportAll()
{
	// write result out to the output directory
}

void reduce(string key, int iterator[])
{
	for (int i = 0; i < sizeof(iterator); i++)
	{
		int sum = 0;
		sum += iterator[i];
	}

	exportAll();
}