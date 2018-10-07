#ifndef XLSX_DATA_H_
#define XLSX_DATA_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum DC_code
{
	DEBIT = 'C',	// 借
	CREDIT = 'D'	// 貸
};

class FileRow
{
	public:
		// constructors
		FileRow(const string str);
		
		// getters
		const DC_code get_dc_code() const;
		const int get_subject_id() const;
		const int get_money() const;
		const string get_description() const;
		const string get_li_chong() const;
		
		// operators
		friend ostream& operator <<(ostream& strm, const FileRow& other);
	
	protected:
		void init(const string str);
		
	private:
		DC_code dc_value;		// 借/貸
		int subject_id;			// 科目編號
		int money;				// 金額
		string description;		// 摘要
		string li_chong;		// 立沖帳目
};

class FileData
{
	public:
		// constructors
		FileData(const string filename);
		
		// getters
		const FileRow get(const int index);
	
	protected:
		void init(const string filename);
		
	private:
		string filename;
		vector<FileRow> datas;
};

const vector<string> split(const string& s, char delimiter);
const string to_upper_case(const string str);

#endif // XLSX_DATA_H_
