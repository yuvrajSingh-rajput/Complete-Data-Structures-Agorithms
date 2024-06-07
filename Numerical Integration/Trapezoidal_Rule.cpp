#include <iostream>
#include <vector>
using namespace std;

double Calculation_Via_Formula(const vector<double>& y, double h,int n){
    double FirstPart = y.front()  + y.back(); double LastPart = 0;
    for(int i=0;i<n;i++){
        LastPart += y[i];
    }
    LastPart -= y[0];
    double result = (double)(h/2)*((FirstPart) + 2*(LastPart));
    return result;
}
int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
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
        cout<<"The result after the simpson's rule: "<<Calculation_Via_Formula(y,h,n); 
    
    return 0;
}