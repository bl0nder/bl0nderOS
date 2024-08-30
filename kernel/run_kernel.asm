;Function to run the kernel and ensure that execution starts from 'main'
;Parameters:
;   NONE
[bits 32]
[extern main]

call main
jmp $