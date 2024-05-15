def nums(number):
    length=len(number)
    temp=n-length
    return (str(0)*temp)+number

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
    
def rightshift(acc,Q,Qnot):
    a=acc[0]+acc[:-1]
    b=acc[-1]+Q[:-1]
    c=Q[-1]
    return a,b,c
    
def booths(M,MC,Q,n,na,nb):
    acc=nums('0')
    Qnot='0'
    ans=""
    action='initialise'
    print("n    AC      Q       Qnot    Action")
    print(n,"  ",acc," ",Q," ",Qnot,"   ",action)
    while n>0:
        if(Q[-1]+Qnot=='00' or Q[-1]+Qnot=='11'):
            acc,Q,Qnot=rightshift(acc,Q,Qnot)
            action='right shift'
        elif(Q[-1]+Qnot=='10'):
            acc=addition(acc,MC)
            acc,Q,Qnot=rightshift(acc,Q,Qnot)
            action='AC=AC-M && right shift'
        else:
            acc=addition(acc,M)
            acc,Q,Qnot=rightshift(acc,Q,Qnot)
            action='AC=AC+M && right shift'
        print(n,"  ",acc," ",Q," ",Qnot,"   ",action)
        n=n-1
    answer=acc+Q
    print("The product in binary is:",answer)
    if(na==nb):
        ans_d = str(int(answer, 2))
    else:
        ans_d = "-" + str(int(comp(answer), 2))
    print("Decimal Conversion:",ans_d)
    
    
x=int(input("Enter multiplicand:"))
y=int(input("Enter mulitplier:"))
na,nb=0,0

Xbin=bin(x).replace("0b","")
Ybin=bin(y).replace("0b","")

if(Xbin[0]=='-'):
    Xbin=Xbin[1:]
    na=1
if(Ybin[0]=='-'):
    Ybin=Ybin[1:]
    nb=1

n=max(len(Xbin),len(Ybin))+1

fn=nums(Xbin)
sn=nums(Ybin)
fc=comp(fn)
sc=comp(sn)

if na==1:
    M,MC=fc,fn
else:
    M,MC=fn,fc

if nb==1:
    Q=sc
else:
    Q=sn
    
booths(M,MC,Q,n,na,nb)



