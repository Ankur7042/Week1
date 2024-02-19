#include <bits/stdc++.h>
using namespace std;

int main()
{
     long int n;
     int first, End, Swap, digit, divide;
     cout << "Enter the number :--> ";   //for eg: 5623
     cin >> n;
     digit = log10(n);  // 3
     divide = pow(10,digit); //1000
     first = n / divide; //5
     n = n % divide; //623
     End = n % 10; //3
     n = n / 10; //562
     Swap = End * divide + n * 10 + first;  //3 * 1000 + 623 * 10 + 5
     cout << "Swap value is : " << Swap;
     return 0;
}