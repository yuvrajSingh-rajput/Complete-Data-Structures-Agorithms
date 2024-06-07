#include<iostream>
using namespace std;

class Subject{
    private:
    string subject;
    int credits;
    public:
    // Setting subject function.
    void setSubject(string sub){
        subject = sub;
    }
    //Setting credits function.
    void setCredit(int k){
        credits = k;
    }
    //Getting subject function;
    string getSubject(){
        return subject;
    }
    //Getting credit function.
    int getcredit(){
        return credits;
    }
};
int main(){
    int number;
    cout<<"Enter the number of subjects in your semester: ";
    cin>>number;
    Subject SemSub[number];
    string sub[number]; int cred[number],sum =0;
    for(int i=0;i<number;i++){
        cout<<"input for subject "<<(i+1)<<"------------>"<<endl<<endl;
        cout<<"Enter the subject "<<(i+1)<<" name: ";
        cin>>sub[i];
        cout<<"Enter the subject "<<(i+1)<<" credits: ";
        cin>>cred[i];    
        cout<<endl;   
    }
    for(int i=0;i<number;i++){
        SemSub[i].setSubject(sub[i]);
        SemSub[i].setCredit(cred[i]);
    }
    for(int i=0;i<number;i++){
         cout<<"Output for subject "<<(i+1)<<"------------>"<<endl<<endl;
        cout<<"Name of Subject "<<(i+1)<<" is: "<<SemSub[i].getSubject()<<endl;
        cout<<"Number of credits of Subject "<<(i+1)<<" is: "<<SemSub[i].getcredit()<<endl;
        cout<<endl;
    }
    for(int i=0;i<number;i++){
        sum = sum + SemSub[i].getcredit();
    }
    cout<<"The total sum of credits in this semester is: "<<sum;
    
    return 0;
}