BITS 64
    global asm_strcmp
    section .text

asm_strcmp:
    push rcx

_while:
    cmp [rdi], byte 0       ; Have we reached end of first string?
    jz first_ends
    cmp [rsi], byte 0
    jz second_ends
    mov rcx, [rsi]
    cmp [rdi], rcx
    jl less
    jg greater
    inc rdi
    inc rsi
    jmp _while

first_ends:
    cmp [rsi], byte 0
    jz return_matched
    jmp less

second_ends:
    jmp greater

return_matched:
    xor rax, rax
    jmp exit

greater:
    xor rax, rax
    inc rax
    jmp exit

less:
    xor rax, rax
    dec rax
    jmp exit

exit:
    pop rcx
    ret