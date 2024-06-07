#include<bits/stdc++.h>
using namespace std;

class Calculate{
    private:
    double numerator, denomenator;
    public:
    Calculate(double numerator, double denomenator){
        this->numerator = numerator;
        this->denomenator = denomenator;
        try{
            if(this->denomenator == 0.0){
                throw invalid_argument("Can't divide by zero.");
            }
        }
        catch(exception& e){
            cout<<"Constructor failed "<<e.what()<<endl;
        }
    }
    
    double divide(double numerator, double denomenator){
        try{
            if(denomenator == 0){
                throw invalid_argument("0 is invalid here.");
            }
            cout<<"result is: "<<static_cast<double>(numerator)/denomenator<<endl;
        }
        catch(exception& e){
            cout<<e.what()<<endl;
        }
    }
};

int main(){
    Calculate division(2,3);
    division.divide(3,4);
    return 0;
}