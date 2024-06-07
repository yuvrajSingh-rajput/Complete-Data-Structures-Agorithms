#include<bits/stdc++.h>
using namespace std;

int main(){
    int query;
    cin>>query;
    set<int> s;
    while(query--){
        int choice, value;
        cin>>choice>>value;
        if(choice == 1){
            s.insert(value);
        }else if(choice == 2){
            set<int>::iterator it = s.find(value);
            if(it != s.end()){
                s.erase(value);
            }
        }else{
            set<int>::iterator it = s.find(value);
            if(it != s.end()){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}