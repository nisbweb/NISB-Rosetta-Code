#include <iostream>

using namespace std;

int main()
{
    int n;
    int x=1,y=1,i;
    cin >> n;
    int z;
    cout << "0" << " " << "1" << " " << "1" << " " ;
    for(i=0;i<n-3;i++)
    {
        z = x + y;
        cout << z << " ";
        y = x;
        x = z;
    }
    
    return 0;
}