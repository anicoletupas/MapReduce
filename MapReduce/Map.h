#pragma once
#ifndef MAP_H
#define MAP_H
#include <string>

// map class

class Map
{
public:
	static void mapExport();
	static void map(std::string filename, std::string input);
};

#endif

