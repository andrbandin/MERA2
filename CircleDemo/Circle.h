#pragma once
#include <iostream>
#include <cmath>
#define pi 3.14159

using namespace std;

class Circle {


public:

	void setR(double set_Rad) {

		Radius = set_Rad;
		Ference = 2 * pi * Radius;
		Area = pi * pow(Radius, 2);
							  }


	void setE(double set_Fer) {

		Ference = set_Fer;
		Radius = Ference / (2 * pi);
		Area = pi * pow(Radius, 2);
						      }



	void setA(double set_Ar) {

		Area = set_Ar;
		Radius = sqrt(Area / pi);
		Ference = 2 * pi * Radius;
	                         }


	void get() {

		cout <<"Radius - "<< Radius << endl;
		cout <<"Ference - " << Ference << endl;
		cout <<"Area - " << Area << endl;
		cout << endl;

	}


	double get_Radius() {
		return Radius;
	}
	double get_Ference() {
		return Ference;
	}
	double get_Area() {
		return Area;
	}


private:

	double Radius, Ference, Area;


};
