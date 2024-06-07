//? We can avoid the structure padding by simply writting the {#pragma pack(1);} This process is known as structure packing.

#include<iostream>
using namespace std;
struct student{
    char name[13];
    int age;
    double salary;
};
int main(){

    //! it does not increase its word size depending upon the type of variable, since it is 64-bit system so, it is reading 8-bit in one CPU cycle..... And to reduce the number of CPU cycle, the concept of structure padding was evolved.
    
    struct student stud1;
    cout<<sizeof(stud1);
    return 0;
}