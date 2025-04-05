	.file	"mediciones.c"
	.text
	.globl	producto
	.type	producto, @function
producto:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movss	%xmm0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	producto, .-producto
	.section	.rodata
.LC0:
	.string	"r+"
.LC1:
	.string	"tiempos.csv"
.LC2:
	.string	"w"
	.align 8
.LC3:
	.string	"Error al abrir el archivo de guardado de resultados."
	.align 8
.LC4:
	.string	"overhead,total_time,real_time\n"
.LC9:
	.string	"%lf,%lf,%lf\n"
.LC10:
	.string	"%f "
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	-4317184(%rsp), %r11
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$2944, %rsp
	movl	%edi, -4320116(%rbp)
	movq	%rsi, -4320128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -4320088(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -4320088(%rbp)
	cmpq	$0, -4320088(%rbp)
	jne	.L3
	leaq	.LC2(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -4320088(%rbp)
	cmpq	$0, -4320088(%rbp)
	jne	.L4
	leaq	.LC3(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L21
.L4:
	movq	-4320088(%rbp), %rax
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	leaq	.LC4(%rip), %rdi
	call	fwrite@PLT
	jmp	.L6
.L3:
	movq	-4320088(%rbp), %rax
	movl	$2, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	fseek@PLT
.L6:
	leaq	-4320032(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday@PLT
	leaq	-4320064(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday@PLT
	movl	$0, -4320100(%rbp)
	jmp	.L7
.L10:
	movl	$0, -4320096(%rbp)
	jmp	.L8
.L9:
	movl	-4320100(%rbp), %edx
	movl	-4320096(%rbp), %eax
	addl	%edx, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdl	-4320096(%rbp), %xmm2
	movsd	.LC5(%rip), %xmm1
	addsd	%xmm2, %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movl	-4320096(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320100(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movss	%xmm0, -4320016(%rbp,%rax,4)
	movl	-4320100(%rbp), %eax
	subl	-4320096(%rbp), %eax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdl	-4320096(%rbp), %xmm2
	movsd	.LC6(%rip), %xmm1
	addsd	%xmm2, %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movl	-4320096(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320100(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movss	%xmm0, -2880016(%rbp,%rax,4)
	addl	$1, -4320096(%rbp)
.L8:
	cmpl	$599, -4320096(%rbp)
	jle	.L9
	addl	$1, -4320100(%rbp)
.L7:
	cmpl	$599, -4320100(%rbp)
	jle	.L10
	movl	$0, -4320100(%rbp)
	jmp	.L11
.L16:
	movl	$0, -4320096(%rbp)
	jmp	.L12
.L15:
	pxor	%xmm0, %xmm0
	movss	%xmm0, -4320104(%rbp)
	movl	$0, -4320092(%rbp)
	jmp	.L13
.L14:
	movl	-4320096(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320092(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movss	-2880016(%rbp,%rax,4), %xmm0
	movl	-4320092(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320100(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movl	-4320016(%rbp,%rax,4), %eax
	leaq	-4320108(%rbp), %rdx
	movq	%rdx, %rdi
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	producto
	movss	-4320108(%rbp), %xmm0
	movss	-4320104(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -4320104(%rbp)
	addl	$1, -4320092(%rbp)
.L13:
	cmpl	$599, -4320092(%rbp)
	jle	.L14
	movl	-4320096(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320100(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movss	-4320104(%rbp), %xmm0
	movss	%xmm0, -1440016(%rbp,%rax,4)
	addl	$1, -4320096(%rbp)
.L12:
	cmpl	$599, -4320096(%rbp)
	jle	.L15
	addl	$1, -4320100(%rbp)
.L11:
	cmpl	$599, -4320100(%rbp)
	jle	.L16
	leaq	-4320048(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday@PLT
	movq	-4320064(%rbp), %rax
	movq	-4320032(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	-4320056(%rbp), %rax
	movq	-4320024(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC8(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -4320080(%rbp)
	movq	-4320048(%rbp), %rax
	movq	-4320064(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	-4320040(%rbp), %rax
	movq	-4320056(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC8(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -4320072(%rbp)
	movsd	-4320072(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	subsd	-4320080(%rbp), %xmm1
	movsd	-4320072(%rbp), %xmm0
	movq	-4320080(%rbp), %rdx
	movq	-4320088(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	leaq	.LC9(%rip), %rsi
	movq	%rax, %rdi
	movl	$3, %eax
	call	fprintf@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, -4320100(%rbp)
	jmp	.L17
.L20:
	movl	$0, -4320096(%rbp)
	jmp	.L18
.L19:
	movl	-4320096(%rbp), %eax
	movslq	%eax, %rdx
	movl	-4320100(%rbp), %eax
	cltq
	imulq	$600, %rax, %rax
	addq	%rdx, %rax
	movss	-1440016(%rbp,%rax,4), %xmm0
	pxor	%xmm3, %xmm3
	cvtss2sd	%xmm0, %xmm3
	movq	%xmm3, %rax
	movq	%rax, %xmm0
	leaq	.LC10(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -4320096(%rbp)
.L18:
	cmpl	$599, -4320096(%rbp)
	jle	.L19
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -4320100(%rbp)
.L17:
	cmpl	$599, -4320100(%rbp)
	jle	.L20
	movq	-4320088(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
.L21:
	movq	-8(%rbp), %rcx
	subq	%fs:40, %rcx
	je	.L22
	call	__stack_chk_fail@PLT
.L22:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC5:
	.long	-1717986918
	.long	1072798105
	.align 8
.LC6:
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
