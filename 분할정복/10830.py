#10830
#divide and conquer

def multiply(Mat1, Mat2):
    Mat_result = [[0 for col in range(6)] for row in range(6)]
    global n
    for i in range(6):
        for j in range(6):
            Mat_result[i][j]=0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                Mat_result[i][j] += Mat1[i][k]*Mat2[k][j]
                Mat_result[i][j] %= 1000
    return Mat_result

def pow(Mat, b):
    Mat_result = [[0 for col in range(6)] for row in range(6)]
    global n
    if b==1:
        return Mat
    if b==2:
        return multiply(Mat, Mat)
    if b%2==1:
        return multiply(Mat, pow(Mat,b-1))
    Mat_result = pow(Mat,b/2)
    return multiply(Mat_result, Mat_result)

Mat = [[0 for col in range(6)] for row in range(6)]
n, b = input().split()
n=int(n)
b=int(b)
for i in range(n):
    Mat[i] = list(map(int, input().split()))
result = [[0 for col in range(6)] for row in range(6)]
result = pow(Mat, b)
for i in range(n):
    for j in range(n):
        print(result[i][j]%1000, end=' ')
    print()
