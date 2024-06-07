#include<iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(nullptr)));
    int minimum_range = 1;
    int maximum_range = 3;
    int random_Number = minimum_range + (rand()%(maximum_range-minimum_range + 1));
    cout<<"Random Number between "<<minimum_range<<" & "<<maximum_range<<" is: "<<random_Number<<endl;
    return 0;
}