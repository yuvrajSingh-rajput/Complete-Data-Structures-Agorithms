#include<iostream>
#include<algorithm>
using namespace std;
int lowerBound(int *arr,int n,int lb){
    int s = 0, e = n - 1,ans = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(*(arr+mid)>=lb){
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid +1;
        }
    }
    return ans;
}
int main(){
    int arr[10] = {1,2,3,3,7,8,9,9,9,11};
    // searching for 9;
    cout << lowerBound(arr,10,9)<<endl;
    
    //! there is an inbuilt fuction to calculate lower_bound whuch needs the address from-to the index;
    int * ptr = (lower_bound(arr,arr+10,9));    //? It means it is searching from index [2,6] where n = element to be searched;
    cout<<*ptr;  //* output == 9;(value);

    return 0;
}