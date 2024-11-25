ip = input("Enter IP address: ")
iplist = ip.split(".")

if len(iplist) != 4:
    print("ERROR IN IP")
else:
    first=int(iplist[0])
    if (first>=0 and first<=127):
        print("Class: A")
        print("Subnet mask: 255.0.0.0")
        iplist[1]=iplist[2]=iplist[3]="0"
        modified_ip = ".".join(iplist)
        print("Subnet address: ", modified_ip)
    elif (first>=128 and first<=191):
        print("Class: B")
        print("Subnet mask: 255.255.0.0")
        iplist[2]=iplist[3]="0"
        modified_ip = ".".join(iplist)
        print("Subnet address: ", modified_ip)
    elif (first>=192 and first<=223):
        print("Class: C")
        print("Subnet mask: 255.255.255.0")
        iplist[3]="0"
        modified_ip = ".".join(iplist)
        print("Subnet address: ", modified_ip)
    elif (first>=224 and first<=239):
        print("Class: D")
        print("Subnet mask: Multicast")
    elif (first>=240 and first<=255):
        print("Class: E")
        print("Subnet mask: Reserved")