global ft_strdup
extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
	push rdi
	xor rax, rax
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc
	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret
