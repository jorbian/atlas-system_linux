BITS 64
    global asm_strcspn
    section .text

asm_strcspn:
    push rcx                ; save contents of rcx to stack
    push rdx                ; save contents of rdx to stack
    push rbx                ; save contents of rbx to stack
    push r9                 ; save contents of rcx to stack

    xor rdx, rdx            ; initalize index for source string (rdi)
    xor rcx, rcx            ; initalize index for characters to search (rsi)
    xor rbx, rbx            ; rbx will be used to store the current character being compared

_comp_char:
    mov dl, [rdi + rcx]     ; move character from the source string into dl
    cmp dl, 0               ; end of string reached?
    jz _end                 ; if so, jump to the end
    xor r9, r9              ; if not set up a counter for characters to search

_search_char:
    mov bl, [rsi + r9]     ; move character from characters to search into bl
    cmp bl, 0              ; have we reached the null terminating byte?
    jz _new_comp           ; If so, we haven't found a match, so move on
    cmp dl, bl             ; does character (dl) from source match query (bl)?
    je _end                ; if so, then jump to the end
    jmp _new_search        ; if not then we have to keep searching...

_new_comp:
    inc rcx                ; move up one index on the search string
    jmp _comp_char         ; Jump back to compare the new character

_new_search:
    inc r9                 ; slide over to next character to look for
    jmp _search_char       ; Jump back to search the next character

_end:
    mov rax, rcx          ; store the result (if any)
    pop r9                ; restore contents of r9
    pop rbx               ; restore contents of rbx
    pop rdx               ; restore contents of rdx
    pop rcx               ; restore contents of rcx
    ret                   ; go back to the caller
