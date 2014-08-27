#include "Directory.h"

Directory::Directory(const wchar_t* filepath, const wchar_t* searchpattern)
	:
filepath(filepath),
filetype(searchpattern)
{
	HANDLE hFind;
	WIN32_FIND_DATA FindData;
	searchpath.append(filepath);
	searchpath.append(searchpattern);
	hFind = FindFirstFile((searchpath.c_str()), &FindData);
	int index;
	do
	{
		std::wstring buffer; //= filepath;
		buffer += FindData.cFileName;
		FileList.push_back(buffer);
	}while (FindNextFile(hFind, &FindData) > 0);
	InnitDrawings();
}

Directory::~Directory()
{
}

int Directory::size() const
{
	return FileList.size();
}

bool Directory::update()
{
	FileList.clear();

	HANDLE hFind;
	WIN32_FIND_DATA FindData;
	hFind = FindFirstFile((searchpath.c_str()), &FindData);
	int index;
	do
	{
		std::wstring buffer = FindData.cFileName;
		FileList.push_back(buffer);
	}while (FindNextFile(hFind, &FindData) > 0);
	return true;
}

std::wstring Directory::path() const
{
	return filepath;
}

std::wstring Directory::operator[](int index)
{
	return FileList[index];
}

std::wstring Directory::getname(int index)
{
	std::wstring buffer = filepath + FileList[index];
	return buffer;
}

void Directory::InnitDrawings()
{
	 std::ifstream drawdata;//get input/stuff from file
	 for(int i = 0; i < size();++i )
	 {
		 std::string buffer;
		 drawdata.open(getname(i));
		 while(!drawdata.eof())//EOF
		 {
			 buffer.push_back(drawdata.get());
		 }
		 drawdata.close();
		 buffer.pop_back();// do this to pop the null ascii
		 drawings.push_back(buffer);
	 }
}

std::string Directory::getstring(wchar_t* filename)
{
	int index = 0;
	while(wcscmp(filename,FileList[index].c_str()))
	{
		index++;
	}
	return drawings[index];
}