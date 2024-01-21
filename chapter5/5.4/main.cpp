#include <iostream>
#include <string.h>
using namespace std;

const int coinNum = 3;
const string coinStrings[coinNum] = { 
	"quarter(s)", 
	"dime(s)", 
	"penn(y/ies)"
};
const int coins[coinNum] = { 
	25,
	10,
	1
};

void compute_coins(int coin_value, int &num, int &amount_left) {
	num = 0;
	while (amount_left >= coin_value) {
		amount_left -= coin_value;
		num++;
	}
}

void printCoins(int coins[], const std::string strings[], int length) {
/* void printCoins(int coins[], int length) { */
	for (int i = 0; i < length; i++) {
		cout << coins[i] << " " << coinStrings[i] << ( (i != length-1) ? ", " : ".\n" );
	}
}

/*
Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
Postcondition: num has been set equal to the maximum number
of coins of denomination coin_value cents that can be
obtained from amount_left. Additionally, amount_left has
been decreased by the value of the coins, that is,
decreased by num * coin_value.
*/



void doCode(){
	int cents = 0;
	cout << "Enter cents:\n";
	cin >> cents;
	cout << "Cents: " << cents << endl;
	int change[coinNum] = {0};
	for (int i = 0; i < coinNum; i++) {
		int coin = 0;
		compute_coins(coins[i], coin, cents);
		change[i] = coin;
	}
	/* printCoins(change, coinNum); */
	printCoins(change, coinStrings, coinNum);
}
	
int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		doCode();
		
		cout << "\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
