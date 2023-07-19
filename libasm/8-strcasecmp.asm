BITS 64
	global asm_strcasecmp
	section .text

asm_strcasecmp:
	push rbp					; push value of base pointer onto stack 
	mov rbp, rsp				; copy stack pointer into base pointer
	push rdx					; reserve space on stack for rdx register

_while:
	mov rax, rdi 				; rax = s1
	mov rdx, rsi				; rdx = s2
	movzx eax, BYTE [rax]		; load lower bits of rax into eax
	movzx edx, BYTE [rdx]		; load lower bits of rdx into edx
	cmp al, 0x0					; is the first byte we're looking at null?
	jne _not_both_null			; if it's not, then we can go on like normal --
	cmp dl, 0x0					; is the second byte we're looking at null?
	je _L2						; if it is then we're mostly sort of done then.

_not_both_null:
	cmp al, 65					; is first letter we're dealing with uppercase?
	jl _case_a_done				
	cmp al, 90
	jg _case_a_done
	add ax, 32

_case_a_done:
	cmp dl, 65
	jl _L1
	cmp dl, 90
	jg _L1
	add dx, 32

_L1:
	cmp al, dl
	jne _L2
	inc rdi
	inc rsi
	jmp _while

_L2:
	cmp al, dl
	je _isIS
	jl _less_then
	sub al, dl
	jmp _end				; proced to end of subroutine

_isIS:
	mov rax, 0x0
	jmp _end				; proced to end of subroutine

_less_then:
	sub al, dl
	neg al
	imul eax, -1

_end:
	pop rdx					; pop the value of rdx from stack
	mov rbp, rsp			; restore the original base pointer
	pop rbp					; pop value of base pointer from stack
	ret						; return to the original caller
