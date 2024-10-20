 org $8000

 ;способ 1
 bset $10,#%00001100
 bclr $10,#%11110011  

 ldaa #$ff
 staa $10 
 
 ;способ 2
 bclr $10,#%11111111
 ldaa $10  

 oraa #%00001100
 staa $10 

 ldaa #$ff
 staa $10 
 
 ;способ 3	
 ldaa $10 
 asla
 asla
 asla
 asla
 asla
 asla
 asla
 asla
 coma
 asla 
 asla 
 asla
 asla
 asla
 asla
 rola 
 rola  +    
 asla
 asla
 staa $10
	  
  