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
		XlsxRow(const DC_code dc_value, const int subject_id, const int money, const string description);
		XlsxRow(const DC_code dc_value, const int subject_id, const int money, const string description, const string li_chong);
		
		const DC_code get_dc_code() const;
		const int get_subject_id() const;
		const int get_money() const;
		const string get_description() const;
		const string get_li_chong() const;
		
	private:
		DC_code dc_value;		// 借/貸
		int subject_id;			// 科目編號
		int money;				// 金額
		string description;		// 摘要
		string li_chong;		// 立沖帳目
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
