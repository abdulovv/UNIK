.model small
.stack 100h
.data 
    text db 30 dup(0)   
    err db "File path not founded$"
    emp db "Cmd is empty", 0Ah, 0Dh, 24h 
    msg db "Count of strings:$"
    res db 10 dup("$")          
    buffer db 1 dup(0)
    
.code

print macro str
    lea dx, str
    mov ah, 09h
    int 21h
endm 

main:          
    mov ax, @data 
    mov ds, ax
    
    jmp Start
    
Error:
    print err
    jmp ENDPROG
Empty:    
    print emp
    print err
    jmp ENDPROG
    
Start:
    call readCmd 
    
    call readFile
              
    push dx          
              
    print msg
    
    pop ax  ;count of strings  
    
    call PrintDecimal 
    
                     
           
    
    
ENDPROG:
    mov ah, 4Ch
    int 21h

proc readCmd near        
    xor cx, cx
    xor ax, ax   
    
    mov cl, es:[80h] ; count of symbols in cmd
    
    mov si, 81h ; adress of arguments
    mov di, offset text   
    
    cmp cx, 0
    je Empty    
    
    inc si
    dec cx
    
copy:   
    push ds
    mov ax, es
    mov ds, ax
    
    mov al, [si]
    
    pop ds
                     
    mov [di], al                         
    
    dec cl
    inc si
    inc di 
    
    cmp cl,0
    jne copy
    
    mov al, 0
    mov [di], al
            
                   
    ret             
    
readCmd endp             

proc readFile near        
open:    
    lea dx, text
    mov al, 0h
    mov ah, 3Dh 
    int 21h  
    jc Error
    
read:    
    mov bx, ax
    mov si, offset buffer 
    
    xor ax, ax
    push ax
    
startRead:    
    mov ah, 3Fh
    lea dx, buffer
    mov cx, 1
    int 21h
    
    cmp ax, 0
    je close  
    
    xor ax, ax
    
    mov al,[si]

    cmp al, 0AH
    je endOfString         
     
    jmp startRead
     
endOfString:
    pop ax
    inc ax
    push ax
          
    jmp startRead
       
close:       
    mov ah,3Eh 
    int 21h
    
    POP dx
    inc dx
    
    ret
readFile endp      

PrintDecimal proc near
  
    push ax
   
    xor cx, cx          
    mov bx, 10        

convert_loop:
    xor dx, dx         
    div bx              
    push dx            
    inc cx               
    cmp ax, 0       
    jnz convert_loop    

   
output_loop:
    pop dx            
    add dl, '0'       
    mov ah, 02h       
    int 21h           
    loop output_loop   

    
    pop ax
    ret
PrintDecimal endp



           
end main