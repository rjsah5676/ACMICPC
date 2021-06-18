dp=[0]*1000002
n=int(input())
dp[1]=1
dp[2]=2
for i in range(3,n+1):
    dp[i]=(dp[i-1]%15746+dp[i-2]%15746)%15746
print(dp[n])