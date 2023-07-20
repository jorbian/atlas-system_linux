BITS 64
    global asm_strpbrk
    section .text

asm_strpbrk:
    push rcx
    push rdx
    push rbx
    push r9
    xor rdx, rdx
    xor rcx, rcx
    xor rbx, rbx

_comp_char:
    mov dl, [rdi + rcx]
    cmp dl, 0
    jz _no_match
    xor r9, r9

zsearch_char:
    mov bl, [rsi + r9]
    cmp bl, 0
    jz _new_com
    cmp dl, bl
    je _pre_end
    inc r9
    jmp zsearch_char

_new_com:
    inc rcx
    jmp _comp_char

_no_match:
    xor rax, rax
    jmp _end

_pre_end:
    mov rax, rdi
    add rax, rcx

_end:
    pop r9
    pop rbx
    pop rdx
    pop rcx
    ret
