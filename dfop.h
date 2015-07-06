#pragma once

#include <string>
#include <iostream>
#include <string>
#include <algorithm>

#include <boost\filesystem.hpp>


using namespace std;
using namespace boost::filesystem;

void ToUpperString(string &str)  
{  
	transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);  
}  
void ToLowerString(string &str)  
{  
	transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);  
}  

vector<string> getSubPath(string rootPath)
{
	vector<string> subPath;
	directory_iterator enditer;
	//ToLowerString(fExt);
	path pname(rootPath);
	for( directory_iterator it(pname); it != enditer; it++)
	{
		if(is_directory(*it))
		{
			string filename = it->path().string();
			subPath.push_back(filename);
		}
	}
	return subPath;
}

vector<string> getSubFile(string rootPath, string fExt = ".jpg")
{
	vector<string> subFile;
	directory_iterator enditer;
	ToLowerString(fExt);
	path pname(rootPath);
	for( directory_iterator it(pname); it != enditer; it++)
	{
		if(is_regular_file(*it))
		{
			string filename = it->path().string();
			string ext =extension( path(filename) );
			ToLowerString(ext);
			if(ext == fExt || fExt == "")
			{
				subFile.push_back(filename);
			}
		}
	}
	return subFile;
}
