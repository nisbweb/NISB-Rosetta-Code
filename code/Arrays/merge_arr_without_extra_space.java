import java.lang.*;
import java.io.*;
class Main
 {
	public static void main (String[] args) throws IOException
	 {
		 // Read Input from the user
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int t = Integer.parseInt(br.readLine());
	    while(t-->0)
	    {
	        String sizes[] = br.readLine().trim().split("\\s+");
	        int x = Integer.parseInt(sizes[0]);
	        int y = Integer.parseInt(sizes[1]);
	        
	        String input[]=br.readLine().trim().split("\\s+");
	        int arr1[] = new int[x];
	        for(int i=0;i<x;i++)
	          arr1[i] = Integer.parseInt(input[i]);
	   
  	        String input2[]=br.readLine().trim().split("\\s+");
	        int arr2[] = new int[y];
	        for(int i=0;i<y;i++)
	          arr2[i] = Integer.parseInt(input2[i]);
	          
	          mergeTwoArrays(arr1,arr2);
	    }
	 }
	 
	 static void mergeTwoArrays(int a1[],int a2[])
	 {
	     int pt1 = a1.length-1; //Last index of a
	     int pt2 = 0; //First Index of b
	     
	     while(pt1 >=0 && pt2 < a2.length)
	     {
	         if(a1[pt1]>a2[pt2]) //smaller elements should be in array1 and larger in array2. 
	         {
	            int temp = a1[pt1];
	            a1[pt1] = a2[pt2];
	            a2[pt2] = temp;
	         }
	         
	         pt1--;
	         pt2++;
	     }
	     
	     //Now sort both arrays.
	     Arrays.sort(a1);
	     Arrays.sort(a2);
	     
	     //Printing the arrays
	     StringBuilder sb = new StringBuilder();
	     for(int i=0;i<a1.length;i++)
	     {
	         sb.append(a1[i]+" ");
	     }
	     
	     for(int i=0;i<a2.length;i++)
	     {
	         sb.append(a2[i]+" ");
	     }
	     
	     System.out.println(sb);
	 }
}
