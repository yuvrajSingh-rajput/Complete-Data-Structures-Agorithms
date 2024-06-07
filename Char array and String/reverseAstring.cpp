#include<iostream>
using namespace std;
#include<string>
void reverse_method_2(char ch[],int str_length){
    int s = 0,e = str_length-1;
    while(s<=e){
        swap(ch[s++],ch[e--]);
        // s++; e--;
    }
}
int length(char ch[]){
    int count = 0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    return count;
}
// void reverse_method_1(char ch[],int str_length){
//     for(int i=str_length-1;i>=0;i--){
//         cout<<ch[i];
//     }
// }
int main(){
    char ch[14];
    cin>>ch; 
    // string str;
    // getline(cin,str);
    cout<<"String before reversing: "<<ch<<endl;
    int str_length = length(ch);
    // reverse_method_1(ch,str_length);
    return 0;
}