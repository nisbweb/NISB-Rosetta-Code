#include<iostream>
using namespace std;

int main()
{
    //Central Numerical Triangle
    int n;
    cin >> n;
    int x = (n*2)-1;
    int row=1;
    while(row<=n)
    {
        int space = n- row;
        while(space)
        {
            cout << " ";
            space--;
        }
        int count=1;
        for(count=1;count<=row;count++)
        {
            cout << count;
        }
        count--;
        while(count>1)
        {
            count--;
            cout << count;
        }
        cout << endl;
        row++;
    }
}