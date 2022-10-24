#pragma once
#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <filesystem>
#include <string>

class FileManagement
{
public:
	static void readFile(const std::filesystem::path& filename);
	static void writeFile(std::filesystem::path& p, std::string toWrite);
	static void checkDir(std::filesystem::path& p);
	static void iterateFiles(std::filesystem::path& p);
	static void intermediateWrite(std::string key, int value);
	static void createOutput(std::filesystem::path& p);
	static void setIntermediatePath(std::filesystem::path& p);
	static void setOutputPath(std::filesystem::path& p);
};

#endif