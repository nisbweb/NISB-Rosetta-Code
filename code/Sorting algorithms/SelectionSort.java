package arrays;
import java.util.Scanner;
public class SelectionSort {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=0;i<n-1;i++) {
			int lowindex=i;
			for(int j=i;j<n;j++) {
				if(a[j]<a[lowindex]) {
					lowindex=j;
				}
				
			}
			int temp=a[i];
			a[i]=a[lowindex];
			a[lowindex]=temp;
		}
		System.out.println("after sorting:");
		for(int i=0;i<n;i++) {
			System.out.print(a[i]+" ");
		}

	}

}
