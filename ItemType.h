#pragma once

/*
*	Set ItemType class
*/
class ItemType {
public:
	/*
		default constructor
	*/
	ItemType() {
		c_name = "";
		c_Dtime = "";
		c_type = "";
		c_people = "";
		c_con = "";
		c_place = "";
		filepath = "";
		view_point = 0;
		fc = false;
	}

	ItemType(int num) {
		c_name = "";
		c_Dtime = num;
		c_type = "";
		c_people = "";
		c_con = "";
		c_place = "";
		view_point = 0;
		fc = false;
	}

	ItemType(string _cname) {
		c_name = _cname;
		c_Dtime = "";
		c_type = "";
		c_people = "";
		c_con = "";
		c_place = "";
		view_point = 0;
		fc = false;
	}
	/*
		destructor
	*/
	~ItemType() {}

	/**
	*	@brief	Get contents name
	*	@pre	Contents name is set
	*	@post	none
	*	@return	Contents name
	*/
	string GetName() const { return c_name; }

	/**
	*	@brief	Get contents date and time
	*	@pre	Contents date and time is set
	*	@post	none
	*	@return	Contents date and time
	*/
	string GetDtime() const { return c_Dtime; }

	/**
	*	@brief	Get contents type
	*	@pre	Contents type is set
	*	@post	none
	*	@return	Contents type
	*/
	string GetType() const { return c_type; }

	/**
	*	@brief	Get people who included in contents
	*	@pre	People is set
	*	@post	none
	*	@return	People who included in contents
	*/
	string GetPeople() const { return c_people; }

	/**
	*	@brief	Get contents event
	*	@pre	Contents event is set
	*	@post	none
	*	@return	Contents event
	*/
	string GetEvent() const { return c_event; }

	/**
	*	@brief	Get contents place
	*	@pre	Contents place is set
	*	@post	none
	*	@return	Contents place
	*/
	string GetPlace() const { return c_place; }

	/**
	*	@brief	Get contents content
	*	@pre	Contents content is set
	*	@post	none
	*	@return	Contents content
	*/
	string GetCon() const { return c_con; }

	/**
	*	@brief	Get contents view_point
	*	@pre	Contents view_point is set
	*	@post	none
	*	@return	Contents view_point
	*/
	int GetView() const { return view_point; }

	/**
	*	@brief	FcList에 포함 되어 있는지 아닌지.
	*	@pre	none
	*	@post	none
	*	@return	FcList에 포함 되어 있는지 아닌지 참 거짓을 return
	*/
	bool GetFc() const { return fc; }

	/**
	*	@brief	Get contents filePath
	*	@pre	Contents filePath is set
	*	@post	none
	*	@return	Contents filePath
	*/
	string GetFile() const { return filepath; }

	/**
	*	@brief	Set contents Name
	*	@pre	none
	*	@post	Contents name is set
	*	@param	inName	contents name
	*/
	void SetName(string inName) { c_name = inName; }

	/**
	*	@brief	Set contents date and time
	*	@pre	none
	*	@post	Contents date and time is set
	*	@param	inDtime	contents date and time
	*/
	void SetDtime(string inDtime) { c_Dtime = inDtime; }

	/**
	*	@brief	Set contents type
	*	@pre	none
	*	@post	Contents types is set
	*	@param	inType	contents type
	*/
	void SetType(string inType) { c_type = inType; }

	/**
	*	@brief	Set people who included in contents
	*	@pre	none
	*	@post	People who included in contents is set
	*	@param	inPeople	People who included in contents
	*/
	void SetPeople(string inPeople) { c_people = inPeople; }

	/**
	*	@brief	Set event name
	*	@pre	none
	*	@post	Event name is set
	*	@param	inEvent	Event name
	*/
	void SetEvent(string inEvent) { c_event = inEvent; }

