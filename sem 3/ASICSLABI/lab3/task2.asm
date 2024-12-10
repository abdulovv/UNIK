.model small
.stack 100h

.data     
    msg1 db "enter string:$"
    newLine db 13, 10, '$'  
    msg2 db "res:$"
    buffer db 200, 200 dup('$')

.code 
main:              
    mov ax, @data           
    mov ds, ax
        
    mov dx, offset msg1
    mov ah, 09h                 
    int 21h         
    
    lea dx, buffer             
    mov ah, 0Ah
    mov al, 24h
    int 21h                
                    
    mov dx, offset newLine        
    mov ah, 09h               
    int 21h 
    
    mov dx, offset msg2
    mov ah, 09h                 
    int 21h
    
    
                      
    ;sort    
    
    mov ch, buffer[1] ;length         
    lea si, buffer + 2  ;first el
    
    mov dx, 0
    dec dl
    dec ch
    
    ;i-->dl
    

for1:
    inc dl
    cmp dl, ch   ; i==length
    je res
          
    mov dh, 0 ;j=0 ,j-->dh      
     
    lea di, buffer + 2
    mov ax,0
    add al,dh  
    add di, ax 
    
for2:  
    mov ah, [di] ;[j]  
    mov al, [di+1] ;[j+1]
          
    cmp al, ah   
    jl swap
    
    jmp noswap
noswap:
    inc di                                
    inc dh
    
    cmp dh, ch ;j<length
    jl for2
    
    
    jmp for1           
swap:
    xchg ah, al
    
    mov [di], ah 
    mov [di+1], al
    
    inc di                                
    inc dh             
    
    cmp dh, ch  ;j<length
    jl for2
    
    jmp for1     
    ;sort
     
                     
                     
res:    
    lea di, buffer + 2    ; i = 0
    mov cl, [buffer + 1]  ; length 
    mov ch, 0             
print:
    mov dl, [di]                 
    inc di
    dec cl
    mov ah, 02h
    int 21h
    
    cmp cl, 0                    
    jge print        

   
            

    mov ah, 4Ch           
    int 21h
end main

