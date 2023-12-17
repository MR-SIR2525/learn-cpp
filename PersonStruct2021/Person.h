#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string name;
	int age;
};

void getPersonData(Person personData[], int);
void getPersonData(Person personData[], istream & in, int);
void displayPersonData(Person personData[], int);
void displayPersonDataIndirect(Person* pPerson[], int);
void sortByPointers(Person * pPerson[], Person personData[], int);
