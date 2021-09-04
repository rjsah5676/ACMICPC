n=int(input())
a=[[0] for k in range(n)]
b=[]
for i in range(n) :
    a[i] = input().split(' ')
    a[i] = list(map(int, a[i]))
for i in range(n) :
    b.append(1)
    for j in range(n) :
        if j == i : pass
        elif a[i][0] < a[j][0] and a[i][1] < a[j][1] :
            b[i]+=1
for i in range(n) :
    print(b[i], end=" ")