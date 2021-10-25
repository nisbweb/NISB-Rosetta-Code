#include <iostream>
using namespace std;

int main()
{
    int n,i,k;
    cin >> n;
    
    if(n%2!=0)
    {
        n++;
    }
    int half;
    half = (n/2);                              
    for(i = 1; i <= half; i++) 
    {
       for(k = 1; k<=(half-i); k++) 
       {
           cout << " ";
       }
       if(i == 1) 
       {
           
           cout << "*";
       }
       else
       {
           cout << "*"; 
           for(k = 1; k<=2*i-3; k++) 
           { 
               cout << " ";
           }
           cout << "*";
       }
       cout << endl;
    }
    for(i = half+1; i<n; i++) 
    {
        for(k = 1; k<=i-half; k++) 
        {
            cout << " ";
        }
        if(i == n-1) 
        {
            cout << "*";
        }
        else
        {
            cout << "*";
            for(k = 1; k<=2*(n - i)-3; k++) 
            { 
                cout << " ";
            }
        cout << "*";
        }
    cout << endl;
   }
   return 0;
}