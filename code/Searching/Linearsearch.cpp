#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the number to be searched";
    int k,l=0;
    cin>>k;
    for(int i=0;i<n;i++){
        if(k==a[i]){
            l=1;
            cout<<"Element was found at index "<<i;
            return 0;
        }
    }
    if(l==0){
        cout<<"Element not found";
    }
    return 0;
}