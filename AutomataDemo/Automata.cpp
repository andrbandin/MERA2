#include "Automata.h"
#include <iomanip>
#include <string>



//private

void Automata::get() {
	

		for (int i = 0; i < 4; i++)
		{
			cout << "\n Name: \t";
			cin >> pricelist[i].au_menu;
			cout << "\n Cost: \t";
			cin >> pricelist[i].au_price;
			cout << endl;
		}
		show();
	}


void Automata::show(){

	for (int i = 0; i < 4; i++)
	{
		cout << pricelist[i].au_menu << "\t\t";
		cout << pricelist[i].au_price << endl;

	}
	cout << endl;
	system("pause");

}


//void Automata::get() {
//	cout << "Enter bottle" << endl;
//	const int n = 4;
//	bottle aray[n] = {};
//	for (int i = 0; i<n; i++) {
//		cout << "\n Name: \t";
//		cin >> aray[i].au_menu;
//		cout << "\n Cost: \t";
//		cin >> aray[i].au_price;
//		cin.get();
//
//	}
//	show(aray, n);
//	cout << endl;
//	system("pause");
//}

void Automata::on() {
	system("cls");
	cout << "Launching...";
	delay(2);
	au_state = CHOICE;
}

void Automata::off() {
	au_state = OFF;
	system("cls");
	cout << "Shutdown...";
	delay(2);
	printState();
}

void Automata::coin() {
	au_state = CHOICE;
	int cash;
	cin >> cash;
	au_cash += cash;
}

void Automata::printMenu() {
	double a = 0.7;
	string b = "Empty";
	cout << "Your balance: " << au_cash << " rub.\n";
	cout << "Select a drink:" << endl;
	cout << "Number\t\tDrink\t\t\tCost\n";
	int num = 1;
	for (int i = 0; i < 5; i++) {
		if (num < 5) {
			cout << num << "\t\t" << pricelist[i].au_menu;
			//cout << "\t\t\t" << au_price[i];
			//cout << "\t\t\t" << setprecision(4) << au_litre[i] << endl;
			if (au_litre[i] > a) { cout << "\t\t\t" << pricelist[i].au_price << endl; }
			else if (au_litre[i] < a) { cout << "\t\t\t" << b << endl; }


			num++;

		}

	}
	cout << "...or replenish the balance (usage 'r' for replenish).\n";
	cout << "Enter 'cancel' to receive change: ";
	choice();
}

void Automata::printState() {
	system("cls");
	switch (au_state) {
	case CHOICE:
		printMenu();
		break;
	case CHECK:
		cout  <<"Not enough money or no drink. "<< endl ;
		printMenu();
		break;
	case COOK:
		cook();
		finish();
		break;
	case OFF:
		cout << "The machine is off. Enter start to 'start' the machine\n";
		cout << "or 'exit' for output\n";
		cout << "(Use 'stop' to stop the machine running): ";
		break;
	}
}

void Automata::choice() {
	string ch;
	cin >> ch;
	int num;
	if (ch == "1" || ch == "2" || ch == "3" || ch == "4") {
		num = stoi(ch);
		cout << num;
		check(num - 1);
	}
	else if (ch == "r") {
		coin();
	}
	else if (ch == "cancel") {
		cancel();
	}
	else if (ch == "stop") {
		off();
	}
	else {
		printState();
	}
}

void Automata::check(int number) {
	double a = 0.7; 
	if (au_cash >= pricelist[number].au_price && au_litre[number] >= a) {
		au_cash -= pricelist[number].au_price;
		au_litre[number] -= a;
	    au_state = COOK;

	}
	else {
		au_state = CHECK;
	}
	printState();
}

void Automata::cancel() {
	if (au_cash != 0) {
		au_cash = 0;
		system("cls");
		cout << "Get change.";
		delay(3);
	}
	printState();
}

void Automata::cook() {
	cout << "Please wait..." << endl;
	delay(4);
}

void Automata::finish() {
	cout << "Drink is ready.";
	delay(2);
	au_state = CHOICE;
}

void Automata::delay(int sec) {
	time_t timeReference, timeGet;
	time(&timeReference);
	timeReference += sec;
	while (true) {
		if (time(&timeGet) == timeReference) {
			break;
		}
	}
}


//public

Automata::Automata() {
	au_state = OFF;
	au_cash = 0;
	/*string buff;
	int ibuff;
	double ilitre;
	ifstream fin("menu.txt");
	for (int i = 0; i < 4; i++) {
		fin >> buff;
		au_menu[i] = buff;
		
		fin >> buff;
		ibuff = stoi(buff);
		au_price[i] = ibuff;

		fin >> buff;
		ilitre = stoi(buff);
		au_litre[i] = ilitre;
	}
	fin.close();*/
}




void Automata::offline() {
	string status;
	while (true) {
		printState();
		cin.clear();

		if (au_state == OFF) {
			cin >> status;
			if (status == "start") on();
			else if (status == "exit") break;
		}
	}
}
