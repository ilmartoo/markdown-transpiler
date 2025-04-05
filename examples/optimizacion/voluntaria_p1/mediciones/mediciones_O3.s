	.file	"mediciones.c"
	.text
	.p2align 4
	.globl	producto
	.type	producto, @function
producto:
.LFB39:
	.cfi_startproc
	endbr64
	mulss	%xmm1, %xmm0
	movss	%xmm0, (%rdi)
	ret
	.cfi_endproc
.LFE39:
	.size	producto, .-producto
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"r+"
.LC2:
	.string	"tiempos.csv"
.LC3:
	.string	"w"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"Error al abrir el archivo de guardado de resultados."
	.align 8
.LC5:
	.string	"overhead,total_time,real_time\n"
	.section	.rodata.str1.1
.LC10:
	.string	"%lf,%lf,%lf\n"
.LC11:
	.string	"%f "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB40:
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
	je	.L24
	movl	$2, %edx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	fseek@PLT
.L7:
	leaq	32(%rsp), %rdi
	xorl	%esi, %esi
	call	gettimeofday@PLT
	xorl	%esi, %esi
	movq	%rsp, %rdi
	call	gettimeofday@PLT
	leaq	48(%rsp), %r11
	xorl	%edx, %edx
	leaq	1440048(%rsp), %r10
	movdqa	.LC6(%rip), %xmm5
	movq	%r10, %rsi
	movq	%r11, %rcx
	movapd	.LC7(%rip), %xmm3
	movapd	.LC8(%rip), %xmm2
	movdqa	.LC0(%rip), %xmm6
.L8:
	movd	%edx, %xmm4
	xorl	%eax, %eax
	movdqa	%xmm6, %xmm1
	pshufd	$0, %xmm4, %xmm4
.L9:
	movdqa	%xmm1, %xmm10
	movdqa	%xmm4, %xmm0
	paddd	%xmm5, %xmm1
	cvtdq2pd	%xmm10, %xmm9
	movapd	%xmm9, %xmm11
	paddd	%xmm10, %xmm0
	pshufd	$238, %xmm10, %xmm8
	addpd	%xmm3, %xmm11
	cvtdq2pd	%xmm8, %xmm8
	cvtdq2pd	%xmm0, %xmm7
	pshufd	$238, %xmm0, %xmm0
	cvtdq2pd	%xmm0, %xmm0
	addpd	%xmm2, %xmm9
	divpd	%xmm11, %xmm7
	movapd	%xmm8, %xmm11
	addpd	%xmm2, %xmm8
	addpd	%xmm3, %xmm11
	divpd	%xmm11, %xmm0
	cvtpd2ps	%xmm7, %xmm7
	cvtpd2ps	%xmm0, %xmm0
	movlhps	%xmm0, %xmm7
	movdqa	%xmm4, %xmm0
	psubd	%xmm10, %xmm0
	movaps	%xmm7, (%rcx,%rax)
	cvtdq2pd	%xmm0, %xmm7
	divpd	%xmm9, %xmm7
	pshufd	$238, %xmm0, %xmm0
	cvtdq2pd	%xmm0, %xmm0
	divpd	%xmm8, %xmm0
	cvtpd2ps	%xmm7, %xmm7
	cvtpd2ps	%xmm0, %xmm0
	movlhps	%xmm0, %xmm7
	movaps	%xmm7, (%rsi,%rax)
	addq	$16, %rax
	cmpq	$2400, %rax
	jne	.L9
	addl	$1, %edx
	addq	$2400, %rcx
	addq	$2400, %rsi
	cmpl	$600, %edx
	jne	.L8
	leaq	2880048(%rsp), %rbx
	xorl	%r8d, %r8d
	leaq	1442448(%rsp), %r13
	movq	%rbx, %r12
	leaq	1440000(%r10), %r14
.L10:
	imulq	$2400, %r8, %r9
	movq	%r14, %rcx
	movq	%r12, %rdi
	movq	%r10, %rsi
	addq	%r11, %r9
.L14:
	movq	%rsi, %rax
	movq	%r9, %rdx
	pxor	%xmm1, %xmm1
	.p2align 4,,10
	.p2align 3
.L11:
	movss	(%rdx), %xmm0
	addq	$2400, %rax
	addq	$4, %rdx
	shufps	$0, %xmm0, %xmm0
	mulps	-2400(%rax), %xmm0
	addps	%xmm0, %xmm1
	cmpq	%rcx, %rax
	jne	.L11
	addq	$16, %rsi
	movaps	%xmm1, (%rdi)
	leaq	16(%rax), %rcx
	addq	$16, %rdi
	cmpq	%r13, %rsi
	jne	.L14
	addq	$1, %r8
	addq	$2400, %r12
	cmpq	$600, %r8
	jne	.L10
	leaq	16(%rsp), %rdi
	xorl	%esi, %esi
	leaq	2400(%rbx), %r12
	call	gettimeofday@PLT
	movq	8(%rsp), %rcx
	pxor	%xmm0, %xmm0
	movsd	.LC9(%rip), %xmm2
	movq	(%rsp), %rdx
	pxor	%xmm1, %xmm1
	movl	$1, %esi
	movq	%rbp, %rdi
	movq	%rcx, %rax
	subq	40(%rsp), %rax
	leaq	1442400(%rbx), %r14
	cvtsi2sdq	%rax, %xmm0
	movq	%rdx, %rax
	subq	32(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	leaq	.LC11(%rip), %r13
	subq	%rcx, %rax
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	16(%rsp), %rax
	subq	%rdx, %rax
	leaq	.LC10(%rip), %rdx
	divsd	%xmm2, %xmm1
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rax, %xmm2
	movl	$3, %eax
	addsd	%xmm2, %xmm1
	movapd	%xmm1, %xmm2
	subsd	%xmm0, %xmm2
	call	__fprintf_chk@PLT
	movl	$10, %edi
	call	putchar@PLT
.L15:
	leaq	-2400(%r12), %rbx
.L16:
	pxor	%xmm0, %xmm0
	movq	%r13, %rsi
	movl	$1, %edi
	addq	$4, %rbx
	movl	$1, %eax
	cvtss2sd	-4(%rbx), %xmm0
	call	__printf_chk@PLT
	cmpq	%rbx, %r12
	jne	.L16
	movl	$10, %edi
	addq	$2400, %r12
	call	putchar@PLT
	cmpq	%r14, %r12
	jne	.L15
	movq	%rbp, %rdi
	call	fclose@PLT
	xorl	%eax, %eax
.L3:
	movq	4320056(%rsp), %rsi
	subq	%fs:40, %rsi
	jne	.L25
	addq	$4320064, %rsp
	.cfi_remember_state
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
.L24:
	.cfi_restore_state
	leaq	.LC3(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	fopen@PLT
	movq	%rax, %rbp
	testq	%rax, %rax
	je	.L26
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rdi
	call	fwrite@PLT
	jmp	.L7
.L26:
	leaq	.LC4(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L3
.L25:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE40:
	.size	main, .-main
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC6:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC7:
	.long	-1717986918
	.long	1072798105
	.long	-1717986918
	.long	1072798105
	.align 16
.LC8:
	.long	-858993459
	.long	1073794252
	.long	-858993459
	.long	1073794252
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC9:
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
