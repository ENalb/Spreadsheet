#include "test.h"
#include "spreadsheet.h"
#include <iostream>
#include <vector>
#include <string>

void Tester::testSetValue()
{
	Cell c;
	c.setValue("N");
	if(c.getValue() != "N")
	{
		std::cout << "N setvalue Test failed" << std::endl; 
	}
	else
	{
		std::cout << "N setvalue Test passed" << std::endl;
	}
}
void Tester::testGetValue()
{
	Cell c;
	c.setValue("E");
	if(c.getValue() != "E")
	{
		std::cout << "E getvalue Test failed" << std::endl; 
	}
	else
	{
		std::cout << "E getvalue Test passed" << std::endl;
	}
}
void Tester::testToInt()
{
	Cell c1, c2;
	c1.setValue("25");
	if(c1.toInt() != 25)
	{
		std::cout << "25 toint Test failed" << std::endl; 
	}
	else
	{
		std::cout << "25 toint Test passed" << std::endl;
	}
	c2.setValue("-4");
	if(c2.toInt() != -4)
	{
		std::cout << "-4 toint Test failed" << std::endl; 
	}
	else
	{
		std::cout << "-4 toint Test passed" << std::endl;
	}
}

void Tester::testToDouble()
{
	Cell c;
	c.setValue("3.47");
	if(c.toDouble() != 3.47)
	{
		std::cout << "3.47 todouble Test failed" << std::endl; 
	}
	else
	{
		std::cout << "3.47 todouble Test passed" << std::endl;
	}
}

void Tester::testToDate()
{
	Cell c;
	c.setValue("2001/5/24");
	if(c.toDate().getYear() != 2001 || c.toDate().getMonth() != 5 || c.toDate().getDay() != 24)
	{
		std::cout << "toDate Test failed" << std::endl; 
	}
	else
	{
		std::cout << "toDate Test passed" << std::endl;
	}
}

void Tester::testToReset()
{
	Cell c;
	c.setValue("M");
	c.reset();
	if(c.getValue() != "")
	{
		std::cout << "reset Test failed" << std::endl; 
	}
	else
	{
		std::cout << "reset Test passed" << std::endl;
	}
}

void Tester::testSetCellAt()
{
	Spreadsheet sp(3,3);
	Cell c("5", Color::black);
	sp.setCellAt(2,1,c);
	if(sp.getCellAt(2,1).getValue() != c.getValue())
	{
		std::cout << "setCellAt Test failed" << std::endl; 
	}
	else
	{
		std::cout << "setCellAt Test passed" << std::endl;
	}
}

void Tester::testSetCellAt1()
{
	Spreadsheet sp(4,4);
	sp.setCellAt(2,3,"H");
	if(sp.getCellAt(2,3).getValue() != "H")
	{
		std::cout << "setCellAt1 Test failed" << std::endl; 
	}
	else
	{
		std::cout << "setCellAt1 Test passed" << std::endl;
	}
}

void Tester::testGetCellAt()
{
	Spreadsheet sp(4,4);
	sp.setCellAt(2,3,"O");
	if(sp.getCellAt(2,3).getValue() != "O")
	{
		std::cout << "getCellAt Test failed" << std::endl; 
	}
	else
	{
		std::cout << "getCellAt Test passed" << std::endl;
	}
}

void Tester::testAddRow()
{
	Spreadsheet sp(2, 2);
	int rows = sp.getRow();
	Cell c1("3", Color::pink);
	Cell c2("0", Color::purple);
	std::vector<Cell> newRow = {c1, c2};
	sp.addRow(1, newRow);
	int new_rows = sp.getRow();
	if(new_rows == rows + 1)
	{
		std::cout << "addrow Test passed" << std::endl;
	}
	else
	{
		std::cout << "addrow Test failed" << std::endl;
	}
}

void Tester::testRemoveRow()
{
	Spreadsheet sp(2, 2);
	int rows = sp.getRow();
	sp.removeRow(1);
	int new_rows = sp.getRow();
	if(new_rows == rows - 1)
	{
		std::cout << "removerow Test passed" << std::endl;
	}
	else
	{
		std::cout << "removerow Test failed" << std::endl;
	}
}

void Tester::testAddColumn()
{
	Spreadsheet sp(3,3);
	int cols = sp.getColumn();
    Cell c1("24", Color::red);
    Cell c2("36", Color::purple);
    Cell c3("47", Color::green);
	std::vector<Cell> newCol = {c1, c2, c3};
	sp.addColumn(2, newCol);
    int new_cols = sp.getColumn();
    if (new_cols == cols + 1) {
        std::cout << "addColumn Test passed" << std::endl;
    } else {
        std::cout << "addColumn Test failed" << std::endl;
    }
}

void Tester::testRemoveColumn()
{
	Spreadsheet sp(5, 5);
	int cols = sp.getColumn();
	sp.removeColumn(2);
	int new_cols = sp.getColumn();
	if (new_cols == cols - 1) {
        std::cout << "removeColumn Test passed" << std::endl;
    } else {
        std::cout << "removeColumn Test failed" << std::endl;
    }
}

void Tester::testSwapRows()
{
	Spreadsheet sp(3, 3);
	int row = sp.getRow();
	int column = sp.getColumn();
	Spreadsheet oldSp(row, column);
	sp.swapRows(1, 2);
	bool isSwapped = true;
	for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            if (oldSp.getCellAt(r,c).getValue() != sp.getCellAt(r,c).getValue()) {
                isSwapped = false;
                break;
            }
        }
    }
    for (int c = 0; c < column; c++) {
        if (oldSp.getCellAt(1,c).getValue() != sp.getCellAt(2,c).getValue() || 
        	oldSp.getCellAt(2,c).getValue() != sp.getCellAt(1,c).getValue()) {
            isSwapped = false;
            break;
        }
    }
    if (isSwapped) {
        std::cout << "swapRows Test passed" << std::endl;
    } 
    else {
        std::cout << "swapRows Test failed" << std::endl;
    }
}

void Tester::testSwapColumns()
{
	Spreadsheet sp(3, 3);
	int row = sp.getRow();
	int column = sp.getColumn();
	Spreadsheet oldSp(row, column);
	sp.swapColumns(1, 2);
	bool isSwapped = true;
	for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            if (oldSp.getCellAt(r,c).getValue() != sp.getCellAt(r,c).getValue()) {
                isSwapped = false;
                break;
            }
        }
    }
    for (int c = 0; c < column; c++) {
        if (oldSp.getCellAt(c,1).getValue() != sp.getCellAt(c,2).getValue() || 
        	oldSp.getCellAt(c,2).getValue() != sp.getCellAt(c,1).getValue()) {
            isSwapped = false;
            break;
        }
    }
    if (isSwapped) {
        std::cout << "swapColumns Test passed" << std::endl;
    } 
    else {
        std::cout << "swapColumns Test failed" << std::endl;
    }
}