#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The original array is ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int j=n-1;
    for(int i=0;i<n;i++){
        b[j]=a[i];
        j-=1;
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
    cout<<"The reversed array is "
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}