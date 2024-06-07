#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //writing in the file;
    ofstream out("program_File_1.txt");
    string s;
    getline(cin,s);
    for(int i = 0;i<10;i++){
        out<<s<<"\t"<<s<<endl;
    }
    out.close();

    //reading from the file;
    ifstream in("program_File_1.txt");
    string st;
    cout<<endl<<endl<<endl;
    while (getline(in, st)) {
        cout << st << endl;
    }
    in.close();

    return 0;
}