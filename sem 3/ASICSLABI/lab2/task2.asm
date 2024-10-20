 org $8000

START:
  ldx #$8200

LOOP:
  ldaa $0,x 
  anda #%00000001
  beq ZERO

  ldab $0,x
  andb #%00010000
  bne NOTZERO

ZERO:
  bclr $0,x,#%00000010   
  bra NEXT

NOTZERO:
  bset $0,x,#%00000010
  bra NEXT

NEXT:
  ldaa $0,x
  adda #%01001011
   
  inx
  staa $0,x
  
  clra
  clrb
  
  cpx #$821f
  bne LOOP
 
 swi

 
    