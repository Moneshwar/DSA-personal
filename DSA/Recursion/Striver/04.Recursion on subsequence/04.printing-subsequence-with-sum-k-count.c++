#include <bits/stdc++.h>
using namespace std;

int printSubSequence(int index , int arr[] , vector<int> res , int n , int sum){
    if(index == n){
        int arraySum = accumulate(res.begin(),res.end(),0);
        if(arraySum != sum)
            return 0;
        return 1;
    }
    res.push_back(arr[index]);
    int leftCallRes = printSubSequence(index+1 , arr ,res,n,sum);\
    res.pop_back();
    int rightCallRes = printSubSequence(index+1 , arr ,res,n,sum);
    return leftCallRes + rightCallRes;
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
    cout<<printSubSequence(0 , arr , {} , n ,sum);
    return 0;
}