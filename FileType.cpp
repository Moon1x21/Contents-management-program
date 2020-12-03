#include "pch.h"
#include "FileType.h"

bool FileType::operator >(const FileType& data)
{
	if (this->cname > data.cname)
		return true;
	else
		return false;
}
bool FileType::operator <(const FileType& data)
{
	if (this->cname < data.cname)
		return true;
	else
		return false;
}
void FileType::operator =(const FileType& data)
{
	this->cname = data.cname;
	this->filepath = data.filepath;
}
bool FileType::operator==(const FileType& data)
{
	if (this->cname == data.cname)
		return true;
	else
		return false;
}