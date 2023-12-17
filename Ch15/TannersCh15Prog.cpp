/********************************************
 * Student name:
 * Assignment name:
 * File name:
 * Description:
 * Date: 
 ********************************************/

#include <iostream>

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

char GradedActivity::getLetterGrade() const 
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

class Essay : public GradedActivity
{
private:
	double grammar;
	double spelling;
	double correctLen;
	double content;

public:
	Essay() : GradedActivity()
	{
		/*
		grammar=0;
		spelling=0;
		correctLen=0;
		content=0;
		*/
	}
	Essay(double grammar, double spelling, double correctLen, double content)
	{
		this-> grammar = grammar;
		this-> spelling = spelling;
		this-> correctLen = correctLen;
		this-> content = content;
	}
	void setPoints(double grammar, double spelling, double correctLen, double content)
	{
		//void setscore(); ////you don't need to declare a function here
		setScore(grammar+spelling+correctLen+content);
		////really, setPoints() is redundant and pointless in this template she gave us
		////bc of the setScore() member function of the base class...  but we'll use setPoints()
		////to call setScore() because setScore() is already ready for us to use (it's what I did)		
	}
	double getGrammar()
	{
		return grammar;
	}
	void setGrammar(double grammar)
	{
		if (grammar > 0.0 && grammar <= 30.0)
			this->grammar = grammar;
		else
			this->grammar = 0.0;
	}
	double getSpelling()
	{
		return spelling;
	}
	void setSpelling(double spelling)
	{
		if (spelling > 0.0 && spelling <= 20.0)
			this->spelling = spelling;
		else
			this->spelling = 0.0;
	}
	double getCorrectLength()
	{
		return correctLen;
	}
	void setCorrectLength(double correctLen)
	{
		if (correctLen > 0.0 && correctLen <= 20.0)
			this->correctLen = correctLen;
		else
			this->correctLen = 0.0;
	}
	double getContent()
	{
		return content;
	}
	void setContent(double content)
	{
		if (content > 0.0 && content <= 30.0)
			this->content = content;
		else
			this->content = 0.0;
	}
};

int main()
{
    double grammar = 0.0, 
           spelling = 0.0, 
           correctLen = 0.0, 
           content = 0.0;

	//////////Need to create class object
	Essay elEsse;

	cout <<"Grammar can be no more than 30 points." <<endl;
	cout << "Enter the points for grammar" <<endl;
	cin >> grammar;
	//setGrammar(grammar);  ////you're calling a class-only function as if it were a normal function
	elEsse.setGrammar(grammar); 
	////here I'm specifying the function "setGrammar" for elEsse's type, which is "Essay"

	cout << "Spelling can be no more than 20 points." <<endl;
	cout << "Enter the points for spelling" <<endl;
	cin >> spelling;
	elEsse.setSpelling(spelling); ////same idea as above

	cout << "Correct length can be no more than 20 points." <<endl;
	cout << "Enter the points for Correct length" <<endl;
	cin >> correctLen;
	elEsse.setCorrectLength(correctLen); ////same idea as above

	cout << "Content can be no more than 30 points." <<endl;
	cout << "Enter the points for content" <<endl;
	cin >> content;
	elEsse.setContent(content); ////same as above

	////set points here then...
	elEsse.setPoints(grammar, spelling, correctLen, content);

	////your getScore() and getLetterGrade() essay class functions would be here with whatever "cout" u want
		//// #3 and #4 To Do's 
	double myScore = elEsse.getScore();
	char gradeTemp = elEsse.getLetterGrade();

	cout << myScore << " " << gradeTemp;
	
	

    //TO DO
    //  1. Ask the user to enter the points for grammar, spelling correctLen, and content
		//done
    //  2. Create an object of type Essay by calling the overloaded constructor
		//done
    //  3. Display the numeric grade for the Essay object
		//
    //  4. Display the letter grade for the Essay object
	
    
return 0;
}