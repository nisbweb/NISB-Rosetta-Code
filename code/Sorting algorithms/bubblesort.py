
def Sort(a):
    for passnum in range(len(a)-1,0,-1):
        for i in range(passnum):
            if a[i]>a[i+1]:
                temp = a[i]
                a[i] = a[i+1]
                a[i+1] = temp



a = []

n = int(input("What number of elements do you want to insert to the array?"))
print("Enter numbers that you need here:")
for i in range(n):
    
    ele = int(input())
    a.append(ele)
print(a)

print("After sorting the elements, results are:")


Sort(a)
print(a)