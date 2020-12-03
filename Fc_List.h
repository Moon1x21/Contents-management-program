#pragma once
using namespace std;

class Fc_list {
public:

	/**
	*	default constructor
	*/
	Fc_list() {
		Fcname = "";
		Flist = new DoubleLinkedList<FileType>;
		Description = "";
	}

	Fc_list(string name) {
		Fcname = name;
		Flist = new DoubleLinkedList<FileType>;
		Description = "";
	}

	/**
	*	destructor
	*/
	~Fc_list() {}

	/**
	*	@brief	Set list key name
	*	@pre	none
	*	@post	key name is set
	*	@param	_pname	key name
	*/
	void Setname(string _pname) { Fcname = _pname; }

	/**
	*	@brief	Set list Description
	*	@pre	none
	*	@post	list Description is set
	*	@param	_Des	list Description
	*/
	void SetDes(string _Des) { Description = _Des; }

	/**
	*	@brief	Get key name
	*	@pre	people name is set
	*	@post	none
	*	@return	key name
	*/
	string Getname() const { return Fcname; }

	/**
	*	@brief	Set list Description
	*	@pre	none
	*	@post	list Description is set
	*	@return	list Description
	*/
	string GetDes() const { return Description; }


	/**
	*	@brief	Get key list
	*	@pre	key list is set
	*	@post	none
	*	@return	key list
	*/
	DoubleLinkedList<FileType>* GetList() const { return Flist; }

	/**
	*	@brief	Add new contents into event list
	*	@pre	list should be initialized
	*	@post	new  contents is added into the list
	*	@param	inData	new key data
	*	@return	return 1 if this function is worls well, otherwise return 0
	*/
	int AddPlist(FileType inData);

	/**
	*	@brief	Find the data and delete the data record in the list
	*	@pre	Data name must in the list
	*	@post	Data is delete in the list
	*	@param	data	key with the name you want to remove.
	*/
	int DeletePlist(FileType& data);

	/**
	*	@brief	Compare two item types by item Pname
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Pname == data.Pname, 0 if not.
	*/
	bool operator==(const Fc_list& _item);
	/**
	*	@brief	Compare two item types by item Pname
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Pname > data.Pname, 0 if not.
	*/
	bool operator>(const Fc_list& _item);

	/**
	*	@brief	Compare two item types by item Pname
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Pname < data.Pname, 0 if not.
	*/
	bool operator<(const Fc_list& _item);

	/**
	*	@brief	Copy the item.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for copy
	*/
	void operator =(Fc_list& _item);


private:
	string Fcname;		///<key ÀÌ¸§
	DoubleLinkedList<FileType>* Flist;			///<key list
	string Description;
};