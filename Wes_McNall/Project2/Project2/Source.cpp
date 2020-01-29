// Wes McNall
// wwmgbr@mail.umkc.edu
// 1/28/2020
// CS201R Program 2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int Display_Menu();
void ActivateMenu(int choice);

int main() {

	int choice;

	// Display menu and get correct choice
	choice = Display_Menu();
	// Activate logic for that choice
	ActivateMenu(choice);

	return 0;
}

void _Show_Menu() {
	cout << "Welcome to the paint shop" << endl;
	cout << "We have a couple options you can choose from: " << endl;
	cout << "1- Paint the interior of a house" << endl;
	cout << "2- Paint the exterior of a house" << endl;
	cout << "3- Paint both interior and exterior of a house" << endl;
	cout << "What option fits you more?" << endl;
}

int Display_Menu() {
	int input;
	// Displays menu
	_Show_Menu();

	// Fails if a letter is inputted
	cin >> input;
	while ((input != 1) && (input != 2) && (input != 3)) {
		cout << "Please input a valid number" << endl;
		cin >> input;
	}
	return input;
}

int House_Area(int height, int width) {
	return height * width;
}

int _Paint_Interior(string where) {
	int walls, length, height, area = 0;
	cout << "Now, how many "<< where <<" walls do you want to paint" << endl;
	cin >> walls;
	for (int i = 1; i <= walls; i++) {
		cout << "What is the length and height for wall " << i << ":" << endl;
		cout << "Length = ";
		cin >> length;
		cout << endl;
		cout << "Height = ";
		cin >> height;
		cout << endl;
		area += House_Area(length, height);
	}
	
	return area;
}

int _Paint_Exterior() {
	return _Paint_Interior("exterior");
}

float Num_Paintcans(int area) {
	return area / 400.0;
}

void _Cost_Summary(int total_cost, string side) {

	cout << "Now lets caculate the cost to paint the " << side << " of the house " << endl;
	cout << "The price of the can is $ " << total_cost << endl;

	return;
}

int Summary(int area) {
	float cans = Num_Paintcans(area);
	int round_cans;

	cout << "As each can covers 400 feet" << endl;
	cout << "With area = " << area << " square feet, you will need to get " << cans << endl;

	round_cans = static_cast<int>(cans + 1);
	cout << "So in total we need " << round_cans << " cans" << endl << endl;

	return round_cans;
}

int _Interior_Cost(int cans) {
	return cans * 100;
}

int _Exterior_Cost(int cans) {
	return cans * 150;
}

int _Activate_Interior(int cans, int total_cost) {
	cans = Summary(_Paint_Interior("interior"));
	total_cost = _Interior_Cost(cans);
	_Cost_Summary(total_cost, "interior");
	return total_cost;
}

int _Activate_Exterior(int cans, int total_cost) {
	cans = Summary(_Paint_Exterior());
	
	total_cost = _Exterior_Cost(cans);
	_Cost_Summary(total_cost, "exterior");

	return total_cost;
}

void ActivateMenu(int choice) {
	int area, cans=0, total_cost=0;
	if (choice == 1) {
		total_cost = _Activate_Interior(cans, 0);
	}
	else if (choice == 2) {
		total_cost = _Activate_Exterior(cans, 0);
	}
	else { // choice == 3 
		total_cost = _Activate_Interior(cans, 0);
		total_cost += _Activate_Exterior(cans, 0);
	}

	cout << "The total cost is $ " << total_cost << endl;
}