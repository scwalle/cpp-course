/* Project 2.5 */
#include <iostream>
using namespace std;

int main(){
	while(true){
		int maxcap, people;
		cout << "Max capacity: ";
		cin >> maxcap;

		cout << "Number of people attending: ";
		cin >> people;
		if(people == maxcap) cout << "Meeting is legal but at max capacity; no room for more people.";
		if(people < maxcap) cout << "Meeting is legal with room for " << maxcap - people << " more " << ((maxcap - people) == 1 ? "person." : "people.");
		if(people > maxcap) cout << "Meeting is in violation of fire reglations. " << people - maxcap << " less " << (people - maxcap == 1 ? "person" : "people") << " must attend in order for the meeting to proceed.";

		cout << endl << endl;
		cout << "Run again? (y/n): ";
		char loop;
		cin >> loop;
		if (loop == 'n' || loop == 'N') return 0;
		// loop == '\n' ||
		/* cin >> noskipws >> loop; */
	}
}
// need: 5, 6, 7, 9, 13, 14
