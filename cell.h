#include "date.h"
#include <string>

enum class Color{red = 1, blue, green, pink, purple, black, white, grey};

class Cell{
public:
	Cell() = default;
	Cell(const std::string&, Color);
	void setValue(const std::string&);
	std::string getValue() const;
	int toInt();
	double toDouble();
	Date toDate();
	void reset();
	void setColor(Color color);
	Color getColor() const;
private:
	std::string m_value;
	Color m_color;
};