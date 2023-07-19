BITS 64
	global asm_strstr
	section .text

asm_strstr:
	push rbp,				; Preserve original base pointer
	mov rbp, rsp			; Set base pointer to stack pointer

_while:
	xor rax, rax			; Clear rax register
	push rdi				; Save rdi register
	push rsi				; Save rsi register
	jmp _strstr				; Jump to the implementation of strstr

_strstr_ret:
	pop rsi					; Restore rsi register
	pop rdi					; Restore rdi register
	test rax, rax			; Check if rax is zero (end search or not found)
	jnz _end				; If not zero, go to _end
	inc rdi					; Move to the next character in rdi
	cmp BYTE [rdi], 0		; Check if rdi points to the end of string
	jz _end					; if so -- end subroutine
	jmp _while				; if not -- keep searching

_end:
	mov rsp, rbp			; Restore stack pointer
	pop rbp					; Restore base pointer
	ret						; Return to the caller

_strstr:
	push rbp				; Preserve rbp register
	mov rbp, rsp			; Set base pointer to stack pointer
	push rdi				; Save rdi register
	xor rax, rax			; Clear rax register

_ss_while:
	movzx edx, BYTE [rdi]	; Load the next byte from rdi into edx
	movzx ecx, BYTE [rsi]	; Load the next byte from rsi into ecx
	test cl, cl				; Check if the byte in ecx is zero (end of search)
	jz _ss_found			; If yes, the search is successful
	cmp dl, cl				; Compare the bytes in edx and ecx

_after:
	jnz _ss_not_found		; it wasn't found if the value was 0
	inc rdi					; Move to next character in rdi
	inc rsi					; Move to next character in rsi
	jmp _ss_while			; keep searching search

_ss_found:
	pop rax					; Restore rax register
	jmp _ss_end				; Jump to the end of strstr

_ss_not_found:
	pop rax					; Restore rax register
	xor rax, rax			; Set rax to zero (not found)

_ss_end:
	mov rsp, rbp			; Restore stack pointer
	pop rbp					; Restore base pointer
	jmp _strstr_ret			; Process return value
