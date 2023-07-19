BITS 64
	global asm_puts
	extern asm_strlen

asm_puts:
	push rdi
	push rsi
	push rdx
	mov rsi, rdi
	call asm_strlen		; calculate the length of the string

	mov rdx, rax		; move the string length into rdx
	mov rdi, 1			; stdout as file descriptor
	mov rax, 1			; tee up the sys_write syscall
	syscall				; invoke the syscall
	mov rax, rdx		; move the contents of rdx into rax
	pop rdx
	pop rsi
	pop rdi
	ret					; return to caller

