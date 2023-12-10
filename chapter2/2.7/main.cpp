/* Project 2.7 */
#define cin >> x cin >> x; cout << x << endl
#include <iostream>
using namespace std;


//Constants

void getPay(){
	double cost = 0;
	cout << "Cost of item: $";
	cin >> cost;

	double inflationPercent = 0.0;
	cout << "Inflation rate (input as a percentage): ";
	cin >> inflationPercent;
	double inflationRate = inflationPercent / 100;

	int years = 0;
	cout << "Number of years: ";
	cin >> years;

	for(int i = 0; i < years; i++){
		cost += cost * inflationRate;
	}

	cout << "Item cost after " << years << " year" << (years == 1 ? "" : "s") << " of inflation: $" << cost << endl;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		getPay();
		
		cout << "\nTry again? (enter to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
// need: 5, 6, 7, 9, 13, 14
