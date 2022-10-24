#include "FileManagement.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <map>

using namespace std;

static filesystem::path intermediatePath;
static filesystem::path outputPath;

// use directory_iterator to iterate through all files in the given directory input

// check directory if it exists, and if it does, continue to parse files
// read files from input directory and feed into map
void FileManagement::readFile(const filesystem::path& filename)
{
	string line;
	fstream file;
	file.open(filename);

	while (getline(file, line))
	{
		getline(file, line);
		Map::mapFile(filename.string(), line);
	}
}

// function that creates and writes to a file in given directory, will call from reduce class
void FileManagement::writeFile(filesystem::path& p, string toWrite)
{
	string fileName = p.generic_string();
	fileName += "\\output.txt";
	ofstream outfile;
	outfile.open(fileName);

	// write to file here
	cout << fileName << "\n";
	cout << toWrite;
	outfile << toWrite;

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
	string output = key + ", " + to_string(value) + "\n";
	writeFile(intermediatePath, output);
}

void FileManagement::createOutput(filesystem::path& p)
{
	string fileName = p.string() + "\\output.txt";
	ofstream outfile;
	outfile.open(fileName);
}

void FileManagement::setIntermediatePath(filesystem::path& p)
{
	intermediatePath = p;
}

void FileManagement::setOutputPath(filesystem::path& p)
{
	outputPath = p;
}
