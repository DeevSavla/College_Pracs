data = input("Enter 4 bit data:")

parity = input("Enter even or odd parity:")

hamming = [-1] * 7

hamming[0] = int(data[0])
hamming[1] = int(data[1])
hamming[2] = int(data[2])
hamming[4] = int(data[3])

def isSeven(num,str):
    if (num % 2 == 0 and str=="even") or (num%2==1 and str=="odd"):
        return 0
    else:
        return 1

cp1 = hamming[0] + hamming[2] + hamming[4]
cp2 = hamming[0] + hamming[1] + hamming[4]
cp4 = hamming[0] + hamming[1] + hamming[2]

p1 = isSeven(cp1,parity)
p2 = isSeven(cp2,parity)
p4 = isSeven(cp4,parity)

hamming[3] = p4
hamming[5] = p2
hamming[6] = p1

generate = "".join(str(bit) for bit in hamming)

print(generate)