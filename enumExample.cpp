/*  */
#include <iostream>

using namespace std;

enum Day {MONDAY=1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
//        0       1        2          3         4
int main()
{
    Day today;
    today = static_cast<Day>(2);

    //cout << today << endl;
    switch(today)
    {
        case MONDAY: cout << "Monday\n";
            break;
        case TUESDAY: cout << "Tuesday\n";
            break;
        case WEDNESDAY: cout << "Wednesday\n";
            break;
        case THURSDAY: cout << "Thursday\n";
            break;
        case FRIDAY: cout << "Friday\n";
            break;
    }

    for (int workday=MONDAY; workday <= FRIDAY; workday++)
        cout << workday+1 << endl;

    return 0;
}
