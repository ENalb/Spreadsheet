#include <string>
#include <vector>
#include "cell.h"

class Spreadsheet{
public:
	Spreadsheet() = default;
	Spreadsheet(int, int);
	int getRow();
	int getColumn();
	void setCellAt(int, int, Cell);
	void setCellAt(int, int, const std::string&);
	Cell getCellAt(int, int) const;
	void addRow(int, const std::vector<Cell>&);
	void removeRow(int);
	void addColumn(int, const std::vector<Cell>&);
	void removeColumn(int);
	void swapRows(int, int);
	void swapColumns(int, int);
private:
	std::vector<std::vector<Cell>> m_cells;
	int row;
	int column;
};