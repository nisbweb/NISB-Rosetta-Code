#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    int x,y,z;
    for (x = 0; x < n; x++)
    {
        int r = 1;
        if(x==0)
        {
            int l,t;
            t = n/2;
            for(l=2;l<t-2;l++)
            {
                cout << " ";
            }
        }
        for (y = 1; y < (n - x); y++)
        {
            cout << "   ";
        }
        for (z = 0; z <= x; z++)
        {
            cout << "      " << r;
            r = r * (x - z) / (z + 1);
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}