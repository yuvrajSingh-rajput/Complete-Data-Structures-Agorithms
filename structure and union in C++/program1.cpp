#include<iostream> 
#include<string>
#include<climits>
#include<cctype>
using namespace std;

struct student{
    string name;
    string roll_number;
    int standard;
    string date_of_birth;
};
int main(){
    struct student stud[3];
    cout<<"Taking the input of data's from student: "<<endl;
    for(int i=0;i<3;i++){
        cout<<"Enter the name of the student "<<(i+1)<<": ";
        getline(cin,stud[i].name);

        cout<<"Enter the Roll Number of the student "<<(i+1)<<": ";
        getline(cin,stud[i].roll_number);

        cout<<"Enter the DOB of the student "<<(i+1)<<": ";
        getline(cin,stud[i].date_of_birth);

        //The problem you face everytime when you switch to string "Getline" from a different data type, because when we press enter string input reads a empty string as an input;
        cout<<"Enter the standard of the student "<<(i+1)<<": ";
        cin>>stud[i].standard;
        cin.ignore(); //By adding cin.ignore() after reading the integer input, you ensure that any leftover newline character in the input buffer is discarded before you proceed to use getline for reading strings.

        cout<<endl;
    }
    cout<<"Printing the data's of the students: "<<endl;
    for(int i=0;i<3;i++){
        cout<<"Name of student "<<i+1<<": "<<stud[i].name<<endl;
        cout<<"Roll Number of student "<<i+1<<": "<<stud[i].roll_number<<endl;
        cout<<"Date of birth of student "<<i+1<<": "<<stud[i].date_of_birth<<endl;
        cout<<"standard of student "<<i+1<<": "<<stud[i].standard<<endl;
        cout<<endl;
    }
    return 0;
}