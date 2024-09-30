#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int>arr) {
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printSubSequence(int index , int arr[] , vector<int> res , int n){
    if(index == n){
        printArr(res);
        return;
    }
    res.push_back(arr[index]);
    printSubSequence(index+1 , arr ,res,n);
    res.pop_back();
    printSubSequence(index+1 , arr ,res,n);
}

int main() {  
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    printSubSequence(0 , arr , {} , n);
    return 0;
}


// Time Complexity : O(2^n * n)  ==> Extra *n for printing
// Space Complexity : O(n)

// Sample Input:

// 3
// 1 2 3

// Sample Output:

// 1 2 3
// 1 2 3 
// 1 2 
// 1 3 
// 1 
// 2 3 
// 2 
// 3 