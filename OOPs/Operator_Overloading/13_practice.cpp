#include<bits/stdc++.h>
using namespace std;

//* ios :: ate -> go to the end of the file on opening.
//* ios :: app -> append to end of the file
//? [app] allow us to add data at the end of the file only while [ate] can add at the end as well as modify existing content anywhere.

//* FILE POINTERS->
// 1. seekg() or seekp() moves get/put pointer to a specified location.
// 2. tellg() or tellp() gives the current position of get/put pointer.

// put() writes a single charecter to the associated stream.
// get() reads a single charecter to the associated stream.


int main(){
    string sentence;
    cout<<"Enter the string: ";
    getline(cin,sentence);

    fstream file;
    cout<<"\nopening the file and storing the string it."<<endl;
    file.open("13_text.txt", ios::in | ios::out);
    
    for(int i = 0; i<sentence.length(); i++){
        file.put(sentence.at(i));
    }

    file.seekg(0);

    char ch;
    cout<<"\nreading the file contents."<<endl;
    while(!file.eof()){
        file.get(ch);
        cout<<ch;
    }
    file.seekg(0,ios::end);
    file.close();
    return 0;
}