"""
# A Very Fast Implementation for prime number generator..
Author : Satyam Rai
Example usage:
    1. primeGenerator(n) -> returns a generator object that goes through n numbers..
    2. primeGenerator() same as primeGenerator(0) -> returns a gen obj that goes through all prime numbers (almost infinite) 
    3. primeGenerator(lessthan = k) -> returns a gen object that produces all primes less than k.



    
"""
from typing import Generator


#Generator[yield_type, send_type, return_type]
def primeGenerator(no = 0,lessthan = None )-> Generator[int,None,None]:
    """
    >>> list(primeGenerator(10)) 
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    >>> list(primeGenerator(lessthan=10))
    [2, 3, 5, 7]
    >>> from itertools import islice
    >>> list(islice(primeGenerator(),10))  # using islice to limit to  10 outputs (continues forever..)
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    """
    
    prmd  = {2:1,3:2} # using a dict To maintain order and o(1) searching..
    sqrtn = 2
    l = 1
    count = 0
    while ((no!=0 and count < no) or ( (no==0) and (lessthan and l<lessthan ) or (not lessthan ) ))and (l<4) :
        if l in prmd:
            count += 1
            yield l
        l+=1                        # incrementing by 1 till you reach 5
    l=5
    add = 2
    
    while (no!=0 and count < no) or ( (no==0) and ( (lessthan and l<lessthan ) or (not lessthan )) ) :  #check only 6n-1 and 6n+1
        if l > sqrtn**2:
            sqrtn = l**0.5
        for i in prmd:
            if i > sqrtn:
                prmd[l] = len(prmd)
                add = 2 if add==4 else 2
                count +=1
                yield l
                break
            if l%i ==0 :  
                break
        l+=add


if __name__ == "__main__":
    n = int(input("Enter how many primes do you want (0-> inf): "))
    for i in primeGenerator(n):
        print(i,end = " ")