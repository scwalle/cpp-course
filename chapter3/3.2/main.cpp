#include <iostream>
#include <cmath>
using namespace std;


void twoReal(float a, float d, float rest){
	float disc = ( sqrt(d) / (2*a) );
	cout << "There are two real solutions:\n" 
		 << "x = " << rest + disc << endl
		 << "x = " << rest - disc;
}

void twoComplex(float a, float d, float rest){
	float imag = sqrt(-d) / (2*a);
	cout << "There are two complex solutions:\n" 
		 << "x = " << rest << " + " << imag << "i\n"
		 << "x = " << rest << " - " << imag << "i\n";
}

void oneReal(float rest){
	cout << "There is one real solution:\n" 
		 << "x = " << rest << endl;
}

void run(){
	float a, b, c;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;
	
	// discriminant
	float d = b*b - (4 * a * c);
	float rest = (-b / (2*a));
	if (d > 0) { // 2 real roots
		twoReal(a, d, rest);
	} else if (d < 0) { // 2 complex roots
		twoComplex(a, d, rest);
	} else { // d == 0, 1 real root
		oneReal(rest);
		// return rest;
	}
}

int main(){
	/* cout.setf(ios::fixed); */
	/* cout.setf(ios::showpoint); */
	cout.precision(5);

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
