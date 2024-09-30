// Print from 1 to n 
#include <bits/stdc++.h>
using namespace std;
int n;
void printFrom1ToN(int i,int n)
{
    if (n+1 == i)
    {
        return;
    }
    cout << i << endl;
    printFrom1ToN(i+1 , n);
}
int main()
{
    cin >> n;
    int i = 1;
    printFrom1ToN(i,n);
}