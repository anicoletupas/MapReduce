#include "FileManagement.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

// use directory_iterator to iterate through all files in the given directory input

// check directory if it exists, and if it does, continue to parse files
// read files from directory and map
void FileManagement::readFile(const filesystem::path& filename)
{
	string line;
	fstream file;
	file.open(filename);

	getline(file, line);
	Map::map(filename.string(), line);
}

// function that creates and writes to a file in given directory
void FileManagement::writeFile(filesystem::path& p)
{
	string fileName = p.string() + "\\output.txt";
	ofstream outfile(fileName);

	// write to file here
	outfile << "Hello";

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
