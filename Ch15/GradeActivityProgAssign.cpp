/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: 
 * Program description: 
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class GradedActivity
{
    private:
        double score;
    public:
        GradedActivity()
        {
            score = 0.0;
        }
        GradedActivity(double s)
        {
            score = s;
        }

        void setScore(double s)
        {
            score = s;
        }
        double getScore() const
        {
            return score;
        }

        char getLetterGrade() const;
};

char GradedActivity::getLetterGrade() const //finds/calculates letter grade based on number score
{
	char letterGrade;

	if (score > 89) {
		letterGrade = 'A';
	}
	else if (score > 79) {
		letterGrade = 'B';
	}
	else if (score > 69) {
		letterGrade = 'C';
	}
	else if (score > 59) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}

	return letterGrade;
}

class Essay : public GradedActivity //pass: (grammar, spelling, correctLen, content)
{
private:
	double grammar;
	double spelling;
	double correctLen; //correctLength 
	double content;

public:
	Essay() : GradedActivity()
	{
		//TO DO
	}
	Essay(double grammar, double spelling, double correctLen, double content)
	{
		//TO DO
		setGrammar(grammar);
		setSpelling(spelling);
		setCorrectLength(correctLen);
		setContent(content);
		//updated with "this->" to use correct variable after its value's been verified
		setPoints(this->grammar, this->spelling, this->correctLen, this->content);
		//auto calculates and stores total score through "setPoints(...)"
	}
	void setPoints(double &grammar, double &spelling, double &correctLen, double &content)
	{
		//TO DO 
		//Because "score" is a private variable of base class, have to use this function to 
		//backdoor-set score, to keep this template as unchanged as possible...
		
		setScore(grammar+spelling+correctLen+content); //calculates and stores total score
	}
	void setGrammar(double grammar)
	{
		if (grammar > 0.0 && grammar <= 30.0)
			this->grammar = grammar;
		else
			this->grammar = 0.0;
	}
	void setSpelling(double spelling)
	{
		if (spelling > 0.0 && spelling <= 20.0)
			this->spelling = spelling;
		else
			this->spelling = 0.0;
	}
	void setCorrectLength(double correctLen)
	{
		if (correctLen > 0.0 && correctLen <= 20.0)
			this->correctLen = correctLen;
		else
			this->correctLen = 0.0;
	}
	void setContent(double content)
	{
		if (content > 0.0 && content <= 30.0)
			this->content = content;
		else
			this->content = 0.0;
	}
	double getGrammar()
	{
		return grammar;
	}
	double getSpelling()
	{
		return spelling;
	}
	double getCorrectLength()
	{
		return correctLen;
	}
	double getContent()
	{
		return content;
	}
	
};



int main()
{
    double grammar = 0.0, 
           spelling = 0.0, 
           correctLength = 0.0, 
           content = 0.0;
	int numAssignments = 0;
	vector<shared_ptr<Essay>> essaysArr; //vector of graded objects, in this case essays (for loop)

    //TO DO
    //  1. Ask the user to enter the points for grammar, spelling correctLength, and content
	cout << "In this program, you can enter the points received by various students." << endl
		 << "You'll be asked for marks recieved on: grammar, spelling, essay length, and content." << endl << endl;
	cout << "How many students will you be entering essay grades for? ";
	cin >> numAssignments;
	while(!cin || numAssignments < 0)
	{
		cin.clear();  cin.ignore();
		cout << "Invalid entry. Must be an integer larger than 0.";
		cin >> numAssignments;
	}
	cout << endl;

	for(int sss = 0; sss < numAssignments; sss++)
	{
		cout << endl << "STUDENT #" << sss+1 << "   Points received for..." << endl;
		cout << "Grammar (up to 30): ";	
		cin >> grammar;
			while(!cin || grammar < 0)
			{
				cin.clear();  cin.ignore();
				cout << "Invalid entry. Must be an integer larger than 0: ";
				cin >> grammar;
			}
		cout << "Spelling (up to 20): ";	
		cin >> spelling;
			while(!cin || spelling < 0)
			{
				cin.clear();  cin.ignore();
				cout << "Invalid entry. Must be an integer larger than 0: ";
				cin >> spelling;
			}
		cout << "Essay Length (up to 20): ";	
		cin >> correctLength;
			while(!cin || correctLength < 0)
			{
				cin.clear();  cin.ignore();
				cout << "Invalid entry. Must be an integer larger than 0: ";
				cin >> correctLength;
			}
		cout << "Essay Content (up to 30): "; 
		cin >> content;
			while(!cin || content < 0)
			{
				cin.clear();  cin.ignore();
				cout << "Invalid entry. Must be an integer larger than 0: ";
				cin >> content;
			}
		
		//  2. Create an object of type Essay by calling the overloaded constructor
		essaysArr.push_back(make_shared<Essay>(grammar, spelling, correctLength, content)); 
		//inserting new essay object into vector of Assignments
	}
    
	cout << endl;
	double scoreTemp;
	char letterGradeTemp;

	for (int i = 0; i < numAssignments; i++)
	{
		//  3. Display the numeric grade for the Essay object
		//  4. Display the letter grade for the Essay object
		scoreTemp = essaysArr[i]->getScore();
		letterGradeTemp = essaysArr[i]->getLetterGrade();

		cout << endl << "STUDENT #" << i+1 << ":" << endl;
		cout << "Total score on essay = " << scoreTemp << endl;
		
		cout << "        Letter grade = " << letterGradeTemp << endl;
	}
	
	
	cout << endl << "End of program, goodbye!";
	return 0;
}