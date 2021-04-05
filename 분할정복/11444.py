#11444
#divide and conquer

def multiply(Mat1, Mat2):
    Mat_result = [[0 for col in range(2)] for row in range(2)]
    for i in range(2):
        for j in range(2):
            Mat_result[i][j]=0
    for i in range(2):
        for j in range(2):
            for k in range(2):
                Mat_result[i][j] += Mat1[i][k]*Mat2[k][j]
                Mat_result[i][j] %= 1000000007
    return Mat_result

def pow(Mat, b):
    Mat_result = [[0 for col in range(2)] for row in range(2)]
    if b==1:
        return Mat
    if b==2:
        return multiply(Mat, Mat)
    if b%2==1:
        return multiply(Mat, pow(Mat,b-1))
    Mat_result = pow(Mat,b//2)
    return multiply(Mat_result, Mat_result)

Mat = [[0 for col in range(2)] for row in range(2)]
n=int(input())
a=0
Mat=[[1,1],[1,2]]
result = [[0 for col in range(2)] for row in range(2)]
a=n//2
if n==0: print(0)
elif n==1: print(1)
else:
    result = pow(Mat, a)
    if n%2==0:
        print(result[1][0]%1000000007)
    else:
        print(result[1][1] % 1000000007)