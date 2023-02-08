class Date
{
public:
	Date(int, int, int);
	void setYear(int);
	int getYear() const;
	void setMonth(int);
	int getMonth() const;
	void setDay(int);
	int getDay() const;
private:
	int year;
	int month;
	int day;
};