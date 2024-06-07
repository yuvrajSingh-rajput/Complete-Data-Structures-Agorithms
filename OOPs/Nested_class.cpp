#include<iostream>
using namespace std;

class outerClass{
    public:
    string name;
    class InnerClass{
        public:
        string country;
        string stname;
        int home_no;
    };
    InnerClass Address;
    void printData(){
        cout<<name<<endl<<Address.country<<endl<<Address.stname<<endl<<Address.home_no<<endl;
    }
};
int main(){
    outerClass class1;
    class1.name = "Yuvraj Singh";
    class1.Address.country = "Bharat";
    class1.Address.stname = "Ram";
    class1.Address.home_no = 23;

    class1.printData();
    return 0;
}