/******************************************************************************
* Student Name:  Andrew Blythe
* Program Name: Chapter 17 Prog Assignment
* Program Description: Lets user fill a list of integers with 5 numbers, then
                       asks user to type a number to check if it's in the list.
                       Then program will print the whole list out, and then
                       print it out reversed.
*******************************************************************************/
#include <iostream>
using namespace std;

class ListNode //The Node for the list items
{
public:
    ListNode(double v, ListNode *p)
    {
       v = value; p = next;
    }
private:
    double value;
    ListNode *next;
    friend class LinkedList; //LinkedList  has friend status
    
};

//The LinkedList class itself
class LinkedList
{
public:
    void add(double x);
    bool isMember(double x);
    void print();
    void reverse();
    LinkedList( ) { head = NULL;}
    ~LinkedList();
private:
    ListNode * head;
};

int main()
{
    //Explain program to user
    cout << "This program constructs a list of numbers and then allows the user "
         <<  "\nto check if various numbers are in the list." << endl;

    //New empty list
    LinkedList list1;

    //Get numbers from user and add them to list
    cout << "\nEnter 5 numbers: ";
    for (int k = 1; k <= 5; k++)
    {
        double number;
        cin >> number;
        list1.add(number);
    }

    //Allow user to test membership
    for (int k = 1; k <= 5; k++)
    {
        double x; //testing membership (top/main)
        cout << "Enter a number to test membership for: ";
        cin >> x;
        if (list1.isMember(x))
        {
            cout << "\n" << x << " is in the list." << endl;
        }
        else
        {
            cout << "\n" << x << " is not in the list." << endl;
        }
    }
    cout << "The list consists of:  ";
    list1.print();
    cout << "\n";

    cout << "The list in reverse: ";
    list1.reverse();

    return 0;
}

/*************************************
*        LinkedList::add             *
*  Adds a given value to the list.   *
*************************************/
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

/***********************************************************
*          LinkedList::isMember (recursive)                *
* Checks to see if a given value is a member of the list.  *
***********************************************************/
bool LinkedList::isMember(double x)
{
    bool found;// = false;
    int first = 0;
    ListNode *nodePtr;

    if(first == 0)
    {
        nodePtr = head;
        first = 1;
    }

    if(!nodePtr)
        found = false;
    else if(nodePtr -> value == x)
        found = true;
    else // if number is not found, moves to next node
    {
        nodePtr = nodePtr -> next;
        //found = isMember(x);
        return isMember(x);
    }
    return found; //says if it was found or not
}

/******************************************
*           prints out the list           *
/*****************************************/
void LinkedList::print()
{
    ListNode *nodePtr = head;
    if(head == NULL)
    {
        cout << "The list is empty." << endl;
    }
    while (nodePtr)
    {
        cout << nodePtr -> value << "  " << endl;
        nodePtr = nodePtr -> next;
    }
}

/******************************************
*    Deallocates memory for the list.     *
******************************************/
LinkedList::~LinkedList()
{
   while (head != 0)
   {
       ListNode * p = head;
       head = head->next;
       delete p;
   }
}

/******************************************
*           reverses the list             *
******************************************/
void LinkedList::reverse()
{
    if (head == NULL || head -> next == NULL) return;
    ListNode* p = head;
    ListNode* r = p-> next; p-> next = NULL;

    while (r != NULL)
    {
        ListNode* temp = r -> next;
        r-> next = p;
        p = r;
        r = temp;
    }
    head = p;

}