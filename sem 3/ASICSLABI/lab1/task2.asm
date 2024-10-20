 org $8000

 ;€чейки массива: 8100-8108 
 ;ввод от: 0-2
 
 ldaa #1 ;строчка
 ldab #1 ;столбик  
	
 pshb 

 ldab #3 

 mul  
 
 ldx #$8100	
 
 abx 
	
 pulb

 abx 

 ;x - ответ
 
 