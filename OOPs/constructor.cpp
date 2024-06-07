#include <iostream>
#include <string>
using namespace std;

// TODO--> A constructor is special member of function of class that is automaticaly called when an object of a class is created.

class Student
{
private:
    string name;
    int age;

public:
    //! Default Constructor----->
    //*  This constructor is called when an object is created without any arguments. If you don't provide a constructor, the compiler will generate a default constructor for you. It initializes data members to default values (e.g., 0 for numbers, null for pointers).

    Student()
    {
        cout << "Default constructor has been called.";
    }

    //! Parameterized Constructor---->
    //* This constructor takes parameters that are used to initialize the object's data members. You define and use parameterized constructors when you want to set specific initial values during object creation.


    void setname(string s)
    {
        name = s;
    }
    string getname()
    {
        return name;
    }
    void setage(int x)
    {
        age = x;
    }
    int getage()
    {
        return age;
    }
};
int main()
{
    Student stud;
    return 0;
}