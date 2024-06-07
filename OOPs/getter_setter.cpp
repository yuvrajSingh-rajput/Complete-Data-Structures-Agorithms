#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    // setter for the name member
    void setName(string newName)
    {
        name = newName;
    }
    // getter for the name member
    string getName()
    {
        return name;
    }
    // Setter for the age member
    void setAge(int newAge)
    {
        if (newAge >= 0)
        {
            age = newAge;
        }
        else
        {
            cout << "Age cannot be negative.Setting age 0.";
            age = 0;
        }
    }

    // getter for age member.
    int getAge()
    {
        return age;
    }
};
int main()
{
    Person person;

    // using the setter functions to set the value of private members
    person.setName("john");
    person.setAge(30);

    // using the getter function to access the values form private part.
    cout << "name: " << person.getName() << endl;
    cout << "age: " << person.getAge()<<endl;

    return 0;
}