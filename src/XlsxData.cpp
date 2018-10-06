#include <iostream>

#include <zip.h>

#include "XlsxData.h"

using namespace std;

/* ================= class XlsxRow ================= */
// constructors
XlsxRow::XlsxRow(const DC_code dc_value, const int subject_id, const int money, const string description)
{
	this->dc_value = dc_value;
	this->subject_id = subject_id;
	this->money = money;
	this->description = description;
}

XlsxRow::XlsxRow(const DC_code dc_value, const int subject_id, const int money, const string description, const string li_chong)
{
	this->dc_value = dc_value;
	this->subject_id = subject_id;
	this->money = money;
	this->description = description;
	this->li_chong = li_chong;
}

/* ================= class XlsxData ================= */
// constructors
XlsxData::XlsxData(const string filename)
{
}

XlsxData::~XlsxData()
{
	delete data;
}
