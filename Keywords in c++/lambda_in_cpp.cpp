//? (1) Lambda is known as anonymous function, used inline with code.
//? (2) It is used for creating small reusable and concise function, espacially when you need function for short-lived purpose.

/*  SYNTAX:----------->

    [ captures ] ( parameters ) -> return_type {
    // Lambda body (function code)
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void forEach(const vector<int>&arr,void(*function)(int)){
    for(int value: arr){
        function(value);
    }
}
int main(){
    vector<int>values = {1,2,3,4,5};
    auto lambda = [](int value){ cout<<"Value is: "<<value<<endl; };
    forEach(values,lambda);
    return 0;
}