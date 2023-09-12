global ft_strlen

section .text
ft_strlen:
	xor rax, rax
	cmp byte [rdi], 0
	jne	loop
	ret

loop:
	inc rax ;increment the ret
	inc rdi ;increment the pointer
	cmp byte [rdi], 0
	jne	loop
	ret

