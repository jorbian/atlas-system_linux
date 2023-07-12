section .txt
	[GLOBAL asm_strlen:]

asm_strlen:
	push ebp
	move epb, esp

	move edx, [edb + 8]	; the string
	xor eax, eax

then:
	inc eax

if:
	mov cl, [edx + eax]
	cmp cl, 0x0
	jne then

end:
	pop edp
	ret
