#include <iostream>
using namespace std;

int main()
{
    int quarters, dimes, nickels;
    cout << "Enter the number of each type of coin:\n";

    cout << "Quarters:\n";
    cin >> quarters;

    cout << "Dimes:\n";
    cin >> dimes;

    cout << "Nickels:\n";
    cin >> nickels;


    int total = 25 * quarters + 10 * dimes + 5 * nickels;
	
    cout << "Total: " << total << " cents";

    return 0;
}
