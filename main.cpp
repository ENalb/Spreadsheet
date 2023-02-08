#include <iostream>
#include "spreadsheet.h"
#include "test.h"

int main()
{
	Tester t;
	t.testSetValue();
	t.testGetValue();
	t.testToInt();
	t.testToDouble();
	t.testToDate();
	t.testToReset();
	t.testSetCellAt();
	t.testSetCellAt1();
	t.testGetCellAt();
	t.testAddRow();
	t.testRemoveRow();
	t.testAddColumn();
	t.testRemoveColumn();
	t.testSwapRows();
	t.testSwapColumns();
}