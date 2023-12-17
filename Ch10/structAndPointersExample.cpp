#include <iostream>
#include <iomanip>  // input/output manipulation
using namespace std;

struct GradeInfo
{
    string name;
    int *testScores;
    double average;
};

int main()
{
    GradeInfo student1;
    int numGrades, sum = 0;

    cout << "Enter the name of the student: ";
    cin >> student1.name;
    cout << "How man grades do you want to enter? "; 
    cin >> numGrades;

    student1.testScores = new int[numGrades];
    
    for(int i = 0; i < numGrades; i++)
    {
        cout << "Enter grade " << i+1 << " for this student: ";
        cin >> student1.testScores[i];
        sum += student1.testScores[i];      
    }
    
    student1.average = sum/numGrades;
    cout << "The average for " << student1.name << " is " << student1.average << endl;

    delete [] student1.testScores;
    student1.testScores = nullptr;

    return 0;


}