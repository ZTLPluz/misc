DATAS SEGMENT
N1 DB 10,-10,'ab','AB'
N2 DW 10,-10,'ab','AB'
N3 DD 10,-10,'ab','AB'
DATAS ENDS
CODES SEGMENT
ASSUME CS:CODES,DS:DATAS
START:
MOV AX,DATAS 
MOV DS,AX
MOV AH,4CH 
INT 21H
CODES ENDS
END START