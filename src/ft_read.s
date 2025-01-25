global ft_read
extern __errno_location

section .text

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	mov r10, rax
	call __errno_location
	mov [rax], r10
	mov rax, -1
	ret
