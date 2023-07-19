BITS 64
    global asm_strcmp
    section .text

asm_strcmp:
    push rcx

_while:
    cmp [rdi], byte 0       ; Have we reached end of first string?
    jz _first_end           ; See if there's a match
    cmp [rsi], byte 0       ; Have we reached end of second string?
    jz _second_end          ; we're pretty much done then...
    mov rcx, [rsi]
    cmp [rdi], rcx
    jl _less
    jg _greater
    inc rdi                 ; move to the next character of first string
    inc rsi                 ; move to the next character of second string
    jmp _while              ; loop back up to the top

_first_end:
    cmp [rsi], byte 0       ;
    jz _matched             ; return the match
    jmp _less

_second_end:
    jmp _greater

_matched:
    xor rax, rax            ; clear the rax register
    jmp _end

_greater:
    xor rax, rax            
    inc rax
    jmp _end

_less:
    xor rax, rax
    dec rax
    jmp _end

_end:
    pop rcx
    ret