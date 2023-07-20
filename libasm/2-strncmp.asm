BITS 64
    global asm_strncmp
    section .text

asm_strncmp:
	push rbp			    ; preserve original base pointer
	mov rbp, rsp		    ; set base pointer to stack pointer
    push rcx                ; save rcx (counter) on stack

_Loop:
    mov rax, rdi            ; load in character from source string
    mov rcx, rsi            ; copy source pointer to access characters
    movzx eax, BYTE [rax]   ; move byte at current pos in source to eax
    movzx ecx, BYTE [rcx]   ; move byte at current pos in dest to ecx

    cmp al, 0x0             ; if character from source string null terminator?
    je _process             ; prepare to treturn value

    cmp al, cl              ; Compare characters (eax and exc)
    jne _process            ; prepare to treturn value

    inc rdi                 ; slide forward one character on source
    inc rsi                 ; slide forward one character on dest

    dec edx                 ; decrement counter value
    jz _strs_eq             ; if edx reached zero strings are equal so
    jmp _Loop               ; if not move back to top of loop

_process:
    cmp al, cl              ; recompare characters
    je _strs_eq             ; prepare to return 0
    jl _less_than           ; prepare to return -1

    mov RAX, 0x1            ; return 1
    jmp _end                ; proced to end

_strs_eq:
    mov RAX, 0x0            ; strings equal up to limit so return 0
    jmp _end                ; proced to end

_less_than:
    mov RAX, -0x1           ; src < dest character so return - 1
    jmp _end                ; procede to end

_end:
    pop rcx                 ; restore original value of rcx
	mov rsp, rbp		    ; restore stack pointer
	pop rbp				    ; restore base pointer
	ret					    ; go back to the caller
