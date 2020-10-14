swaps=[]

def heapify(data,n,vert):
    min=vert
    l=2*vert+1
    r=2*vert+2
    if l<n and data[l]<data[min]:
        min=l
    if r<n and data[r]<data[min]:
        min=r
    if min!=vert:
        data[vert],data[min]=data[min],data[vert]
        swaps.append([vert,min])
        heapify(data,n,min)


def main():
    n = int(input())
    data = list(map(int, input().split()))
    for i in range(n//2-1,-1,-1):
        heapify(data,n,i)
    
    print(len(swaps))
    for i, j in swaps:
        print(i, j)
    print(data)


if __name__ == "__main__":
    main()
