#include<algorithm>
#include<random>
#include<iostream>

bool isSorted(int a[], int n){
	while ( --n > 1 )
		if (a[n] < a[n-1])
			return false;
	return true;
}
 
void shuffle(int a[], int n){
	for (int i=0; i < n; i++)
		std::swap(a[i], a[std::rand()%n]);
}
 
void bogosort(int a[], int n){
	while ( !isSorted(a, n) )
		shuffle(a, n);
}
 
void printArray(int a[], int n){
	for (int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
 
int main(){
	int a[] = {3, 2, 5, 1, 0, 4};
	int n = sizeof a/sizeof a[0];
	bogosort(a, n);
	std::cout<<"Sorted array :\n";
	printArray(a,n);
	return 0;
}