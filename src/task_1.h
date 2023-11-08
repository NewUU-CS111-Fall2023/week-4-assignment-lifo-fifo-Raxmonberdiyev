/*
 * Author:
 * Date:
 * Name:
 */
#include <bits/stdc++.h>

using namespace std;

bool prime(long long a)
{
    if(a > 3)
        for(int j=2; j<=sqrt(a); j++)
        {
            if(!(a%j))
                return true;
        }
    return false;
}

int main()
{
    long long n;
    cin >> n;
    for(int i=1; i<=10000; i++)
    {
        if(prime(i*n+1))
        {
            cout << i;
            return 0;
        }
    }



    return 0;
}