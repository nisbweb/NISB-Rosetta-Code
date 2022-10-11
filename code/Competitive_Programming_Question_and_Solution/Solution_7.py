from math import factorial
n=int(input())
for i in range(n):
    numberofways=int(input())
    for j in range(1,1000):
        if (factorial(2*(j))//(factorial(j+1)*factorial(j)))==numberofways:
            print(j+2)
