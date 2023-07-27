BITS 64
    global asm_strlen
    section .text

asm_strlen:
    push rbp               ; Save base pointer
    mov rbp, rsp           ; Set up the new base pointer

    xor rax, rax           ; Initialize length
    mov rdi, rdi           ; Load address of the input string

loop_start:
    cmp byte [rdi], 0      ; Check for null termination
    je loop_end            ; Exit the loop

    inc rax                ; Increment the length
    inc rdi                ; Move to the next character
    jmp loop_start         ; Continue looping

loop_end:
    pop rbp                ; Restore the base pointer
    ret                    ; Return to the calling code
