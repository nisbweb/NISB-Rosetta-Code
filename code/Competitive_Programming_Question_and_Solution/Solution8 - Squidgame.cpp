#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    //Input of the number of steps
    int n;
    cin >> n;
    
    //Input of time taken for each step
    int t;
    cin >> t;
    
    //Input of the probability of passing each step successfully
    float y;
    cin >> y;
    
    //Calculation of the rounds
    float x;
    x = 10 / n;
    
    //Calculation of total time taken
    float time;
    time = x * t; 
    
    
    //Calculation of the probability of passing the game
    float p,i;
    p = pow(y,x);
    
    if(time>50)
    {
        cout << "Not possible." ;
    }
    else
    {
        cout << "Time required : " << time << endl ;
        cout << "The probability of the person passing the game is " << p;
    }
    
    return 0;
}