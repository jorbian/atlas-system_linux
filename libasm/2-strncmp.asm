BITS 64
    global asm_strncmp
    section .text

asm_strncmp:
    ; Function prologue: Saving the base pointer (RBP) and stack pointer (RSP)
    push rbp
    mov rbp, rsp
    push rcx   ; Save RCX (counter) on the stack

_Loop:
    ; Load the character from the source string (RDI) into RAX and zero-extend it to 32 bits (EAX)
    mov rax, rdi
    mov rcx, rsi   ; Copy the source pointer (RSI) into RCX to access characters from it

    ; Load the byte (character) at the current position of the source string (RDI) into EAX
    movzx eax, BYTE [rax]

    ; Load the byte (character) at the current position of the destination string (RSI) into ECX
    movzx ecx, BYTE [rcx]

    ; Compare the two characters
    cmp al, 0x0   ; Check if the source character (EAX) is null (end of string)
    je _L1        ; If it is, jump to the label _L1

    cmp al, cl    ; Compare the characters (EAX and ECX)
    jne _L1       ; If they are not equal, jump to the label _L1

    ; Increment the pointers and decrement the counter (EDX)
    inc rdi
    inc rsi
    dec edx

    ; If the counter (EDX) has reached zero, we have successfully compared the specified number of characters
    jz _Is        ; Jump to the label _Is

    ; If the counter (EDX) has not reached zero, continue comparing the next characters
    jmp _Loop

_L1:
    ; We reach this label when characters are not equal or the source string has ended

    ; Compare the characters again (to check if they are equal, but we already know they are not)
    cmp al, cl
    je _Is        ; If they are equal, strings are equal up to the specified number of characters

    jl _Lt        ; If not equal and source character < destination character, jump to _Lt

    ; If not equal and source character > destination character, return 1
    mov RAX, 0x1
    jmp _end

_Is:
    ; Strings are equal up to the specified number of characters (counter reached zero)
    mov RAX, 0x0  ; Return 0 to indicate equality
    jmp _end

_Lt:
    ; Source character < destination character
    mov RAX, -0x1 ; Return -1 to indicate source string is less than destination string
    jmp _end

_end:
    ; Function epilogue: Restore the original value of RCX and return
    pop rcx
    mov rbp, rsp
    pop rbp
    ret
