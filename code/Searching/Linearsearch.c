#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched\n");
    int k,l=0;
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(k==a[i]){
            l=1;
            printf("Element was found at index %d",i);
        }
    }
    if(l==0){
        printf("Element not found");
    }
    return 0;
}