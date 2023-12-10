#include <iostream>
using namespace std;

double basalMetabolicRate(double weight) {
	return 70.0 * (weight / 2.2) * 0.756;
}

double physicalActivity(double weight, double minutes, double intensity) {
	return 0.0385 * intensity * weight * minutes;
}

double digestion(double calories) {
	return calories / 10.0;
}

void run(){
	// inputs
	// weight
	// intensity of physical activity
	// # of mins spent
	// number of calories in one serving of favorite food
	double weight, intensity, exerciseTime, calories;

	cout << "Weight: ";
	cin >> weight;
	cout << "Intensity: ";
	cin >> intensity;
	cout << "Exercise Time: ";
	cin >> exerciseTime;

	cout << "Calories: ";
	cin >> calories;

 	cout << endl;
	cout << "Basal Metabolic Rate: " << basalMetabolicRate(weight) << endl;
	cout << "Physical Activity: " << physicalActivity(weight, exerciseTime, intensity) << endl;

	double caloriesNeeded = basalMetabolicRate(weight) + physicalActivity(weight, exerciseTime, intensity);
	caloriesNeeded += digestion(calories);
	
	cout << "Total Calories Needed: " << caloriesNeeded << endl;
	cout << "Servings to eat: " << ( caloriesNeeded / calories ) << endl;
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
	} while (true);

	return 0;
}
