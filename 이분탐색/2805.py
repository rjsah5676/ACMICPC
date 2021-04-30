n,m=map(int,input().split())
a=list(map(int,input().split()))
def h(j):
    s=0
    for i in a:
        x=i-j
        if x>0:
            s+=x
    return s
def f(x):
    s,e=0,max(a)
    r=0
    while s<=e:
        m=(s+e)//2
        z=h(m)
        if z<x:
            e=m-1
        if z>=x:
            r=m
            s=m+1
    return r
print(f(m))