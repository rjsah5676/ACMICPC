t=int(input())
p=[0]*102
p[0]=1
p[1]=1
p[2]=1
p[3]=2
p[4]=2
while t:
    t-=1
    N=int(input())
    for i in range(5,N):
        p[i]=p[i-1]+p[i-5]
    print(p[N-1])