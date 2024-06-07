#include<iostream>
using namespace std;

int length_of_string(char s[]){
    if(s[0] == '\0'){
        return 0;
    }
    return 1 + length_of_string(s+1);
}

void remove_character(char s[], char target){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != target){
        remove_character(s+1,target);
    }else{
        int i = 1;
        for(;s[i]!='\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        remove_character(s,target);
    }
}

int main(){
    char ch[100];
    cin>>ch;
    remove_character(ch,'a');
    cout<<ch<<endl;
    cout<<length_of_string(ch)<<endl;
    return 0;
}