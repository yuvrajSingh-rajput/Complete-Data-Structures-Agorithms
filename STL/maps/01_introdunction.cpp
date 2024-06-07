#include<bits/stdc++.h>
using namespace std;

void print_map(map<string,int>& m){
    for(auto &it: m){
        cout<<it.first<<" "<<it.second<<"\n";
    }
}

int main(){
    map<string,int> people;
    int n;
    cin>>n;
    while(n--){
        string input;
        cin>>input;
        people[input]++;
    }
    print_map(people);
    return 0;
}