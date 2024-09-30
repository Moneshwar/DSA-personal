// Parametterized way

#include <bits/stdc++.h>
using namespace std;

void factorial(int i , int res) {

    if (i == 0) {
        cout<<res;
        return ;
    }
    factorial(i-1 , res*i);
}

int main() {  
    int n;  
    cin >> n;
    factorial(n , 1);
    return 0;
}


---------------------------------------------------


// Functional way

#include <bits/stdc++.h>
using namespace std;

int factorial(int i) {

    if (i == 1) {
        return 1;
    }
    int res = i * factorial(i-1);
    return res;
}

int main() {  
    int n;  
    cin >> n;
    cout<<factorial(n);
    return 0;
}