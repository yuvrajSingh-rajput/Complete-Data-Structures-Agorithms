#include <iostream>
using namespace std;
void printData(void)
{
    class Person
    {
    public:
        string name;

        class Address
        {
        public:
            string country;
            int age;
        };
        Address address;

        void getdata()
        {
            cout << name << endl;
            cout << address.country << endl;
            cout << address.age << endl;
        }
    };
    Person person;
    person.address.country = "Bharat";
    person.address.age = 25;
    person.name = "Yuvraj Singh";
    person.getdata();
}
int main()
{
    printData();
    return 0;
}