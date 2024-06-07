#include <iostream>
#include <vector>
using namespace std;

// Checking if Simpson's 1/3 rule can be applied;
bool Check_Simpson(int k)
{
    if (k % 2 == 0)
    {
        return true;
    }
    return false;
}
double Calculation_Via_Formula(const vector<double>& y, double h){
    double FirstPart = y.front()  + y.back();
    double MiddlePart = 0;  double LastPart = 0;
    for(int i=0;i<y.size();i++){
        if(i%2==0){
            LastPart += y[i];
        }
        else{
            MiddlePart += y[i];
        }
    }
    LastPart -= y[0];
    double result = (double)(h/3)*((FirstPart) + 4*(MiddlePart) + 2*(LastPart));
    return result;
}
int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    if (Check_Simpson(n))
    {
        vector<double> x(n+1);
        vector<double> y(n+1);
        // Taking input from User based on statistical data;
        cout << "Enter the values for the x with a constant interval: " << endl;
        for(int i=0;i<x.size();i++){
            cin>>x[i];
        }
        cout<<endl;
        cout << "Enter the values for the y with a constant interval: " << endl;
        for(int j=0;j<y.size();j++){
            cin>>y[j];
        }
        // calculation of h;
        double h = x[1] - x[0];
        cout<<"The result after the simpson's rule: "<<Calculation_Via_Formula(y,h); 
    }
    else{
        cout<<"Simpson's Rule can not be applied, since n is not multiple of 2."<<endl;
    }
    return 0;
}