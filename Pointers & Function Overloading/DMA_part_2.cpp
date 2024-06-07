#include<iostream>
using namespace std;

int main(){
    char ch = 'q';
    cout<<sizeof(ch)<<endl;
    char *p = &ch;
    cout<<sizeof(p)<<endl;   

    //* Creating an array;
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin>>(*(arr+i));    //! arr[i] = *(arr + i);
    }
    return 0;
}