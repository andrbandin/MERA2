#include "DateTime.h"

//public
DateTime::DateTime(int dd, int mm, int yy){
	time( &dt_it );
	struct tm* t;
	t = localtime( &dt_it );            
	t -> tm_mday = dd;
	t -> tm_mon = mm - 1;
	t -> tm_year = yy - 1900;                    
	dt_it = mktime( t );
};

DateTime::DateTime(){
	time(&dt_it);
};

DateTime::DateTime(const DateTime &dateTime) {
    dt_it = dateTime.getDt_it();
}

void DateTime::printToday(){
	printDate(0);
};

void DateTime::printYesterday(){ 
	printDate(-1);
}
void DateTime::printTomorrow(){
	printDate(1);
}
void DateTime::printFuture(int days){
	printDate(days);
}
void DateTime::printPast(int days){
	printDate(-days);
}

void DateTime::printMonth(){
	cout << put_time( localtime(&dt_it), "%B") << endl;
}

void DateTime::printWeekDay(){
	cout << std::put_time( localtime(&dt_it), "%A") << endl;
}	

int DateTime::calcDifference(DateTime date){
	return dt_it / 86400 - date.getDt_it() / 86400; 
}

//private
time_t DateTime::getDt_it() const {
    return dt_it;
}

void DateTime::printDate(int days) const{
	time_t printIt = dt_it + days * 86400;
	cout << put_time( localtime( &printIt ), "%A, %d %B %Y") << endl;
}