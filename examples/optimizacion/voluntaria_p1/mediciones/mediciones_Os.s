	.file	"mediciones.c"
	.text
	.globl	producto
	.type	producto, @function
producto:
.LFB24:
	.cfi_startproc
	endbr64
	mulss	%xmm1, %xmm0
	movss	%xmm0, (%rdi)
	ret
	.cfi_endproc
.LFE24:
	.size	producto, .-producto
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"r+"
.LC2:
	.string	"tiempos.csv"
.LC3:
	.string	"w"
.LC4:
	.string	"Error al abrir el archivo de guardado de resultados."
.LC5:
	.string	"overhead,total_time,real_time\n"
.LC9:
	.string	"%lf,%lf,%lf\n"
.LC10:
	.string	"%f "
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	leaq	-4317184(%rsp), %r11
	.cfi_def_cfa 11, 4317232
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	.cfi_def_cfa_register 7
	subq	$2880, %rsp
	.cfi_def_cfa_offset 4320112
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	movq	%fs:40, %rax
	movq	%rax, 4320056(%rsp)
	xorl	%eax, %eax
	call	fopen@PLT
	testq	%rax, %rax
	jne	.L3
	leaq	.LC3(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	fopen@PLT
	movq	%rax, %rbp
	testq	%rax, %rax
	jne	.L4
	leaq	.LC4(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L2
.L4:
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	call	fputs@PLT
	jmp	.L6
.L3:
	movl	$2, %edx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	fseek@PLT
.L6:
	leaq	40(%rsp), %rdi
	xorl	%esi, %esi
	call	gettimeofday@PLT
	leaq	8(%rsp), %rdi
	xorl	%esi, %esi
	call	gettimeofday@PLT
	movsd	.LC6(%rip), %xmm2
	xorl	%edx, %edx
	movsd	.LC7(%rip), %xmm3
	leaq	56(%rsp), %rsi
	leaq	1440056(%rsp), %rdi
.L7:
	imulq	$2400, %rdx, %rcx
	xorl	%eax, %eax
.L8:
	cvtsi2sdl	%eax, %xmm1
	leal	(%rax,%rdx), %r8d
	addq	$4, %rcx
	cvtsi2sdl	%r8d, %xmm0
	movl	%edx, %r8d
	subl	%eax, %r8d
	incl	%eax
	movaps	%xmm1, %xmm4
	addsd	%xmm3, %xmm1
	addsd	%xmm2, %xmm4
	divsd	%xmm4, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4(%rcx,%rsi)
	cvtsi2sdl	%r8d, %xmm0
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4(%rcx,%rdi)
	cmpl	$600, %eax
	jne	.L8
	incq	%rdx
	cmpq	$600, %rdx
	jne	.L7
	xorl	%eax, %eax
.L9:
	xorl	%edx, %edx
	leaq	(%rsi,%rax), %r9
.L13:
	leaq	(%rdi,%rdx), %r8
	xorl	%ecx, %ecx
	xorps	%xmm0, %xmm0
.L10:
	movss	(%r9,%rcx,4), %xmm1
	mulss	(%r8), %xmm1
	incq	%rcx
	addq	$2400, %r8
	addss	%xmm1, %xmm0
	cmpq	$600, %rcx
	jne	.L10
	leaq	2880056(%rsp), %rbx
	leaq	(%rax,%rbx), %rcx
	movss	%xmm0, (%rcx,%rdx)
	addq	$4, %rdx
	cmpq	$2400, %rdx
	jne	.L13
	addq	$2400, %rax
	cmpq	$1440000, %rax
	jne	.L9
	leaq	24(%rsp), %rdi
	xorl	%esi, %esi
	leaq	4320056(%rsp), %r13
	call	gettimeofday@PLT
	movq	16(%rsp), %rcx
	movq	8(%rsp), %rdx
	movq	%rbp, %rdi
	movsd	.LC8(%rip), %xmm2
	movl	$1, %esi
	leaq	.LC10(%rip), %r14
	movq	%rcx, %rax
	subq	48(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	movq	%rdx, %rax
	subq	40(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	32(%rsp), %rax
	subq	%rcx, %rax
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	subq	%rdx, %rax
	leaq	.LC9(%rip), %rdx
	divsd	%xmm2, %xmm1
	cvtsi2sdq	%rax, %xmm2
	movb	$3, %al
	addsd	%xmm2, %xmm1
	movaps	%xmm1, %xmm2
	subsd	%xmm0, %xmm2
	call	__fprintf_chk@PLT
	movl	$10, %edi
	call	putchar@PLT
.L14:
	xorl	%r12d, %r12d
.L15:
	cvtss2sd	(%rbx,%r12,4), %xmm0
	movq	%r14, %rsi
	movl	$1, %edi
	movb	$1, %al
	call	__printf_chk@PLT
	incq	%r12
	cmpq	$600, %r12
	jne	.L15
	movl	$10, %edi
	addq	$2400, %rbx
	call	putchar@PLT
	cmpq	%rbx, %r13
	jne	.L14
	movq	%rbp, %rdi
	call	fclose@PLT
	xorl	%eax, %eax
.L2:
	movq	4320056(%rsp), %rbx
	subq	%fs:40, %rbx
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	addq	$4320064, %rsp
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	-1717986918
	.long	1072798105
	.align 8
.LC7:
	.long	-858993459
	.long	1073794252
	.align 8
.LC8:
	.long	0
	.long	1093567616
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
