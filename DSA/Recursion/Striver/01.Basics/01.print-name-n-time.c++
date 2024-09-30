// Write a program to print a name n times using recursion

#include <bits/stdc++.h>
using namespace std;
string name;
void printName(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << name << endl;
    printName(n - 1);
}
int main()
{
    cin >> name;
    int n;
    cin >> n;
    printName(n);
}