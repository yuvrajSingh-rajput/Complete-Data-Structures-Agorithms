#include <iostream>
#include <memory>
using namespace std;

//! If we want to count the total object then we should use static variable as it retains its value after function call inside a class; Here we cannot use simple int count; var because every object have their own and new count variable;

class Employee
{
private:
    static int count;
    int id;

public:
    void setdata(void)
    {
        cout << "Enter the id of employee: ";
        cin >> id;
        count++;
    }
    void getdata(void)
    {
        cout << "The id of the Employee number " << count << " is: " << id << endl;
    }

    //! Static functions :: static methods can only access static data members and other static methods of the class. ! have(this ptr)
    static void Getcount(void)
    {
        cout << "The value of count is: " << count << endl;
    }
};

int Employee::count; // Default value is zero.

int main()
{
    Employee m1, m2, m3;
    m1.setdata();
    m1.getdata();
    Employee::Getcount();

    m2.setdata();
    m2.getdata();
    Employee::Getcount();

    m3.setdata();
    m3.getdata();
    Employee::Getcount();

    return 0;
}

// TODO::----> CONST: Indicates that the function won't modify the content of the string passed as an argument.
//? Example:
 
static bool startsWith(const std::string& str, const std::string& prefix) {
     return str.substr(0, prefix.length()) == prefix;
 }