package arrays;
import java.util.Scanner;
public class Bubblesort {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		int t;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		System.out.println("array before sorting");
		for(int i=0;i<n;i++) {
			System.out.print(a[i] +" ");
		}
		System.out.println();
		for(int i=0;i<n-1;i++) {
			boolean sorted=true;
			for(int j=0;j<n-i-1;j++) {
				if(a[j+1]>a[j]) {
					t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;
					sorted=false;
					
				}
			}
			if(sorted) break;
		}
		System.out.println("array after sorting");
//		for(int i=0;i<n;i++) {
//			System.out.print(a[i] +" ");
//		}
//	
		for(int item : a) {
			System.out.print(item +" ");
		}

	}

}
