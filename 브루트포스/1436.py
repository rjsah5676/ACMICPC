n = int(input())
def q(x) :
    c=0
    j=-1
    r=0
    k=-1
    t = 0
    for i in str(x) :
        k+=1
        if int(i) == 6 and j == -1: 
            j = k
        elif int(i) == 6 : 
            r = k
        else :
            c = r - j + 1
            j = -1
            r = 0
            t = max(c,t)
    c = r - j + 1
    t = max(c,t)   
    return t
    
def a(x) :
    b = 666
    o = 0
    oc = 0
    for i in range(1, x) :
        if o == 1 :
            b+=1
            oc+=1
            if oc == 10 : 
                o = 0
                oc = 0
                b -= 4
        if o == 2 :
            b+=1
            oc+=1
            if oc == 100 :
                o = 0
                oc = 0
                b -= 34
        if o == 3 : 
            b+=1
            oc+=1
            if oc == 1000 :
                o = 0
                oc = 0
                b -= 334
        if o == 0 and q(b + 1000) == 3 :
            b += 1000
        elif o == 0 and q(b + 1000) == 4 :
            b = b + 1000 - 6
            o = 1
        elif o == 0 and q(b + 1000) == 5 :
            b = b + 1000 - 66
            o = 2
        elif o == 0 and q(b + 1000) == 6 :
            b = b + 1000 - 666
            o = 3
    return b
print(a(n))