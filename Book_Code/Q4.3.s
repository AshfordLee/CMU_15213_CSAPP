	.file	"Q4.3.c"
	.text
	.globl	rSum
	.type	rSum, @function
rSum:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpl	$0, -28(%rbp)
	jg	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	-24(%rbp), %rax
	movl	(%rax), %ebx
	movl	-28(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	addq	$4, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	rSum
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	rSum, .-rSum
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
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


#Y86-64

	pushq %rbp #保存调用者的栈基址
	rrmovq %rsp,%rbp #设置新栈基址%rsp
	pushq %rbx #被调用者保存寄存器，执行完了再恢复
	irmovq $24,%r10 #准备栈空间大小，%r10是个通用寄存器
	subq %r10,%rsp #分派栈空间

	#传递参数 rdi=Start,rsi=Count
	rmmovq %rdi,-24(%rbp) #保存Start指针
	rmmovq %rsi,-28(%rbp) #保存Count的数值

	#判断递归出口Count<=0
	irmovq $0,%r10 #常数0放进通用寄存器%r10
	rmmovq %rsi,%r11 #Count值放进寄存器%r11
	subq %r10,%r11 #获取Count-0
	jle ReturnZero #如果Count<=0就跳转到递归出口

	#递归部分 
	mrmovq -24(%rbp),%rax #获取Start指针
	mrmovq (%rax),%rbx #获取*Start的值

	#计算Count-1准备递归
	irmovq $1,%r10 #常数1放到寄存器%r10里面
	rrmovq %rsi,%rdx #Count放到%rdx
	subq %r10,%rdx #Count-1

	#计算Start+1
	irmovq $4,%r10 #准备常数4(int的大小)
	rrmovq %rdi,%rax #复制Start到rax
	addq %r10,%rax #Start指针加4字节

	#递归调用
	rrmovq %rax,%rdi #Start+1
	rrmovq %rdx,%rsi #Count-1

	call rSum #调用rSum(Start+1,Count-1)

	addq %rbx,%rax #*Start+递归结果
	jmp Done #跳转到函数结尾

ReturnZero:
	irmovq $0,%rax #%rax置为0

Done:
    # 函数尾声
    mrmovq -8(%rbp), %rbx   # 恢复rbx寄存器
    rrmovq %rbp, %rsp       # 恢复栈指针
    popq %rbp               # 恢复栈基址
    ret                     # 返回