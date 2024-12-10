.model small
.stack 100h
.data
    text db " - Hello Darova", 0Ah, 0Dh, 24h
.code

main:
          
    mov ax, @data 
    mov ds, ax
    
    lea dx, buffer
    mov ah, 09h
    int 21h
    
                
    lea dx, text
    mov ah, 09h
    int 21h
                   
 
    mov ah, 4Ch
    int 21h
 
end main       