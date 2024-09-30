// Print from n to 1 using recursion
#include <bits/stdc++.h>
using namespace std;
int n;
void printFromNTo1(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printFromNTo1(n-1);
}
int main()
{
    cin >> n;
    printFromNTo1(n);
}