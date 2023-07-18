BITS 64
    global asm_strncmp
	section .text

asm_strncmp:
    push rbp
    mov rbp, rsp
    push rdi
    push rsi
    push rcx

    xor rax, rax    ; Return value: 0 if equal, < 0 if s1 < s2, > 0 if s1 > s2

    cmp rcx, 0      ; Check if the maximum length is zero
    je .exit

.loop:
    mov al, byte [rdi]   ; Load a byte from the first string
    mov dl, byte [rsi]   ; Load a byte from the second string
    cmp al, dl           ; Compare the bytes
    jne .exit            ; If not equal, exit the loop

    cmp al, 0            ; Check if the null terminator is reached
    je .exit

    inc rdi              ; Move to the next character in the first string
    inc rsi              ; Move to the next character in the second string
    dec rcx              ; Decrement the remaining length
    jnz .loop            ; Loop if the remaining length is not zero

.exit:
    pop rcx
    pop rsi
    pop rdi
    pop rbp
    ret
