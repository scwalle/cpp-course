/* Project 2.6 */
/*
$16.78 per hour for first 40 hours

overtime rate of 1.5x normal rate

6% of gross(total) for ss tax
14% for federal income tax
5% for state
$10 per week is withhelf for union dues

if 3 or more dependants, then an additional $35 doallrs in withwheld for health insurace

Inputs:
hours worked in a week
number of dependants

Output:
Gross pay
ss tax
federal tax
state tax
union dues
net takehome pay
*/

#include <iostream>
using namespace std;


const double HOURLY_RATE = 16.78;
const double OVERTIME_RATE = 1.5 * HOURLY_RATE;
// tax rates
const double SOCIAL_SECURITY_RATE = 0.06;
const double STATE_TAX_RATE = 0.05;
const double FEDERAL_TAX_RATE = 0.14;

const double UNION_DUES = 10.0;

const int HEALTH_INSURANCE_DEPENDANT_THRESHOLD = 3;
const double HEALTH_INSURANCE_DEPENDANT_FEE = 35.00;

void getPay(){
	int hours, dependants;
	cout << "Number of dependants: ";
	cin >> dependants;

	cout << "Hours worked during the week: ";
	cin >> hours;
	
	double gross, ss, fed, state;
	if (hours <= 40){
		gross = hours * HOURLY_RATE;
	} else {
		double overtime = hours - 40;
		gross = 40 * HOURLY_RATE + overtime * OVERTIME_RATE;
	}
	cout << "\nGross Pay: $" << gross << endl << endl;

	cout << "---Deductions---\n";
	// taxes
	ss = SOCIAL_SECURITY_RATE * gross;
	cout << "Social Security Tax: $" << ss << endl;

	fed = FEDERAL_TAX_RATE * gross;
	cout << "Federal Tax: $" << fed << endl;
	state = STATE_TAX_RATE * gross;
	cout << "State Tax: $" << state << endl;

	double takehome = gross - ss - fed - state - UNION_DUES;
	
	if (dependants >= HEALTH_INSURANCE_DEPENDANT_THRESHOLD){
		takehome -= HEALTH_INSURANCE_DEPENDANT_FEE;	
	}
	cout << endl;
	cout << "Takehome Pay: $" << takehome << endl;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		getPay();
		
		cout << "\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
// need: 5, 6, 7, 9, 13, 14
