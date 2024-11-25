def character_count():
    n = int(input("Enter the number of frames:"))
    final = ''
    for i in range(0,n):
        s = input(f"Enter frame {i+1}:")
        char_count = str(len(s)+1)+s
        final = final + char_count
    return final

def byte_stuffing():
    final = ''
    s = input("Enter data:")
    start = input("Start char:")
    end = input("End char:")
    escape = input("Escape char:")
    final = final + start
    for ch in s:
        if ch==start or ch==end:
            final = final + escape + ch
        else:
            final = final + ch
    final = final + end
    return final 

def bit_string():
    final = ''
    bitlist = list(input("Enter data:"))
    c = 0
    for i in range(0,len(bitlist)):
        if bitlist[i]=='1':
            c = c + 1
            final = final + bitlist[i]
        else:
            c = 0
            final = final + bitlist[i]

        if c==6:
            final = final + '0' 

    return final

print("Character Count")
char_string = character_count()
print(f"String sent is {char_string}")

print("Byte Stuffing")
byte_string = byte_stuffing()
print(f"String sent is {byte_string}")

print("Bit Stuffing")
bit_string = bit_string()
print(f"String sent is {bit_string}")