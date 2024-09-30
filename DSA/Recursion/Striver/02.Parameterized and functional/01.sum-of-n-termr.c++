// In the parameterized way, the function itself prints the answer

#include <bits/stdc++.h>
using namespace std;

void sumRec(int i , int sum) {

    if (i == 0) {
        cout << sum << endl;
        return;
    }
    sum += i;
    sumRec(i-1,sum);
}

int main() {  
    int n;  
    cin >> n;
    sumRec(n,0);
    return 0;
}

---------------------------------------------------

// In the functional way, the function itself returns the answer

#include <bits/stdc++.h>
using namespace std;

int sumRec(int i) {

    if (i == 0) {
        return 0;
    }
    int sum = i + sumRec(i-1);
    return sum;
}

int main() {  
    int n;  
    cin >> n;
    cout<<sumRec(n); 
    return 0;
}