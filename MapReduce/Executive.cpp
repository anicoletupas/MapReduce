#include "Executive.h"
#include "FileManagement.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	cout << "Enter the directory of the input file: \n";
	string inputPath;
	cin >> inputPath;
	filesystem::path inPath = inputPath;
	FileManagement::checkDir(inPath);

	cout << "Enter the directory of the output file: \n";
	string outputPath;
	cin >> outputPath;
	filesystem::path outPath = outputPath;
	FileManagement::checkDir(outPath);


	cout << "Enter the temporary directory for intermediate files: \n";
	string interPath;
	cin >> interPath;
	filesystem::path intPath = interPath;
	FileManagement::checkDir(intPath);

	cout << "Creating output files in intermediate and output folder... \n";

	intPath /= "output.txt";
	ofstream intOf(intPath);
	FileManagement::setIntermediatePath(intPath);

	outPath /= "output.txt";
	ofstream outOf(outPath);
	FileManagement::setOutputPath(outPath);

	cout << "Starting to parse files in input directory... \n";

	FileManagement::iterateFiles(inPath);

	return 0;
}