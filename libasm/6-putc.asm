BITS 64
	global asm_putc
	section .text

asm_putc:
	push rbp			; preserve base pointer
	mov rbp, rsp		; move stack pointer to base

	push rdi			; push contents of rdi to task
	mov rax, 1			; move the value of 1 into rax
	mov rdi, 1			; move the value of 1 into rdi
	mov rsi, rsp		; move the stack pointer into second arg
	mov rdx, 1			; move the value of 1 into return val
	syscall

	mov rsp, rbp		; move base pointer back to stack
	pop rbp				; pop the old base pointer
	ret					; return to called