	/**
	*	@brief	Set contents place
	*	@pre	none
	*	@post	contents place is set
	*	@param	inSort		contents place
	*/
	void SetPlace(string inplace) { c_place = inplace; }

	/**
	*	@brief	Set contents content
	*	@pre	none
	*	@post	Event name is set
	*	@param	inCon	contents content
	*/
	void SetCon(string inCon) { c_con = inCon; }

	/**
	*	@brief	Set contents view_point
	*	@pre	none
	*	@post	Contents view_point is set
	*	@param	inVeiw	contents view_point
	*/
	void SetView(int inView) { view_point = inView; }

	/**
	*	@brief	Set contents filepath
	*	@pre	none
	*	@post	Contents filepath is set
	*	@param	_file	contents filepath
	*/
	void SetFilePath(string _file) { filepath = _file; }

	/**
	*	@brief	Set content record
	*	@pre	none
	*	@post	content record is set
	*	@param	inName	contents name
	*	@param	inDtime	contents date and time
	*	@param	inType	contents type
	*	@param	inPeople	People who included in contents
	*	@param	inEvent	contents event name
	*	@param	inCon	Contents content
	*	@param	inSort	Contents sort
	*	@param	inView	contents view_point
	*	@param	_file	contents filepath
	*	@param	_view	contents filepath
	*/
	void SetRecord(string inName, string inDtime, string inPeople, string inType, string inEvent, string inCon, string inplace, bool _fc,string _file,int _view) {
		SetName(inName);
		SetDtime(inDtime);
		SetEvent(inEvent);
		SetPeople(inPeople);
		SetType(inType);
		SetCon(inCon);
		SetPlace(inplace);
		fc = _fc;
		view_point = _view;
		SetFilePath(_file);
	}


	/*
	*	@brief	Get the contents type
	*	@pre	Contents type is set
	*	@post	contents type is return
	*	@return	return contents type
	*/
	string GetConType() { return c_type; }

	/**
	*	@brief	Plus the view point
	*	@pre	none
	*	@post	veiw point +1
	*/
	void PlusView() { view_point++; }

	/**
	*	@brief	Compare two item types by item c_name.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.c_name == data.c_name, 0 if not.
	*/
	bool operator==(const ItemType& _item);

	/**
	*	@brief	Compare two item types by item c_Dtime.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.c_Dtime > data.c_Dtime, 0 if not.
	*/
	bool operator>(const ItemType& _item);

	/**
	*	@brief	Compare two item types by item c_Dtime.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.c_Dtime < data.c_Dtime, 0 if not.
	*/
	bool operator<(const ItemType& _item);

	/**
	*	@brief	Copy the item.
	*	@pre	two item types should be initialized.
	*	@param	_item	target item for copy
	*/
	void operator=(const ItemType& _item);

	/**
	*	@brief	Change the Fctpye
	*	@pre	none
	*	@post	if ture, than change false, if false than change true
	*/
	void changeFc()
	{
		if (fc)
			fc = false;
		else
			fc = true;
	}

	/**
	*	@brief	파일로부터 아이템의 모든 정보를 읽어온다.
	*	@pre	정해진 파일을 연다.
	*	@post	아이템의 모든 정보를 설정한다.
	*	@param	fin		파일 디스크립터.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 아이템의 모든 정보를 쓴다.
	*	@pre	정해진 파일을 열고, 리스트를 초기화한다.
	*	@post	정해진 파일에 새로운 아이템들을 설정한다.
	*	@param	fout	파일 디스크립터.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int WriteDataToFile(ofstream& fout);

private:
	string c_name;		///< contents name
	string c_Dtime;	                  	///< contents time and date
	string filepath;		///< contents file Path
	string c_type;		///< Types of contents
	string c_people;		///<people who included in contents
	string c_event;		///<event name
	string c_place;			///place name
	string c_con;			///contents' content
	int view_point;			///contents view point
	bool fc;			///contents의 fclist 포함 유무 여부
};

