#include <iostream>
using namespace std;


/* 
   * Hat size = weight in pounds divided by height in inches and all that multiplied by 2.9. 
*/

double hatSize(int weight, int height) {
	return ((double) weight / (double) height) * 2.9;
}

/* 
	
	* Jacket size (chest in inches) = height times weight divided by 288 and
	* then adjusted by adding 1/8 of an inch for each 10 years over age 30.
	* (note that the adjustment only takes place after a full 10 years. So,
	* there is no adjustment for ages 30 through 39, but 1/8 of an inch is
	* added for age 40.)

*/
double jacketSize(int height, int weight, int age) {
	double w = (double)weight;
	double h = (double)height;
	// intentional integer division; 1/8 in for each full 10 years over 30
	// 1/8 * floor((age - 30) / 10)
	double adjustment;

	if (age > 30) {
		adjustment = (1.0 / 8.0) * (int) ((age - 30) / 10);
	} else {
		adjustment = 0;
	}

	return (h * w) / 288.0 + adjustment;
}

/*

Waist in inches = weight divided by 5.7 and then adjusted by adding 1/10
of an inch for each 2 years over age 28. (note that the adjustment only
takes place after a full 2 years. So, there is no adjustment for age 29,
but 1/10 of an inch is added for age 30.)

*/
double waistSize(int weight, int age) {
	double adjustment = 0.1 * (int) ((age - 28) / 2);
	return ((double)weight / 5.7) + adjustment;
}

void run()
{
    int height, weight, age;
    cout << "Height: ";
    cin >> height;

    cout << "Weight: ";
    cin >> weight;

    cout << "Age: ";
    cin >> age;
    cout << endl;

    cout << "Hat size: ";
    cout << hatSize(height, weight) << endl;

    cout << "Jacket Size: ";
    cout << jacketSize(height, weight, age) << endl;

    cout << "Jacket Size: ";
    cout << waistSize(height, age) << endl;
}

int main(){
	do {
		cout << endl;
		run();

		cout << endl << endl;
		cout << "Run again? (y/n): ";
		char loop;
		cin >> loop;
		if (loop == 'n' || loop == 'N') break;
		// loop == '\n' ||
		/* cin >> noskipws >> loop; */
	} while (true);

	return 0;
}
