#include <iostream>
#include <string>
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(int r, int c)
{
	row = r;
	column = c;
	Cell cell("1", Color::blue);
	for (int i = 0; i < r; ++i) {
		std::vector<Cell> row;
		for (int j = 0; j < c; ++j) {
			row.push_back(cell);
		}
		m_cells.push_back(row);
  	}
}

int Spreadsheet::getRow()
{
	return m_cells.size();
}

int Spreadsheet::getColumn()
{
	return m_cells[0].size();
}

void Spreadsheet::setCellAt(int r, int c, Cell cl){
	m_cells[r][c] = cl;
}

void Spreadsheet::setCellAt(int r, int c, const std::string& cl)
{
	m_cells[r][c].setValue(cl);
}

Cell Spreadsheet::getCellAt(int r, int c) const
{
	return m_cells[r][c];
}

void Spreadsheet::addRow(int r, const std::vector<Cell>& row)
{
	m_cells.insert(m_cells.begin() + r, row);
}

void Spreadsheet::removeRow(int r)
{
	m_cells.erase(m_cells.begin() + r);
}

void Spreadsheet::addColumn(int c, const std::vector<Cell>& column)
{
	int rows = getRow();
    	int cols = getColumn();
    	for (int i = 0; i < rows; ++i) {
        	m_cells[i].resize(cols + 1);
        	for (int j = cols; j > c; --j) {
            		m_cells[i][j] = m_cells[i][j-1];
        	}
        	m_cells[i][c] = column[i];
    	}
}

void Spreadsheet::removeColumn(int c)
{
	int rows = m_cells.size();
    	int cols = m_cells[0].size();
    	for (int i = 0; i < rows; ++i) {
        	for (int j = c; j < cols - 1; ++j) {
            		m_cells[i][j] = m_cells[i][j+1];
        	}
        	m_cells[i].resize(cols - 1);
    	}
}

void Spreadsheet::swapRows(int r1, int r2)
{
	std::vector<Cell> temp = m_cells[r1];
    	m_cells[r1] = m_cells[r2];
    	m_cells[r2] = temp;
}

void Spreadsheet::swapColumns(int c1, int c2)
{
	int rows = m_cells.size();
    	for (int i = 0; i < rows; ++i) {
        	Cell temp = m_cells[i][c1];
        	m_cells[i][c1] = m_cells[i][c2];
        	m_cells[i][c2] = temp;
    	}
}
