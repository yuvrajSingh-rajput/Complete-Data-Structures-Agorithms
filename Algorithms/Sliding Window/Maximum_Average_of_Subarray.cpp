#include<iostream>
#include<vector>
using namespace std;

double Maximum_Average_Subarray(vector<int>& nums, int length){
    double sum = 0;
    for(int i = 0;i<length;i++){
        sum = sum + nums.at(i);
    }
    double avg = (double)sum/length;
    //Slide the window and remove the elements one by one from start.
    for(int i = length;i<nums.size();i++){
        sum = sum + nums.at(i) - nums.at(i-length); // Update the sum by adding the new element and removing the old one.
        double temp = (double) sum / length;
        avg = max(temp,avg);
    }
    return avg;
}

int main(){
    vector<int>v;
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    v.resize(size);
    cout<<"Enter the elements: "<<endl;
    for(int i = 0;i<size;i++){
        cin>>v.at(i);   //Input: nums = [1,12,-5,-6,50,3], k = 4 || Output: 12.75000
    }
    cout<<Maximum_Average_Subarray(v,4)<<endl;
    return 0;
}