def pisano(m):
    prev,curr=0,1
    for i in range(0,m*m):
        prev,curr=curr,(prev+curr)%m
        if prev==0 and curr == 1 :
            return i+1

def fib(n,m):
    
    seq=pisano(m)
    n%=seq
    if n<2:
        return n
    f=[0]*(n+1)
    f[1]=1
    for i in range(2,n+1):
        f[i]=f[i-1]+f[i-2]    
    return f[n]


# Print Fn % m where n and m are 2 inputs, and Fn => nth Fibonacci Term
inp=list(map(int,input().split()))
print(fib(inp[0],inp[1])%inp[1])