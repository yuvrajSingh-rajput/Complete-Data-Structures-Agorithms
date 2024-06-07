#include<iostream>
using namespace std;

class Peoples{
    private:
    string name;
    int age;
    string gender;
    char favlet;

    public:
    void setName(string Name){
        name = Name;
    }
    void setAge(int Age){
        if(Age>=0){
            age = Age;
        }
        else{
            cout<<"Since because the age never can be a negative number so, setting the age is 0."<<endl;
            age = 0;
        }
    }
    void setGender(string Gender){
        gender = Gender;
    }
    void setfavlet(char ch){
        if(ch>='A' && ch<='Z'){
            favlet=ch;
        }
        else if(ch>='a' && ch<='z'){
            favlet = ch;
        }
        else{
            favlet = 'A';
            cout<<"By default";
        }
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getGender(){
        return gender;
    }
    char getfavlet(){
        return favlet;
    }
};

int main(){
    int num;
    cout << "Enter the number of person for which you want to store the data: ";
    cin>>num;
    cout<<endl;
    string pname[num],pgen[num]; char pch[num]; int page[num];
    Peoples people[num];
    for(int i=0;i<num;i++){
        cout<<"Input for person "<<(i+1)<<"--------->"<<endl<<endl;
        cout<<"Enter the name of person "<<(i+1)<<": ";
        cin>>pname[i];
        cout<<"Enter the age of person "<<(i+1)<<": ";
        cin>>page[i];
        cout<<"Enter the gender of person "<<(i+1)<<": ";
        cin>>pgen[i];
        cout<<"Enter the favorite charecter alphabet of person "<<(i+1)<<": ";
        cin>>pch[i];
        cout<<endl<<endl;
    }
    cout<<"--------------------------------------------------------------------------------------------------------------------------------";
    cout<<"Printing the data -------------->"<<endl;

    for(int i=0;i<num;i++){
        people[i].setName(pname[i]);
        people[i].setAge(page[i]);
        people[i].setGender(pgen[i]);
        people[i].setfavlet(pch[i]);
    }

    for(int i=0;i<num;i++){
        cout<<"Output for person "<<(i+1)<<"--------->"<<endl<<endl;

        cout<<"The name of person "<<(i+1)<<" is: "<<people[i].getName()<<endl;
        cout<<"The age of person "<<(i+1)<<" is: "<<people[i].getAge()<<endl;
        cout<<"The gender of person "<<(i+1)<<" is: "<<people[i].getGender()<<endl;
        cout<<"The favorite charecter of person "<<(i+1)<<" is: "<<people[i].getfavlet()<<endl;

        cout<<endl<<endl;
    }

    return 0;
}