#include <stdio.h>
#include <stdlib.h>
 
// Define a constant
#define MAX 10
 
// Ordination function prototype
void quick_sort(int *a, int left, int right);
 
// Main Function
int main(int argc, char** argv)
{
 int i, vet[MAX];
 
 // Read MAX or 10 values
 printf("Read 10 values then order according to quicksort algo!");
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 // Order values
 quick_sort(vet, 0, MAX - 1);
 
 // Print values in order ascendant
 printf("\nOrdered values\n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d\n", vet[i]);
 }
 system("pause");
 return 0;
}
 
// Quick sort function
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}