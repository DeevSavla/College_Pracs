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

def non_restoringDivision(Q,M,A):
    count=len(Q)
    action = "Initialise"
    print("n        A             Q                   Action")
    print(count, "      ", A, "      ", Q, "      ", action)
    while (count):
        if (A[0] == '0'):        
            A = A[1:] + Q[0]
            action = "Left shift"
            print(count, "      ", A, "      ", Q[1:]+'_', "      ", action)
            MC = comp(M)
            A = addition(A, MC)
            action = "Subtraction"
            print(count, "      ", A, "      ", Q[1:]+'_', "      ", action)
        else:      
            A = A[1:] + Q[0]
            action = "Left shift"
            print(count, "      ", A, "      ", Q[1:]+'_', "      ", action)
            A = addition(A, M)
            action = "Addition"
            print(count, "      ", A, "      ", Q[1:]+'_', "      ", action)
        if (A[0] == '0'):   
            Q = Q[1:] + '1'
            action = "Q[0]=1"
            print(count, "      ", A, "      ", Q, "      ", action)
        else:
            Q = Q[1:] + '0'
            action = "Q[0]=0"
            print(count, "      ", A, "      ", Q, "      ", action)               
        count = count - 1        
    if (A[0] == '1'):   
            print("\nMSB of A is 1, we perform addition:")
            A = addition(A, M)
            action = "Addition"
            print(count, "      ", A, "      ", Q, "      ", action)
            ans_q = str(int(Q, 2))
            ans_a = str(int(A,2))
            print('\nQuotient:', ans_q, ' Remainder:', ans_a)
            print ('Quotient(Q):', Q,' Remainder(A):', A)
    else:
        ans_q = str(int(Q, 2))
        ans_a = str(int(A,2))
        print('\nQuotient:', ans_q, ' Remainder:', ans_a)
        print ('\nQuotient(Q):', Q,' Remainder(A):', A)
              

dividend_binary = input("Enter dividend in binary: ")
divisor_binary = input("Enter divisor in binary: ")  
accumulator = '0' * (len(dividend_binary) + 1)
divisor_binary = '0' * (len(accumulator) - len(divisor_binary)) + divisor_binary 
non_restoringDivision(dividend_binary, divisor_binary, accumulator)
