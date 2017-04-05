#include <iostream>
#include "Circle.h"

using namespace std;

int main() {

	//------------------------------The Earth and the rope

	Circle Earth, Roop;
	Earth.setR(6378100);
	//Earth.get();

	Roop.setE(1);
	//Roop.get();

	Roop.setE(Earth.get_Ference() + Roop.get_Ference());
	cout << "Gap - " << Roop.get_Radius() - Earth.get_Radius() << endl;
	system("pause");
	

	//----------------------------------The pool

	Circle Pool, PoolTrack;
	Pool.setR(3);
	PoolTrack.setR(4);

	//PoolTrack.get();
	//Pool.get();

	double PriArTrack = (PoolTrack.get_Area() - Pool.get_Area()) * 1000;
	//cout << PriArTrack << endl;
	double PriFerFence = (PoolTrack.get_Ference()) * 2000;
	//cout << PriFerFence << endl;
	cout << "Cost of materials = " << PriArTrack + PriFerFence << " rub\n";



	system("pause");
	return 0;
}