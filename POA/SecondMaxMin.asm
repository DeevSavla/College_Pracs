DATA SEGMENT
    STRING DB 99h,45h,54h,36h,12h 
    SECMAX DB ?
    SECMIN DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:  
    MOV AX,DATA
    MOV DS,AX
    MOV CH,04H
    
    OP:MOV CL,04H
    LEA SI,STRING
    
    IP:MOV AL,[SI]
    MOV BL,[SI+1]
    CMP AL,BL     
    JC jump
    MOV DL,[SI+1]
    XCHG DL,[SI]
    MOV [SI+1],DL
    
    jump:
    INC SI
    DEC CL
    JNZ IP
    DEC CH
    JNZ OP 
           
    MOV DL,[SI-1]
    MOV SECMAX,DL 
    MOV DL,[SI-3]  
    MOV SECMIN,DL
CODE ENDS
END START
