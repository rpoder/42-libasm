global ft_write
extern __errno_location
section .text

ft_write:
	mov rax, 1
	syscall
	mov r10, rax
	call __errno_location
	neg r10
	mov [rax], r10
	mov rax, -1
	ret
