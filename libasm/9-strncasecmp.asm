BITS 64
	global asm_strncasecmp
	section .text

asm_strncasecmp:
	push rbp					; push value of base pointer onto stack
	mov rbp, rsp				; copy stack pointer into base pointer
	mov r15, rdx

_while:
	cmp r15, 0
	jz _after
	mov rax, rdi 				; rax = s1
	mov rdx, rsi				; rdx = s2
	movzx eax, BYTE [rax]		; load lower bits of rax into eax
	movzx edx, BYTE [rdx]		; load lower bits of rdx into edx
	cmp al, 0x0					; is the first byte we're looking at null?
	jne _not_both_null			; if it's not, then we can go on like normal --
	cmp dl, 0x0					; is the second byte we're looking at null?
	je _after					; if it is then we're mostly sort of done then.

_not_both_null:
	cmp al, 65					;
	jl _case_a_done				;
	cmp al, 90					;
	jg _case_a_done				;
	add ax, 32					;

_case_a_done:
	cmp dl, 65					;
	jl _case_done				;
	cmp dl, 90					;
	jg _case_done				;
	add dx, 32					;

_case_done:
	cmp al, dl					;
	jne _after					;
	inc rdi						;
	inc rsi						;
	dec r15						;
	jmp _while					;

_after:
	cmp al, dl					;
	je _equal					;
	jl _less					;
	sub al, dl					;
	jmp _end					;

_equal:
	mov rax, 0x0				;
	jmp _end					;

_less:
	sub al, dl					;
	neg al						;
	imul eax, -1				;

_end:
	mov rbp, rsp				; restore the original base pointer
	pop rbp						; pop value of base pointer from stack
	ret							; return to the original caller
