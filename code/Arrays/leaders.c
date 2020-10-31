#include<stdlib.h>
#include<stdio.h>
int main(){
    int *a,i,j,n;
    printf("Enter the number of elements in an array\n");
    scanf("%d\n",&n);
    a=(int *)malloc(n*sizeof(int *));
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d\n",a+i);
    }
    printf("Leaders are\n");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(*(a+i)<*(a+j))
            break;
        }
        if(j==n){
            printf("%d\n",*(a+i));
        }
    }
    return 0;

}