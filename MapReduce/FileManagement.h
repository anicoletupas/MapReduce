#pragma once
#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <filesystem>

class FileManagement
{
public:
	static void readFile(const std::filesystem::path& filename);
	static void writeFile(std::filesystem::path& p);
	static void checkDir(std::filesystem::path& p);
	static void iterateFiles(std::filesystem::path& p);
};

#endif