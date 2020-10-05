import time
import random
def swap(arr, pos1, pos2): 
    temp = arr[pos1]
    arr[pos1] = arr[pos2]
    arr[pos2] = temp
    return arr

def insertionSort(A):
    start = time.time()
    try:
        for ii in range(1, len(A)):
            i = ii
            while(i > 0) and (A[i-1] > A[i]):
                swap(A, i, i-1)
                i = i - 1
    except TypeError:
        print("Error in input")
    end = time.time()
    timeT = end - start
    duration = round(timeT, 5)
    print("---Finished in ", duration, "seconds---")


testArr = random.sample(range(500),100)
insertionSort(testArr)
print(testArr)
