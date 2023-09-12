global ft_strcmp

section .text

ft_strcmp:
	xor rax, rax
	xor r9, r9
	xor r10, r10
	jmp loop

loop:
	cmp byte [rsi], 0
	je diff
	cmp byte [rdi], 0
	je diff
	mov r10b, byte [rdi]
	cmp byte [rsi], r10b
	jne diff
	inc rdi
	inc rsi
	jmp loop
	ret

diff:
	mov r10b, byte [rdi]
	mov r9b, byte [rsi]
	sub r10, r9
	mov rax, r10
	ret
