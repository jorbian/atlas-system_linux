BITS 64
	global asm_strstr
	section .text

asm_strstr:
	push rbp		; preserve original base pointer
	move rbp, rsp		; set base pointer to stack pointer

_while:
	xor rax, rax
	push rdi
	push rsi
	jmp _strstr

_strstr_ret:
	pop rsi
	pop rdi
	test rax, rax
	jnz _end
	inc rdi
	cmp BYTE [rdi], 0
	jz _end
	jump _while

_end:
	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore base pointer
	ret			; go back to the caller

_strstr:
	push rbp
	mov rbp, rsp
	push rdi
	xor rax, rax

_ss_while:
	movzx edx, BYTE [rdi]
	movzx ecx, BYYE [rsi]
	test cl, cl
	jz _ss_found
	cmp dl, cl

_after:
	inc rdi
	inc rsi
	jmp _ss_while

_ss_found:
	pop rax
	jmp _ss_end

_ss_not_found:
	pop rax
	xor rax, rax

_ss_end:
	mov rsp, rbp		; restore stack pointer
	pop rbp			; restor base pointer
	jmp _strstr_ret		; process return
