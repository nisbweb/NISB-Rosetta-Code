# a function to implement quick sort algorithm

def quick_sort(arr):
	length = len(arr) # getting the length of array
	if(length<=1):
		return arr
	else :
		pivot = arr.pop() # set pivot as the last element of the array
	
	items_greater = []
	items_lower = []
	
	for item in arr: # sorting array based on pivot
		if item >pivot:
			items_greater.append(item)
		else :
			items_lower.append(item)
			
	return quick_sort(items_lower) + [pivot] + quick_sort(items_greater) # return the final array
	
print(quick_sort([4, 6, 2, 56, 36, 83, 93,100]))