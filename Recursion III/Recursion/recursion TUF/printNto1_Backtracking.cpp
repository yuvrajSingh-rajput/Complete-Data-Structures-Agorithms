#include<iostream>
using namespace std;

void printNto1_By_BacktrackingHelper(int s,int n){
    if(s>n){
        return;
    }
    return printNto1_By_BacktrackingHelper(s+1,n);
    cout<<s<<" ";
}
void printNto1_By_Backtracking(int n){
    int start = 1;
    printNto1_By_BacktrackingHelper(start,n);
}

int main(){
    printNto1_By_Backtracking(9);
    return 0;
}