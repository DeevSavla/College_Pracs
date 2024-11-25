hamming = input("Enter 7-bit hamming code:")

def isSeven(num):
    if num%2==0:
        return 0
    else:
        return 1

cp1 = int(hamming[0]) + int(hamming[2]) + int(hamming[4]) + int(hamming[6])
cp2 = int(hamming[0]) + int(hamming[1]) + int(hamming[4]) + int(hamming[5])
cp4 = int(hamming[0]) + int(hamming[1]) + int(hamming[2]) + int(hamming[3])

p1 = isSeven(cp1)
p2 = isSeven(cp2)
p4 = isSeven(cp4)

check = f"{p4}{p2}{p1}"

bit = int(check,2)

if bit == 0:
    print("No error")
else:
    print(f"Error at bit {bit}.")