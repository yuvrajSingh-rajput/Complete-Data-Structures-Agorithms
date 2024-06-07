#include<bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> &arr){
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> hash(maxi + 1, 0);
    for(int i = 0; i < arr.size(); i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i < hash.size(); i++){
        hash[i] = hash[i] + hash[i - 1];
    }
    vector<int> result(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--){
        int index = hash[arr[i]] - 1;
        result[index] = arr[i];
    }
    return result;
}

int main(){
    vector<int> arr = {34, 12, 23, 90, 22, 0};
    vector<int> result = countingSort(arr);
    for(auto &it : result){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}