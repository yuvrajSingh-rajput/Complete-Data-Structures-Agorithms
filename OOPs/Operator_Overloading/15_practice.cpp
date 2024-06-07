#include<bits/stdc++.h>
using namespace std;

class INVENTORY{
    char name[10];
    int code;
    float cost;
    public:
    void getdata(void){
        cout<<"Enter name: ";cin>>name;
        cout<<"Enter code: ";cin>>code;
        cout<<"Enter cost: ";cin>>cost;
    }
    void putdata(void){
        cout<<setw(10)<<name<<setw(10)<<code<<setprecision(2)<<setw(10)<<cost<<endl;
    }
};

int main(){
    INVENTORY item;
    fstream inoutfile;
    inoutfile.open("STOCK.DAT", ios::ate | ios::in | ios::out | ios::binary);
    inoutfile.seekg(0,ios::beg);
    cout<<"CURRENT CONTENT OF THE STOCK"<<endl;
    while(inoutfile.read((char*)&item, sizeof(item))){
        item.putdata();
    }
    inoutfile.clear();
    
    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ADD MORE ITEMS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

    cout<<"\nADD AN ITEM\n";
    item.getdata();
    char ch;
    cin.get(ch);
    inoutfile.write((char*) &item, sizeof(item));

    //Display the appended file.
    inoutfile.seekg(0);
    cout<<"CONTENTS OF THE APPNEDED FILE"<<endl;
    while(inoutfile.read((char*)& item, sizeof(item))){
        item.putdata();
    }
    //Find number of objects in the file.
    int last = inoutfile.tellg();
    int n = last/sizeof(item);
    cout<<"Number of objects = "<<n<<endl;
    cout<<"Total bytes in the file = "<<last<<endl;

    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MODIFY THE DETAILS OF AN ITEMS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

    cout<<"Enter objected number to be updated"<<endl;
    int object;
    cin>>object;
    cin.get(ch);
    int location = (object-1)*sizeof(item);
    if(inoutfile.eof()){
        inoutfile.clear();
    }
    inoutfile.seekp(location);
    cout<<"Enter new values of the object\n";
    item.getdata();
    cin.get(ch);
    inoutfile.write((char*)&item, sizeof(item))<<flush;

    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SHOW UPDATED FILE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
    inoutfile.seekg(0);
    cout<<"CONTENTS OF THE UPDATED FILE"<<endl;

    while(inoutfile.read((char*)&item,sizeof(item))){
        item.putdata();
    }
    inoutfile.close();
    return 0;
}