#include<iostream>
#include<string>
using namespace std;
struct student{
    string name;
    int marks[3];
};
float average_of_marks(student s){
    float sum = 0;
    for(int i=0;i<3;i++){
        sum = sum + s.marks[i];
    }
    sum = sum / float(3);
    return sum;
}
void printStudentByValue(student s){
    cout<<"The name of the student is: "<<s.name<<endl;
    cout<<"Average marks scored by the student: "<<average_of_marks(s);
}
int main(){
    struct student stud;
    cout<<"Enter the name of the student: ";
    getline(cin,stud.name);
    for(int i=0;i<3;i++){
        cout<<"Enter the marks of the student in subject "<<(i+1)<<": ";
        cin>>stud.marks[i];
    }
    printStudentByValue(stud);
    return 0;
}