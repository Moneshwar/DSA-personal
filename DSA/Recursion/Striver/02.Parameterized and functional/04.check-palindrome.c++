#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(int l , int r ,string str) {

    if (l >= r) {
        return true;
    }
    if(str[l] != str[r])
        return false;
    return palindromeCheck(l+1 , r-1 , str);
}

int main() {  
    string str;
    cin>>str;
    cout<<palindromeCheck(0,str.length()-1 ,str);
    return 0;
}