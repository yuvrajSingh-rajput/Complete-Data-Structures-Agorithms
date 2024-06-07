#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    //write your code here
        int *max = &ar[0];
    for(int i=0;i<n;i++){
        if(*max<*(ar+i)){
            max = (ar+i);
        }
    }
    return max;
}

int main()
{
   int n;
   cin>>n;
   int ar[n];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }
   int *ans =findmax(ar,n);
   cout<<*ans;
    
}