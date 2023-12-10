/* Project 2.9 */
#include <iostream>
using namespace std;


//Constants

void getSums(){
	int posSum = 0;
	int negSum = 0;
	int totSum = 0;

	for (int i = 0; i < 10; i++){
        int n;
        cout << "Number " << i+1 << ": ";
        cin >> n;
        if (n > 0) posSum += n;
        else negSum += n;
        totSum += n;
    }

    cout << endl;
    cout << "Positive sum: " << posSum << endl;
    cout << "Negative sum: " << negSum << endl;
    cout << "Total sum: " << totSum << endl;

    return;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		getSums();
		
		cout << "\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
// need: 5, 6, 7, 9, 13, 14
