#pragma once


class Key_List {
public:
	/**
	*	default constructor
	*/
	Key_List() {
		keyname = "";
		key_description = "";
		keylist = new DoubleLinkedList<string>;
	}

	Key_List(string name) {
		keyname = name;
		key_description = "";
		keylist = new DoubleLinkedList<string>;
	}

	/**
	*	destructor
	*/
	~Key_List()
	{
	}

	/**
	*	@brief	Set key name
	*	@pre	none
	*	@post	key name is set
	*	@param	_name	key name
	*/
	void SetKeyName(string _name) { keyname = _name; }

	/**
	*	@brief	Set key description
	*	@pre	none
	*	@post	key description is set
	*	@param	_descip	key description
	*/
	void SetDes(string _descrip) { key_description = _descrip; }

	/**
	*	@brief	Set key record
	*	@pre	none
	*	@post	key record is set
	*/
	void SetKeyRecord(string _name, string _descrip)
	{
		SetKeyName(_name);
		SetDes(_descrip);
	}

	/**
	*	@brief	Get event name
	*	@pre	event name is set
	*	@post	none
	*	@return	event name
	*/
	string GetKeyname() const { return keyname; }

	/**
	*	@brief	Get event description
	*	@pre	event description is set
	*	@post	none
	*	@return	event description
	*/
	string GetDescrip() const { return key_description; }

	/**
	*	@brief	Get event num
	*	@pre	event num is set
	*	@post	none
	*	@return	event num
	*/
	int GetKeynum() const { return keylist->GetLength(); }

	/**
	*	@brief	Get event list
	*	@pre	event list is set
	*	@post	none
	*	@return	event list
	*/
	DoubleLinkedList<string>* GetList() const { return keylist; }

	/**
	*	@brief	Add new master contents into event list
	*	@pre	list should be initialized
	*	@post	new master contents is added into the list
	*	@param	data	new master contents
	*	@return	return 1 if this function is worls well, otherwise return 0
	*/
	int AddKeyList(string data);

	/**
	*	@brief	Find the data and delete the data record in the list
	*	@pre	Data name must in the list
	*	@post	Data is delete in the list
	*	@param	data	EventType value with the name you want to remove.
	*	@return	return 1 if this function is worls well, otherwise return 0
	*/
	int DeleteKeyList(string& data);

	/**
	*	@brief	Find the item int the list
	*	@pre	none
	*	@post	the item and name are found to match and returned to the data.
	*	@param	data EventType value with the name you want to find.
	*	@return	return 1 if this function is worls well, otherwise return 0
	*/
	int RetrieveKeyList(string& data);

	/**
	*	@brief	Copy the item.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for copy
	*/
	bool operator==(const Key_List& _item);

	/**
	*	@brief	Compare two item types by item e_name.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for comparing.
	*	@return	return 1 if this.e_name < data.e_name, 0 if not.
	*/
	bool operator>(const Key_List& _item);

	/**
	*	@brief	Compare two item types by item e_name.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.e_name > data.e_name, 0 if not.
	*/
	bool operator<(const Key_List& _item);

	/**
	*	@brief	Copy the item.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for copy
	*/
	void operator =(Key_List& _item);
private:
	DoubleLinkedList<string>* keylist;		///<event list
	string keyname;		///<event name
	string key_description;		///<event description
};