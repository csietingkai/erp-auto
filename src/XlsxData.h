#ifndef XLSX_DATA_H_
#define XLSX_DATA_H_

using namespace std;

enum DC_code
{
	DEBIT = 'C',	// 借
	CREDIT = 'D'	// 貸
};

class XlsxRow
{
	public:
		XlsxRow();
		
	private:
		int index;
		DC_code value;
		int subject_id;
		int money;
		string description;
		string li_chong;
};

class XlsxData
{
	public:
		XlsxData(const string filename);
		~XlsxData();
		
	private:
		XlsxRow *data;
};

#endif // XLSX_DATA_H_
