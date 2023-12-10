/* Project 2.13 */
#include <iostream>
using namespace std;


//Constants

void getBars(){
    const float CHOCOLATE_BAR_CALORIES = 230.0;
	float weight, height, age;
    char sex;

    cout << "Weight in pounds: ";
    cin >> weight;

    cout << "Height in inches: ";
    cin >> height;

    cout << "Age in years: ";
    cin >> age;

    cout << "Sex (m/f): ";
    cin >> sex;

    float BmR;

    if (sex == 'm' || sex == 'M'){
        BmR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    } else if (sex == 'f' || sex == 'F'){
        BmR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    }

    float numOfBars = BmR / CHOCOLATE_BAR_CALORIES;

    cout << "Number of bars needed to maintain weight: " << numOfBars << endl;

    return;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		getBars();
		
		cout << "\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
// need: 5, 6, 7, 9, 13, 14
