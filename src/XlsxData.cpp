#include <iostream>

#include <zip.h>

#include "XlsxData.h"

using namespace std;

/* ================= class XlsxRow ================= */
// constructors
XlsxRow::XlsxRow()
{
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
