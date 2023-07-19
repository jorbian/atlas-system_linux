BITS 64
	global asm_strchr
	section text

asm_strchr:
	push rbp			; preserve original base pointer
	mov rbp, rsp		; set base pointer to stack pointer
	xor rax, rax		; clear the return value

_loop:
	mov al, BYTE [rdi]	; get current character
	cmp BYTE [rdi], sil	; compare it to character we're looking for
	jz _found_it		; if it's the same jump
	cmp BYTE [rdi], 0	; see if we're reached null terminaotr
	jz _end				; jump to the function epilogue
	inc rdi				; increment string pointer
	jmp _loop			; go back to the top of the loop

_found_it:
	mov rax, rdi		; set return value to string pointer

_end:
	mov rsp, rbp		; restore stack pointer
	pop rbp				; restore base pointer
	ret					; go back to the caller

