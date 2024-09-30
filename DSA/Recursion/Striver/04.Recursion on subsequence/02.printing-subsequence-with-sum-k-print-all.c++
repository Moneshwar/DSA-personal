
// This code is to print all subsequences whose sum is k
#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int>arr,int sum) {
    int arraySum = accumulate(arr.begin(),arr.end(),0);
    if(arraySum != sum)
        return;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printSubSequence(int index , int arr[] , vector<int> res , int n , int sum){
    if(index == n){
        printArr(res ,sum);
        return;
    }
    res.push_back(arr[index]);
    printSubSequence(index+1 , arr ,res,n,sum);
    res.pop_back();
    printSubSequence(index+1 , arr ,res,n,sum);
}

int main() {  
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    printSubSequence(0 , arr , {} , n ,sum);
    return 0;
}