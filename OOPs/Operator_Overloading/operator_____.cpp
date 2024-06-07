#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int age;
    static int id_p;
    static int id_s;
    virtual void getdata(void);
    virtual void putdata(void);
    virtual ~Person() {}  // Virtual destructor
};


class Professor: virtual public Person{
    private:
    int publications, cur_id;
    public:
    Professor(void){
        this->cur_id = id_p;
        this->id_p++;
    }
    void getdata(void) override{
        cin>>this->name>>this->age>>this->publications;
    }
    void putdata() override{
        cout<<this->name<<" "<<this->age<<" "<<this->publications<<" "<<this->cur_id<<endl;
    }
};
Person:: ~Person() {} 
int Person::id_p = 1;
int Person::id_s = 1;

class Student: virtual public Person{
    private:
    int marks[6];
    int curr_id;
    public:
    Student(void){
        this->curr_id = id_s;
        this->id_s++;
    }
    void getdata(void) override{
        cin>>this->name>>this->age>>this->marks[0]>>this->marks[1]>>this->marks[2]>>this->marks[3]>>this->marks[4];
    }
    void putdata(void) override{
        cout<<this->name<<" "<<this->age<<" "<<(marks[0]+marks[1]+marks[2]+marks[3]+marks[4])<<this->curr_id<<endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
