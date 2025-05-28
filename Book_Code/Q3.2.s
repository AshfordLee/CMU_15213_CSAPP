	.file	"Q3.2.c"
	.text
	.p2align 4
	.globl	decode1
	.type	decode1, @function
decode1:
.LFB0:
	.cfi_startproc
	endbr64
	movl	(%rdi), %r8d
	movl	(%rsi), %ecx
	movl	(%rdx), %eax
	movl	%r8d, (%rsi)
	movl	%ecx, (%rdx)
	movl	%eax, (%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	decode1, .-decode1
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
