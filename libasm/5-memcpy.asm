BITS 64
	global asm_memcpy
	section .text

asm_memcpy:
	push rbp			; preserve base pointer
	mov rbp, rsp		; move stack pointer into base
	push rdi			; save contents of rdi
	xor rax, rax		; clear rax

_while:
	test rdx, rdx		; is rdx equal to zero?
	jz end				; if it is subroutine is done
	dec rdx				; move down the patch of memory
	mov al, BYTE [rsi]	; pick up next byte
	mov BYTE [rdi], al	; shift it over to the rdi register
	inc rdi				; move destination over
	inc rsi				; move original source over
	jmp _while			; back to top of loop to start process again

_end:
	pop rax				; pop the rax register
	mov rsp, rbp		; move base pointer back to stack
	pop rbp				; pop the old stack pointer
	ret					; go back to the caller.

