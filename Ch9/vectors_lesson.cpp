#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> grades(10); // Declaring size of vector
    vector<string> names;
    vector<char> letterGrade(15, 'A');
    vector<int> points(grades);
    vector<string> cities{ "Hattiesburg", "Petal", "Laurel" };

    for (int i = 0; i < letterGrade.size(); i ++)
    {
        cout << letterGrade[i] << endl;
    }

    /*for(string val: cities)
        cout << val << endl; */

    cities.push_back("New Orleans");
    cities.push_back("Beatville");

    // Range-based for loop
    /*cout << "\nNew cities: \n";
    for(string val: cities)
        cout << val << endl; */

    names.push_back("Alpha Bro");
    names.push_back("Joe");
    names.push_back("Bob");
    names.push_back("Bruh");
    names.push_back("Smiff");


    cout << "\n___Names:___\n";
    cout << "Size of names: " << names.size() << endl;
        for(string val: names)
            cout << val << endl;

    names.pop_back(); // pops the name last created/added.
    cout << "\n___Names after pop_back completed. " << endl;
    cout << "Size of names: " << names.size() << endl;
        for(string val: names)
            cout << val << endl;

    return 0;
}
