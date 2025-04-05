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
.LC9:
	.string	"%lf,%lf,%lf\n"
.LC10:
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
	movq	%rsp, %rdi
	xorl	%esi, %esi
	call	gettimeofday@PLT
	leaq	48(%rsp), %rdi
	xorl	%edx, %edx
	leaq	1440048(%rsp), %r9
	movsd	.LC6(%rip), %xmm4
	movsd	.LC7(%rip), %xmm3
	movq	%r9, %r8
	movq	%rdi, %rsi
.L8:
	xorl	%eax, %eax
.L9:
	pxor	%xmm1, %xmm1
	leal	(%rdx,%rax), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm1
	cvtsi2sdl	%ecx, %xmm0
	movl	%edx, %ecx
	subl	%eax, %ecx
	movapd	%xmm1, %xmm2
	addsd	%xmm3, %xmm1
	addsd	%xmm4, %xmm2
	divsd	%xmm2, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, (%rsi,%rax,4)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ecx, %xmm0
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, (%r8,%rax,4)
	addq	$1, %rax
	cmpq	$600, %rax
	jne	.L9
	addl	$1, %edx
	addq	$2400, %rsi
	addq	$2400, %r8
	cmpl	$600, %edx
	jne	.L8
	xorl	%r10d, %r10d
	pxor	%xmm2, %xmm2
	leaq	2880048(%rsp), %r14
	leaq	1440000(%r9), %r11
	leaq	1442400(%r9), %r8
.L10:
	leaq	(%r14,%r10), %rsi
	movq	%r11, %rcx
	leaq	(%r10,%rdi), %r9
.L14:
	leaq	-1440000(%rcx), %rax
	movq	%r9, %rdx
	movaps	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L11:
	movss	(%rax), %xmm0
	mulss	(%rdx), %xmm0
	addq	$2400, %rax
	addq	$4, %rdx
	addss	%xmm0, %xmm1
	cmpq	%rcx, %rax
	jne	.L11
	leaq	4(%rax), %rcx
	movss	%xmm1, (%rsi)
	addq	$4, %rsi
	cmpq	%r8, %rcx
	jne	.L14
	addq	$2400, %r10
	cmpq	$1440000, %r10
	jne	.L10
	leaq	16(%rsp), %rdi
	xorl	%esi, %esi
	leaq	2400(%r14), %r12
	addq	$1442400, %r14
	call	gettimeofday@PLT
	pxor	%xmm0, %xmm0
	movq	(%rsp), %rdx
	movq	%rbp, %rdi
	movq	8(%rsp), %rcx
	pxor	%xmm1, %xmm1
	movsd	.LC8(%rip), %xmm2
	movl	$1, %esi
	leaq	.LC10(%rip), %r13
	movq	%rcx, %rax
	subq	40(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	movq	%rdx, %rax
	subq	32(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	subq	%rcx, %rax
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	16(%rsp), %rax
	subq	%rdx, %rax
	leaq	.LC9(%rip), %rdx
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
	cmpq	%r12, %r14
	jne	.L15
	movq	%rbp, %rdi
	call	fclose@PLT
	xorl	%eax, %eax
.L3:
	movq	4320056(%rsp), %rdi
	subq	%fs:40, %rdi
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
