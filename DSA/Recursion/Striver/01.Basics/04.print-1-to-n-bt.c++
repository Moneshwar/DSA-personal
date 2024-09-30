// Print from 1 to n using recursion backtracking
#include <bits/stdc++.h>
using namespace std;
void printFrom1ToN_BT(int n)
{
    if (n == 0)
    {
        return;
    }
    printFrom1ToN_BT(n-1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    printFrom1ToN_BT(n);
}