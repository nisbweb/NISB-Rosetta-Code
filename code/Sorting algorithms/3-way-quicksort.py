
import random

def partition3(a, l, r):
    if r-l<=1:
        if a[r]<a[l]:
            a[r],a[l]=a[l],a[r]
        return [l,r]
    i=l
    pivot=a[r]
    while i <= r:
        if a[i]<pivot:
            a[i],a[l]=a[l],a[i]
            i+=1
            l+=1
        elif a[i]==pivot:
            i+=1
        else:
            a[i],a[r]=a[r],a[i]
            r-=1
    return [l-1,i]

def randomized_quick_sort(a, l, r):
    if l >= r:
        return    
    parts = partition3(a, l, r)
    
    randomized_quick_sort(a, l, parts[0])
    randomized_quick_sort(a, parts[1], r)


if __name__ == '__main__':
    input = input()
    n, *a = list(map(int, input.split()))
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
