	.file	"main.c++"
	.section	.text._ZN3fem6Prism6IdE4setNERKNS_5pointE,"axG",@progbits,_ZN3fem6Prism6IdE4setNERKNS_5pointE,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE4setNERKNS_5pointE
	.type	_ZN3fem6Prism6IdE4setNERKNS_5pointE, @function
_ZN3fem6Prism6IdE4setNERKNS_5pointE:
.LFB3526:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	16(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE3526:
	.size	_ZN3fem6Prism6IdE4setNERKNS_5pointE, .-_ZN3fem6Prism6IdE4setNERKNS_5pointE
	.section	.text._ZN3fem6Prism6IdE4setNERKdS3_S3_,"axG",@progbits,_ZN3fem6Prism6IdE4setNERKdS3_S3_,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE4setNERKdS3_S3_
	.type	_ZN3fem6Prism6IdE4setNERKdS3_S3_, @function
_ZN3fem6Prism6IdE4setNERKdS3_S3_:
.LFB3560:
	.cfi_startproc
	movsd	(%rdx), %xmm0
	movq	88(%rdi), %rax
	movsd	.LC0(%rip), %xmm3
	movsd	.LC1(%rip), %xmm1
	xorpd	%xmm3, %xmm0
	movaps	%xmm1, %xmm2
	subsd	(%rsi), %xmm0
	subsd	(%rcx), %xmm2
	addsd	%xmm1, %xmm0
	mulsd	%xmm2, %xmm0
	movsd	.LC2(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, (%rax)
	movaps	%xmm1, %xmm0
	subsd	(%rcx), %xmm0
	mulsd	(%rsi), %xmm0
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, 8(%rax)
	movaps	%xmm1, %xmm0
	subsd	(%rcx), %xmm0
	mulsd	(%rdx), %xmm0
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, 16(%rax)
	movsd	(%rdx), %xmm0
	xorpd	%xmm3, %xmm0
	movsd	(%rcx), %xmm3
	subsd	(%rsi), %xmm0
	addsd	%xmm1, %xmm3
	addsd	%xmm1, %xmm0
	mulsd	%xmm3, %xmm0
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, 24(%rax)
	movsd	(%rcx), %xmm0
	addsd	%xmm1, %xmm0
	mulsd	(%rsi), %xmm0
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, 32(%rax)
	addsd	(%rcx), %xmm1
	mulsd	(%rdx), %xmm1
	mulsd	%xmm2, %xmm1
	movsd	%xmm1, 40(%rax)
	leaq	88(%rdi), %rax
	ret
	.cfi_endproc
.LFE3560:
	.size	_ZN3fem6Prism6IdE4setNERKdS3_S3_, .-_ZN3fem6Prism6IdE4setNERKdS3_S3_
	.section	.text._ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE,"axG",@progbits,_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE
	.type	_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE, @function
_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE:
.LFB4023:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	32(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4023:
	.size	_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE, .-_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE
	.section	.text._ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_,"axG",@progbits,_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_
	.type	_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_, @function
_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_:
.LFB4024:
	.cfi_startproc
	movsd	.LC1(%rip), %xmm2
	movq	112(%rdi), %rax
	movsd	.LC0(%rip), %xmm3
	xorl	%edx, %edx
	movaps	%xmm2, %xmm0
	movsd	.LC2(%rip), %xmm1
	subsd	(%rcx), %xmm0
	xorpd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	movaps	%xmm2, %xmm0
	subsd	(%rcx), %xmm0
	movq	%rdx, 16(%rax)
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rax)
	movsd	(%rcx), %xmm0
	addsd	%xmm2, %xmm0
	xorpd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 24(%rax)
	addsd	(%rcx), %xmm2
	movq	%rdx, 40(%rax)
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, 32(%rax)
	leaq	112(%rdi), %rax
	ret
	.cfi_endproc
.LFE4024:
	.size	_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_, .-_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_
	.section	.text._ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE,"axG",@progbits,_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE
	.type	_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE, @function
_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE:
.LFB4025:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	48(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4025:
	.size	_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE, .-_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE
	.section	.text._ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_,"axG",@progbits,_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_
	.type	_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_, @function
_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_:
.LFB4026:
	.cfi_startproc
	movsd	.LC1(%rip), %xmm2
	movq	136(%rdi), %rax
	movsd	.LC0(%rip), %xmm3
	xorl	%edx, %edx
	movaps	%xmm2, %xmm0
	movsd	.LC2(%rip), %xmm1
	subsd	(%rcx), %xmm0
	movq	%rdx, 8(%rax)
	xorpd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	movaps	%xmm2, %xmm0
	subsd	(%rcx), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 16(%rax)
	movsd	(%rcx), %xmm0
	movq	%rdx, 32(%rax)
	addsd	%xmm2, %xmm0
	xorpd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 24(%rax)
	addsd	(%rcx), %xmm2
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, 40(%rax)
	leaq	136(%rdi), %rax
	ret
	.cfi_endproc
.LFE4026:
	.size	_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_, .-_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_
	.section	.text._ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE,"axG",@progbits,_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE
	.type	_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE, @function
_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE:
.LFB4027:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	64(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4027:
	.size	_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE, .-_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE
	.section	.text._ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_,"axG",@progbits,_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_
	.type	_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_, @function
_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_:
.LFB4028:
	.cfi_startproc
	movsd	(%rdx), %xmm0
	movq	160(%rdi), %rax
	movsd	.LC0(%rip), %xmm2
	movsd	.LC1(%rip), %xmm3
	xorpd	%xmm2, %xmm0
	movsd	.LC2(%rip), %xmm1
	subsd	(%rsi), %xmm0
	addsd	%xmm3, %xmm0
	xorpd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	movsd	(%rsi), %xmm0
	xorpd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rax)
	movsd	(%rdx), %xmm0
	xorpd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 16(%rax)
	movsd	(%rdx), %xmm0
	xorpd	%xmm2, %xmm0
	subsd	(%rsi), %xmm0
	addsd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 24(%rax)
	movsd	(%rsi), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 32(%rax)
	mulsd	(%rdx), %xmm1
	movsd	%xmm1, 40(%rax)
	leaq	160(%rdi), %rax
	ret
	.cfi_endproc
.LFE4028:
	.size	_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_, .-_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_
	.section	.text._ZNK3fem6Prism6IdE11node_numberEv,"axG",@progbits,_ZNK3fem6Prism6IdE11node_numberEv,comdat
	.align 2
	.weak	_ZNK3fem6Prism6IdE11node_numberEv
	.type	_ZNK3fem6Prism6IdE11node_numberEv, @function
_ZNK3fem6Prism6IdE11node_numberEv:
.LFB4030:
	.cfi_startproc
	movl	$16, %eax
	ret
	.cfi_endproc
.LFE4030:
	.size	_ZNK3fem6Prism6IdE11node_numberEv, .-_ZNK3fem6Prism6IdE11node_numberEv
	.section	.text._ZN3fem6Prism6IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem6Prism6IdE14setCoordinatesEv,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE14setCoordinatesEv
	.type	_ZN3fem6Prism6IdE14setCoordinatesEv, @function
_ZN3fem6Prism6IdE14setCoordinatesEv:
.LFB4022:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA4022
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	movabsq	$-4616189618054758400, %rax
	subq	$528, %rsp
	.cfi_def_cfa_offset 544
	leaq	512(%rsp), %rdx
	leaq	520(%rsp), %rsi
	leaq	352(%rsp), %rdi
	leaq	504(%rsp), %rcx
	movq	%rax, 504(%rsp)
	movq	$0, 512(%rsp)
	movq	$0, 520(%rsp)
.LEHB0:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE0:
	movq	64(%rbx), %rsi
	leaq	352(%rsp), %rdx
	leaq	320(%rsp), %rdi
.LEHB1:
	call	_ZN3fem5pointaSERKS0_
	leaq	320(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE1:
	leaq	352(%rsp), %rdi
.LEHB2:
	call	_ZN3fem5pointD1Ev
	leaq	488(%rsp), %rdx
	leaq	496(%rsp), %rsi
	leaq	288(%rsp), %rdi
	leaq	480(%rsp), %rcx
	movabsq	$-4616189618054758400, %r10
	movabsq	$4607182418800017408, %r11
	movq	%r10, 480(%rsp)
	movq	$0, 488(%rsp)
	movq	%r11, 496(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE2:
	movq	64(%rbx), %rsi
	leaq	288(%rsp), %rdx
	leaq	256(%rsp), %rdi
	addq	$32, %rsi
.LEHB3:
	call	_ZN3fem5pointaSERKS0_
	leaq	256(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE3:
	leaq	288(%rsp), %rdi
.LEHB4:
	call	_ZN3fem5pointD1Ev
	leaq	464(%rsp), %rdx
	leaq	472(%rsp), %rsi
	leaq	224(%rsp), %rdi
	leaq	456(%rsp), %rcx
	movabsq	$-4616189618054758400, %r8
	movabsq	$4607182418800017408, %r9
	movq	%r8, 456(%rsp)
	movq	%r9, 464(%rsp)
	movq	$0, 472(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE4:
	movq	64(%rbx), %rsi
	leaq	224(%rsp), %rdx
	leaq	192(%rsp), %rdi
	addq	$64, %rsi
.LEHB5:
	call	_ZN3fem5pointaSERKS0_
	leaq	192(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE5:
	leaq	224(%rsp), %rdi
.LEHB6:
	call	_ZN3fem5pointD1Ev
	movabsq	$4607182418800017408, %rdi
	leaq	440(%rsp), %rdx
	leaq	448(%rsp), %rsi
	movq	%rdi, 432(%rsp)
	leaq	432(%rsp), %rcx
	leaq	160(%rsp), %rdi
	movq	$0, 440(%rsp)
	movq	$0, 448(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE6:
	movq	64(%rbx), %rsi
	leaq	160(%rsp), %rdx
	leaq	128(%rsp), %rdi
	addq	$96, %rsi
.LEHB7:
	call	_ZN3fem5pointaSERKS0_
	leaq	128(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE7:
	leaq	160(%rsp), %rdi
.LEHB8:
	call	_ZN3fem5pointD1Ev
	movabsq	$4607182418800017408, %rcx
	movabsq	$4607182418800017408, %rsi
	leaq	416(%rsp), %rdx
	movq	%rcx, 408(%rsp)
	movq	%rsi, 424(%rsp)
	leaq	96(%rsp), %rdi
	leaq	424(%rsp), %rsi
	leaq	408(%rsp), %rcx
	movq	$0, 416(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE8:
	movq	64(%rbx), %rsi
	leaq	96(%rsp), %rdx
	leaq	64(%rsp), %rdi
	subq	$-128, %rsi
.LEHB9:
	call	_ZN3fem5pointaSERKS0_
	leaq	64(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE9:
	leaq	96(%rsp), %rdi
.LEHB10:
	call	_ZN3fem5pointD1Ev
	movabsq	$4607182418800017408, %rdx
	leaq	400(%rsp), %rsi
	leaq	32(%rsp), %rdi
	movq	%rdx, 392(%rsp)
	leaq	384(%rsp), %rcx
	leaq	392(%rsp), %rdx
	movabsq	$4607182418800017408, %rax
	movq	$0, 400(%rsp)
	movq	%rax, 384(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE10:
	movq	64(%rbx), %rsi
	leaq	32(%rsp), %rdx
	movq	%rsp, %rdi
	addq	$160, %rsi
.LEHB11:
	call	_ZN3fem5pointaSERKS0_
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
.LEHE11:
	leaq	32(%rsp), %rdi
.LEHB12:
	call	_ZN3fem5pointD1Ev
.LEHE12:
	leaq	64(%rbx), %rax
	addq	$528, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L17:
	.cfi_restore_state
	leaq	352(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L23
.L18:
	leaq	288(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
.L23:
	movq	%rbx, %rdi
.LEHB13:
	call	_Unwind_Resume
.LEHE13:
.L19:
	leaq	224(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L23
.L20:
	leaq	160(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L23
.L21:
	leaq	96(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L23
.L22:
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L23
	.cfi_endproc
.LFE4022:
	.size	_ZN3fem6Prism6IdE14setCoordinatesEv, .-_ZN3fem6Prism6IdE14setCoordinatesEv
.globl __gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA4022:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4022-.LLSDACSB4022
.LLSDACSB4022:
	.uleb128 .LEHB0-.LFB4022
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB1-.LFB4022
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L17-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB2-.LFB4022
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB3-.LFB4022
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L18-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB4-.LFB4022
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB5-.LFB4022
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L19-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB6-.LFB4022
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB7-.LFB4022
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L20-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB8-.LFB4022
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB9-.LFB4022
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L21-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB10-.LFB4022
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB11-.LFB4022
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L22-.LFB4022
	.uleb128 0x0
	.uleb128 .LEHB12-.LFB4022
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB13-.LFB4022
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE4022:
	.section	.text._ZN3fem6Prism6IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem6Prism6IdE14setCoordinatesEv,comdat
	.text
	.align 2
	.type	_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8, @function
_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8:
.LFB4085:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L24
	call	_ZN3fem5pointC1ERKS0_
	movq	32(%rbp), %rax
	movq	%rax, 32(%rbx)
.L24:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4085:
	.size	_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8, .-_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8
	.align 2
	.type	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29, @function
_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29:
.LFB4106:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L26
	jmp	_ZdlPv
.L26:
	ret
	.cfi_endproc
.LFE4106:
	.size	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29, .-_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
	.align 2
	.type	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34, @function
_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34:
.LFB4111:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L28
	jmp	_ZdlPv
.L28:
	ret
	.cfi_endproc
.LFE4111:
	.size	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34, .-_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34
	.align 2
	.type	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94, @function
_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94:
.LFB4171:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rdi, %rdi
	je	.L31
	movabsq	$461168601842738790, %rax
	cmpq	%rax, %rdi
	jbe	.L32
	call	_ZSt17__throw_bad_allocv
.L32:
	imulq	$40, %rdi, %rdi
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	jmp	_Znwm
.L31:
	.cfi_restore_state
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4171:
	.size	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94, .-_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94
	.section	.text._ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev,"axG",@progbits,_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED5Ev,comdat
	.align 2
	.weak	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.type	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev, @function
_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev:
.LFB3585:
	.cfi_startproc
	jmp	_ZN3fem5pointD1Ev
	.cfi_endproc
.LFE3585:
	.size	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev, .-_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.weak	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	.set	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev,_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.section	.text._ZNSt6vectorIdSaIdEED2Ev,"axG",@progbits,_ZNSt6vectorIdSaIdEED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIdSaIdEED2Ev
	.type	_ZNSt6vectorIdSaIdEED2Ev, @function
_ZNSt6vectorIdSaIdEED2Ev:
.LFB3597:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L36
	jmp	_ZdlPv
.L36:
	ret
	.cfi_endproc
.LFE3597:
	.size	_ZNSt6vectorIdSaIdEED2Ev, .-_ZNSt6vectorIdSaIdEED2Ev
	.weak	_ZNSt6vectorIdSaIdEED1Ev
	.set	_ZNSt6vectorIdSaIdEED1Ev,_ZNSt6vectorIdSaIdEED2Ev
	.section	.text._ZNSt6vectorImSaImEED2Ev,"axG",@progbits,_ZNSt6vectorImSaImEED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorImSaImEED2Ev
	.type	_ZNSt6vectorImSaImEED2Ev, @function
_ZNSt6vectorImSaImEED2Ev:
.LFB3600:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L42
	jmp	_ZdlPv
.L42:
	ret
	.cfi_endproc
.LFE3600:
	.size	_ZNSt6vectorImSaImEED2Ev, .-_ZNSt6vectorImSaImEED2Ev
	.weak	_ZNSt6vectorImSaImEED1Ev
	.set	_ZNSt6vectorImSaImEED1Ev,_ZNSt6vectorImSaImEED2Ev
	.section	.text._ZN3fem11BaseElementIdE6gaulegEPdS2_i,"axG",@progbits,_ZN3fem11BaseElementIdE6gaulegEPdS2_i,comdat
	.align 2
	.weak	_ZN3fem11BaseElementIdE6gaulegEPdS2_i
	.type	_ZN3fem11BaseElementIdE6gaulegEPdS2_i, @function
_ZN3fem11BaseElementIdE6gaulegEPdS2_i:
.LFB3643:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	movl	$1, %r15d
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	xorl	%r14d, %r14d
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	movl	%ecx, %r12d
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	movl	$2, %ecx
	leal	1(%r12), %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rsi, %rbp
	.cfi_offset 6, -48
	movl	%r13d, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rdx, %rbx
	.cfi_offset 3, -56
	cltd
	idivl	%ecx
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movabsq	$4607182418800017408, %rdx
	movslq	%r12d, %rcx
	movq	%rdx, 8(%rsp)
	movsd	8(%rsp), %xmm2
	movaps	%xmm2, %xmm1
	movl	%eax, %r13d
	jmp	.L49
.L53:
	cvtsi2sd	%r15d, %xmm0
	movq	%rdx, 72(%rsp)
	cvtsi2sd	%r12d, %xmm3
	movq	%rcx, 24(%rsp)
	movsd	.LC2(%rip), %xmm4
	movsd	%xmm1, 32(%rsp)
	movsd	%xmm2, 48(%rsp)
	subsd	.LC5(%rip), %xmm0
	addsd	%xmm3, %xmm4
	movsd	%xmm3, 80(%rsp)
	mulsd	.LC6(%rip), %xmm0
	divsd	%xmm4, %xmm0
	call	cos
	movsd	.LC7(%rip), %xmm10
	movq	72(%rsp), %rdx
	movsd	.LC8(%rip), %xmm9
	movq	24(%rsp), %rcx
	movsd	32(%rsp), %xmm1
	movsd	48(%rsp), %xmm2
	movsd	80(%rsp), %xmm3
	jmp	.L52
.L54:
	movaps	%xmm5, %xmm0
.L52:
	movq	%rdx, 8(%rsp)
	xorps	%xmm7, %xmm7
	movsd	8(%rsp), %xmm5
	movl	$1, %eax
	jmp	.L50
.L51:
	cvtsi2sd	%eax, %xmm6
	incl	%eax
	movaps	%xmm6, %xmm4
	movaps	%xmm6, %xmm8
	addsd	%xmm6, %xmm4
	subsd	%xmm2, %xmm8
	subsd	%xmm2, %xmm4
	mulsd	%xmm7, %xmm8
	movaps	%xmm5, %xmm7
	mulsd	%xmm0, %xmm4
	mulsd	%xmm5, %xmm4
	subsd	%xmm8, %xmm4
	movaps	%xmm4, %xmm5
	divsd	%xmm6, %xmm5
.L50:
	cmpl	%r12d, %eax
	jle	.L51
	movaps	%xmm0, %xmm4
	movaps	%xmm0, %xmm6
	mulsd	%xmm5, %xmm4
	mulsd	%xmm0, %xmm6
	subsd	%xmm7, %xmm4
	subsd	%xmm1, %xmm6
	mulsd	%xmm3, %xmm4
	divsd	%xmm6, %xmm4
	movaps	%xmm0, %xmm6
	divsd	%xmm4, %xmm5
	subsd	%xmm5, %xmm6
	movaps	%xmm6, %xmm5
	subsd	%xmm0, %xmm6
	movaps	%xmm6, %xmm0
	andpd	%xmm10, %xmm0
	ucomisd	%xmm9, %xmm0
	ja	.L54
	movsd	.LC0(%rip), %xmm0
	movq	%r14, %rax
	negq	%rax
	movsd	.LC9(%rip), %xmm3
	xorpd	%xmm5, %xmm0
	leaq	0(%rbp,%rax), %rsi
	leaq	(%rbx,%rax), %rax
	incl	%r15d
	movsd	%xmm0, 0(%rbp,%r14)
	movaps	%xmm1, %xmm0
	movsd	%xmm5, -8(%rsi,%rcx,8)
	mulsd	%xmm5, %xmm5
	subsd	%xmm5, %xmm0
	mulsd	%xmm4, %xmm0
	mulsd	%xmm4, %xmm0
	divsd	%xmm0, %xmm3
	movsd	%xmm3, (%rbx,%r14)
	addq	$8, %r14
	movsd	%xmm3, -8(%rax,%rcx,8)
.L49:
	cmpl	%r13d, %r15d
	jle	.L53
	addq	$104, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3643:
	.size	_ZN3fem11BaseElementIdE6gaulegEPdS2_i, .-_ZN3fem11BaseElementIdE6gaulegEPdS2_i
	.section	.text._ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc:
.LFB3766:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rdi), %rcx
	subq	(%rdi), %rcx
	movabsq	$576460752303423487, %rax
	movq	%rax, %rdi
	sarq	$5, %rcx
	subq	%rcx, %rdi
	cmpq	%rsi, %rdi
	jae	.L56
	movq	%rdx, %rdi
	call	_ZSt20__throw_length_errorPKc
.L56:
	cmpq	%rsi, %rcx
	cmovae	%rcx, %rsi
	addq	%rcx, %rsi
	jb	.L57
	cmpq	%rax, %rsi
	cmovbe	%rsi, %rax
.L57:
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3766:
	.size	_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc, .-_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc
	.section	.text._ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc:
.LFB3775:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rdi), %rcx
	subq	(%rdi), %rcx
	movabsq	$2305843009213693951, %rax
	movq	%rax, %rdi
	sarq	$3, %rcx
	subq	%rcx, %rdi
	cmpq	%rsi, %rdi
	jae	.L60
	movq	%rdx, %rdi
	call	_ZSt20__throw_length_errorPKc
.L60:
	cmpq	%rsi, %rcx
	cmovae	%rcx, %rsi
	addq	%rcx, %rsi
	jb	.L61
	cmpq	%rax, %rsi
	cmovbe	%rsi, %rax
.L61:
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3775:
	.size	_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc, .-_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev:
.LFB3779:
	.cfi_startproc
	movq	%rdi, %rdx
	leaq	8(%rdi), %rdi
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	$0, 40(%rdx)
	rep stosl
	leaq	8(%rdx), %rax
	movq	%rax, 24(%rdx)
	movq	%rax, 32(%rdx)
	ret
	.cfi_endproc
.LFE3779:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC1Ev,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC2Ev
	.section	.text._ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_,"axG",@progbits,_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_,comdat
	.align 2
	.weak	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
	.type	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_, @function
_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_:
.LFB3800:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rdx
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	movq	%rdi, %rsi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%rsp, %rdi
	call	_ZN3fem5pointaSERKS0_
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
	movq	32(%rbp), %rax
	movq	%rax, 32(%rbx)
	movq	%rbx, %rax
	addq	$40, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3800:
	.size	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_, .-_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
	.section	.text._ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc:
.LFB3801:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rdi), %rcx
	subq	(%rdi), %rcx
	movabsq	$-3689348814741910323, %rax
	sarq	$3, %rcx
	imulq	%rax, %rcx
	movabsq	$461168601842738790, %rax
	movq	%rax, %rdi
	subq	%rcx, %rdi
	cmpq	%rsi, %rdi
	jae	.L66
	movq	%rdx, %rdi
	call	_ZSt20__throw_length_errorPKc
.L66:
	cmpq	%rsi, %rcx
	cmovae	%rcx, %rsi
	addq	%rcx, %rsi
	jb	.L67
	cmpq	%rax, %rsi
	cmovbe	%rsi, %rax
.L67:
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3801:
	.size	_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc, .-_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_:
.LFB3812:
	.cfi_startproc
	leaq	8(%rdi), %rax
	movq	16(%rdi), %rdx
	jmp	.L70
.L73:
	movl	(%rsi), %ecx
	cmpl	%ecx, 32(%rdx)
	jl	.L71
	movq	16(%rdx), %rcx
	jmp	.L72
.L71:
	movq	24(%rdx), %rcx
	movq	%rax, %rdx
.L72:
	movq	%rdx, %rax
	movq	%rcx, %rdx
.L70:
	testq	%rdx, %rdx
	jne	.L73
	ret
	.cfi_endproc
.LFE3812:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_
	.section	.text._ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_,"axG",@progbits,_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_,comdat
	.weak	_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_
	.type	_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_, @function
_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_:
.LFB3858:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rsi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rdx, %rbp
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	jmp	.L75
.L76:
	movq	%rbx, %rsi
	movq	%rbp, %rdx
	movq	%rsp, %rdi
	call	_ZN3fem5pointaSERKS0_
	addq	$32, %rbx
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
.L75:
	cmpq	%r12, %rbx
	jne	.L76
	addq	$32, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3858:
	.size	_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_, .-_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_,comdat
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_:
.LFB3890:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	jmp	.L78
.L79:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L78:
	cmpq	%rbp, %rbx
	jne	.L79
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3890:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv:
.LFB3633:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	(%rdi), %rbp
	movq	8(%rdi), %rsi
	movq	%rbp, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	movq	%rbp, 8(%rbx)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3633:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev:
.LFB3631:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	movq	(%rbx), %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
	.cfi_endproc
.LFE3631:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	.set	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E:
.LFB3647:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbp
	.cfi_offset 6, -24
	.cfi_offset 12, -16
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	jmp	.L88
.L92:
	movq	24(%rbx), %rsi
	movq	%rbp, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	movq	16(%rbx), %r12
	leaq	40(%rbx), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	movq	%rbx, %rdi
	movq	%r12, %rbx
	call	_ZdlPv
.L88:
	testq	%rbx, %rbx
	jne	.L92
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3647:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev:
.LFB3591:
	.cfi_startproc
	movq	16(%rdi), %rsi
	jmp	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.cfi_endproc
.LFE3591:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_,comdat
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_:
.LFB3919:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	jmp	.L99
.L100:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L99:
	cmpq	%rbp, %rbx
	jne	.L100
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3919:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_
	.section	.text._ZSt8_DestroyIN3fem5pointEEvPT_,"axG",@progbits,_ZSt8_DestroyIN3fem5pointEEvPT_,comdat
	.weak	_ZSt8_DestroyIN3fem5pointEEvPT_
	.type	_ZSt8_DestroyIN3fem5pointEEvPT_, @function
_ZSt8_DestroyIN3fem5pointEEvPT_:
.LFB3935:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE3935:
	.size	_ZSt8_DestroyIN3fem5pointEEvPT_, .-_ZSt8_DestroyIN3fem5pointEEvPT_
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_,comdat
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_:
.LFB3843:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	jmp	.L103
.L104:
	movq	%rbx, %rdi
	addq	$32, %rbx
	call	_ZSt8_DestroyIN3fem5pointEEvPT_
.L103:
	cmpq	%rbp, %rbx
	jne	.L104
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3843:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EED2Ev,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev
	.type	_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev, @function
_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev:
.LFB3594:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3594
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdi
.LEHB14:
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
.LEHE14:
	movq	(%rbx), %rdi
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34
.L116:
	.cfi_restore_state
	movq	(%rbx), %rdi
	movq	%rax, %rbp
	call	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34
	movq	%rbp, %rdi
.LEHB15:
	call	_Unwind_Resume
.LEHE15:
	.cfi_endproc
.LFE3594:
	.size	_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev, .-_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev
	.section	.gcc_except_table
.LLSDA3594:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3594-.LLSDACSB3594
.LLSDACSB3594:
	.uleb128 .LEHB14-.LFB3594
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L116-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB15-.LFB3594
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3594:
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EED2Ev,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EED5Ev,comdat
	.weak	_ZNSt6vectorIN3fem5pointESaIS1_EED1Ev
	.set	_ZNSt6vectorIN3fem5pointESaIS1_EED1Ev,_ZNSt6vectorIN3fem5pointESaIS1_EED2Ev
	.section	.text._ZN3fem11BaseElementIdED2Ev,"axG",@progbits,_ZN3fem11BaseElementIdED5Ev,comdat
	.align 2
	.weak	_ZN3fem11BaseElementIdED2Ev
	.type	_ZN3fem11BaseElementIdED2Ev, @function
_ZN3fem11BaseElementIdED2Ev:
.LFB3556:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3556
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rdi)
	leaq	192(%rdi), %rdi
	call	_ZNSt6vectorImSaImEED1Ev
	leaq	160(%rbx), %rdi
	call	_ZNSt6vectorIdSaIdEED1Ev
	leaq	136(%rbx), %rdi
	call	_ZNSt6vectorIdSaIdEED1Ev
	leaq	112(%rbx), %rdi
	call	_ZNSt6vectorIdSaIdEED1Ev
	leaq	88(%rbx), %rdi
	call	_ZNSt6vectorIdSaIdEED1Ev
	leaq	64(%rbx), %rdi
	addq	$16, %rbx
.LEHB16:
	call	_ZNSt6vectorIN3fem5pointESaIS1_EED1Ev
.LEHE16:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
.L122:
	.cfi_restore_state
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbp, %rdi
.LEHB17:
	call	_Unwind_Resume
.LEHE17:
	.cfi_endproc
.LFE3556:
	.size	_ZN3fem11BaseElementIdED2Ev, .-_ZN3fem11BaseElementIdED2Ev
	.section	.gcc_except_table
.LLSDA3556:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3556-.LLSDACSB3556
.LLSDACSB3556:
	.uleb128 .LEHB16-.LFB3556
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L122-.LFB3556
	.uleb128 0x0
	.uleb128 .LEHB17-.LFB3556
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3556:
	.section	.text._ZN3fem11BaseElementIdED2Ev,"axG",@progbits,_ZN3fem11BaseElementIdED5Ev,comdat
	.weak	_ZN3fem11BaseElementIdED1Ev
	.set	_ZN3fem11BaseElementIdED1Ev,_ZN3fem11BaseElementIdED2Ev
	.section	.text._ZN3fem6Prism6IdED2Ev,"axG",@progbits,_ZN3fem6Prism6IdED5Ev,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdED2Ev
	.type	_ZN3fem6Prism6IdED2Ev, @function
_ZN3fem6Prism6IdED2Ev:
.LFB3524:
	.cfi_startproc
	movq	$_ZTVN3fem11PrismFamilyIdEE+16, (%rdi)
	jmp	_ZN3fem11BaseElementIdED2Ev
	.cfi_endproc
.LFE3524:
	.size	_ZN3fem6Prism6IdED2Ev, .-_ZN3fem6Prism6IdED2Ev
	.weak	_ZN3fem6Prism6IdED1Ev
	.set	_ZN3fem6Prism6IdED1Ev,_ZN3fem6Prism6IdED2Ev
	.section	.text._ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_
	.type	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_, @function
_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_:
.LFB3980:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movabsq	$-3689348814741910323, %rax
	movq	%rdx, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbp
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	subq	%rdi, %rbx
	sarq	$3, %rbx
	imulq	%rax, %rbx
	jmp	.L127
.L128:
	movq	%rbp, %rsi
	movq	%r12, %rdi
	addq	$40, %rbp
	addq	$40, %r12
	decq	%rbx
	call	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
.L127:
	testq	%rbx, %rbx
	jg	.L128
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%r12, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3980:
	.size	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_, .-_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_
	.section	.text._ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_,comdat
	.weak	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_
	.type	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_, @function
_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_:
.LFB3828:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EEPS9_EET0_T_SE_SD_
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3828:
	.size	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_, .-_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_
	.section	.text._ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_,"axG",@progbits,_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_,comdat
	.weak	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_
	.type	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_, @function
_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_:
.LFB3735:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET1_T0_SI_SH_
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3735:
	.size	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_, .-_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_
	.section	.text._ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	.type	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_, @function
_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_:
.LFB3983:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movabsq	$-3689348814741910323, %rax
	movq	%rdx, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbp
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	subq	%rdi, %rbx
	sarq	$3, %rbx
	imulq	%rax, %rbx
	jmp	.L132
.L133:
	movq	%rbp, %rsi
	movq	%r12, %rdi
	addq	$40, %rbp
	addq	$40, %r12
	decq	%rbx
	call	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
.L132:
	testq	%rbx, %rbx
	jg	.L133
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%r12, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3983:
	.size	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_, .-_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	.section	.text._ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_,"axG",@progbits,_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_,comdat
	.weak	_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_
	.type	_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_, @function
_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_:
.LFB3984:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L134
	call	_ZN3fem5pointC1ERKS0_
	movq	32(%rbp), %rax
	movq	%rax, 32(%rbx)
.L134:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3984:
	.size	_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_, .-_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_,comdat
	.weak	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_
	.type	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_, @function
_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_:
.LFB3923:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3923
	pushq	%r13
	.cfi_def_cfa_offset 16
	movq	%rsi, %r13
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rdx, %r12
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rdx, %rbx
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	jmp	.L137
.L138:
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB18:
	call	_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_
.LEHE18:
	addq	$40, %rbp
	addq	$40, %rbx
.L137:
	cmpq	%r13, %rbp
	jne	.L138
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L142:
	.cfi_restore_state
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB19:
	call	_Unwind_Resume
.LEHE19:
.L141:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbx, %rsi
	movq	%r12, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB20:
	call	__cxa_rethrow
.LEHE20:
	.cfi_endproc
.LFE3923:
	.size	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_, .-_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_
	.section	.gcc_except_table
	.align 4
.LLSDA3923:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3923-.LLSDATTD3923
.LLSDATTD3923:
	.byte	0x1
	.uleb128 .LLSDACSE3923-.LLSDACSB3923
.LLSDACSB3923:
	.uleb128 .LEHB18-.LFB3923
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L141-.LFB3923
	.uleb128 0x1
	.uleb128 .LEHB19-.LFB3923
	.uleb128 .LEHE19-.LEHB19
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB20-.LFB3923
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L142-.LFB3923
	.uleb128 0x0
.LLSDACSE3923:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3923:
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_,comdat
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_,comdat
	.weak	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_
	.type	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_, @function
_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_:
.LFB3977:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3977
	pushq	%r13
	.cfi_def_cfa_offset 16
	movq	%rsi, %r13
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rdx, %r12
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rdx, %rbx
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	jmp	.L144
.L145:
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB21:
	call	_ZSt10_ConstructIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EES6_EvPT_RKT0_
.LEHE21:
	addq	$40, %rbp
	addq	$40, %rbx
.L144:
	cmpq	%r13, %rbp
	jne	.L145
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L149:
	.cfi_restore_state
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB22:
	call	_Unwind_Resume
.LEHE22:
.L148:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbx, %rsi
	movq	%r12, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB23:
	call	__cxa_rethrow
.LEHE23:
	.cfi_endproc
.LFE3977:
	.size	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_, .-_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_
	.section	.gcc_except_table
	.align 4
.LLSDA3977:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3977-.LLSDATTD3977
.LLSDATTD3977:
	.byte	0x1
	.uleb128 .LLSDACSE3977-.LLSDACSB3977
.LLSDACSB3977:
	.uleb128 .LEHB21-.LFB3977
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L148-.LFB3977
	.uleb128 0x1
	.uleb128 .LEHB22-.LFB3977
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB23-.LFB3977
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L149-.LFB3977
	.uleb128 0x0
.LLSDACSE3977:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3977:
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_,comdat
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_:
.LFB3642:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3642
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%r13
	.cfi_def_cfa_offset 24
	pushq	%r12
	.cfi_def_cfa_offset 32
	movq	%rsi, %r12
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	pushq	%rbp
	.cfi_def_cfa_offset 40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbx
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	subq	$16, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L151
	movq	8(%rsi), %rsi
	movq	(%r12), %r13
	movabsq	$-3689348814741910323, %rcx
	movq	(%rdi), %rdx
	movq	16(%rdi), %rax
	movq	%rsi, %rbp
	subq	%r13, %rbp
	subq	%rdx, %rax
	sarq	$3, %rbp
	sarq	$3, %rax
	imulq	%rcx, %rbp
	imulq	%rcx, %rax
	cmpq	%rax, %rbp
	jbe	.L152
	movq	%rbp, %rdi
	movq	%rsi, 8(%rsp)
.LEHB24:
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94
.LEHE24:
	movq	8(%rsp), %rsi
	movq	%rax, %rdx
	movq	%r13, %rdi
	movq	%rax, %r12
.LEHB25:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_
.LEHE25:
	movq	8(%rbx), %rsi
	movq	(%rbx), %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	movq	(%rbx), %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
	imulq	$40, %rbp, %rax
	movq	%r12, (%rbx)
	addq	%rax, %r12
	movq	%r12, 16(%rbx)
	jmp	.L153
.L158:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB26:
	call	_Unwind_Resume
.LEHE26:
.L157:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r12, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
.LEHB27:
	call	__cxa_rethrow
.LEHE27:
.L152:
	movq	8(%rdi), %r14
	movq	%r14, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	imulq	%rax, %rcx
	cmpq	%rbp, %rcx
	jb	.L156
	movq	%r13, %rdi
.LEHB28:
	call	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EESt6vectorIS8_SaIS8_EEEENS1_IPS8_SD_EEET0_T_SI_SH_
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIN9__gnu_cxx17__normal_iteratorIPN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEEEvT_SG_
	jmp	.L153
.L156:
	leaq	0(%r13,%rax,8), %rsi
	movq	%r13, %rdi
	call	_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	movq	8(%rbx), %rdx
	movq	8(%r12), %rsi
	movq	%rdx, %rdi
	subq	(%rbx), %rdi
	andq	$-8, %rdi
	addq	(%r12), %rdi
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_
.LEHE28:
.L153:
	imulq	$40, %rbp, %rbp
	addq	(%rbx), %rbp
	movq	%rbp, 8(%rbx)
.L151:
	addq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%rbx, %rax
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
.LFE3642:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	.section	.gcc_except_table
	.align 4
.LLSDA3642:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3642-.LLSDATTD3642
.LLSDATTD3642:
	.byte	0x1
	.uleb128 .LLSDACSE3642-.LLSDACSB3642
.LLSDACSB3642:
	.uleb128 .LEHB24-.LFB3642
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB25-.LFB3642
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L157-.LFB3642
	.uleb128 0x1
	.uleb128 .LEHB26-.LFB3642
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB27-.LFB3642
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L158-.LFB3642
	.uleb128 0x0
	.uleb128 .LEHB28-.LFB3642
	.uleb128 .LEHE28-.LEHB28
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3642:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3642:
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,comdat
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC5ERKS8_,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_:
.LFB3816:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3816
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rsi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	8(%rsi), %rbp
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	movq	%rdi, %rbx
	subq	(%rsi), %rbp
	movabsq	$-3689348814741910323, %rdi
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	sarq	$3, %rbp
	imulq	%rbp, %rdi
.LEHB29:
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94
.LEHE29:
	leaq	(%rax,%rbp,8), %rdx
	movq	%rax, (%rbx)
	movq	%rax, 8(%rbx)
	movq	(%r12), %rdi
	movq	8(%r12), %rsi
	movq	%rdx, 16(%rbx)
	movq	%rax, %rdx
.LEHB30:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKN5boost6tuples5tupleIN3fem5pointEdNS5_9null_typeES9_S9_S9_S9_S9_S9_S9_EESt6vectorISA_SaISA_EEEEPSA_EET0_T_SJ_SI_
.LEHE30:
	movq	%rax, 8(%rbx)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L165:
	.cfi_restore_state
	movq	(%rbx), %rdi
	movq	%rax, %rbp
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
	movq	%rbp, %rdi
.LEHB31:
	call	_Unwind_Resume
.LEHE31:
	.cfi_endproc
.LFE3816:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_
	.section	.gcc_except_table
.LLSDA3816:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3816-.LLSDACSB3816
.LLSDACSB3816:
	.uleb128 .LEHB29-.LFB3816
	.uleb128 .LEHE29-.LEHB29
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB30-.LFB3816
	.uleb128 .LEHE30-.LEHB30
	.uleb128 .L165-.LFB3816
	.uleb128 0x0
	.uleb128 .LEHB31-.LFB3816
	.uleb128 .LEHE31-.LEHB31
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3816:
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC5ERKS8_,comdat
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC1ERKS8_
	.set	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC1ERKS8_,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC2ERKS8_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_:
.LFB3908:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3908
	pushq	%r14
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	movq	%rcx, %r14
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	movb	$1, %r13b
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	movq	%rdx, %r12
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbx
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	jne	.L167
	leaq	8(%rdi), %rax
	cmpq	%rax, %rdx
	je	.L167
	movl	32(%rdx), %eax
	cmpl	%eax, (%rcx)
	setl	%r13b
.L167:
	movl	$64, %edi
.LEHB32:
	call	_Znwm
.LEHE32:
	cmpq	$-32, %rax
	movq	%rax, %rbp
	je	.L169
	movl	(%r14), %eax
	leaq	8(%r14), %rsi
	leaq	40(%rbp), %rdi
	movl	%eax, 32(%rbp)
.LEHB33:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC1ERKS8_
.LEHE33:
.L169:
	leaq	8(%rbx), %rcx
	movzbl	%r13b, %edi
	movq	%r12, %rdx
	movq	%rbp, %rsi
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rbx)
	movq	%rbp, %rax
	popq	%rbx
	.cfi_remember_state
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
.L175:
	.cfi_restore_state
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB34:
	call	_Unwind_Resume
.LEHE34:
.L174:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rdi
	call	_ZdlPv
.LEHB35:
	call	__cxa_rethrow
.LEHE35:
	.cfi_endproc
.LFE3908:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	.section	.gcc_except_table
	.align 4
.LLSDA3908:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3908-.LLSDATTD3908
.LLSDATTD3908:
	.byte	0x1
	.uleb128 .LLSDACSE3908-.LLSDACSB3908
.LLSDACSB3908:
	.uleb128 .LEHB32-.LFB3908
	.uleb128 .LEHE32-.LEHB32
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB33-.LFB3908
	.uleb128 .LEHE33-.LEHB33
	.uleb128 .L174-.LFB3908
	.uleb128 0x1
	.uleb128 .LEHB34-.LFB3908
	.uleb128 .LEHE34-.LEHB34
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB35-.LFB3908
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L175-.LFB3908
	.uleb128 0x0
.LLSDACSE3908:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3908:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,comdat
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_:
.LFB3909:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rsi, %rcx
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	leaq	8(%rdi), %rdx
	movb	$1, %sil
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	movq	16(%rdi), %rax
	jmp	.L177
.L180:
	movl	32(%rax), %edx
	cmpl	%edx, (%rcx)
	jge	.L178
	movq	16(%rax), %rdi
	movb	$1, %sil
	jmp	.L179
.L178:
	movq	24(%rax), %rdi
	xorl	%esi, %esi
.L179:
	movq	%rax, %rdx
	movq	%rdi, %rax
.L177:
	testq	%rax, %rax
	jne	.L180
	testb	%sil, %sil
	movq	%rdx, %rax
	je	.L181
	cmpq	24(%rbx), %rdx
	je	.L186
.L182:
	movq	%rdx, %rdi
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	(%rsp), %rcx
	movq	8(%rsp), %rdx
.L181:
	movl	(%rcx), %esi
	cmpl	%esi, 32(%rax)
	jge	.L184
.L186:
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movb	$1, 40(%rsp)
	movq	%rax, 32(%rsp)
	jmp	.L183
.L184:
	movq	%rax, 32(%rsp)
	movb	$0, 40(%rsp)
.L183:
	movq	32(%rsp), %rax
	movl	40(%rsp), %edx
	addq	$48, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3909:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_:
.LFB3821:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	leaq	8(%rdi), %rax
	movq	%rdx, %rcx
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rsi, %rbp
	.cfi_offset 6, -24
	.cfi_offset 12, -16
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	.cfi_offset 3, -32
	subq	$80, %rsp
	.cfi_def_cfa_offset 112
	cmpq	%rax, %rsi
	jne	.L188
	cmpq	$0, 40(%rdi)
	je	.L196
	movq	32(%rdi), %rdx
	movl	(%rcx), %eax
	cmpl	%eax, 32(%rdx)
	jge	.L196
	jmp	.L200
.L188:
	movl	(%rdx), %r12d
	movl	32(%rsi), %eax
	cmpl	%eax, %r12d
	jge	.L191
	cmpq	24(%rdi), %rsi
	je	.L194
.L192:
	movq	%rsi, %rdi
	movq	%rdx, 8(%rsp)
	call	_ZSt18_Rb_tree_decrementPKSt18_Rb_tree_node_base
	cmpl	%r12d, 32(%rax)
	movq	8(%rsp), %rcx
	jge	.L196
	cmpq	$0, 24(%rax)
	jne	.L194
	movq	%rax, %rdx
.L200:
	xorl	%esi, %esi
	jmp	.L199
.L194:
	movq	%rbp, %rdx
	movq	%rbp, %rsi
	jmp	.L199
.L191:
	cmpl	%r12d, %eax
	jge	.L190
	cmpq	32(%rdi), %rsi
	je	.L201
.L195:
	movq	%rsi, %rdi
	movq	%rdx, 8(%rsp)
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	cmpl	32(%rax), %r12d
	movq	8(%rsp), %rcx
	jge	.L196
	cmpq	$0, 24(%rbp)
	jne	.L197
.L201:
	movq	%rbp, %rdx
	jmp	.L200
.L197:
	movq	%rax, %rdx
	movq	%rax, %rsi
.L199:
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	jmp	.L198
.L196:
	movq	%rcx, %rsi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE16_M_insert_uniqueERKSC_
	movl	%edx, 24(%rsp)
.L198:
	movq	%rax, %rbp
.L190:
	addq	$80, %rsp
	.cfi_def_cfa_offset 32
	movq	%rbp, %rax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3821:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
	.section	.text._ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_,"axG",@progbits,_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_,comdat
	.align 2
	.weak	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_
	.type	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_, @function
_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_:
.LFB3727:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3727:
	.size	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_, .-_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_
	.section	.text._ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_,"axG",@progbits,_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_,comdat
	.align 2
	.weak	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	.type	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_, @function
_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_:
.LFB3638:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3638
	pushq	%r13
	.cfi_def_cfa_offset 16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rsi, %r12
	.cfi_offset 12, -24
	.cfi_offset 13, -16
	pushq	%rbp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	subq	$72, %rsp
	.cfi_def_cfa_offset 112
	.cfi_offset 3, -40
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE11lower_boundERS1_
	movq	%rax, %rbx
	movq	%rax, %r13
	leaq	8(%rbp), %rax
	cmpq	%rax, %rbx
	je	.L204
	movl	32(%rbx), %eax
	cmpl	%eax, (%r12)
	jge	.L205
.L204:
	movl	(%r12), %eax
	leaq	8(%rsp), %rdi
	leaq	32(%rsp), %rsi
	movq	$0, 32(%rsp)
	movq	$0, 40(%rsp)
	movq	$0, 48(%rsp)
	movl	%eax, (%rsp)
.LEHB36:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEC1ERKS8_
.LEHE36:
	movq	%rsp, %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB37:
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEE6insertESt17_Rb_tree_iteratorISE_ERKSE_
.LEHE37:
	leaq	8(%rsp), %rdi
	movq	%rax, %r13
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	32(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
.L205:
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	leaq	40(%r13), %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L211:
	.cfi_restore_state
	leaq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L209
.L210:
	movq	%rax, %rbx
.L209:
	leaq	32(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	movq	%rbx, %rdi
.LEHB38:
	call	_Unwind_Resume
.LEHE38:
	.cfi_endproc
.LFE3638:
	.size	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_, .-_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	.section	.gcc_except_table
.LLSDA3638:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3638-.LLSDACSB3638
.LLSDACSB3638:
	.uleb128 .LEHB36-.LFB3638
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L210-.LFB3638
	.uleb128 0x0
	.uleb128 .LEHB37-.LFB3638
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L211-.LFB3638
	.uleb128 0x0
	.uleb128 .LEHB38-.LFB3638
	.uleb128 .LEHE38-.LEHB38
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3638:
	.section	.text._ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_,"axG",@progbits,_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_,comdat
	.section	.text._ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_,"axG",@progbits,_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_,comdat
	.weak	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_
	.type	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_, @function
_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_:
.LFB3992:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rsi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rdx, %rbp
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	subq	%rdi, %rbx
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	sarq	$5, %rbx
	jmp	.L213
.L214:
	subq	$32, %r12
	subq	$32, %rbp
	movq	%rsp, %rdi
	movq	%r12, %rdx
	movq	%rbp, %rsi
	decq	%rbx
	call	_ZN3fem5pointaSERKS0_
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
.L213:
	testq	%rbx, %rbx
	jg	.L214
	addq	$32, %rsp
	.cfi_def_cfa_offset 32
	movq	%rbp, %rax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3992:
	.size	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_, .-_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_
	.section	.text._ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_,"axG",@progbits,_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_,comdat
	.weak	_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_
	.type	_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_, @function
_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_:
.LFB3993:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L215
	jmp	_ZN3fem5pointC1ERKS0_
.L215:
	ret
	.cfi_endproc
.LFE3993:
	.size	_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_, .-_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_
	.section	.text._ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_,"axG",@progbits,_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_,comdat
	.weak	_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_
	.type	_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_, @function
_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_:
.LFB3939:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3939
	pushq	%r13
	.cfi_def_cfa_offset 16
	movq	%rdx, %r13
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rdi, %r12
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rsi, %rbx
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	jmp	.L218
.L219:
	movq	%r13, %rsi
	movq	%rbp, %rdi
.LEHB39:
	call	_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_
.LEHE39:
	decq	%rbx
	addq	$32, %rbp
.L218:
	testq	%rbx, %rbx
	jne	.L219
	jmp	.L225
.L223:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB40:
	call	_Unwind_Resume
.LEHE40:
.L222:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rsi
	movq	%r12, %rdi
.LEHB41:
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	call	__cxa_rethrow
.LEHE41:
.L225:
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3939:
	.size	_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_, .-_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_
	.section	.gcc_except_table
	.align 4
.LLSDA3939:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3939-.LLSDATTD3939
.LLSDATTD3939:
	.byte	0x1
	.uleb128 .LLSDACSE3939-.LLSDACSB3939
.LLSDACSB3939:
	.uleb128 .LEHB39-.LFB3939
	.uleb128 .LEHE39-.LEHB39
	.uleb128 .L222-.LFB3939
	.uleb128 0x1
	.uleb128 .LEHB40-.LFB3939
	.uleb128 .LEHE40-.LEHB40
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB41-.LFB3939
	.uleb128 .LEHE41-.LEHB41
	.uleb128 .L223-.LFB3939
	.uleb128 0x0
.LLSDACSE3939:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3939:
	.section	.text._ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_,"axG",@progbits,_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_,comdat
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_,comdat
	.weak	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
	.type	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_, @function
_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_:
.LFB3991:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3991
	pushq	%r13
	.cfi_def_cfa_offset 16
	movq	%rsi, %r13
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rdx, %r12
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rdx, %rbx
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	jmp	.L227
.L228:
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB42:
	call	_ZSt10_ConstructIN3fem5pointES1_EvPT_RKT0_
.LEHE42:
	addq	$32, %rbp
	addq	$32, %rbx
.L227:
	cmpq	%r13, %rbp
	jne	.L228
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L232:
	.cfi_restore_state
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB43:
	call	_Unwind_Resume
.LEHE43:
.L231:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbx, %rsi
	movq	%r12, %rdi
.LEHB44:
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	call	__cxa_rethrow
.LEHE44:
	.cfi_endproc
.LFE3991:
	.size	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_, .-_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
	.section	.gcc_except_table
	.align 4
.LLSDA3991:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3991-.LLSDATTD3991
.LLSDATTD3991:
	.byte	0x1
	.uleb128 .LLSDACSE3991-.LLSDACSB3991
.LLSDACSB3991:
	.uleb128 .LEHB42-.LFB3991
	.uleb128 .LEHE42-.LEHB42
	.uleb128 .L231-.LFB3991
	.uleb128 0x1
	.uleb128 .LEHB43-.LFB3991
	.uleb128 .LEHE43-.LEHB43
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB44-.LFB3991
	.uleb128 .LEHE44-.LEHB44
	.uleb128 .L232-.LFB3991
	.uleb128 0x0
.LLSDACSE3991:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3991:
	.section	.text._ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_,comdat
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC10:
	.string	"vector::_M_fill_insert"
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,comdat
	.align 2
	.weak	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
	.type	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_, @function
_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_:
.LFB3676:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3676
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	movq	%rcx, %r14
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rsi, %r13
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	movq	%rdx, %r12
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rdi, %rbx
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	testq	%rdx, %rdx
	je	.L233
	movq	16(%rdi), %rax
	subq	8(%rdi), %rax
	sarq	$5, %rax
	cmpq	%rdx, %rax
	jb	.L235
	leaq	16(%rsp), %rdi
	movq	%rcx, %rsi
.LEHB45:
	call	_ZN3fem5pointC1ERKS0_
.LEHE45:
	movq	8(%rbx), %rbp
	movq	%rbp, %r14
	subq	%r13, %r14
	sarq	$5, %r14
	cmpq	%r12, %r14
	jbe	.L236
	salq	$5, %r12
	movq	%rbp, %r14
	movq	%rbp, %rdx
	subq	%r12, %r14
	movq	%rbp, %rsi
	movq	%r14, %rdi
.LEHB46:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
	addq	%r12, 8(%rbx)
	movq	%rbp, %rdx
	movq	%r14, %rsi
	movq	%r13, %rdi
	call	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN3fem5pointES5_EET0_T_S7_S6_
	leaq	0(%r13,%r12), %rsi
	leaq	16(%rsp), %rdx
	jmp	.L256
.L236:
	subq	%r14, %r12
	leaq	16(%rsp), %rdx
	movq	%rbp, %rdi
	movq	%r12, %rsi
	call	_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_
	movq	%r12, %rdx
	movq	%rbp, %rsi
	movq	%r13, %rdi
	salq	$5, %rdx
	addq	8(%rbx), %rdx
	movq	%rdx, 8(%rbx)
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
	salq	$5, %r14
	addq	%r14, 8(%rbx)
	leaq	16(%rsp), %rdx
	movq	%rbp, %rsi
.L256:
	movq	%r13, %rdi
	call	_ZSt8__fill_aIPN3fem5pointES1_EN9__gnu_cxx11__enable_ifIXntsrSt11__is_scalarIT0_E7__valueEvE6__typeET_SA_RKS6_
.LEHE46:
	leaq	16(%rsp), %rdi
.LEHB47:
	call	_ZN3fem5pointD1Ev
	jmp	.L233
.L235:
	movl	$.LC10, %edx
	movq	%r12, %rsi
	call	_ZNKSt6vectorIN3fem5pointESaIS1_EE12_M_check_lenEmPKc
	movq	%rax, %r15
	movq	(%rbx), %rax
	testq	%r15, %r15
	movq	%rax, (%rsp)
	je	.L248
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %r15
	jbe	.L239
	call	_ZSt17__throw_bad_allocv
.L239:
	movq	%r15, %rdi
	salq	$5, %rdi
	call	_Znwm
.LEHE47:
	movq	%rax, %rbp
	jmp	.L238
.L248:
	xorl	%ebp, %ebp
.L238:
	movq	%r13, %rax
	subq	(%rsp), %rax
	movq	%r14, %rdx
	movq	%r12, %rsi
	sarq	$5, %rax
	movq	%rax, (%rsp)
	salq	$5, %rax
	leaq	0(%rbp,%rax), %rax
	movq	%rax, %rdi
	movq	%rax, 8(%rsp)
.LEHB48:
	call	_ZNSt22__uninitialized_fill_nILb0EE20uninitialized_fill_nIPN3fem5pointEmS3_EEvT_T0_RKT1_
.LEHE48:
	movq	(%rbx), %rdi
	movq	%rbp, %rdx
	movq	%r13, %rsi
.LEHB49:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
.LEHE49:
	movq	%r12, %rdx
	movq	8(%rbx), %rsi
	movq	%r13, %rdi
	salq	$5, %rdx
	leaq	(%rax,%rdx), %r14
	movq	%r14, %rdx
.LEHB50:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN3fem5pointES4_EET0_T_S6_S5_
.LEHE50:
	jmp	.L260
.L253:
	xorl	%r14d, %r14d
	jmp	.L242
.L260:
	movq	8(%rbx), %rsi
	movq	(%rbx), %rdi
	movq	%rax, %r12
	salq	$5, %r15
.LEHB51:
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
.LEHE51:
	movq	(%rbx), %rdi
	call	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34
	movq	%rbp, (%rbx)
	addq	%r15, %rbp
	movq	%r12, 8(%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L233
.L249:
	leaq	16(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L259
.L251:
	movq	%rax, %rbx
	call	__cxa_end_catch
.L259:
	movq	%rbx, %rdi
.LEHB52:
	call	_Unwind_Resume
.LEHE52:
.L252:
	movq	%rbp, %r14
	jmp	.L242
.L250:
.L242:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	testq	%r14, %r14
	jne	.L246
	addq	(%rsp), %r12
	movq	8(%rsp), %rdi
	salq	$5, %r12
	leaq	0(%rbp,%r12), %rsi
	jmp	.L258
.L246:
	movq	%r14, %rsi
	movq	%rbp, %rdi
.L258:
.LEHB53:
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	movq	%rbp, %rdi
	call	_ZNSt12_Vector_baseIN3fem5pointESaIS1_EE13_M_deallocateEPS1_m.clone.34
	call	__cxa_rethrow
.LEHE53:
.L233:
	addq	$56, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3676:
	.size	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_, .-_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
	.section	.gcc_except_table
	.align 4
.LLSDA3676:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3676-.LLSDATTD3676
.LLSDATTD3676:
	.byte	0x1
	.uleb128 .LLSDACSE3676-.LLSDACSB3676
.LLSDACSB3676:
	.uleb128 .LEHB45-.LFB3676
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB46-.LFB3676
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L249-.LFB3676
	.uleb128 0x0
	.uleb128 .LEHB47-.LFB3676
	.uleb128 .LEHE47-.LEHB47
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB48-.LFB3676
	.uleb128 .LEHE48-.LEHB48
	.uleb128 .L252-.LFB3676
	.uleb128 0x1
	.uleb128 .LEHB49-.LFB3676
	.uleb128 .LEHE49-.LEHB49
	.uleb128 .L253-.LFB3676
	.uleb128 0x1
	.uleb128 .LEHB50-.LFB3676
	.uleb128 .LEHE50-.LEHB50
	.uleb128 .L250-.LFB3676
	.uleb128 0x1
	.uleb128 .LEHB51-.LFB3676
	.uleb128 .LEHE51-.LEHB51
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB52-.LFB3676
	.uleb128 .LEHE52-.LEHB52
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB53-.LFB3676
	.uleb128 .LEHE53-.LEHB53
	.uleb128 .L251-.LFB3676
	.uleb128 0x0
.LLSDACSE3676:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3676:
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,comdat
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_,comdat
	.align 2
	.weak	_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_
	.type	_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_, @function
_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_:
.LFB3558:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	8(%rdi), %rsi
	movq	(%rdi), %r8
	movq	%rsi, %rdi
	subq	%r8, %rdi
	sarq	$5, %rdi
	cmpq	%rdi, %rax
	jae	.L262
	movq	%rax, %rbp
	salq	$5, %rbp
	leaq	(%r8,%rbp), %rbp
	movq	%rbp, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN3fem5pointEEEvT_S5_
	movq	%rbp, 8(%rbx)
	jmp	.L261
.L262:
	subq	%rdi, %rax
	movq	%rdx, %rcx
	movq	%rbx, %rdi
	movq	%rax, %rdx
	call	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
.L261:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3558:
	.size	_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_, .-_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_
	.section	.text._ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_
	.type	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_, @function
_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_:
.LFB3995:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	subq	%rdi, %rsi
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdx, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	sarq	$3, %rbp
	je	.L265
	leaq	0(,%rbp,8), %rdx
	movq	%rbx, %rax
	movq	%rdi, %rsi
	subq	%rdx, %rax
	movq	%rax, %rdi
	call	memmove
.L265:
	salq	$3, %rbp
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	subq	%rbp, %rax
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3995:
	.size	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_, .-_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_
	.section	.text._ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_,"axG",@progbits,_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_,comdat
	.weak	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	.type	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_, @function
_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_:
.LFB3997:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movabsq	$-3689348814741910323, %rax
	movq	%rdx, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	movq	%rsi, %rbp
	.cfi_offset 6, -24
	subq	%rdi, %rbp
	sarq	$3, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	imulq	%rax, %rbp
	jmp	.L267
.L268:
	subq	$40, %rbx
	subq	$40, %r12
	decq	%rbp
	movq	%rbx, %rsi
	movq	%r12, %rdi
	call	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
.L267:
	testq	%rbp, %rbp
	jg	.L268
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%r12, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3997:
	.size	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_, .-_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	.section	.rodata.str1.1
.LC11:
	.string	"vector::_M_insert_aux"
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_:
.LFB3712:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3712
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rsi, %r13
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r12
	.cfi_def_cfa_offset 40
	movq	%rdx, %r12
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rdi, %rbx
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	8(%rdi), %rdi
	cmpq	16(%rbx), %rdi
	je	.L270
	leaq	-40(%rdi), %rsi
.LEHB54:
	call	_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8
	addq	$40, 8(%rbx)
	movq	%r12, %rsi
	movq	%rsp, %rdi
	call	_ZN3fem5pointC1ERKS0_
.LEHE54:
	movq	8(%rbx), %rsi
	movq	32(%r12), %rax
	movq	%r13, %rdi
	leaq	-40(%rsi), %rdx
	subq	$80, %rsi
	movq	%rax, 32(%rsp)
.LEHB55:
	call	_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIPN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESA_EET0_T_SC_SB_
	movq	%rsp, %rsi
	movq	%r13, %rdi
	call	_ZN5boost6tuples4consIN3fem5pointENS1_IdNS0_9null_typeEEEEaSERKS6_
.LEHE55:
	movq	%rsp, %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L269
.L270:
	movl	$1, %esi
	movl	$.LC11, %edx
	movq	%rbx, %rdi
.LEHB56:
	call	_ZNKSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE12_M_check_lenEmPKc
	movq	%r13, %r15
	subq	(%rbx), %r15
	movq	%rax, %rdi
	movq	%rax, %r14
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE11_M_allocateEm.clone.94
.LEHE56:
	movq	%r12, %rsi
	movq	%rax, %rbp
	sarq	$3, %r15
	leaq	(%rax,%r15,8), %r15
	movq	%r15, %rdi
.LEHB57:
	call	_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8
.LEHE57:
	movq	(%rbx), %rdi
	movq	%rbp, %rdx
	movq	%r13, %rsi
.LEHB58:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_
.LEHE58:
	leaq	40(%rax), %r12
	movq	8(%rbx), %rsi
	movq	%r13, %rdi
	movq	%r12, %rdx
.LEHB59:
	call	_ZNSt20__uninitialized_copyILb0EE18uninitialized_copyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EES9_EET0_T_SB_SA_
.LEHE59:
	jmp	.L287
.L284:
	xorl	%r12d, %r12d
	jmp	.L274
.L287:
	movq	8(%rbx), %rsi
	movq	(%rbx), %rdi
	movq	%rax, %r12
	imulq	$40, %r14, %r14
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	movq	(%rbx), %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
	movq	%rbp, (%rbx)
	addq	%r14, %rbp
	movq	%r12, 8(%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L269
.L280:
	movq	%rsp, %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L286
.L282:
	movq	%rax, %rbx
	call	__cxa_end_catch
.L286:
	movq	%rbx, %rdi
.LEHB60:
	call	_Unwind_Resume
.LEHE60:
.L283:
	movq	%rbp, %r12
	jmp	.L274
.L281:
.L274:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	testq	%r12, %r12
	jne	.L278
	movq	%r15, %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L279
.L278:
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.L279:
	movq	%rbp, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.29
.LEHB61:
	call	__cxa_rethrow
.LEHE61:
.L269:
	addq	$56, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3712:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
	.section	.gcc_except_table
	.align 4
.LLSDA3712:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3712-.LLSDATTD3712
.LLSDATTD3712:
	.byte	0x1
	.uleb128 .LLSDACSE3712-.LLSDACSB3712
.LLSDACSB3712:
	.uleb128 .LEHB54-.LFB3712
	.uleb128 .LEHE54-.LEHB54
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB55-.LFB3712
	.uleb128 .LEHE55-.LEHB55
	.uleb128 .L280-.LFB3712
	.uleb128 0x0
	.uleb128 .LEHB56-.LFB3712
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB57-.LFB3712
	.uleb128 .LEHE57-.LEHB57
	.uleb128 .L283-.LFB3712
	.uleb128 0x1
	.uleb128 .LEHB58-.LFB3712
	.uleb128 .LEHE58-.LEHB58
	.uleb128 .L284-.LFB3712
	.uleb128 0x1
	.uleb128 .LEHB59-.LFB3712
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L281-.LFB3712
	.uleb128 0x1
	.uleb128 .LEHB60-.LFB3712
	.uleb128 .LEHE60-.LEHB60
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB61-.LFB3712
	.uleb128 .LEHE61-.LEHB61
	.uleb128 .L282-.LFB3712
	.uleb128 0x0
.LLSDACSE3712:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0

.LLSDATT3712:
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,comdat
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_,comdat
	.align 2
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_:
.LFB3634:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	movq	8(%rdi), %rdi
	cmpq	16(%rbx), %rdi
	je	.L289
	call	_ZN9__gnu_cxx13new_allocatorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EEE9constructEPS7_RKS7_.clone.8
	addq	$40, 8(%rbx)
	jmp	.L288
.L289:
	movq	%rsi, %rdx
	movq	%rdi, %rsi
	movq	%rbx, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.L288:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3634:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
	.section	.text._ZN3fem11PrismFamilyIdE22generateQuadratureDataEv,"axG",@progbits,_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv,comdat
	.align 2
	.weak	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv
	.type	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv, @function
_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv:
.LFB3580:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3580
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rdi, %r13
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$3160, %rsp
	.cfi_def_cfa_offset 3216
	leaq	2640(%rsp), %rdi
	movq	$0, 2640(%rsp)
	movq	$0, 2648(%rsp)
	movq	$0, 2656(%rsp)
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	movabsq	$4599676419421066581, %rdx
	leaq	3104(%rsp), %rcx
	leaq	3120(%rsp), %rsi
	movq	%rdx, 3120(%rsp)
	leaq	2608(%rsp), %rdi
	leaq	3112(%rsp), %rdx
	movabsq	$4599676419421066581, %rax
	movq	$0, 3104(%rsp)
	movq	%rax, 3112(%rsp)
.LEHB62:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE62:
	leaq	2608(%rsp), %rsi
	leaq	1504(%rsp), %rdi
.LEHB63:
	call	_ZN3fem5pointC1ERKS0_
.LEHE63:
	leaq	1504(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4607182418800017408, %rax
	movq	%rax, 1536(%rsp)
.LEHB64:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE64:
	leaq	1504(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2608(%rsp), %rdi
.LEHB65:
	call	_ZN3fem5pointD1Ev
	leaq	16(%r13), %r14
	leaq	3148(%rsp), %rsi
	movl	$1, 3148(%rsp)
	movq	%r14, %rdi
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	leaq	2640(%rsp), %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	leaq	2640(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	movabsq	$-4619996508395130083, %rax
	leaq	3080(%rsp), %rcx
	leaq	3088(%rsp), %rdx
	movq	%rax, 3080(%rsp)
	leaq	3096(%rsp), %rsi
	movabsq	$4595172819793696085, %rax
	leaq	2576(%rsp), %rdi
	movq	%rax, 3088(%rsp)
	movabsq	$4604180019048437077, %rax
	movq	%rax, 3096(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE65:
	leaq	2576(%rsp), %rsi
	leaq	1456(%rsp), %rdi
.LEHB66:
	call	_ZN3fem5pointC1ERKS0_
.LEHE66:
	leaq	1456(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %rax
	movq	%rax, 1488(%rsp)
.LEHB67:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE67:
	leaq	1456(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2576(%rsp), %rdi
.LEHB68:
	call	_ZN3fem5pointD1Ev
	leaq	3056(%rsp), %rcx
	leaq	3064(%rsp), %rdx
	leaq	3072(%rsp), %rsi
	leaq	2544(%rsp), %rdi
	movabsq	$-4619996508395130083, %rbp
	movabsq	$4604180019048437077, %r12
	movabsq	$4595172819793696085, %r15
	movq	%rbp, 3056(%rsp)
	movq	%r12, 3064(%rsp)
	movq	%r15, 3072(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE68:
	leaq	2544(%rsp), %rsi
	leaq	1408(%rsp), %rdi
.LEHB69:
	call	_ZN3fem5pointC1ERKS0_
.LEHE69:
	leaq	1408(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %rbx
	movq	%rbx, 1440(%rsp)
.LEHB70:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE70:
	leaq	1408(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2544(%rsp), %rdi
.LEHB71:
	call	_ZN3fem5pointD1Ev
	leaq	3032(%rsp), %rcx
	leaq	3040(%rsp), %rdx
	leaq	3048(%rsp), %rsi
	leaq	2512(%rsp), %rdi
	movabsq	$-4619996508395130083, %r9
	movabsq	$4595172819793696085, %r10
	movabsq	$4595172819793696085, %r11
	movq	%r9, 3032(%rsp)
	movq	%r10, 3040(%rsp)
	movq	%r11, 3048(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE71:
	leaq	2512(%rsp), %rsi
	leaq	1360(%rsp), %rdi
.LEHB72:
	call	_ZN3fem5pointC1ERKS0_
.LEHE72:
	leaq	1360(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %r8
	movq	%r8, 1392(%rsp)
.LEHB73:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE73:
	leaq	1360(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2512(%rsp), %rdi
.LEHB74:
	call	_ZN3fem5pointD1Ev
	movabsq	$4603375528459645725, %rcx
	movabsq	$4595172819793696085, %rsi
	movabsq	$4604180019048437077, %rdi
	movq	%rcx, 3008(%rsp)
	movq	%rsi, 3016(%rsp)
	leaq	3008(%rsp), %rcx
	movq	%rdi, 3024(%rsp)
	leaq	3016(%rsp), %rdx
	leaq	3024(%rsp), %rsi
	leaq	2480(%rsp), %rdi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE74:
	leaq	2480(%rsp), %rsi
	leaq	1312(%rsp), %rdi
.LEHB75:
	call	_ZN3fem5pointC1ERKS0_
.LEHE75:
	leaq	1312(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %rdx
	movq	%rdx, 1344(%rsp)
.LEHB76:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE76:
	leaq	1312(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2480(%rsp), %rdi
.LEHB77:
	call	_ZN3fem5pointD1Ev
	movabsq	$4603375528459645725, %rax
	leaq	2984(%rsp), %rcx
	leaq	2992(%rsp), %rdx
	movq	%rax, 2984(%rsp)
	leaq	3000(%rsp), %rsi
	movabsq	$4604180019048437077, %rax
	leaq	2448(%rsp), %rdi
	movq	%rax, 2992(%rsp)
	movabsq	$4595172819793696085, %rax
	movq	%rax, 3000(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE77:
	leaq	2448(%rsp), %rsi
	leaq	1264(%rsp), %rdi
.LEHB78:
	call	_ZN3fem5pointC1ERKS0_
.LEHE78:
	leaq	1264(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %rax
	movq	%rax, 1296(%rsp)
.LEHB79:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE79:
	leaq	1264(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2448(%rsp), %rdi
.LEHB80:
	call	_ZN3fem5pointD1Ev
	movabsq	$4595172819793696085, %rax
	leaq	2960(%rsp), %rcx
	leaq	2968(%rsp), %rdx
	leaq	2976(%rsp), %rsi
	leaq	2416(%rsp), %rdi
	movabsq	$4603375528459645725, %r15
	movq	%rax, 2968(%rsp)
	movabsq	$4595172819793696085, %rax
	movq	%r15, 2960(%rsp)
	movq	%rax, 2976(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE80:
	leaq	2416(%rsp), %rsi
	leaq	1216(%rsp), %rdi
.LEHB81:
	call	_ZN3fem5pointC1ERKS0_
.LEHE81:
	leaq	1216(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4595172819793696085, %r12
	movq	%r12, 1248(%rsp)
.LEHB82:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE82:
	leaq	1216(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2416(%rsp), %rdi
.LEHB83:
	call	_ZN3fem5pointD1Ev
	leaq	3144(%rsp), %rsi
	movq	%r14, %rdi
	movl	$2, 3144(%rsp)
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	leaq	2640(%rsp), %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	leaq	1968(%rsp), %r15
	leaq	1936(%rsp), %rdx
	movl	$3, %ecx
	movq	%r13, %rdi
	movabsq	$4591263182279782599, %rbp
	movabsq	$4601705113747968217, %rbx
	movq	%r15, %rsi
	xorl	%r12d, %r12d
	call	_ZN3fem11BaseElementIdE6gaulegEPdS2_i
	leaq	2640(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	movq	%rbp, 2920(%rsp)
	leaq	1936(%rsp), %rbp
	movq	%rbx, 2912(%rsp)
.L292:
	movsd	0(%rbp), %xmm0
	movslq	%r12d, %rax
	movsd	.LC1(%rip), %xmm1
	leaq	(%r15,%rax,8), %rbx
	movsd	%xmm0, 8(%rsp)
	leaq	2912(%rsp), %rdx
	leaq	2952(%rsp), %rsi
	movsd	2912(%rsp), %xmm0
	leaq	2384(%rsp), %rdi
	movq	%rbx, %rcx
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2952(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE83:
	leaq	2384(%rsp), %rsi
	leaq	1168(%rsp), %rdi
.LEHB84:
	call	_ZN3fem5pointC1ERKS0_
.LEHE84:
	movsd	8(%rsp), %xmm0
	leaq	1168(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC19(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 1200(%rsp)
.LEHB85:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE85:
	leaq	1168(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2384(%rsp), %rdi
.LEHB86:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2944(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2912(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2352(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2912(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2944(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE86:
	leaq	2352(%rsp), %rsi
	leaq	1120(%rsp), %rdi
.LEHB87:
	call	_ZN3fem5pointC1ERKS0_
.LEHE87:
	movsd	8(%rsp), %xmm0
	leaq	1120(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC19(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 1152(%rsp)
.LEHB88:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE88:
	leaq	1120(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2352(%rsp), %rdi
.LEHB89:
	call	_ZN3fem5pointD1Ev
	leaq	2912(%rsp), %rdx
	movsd	0(%rbp), %xmm0
	leaq	2320(%rsp), %rdi
	movq	%rbx, %rcx
	movq	%rdx, %rsi
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE89:
	leaq	2320(%rsp), %rsi
	leaq	1072(%rsp), %rdi
.LEHB90:
	call	_ZN3fem5pointC1ERKS0_
.LEHE90:
	movsd	8(%rsp), %xmm0
	leaq	1072(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC19(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 1104(%rsp)
.LEHB91:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE91:
	leaq	1072(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2320(%rsp), %rdi
.LEHB92:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2920(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2936(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2288(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2920(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2936(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE92:
	leaq	2288(%rsp), %rsi
	leaq	1024(%rsp), %rdi
.LEHB93:
	call	_ZN3fem5pointC1ERKS0_
.LEHE93:
	movsd	8(%rsp), %xmm0
	leaq	1024(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC21(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 1056(%rsp)
.LEHB94:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE94:
	leaq	1024(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2288(%rsp), %rdi
.LEHB95:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2928(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2920(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2256(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2920(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2928(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE95:
	leaq	2256(%rsp), %rsi
	leaq	976(%rsp), %rdi
.LEHB96:
	call	_ZN3fem5pointC1ERKS0_
.LEHE96:
	movsd	8(%rsp), %xmm0
	leaq	976(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC21(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 1008(%rsp)
.LEHB97:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE97:
	leaq	976(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2256(%rsp), %rdi
.LEHB98:
	call	_ZN3fem5pointD1Ev
	leaq	2920(%rsp), %rdx
	movsd	0(%rbp), %xmm0
	leaq	2224(%rsp), %rdi
	movq	%rbx, %rcx
	movq	%rdx, %rsi
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE98:
	leaq	2224(%rsp), %rsi
	leaq	928(%rsp), %rdi
.LEHB99:
	call	_ZN3fem5pointC1ERKS0_
.LEHE99:
	movsd	8(%rsp), %xmm0
	leaq	928(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC21(%rip), %xmm0
	divsd	.LC20(%rip), %xmm0
	movsd	%xmm0, 960(%rsp)
.LEHB100:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE100:
	leaq	928(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2224(%rsp), %rdi
.LEHB101:
	call	_ZN3fem5pointD1Ev
	incl	%r12d
	addq	$8, %rbp
	cmpl	$3, %r12d
	jne	.L292
	leaq	3140(%rsp), %rsi
	movq	%r14, %rdi
	movl	$3, 3140(%rsp)
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	leaq	2640(%rsp), %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	leaq	1936(%rsp), %r15
	leaq	1968(%rsp), %rdx
	movl	$3, %ecx
	movq	%r13, %rdi
	leaq	1968(%rsp), %rbp
	xorb	%r12b, %r12b
	movq	%r15, %rsi
	call	_ZN3fem11BaseElementIdE6gaulegEPdS2_i
	leaq	2640(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
	movabsq	$4591962882689398159, %r10
	movabsq	$4602140946416765888, %r11
	movq	%r10, 2920(%rsp)
	movq	%r11, 2912(%rsp)
.L293:
	movsd	0(%rbp), %xmm0
	movslq	%r12d, %rax
	movsd	.LC1(%rip), %xmm1
	leaq	(%r15,%rax,8), %rbx
	movsd	%xmm0, 8(%rsp)
	leaq	2920(%rsp), %rdx
	leaq	2904(%rsp), %rsi
	movsd	2920(%rsp), %xmm0
	leaq	2192(%rsp), %rdi
	movq	%rbx, %rcx
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2904(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE101:
	leaq	2192(%rsp), %rsi
	leaq	880(%rsp), %rdi
.LEHB102:
	call	_ZN3fem5pointC1ERKS0_
.LEHE102:
	movsd	8(%rsp), %xmm0
	leaq	880(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC24(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 912(%rsp)
.LEHB103:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE103:
	leaq	880(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2192(%rsp), %rdi
.LEHB104:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2896(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2920(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2160(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2920(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2896(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE104:
	leaq	2160(%rsp), %rsi
	leaq	832(%rsp), %rdi
.LEHB105:
	call	_ZN3fem5pointC1ERKS0_
.LEHE105:
	movsd	8(%rsp), %xmm0
	leaq	832(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC24(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 864(%rsp)
.LEHB106:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE106:
	leaq	832(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2160(%rsp), %rdi
.LEHB107:
	call	_ZN3fem5pointD1Ev
	leaq	2920(%rsp), %rdx
	movsd	0(%rbp), %xmm0
	leaq	2128(%rsp), %rdi
	movq	%rbx, %rcx
	movq	%rdx, %rsi
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE107:
	leaq	2128(%rsp), %rsi
	leaq	784(%rsp), %rdi
.LEHB108:
	call	_ZN3fem5pointC1ERKS0_
.LEHE108:
	movsd	8(%rsp), %xmm0
	leaq	784(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC24(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 816(%rsp)
.LEHB109:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE109:
	leaq	784(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2128(%rsp), %rdi
.LEHB110:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2912(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2888(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2096(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2912(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2888(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE110:
	leaq	2096(%rsp), %rsi
	leaq	736(%rsp), %rdi
.LEHB111:
	call	_ZN3fem5pointC1ERKS0_
.LEHE111:
	movsd	8(%rsp), %xmm0
	leaq	736(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC26(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 768(%rsp)
.LEHB112:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE112:
	leaq	736(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2096(%rsp), %rdi
.LEHB113:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2880(%rsp), %rdx
	movsd	.LC1(%rip), %xmm1
	leaq	2912(%rsp), %rsi
	movsd	%xmm0, 8(%rsp)
	leaq	2064(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	2912(%rsp), %xmm0
	addsd	%xmm0, %xmm0
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 2880(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE113:
	leaq	2064(%rsp), %rsi
	leaq	688(%rsp), %rdi
.LEHB114:
	call	_ZN3fem5pointC1ERKS0_
.LEHE114:
	movsd	8(%rsp), %xmm0
	leaq	688(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC26(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 720(%rsp)
.LEHB115:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE115:
	leaq	688(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2064(%rsp), %rdi
.LEHB116:
	call	_ZN3fem5pointD1Ev
	leaq	2912(%rsp), %rdx
	movsd	0(%rbp), %xmm0
	leaq	2032(%rsp), %rdi
	movq	%rbx, %rcx
	movq	%rdx, %rsi
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE116:
	leaq	2032(%rsp), %rsi
	leaq	640(%rsp), %rdi
.LEHB117:
	call	_ZN3fem5pointC1ERKS0_
.LEHE117:
	movsd	8(%rsp), %xmm0
	leaq	640(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC26(%rip), %xmm0
	divsd	.LC25(%rip), %xmm0
	movsd	%xmm0, 672(%rsp)
.LEHB118:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE118:
	leaq	640(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2032(%rsp), %rdi
.LEHB119:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2864(%rsp), %rdx
	leaq	2872(%rsp), %rsi
	leaq	2000(%rsp), %rdi
	movabsq	$4599676419421066581, %r8
	movabsq	$4599676419421066581, %r9
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%r8, 2864(%rsp)
	movq	%r9, 2872(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE119:
	leaq	2000(%rsp), %rsi
	leaq	592(%rsp), %rdi
.LEHB120:
	call	_ZN3fem5pointC1ERKS0_
.LEHE120:
	movsd	8(%rsp), %xmm0
	leaq	592(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC27(%rip), %xmm0
	divsd	.LC28(%rip), %xmm0
	movsd	%xmm0, 624(%rsp)
.LEHB121:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE121:
	leaq	592(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	2000(%rsp), %rdi
.LEHB122:
	call	_ZN3fem5pointD1Ev
	incl	%r12d
	addq	$8, %rbp
	cmpl	$3, %r12d
	jne	.L293
	leaq	3136(%rsp), %rsi
	movq	%r14, %rdi
	movl	$4, 3136(%rsp)
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	leaq	2640(%rsp), %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	leaq	1968(%rsp), %rbx
	leaq	1936(%rsp), %rdx
	movq	%r13, %rdi
	movl	$4, %ecx
	leaq	1936(%rsp), %rbp
	xorb	%r12b, %r12b
	movq	%rbx, %rsi
	movq	%rbx, %r13
	call	_ZN3fem11BaseElementIdE6gaulegEPdS2_i
	leaq	2640(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE5clearEv
.L294:
	movslq	%r12d, %rax
	movabsq	$4589210463257646532, %rsi
	movabsq	$4606045908151397007, %rdi
	leaq	0(%r13,%rax,8), %rbx
	movsd	0(%rbp), %xmm0
	leaq	2848(%rsp), %rdx
	movq	%rsi, 2848(%rsp)
	movq	%rdi, 2856(%rsp)
	leaq	2856(%rsp), %rsi
	leaq	1904(%rsp), %rdi
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE122:
	leaq	1904(%rsp), %rsi
	leaq	544(%rsp), %rdi
.LEHB123:
	call	_ZN3fem5pointC1ERKS0_
.LEHE123:
	movsd	8(%rsp), %xmm0
	leaq	544(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC31(%rip), %xmm0
	movsd	%xmm0, 576(%rsp)
.LEHB124:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE124:
	leaq	544(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1904(%rsp), %rdi
.LEHB125:
	call	_ZN3fem5pointD1Ev
	movabsq	$4606045908151397007, %rdx
	movsd	0(%rbp), %xmm0
	movabsq	$4589210463257646532, %rcx
	movq	%rdx, 2832(%rsp)
	leaq	2840(%rsp), %rsi
	leaq	2832(%rsp), %rdx
	leaq	1872(%rsp), %rdi
	movq	%rcx, 2840(%rsp)
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE125:
	leaq	1872(%rsp), %rsi
	leaq	496(%rsp), %rdi
.LEHB126:
	call	_ZN3fem5pointC1ERKS0_
.LEHE126:
	movsd	8(%rsp), %xmm0
	leaq	496(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC31(%rip), %xmm0
	movsd	%xmm0, 528(%rsp)
.LEHB127:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE127:
	leaq	496(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1872(%rsp), %rdi
.LEHB128:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	movabsq	$4589210463257646532, %rax
	leaq	2816(%rsp), %rdx
	leaq	2824(%rsp), %rsi
	leaq	1840(%rsp), %rdi
	movq	%rax, 2816(%rsp)
	movq	%rbx, %rcx
	movabsq	$4589210463257646532, %rax
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2824(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE128:
	leaq	1840(%rsp), %rsi
	leaq	448(%rsp), %rdi
.LEHB129:
	call	_ZN3fem5pointC1ERKS0_
.LEHE129:
	movsd	8(%rsp), %xmm0
	leaq	448(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC31(%rip), %xmm0
	movsd	%xmm0, 480(%rsp)
.LEHB130:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE130:
	leaq	448(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1840(%rsp), %rdi
.LEHB131:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	movabsq	$4598149521831816337, %rax
	leaq	2800(%rsp), %rdx
	leaq	2808(%rsp), %rsi
	leaq	1808(%rsp), %rdi
	movq	%rax, 2800(%rsp)
	movq	%rbx, %rcx
	movabsq	$4602691668029376943, %rax
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2808(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE131:
	leaq	1808(%rsp), %rsi
	leaq	400(%rsp), %rdi
.LEHB132:
	call	_ZN3fem5pointC1ERKS0_
.LEHE132:
	movsd	8(%rsp), %xmm0
	leaq	400(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC34(%rip), %xmm0
	movsd	%xmm0, 432(%rsp)
.LEHB133:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE133:
	leaq	400(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1808(%rsp), %rdi
.LEHB134:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	movabsq	$4602691668029376943, %rax
	leaq	2784(%rsp), %rdx
	leaq	2792(%rsp), %rsi
	leaq	1776(%rsp), %rdi
	movq	%rax, 2784(%rsp)
	movq	%rbx, %rcx
	movabsq	$4598149521831816337, %rax
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2792(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE134:
	leaq	1776(%rsp), %rsi
	leaq	352(%rsp), %rdi
.LEHB135:
	call	_ZN3fem5pointC1ERKS0_
.LEHE135:
	movsd	8(%rsp), %xmm0
	leaq	352(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC34(%rip), %xmm0
	movsd	%xmm0, 384(%rsp)
.LEHB136:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE136:
	leaq	352(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1776(%rsp), %rdi
.LEHB137:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2768(%rsp), %rdx
	leaq	2776(%rsp), %rsi
	leaq	1744(%rsp), %rdi
	movabsq	$4598149521831816337, %r11
	movabsq	$4598149521831816337, %r15
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%r11, 2768(%rsp)
	movq	%r15, 2776(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE137:
	leaq	1744(%rsp), %rsi
	leaq	304(%rsp), %rdi
.LEHB138:
	call	_ZN3fem5pointC1ERKS0_
.LEHE138:
	movsd	8(%rsp), %xmm0
	leaq	304(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC34(%rip), %xmm0
	movsd	%xmm0, 336(%rsp)
.LEHB139:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE139:
	leaq	304(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1744(%rsp), %rdi
.LEHB140:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	leaq	2752(%rsp), %rdx
	leaq	2760(%rsp), %rsi
	leaq	1712(%rsp), %rdi
	movabsq	$4599262432649223017, %r9
	movabsq	$4603908324381003460, %r10
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%r9, 2752(%rsp)
	movq	%r10, 2760(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE140:
	leaq	1712(%rsp), %rsi
	leaq	256(%rsp), %rdi
.LEHB141:
	call	_ZN3fem5pointC1ERKS0_
.LEHE141:
	movsd	8(%rsp), %xmm0
	leaq	256(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 288(%rsp)
.LEHB142:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE142:
	leaq	256(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1712(%rsp), %rdi
.LEHB143:
	call	_ZN3fem5pointD1Ev
	movabsq	$4603908324381003460, %rdi
	movsd	0(%rbp), %xmm0
	leaq	2736(%rsp), %rdx
	movq	%rdi, 2736(%rsp)
	leaq	2744(%rsp), %rsi
	leaq	1680(%rsp), %rdi
	movabsq	$4599262432649223017, %r8
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%r8, 2744(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE143:
	leaq	1680(%rsp), %rsi
	leaq	208(%rsp), %rdi
.LEHB144:
	call	_ZN3fem5pointC1ERKS0_
.LEHE144:
	movsd	8(%rsp), %xmm0
	leaq	208(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 240(%rsp)
.LEHB145:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE145:
	leaq	208(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1680(%rsp), %rdi
.LEHB146:
	call	_ZN3fem5pointD1Ev
	movabsq	$4603908324381003460, %rsi
	movsd	0(%rbp), %xmm0
	movabsq	$4587819829889480825, %rcx
	movq	%rsi, 2728(%rsp)
	leaq	2720(%rsp), %rdx
	leaq	2728(%rsp), %rsi
	leaq	1648(%rsp), %rdi
	movq	%rcx, 2720(%rsp)
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE146:
	leaq	1648(%rsp), %rsi
	leaq	160(%rsp), %rdi
.LEHB147:
	call	_ZN3fem5pointC1ERKS0_
.LEHE147:
	movsd	8(%rsp), %xmm0
	leaq	160(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 192(%rsp)
.LEHB148:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE148:
	leaq	160(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1648(%rsp), %rdi
.LEHB149:
	call	_ZN3fem5pointD1Ev
	movabsq	$4587819829889480825, %rdx
	movsd	0(%rbp), %xmm0
	leaq	2712(%rsp), %rsi
	movq	%rdx, 2712(%rsp)
	leaq	1616(%rsp), %rdi
	leaq	2704(%rsp), %rdx
	movabsq	$4603908324381003460, %rax
	movq	%rbx, %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2704(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE149:
	leaq	1616(%rsp), %rsi
	leaq	112(%rsp), %rdi
.LEHB150:
	call	_ZN3fem5pointC1ERKS0_
.LEHE150:
	movsd	8(%rsp), %xmm0
	leaq	112(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 144(%rsp)
.LEHB151:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE151:
	leaq	112(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1616(%rsp), %rdi
.LEHB152:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	movabsq	$4587819829889480825, %rax
	leaq	2688(%rsp), %rdx
	leaq	2696(%rsp), %rsi
	leaq	1584(%rsp), %rdi
	movq	%rax, 2688(%rsp)
	movq	%rbx, %rcx
	movabsq	$4599262432649223017, %rax
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2696(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE152:
	leaq	1584(%rsp), %rsi
	leaq	64(%rsp), %rdi
.LEHB153:
	call	_ZN3fem5pointC1ERKS0_
.LEHE153:
	movsd	8(%rsp), %xmm0
	leaq	64(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 96(%rsp)
.LEHB154:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE154:
	leaq	64(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1584(%rsp), %rdi
.LEHB155:
	call	_ZN3fem5pointD1Ev
	movsd	0(%rbp), %xmm0
	movabsq	$4599262432649223017, %rax
	leaq	2672(%rsp), %rdx
	leaq	2680(%rsp), %rsi
	leaq	1552(%rsp), %rdi
	movq	%rax, 2672(%rsp)
	movq	%rbx, %rcx
	movabsq	$4587819829889480825, %rax
	movsd	%xmm0, 8(%rsp)
	movq	%rax, 2680(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE155:
	leaq	1552(%rsp), %rsi
	leaq	16(%rsp), %rdi
.LEHB156:
	call	_ZN3fem5pointC1ERKS0_
.LEHE156:
	movsd	8(%rsp), %xmm0
	leaq	16(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC37(%rip), %xmm0
	movsd	%xmm0, 48(%rsp)
.LEHB157:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE9push_backERKS6_
.LEHE157:
	leaq	16(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	leaq	1552(%rsp), %rdi
.LEHB158:
	call	_ZN3fem5pointD1Ev
	incl	%r12d
	addq	$8, %rbp
	cmpl	$4, %r12d
	jne	.L294
	leaq	3132(%rsp), %rsi
	movq	%r14, %rdi
	movl	$5, 3132(%rsp)
	call	_ZNSt3mapIiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS2_9null_typeES6_S6_S6_S6_S6_S6_S6_EESaIS7_EESt4lessIiESaISt4pairIKiS9_EEEixERSD_
	leaq	2640(%rsp), %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE158:
	leaq	2640(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	addq	$3160, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L362:
	.cfi_restore_state
	leaq	1504(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L296
.L361:
.L296:
	leaq	2608(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L364:
	leaq	1456(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L299
.L363:
.L299:
	leaq	2576(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L366:
	leaq	1408(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L301
.L365:
.L301:
	leaq	2544(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L368:
	leaq	1360(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L303
.L367:
.L303:
	leaq	2512(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L370:
	leaq	1312(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L305
.L369:
.L305:
	leaq	2480(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L372:
	leaq	1264(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L307
.L371:
.L307:
	leaq	2448(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L374:
	leaq	1216(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L309
.L373:
.L309:
	leaq	2416(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L376:
	leaq	1168(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L311
.L375:
.L311:
	leaq	2384(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L378:
	leaq	1120(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L313
.L377:
.L313:
	leaq	2352(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L380:
	leaq	1072(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L315
.L379:
.L315:
	leaq	2320(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L382:
	leaq	1024(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L317
.L381:
.L317:
	leaq	2288(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L384:
	leaq	976(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L319
.L383:
.L319:
	leaq	2256(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L386:
	leaq	928(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L321
.L385:
.L321:
	leaq	2224(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L388:
	leaq	880(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L323
.L387:
.L323:
	leaq	2192(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L390:
	leaq	832(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L325
.L389:
.L325:
	leaq	2160(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L392:
	leaq	784(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L327
.L391:
.L327:
	leaq	2128(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L394:
	leaq	736(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L329
.L393:
.L329:
	leaq	2096(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L396:
	leaq	688(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L331
.L395:
.L331:
	leaq	2064(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L398:
	leaq	640(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L333
.L397:
.L333:
	leaq	2032(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L400:
	leaq	592(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L335
.L399:
.L335:
	leaq	2000(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L402:
	leaq	544(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L337
.L401:
.L337:
	leaq	1904(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L404:
	leaq	496(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L339
.L403:
.L339:
	leaq	1872(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L406:
	leaq	448(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L341
.L405:
.L341:
	leaq	1840(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L408:
	leaq	400(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L343
.L407:
.L343:
	leaq	1808(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L410:
	leaq	352(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L345
.L409:
.L345:
	leaq	1776(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L412:
	leaq	304(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L347
.L411:
.L347:
	leaq	1744(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L414:
	leaq	256(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L349
.L413:
.L349:
	leaq	1712(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L416:
	leaq	208(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L351
.L415:
.L351:
	leaq	1680(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L418:
	leaq	160(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L353
.L417:
.L353:
	leaq	1648(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L420:
	leaq	112(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L355
.L419:
.L355:
	leaq	1616(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L422:
	leaq	64(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L357
.L421:
.L357:
	leaq	1584(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
.L428:
	movq	(%rsp), %rax
	jmp	.L297
.L424:
	leaq	16(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	(%rsp), %rax
	jmp	.L359
.L423:
.L359:
	leaq	1552(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	jmp	.L428
.L360:
.L297:
	leaq	2640(%rsp), %rdi
	movq	%rax, (%rsp)
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	movq	(%rsp), %rax
	movq	%rax, %rdi
.LEHB159:
	call	_Unwind_Resume
.LEHE159:
	.cfi_endproc
.LFE3580:
	.size	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv, .-_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv
	.section	.gcc_except_table
.LLSDA3580:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3580-.LLSDACSB3580
.LLSDACSB3580:
	.uleb128 .LEHB62-.LFB3580
	.uleb128 .LEHE62-.LEHB62
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB63-.LFB3580
	.uleb128 .LEHE63-.LEHB63
	.uleb128 .L361-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB64-.LFB3580
	.uleb128 .LEHE64-.LEHB64
	.uleb128 .L362-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB65-.LFB3580
	.uleb128 .LEHE65-.LEHB65
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB66-.LFB3580
	.uleb128 .LEHE66-.LEHB66
	.uleb128 .L363-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB67-.LFB3580
	.uleb128 .LEHE67-.LEHB67
	.uleb128 .L364-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB68-.LFB3580
	.uleb128 .LEHE68-.LEHB68
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB69-.LFB3580
	.uleb128 .LEHE69-.LEHB69
	.uleb128 .L365-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB70-.LFB3580
	.uleb128 .LEHE70-.LEHB70
	.uleb128 .L366-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB71-.LFB3580
	.uleb128 .LEHE71-.LEHB71
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB72-.LFB3580
	.uleb128 .LEHE72-.LEHB72
	.uleb128 .L367-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB73-.LFB3580
	.uleb128 .LEHE73-.LEHB73
	.uleb128 .L368-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB74-.LFB3580
	.uleb128 .LEHE74-.LEHB74
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB75-.LFB3580
	.uleb128 .LEHE75-.LEHB75
	.uleb128 .L369-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB76-.LFB3580
	.uleb128 .LEHE76-.LEHB76
	.uleb128 .L370-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB77-.LFB3580
	.uleb128 .LEHE77-.LEHB77
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB78-.LFB3580
	.uleb128 .LEHE78-.LEHB78
	.uleb128 .L371-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB79-.LFB3580
	.uleb128 .LEHE79-.LEHB79
	.uleb128 .L372-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB80-.LFB3580
	.uleb128 .LEHE80-.LEHB80
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB81-.LFB3580
	.uleb128 .LEHE81-.LEHB81
	.uleb128 .L373-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB82-.LFB3580
	.uleb128 .LEHE82-.LEHB82
	.uleb128 .L374-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB83-.LFB3580
	.uleb128 .LEHE83-.LEHB83
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB84-.LFB3580
	.uleb128 .LEHE84-.LEHB84
	.uleb128 .L375-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB85-.LFB3580
	.uleb128 .LEHE85-.LEHB85
	.uleb128 .L376-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB86-.LFB3580
	.uleb128 .LEHE86-.LEHB86
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB87-.LFB3580
	.uleb128 .LEHE87-.LEHB87
	.uleb128 .L377-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB88-.LFB3580
	.uleb128 .LEHE88-.LEHB88
	.uleb128 .L378-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB89-.LFB3580
	.uleb128 .LEHE89-.LEHB89
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB90-.LFB3580
	.uleb128 .LEHE90-.LEHB90
	.uleb128 .L379-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB91-.LFB3580
	.uleb128 .LEHE91-.LEHB91
	.uleb128 .L380-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB92-.LFB3580
	.uleb128 .LEHE92-.LEHB92
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB93-.LFB3580
	.uleb128 .LEHE93-.LEHB93
	.uleb128 .L381-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB94-.LFB3580
	.uleb128 .LEHE94-.LEHB94
	.uleb128 .L382-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB95-.LFB3580
	.uleb128 .LEHE95-.LEHB95
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB96-.LFB3580
	.uleb128 .LEHE96-.LEHB96
	.uleb128 .L383-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB97-.LFB3580
	.uleb128 .LEHE97-.LEHB97
	.uleb128 .L384-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB98-.LFB3580
	.uleb128 .LEHE98-.LEHB98
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB99-.LFB3580
	.uleb128 .LEHE99-.LEHB99
	.uleb128 .L385-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB100-.LFB3580
	.uleb128 .LEHE100-.LEHB100
	.uleb128 .L386-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB101-.LFB3580
	.uleb128 .LEHE101-.LEHB101
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB102-.LFB3580
	.uleb128 .LEHE102-.LEHB102
	.uleb128 .L387-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB103-.LFB3580
	.uleb128 .LEHE103-.LEHB103
	.uleb128 .L388-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB104-.LFB3580
	.uleb128 .LEHE104-.LEHB104
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB105-.LFB3580
	.uleb128 .LEHE105-.LEHB105
	.uleb128 .L389-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB106-.LFB3580
	.uleb128 .LEHE106-.LEHB106
	.uleb128 .L390-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB107-.LFB3580
	.uleb128 .LEHE107-.LEHB107
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB108-.LFB3580
	.uleb128 .LEHE108-.LEHB108
	.uleb128 .L391-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB109-.LFB3580
	.uleb128 .LEHE109-.LEHB109
	.uleb128 .L392-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB110-.LFB3580
	.uleb128 .LEHE110-.LEHB110
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB111-.LFB3580
	.uleb128 .LEHE111-.LEHB111
	.uleb128 .L393-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB112-.LFB3580
	.uleb128 .LEHE112-.LEHB112
	.uleb128 .L394-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB113-.LFB3580
	.uleb128 .LEHE113-.LEHB113
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB114-.LFB3580
	.uleb128 .LEHE114-.LEHB114
	.uleb128 .L395-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB115-.LFB3580
	.uleb128 .LEHE115-.LEHB115
	.uleb128 .L396-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB116-.LFB3580
	.uleb128 .LEHE116-.LEHB116
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB117-.LFB3580
	.uleb128 .LEHE117-.LEHB117
	.uleb128 .L397-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB118-.LFB3580
	.uleb128 .LEHE118-.LEHB118
	.uleb128 .L398-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB119-.LFB3580
	.uleb128 .LEHE119-.LEHB119
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB120-.LFB3580
	.uleb128 .LEHE120-.LEHB120
	.uleb128 .L399-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB121-.LFB3580
	.uleb128 .LEHE121-.LEHB121
	.uleb128 .L400-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB122-.LFB3580
	.uleb128 .LEHE122-.LEHB122
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB123-.LFB3580
	.uleb128 .LEHE123-.LEHB123
	.uleb128 .L401-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB124-.LFB3580
	.uleb128 .LEHE124-.LEHB124
	.uleb128 .L402-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB125-.LFB3580
	.uleb128 .LEHE125-.LEHB125
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB126-.LFB3580
	.uleb128 .LEHE126-.LEHB126
	.uleb128 .L403-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB127-.LFB3580
	.uleb128 .LEHE127-.LEHB127
	.uleb128 .L404-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB128-.LFB3580
	.uleb128 .LEHE128-.LEHB128
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB129-.LFB3580
	.uleb128 .LEHE129-.LEHB129
	.uleb128 .L405-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB130-.LFB3580
	.uleb128 .LEHE130-.LEHB130
	.uleb128 .L406-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB131-.LFB3580
	.uleb128 .LEHE131-.LEHB131
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB132-.LFB3580
	.uleb128 .LEHE132-.LEHB132
	.uleb128 .L407-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB133-.LFB3580
	.uleb128 .LEHE133-.LEHB133
	.uleb128 .L408-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB134-.LFB3580
	.uleb128 .LEHE134-.LEHB134
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB135-.LFB3580
	.uleb128 .LEHE135-.LEHB135
	.uleb128 .L409-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB136-.LFB3580
	.uleb128 .LEHE136-.LEHB136
	.uleb128 .L410-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB137-.LFB3580
	.uleb128 .LEHE137-.LEHB137
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB138-.LFB3580
	.uleb128 .LEHE138-.LEHB138
	.uleb128 .L411-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB139-.LFB3580
	.uleb128 .LEHE139-.LEHB139
	.uleb128 .L412-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB140-.LFB3580
	.uleb128 .LEHE140-.LEHB140
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB141-.LFB3580
	.uleb128 .LEHE141-.LEHB141
	.uleb128 .L413-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB142-.LFB3580
	.uleb128 .LEHE142-.LEHB142
	.uleb128 .L414-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB143-.LFB3580
	.uleb128 .LEHE143-.LEHB143
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB144-.LFB3580
	.uleb128 .LEHE144-.LEHB144
	.uleb128 .L415-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB145-.LFB3580
	.uleb128 .LEHE145-.LEHB145
	.uleb128 .L416-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB146-.LFB3580
	.uleb128 .LEHE146-.LEHB146
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB147-.LFB3580
	.uleb128 .LEHE147-.LEHB147
	.uleb128 .L417-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB148-.LFB3580
	.uleb128 .LEHE148-.LEHB148
	.uleb128 .L418-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB149-.LFB3580
	.uleb128 .LEHE149-.LEHB149
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB150-.LFB3580
	.uleb128 .LEHE150-.LEHB150
	.uleb128 .L419-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB151-.LFB3580
	.uleb128 .LEHE151-.LEHB151
	.uleb128 .L420-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB152-.LFB3580
	.uleb128 .LEHE152-.LEHB152
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB153-.LFB3580
	.uleb128 .LEHE153-.LEHB153
	.uleb128 .L421-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB154-.LFB3580
	.uleb128 .LEHE154-.LEHB154
	.uleb128 .L422-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB155-.LFB3580
	.uleb128 .LEHE155-.LEHB155
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB156-.LFB3580
	.uleb128 .LEHE156-.LEHB156
	.uleb128 .L423-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB157-.LFB3580
	.uleb128 .LEHE157-.LEHB157
	.uleb128 .L424-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB158-.LFB3580
	.uleb128 .LEHE158-.LEHB158
	.uleb128 .L360-.LFB3580
	.uleb128 0x0
	.uleb128 .LEHB159-.LFB3580
	.uleb128 .LEHE159-.LEHB159
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3580:
	.section	.text._ZN3fem11PrismFamilyIdE22generateQuadratureDataEv,"axG",@progbits,_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv,comdat
	.section	.text._ZN3fem11PrismFamilyIdEC2Ev,"axG",@progbits,_ZN3fem11PrismFamilyIdEC5Ev,comdat
	.align 2
	.weak	_ZN3fem11PrismFamilyIdEC2Ev
	.type	_ZN3fem11PrismFamilyIdEC2Ev, @function
_ZN3fem11PrismFamilyIdEC2Ev:
.LFB3550:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3550
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rdi)
	leaq	16(%rdi), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE13_Rb_tree_implISG_Lb0EEC1Ev
	movq	$0, 64(%rbx)
	movq	$0, 72(%rbx)
	movq	%rbx, %rdi
	movq	$0, 80(%rbx)
	movq	$0, 88(%rbx)
	movq	$0, 96(%rbx)
	movq	$0, 104(%rbx)
	movq	$0, 112(%rbx)
	movq	$0, 120(%rbx)
	movq	$0, 128(%rbx)
	movq	$0, 136(%rbx)
	movq	$0, 144(%rbx)
	movq	$0, 152(%rbx)
	movq	$0, 160(%rbx)
	movq	$0, 168(%rbx)
	movq	$0, 176(%rbx)
	movq	$0, 192(%rbx)
	movq	$0, 200(%rbx)
	movq	$0, 208(%rbx)
	movq	$_ZTVN3fem11PrismFamilyIdEE+16, (%rbx)
.LEHB160:
	call	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv
.LEHE160:
	jmp	.L433
.L431:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB161:
	call	_Unwind_Resume
.LEHE161:
.L433:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3550:
	.size	_ZN3fem11PrismFamilyIdEC2Ev, .-_ZN3fem11PrismFamilyIdEC2Ev
	.section	.gcc_except_table
.LLSDA3550:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3550-.LLSDACSB3550
.LLSDACSB3550:
	.uleb128 .LEHB160-.LFB3550
	.uleb128 .LEHE160-.LEHB160
	.uleb128 .L431-.LFB3550
	.uleb128 0x0
	.uleb128 .LEHB161-.LFB3550
	.uleb128 .LEHE161-.LEHB161
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3550:
	.section	.text._ZN3fem11PrismFamilyIdEC2Ev,"axG",@progbits,_ZN3fem11PrismFamilyIdEC5Ev,comdat
	.weak	_ZN3fem11PrismFamilyIdEC1Ev
	.set	_ZN3fem11PrismFamilyIdEC1Ev,_ZN3fem11PrismFamilyIdEC2Ev
	.section	.text._ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	.type	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_, @function
_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_:
.LFB4020:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	subq	%rdi, %rsi
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdx, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	sarq	$3, %rbp
	je	.L435
	leaq	0(,%rbp,8), %rdx
	movq	%rdi, %rsi
	movq	%rbx, %rdi
	call	memmove
.L435:
	leaq	(%rbx,%rbp,8), %rax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4020:
	.size	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_, .-_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	.section	.text._ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd,"axG",@progbits,_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd,comdat
	.align 2
	.weak	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	.type	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd, @function
_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd:
.LFB3680:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	movq	%rcx, %r15
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rsi, %r13
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	pushq	%r12
	.cfi_def_cfa_offset 40
	movq	%rsi, %r12
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rdx, %rbp
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rdi, %rbx
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	testq	%rdx, %rdx
	je	.L436
	movq	8(%rdi), %r14
	movq	16(%rdi), %rax
	subq	%r14, %rax
	sarq	$3, %rax
	cmpq	%rdx, %rax
	jb	.L438
	movq	%r14, %r15
	movq	(%rcx), %rcx
	subq	%rsi, %r15
	sarq	$3, %r15
	cmpq	%rdx, %r15
	jbe	.L439
	salq	$3, %rbp
	movq	%r14, %r12
	movq	%r14, %rdx
	subq	%rbp, %r12
	movq	%r14, %rsi
	movq	%rcx, (%rsp)
	movq	%r12, %rdi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	addq	%rbp, 8(%rbx)
	movq	%r14, %rdx
	movq	%r12, %rsi
	movq	%r13, %rdi
	leaq	0(%r13,%rbp), %rbp
	call	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIdEEPT_PKS3_S6_S4_
	movq	(%rsp), %rcx
	jmp	.L440
.L441:
	movq	%rcx, 0(%r13)
	addq	$8, %r13
.L440:
	cmpq	%rbp, %r13
	jne	.L441
	jmp	.L436
.L439:
	subq	%r15, %rbp
	movq	%r14, %rax
	movq	%rbp, %rdx
	jmp	.L442
.L443:
	movq	%rcx, (%rax)
	decq	%rdx
	addq	$8, %rax
.L442:
	testq	%rdx, %rdx
	jne	.L443
	leaq	(%r14,%rbp,8), %rdx
	movq	%r14, %rsi
	movq	%r12, %rdi
	movq	%rcx, (%rsp)
	salq	$3, %r15
	movq	%rdx, 8(%rbx)
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	addq	%r15, 8(%rbx)
	movq	(%rsp), %rcx
	jmp	.L444
.L445:
	movq	%rcx, 0(%r13)
	addq	$8, %r13
.L444:
	cmpq	%r14, %r13
	jne	.L445
	jmp	.L436
.L438:
	movl	$.LC10, %edx
	movq	%rbp, %rsi
	xorl	%r13d, %r13d
	call	_ZNKSt6vectorIdSaIdEE12_M_check_lenEmPKc
	movq	%rax, %r14
	movq	(%rbx), %rax
	testq	%r14, %r14
	movq	%rax, 8(%rsp)
	je	.L446
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r14
	jbe	.L447
	call	_ZSt17__throw_bad_allocv
.L447:
	leaq	0(,%r14,8), %rdi
	call	_Znwm
	movq	%rax, %r13
.L446:
	movq	%r12, %rdx
	subq	8(%rsp), %rdx
	movq	(%r15), %rcx
	movq	%rbp, %rax
	andq	$-8, %rdx
	leaq	0(%r13,%rdx), %rdx
.L448:
	movq	%rcx, (%rdx)
	addq	$8, %rdx
	decq	%rax
	jne	.L448
	movq	(%rbx), %rdi
	movq	%r13, %rdx
	movq	%r12, %rsi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	movq	8(%rbx), %rsi
	leaq	(%rax,%rbp,8), %rdx
	movq	%r12, %rdi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIdEEPT_PKS3_S6_S4_
	movq	(%rbx), %rdi
	movq	%rax, %rbp
	testq	%rdi, %rdi
	je	.L449
	call	_ZdlPv
.L449:
	leaq	0(%r13,%r14,8), %rax
	movq	%r13, (%rbx)
	movq	%rbp, 8(%rbx)
	movq	%rax, 16(%rbx)
.L436:
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3680:
	.size	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd, .-_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	.section	.text._ZNSt6vectorIdSaIdEE6resizeEmd,"axG",@progbits,_ZNSt6vectorIdSaIdEE6resizeEmd,comdat
	.align 2
	.weak	_ZNSt6vectorIdSaIdEE6resizeEmd
	.type	_ZNSt6vectorIdSaIdEE6resizeEmd, @function
_ZNSt6vectorIdSaIdEE6resizeEmd:
.LFB3559:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%rsi, %rdx
	movq	8(%rdi), %rsi
	movq	(%rdi), %rcx
	movsd	%xmm0, 8(%rsp)
	movq	%rsi, %rax
	subq	%rcx, %rax
	sarq	$3, %rax
	cmpq	%rax, %rdx
	jae	.L453
	leaq	(%rcx,%rdx,8), %rax
	movq	%rax, 8(%rdi)
	jmp	.L452
.L453:
	leaq	8(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
.L452:
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3559:
	.size	_ZNSt6vectorIdSaIdEE6resizeEmd, .-_ZNSt6vectorIdSaIdEE6resizeEmd
	.section	.text._ZN3fem6Prism6IdEC2Ev,"axG",@progbits,_ZN3fem6Prism6IdEC5Ev,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdEC2Ev
	.type	_ZN3fem6Prism6IdEC2Ev, @function
_ZN3fem6Prism6IdEC2Ev:
.LFB3521:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3521
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdi, %rbx
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
.LEHB162:
	call	_ZN3fem11PrismFamilyIdEC2Ev
.LEHE162:
	movq	$_ZTVN3fem6Prism6IdEE+16, (%rbx)
	movl	$6, 216(%rbx)
	movq	%rsp, %rdi
	movl	$2, 8(%rbx)
	movl	$2, 12(%rbx)
.LEHB163:
	call	_ZN3fem5pointC1Ev
.LEHE163:
	leaq	64(%rbx), %rdi
	movq	%rsp, %rdx
	movl	$6, %esi
.LEHB164:
	call	_ZNSt6vectorIN3fem5pointESaIS1_EE6resizeEmS1_
.LEHE164:
	movq	%rsp, %rdi
.LEHB165:
	call	_ZN3fem5pointD1Ev
	xorps	%xmm0, %xmm0
	leaq	88(%rbx), %rdi
	movl	$6, %esi
	call	_ZNSt6vectorIdSaIdEE6resizeEmd
	xorps	%xmm0, %xmm0
	leaq	112(%rbx), %rdi
	movl	$6, %esi
	call	_ZNSt6vectorIdSaIdEE6resizeEmd
	xorps	%xmm0, %xmm0
	leaq	136(%rbx), %rdi
	movl	$6, %esi
	call	_ZNSt6vectorIdSaIdEE6resizeEmd
	xorps	%xmm0, %xmm0
	leaq	160(%rbx), %rdi
	movl	$6, %esi
	call	_ZNSt6vectorIdSaIdEE6resizeEmd
.LEHE165:
	jmp	.L462
.L460:
	movq	%rsp, %rdi
	movq	%rax, %rbp
	call	_ZN3fem5pointD1Ev
	jmp	.L457
.L459:
	movq	%rax, %rbp
.L457:
	movq	%rbx, %rdi
	movq	$_ZTVN3fem11PrismFamilyIdEE+16, (%rbx)
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB166:
	call	_Unwind_Resume
.LEHE166:
.L462:
	addq	$40, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3521:
	.size	_ZN3fem6Prism6IdEC2Ev, .-_ZN3fem6Prism6IdEC2Ev
	.section	.gcc_except_table
.LLSDA3521:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3521-.LLSDACSB3521
.LLSDACSB3521:
	.uleb128 .LEHB162-.LFB3521
	.uleb128 .LEHE162-.LEHB162
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB163-.LFB3521
	.uleb128 .LEHE163-.LEHB163
	.uleb128 .L459-.LFB3521
	.uleb128 0x0
	.uleb128 .LEHB164-.LFB3521
	.uleb128 .LEHE164-.LEHB164
	.uleb128 .L460-.LFB3521
	.uleb128 0x0
	.uleb128 .LEHB165-.LFB3521
	.uleb128 .LEHE165-.LEHB165
	.uleb128 .L459-.LFB3521
	.uleb128 0x0
	.uleb128 .LEHB166-.LFB3521
	.uleb128 .LEHE166-.LEHB166
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3521:
	.section	.text._ZN3fem6Prism6IdEC2Ev,"axG",@progbits,_ZN3fem6Prism6IdEC5Ev,comdat
	.weak	_ZN3fem6Prism6IdEC1Ev
	.set	_ZN3fem6Prism6IdEC1Ev,_ZN3fem6Prism6IdEC2Ev
	.text
.globl main
	.type	main, @function
main:
.LFB3480:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3480
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$256, %rsp
	.cfi_def_cfa_offset 272
	movq	%rsp, %rdi
.LEHB167:
	.cfi_offset 3, -16
	call	_ZN3fem6Prism6IdEC1Ev
.LEHE167:
	leaq	224(%rsp), %rdi
.LEHB168:
	call	_ZN3fem5pointC1Ev
.LEHE168:
	leaq	224(%rsp), %rsi
	movq	%rsp, %rdi
.LEHB169:
	call	_ZN3fem6Prism6IdE4setNERKNS_5pointE
.LEHE169:
	leaq	224(%rsp), %rdi
.LEHB170:
	call	_ZN3fem5pointD1Ev
.LEHE170:
	movq	%rsp, %rdi
.LEHB171:
	call	_ZN3fem6Prism6IdED1Ev
.LEHE171:
	xorl	%eax, %eax
	addq	$256, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L467:
	.cfi_restore_state
	leaq	224(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L465
.L466:
	movq	%rax, %rbx
.L465:
	movq	%rsp, %rdi
	call	_ZN3fem6Prism6IdED1Ev
	movq	%rbx, %rdi
.LEHB172:
	call	_Unwind_Resume
.LEHE172:
	.cfi_endproc
.LFE3480:
	.size	main, .-main
	.section	.gcc_except_table
.LLSDA3480:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3480-.LLSDACSB3480
.LLSDACSB3480:
	.uleb128 .LEHB167-.LFB3480
	.uleb128 .LEHE167-.LEHB167
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB168-.LFB3480
	.uleb128 .LEHE168-.LEHB168
	.uleb128 .L466-.LFB3480
	.uleb128 0x0
	.uleb128 .LEHB169-.LFB3480
	.uleb128 .LEHE169-.LEHB169
	.uleb128 .L467-.LFB3480
	.uleb128 0x0
	.uleb128 .LEHB170-.LFB3480
	.uleb128 .LEHE170-.LEHB170
	.uleb128 .L466-.LFB3480
	.uleb128 0x0
	.uleb128 .LEHB171-.LFB3480
	.uleb128 .LEHE171-.LEHB171
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB172-.LFB3480
	.uleb128 .LEHE172-.LEHB172
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3480:
	.text
	.section	.text._ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
	.type	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_, @function
_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_:
.LFB4071:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	subq	%rdi, %rsi
	movq	%rsi, %rbp
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	movq	%rdx, %rbx
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	sarq	$3, %rbp
	je	.L469
	leaq	0(,%rbp,8), %rdx
	movq	%rdi, %rsi
	movq	%rbx, %rdi
	call	memmove
.L469:
	leaq	(%rbx,%rbp,8), %rax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4071:
	.size	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_, .-_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
	.section	.text._ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_,comdat
	.weak	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_
	.type	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_, @function
_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_:
.LFB4053:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4053:
	.size	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_, .-_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_
	.section	.text._ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_,"axG",@progbits,_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_,comdat
	.weak	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_
	.type	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_, @function
_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_:
.LFB4039:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET1_T0_SB_SA_
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4039:
	.size	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_, .-_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_
	.section	.text._ZNSt6vectorImSaImEEaSERKS1_,"axG",@progbits,_ZNSt6vectorImSaImEEaSERKS1_,comdat
	.align 2
	.weak	_ZNSt6vectorImSaImEEaSERKS1_
	.type	_ZNSt6vectorImSaImEEaSERKS1_, @function
_ZNSt6vectorImSaImEEaSERKS1_:
.LFB4033:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	pushq	%r12
	.cfi_def_cfa_offset 24
	movq	%rsi, %r12
	.cfi_offset 12, -24
	.cfi_offset 13, -16
	pushq	%rbp
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rdi, %rbx
	.cfi_offset 3, -40
	.cfi_offset 6, -32
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L473
	movq	8(%rsi), %rsi
	movq	(%r12), %r13
	movq	(%rdi), %rdx
	movq	16(%rdi), %rax
	movq	%rsi, %rbp
	subq	%r13, %rbp
	subq	%rdx, %rax
	sarq	$3, %rbp
	sarq	$3, %rax
	cmpq	%rax, %rbp
	jbe	.L474
	testq	%rbp, %rbp
	je	.L480
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbp
	jbe	.L476
	call	_ZSt17__throw_bad_allocv
.L476:
	leaq	0(,%rbp,8), %rdi
	movq	%rsi, 8(%rsp)
	call	_Znwm
	movq	8(%rsp), %rsi
	movq	%rax, %r12
	jmp	.L475
.L480:
	xorl	%r12d, %r12d
.L475:
	movq	%r13, %rdi
	movq	%r12, %rdx
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L477
	call	_ZdlPv
.L477:
	leaq	(%r12,%rbp,8), %rax
	movq	%r12, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L478
.L474:
	movq	8(%rdi), %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	%rbp, %rax
	jb	.L479
	movq	%r13, %rdi
	call	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKmSt6vectorImSaImEEEENS1_IPmS6_EEET0_T_SB_SA_
	jmp	.L478
.L479:
	leaq	0(%r13,%rax,8), %rsi
	movq	%r13, %rdi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
	movq	8(%rbx), %rdx
	movq	8(%r12), %rsi
	movq	%rdx, %rdi
	subq	(%rbx), %rdi
	andq	$-8, %rdi
	addq	(%r12), %rdi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mImEEPT_PKS3_S6_S4_
.L478:
	movq	(%rbx), %rcx
	leaq	(%rcx,%rbp,8), %rbp
	movq	%rbp, 8(%rbx)
.L473:
	addq	$24, %rsp
	.cfi_def_cfa_offset 40
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4033:
	.size	_ZNSt6vectorImSaImEEaSERKS1_, .-_ZNSt6vectorImSaImEEaSERKS1_
	.section	.rodata.str1.1
.LC39:
	.string	"Prism6.h++"
.LC40:
	.string	"nodes.size() == 6"
	.section	.text._ZN3fem6Prism6IdE3setERSt6vectorImSaImEE,"axG",@progbits,_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE,comdat
	.align 2
	.weak	_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE
	.type	_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE, @function
_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE:
.LFB4029:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rsi), %rax
	subq	(%rsi), %rax
	sarq	$3, %rax
	cmpq	$6, %rax
	je	.L482
	movl	$_ZZN3fem6Prism6IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, %ecx
	movl	$172, %edx
	movl	$.LC39, %esi
	movl	$.LC40, %edi
	call	__assert_fail
.L482:
	addq	$192, %rdi
	call	_ZNSt6vectorImSaImEEaSERKS1_
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4029:
	.size	_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE, .-_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE
	.text
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB4076:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE4076:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__I_main
	.local	_ZN5boost6tuplesL6ignoreE
	.comm	_ZN5boost6tuplesL6ignoreE,1,1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.weak	_ZTVN3fem6Prism6IdEE
	.section	.rodata._ZTVN3fem6Prism6IdEE,"aG",@progbits,_ZTVN3fem6Prism6IdEE,comdat
	.align 16
	.type	_ZTVN3fem6Prism6IdEE, @object
	.size	_ZTVN3fem6Prism6IdEE, 112
_ZTVN3fem6Prism6IdEE:
	.quad	0
	.quad	_ZTIN3fem6Prism6IdEE
	.quad	_ZN3fem6Prism6IdE14setCoordinatesEv
	.quad	_ZN3fem6Prism6IdE4setNERKNS_5pointE
	.quad	_ZN3fem6Prism6IdE4setNERKdS3_S3_
	.quad	_ZN3fem6Prism6IdE9setdNdcsiERKNS_5pointE
	.quad	_ZN3fem6Prism6IdE9setdNdcsiERKdS3_S3_
	.quad	_ZN3fem6Prism6IdE9setdNdetaERKNS_5pointE
	.quad	_ZN3fem6Prism6IdE9setdNdetaERKdS3_S3_
	.quad	_ZN3fem6Prism6IdE10setdNdzetaERKNS_5pointE
	.quad	_ZN3fem6Prism6IdE10setdNdzetaERKdS3_S3_
	.quad	_ZN3fem6Prism6IdE3setERSt6vectorImSaImEE
	.quad	_ZNK3fem6Prism6IdE11node_numberEv
	.quad	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv
	.section	.rodata
	.align 16
	.type	_ZZN3fem6Prism6IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, @object
	.size	_ZZN3fem6Prism6IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, 178
_ZZN3fem6Prism6IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__:
	.string	"typename fem::BaseElement<T>::Error fem::Prism6<T>::set(std::vector<long unsigned int>&) [with T = double, typename fem::BaseElement<T>::Error = fem::BaseElement<double>::Error]"
	.weak	_ZTVN3fem11PrismFamilyIdEE
	.section	.rodata._ZTVN3fem11PrismFamilyIdEE,"aG",@progbits,_ZTVN3fem11PrismFamilyIdEE,comdat
	.align 16
	.type	_ZTVN3fem11PrismFamilyIdEE, @object
	.size	_ZTVN3fem11PrismFamilyIdEE, 112
_ZTVN3fem11PrismFamilyIdEE:
	.quad	0
	.quad	_ZTIN3fem11PrismFamilyIdEE
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	_ZN3fem11PrismFamilyIdE22generateQuadratureDataEv
	.weak	_ZTVN3fem11BaseElementIdEE
	.section	.rodata._ZTVN3fem11BaseElementIdEE,"aG",@progbits,_ZTVN3fem11BaseElementIdEE,comdat
	.align 16
	.type	_ZTVN3fem11BaseElementIdEE, @object
	.size	_ZTVN3fem11BaseElementIdEE, 112
_ZTVN3fem11BaseElementIdEE:
	.quad	0
	.quad	_ZTIN3fem11BaseElementIdEE
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.weak	_ZTIN3fem6Prism6IdEE
	.section	.rodata._ZTIN3fem6Prism6IdEE,"aG",@progbits,_ZTIN3fem6Prism6IdEE,comdat
	.align 16
	.type	_ZTIN3fem6Prism6IdEE, @object
	.size	_ZTIN3fem6Prism6IdEE, 24
_ZTIN3fem6Prism6IdEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3fem6Prism6IdEE
	.quad	_ZTIN3fem11PrismFamilyIdEE
	.weak	_ZTIN3fem11PrismFamilyIdEE
	.section	.rodata._ZTIN3fem11PrismFamilyIdEE,"aG",@progbits,_ZTIN3fem11PrismFamilyIdEE,comdat
	.align 16
	.type	_ZTIN3fem11PrismFamilyIdEE, @object
	.size	_ZTIN3fem11PrismFamilyIdEE, 24
_ZTIN3fem11PrismFamilyIdEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3fem11PrismFamilyIdEE
	.quad	_ZTIN3fem11BaseElementIdEE
	.weak	_ZTIN3fem11BaseElementIdEE
	.section	.rodata._ZTIN3fem11BaseElementIdEE,"aG",@progbits,_ZTIN3fem11BaseElementIdEE,comdat
	.align 16
	.type	_ZTIN3fem11BaseElementIdEE, @object
	.size	_ZTIN3fem11BaseElementIdEE, 16
_ZTIN3fem11BaseElementIdEE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN3fem11BaseElementIdEE
	.weak	_ZTSN3fem6Prism6IdEE
	.section	.rodata._ZTSN3fem6Prism6IdEE,"aG",@progbits,_ZTSN3fem6Prism6IdEE,comdat
	.align 16
	.type	_ZTSN3fem6Prism6IdEE, @object
	.size	_ZTSN3fem6Prism6IdEE, 17
_ZTSN3fem6Prism6IdEE:
	.string	"N3fem6Prism6IdEE"
	.weak	_ZTSN3fem11PrismFamilyIdEE
	.section	.rodata._ZTSN3fem11PrismFamilyIdEE,"aG",@progbits,_ZTSN3fem11PrismFamilyIdEE,comdat
	.align 16
	.type	_ZTSN3fem11PrismFamilyIdEE, @object
	.size	_ZTSN3fem11PrismFamilyIdEE, 23
_ZTSN3fem11PrismFamilyIdEE:
	.string	"N3fem11PrismFamilyIdEE"
	.weak	_ZTSN3fem11BaseElementIdEE
	.section	.rodata._ZTSN3fem11BaseElementIdEE,"aG",@progbits,_ZTSN3fem11BaseElementIdEE,comdat
	.align 16
	.type	_ZTSN3fem11BaseElementIdEE, @object
	.size	_ZTSN3fem11BaseElementIdEE, 23
_ZTSN3fem11BaseElementIdEE:
	.string	"N3fem11BaseElementIdEE"
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1072693248
	.align 8
.LC2:
	.long	0
	.long	1071644672
	.align 8
.LC5:
	.long	0
	.long	1070596096
	.align 8
.LC6:
	.long	1414677840
	.long	1074340347
	.section	.rodata.cst16
	.align 16
.LC7:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.section	.rodata.cst8
	.align 8
.LC8:
	.long	3910863728
	.long	1036025375
	.align 8
.LC9:
	.long	0
	.long	1073741824
	.align 8
.LC19:
	.long	188365716
	.long	1081735126
	.align 8
.LC20:
	.long	0
	.long	1085083648
	.align 8
.LC21:
	.long	3918235863
	.long	1080660051
	.align 8
.LC24:
	.long	2235220677
	.long	1080222736
	.align 8
.LC25:
	.long	0
	.long	1084407808
	.align 8
.LC26:
	.long	2059746619
	.long	1080286191
	.align 8
.LC27:
	.long	0
	.long	1075970048
	.align 8
.LC28:
	.long	0
	.long	1079246848
	.align 8
.LC31:
	.long	4094587648
	.long	1068107863
	.align 8
.LC34:
	.long	2464009927
	.long	1069409716
	.align 8
.LC37:
	.long	1681401503
	.long	1068840378
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
