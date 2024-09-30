// Print from n to 1 using recursion backtracking
#include <bits/stdc++.h>
using namespace std;
void printFromNTo1_BT(int i,int n)
{
    if (n+1 == i)
    {
        return;
    }
    printFromNTo1_BT(i+1,n);
    cout << i << endl;
}
int main()
{
    int n;
    cin >> n;
    int i = 1;
    printFromNTo1_BT(i,n);
}