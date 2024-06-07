#include <iostream>
using namespace std;

// This algorithm is to calculate the GCD or HCF of two give numbers;


//! Time Complexity O[min(num1,num2)];
void GCD_method1(int num1, int num2)
{
    int ans = -1;
    for (int i = 1; i != num1 && i != num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            ans = i;
        }
    }
    cout << ans << endl;
}
//? (a>b): a = a%b;

//* Euclidean algorithm says: GCD(a,b) = GCD(a-b,b), Provided [a>b];----- It reduces Time Complexity;
//! Time Complexity O[min(num1-num2,num2)];
int gcd(int a,int b)
{
	
	while(a>0 && b>0){
		if(a>b){
			a = a%b;
		}
		else{
			b = b%a;
		}
	}
	if(a == 0){
		return b;
	}
	else{
		return a;
	}
}
int main()
{
    GCD_method1(16,4);
    return 0;
}