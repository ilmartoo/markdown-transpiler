	.file	"mediciones.c"
	.text
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
	.text
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
	movq	%fs:40, %rax
	movq	%rax, 4320056(%rsp)
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	fopen@PLT
	testq	%rax, %rax
	je	.L23
	movq	%rax, %rbx
	movl	$2, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	fseek@PLT
.L6:
	leaq	32(%rsp), %rdi
	movl	$0, %esi
	call	gettimeofday@PLT
	movq	%rsp, %rdi
	movl	$0, %esi
	call	gettimeofday@PLT
	leaq	48(%rsp), %rdi
	leaq	1440048(%rsp), %r8
	movq	%r8, %r9
	movq	%rdi, %rsi
	movl	$0, %edx
	movsd	.LC6(%rip), %xmm4
	movsd	.LC7(%rip), %xmm3
.L7:
	movl	$0, %eax
.L8:
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
	leal	(%rdx,%rax), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ecx, %xmm0
	movapd	%xmm1, %xmm2
	addsd	%xmm4, %xmm2
	divsd	%xmm2, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, (%rsi,%rax,4)
	movl	%edx, %ecx
	subl	%eax, %ecx
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ecx, %xmm0
	addsd	%xmm3, %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, (%r9,%rax,4)
	addq	$1, %rax
	cmpq	$600, %rax
	jne	.L8
	addl	$1, %edx
	addq	$2400, %rsi
	addq	$2400, %r9
	cmpl	$600, %edx
	jne	.L7
	movl	$0, %r9d
	leaq	2880048(%rsp), %r14
	leaq	1442400(%r8), %r10
	jmp	.L9
.L23:
	leaq	.LC3(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	fopen@PLT
	movq	%rax, %rbx
	testq	%rax, %rax
	je	.L24
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rdi
	call	fwrite@PLT
	jmp	.L6
.L24:
	leaq	.LC4(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L2
.L25:
	movss	%xmm1, (%rsi)
	addq	$4, %rsi
	addq	$4, %rcx
	cmpq	%r10, %rcx
	je	.L11
.L13:
	leaq	-1440000(%rcx), %rax
	leaq	(%r9,%rdi), %rdx
	pxor	%xmm1, %xmm1
.L10:
	movss	(%rax), %xmm0
	mulss	(%rdx), %xmm0
	addss	%xmm0, %xmm1
	addq	$2400, %rax
	addq	$4, %rdx
	cmpq	%rcx, %rax
	jne	.L10
	jmp	.L25
.L11:
	addq	$2400, %r9
	cmpq	$1440000, %r9
	je	.L26
.L9:
	leaq	(%r9,%r14), %rsi
	leaq	1440000(%r8), %rcx
	jmp	.L13
.L26:
	leaq	16(%rsp), %rdi
	movl	$0, %esi
	call	gettimeofday@PLT
	movq	(%rsp), %rdx
	movq	8(%rsp), %rcx
	movq	%rcx, %rax
	subq	40(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC8(%rip), %xmm2
	divsd	%xmm2, %xmm0
	movq	%rdx, %rax
	subq	32(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	movq	24(%rsp), %rax
	subq	%rcx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	divsd	%xmm2, %xmm1
	movq	16(%rsp), %rax
	subq	%rdx, %rax
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rax, %xmm2
	addsd	%xmm2, %xmm1
	movapd	%xmm1, %xmm2
	subsd	%xmm0, %xmm2
	leaq	.LC9(%rip), %rdx
	movl	$1, %esi
	movq	%rbx, %rdi
	movl	$3, %eax
	call	__fprintf_chk@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	2400(%r14), %r12
	addq	$1442400, %r14
	leaq	.LC10(%rip), %r13
.L14:
	leaq	-2400(%r12), %rbp
.L15:
	pxor	%xmm0, %xmm0
	cvtss2sd	0(%rbp), %xmm0
	movq	%r13, %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	addq	$4, %rbp
	cmpq	%rbp, %r12
	jne	.L15
	movl	$10, %edi
	call	putchar@PLT
	addq	$2400, %r12
	cmpq	%r14, %r12
	jne	.L14
	movq	%rbx, %rdi
	call	fclose@PLT
	movl	$0, %eax
.L2:
	movq	4320056(%rsp), %rbx
	subq	%fs:40, %rbx
	jne	.L27
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
.L27:
	.cfi_restore_state
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
