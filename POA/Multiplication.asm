DATA SEGMENT
    NUM1 DW 2
    NUM2 DW 3
    RESULT DW ?
DATA ENDS

CODE SEGMENT
    START:        
    MOV AX,DATA
    MOV DS,AX
    MOV AX,NUM1
    MOV BX,NUM2
    MUL BX       
    ;Multiply the value in AX by the value in BX.
    ;The result is a 32-bit value stored in DX:AX 
    ;(high 16 bits in DX and low 16 bits in AX).
    MOV RESULT,AX   
    ;Move the lower 16 bits of the multiplication result from AX into RESULT.
CODE ENDS 
END START
