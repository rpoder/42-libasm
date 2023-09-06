global test

section .text
test:
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

