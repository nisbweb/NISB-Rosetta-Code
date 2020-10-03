using System;
using System.Collections.Generic;

namespace BubbleSort
{
    class Program
    {
    	public static void Main(string[] args)
        {
        	int[] sort = new int[] { 1,2,3,4,5,6,7,8,9,0 };
        	Shuffle(ref sort);
        	BubbleSort(ref sort);
        	foreach (int i in sort){
        		Console.Write(i.ToString());
        	}
        }
        public static void Shuffle(ref int[] Array){
            Random rng = new Random();
			for (int i = 0; i<Array.Length; i++){
				int IndexTo = rng.Next(i, Array.Length);
				int A = Array[IndexTo];
				Array[IndexTo] = Array[i];
				Array[i] = A;
			}
		}
		public static void BubbleSort(ref int[] Array){
			while (true){
				bool Sorted = true;
				for (int i = 0; i<Array.Length-1; i++){
					if (Array[i] > Array[i+1]){ //read+2
						int A = Array[i+1]; //read
						Array[i+1] = Array[i]; //write+read
						Array[i] = A; //write
						Sorted = false;
					}
				}
				if (Sorted) return;
			}
		}
    }
}