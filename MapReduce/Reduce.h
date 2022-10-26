#pragma once
#ifndef REDUCE_H
#define REDUCE_H
#include <iostream>
#include <vector>
#include <iterator>
class Reduce
{
public:

	static void exportAll(std::string key, int result);
	static void reduce(std::string key, int iterator);

};

#endif
