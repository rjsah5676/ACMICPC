a=[]
for _ in range(int(input())):
    b,c=list(map(int,input().split()))
    a.append([c,b])
a.sort()
for i in range(len(a)):
    print(a[i][1],end=" ")
    print(a[i][0])