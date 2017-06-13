#include "stdafx.h"

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <fstream>
#include <thread>
using namespace std;

void GetFileNameData(string fileLocation, string& fileName, string& fileFormat)
{
	//fileName과 fileFormat은 레퍼런스 값으로써 데이터를 날려주지 않으면 중첩된다.
	fileName.clear(); fileFormat.clear();

	string sType;
	int formatLen = fileLocation.length() - 1;
	int nameLen;

	while(true){
		if('.' == fileLocation[formatLen-1]) break;
		formatLen--;
	}		

	nameLen = formatLen-1;
	while(true){
		if('/' == fileLocation[nameLen-1])break;
		nameLen--;
	}

	for(int i=nameLen ; i<formatLen-1 ; ++i) fileName.push_back(fileLocation[i]);
	for(int i=formatLen ; i<fileLocation.length() ; ++i) fileFormat.push_back(fileLocation[i]);
}


vector<string> GetDirectoryFileNamesA(string pfolderLocation)
{
	vector<string> names;
	string search_path(pfolderLocation);
	search_path += "/*.*";
	//"%s/*.*"			All Files
	//"%s/*.cpp*"		Only cpp Files
	//"%s/*.h*"			Only h Files
	
	WIN32_FIND_DATAA fd; 
	HANDLE hFind = ::FindFirstFileA(search_path.c_str(), &fd); 
	
	if(hFind == INVALID_HANDLE_VALUE) { 
		while(::FindNextFileA(hFind, &fd)){ 
			//Exept Directory Folder
		    if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
				names.push_back(pfolderLocation + fd.cFileName);
			}
		} 
		::FindClose(hFind); 
	} 
	return names;
}


vector<wstring> GetDirectoryFileNamesW(wstring pfolderLocation)
{
    vector<wstring> vNames;
	wstring search_path = pfolderLocation;
	search_path += L"/*.*";
	//"%s/*.*"			All Files
	//"%s/*.cpp*"		Only cpp Files
	//"%s/*.h*"			Only h Files

	WIN32_FIND_DATA fd; 
    HANDLE hFind = FindFirstFile(search_path.c_str(), &fd); 

	if(hFind != INVALID_HANDLE_VALUE){
		while(FindNextFile(hFind, &fd)){ 
			//Exept Directory Folder
			if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
				vNames.push_back(pfolderLocation + fd.cFileName);
			}
		}
	}

    FindClose(hFind); 
	return vNames;
}

int main()
{
	//vector<string> vsFileList = GetDirectoryFileNamesA("./");
	//string fileName;
	//string fileFormat;

	//for(string fileLocationName : vsFileList)
	//{
	//	GetFileNameData(fileLocationName , fileName, fileFormat);
	//	cout << fileLocationName  << "\t\t" << fileName << " - [" << fileFormat << "]" << endl << endl;
	//}

	vector<wstring> vsFileList = GetDirectoryFileNamesW(L"./");
	string fileName;
	string fileFormat;

	for(wstring fileLocationName : vsFileList)
	{
	//	GetFileNameData(fileLocationName , fileName, fileFormat);
		wcout << fileLocationName  << endl;
	}
}