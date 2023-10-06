#include <iostream>
using namespace std;

int main()
{
    int exerciseCount;
    int earnedTotal = 0;
    int pointsTotal = 0;
    cout << "Number of classrom exercises: ";
    cin >> exerciseCount;
    cout << endl;
    for(int i = 0; i < exerciseCount; i++){
        int score, possible;
        cout << "Score received for exercise " << i+1 << ": ";
        cin >> score;
        earnedTotal += score;

        cout << "Total points possible for exercise " << i+1 << ": ";
        cin >> possible;
        pointsTotal += possible;
    }

    float totalGrade = ((float) earnedTotal) / ((float) pointsTotal);
    totalGrade *= 100;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Your total is " << earnedTotal << " out of " << pointsTotal << ", or " << totalGrade << "%";

    return 0;
}