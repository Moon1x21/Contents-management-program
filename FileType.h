#pragma once
using namespace std;

class FileType {
public:

	/*
		default constructor
	*/
	FileType()
	{
		cname = "";
		filepath = "";
	}
	FileType(string _cname, string _filepath)
	{
		cname = _cname;
		filepath = _filepath;
	}
	FileType(string _cname)
	{
		cname = _cname;
		filepath = "";
	}

	/*
		destructor
	*/
	~FileType(){}

	/**
	*	@brief	Get contents name
	*	@pre	Contents name is set
	*	@post	none
	*	@return	Contents name
	*/
	string GetName() const{ return cname; }

	/**
	*	@brief	Get contents filePath
	*	@pre	Contents filePath is set
	*	@post	none
	*	@return	Contents filePath
	*/
	string GetFilePath() const { return filepath; }

	/**
	*	@brief	Set contents Name
	*	@pre	none
	*	@post	Contents name is set
	*	@param	inName	contents name
	*/
	void SetName(string _cname) { cname = _cname; }

	/**
	*	@brief	Set contents filepath
	*	@pre	none
	*	@post	Contents filepath is set
	*	@param	_file	contents filepath
	*/
	void SetFilePath(string _filepath) { filepath = _filepath; }

	/**
	*	@brief	Set content record
	*	@pre	none
	*	@post	content record is set
	*	@param	_file	contents filepath
	*/
	void SetRecord(string _cname, string _filepath)
	{
		SetName(_cname);
		SetFilePath(_filepath);
	}
	
	/**
	*	@brief	Compare two item types by item cname.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.cname > data.cname, 0 if not.
	*/
	bool operator >(const FileType& data);

	/**
	*	@brief	Compare two item types by item cname.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.cname < data.cname, 0 if not.
	*/
	bool operator <(const FileType& data);
	/**
	*	@brief	Copy the item.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for copy
	*/
	void operator =(const FileType& data);

	/**
	*	@brief	Compare two item types by item c_name.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.c_name == data.c_name, 0 if not.
	*/
	bool operator==(const FileType& data);

private:
	string cname;		//< contents name
	string filepath;		///< contents file Path
};