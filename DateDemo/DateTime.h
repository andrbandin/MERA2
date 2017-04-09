#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

class DateTime {
public:
	DateTime(int dd, int mm, int yy);	
	DateTime();
	DateTime( const DateTime &dateTime);

	void printToday();
	void printYesterday();
	void printTomorrow();
	void printFuture(int days);
	void printPast(int days);
	void printMonth();
	void printWeekDay();
	int calcDifference(DateTime date);

private:
	time_t dt_it;
	time_t getDt_it() const;
	void printDate(int day) const;

};