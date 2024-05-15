def addition(x,y):
    carry=0
    res=""
    for i in range(len(x)-1,-1,-1):
        total=int(x[i])+int(y[i])+carry
        res=str(total%2)+res
        carry=total//2
    return res

def comp(number):
    l=list(number)
    for i in range(len(l)):
        if l[i]=='1':
            l[i]='0'
        else:
            l[i]='1'
    add=(str(0)*(len(l)-1))+"1"
    return addition("".join(l),add)
    
def restore(Q, M, A):
    n = len(M)
    while n:
        print("\niteration :", len(M)-n + 1, end='')
        print(' Left Shift and Subtract M from A: \n', end='')
        A = A[1:] + Q[0]
        MC = comp(M)
        A = addition(A, MC)
        print('A:', A, ' Q:', Q[1:]+'_', end='')
        if A[0] == '1':
            Q = Q[1:] + '0'
            print(' ')
            A = addition(A, M)
            print('A:', A, ' Q:', Q, ' Restored A')
        else:
            Q = Q[1:] + '1'
            print(' ')
            print('A:', A, ' Q:', Q, ' No Restored A')
        n -= 1
    ans_q = str(int(Q,2))
    ans_a = str(int(A,2))
    print('\nQuotient:', ans_q, ' Remainder:', ans_a)
    

dividend = input("Enter dividend in binary: ")
divisor = input("Enter divisor in binary: ")
accumulator = '0' * len(dividend)

restore(dividend, divisor, accumulator)
