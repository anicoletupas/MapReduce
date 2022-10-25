#include "FileManagement.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;

filesystem::path interPath;
vector<pair<string, int>> inter_count;

// use directory_iterator to iterate through all files in the given directory input

// check directory if it exists, and if it does, continue to parse files
// read files from input directory and feed into map
void FileManagement::readFile(const filesystem::path& filename)
{
	string line;
	fstream file;
	file.open(filename);

	while (!file.eof())
	{
		getline(file, line);
		Map::mapFile(filename.string(), line);
	}
}

// function that creates and writes to a file in given directory, will call from reduce class
void FileManagement::writeInterFile()
{
	fstream output;
	output.open(interPath);
	for (auto const& pair : inter_count) {
		output << pair.first << ", " << pair.second << "\n";
	}
}

// error check if directory input is valid
void FileManagement::checkDir(filesystem::path& p)
{
	if (!filesystem::exists(p))
		cout << "The file directory does not exist. Try again. \n";
	else
		cout << "The directory is " << p << "\n";

}

void FileManagement::iterateFiles(filesystem::path& p)
{
	if (filesystem::is_empty(p))
		cout << "There are no files in the directory";
	else
	{
		for (auto const& dir_entry : filesystem::directory_iterator(p))
		{
			cout << dir_entry.path() << '\n';
			readFile(dir_entry.path());
		}
	}
}

void FileManagement::intermediateWrite(string key, int value)
{
	inter_count.push_back(make_pair(key, value));
}

void FileManagement::createOutput(filesystem::path& p)
{
	p /= "output.txt";
	ofstream outfile;
	outfile.open(p);
}

void FileManagement::setIntermediatePath(filesystem::path& p)
{
	interPath = p;
	cout << interPath;
}

void FileManagement::setOutputPath(filesystem::path& p)
{
}
