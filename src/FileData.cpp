#include "FileData.h"

/* ================= class FileRow ================= */

// constructors
FileRow::FileRow(const string str)
{
	this->init(str);
}

// getters
const DC_code FileRow::get_dc_code() const
{
	return this->dc_value;
}

const int FileRow::get_subject_id() const
{
	return this->subject_id;
}

const int FileRow::get_money() const
{
	return this->money;
}

const string FileRow::get_description() const
{
	return this->description;
}

const string FileRow::get_li_chong() const
{
	return this->li_chong;
}

// operators
ostream& operator <<(ostream& strm, const FileRow& other)
{
	const char SLICE = ' ';
	strm << (char)other.get_dc_code();
	strm << SLICE;
	strm << other.get_subject_id();
	strm << SLICE;
	strm << other.get_money();
	strm << SLICE;
	strm << other.get_description();
	strm << SLICE;
	strm << other.get_li_chong();
	return strm;
}

// protected functions
void FileRow::init(const string str)
{
	vector<string> tokens = split(str, ',');
	this->dc_value = static_cast<DC_code>(to_upper_case(tokens[0]).at(0));
	this->subject_id = stoi(tokens[1]);
	this->money = stoi(tokens[2]);
	this->description = tokens[3];
	this->li_chong = tokens.size() > 4 ? tokens[4] : "";
}

/* ================= class FileData ================= */

// constructors
FileData::FileData(const string filename)
{
	this->init(filename);
}

// getters
const FileRow FileData::get(const unsigned int index)
{
	if (index < 0 || index >= this->datas.size())
	{
		throw new invalid_argument("index out of bound");
	}
	return this->datas[index];
}
// operators
const FileRow& FileData::operator [](const unsigned int index) const
{
	if (index < 0 || index >= this->datas.size())
	{
		throw new invalid_argument("index out of bound");
	}
	return this->datas[index];
}

// other public function
const bool FileData::is_empty() const
{
	return this->datas.size() == 0 ? true : false;
}

const int FileData::size() const
{
	return this->datas.size();
}

// protected functions
void FileData::init(const string filename)
{
	this->filename = filename;
	
	// get data in csv file
	ifstream file(filename);
	if(file.is_open())
	{
		string row;
		while(getline(file, row))
		{
			FileRow data(row);
			this->datas.push_back(data);
		}
		file.close();
	}
}

/* ================= other functions ================= */
const vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

const string to_upper_case(const string str)
{
	string s = str;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return s;
}
