#include "DateTime.h"
#include <conio.h>
#include <ctime>
#include <stdio.h>

int main(){
	cout << "Creation of four exemplars of the date and demonstrating the method printToday:" << endl;
	DateTime date1 = DateTime();
	DateTime date2 = DateTime(20, 03, 2017);
	DateTime date3 = DateTime(date1);
	DateTime date4 = DateTime(1, 1, 2017);
	date1.printToday();
	date2.printToday();
	date3.printToday();
	date4.printToday();

	cout << "Demonstrating methods printYesterday and printTomorrow:" << endl;
	date1.printYesterday();
	date1.printTomorrow();

	cout << "Demonstrating methods printFuture and printPast in steps of 7 days:" << endl;
	date1.printFuture(7);
	date1.printPast(7);

	cout << "Month and week output:" << endl;
	date1.printMonth();
	date1.printWeekDay();

	cout << "Output of the difference of days of the first and second dates: " << date1.calcDifference(date2) << endl; 

	_getch();
	return 0;
}