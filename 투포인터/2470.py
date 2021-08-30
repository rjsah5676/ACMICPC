class Num:
    def __init__(self,n1,n2):
        self.n1=n1
        self.n2=n2
b=[]
k=0
l=0
m=2100000000
N=int(input())
a=list(map(int,input().split()))
for i in a:
    b.append(Num(i,abs(i)))
b.sort(key=lambda Num: Num.n2)
for i in range(len(b)-1):
    if abs(m) > abs(b[i].n1+b[i+1].n1):
        m=b[i].n1+b[i+1].n1
        k=i
        l=i+1
c=[]
c.append(b[k].n1)
c.append(b[l].n1)
c.sort()
for i in c:
    print(i)