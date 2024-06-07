#include<iostream>
using namespace std;

void print1toN_By_BacktrackingHelper(int e,int n){
    if(e<1){
        return;
    }
    print1toN_By_BacktrackingHelper(e-1,n);
    cout<<e<<" ";
}
void print1toN_By_Backtracking(int n){
    print1toN_By_BacktrackingHelper(n,n);
}
int main(){
    print1toN_By_Backtracking(9);
    return 0;
}