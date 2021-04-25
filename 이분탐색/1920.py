#1920
#이분 탐색

N=int(input())
a=list(map(int,input().split()))
M=int(input())
b=list(map(int,input().split()))
a.sort()
def f(s,l,w):
    m=(s+l)//2
    if a[m]==w:
        print("1")
        return
    elif s>=l:
        print("0")
        return
    if a[m]<w:
        f(m+1,l,w)
    elif a[m]>w:
        f(s,m-1,w)
for i in b:
    f(0,N-1,i)