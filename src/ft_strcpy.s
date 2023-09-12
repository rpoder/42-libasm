global ft_strcpy

section .text

ft_strcpy:
	mov rax, rdi
	jmp loop
	ret

loop:
	mov r10b, byte [rsi]
	mov byte [rdi], r10b
	cmp byte [rsi], 0
	je end
	inc rdi ;increment dest
	inc rsi ;increment src
	jmp loop
	ret

end:
	ret
