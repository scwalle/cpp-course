#include <iostream>
using namespace std;

double hatSize(int weight, int height) {
	return ((double) weight / (double) height) * 2.9;
}

int main()
{
    int height, weight, age;
    cout << "Height: ";
    cin >> height;

    cout << "Weight: ";
    cin >> weight;

    cout << "Age: ";
    cin >> age;
    cout << endl;

    cout << "Hat size:";
    cout << hatSize(height, weight) << endl;

    return 0;
}
