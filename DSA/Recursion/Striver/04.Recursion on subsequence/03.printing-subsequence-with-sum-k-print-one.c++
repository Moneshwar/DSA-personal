#include <bits/stdc++.h>
using namespace std;

bool printSubSequence(int index , int arr[] , vector<int> res , int n , int sum){
    if(index == n){
        int arraySum = accumulate(res.begin(),res.end(),0);
        if(arraySum != sum)
            return false;
        for(int i : res){
            cout<<i<<" ";
        }
        return true;
    }
    res.push_back(arr[index]);
    bool leftCallRes = printSubSequence(index+1 , arr ,res,n,sum);\
    if(leftCallRes)
        return true;
    res.pop_back();
    bool rightCallRes = printSubSequence(index+1 , arr ,res,n,sum);
    if(rightCallRes)
        return true;
    return false;
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