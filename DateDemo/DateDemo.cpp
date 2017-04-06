#include <iostream>
#include <ctime>
#include "DateTime.h"


using namespace std;

int main () {
	DateTime d1;
	d1.printToday();
	d1.printTomorrow();
	d1.printFuture(3);
	d1.printPast(3);
	d1.printMonth();
	d1.printWeekDay();
	d1.printYesterday();

	DateTime d2(10, 04, 2017);
	d2.printToday();
	d2.printTomorrow();
	d2.printFuture(3);
	d2.printPast(3);
	d2.printMonth();
	d2.printWeekDay();
	d2.printYesterday();
	d2.calcDifference(d1, d2);


	system("pause");
	return 0;


}