	.file	"main.c++"
	.section	.text._ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE,"axG",@progbits,_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE
	.type	_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE, @function
_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE:
.LFB3540:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	16(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE3540:
	.size	_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE, .-_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE
	.section	.text._ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_,"axG",@progbits,_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_
	.type	_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_, @function
_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_:
.LFB3574:
	.cfi_startproc
	movsd	.LC0(%rip), %xmm0
	movq	88(%rdi), %rax
	subsd	(%rcx), %xmm0
	subsd	(%rdx), %xmm0
	subsd	(%rsi), %xmm0
	movsd	%xmm0, (%rax)
	movq	(%rsi), %rsi
	movq	%rsi, 8(%rax)
	movq	(%rdx), %rdx
	movq	%rdx, 16(%rax)
	movq	(%rcx), %rdx
	movq	%rdx, 24(%rax)
	leaq	88(%rdi), %rax
	ret
	.cfi_endproc
.LFE3574:
	.size	_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_, .-_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_
	.section	.text._ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE,"axG",@progbits,_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE
	.type	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE, @function
_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE:
.LFB4036:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	32(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4036:
	.size	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE, .-_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE
	.section	.text._ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_,"axG",@progbits,_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_
	.type	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_, @function
_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_:
.LFB4037:
	.cfi_startproc
	movq	112(%rdi), %rdx
	movabsq	$-4616189618054758400, %rax
	movabsq	$4607182418800017408, %rcx
	movq	%rax, (%rdx)
	xorl	%eax, %eax
	movq	%rcx, 8(%rdx)
	movq	%rax, 16(%rdx)
	movq	%rax, 24(%rdx)
	leaq	112(%rdi), %rax
	ret
	.cfi_endproc
.LFE4037:
	.size	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_, .-_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_
	.section	.text._ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE,"axG",@progbits,_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE
	.type	_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE, @function
_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE:
.LFB4038:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	48(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4038:
	.size	_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE, .-_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE
	.section	.text._ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_,"axG",@progbits,_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_
	.type	_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_, @function
_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_:
.LFB4039:
	.cfi_startproc
	movq	136(%rdi), %rdx
	xorl	%eax, %eax
	movabsq	$-4616189618054758400, %rsi
	movabsq	$4607182418800017408, %r8
	movq	%rax, 8(%rdx)
	movq	%rax, 24(%rdx)
	leaq	136(%rdi), %rax
	movq	%rsi, (%rdx)
	movq	%r8, 16(%rdx)
	ret
	.cfi_endproc
.LFE4039:
	.size	_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_, .-_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_
	.section	.text._ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE,"axG",@progbits,_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE
	.type	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE, @function
_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE:
.LFB4040:
	.cfi_startproc
	movq	(%rdi), %rax
	leaq	24(%rsi), %rcx
	leaq	16(%rsi), %rdx
	addq	$8, %rsi
	movq	64(%rax), %rax
	jmp	*%rax
	.cfi_endproc
.LFE4040:
	.size	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE, .-_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE
	.section	.text._ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_,"axG",@progbits,_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_
	.type	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_, @function
_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_:
.LFB4041:
	.cfi_startproc
	movq	160(%rdi), %rdx
	xorl	%eax, %eax
	movabsq	$-4616189618054758400, %r9
	movabsq	$4607182418800017408, %r10
	movq	%rax, 8(%rdx)
	movq	%rax, 16(%rdx)
	leaq	160(%rdi), %rax
	movq	%r9, (%rdx)
	movq	%r10, 24(%rdx)
	ret
	.cfi_endproc
.LFE4041:
	.size	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_, .-_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_
	.section	.text._ZNK3fem12Tetrahedron4IdE11node_numberEv,"axG",@progbits,_ZNK3fem12Tetrahedron4IdE11node_numberEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNK3fem12Tetrahedron4IdE11node_numberEv
	.type	_ZNK3fem12Tetrahedron4IdE11node_numberEv, @function
_ZNK3fem12Tetrahedron4IdE11node_numberEv:
.LFB4043:
	.cfi_startproc
	movl	$4, %eax
	ret
	.cfi_endproc
.LFE4043:
	.size	_ZNK3fem12Tetrahedron4IdE11node_numberEv, .-_ZNK3fem12Tetrahedron4IdE11node_numberEv
	.section	.text._ZN3fem12Tetrahedron4IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem12Tetrahedron4IdE14setCoordinatesEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE14setCoordinatesEv
	.type	_ZN3fem12Tetrahedron4IdE14setCoordinatesEv, @function
_ZN3fem12Tetrahedron4IdE14setCoordinatesEv:
.LFB4035:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA4035
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	subq	$352, %rsp
	.cfi_def_cfa_offset 368
	leaq	336(%rsp), %rdx
	leaq	344(%rsp), %rsi
	leaq	224(%rsp), %rdi
	leaq	328(%rsp), %rcx
	movq	$0, 328(%rsp)
	movq	$0, 336(%rsp)
	movq	$0, 344(%rsp)
.LEHB0:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE0:
	movq	64(%rbx), %rsi
	leaq	224(%rsp), %rdx
	leaq	192(%rsp), %rdi
.LEHB1:
	call	_ZN3fem5pointaSERKS0_
	leaq	192(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE1:
	leaq	224(%rsp), %rdi
.LEHB2:
	call	_ZN3fem5pointD1Ev
	leaq	312(%rsp), %rdx
	leaq	320(%rsp), %rsi
	leaq	160(%rsp), %rdi
	leaq	304(%rsp), %rcx
	movabsq	$4607182418800017408, %rax
	movq	$0, 304(%rsp)
	movq	$0, 312(%rsp)
	movq	%rax, 320(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE2:
	movq	64(%rbx), %rsi
	leaq	160(%rsp), %rdx
	leaq	128(%rsp), %rdi
	addq	$32, %rsi
.LEHB3:
	call	_ZN3fem5pointaSERKS0_
	leaq	128(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE3:
	leaq	160(%rsp), %rdi
.LEHB4:
	call	_ZN3fem5pointD1Ev
	leaq	288(%rsp), %rdx
	leaq	296(%rsp), %rsi
	leaq	96(%rsp), %rdi
	leaq	280(%rsp), %rcx
	movabsq	$4607182418800017408, %rax
	movq	$0, 280(%rsp)
	movq	%rax, 288(%rsp)
	movq	$0, 296(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE4:
	movq	64(%rbx), %rsi
	leaq	96(%rsp), %rdx
	leaq	64(%rsp), %rdi
	addq	$64, %rsi
.LEHB5:
	call	_ZN3fem5pointaSERKS0_
	leaq	64(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE5:
	leaq	96(%rsp), %rdi
.LEHB6:
	call	_ZN3fem5pointD1Ev
	leaq	264(%rsp), %rdx
	leaq	272(%rsp), %rsi
	leaq	32(%rsp), %rdi
	leaq	256(%rsp), %rcx
	movabsq	$4607182418800017408, %r11
	movq	$0, 264(%rsp)
	movq	%r11, 256(%rsp)
	movq	$0, 272(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE6:
	movq	64(%rbx), %rsi
	leaq	32(%rsp), %rdx
	movq	%rsp, %rdi
	addq	$96, %rsi
.LEHB7:
	call	_ZN3fem5pointaSERKS0_
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
.LEHE7:
	leaq	32(%rsp), %rdi
.LEHB8:
	call	_ZN3fem5pointD1Ev
.LEHE8:
	leaq	64(%rbx), %rax
	addq	$352, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L15:
	.cfi_restore_state
	leaq	224(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB9:
	call	_Unwind_Resume
.LEHE9:
.L18:
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB10:
	call	_Unwind_Resume
.LEHE10:
.L17:
	leaq	96(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB11:
	call	_Unwind_Resume
.LEHE11:
.L16:
	leaq	160(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB12:
	call	_Unwind_Resume
.LEHE12:
	.cfi_endproc
.LFE4035:
	.size	_ZN3fem12Tetrahedron4IdE14setCoordinatesEv, .-_ZN3fem12Tetrahedron4IdE14setCoordinatesEv
.globl __gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA4035:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4035-.LLSDACSB4035
.LLSDACSB4035:
	.uleb128 .LEHB0-.LFB4035
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB1-.LFB4035
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L15-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB2-.LFB4035
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB3-.LFB4035
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L16-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB4-.LFB4035
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB5-.LFB4035
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L17-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB6-.LFB4035
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB7-.LFB4035
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L18-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB8-.LFB4035
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB9-.LFB4035
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB10-.LFB4035
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB11-.LFB4035
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB12-.LFB4035
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE4035:
	.section	.text._ZN3fem12Tetrahedron4IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem12Tetrahedron4IdE14setCoordinatesEv,comdat
	.text
	.align 2
	.p2align 4,,15
	.type	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33, @function
_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33:
.LFB4123:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L20
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L20:
	rep
	ret
	.cfi_endproc
.LFE4123:
	.size	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33, .-_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
	.section	.text._ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev,"axG",@progbits,_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.type	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev, @function
_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev:
.LFB3599:
	.cfi_startproc
	jmp	_ZN3fem5pointD1Ev
	.cfi_endproc
.LFE3599:
	.size	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev, .-_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.weak	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	.set	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev,_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED2Ev
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev:
.LFB3645:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rdi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	8(%rdi), %rbp
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	movq	(%rdi), %rbx
	cmpq	%rbx, %rbp
	je	.L26
	.p2align 4,,10
	.p2align 3
.L35:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L35
.L26:
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L25
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L25:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3645:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	.set	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E:
.LFB3660:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbp
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	%rsi, 56(%rsp)
.L38:
	cmpq	$0, 56(%rsp)
	je	.L178
	.cfi_offset 3, -56
	movq	56(%rsp), %rax
	movq	24(%rax), %r13
.L39:
	testq	%r13, %r13
	je	.L179
	movq	24(%r13), %r14
.L40:
	testq	%r14, %r14
	je	.L180
	movq	24(%r14), %r15
.L41:
	testq	%r15, %r15
	je	.L181
	movq	24(%r15), %rdx
	movq	%rdx, 32(%rsp)
.L42:
	cmpq	$0, 32(%rsp)
	je	.L182
	movq	32(%rsp), %rax
	movq	24(%rax), %rax
	movq	%rax, 40(%rsp)
.L43:
	cmpq	$0, 40(%rsp)
	je	.L183
	movq	40(%rsp), %rdx
	movq	24(%rdx), %rdx
	testq	%rdx, %rdx
	movq	%rdx, 48(%rsp)
	je	.L44
.L175:
	movq	48(%rsp), %rdx
	movq	24(%rdx), %r12
	testq	%r12, %r12
	je	.L45
.L176:
	movq	24(%r12), %rbx
	testq	%rbx, %rbx
	je	.L46
	.p2align 4,,10
	.p2align 3
.L177:
	movq	24(%rbx), %rsi
	movq	%rbp, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	movq	16(%rbx), %rax
	leaq	40(%rbx), %rdx
	movq	%rdx, 24(%rsp)
	movq	%rax, 16(%rsp)
	movq	48(%rbx), %rax
	movq	%rax, 8(%rsp)
	movq	40(%rbx), %rax
	cmpq	%rax, 8(%rsp)
	je	.L47
	.p2align 4,,10
	.p2align 3
.L170:
	movq	%rax, %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
	addq	$40, %rax
	cmpq	%rax, 8(%rsp)
	jne	.L170
.L47:
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L58
	call	_ZdlPv
.L58:
	movq	%rbx, %rdi
	call	_ZdlPv
	cmpq	$0, 16(%rsp)
	je	.L46
	movq	16(%rsp), %rbx
	jmp	.L177
.L46:
	movq	16(%r12), %rax
	movq	40(%r12), %rbx
	leaq	40(%r12), %rdx
	movq	%rdx, 24(%rsp)
	movq	%rax, 16(%rsp)
	movq	48(%r12), %rax
	cmpq	%rbx, %rax
	movq	%rax, 8(%rsp)
	je	.L60
	.p2align 4,,10
	.p2align 3
.L169:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, 8(%rsp)
	jne	.L169
.L60:
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L71
	call	_ZdlPv
.L71:
	movq	%r12, %rdi
	call	_ZdlPv
	cmpq	$0, 16(%rsp)
	je	.L45
	movq	16(%rsp), %r12
	jmp	.L176
.L45:
	movq	48(%rsp), %rax
	movq	48(%rsp), %rdx
	movq	16(%rax), %rax
	addq	$40, %rdx
	movq	%rdx, 16(%rsp)
	movq	%rax, 8(%rsp)
	movq	48(%rsp), %rax
	movq	48(%rax), %r12
	movq	40(%rax), %rbx
	cmpq	%rbx, %r12
	je	.L73
.L168:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	jne	.L168
.L73:
	movq	16(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L84
	call	_ZdlPv
.L84:
	movq	48(%rsp), %rdi
	call	_ZdlPv
	cmpq	$0, 8(%rsp)
	je	.L44
	movq	8(%rsp), %rax
	movq	%rax, 48(%rsp)
	jmp	.L175
.L44:
	movq	40(%rsp), %rax
	movq	40(%rsp), %rdx
	movq	16(%rax), %rax
	movq	48(%rdx), %r12
	movq	40(%rdx), %rbx
	movq	%rax, 8(%rsp)
	movq	40(%rsp), %rax
	addq	$40, %rax
	cmpq	%rbx, %r12
	je	.L86
.L167:
	movq	%rbx, %rdi
	addq	$40, %rbx
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	movq	(%rsp), %rax
	jne	.L167
.L86:
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L97
	call	_ZdlPv
.L97:
	movq	40(%rsp), %rdi
	call	_ZdlPv
	movq	8(%rsp), %rax
	movq	%rax, 40(%rsp)
	jmp	.L43
.L183:
	movq	32(%rsp), %rdx
	movq	%rdx, %rax
	movq	16(%rdx), %r12
	movq	48(%rdx), %rdx
	addq	$40, %rax
	movq	%rdx, 8(%rsp)
	movq	32(%rsp), %rdx
	movq	40(%rdx), %rbx
	jmp	.L99
.L102:
	movq	%rbx, %rdi
	movq	%rax, (%rsp)
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
.L99:
	cmpq	%rbx, 8(%rsp)
	jne	.L102
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L110
	call	_ZdlPv
.L110:
	movq	32(%rsp), %rdi
	call	_ZdlPv
	movq	%r12, 32(%rsp)
	jmp	.L42
.L182:
	movq	48(%r15), %rdx
	movq	16(%r15), %r12
	leaq	40(%r15), %rax
	movq	40(%r15), %rbx
	movq	%rdx, 8(%rsp)
.L112:
	cmpq	%rbx, 8(%rsp)
	je	.L184
	movq	%rbx, %rdi
	movq	%rax, (%rsp)
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
	jmp	.L112
.L184:
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L123
	call	_ZdlPv
.L123:
	movq	%r15, %rdi
	movq	%r12, %r15
	call	_ZdlPv
	jmp	.L41
.L181:
	movq	48(%r14), %rax
	movq	16(%r14), %r12
	leaq	40(%r14), %r15
	movq	40(%r14), %rbx
	movq	%rax, 8(%rsp)
.L125:
	cmpq	%rbx, 8(%rsp)
	je	.L185
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L125
.L180:
	movq	16(%r13), %r12
	movq	48(%r13), %r15
	leaq	40(%r13), %r14
	movq	40(%r13), %rbx
.L138:
	cmpq	%rbx, %r15
	je	.L186
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L138
.L185:
	movq	(%r15), %rdi
	testq	%rdi, %rdi
	je	.L136
	.p2align 4,,5
	call	_ZdlPv
.L136:
	movq	%r14, %rdi
	movq	%r12, %r14
	call	_ZdlPv
	jmp	.L40
.L186:
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L149
	.p2align 4,,5
	call	_ZdlPv
.L149:
	movq	%r13, %rdi
	movq	%r12, %r13
	call	_ZdlPv
	jmp	.L39
.L179:
	movq	56(%rsp), %rdx
	movq	16(%rdx), %r12
	movq	48(%rdx), %r14
	movq	%rdx, %r13
	movq	40(%rdx), %rbx
	addq	$40, %r13
.L151:
	cmpq	%rbx, %r14
	je	.L187
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L151
.L178:
	addq	$72, %rsp
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
.L187:
	.cfi_restore_state
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L162
	call	_ZdlPv
.L162:
	movq	56(%rsp), %rdi
	call	_ZdlPv
	movq	%r12, 56(%rsp)
	jmp	.L38
	.cfi_endproc
.LFE3660:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev:
.LFB3605:
	.cfi_startproc
	movq	16(%rdi), %rsi
	jmp	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	.cfi_endproc
.LFE3605:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED2Ev
	.section	.text._ZN3fem11BaseElementIdED2Ev,"axG",@progbits,_ZN3fem11BaseElementIdED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem11BaseElementIdED2Ev
	.type	_ZN3fem11BaseElementIdED2Ev, @function
_ZN3fem11BaseElementIdED2Ev:
.LFB3570:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3570
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rdi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rdi)
	movq	192(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L198
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	call	_ZdlPv
.L198:
	movq	160(%r12), %rdi
	testq	%rdi, %rdi
	je	.L203
	call	_ZdlPv
.L203:
	movq	136(%r12), %rdi
	testq	%rdi, %rdi
	je	.L208
	call	_ZdlPv
.L208:
	movq	112(%r12), %rdi
	testq	%rdi, %rdi
	je	.L213
	call	_ZdlPv
.L213:
	movq	88(%r12), %rdi
	testq	%rdi, %rdi
	je	.L218
	call	_ZdlPv
.L218:
	movq	72(%r12), %rbp
	movq	64(%r12), %rbx
	cmpq	%rbx, %rbp
	je	.L219
	.p2align 4,,10
	.p2align 3
.L239:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB13:
	call	*(%rax)
.LEHE13:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L239
.L219:
	movq	64(%r12), %rdi
	testq	%rdi, %rdi
	je	.L231
	call	_ZdlPv
.L231:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	32(%r12), %rsi
	leaq	16(%r12), %rdi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
.L238:
	.cfi_restore_state
	movq	64(%r12), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L226
	call	_ZdlPv
.L226:
	leaq	16(%r12), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
.LEHB14:
	call	_Unwind_Resume
.LEHE14:
	.cfi_endproc
.LFE3570:
	.size	_ZN3fem11BaseElementIdED2Ev, .-_ZN3fem11BaseElementIdED2Ev
	.section	.gcc_except_table
.LLSDA3570:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3570-.LLSDACSB3570
.LLSDACSB3570:
	.uleb128 .LEHB13-.LFB3570
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L238-.LFB3570
	.uleb128 0x0
	.uleb128 .LEHB14-.LFB3570
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3570:
	.section	.text._ZN3fem11BaseElementIdED2Ev,"axG",@progbits,_ZN3fem11BaseElementIdED5Ev,comdat
	.weak	_ZN3fem11BaseElementIdED1Ev
	.set	_ZN3fem11BaseElementIdED1Ev,_ZN3fem11BaseElementIdED2Ev
	.section	.text._ZN3fem12Tetrahedron4IdED2Ev,"axG",@progbits,_ZN3fem12Tetrahedron4IdED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdED2Ev
	.type	_ZN3fem12Tetrahedron4IdED2Ev, @function
_ZN3fem12Tetrahedron4IdED2Ev:
.LFB3538:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3538
	pushq	%r12
	.cfi_def_cfa_offset 16
	movq	%rdi, %r12
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rdi)
	movq	192(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L246
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	call	_ZdlPv
.L246:
	movq	160(%r12), %rdi
	testq	%rdi, %rdi
	je	.L251
	call	_ZdlPv
.L251:
	movq	136(%r12), %rdi
	testq	%rdi, %rdi
	je	.L256
	call	_ZdlPv
.L256:
	movq	112(%r12), %rdi
	testq	%rdi, %rdi
	je	.L261
	call	_ZdlPv
.L261:
	movq	88(%r12), %rdi
	testq	%rdi, %rdi
	je	.L266
	call	_ZdlPv
.L266:
	movq	72(%r12), %rbp
	movq	64(%r12), %rbx
	cmpq	%rbx, %rbp
	je	.L267
	.p2align 4,,10
	.p2align 3
.L289:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB15:
	call	*(%rax)
.LEHE15:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L289
.L267:
	movq	64(%r12), %rdi
	testq	%rdi, %rdi
	je	.L279
	call	_ZdlPv
.L279:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	32(%r12), %rsi
	leaq	16(%r12), %rdi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
.L288:
	.cfi_restore_state
	movq	64(%r12), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L274
	call	_ZdlPv
.L274:
	leaq	16(%r12), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
.LEHB16:
	call	_Unwind_Resume
.LEHE16:
	.cfi_endproc
.LFE3538:
	.size	_ZN3fem12Tetrahedron4IdED2Ev, .-_ZN3fem12Tetrahedron4IdED2Ev
	.section	.gcc_except_table
.LLSDA3538:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3538-.LLSDACSB3538
.LLSDACSB3538:
	.uleb128 .LEHB15-.LFB3538
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L288-.LFB3538
	.uleb128 0x0
	.uleb128 .LEHB16-.LFB3538
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3538:
	.section	.text._ZN3fem12Tetrahedron4IdED2Ev,"axG",@progbits,_ZN3fem12Tetrahedron4IdED5Ev,comdat
	.weak	_ZN3fem12Tetrahedron4IdED1Ev
	.set	_ZN3fem12Tetrahedron4IdED1Ev,_ZN3fem12Tetrahedron4IdED2Ev
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"vector::_M_fill_insert"
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
	.type	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_, @function
_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_:
.LFB3689:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3689
	pushq	%r15
	.cfi_def_cfa_offset 16
	movq	%rdi, %r15
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	movq	%rcx, %r14
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rsi, %r13
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rsi, %rbp
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$184, %rsp
	.cfi_def_cfa_offset 240
	testq	%rdx, %rdx
	movq	%rdx, 8(%rsp)
	je	.L291
	.cfi_offset 3, -56
	movq	8(%rdi), %rdx
	movq	16(%rdi), %rax
	subq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, 8(%rsp)
	jbe	.L389
	movq	(%rdi), %rcx
	movq	%rdx, %rax
	movabsq	$576460752303423487, %rsi
	movq	%rsi, %rdx
	subq	%rcx, %rax
	sarq	$5, %rax
	subq	%rax, %rdx
	cmpq	%rdx, 8(%rsp)
	ja	.L390
	cmpq	8(%rsp), %rax
	movq	8(%rsp), %rdx
	cmovae	%rax, %rdx
	addq	%rax, %rdx
	movq	%rdx, 32(%rsp)
	jb	.L325
	cmpq	%rsi, %rdx
	jbe	.L391
.L325:
	movq	%r13, %rax
	movq	$-32, %rdi
	subq	%rcx, %rax
	sarq	$5, %rax
	movq	%rax, 24(%rsp)
	movabsq	$576460752303423487, %rax
	movq	%rax, 32(%rsp)
.L362:
.LEHB17:
	call	_Znwm
.LEHE17:
	movq	%rax, 16(%rsp)
.L326:
	movq	24(%rsp), %rax
	movq	8(%rsp), %r12
	salq	$5, %rax
	addq	16(%rsp), %rax
	movq	%rax, 40(%rsp)
	movq	%rax, %rbx
	jmp	.L329
	.p2align 4,,10
	.p2align 3
.L392:
	addq	$32, %rbx
.L329:
	testq	%rbx, %rbx
	je	.L327
	movq	%r14, %rsi
	movq	%rbx, %rdi
.LEHB18:
	call	_ZN3fem5pointC1ERKS0_
.LEHE18:
.L327:
	subq	$1, %r12
	jne	.L392
	movq	(%r15), %r12
	cmpq	%r13, %r12
	je	.L364
	movq	16(%rsp), %rbx
	.p2align 4,,10
	.p2align 3
.L337:
	testq	%rbx, %rbx
	je	.L336
	movq	%r12, %rsi
	movq	%rbx, %rdi
.LEHB19:
	call	_ZN3fem5pointC1ERKS0_
.LEHE19:
.L336:
	addq	$32, %r12
	addq	$32, %rbx
	cmpq	%r12, %r13
	jne	.L337
.L335:
	movq	8(%rsp), %r14
	movq	8(%r15), %r12
	salq	$5, %r14
	cmpq	%r13, %r12
	leaq	(%rbx,%r14), %r14
	movq	%r14, %rbx
	je	.L339
	.p2align 4,,10
	.p2align 3
.L382:
	testq	%rbx, %rbx
	je	.L345
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB20:
	call	_ZN3fem5pointC1ERKS0_
.LEHE20:
.L345:
	addq	$32, %rbp
	addq	$32, %rbx
	cmpq	%rbp, %r12
	jne	.L382
	movq	8(%r15), %r12
.L339:
	movq	(%r15), %rbp
	cmpq	%r12, %rbp
	je	.L348
	.p2align 4,,10
	.p2align 3
.L381:
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
	addq	$32, %rbp
.LEHB21:
	call	*(%rax)
	cmpq	%r12, %rbp
	jne	.L381
	movq	(%r15), %rbp
.L348:
	testq	%rbp, %rbp
	je	.L354
	movq	%rbp, %rdi
	call	_ZdlPv
.L354:
	movq	16(%rsp), %rax
	movq	%rbx, 8(%r15)
	movq	%rax, (%r15)
	movq	32(%rsp), %rax
	salq	$5, %rax
	addq	16(%rsp), %rax
	movq	%rax, 16(%r15)
.L291:
	addq	$184, %rsp
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
	.p2align 4,,10
	.p2align 3
.L389:
	.cfi_restore_state
	leaq	144(%rsp), %rdi
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKS0_
.LEHE21:
	movq	8(%r15), %r14
	movq	%r14, %rax
	subq	%r13, %rax
	sarq	$5, %rax
	cmpq	%rax, 8(%rsp)
	movq	%rax, 16(%rsp)
	jae	.L294
	movq	8(%rsp), %rdx
	movq	%r14, %rax
	salq	$5, %rdx
	subq	%rdx, %rax
	movq	%rdx, 16(%rsp)
	cmpq	%rax, %r14
	movq	%rax, 8(%rsp)
	je	.L295
	movq	%rax, %r12
	movq	%r14, %rbx
	jmp	.L297
	.p2align 4,,10
	.p2align 3
.L393:
	addq	$32, %rbx
.L297:
	testq	%rbx, %rbx
	je	.L296
	movq	%r12, %rsi
	movq	%rbx, %rdi
.LEHB22:
	call	_ZN3fem5pointC1ERKS0_
.LEHE22:
.L296:
	addq	$32, %r12
	cmpq	%r12, %r14
	jne	.L393
.L295:
	movq	8(%rsp), %rbx
	movq	16(%rsp), %rdx
	addq	%rdx, 8(%r15)
	subq	%r13, %rbx
	sarq	$5, %rbx
	testq	%rbx, %rbx
	jle	.L299
	.p2align 4,,10
	.p2align 3
.L380:
	subq	$32, 8(%rsp)
	subq	$32, %r14
	leaq	112(%rsp), %rdi
	movq	8(%rsp), %rdx
	movq	%r14, %rsi
.LEHB23:
	call	_ZN3fem5pointaSERKS0_
	leaq	112(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	subq	$1, %rbx
	testq	%rbx, %rbx
	jg	.L380
.L299:
	movq	16(%rsp), %rbx
	leaq	0(%r13,%rbx), %rbx
	cmpq	%r13, %rbx
	je	.L306
	.p2align 4,,10
	.p2align 3
.L307:
	leaq	144(%rsp), %rdx
	leaq	80(%rsp), %rdi
	movq	%rbp, %rsi
	call	_ZN3fem5pointaSERKS0_
	leaq	80(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE23:
	addq	$32, %rbp
	cmpq	%rbp, %rbx
	jne	.L307
.L306:
	leaq	144(%rsp), %rdi
.LEHB24:
	call	_ZN3fem5pointD1Ev
.LEHE24:
	jmp	.L291
	.p2align 4,,10
	.p2align 3
.L391:
	movq	%r13, %rdx
	subq	%rcx, %rdx
	sarq	$5, %rdx
	cmpq	$0, 32(%rsp)
	movq	%rdx, 24(%rsp)
	jne	.L394
	movq	$0, 16(%rsp)
	jmp	.L326
.L294:
	movq	8(%rsp), %rax
	subq	16(%rsp), %rax
	movq	%rax, 8(%rsp)
	je	.L308
	movq	%rax, %r12
	movq	%r14, %rbx
	jmp	.L310
	.p2align 4,,10
	.p2align 3
.L395:
	addq	$32, %rbx
.L310:
	testq	%rbx, %rbx
	je	.L309
	leaq	144(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB25:
	call	_ZN3fem5pointC1ERKS0_
.LEHE25:
.L309:
	subq	$1, %r12
	jne	.L395
.L308:
	movq	8(%rsp), %r12
	salq	$5, %r12
	addq	8(%r15), %r12
	cmpq	%r13, %r14
	movq	%r12, 8(%r15)
	je	.L315
	movq	%r12, %rbx
	jmp	.L318
	.p2align 4,,10
	.p2align 3
.L396:
	addq	$32, %rbx
.L318:
	testq	%rbx, %rbx
	je	.L316
	movq	%r13, %rsi
	movq	%rbx, %rdi
.LEHB26:
	call	_ZN3fem5pointC1ERKS0_
.LEHE26:
.L316:
	addq	$32, %r13
	cmpq	%r13, %r14
	jne	.L396
	movq	16(%rsp), %rax
	salq	$5, %rax
	addq	%rax, 8(%r15)
	.p2align 4,,10
	.p2align 3
.L319:
	leaq	144(%rsp), %rdx
	leaq	48(%rsp), %rdi
	movq	%rbp, %rsi
.LEHB27:
	call	_ZN3fem5pointaSERKS0_
	leaq	48(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE27:
	addq	$32, %rbp
	cmpq	%rbp, %r14
	jne	.L319
	jmp	.L306
.L364:
	movq	16(%rsp), %rbx
	jmp	.L335
.L315:
	movq	16(%rsp), %rax
	salq	$5, %rax
	leaq	(%r12,%rax), %rax
	movq	%rax, 8(%r15)
	jmp	.L306
.L372:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L322:
	cmpq	%rbx, %r12
	je	.L397
	movq	(%r12), %rax
	movq	%r12, %rdi
.LEHB28:
	call	*(%rax)
.LEHE28:
	addq	$32, %r12
	jmp	.L322
.L370:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L313:
	cmpq	%r14, %rbx
	je	.L398
	movq	(%r14), %rax
	movq	%r14, %rdi
.LEHB29:
	call	*(%rax)
.LEHE29:
	addq	$32, %r14
	jmp	.L313
.L365:
	movq	%rax, %rbx
.L301:
	leaq	144(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB30:
	call	_Unwind_Resume
.LEHE30:
.L369:
	movq	%rax, %rbx
	call	__cxa_end_catch
	jmp	.L301
.L398:
	.p2align 4,,5
.LEHB31:
	call	__cxa_rethrow
.LEHE31:
.L376:
	movq	%rax, %rdi
	.p2align 4,,5
	call	__cxa_begin_catch
	movq	16(%rsp), %rbp
.L343:
	cmpq	%rbp, %rbx
	je	.L399
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB32:
	call	*(%rax)
.LEHE32:
	addq	$32, %rbp
	jmp	.L343
.L378:
	movq	%rax, %rdi
	movq	%r14, %rbp
	call	__cxa_begin_catch
.L351:
	cmpq	%rbp, %rbx
	je	.L400
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB33:
	call	*(%rax)
.LEHE33:
	addq	$32, %rbp
	jmp	.L351
.L375:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
.L341:
	movq	24(%rsp), %rbx
	addq	8(%rsp), %rbx
	salq	$5, %rbx
	addq	16(%rsp), %rbx
.L357:
	cmpq	40(%rsp), %rbx
	je	.L359
	movq	40(%rsp), %rdx
	movq	(%rdx), %rax
	movq	%rdx, %rdi
.LEHB34:
	call	*(%rax)
.LEHE34:
	addq	$32, 40(%rsp)
	jmp	.L357
.L399:
.LEHB35:
	call	__cxa_rethrow
.LEHE35:
.L366:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB36:
	call	_Unwind_Resume
.LEHE36:
.L359:
	cmpq	$0, 16(%rsp)
	je	.L361
	movq	16(%rsp), %rdi
	call	_ZdlPv
.L361:
.LEHB37:
	call	__cxa_rethrow
.LEHE37:
.L394:
	movq	32(%rsp), %rdi
	salq	$5, %rdi
	jmp	.L362
.L368:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L303:
	cmpq	%rbx, %r14
	je	.L401
	movq	(%r14), %rax
	movq	%r14, %rdi
.LEHB38:
	call	*(%rax)
.LEHE38:
	addq	$32, %r14
	jmp	.L303
.L371:
	movq	%rax, %rbx
	call	__cxa_end_catch
	jmp	.L301
.L397:
	.p2align 4,,5
.LEHB39:
	call	__cxa_rethrow
.LEHE39:
.L367:
	movq	%rax, %rbx
	.p2align 4,,5
	call	__cxa_end_catch
	.p2align 4,,2
	jmp	.L301
.L401:
	.p2align 4,,5
.LEHB40:
	call	__cxa_rethrow
.LEHE40:
.L374:
	movq	%rax, %rdi
	.p2align 4,,5
	call	__cxa_begin_catch
	movq	40(%rsp), %rbp
.L333:
	cmpq	%rbp, %rbx
	je	.L402
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB41:
	call	*(%rax)
.LEHE41:
	addq	$32, %rbp
	jmp	.L333
.L390:
	movl	$.LC3, %edi
.LEHB42:
	call	_ZSt20__throw_length_errorPKc
.LEHE42:
.L373:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	16(%rsp), %r14
	movq	%rbx, %rdi
.L331:
	call	__cxa_begin_catch
	testq	%r14, %r14
	je	.L341
	movq	16(%rsp), %rbx
.L356:
	cmpq	%rbx, %r14
	je	.L359
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB43:
	call	*(%rax)
.LEHE43:
	addq	$32, %rbx
	jmp	.L356
.L402:
.LEHB44:
	call	__cxa_rethrow
.LEHE44:
.L377:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	jmp	.L331
.L400:
.LEHB45:
	call	__cxa_rethrow
.LEHE45:
	.cfi_endproc
.LFE3689:
	.size	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_, .-_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
	.section	.gcc_except_table
	.align 4
.LLSDA3689:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3689-.LLSDATTD3689
.LLSDATTD3689:
	.byte	0x1
	.uleb128 .LLSDACSE3689-.LLSDACSB3689
.LLSDACSB3689:
	.uleb128 .LEHB17-.LFB3689
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB18-.LFB3689
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L374-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB19-.LFB3689
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L376-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB20-.LFB3689
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L378-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB21-.LFB3689
	.uleb128 .LEHE21-.LEHB21
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB22-.LFB3689
	.uleb128 .LEHE22-.LEHB22
	.uleb128 .L368-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB23-.LFB3689
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L365-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB24-.LFB3689
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB25-.LFB3689
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L370-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB26-.LFB3689
	.uleb128 .LEHE26-.LEHB26
	.uleb128 .L372-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB27-.LFB3689
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L365-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB28-.LFB3689
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L371-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB29-.LFB3689
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L369-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB30-.LFB3689
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB31-.LFB3689
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L369-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB32-.LFB3689
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L375-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB33-.LFB3689
	.uleb128 .LEHE33-.LEHB33
	.uleb128 .L377-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB34-.LFB3689
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L366-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB35-.LFB3689
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L375-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB36-.LFB3689
	.uleb128 .LEHE36-.LEHB36
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB37-.LFB3689
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L366-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB38-.LFB3689
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L367-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB39-.LFB3689
	.uleb128 .LEHE39-.LEHB39
	.uleb128 .L371-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB40-.LFB3689
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L367-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB41-.LFB3689
	.uleb128 .LEHE41-.LEHB41
	.uleb128 .L373-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB42-.LFB3689
	.uleb128 .LEHE42-.LEHB42
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB43-.LFB3689
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L366-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB44-.LFB3689
	.uleb128 .LEHE44-.LEHB44
	.uleb128 .L373-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB45-.LFB3689
	.uleb128 .LEHE45-.LEHB45
	.uleb128 .L377-.LFB3689
	.uleb128 0x3
.LLSDACSE3689:
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT3689:
	.section	.text._ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,"axG",@progbits,_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_,comdat
	.section	.text._ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd,"axG",@progbits,_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	.type	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd, @function
_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd:
.LFB3693:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	movq	%rsi, %r12
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbp
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rdx, %rbx
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	testq	%rdx, %rdx
	je	.L403
	movq	8(%rdi), %r13
	movq	16(%rdi), %rax
	subq	%r13, %rax
	sarq	$3, %rax
	cmpq	%rax, %rdx
	ja	.L405
	movq	%r13, %r9
	movsd	(%rcx), %xmm0
	subq	%rsi, %r9
	sarq	$3, %r9
	cmpq	%r9, %rdx
	jb	.L460
	subq	%r9, %rbx
	je	.L413
	movq	%r13, %rax
	andl	$15, %eax
	shrq	$3, %rax
	cmpq	%rbx, %rax
	cmova	%rbx, %rax
	testq	%rax, %rax
	je	.L441
	cmpq	%rax, %rbx
	movsd	%xmm0, 0(%r13)
	leaq	-1(%rbx), %rdx
	leaq	8(%r13), %rcx
	je	.L413
.L414:
	movq	%rbx, %r11
	subq	%rax, %r11
	movq	%r11, %rdi
	shrq	%rdi
	movq	%rdi, %r10
	addq	%r10, %r10
	je	.L449
	movapd	%xmm0, %xmm2
	leaq	0(%r13,%rax,8), %r8
	xorl	%eax, %eax
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L417:
	movq	%rax, %rsi
	addq	$1, %rax
	salq	$4, %rsi
	cmpq	%rax, %rdi
	movapd	%xmm1, (%r8,%rsi)
	ja	.L417
	subq	%r10, %rdx
	cmpq	%r10, %r11
	leaq	(%rcx,%r10,8), %rcx
	je	.L413
	.p2align 4,,10
	.p2align 3
.L449:
	movsd	%xmm0, (%rcx)
	addq	$8, %rcx
	subq	$1, %rdx
	jne	.L449
.L413:
	leaq	0(%r13,%rbx,8), %rdi
	xorl	%ebx, %ebx
	testq	%r9, %r9
	movq	%rdi, 8(%rbp)
	jne	.L461
.L421:
	addq	%rbx, %rdi
	cmpq	%r12, %r13
	movq	%rdi, 8(%rbp)
	je	.L403
	leaq	8(%r12), %rax
	movq	%r13, %rcx
	movq	%r12, %rdx
	andl	$15, %edx
	subq	%rax, %rcx
	shrq	$3, %rdx
	shrq	$3, %rcx
	addq	$1, %rcx
	cmpq	%rcx, %rdx
	cmova	%rcx, %rdx
	testq	%rdx, %rdx
	je	.L442
	cmpq	%rdx, %rcx
	movsd	%xmm0, (%r12)
	je	.L403
.L422:
	movq	%rcx, %r9
	subq	%rdx, %r9
	movq	%r9, %rsi
	shrq	%rsi
	movq	%rsi, %r8
	addq	%r8, %r8
	je	.L448
	movapd	%xmm0, %xmm2
	leaq	(%r12,%rdx,8), %rdi
	xorl	%edx, %edx
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L424:
	movq	%rdx, %rcx
	addq	$1, %rdx
	salq	$4, %rcx
	cmpq	%rdx, %rsi
	movapd	%xmm1, (%rdi,%rcx)
	ja	.L424
	cmpq	%r8, %r9
	leaq	(%rax,%r8,8), %rax
	je	.L403
	.p2align 4,,10
	.p2align 3
.L448:
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %r13
	jne	.L448
.L403:
	addq	$24, %rsp
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
	.p2align 4,,10
	.p2align 3
.L405:
	.cfi_restore_state
	movq	(%rdi), %rsi
	movabsq	$2305843009213693951, %rax
	movq	%rax, %rdx
	subq	%rsi, %r13
	sarq	$3, %r13
	subq	%r13, %rdx
	cmpq	%rdx, %rbx
	ja	.L462
	cmpq	%rbx, %r13
	movq	%rbx, %r15
	cmovae	%r13, %r15
	addq	%r15, %r13
	jb	.L427
	cmpq	%rax, %r13
	ja	.L427
	movq	%r12, %r14
	subq	%rsi, %r14
	sarq	$3, %r14
	testq	%r13, %r13
	jne	.L463
	xorl	%r15d, %r15d
	xorl	%r13d, %r13d
.L428:
	leaq	0(%r13,%r14,8), %rax
	movsd	(%rcx), %xmm0
	movq	%rax, %rdi
	andl	$15, %edi
	shrq	$3, %rdi
	cmpq	%rbx, %rdi
	cmova	%rbx, %rdi
	testq	%rdi, %rdi
	je	.L444
	cmpq	%rdi, %rbx
	movsd	%xmm0, (%rax)
	leaq	-1(%rbx), %rdx
	leaq	8(%rax), %rcx
	je	.L430
.L429:
	movq	%rbx, %r11
	subq	%rdi, %r11
	movq	%r11, %r8
	shrq	%r8
	movq	%r8, %r10
	addq	%r10, %r10
	je	.L450
	movapd	%xmm0, %xmm2
	leaq	(%rax,%rdi,8), %r9
	xorl	%eax, %eax
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L432:
	movq	%rax, %rdi
	addq	$1, %rax
	salq	$4, %rdi
	cmpq	%rax, %r8
	movapd	%xmm1, (%r9,%rdi)
	ja	.L432
	subq	%r10, %rdx
	cmpq	%r10, %r11
	leaq	(%rcx,%r10,8), %rcx
	je	.L430
	.p2align 4,,10
	.p2align 3
.L450:
	movsd	%xmm0, (%rcx)
	addq	$8, %rcx
	subq	$1, %rdx
	jne	.L450
.L430:
	movq	%r12, %rax
	xorl	%r14d, %r14d
	subq	%rsi, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L464
.L435:
	movq	8(%rbp), %rax
	leaq	0(%r13,%r14), %r14
	leaq	(%r14,%rbx,8), %r14
	xorl	%ebx, %ebx
	subq	%r12, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L465
.L436:
	movq	0(%rbp), %rdi
	leaq	(%r14,%rbx), %rbx
	testq	%rdi, %rdi
	je	.L437
	call	_ZdlPv
.L437:
	movq	%r13, 0(%rbp)
	addq	%r15, %r13
	movq	%rbx, 8(%rbp)
	movq	%r13, 16(%rbp)
	addq	$24, %rsp
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
	.p2align 4,,10
	.p2align 3
.L427:
	.cfi_restore_state
	movq	%r12, %r14
	movq	$-8, %r15
	subq	%rsi, %r14
	sarq	$3, %r14
.L438:
	movq	%r15, %rdi
	movq	%rcx, (%rsp)
	call	_Znwm
	movq	0(%rbp), %rsi
	movq	%rax, %r13
	movq	(%rsp), %rcx
	jmp	.L428
	.p2align 4,,10
	.p2align 3
.L465:
	leaq	0(,%rax,8), %rbx
	movq	%r12, %rsi
	movq	%r14, %rdi
	movq	%rbx, %rdx
	call	memmove
	jmp	.L436
	.p2align 4,,10
	.p2align 3
.L464:
	leaq	0(,%rax,8), %r14
	movq	%r13, %rdi
	movq	%r14, %rdx
	call	memmove
	jmp	.L435
	.p2align 4,,10
	.p2align 3
.L461:
	leaq	0(,%r9,8), %rbx
	movq	%r12, %rsi
	movsd	%xmm0, (%rsp)
	movq	%rbx, %rdx
	call	memmove
	movq	8(%rbp), %rdi
	movsd	(%rsp), %xmm0
	jmp	.L421
	.p2align 4,,10
	.p2align 3
.L460:
	salq	$3, %rbx
	movq	%r13, %r14
	movq	%r13, %rax
	movq	%rbx, %rdx
	subq	%rbx, %r14
	sarq	$3, %rdx
	testq	%rdx, %rdx
	je	.L407
	salq	$3, %rdx
	movq	%r14, %rsi
	movq	%r13, %rdi
	movsd	%xmm0, (%rsp)
	call	memmove
	movq	8(%rbp), %rax
	movsd	(%rsp), %xmm0
.L407:
	subq	%r12, %r14
	addq	%rbx, %rax
	sarq	$3, %r14
	movq	%rax, 8(%rbp)
	testq	%r14, %r14
	je	.L408
	leaq	0(,%r14,8), %rdx
	movq	%r13, %rdi
	movq	%r12, %rsi
	movsd	%xmm0, (%rsp)
	subq	%rdx, %rdi
	call	memmove
	movsd	(%rsp), %xmm0
.L408:
	leaq	(%r12,%rbx), %rbx
	cmpq	%r12, %rbx
	je	.L403
	leaq	8(%r12), %rax
	movq	%rbx, %rcx
	movq	%r12, %rdx
	andl	$15, %edx
	subq	%rax, %rcx
	shrq	$3, %rdx
	shrq	$3, %rcx
	addq	$1, %rcx
	cmpq	%rdx, %rcx
	cmovbe	%rcx, %rdx
	testq	%rdx, %rdx
	je	.L440
	cmpq	%rcx, %rdx
	movsd	%xmm0, (%r12)
	je	.L403
.L409:
	movq	%rcx, %r9
	subq	%rdx, %r9
	movq	%r9, %rsi
	shrq	%rsi
	movq	%rsi, %r8
	addq	%r8, %r8
	je	.L447
	movapd	%xmm0, %xmm2
	leaq	(%r12,%rdx,8), %rdi
	xorl	%edx, %edx
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L411:
	movq	%rdx, %rcx
	addq	$1, %rdx
	salq	$4, %rcx
	cmpq	%rdx, %rsi
	movapd	%xmm1, (%rdi,%rcx)
	ja	.L411
	cmpq	%r8, %r9
	leaq	(%rax,%r8,8), %rax
	je	.L403
	.p2align 4,,10
	.p2align 3
.L447:
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %rbx
	je	.L403
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %rbx
	jne	.L447
	jmp	.L403
.L463:
	leaq	0(,%r13,8), %r15
	jmp	.L438
.L462:
	movl	$.LC3, %edi
	call	_ZSt20__throw_length_errorPKc
.L444:
	movq	%rbx, %rdx
	movq	%rax, %rcx
	jmp	.L429
.L440:
	movq	%r12, %rax
	jmp	.L409
.L441:
	movq	%rbx, %rdx
	movq	%r13, %rcx
	jmp	.L414
.L442:
	movq	%r12, %rax
	jmp	.L422
	.cfi_endproc
.LFE3693:
	.size	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd, .-_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_,comdat
	.p2align 4,,15
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_:
.LFB3903:
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
	cmpq	%rsi, %rdi
	je	.L466
	.p2align 4,,10
	.p2align 3
.L471:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L471
.L466:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3903:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_:
.LFB3656:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3656
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
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	cmpq	%rdi, %rsi
	movq	%rsi, 24(%rsp)
	je	.L474
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	movq	8(%rsi), %r12
	movq	(%rsi), %rbx
	movabsq	$-3689348814741910323, %rdi
	movq	0(%r13), %rax
	movq	16(%r13), %rdx
	movq	%r12, %rsi
	subq	%rbx, %rsi
	subq	%rax, %rdx
	sarq	$3, %rsi
	sarq	$3, %rdx
	movq	%rsi, %r14
	imulq	%rdi, %r14
	imulq	%rdi, %rdx
	movq	%r14, %rcx
	cmpq	%rdx, %r14
	ja	.L518
	movq	8(%r13), %r15
	movq	%r15, %rdx
	subq	%rax, %rdx
	sarq	$3, %rdx
	movq	%rdx, %rsi
	imulq	%rdi, %rsi
	cmpq	%rsi, %r14
	ja	.L491
	testq	%r14, %r14
	jle	.L492
	movq	%rax, %rbp
	.p2align 4,,10
	.p2align 3
.L493:
	leaq	64(%rsp), %rdi
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movq	%rax, 8(%rsp)
	movq	%rcx, 16(%rsp)
.LEHB46:
	call	_ZN3fem5pointaSERKS0_
	leaq	64(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	movq	16(%rsp), %rcx
	movq	32(%rbx), %rdx
	addq	$40, %rbx
	movq	8(%rsp), %rax
	subq	$1, %rcx
	movq	%rdx, 32(%rbp)
	addq	$40, %rbp
	testq	%rcx, %rcx
	jg	.L493
	leaq	(%r14,%r14,4), %rdx
	leaq	(%rax,%rdx,8), %rax
.L492:
	cmpq	%rax, %r15
	je	.L494
	.p2align 4,,10
	.p2align 3
.L513:
	movq	%rax, %rdi
	movq	%rax, 8(%rsp)
	call	_ZN3fem5pointD1Ev
	movq	8(%rsp), %rax
	addq	$40, %rax
	cmpq	%rax, %r15
	jne	.L513
.L494:
	movq	0(%r13), %rdx
	leaq	(%r14,%r14,4), %rax
	leaq	(%rdx,%rax,8), %rax
.L489:
	movq	%rax, 8(%r13)
.L474:
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r13, %rax
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
	.p2align 4,,10
	.p2align 3
.L491:
	.cfi_restore_state
	movq	%rdx, %rcx
	leaq	(%rbx,%rdx,8), %rbp
	imulq	%rdi, %rcx
	testq	%rcx, %rcx
	jle	.L498
	.p2align 4,,10
	.p2align 3
.L499:
	leaq	32(%rsp), %rdi
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movq	%rax, 8(%rsp)
	movq	%rcx, 16(%rsp)
	call	_ZN3fem5pointaSERKS0_
	leaq	32(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE46:
	movq	16(%rsp), %rcx
	movq	32(%rbx), %rdx
	addq	$40, %rbx
	movq	8(%rsp), %rax
	subq	$1, %rcx
	movq	%rdx, 32(%rax)
	addq	$40, %rax
	testq	%rcx, %rcx
	jg	.L499
	movq	24(%rsp), %rax
	movq	8(%r13), %r15
	movq	24(%rsp), %rdx
	movq	8(%rax), %r12
	movq	0(%r13), %rax
	movq	%r15, %rbp
	subq	%rax, %rbp
	andq	$-8, %rbp
	addq	(%rdx), %rbp
.L498:
	leaq	(%r14,%r14,4), %rdx
	cmpq	%r12, %rbp
	movq	%r15, %rbx
	leaq	(%rax,%rdx,8), %rax
	jne	.L501
	jmp	.L489
	.p2align 4,,10
	.p2align 3
.L503:
	addq	$40, %rbx
.L501:
	testq	%rbx, %rbx
	je	.L502
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB47:
	call	_ZN3fem5pointC1ERKS0_
.LEHE47:
	movq	32(%rbp), %rax
	movq	%rax, 32(%rbx)
.L502:
	addq	$40, %rbp
	cmpq	%r12, %rbp
	jne	.L503
	jmp	.L494
	.p2align 4,,10
	.p2align 3
.L518:
	testq	%r14, %r14
	je	.L506
	movabsq	$461168601842738790, %rax
	cmpq	%rax, %r14
	ja	.L519
	leaq	0(,%rsi,8), %rdi
.LEHB48:
	call	_Znwm
.LEHE48:
	movq	%rax, %r15
.L476:
	cmpq	%r12, %rbx
	je	.L478
	movq	%r15, %rbp
	jmp	.L480
	.p2align 4,,10
	.p2align 3
.L520:
	addq	$40, %rbp
.L480:
	testq	%rbp, %rbp
	je	.L479
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB49:
	call	_ZN3fem5pointC1ERKS0_
.LEHE49:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L479:
	addq	$40, %rbx
	cmpq	%rbx, %r12
	jne	.L520
.L478:
	movq	8(%r13), %rbp
	movq	0(%r13), %rbx
	cmpq	%rbx, %rbp
	je	.L482
	.p2align 4,,10
	.p2align 3
.L512:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB50:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L512
	movq	0(%r13), %rbx
.L482:
	testq	%rbx, %rbx
	je	.L488
	movq	%rbx, %rdi
	call	_ZdlPv
.L488:
	leaq	(%r14,%r14,4), %rax
	movq	%r15, 0(%r13)
	leaq	(%r15,%rax,8), %rax
	movq	%rax, 16(%r13)
	jmp	.L489
	.p2align 4,,10
	.p2align 3
.L506:
	xorl	%r15d, %r15d
	jmp	.L476
.L519:
	call	_ZSt17__throw_bad_allocv
.LEHE50:
.L511:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbx, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB51:
	call	__cxa_rethrow
.LEHE51:
.L509:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB52:
	call	__cxa_rethrow
.LEHE52:
.L510:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB53:
	call	_Unwind_Resume
.LEHE53:
.L508:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
	movq	%r15, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
.LEHB54:
	call	__cxa_rethrow
.LEHE54:
.L507:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB55:
	call	_Unwind_Resume
.LEHE55:
	.cfi_endproc
.LFE3656:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
	.section	.gcc_except_table
	.align 4
.LLSDA3656:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3656-.LLSDATTD3656
.LLSDATTD3656:
	.byte	0x1
	.uleb128 .LLSDACSE3656-.LLSDACSB3656
.LLSDACSB3656:
	.uleb128 .LEHB46-.LFB3656
	.uleb128 .LEHE46-.LEHB46
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB47-.LFB3656
	.uleb128 .LEHE47-.LEHB47
	.uleb128 .L511-.LFB3656
	.uleb128 0x1
	.uleb128 .LEHB48-.LFB3656
	.uleb128 .LEHE48-.LEHB48
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB49-.LFB3656
	.uleb128 .LEHE49-.LEHB49
	.uleb128 .L509-.LFB3656
	.uleb128 0x1
	.uleb128 .LEHB50-.LFB3656
	.uleb128 .LEHE50-.LEHB50
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB51-.LFB3656
	.uleb128 .LEHE51-.LEHB51
	.uleb128 .L510-.LFB3656
	.uleb128 0x0
	.uleb128 .LEHB52-.LFB3656
	.uleb128 .LEHE52-.LEHB52
	.uleb128 .L508-.LFB3656
	.uleb128 0x3
	.uleb128 .LEHB53-.LFB3656
	.uleb128 .LEHE53-.LEHB53
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB54-.LFB3656
	.uleb128 .LEHE54-.LEHB54
	.uleb128 .L507-.LFB3656
	.uleb128 0x0
	.uleb128 .LEHB55-.LFB3656
	.uleb128 .LEHE55-.LEHB55
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3656:
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT3656:
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_,comdat
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
	.type	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_, @function
_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_:
.LFB3728:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3728
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	movq	%rdi, %r14
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r13
	.cfi_def_cfa_offset 32
	movq	%rsi, %r13
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movq	%rdx, %rbp
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rsi, %rbx
	.cfi_offset 3, -56
	subq	$152, %rsp
	.cfi_def_cfa_offset 208
	movq	8(%rdi), %r12
	cmpq	16(%rdi), %r12
	je	.L522
	testq	%r12, %r12
	je	.L523
	leaq	-40(%r12), %rsi
	movq	%r12, %rdi
.LEHB56:
	call	_ZN3fem5pointC1ERKS0_
	movq	-8(%r12), %rax
	movq	%rax, 32(%r12)
	movq	8(%r14), %r12
.L523:
	addq	$40, %r12
	leaq	32(%rsp), %rdi
	movq	%rbp, %rsi
	movq	%r12, 8(%r14)
	call	_ZN3fem5pointC1ERKS0_
.LEHE56:
	movq	8(%r14), %rbx
	movq	32(%rbp), %rax
	subq	$80, %rbx
	movq	%rax, 64(%rsp)
	movabsq	$-3689348814741910323, %rax
	movq	%rbx, %rbp
	subq	%r13, %rbp
	sarq	$3, %rbp
	imulq	%rax, %rbp
	testq	%rbp, %rbp
	jle	.L524
	.p2align 4,,10
	.p2align 3
.L525:
	subq	$40, %rbx
	leaq	112(%rsp), %rdi
	leaq	40(%rbx), %rsi
	movq	%rbx, %rdx
.LEHB57:
	call	_ZN3fem5pointaSERKS0_
	leaq	112(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	movq	32(%rbx), %rax
	subq	$1, %rbp
	testq	%rbp, %rbp
	movq	%rax, 72(%rbx)
	jg	.L525
.L524:
	leaq	32(%rsp), %rdx
	leaq	80(%rsp), %rdi
	movq	%r13, %rsi
	call	_ZN3fem5pointaSERKS0_
	leaq	80(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE57:
	movq	64(%rsp), %rax
	leaq	32(%rsp), %rdi
	movq	%rax, 32(%r13)
.LEHB58:
	call	_ZN3fem5pointD1Ev
.L521:
	addq	$152, %rsp
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
	.p2align 4,,10
	.p2align 3
.L522:
	.cfi_restore_state
	movq	(%rdi), %rax
	movabsq	$-3689348814741910323, %rdx
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
	testq	%r12, %r12
	je	.L527
	leaq	(%r12,%r12), %rcx
	cmpq	%rcx, %r12
	movq	%rcx, 8(%rsp)
	jbe	.L573
.L528:
	movq	%r13, %r12
	movabsq	$461168601842738790, %rcx
	movq	$-16, %rdi
	subq	%rax, %r12
	movabsq	$-3689348814741910323, %rax
	movq	%rcx, 8(%rsp)
	sarq	$3, %r12
	imulq	%rax, %r12
.L556:
	call	_Znwm
.LEHE58:
	movq	%rax, %r15
.L529:
	leaq	(%r12,%r12,4), %rax
	leaq	(%r15,%rax,8), %rax
	testq	%rax, %rax
	movq	%rax, 16(%rsp)
	je	.L530
	movq	%rbp, %rsi
	movq	%rax, %rdi
.LEHB59:
	call	_ZN3fem5pointC1ERKS0_
.LEHE59:
	movq	32(%rbp), %rax
	movq	16(%rsp), %rdx
	movq	%rax, 32(%rdx)
.L530:
	movq	(%r14), %rbp
	cmpq	%r13, %rbp
	je	.L559
	movq	%r15, %r12
	.p2align 4,,10
	.p2align 3
.L533:
	testq	%r12, %r12
	je	.L532
	movq	%rbp, %rsi
	movq	%r12, %rdi
.LEHB60:
	call	_ZN3fem5pointC1ERKS0_
.LEHE60:
	movq	32(%rbp), %rax
	movq	%rax, 32(%r12)
.L532:
	addq	$40, %rbp
	addq	$40, %r12
	cmpq	%rbp, %r13
	jne	.L533
.L531:
	addq	$40, %r12
	movq	%r12, 24(%rsp)
	movq	8(%r14), %r12
	movq	24(%rsp), %rbp
	cmpq	%r13, %r12
	je	.L535
	.p2align 4,,10
	.p2align 3
.L568:
	testq	%rbp, %rbp
	je	.L539
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB61:
	call	_ZN3fem5pointC1ERKS0_
.LEHE61:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L539:
	addq	$40, %rbx
	addq	$40, %rbp
	cmpq	%rbx, %r12
	jne	.L568
	movq	8(%r14), %r12
.L535:
	movq	(%r14), %rbx
	cmpq	%r12, %rbx
	je	.L542
	.p2align 4,,10
	.p2align 3
.L567:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB62:
	call	_ZN3fem5pointD1Ev
.LEHE62:
	cmpq	%rbx, %r12
	jne	.L567
	movq	(%r14), %rbx
.L542:
	testq	%rbx, %rbx
	je	.L549
	movq	%rbx, %rdi
	call	_ZdlPv
.L549:
	movq	8(%rsp), %rcx
	movq	%r15, (%r14)
	movq	%rbp, 8(%r14)
	leaq	(%rcx,%rcx,4), %rax
	leaq	(%r15,%rax,8), %rax
	movq	%rax, 16(%r14)
	jmp	.L521
	.p2align 4,,10
	.p2align 3
.L527:
	movq	%rsi, %r12
	movq	$1, 8(%rsp)
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
.L557:
	imulq	$40, 8(%rsp), %rdi
	jmp	.L556
	.p2align 4,,10
	.p2align 3
.L559:
	movq	%r15, %r12
	jmp	.L531
.L561:
	movq	%r15, 24(%rsp)
.L544:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	cmpq	$0, 24(%rsp)
	je	.L537
	movq	24(%rsp), %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.L555:
	movq	%r15, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
.LEHB63:
	call	__cxa_rethrow
.LEHE63:
.L573:
	movabsq	$461168601842738790, %rcx
	cmpq	%rcx, 8(%rsp)
	ja	.L528
	movq	%rsi, %r12
	xorl	%r15d, %r15d
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
	cmpq	$0, 8(%rsp)
	je	.L529
	jmp	.L557
.L560:
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	%rbx, %rdi
.LEHB64:
	call	_Unwind_Resume
.LEHE64:
.L566:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	24(%rsp), %rdi
	movq	%rbp, %rsi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB65:
	call	__cxa_rethrow
.LEHE65:
.L564:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r12, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB66:
	call	__cxa_rethrow
.LEHE66:
.L565:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	jmp	.L544
.L563:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
.L537:
	movq	16(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L555
.L562:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB67:
	call	_Unwind_Resume
.LEHE67:
	.cfi_endproc
.LFE3728:
	.size	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_, .-_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
	.section	.gcc_except_table
	.align 4
.LLSDA3728:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3728-.LLSDATTD3728
.LLSDATTD3728:
	.byte	0x1
	.uleb128 .LLSDACSE3728-.LLSDACSB3728
.LLSDACSB3728:
	.uleb128 .LEHB56-.LFB3728
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB57-.LFB3728
	.uleb128 .LEHE57-.LEHB57
	.uleb128 .L560-.LFB3728
	.uleb128 0x0
	.uleb128 .LEHB58-.LFB3728
	.uleb128 .LEHE58-.LEHB58
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB59-.LFB3728
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L561-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB60-.LFB3728
	.uleb128 .LEHE60-.LEHB60
	.uleb128 .L564-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB61-.LFB3728
	.uleb128 .LEHE61-.LEHB61
	.uleb128 .L566-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB62-.LFB3728
	.uleb128 .LEHE62-.LEHB62
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB63-.LFB3728
	.uleb128 .LEHE63-.LEHB63
	.uleb128 .L562-.LFB3728
	.uleb128 0x0
	.uleb128 .LEHB64-.LFB3728
	.uleb128 .LEHE64-.LEHB64
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB65-.LFB3728
	.uleb128 .LEHE65-.LEHB65
	.uleb128 .L565-.LFB3728
	.uleb128 0x3
	.uleb128 .LEHB66-.LFB3728
	.uleb128 .LEHE66-.LEHB66
	.uleb128 .L563-.LFB3728
	.uleb128 0x3
	.uleb128 .LEHB67-.LFB3728
	.uleb128 .LEHE67-.LEHB67
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3728:
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT3728:
	.section	.text._ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,"axG",@progbits,_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_,comdat
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_:
.LFB3921:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3921
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	movq	%rdi, %r14
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movq	%rcx, %rbx
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	testq	%rsi, %rsi
	movq	%rdx, (%rsp)
	movb	$1, 15(%rsp)
	je	.L600
.L575:
	movl	$64, %edi
.LEHB68:
	call	_Znwm
.LEHE68:
	cmpq	$-32, %rax
	movq	%rax, %r13
	je	.L589
	movq	16(%rbx), %rbp
	subq	8(%rbx), %rbp
	movl	(%rbx), %eax
	movq	$0, 40(%r13)
	movq	$0, 48(%r13)
	movq	$0, 56(%r13)
	sarq	$3, %rbp
	movl	%eax, 32(%r13)
	movabsq	$-3689348814741910323, %rax
	imulq	%rbp, %rax
	testq	%rax, %rax
	je	.L593
	movabsq	$461168601842738790, %rdx
	cmpq	%rdx, %rax
	ja	.L601
	salq	$3, %rbp
	movq	%rbp, %rdi
.LEHB69:
	call	_Znwm
.LEHE69:
	movq	%rax, %r15
.L577:
	movq	%r15, 40(%r13)
	movq	%r15, 48(%r13)
	leaq	(%r15,%rbp), %rbp
	movq	16(%rbx), %r12
	movq	8(%rbx), %rbx
	movq	%rbp, 56(%r13)
	cmpq	%rbx, %r12
	je	.L594
	movq	%r15, %rbp
	.p2align 4,,10
	.p2align 3
.L581:
	testq	%rbp, %rbp
	je	.L580
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB70:
	call	_ZN3fem5pointC1ERKS0_
.LEHE70:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L580:
	addq	$40, %rbx
	addq	$40, %rbp
	cmpq	%rbx, %r12
	jne	.L581
.L579:
	movq	%rbp, 48(%r13)
.L589:
	movzbl	15(%rsp), %edi
	movq	(%rsp), %rdx
	leaq	8(%r14), %rcx
	movq	%r13, %rsi
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%r14)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r13, %rax
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
	.p2align 4,,10
	.p2align 3
.L593:
	.cfi_restore_state
	xorl	%ebp, %ebp
	xorl	%r15d, %r15d
	jmp	.L577
.L600:
	leaq	8(%rdi), %rax
	cmpq	%rax, %rdx
	je	.L575
	movl	32(%rdx), %eax
	cmpl	%eax, (%rcx)
	setl	15(%rsp)
	jmp	.L575
.L594:
	movq	%r15, %rbp
	jmp	.L579
.L595:
.L588:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r13, %rdi
	call	_ZdlPv
.LEHB71:
	call	__cxa_rethrow
.LEHE71:
.L601:
.LEHB72:
	call	_ZSt17__throw_bad_allocv
.LEHE72:
.L598:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB73:
	call	__cxa_rethrow
.LEHE73:
.L596:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB74:
	call	_Unwind_Resume
.LEHE74:
.L597:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	40(%r13), %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
	movq	%rbx, %rax
	jmp	.L588
	.cfi_endproc
.LFE3921:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	.section	.gcc_except_table
	.align 4
.LLSDA3921:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3921-.LLSDATTD3921
.LLSDATTD3921:
	.byte	0x1
	.uleb128 .LLSDACSE3921-.LLSDACSB3921
.LLSDACSB3921:
	.uleb128 .LEHB68-.LFB3921
	.uleb128 .LEHE68-.LEHB68
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB69-.LFB3921
	.uleb128 .LEHE69-.LEHB69
	.uleb128 .L595-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB70-.LFB3921
	.uleb128 .LEHE70-.LEHB70
	.uleb128 .L598-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB71-.LFB3921
	.uleb128 .LEHE71-.LEHB71
	.uleb128 .L596-.LFB3921
	.uleb128 0x0
	.uleb128 .LEHB72-.LFB3921
	.uleb128 .LEHE72-.LEHB72
	.uleb128 .L595-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB73-.LFB3921
	.uleb128 .LEHE73-.LEHB73
	.uleb128 .L597-.LFB3921
	.uleb128 0x3
	.uleb128 .LEHB74-.LFB3921
	.uleb128 .LEHE74-.LEHB74
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3921:
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT3921:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_,comdat
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_, @function
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_:
.LFB3834:
	.cfi_startproc
	movq	%r14, -16(%rsp)
	leaq	8(%rdi), %r14
	.cfi_offset 14, -24
	movq	%rbx, -48(%rsp)
	movq	%rbp, -40(%rsp)
	movq	%r13, -24(%rsp)
	movq	%rdi, %rbx
	.cfi_offset 13, -32
	.cfi_offset 6, -48
	.cfi_offset 3, -56
	movq	%r12, -32(%rsp)
	movq	%r15, -8(%rsp)
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rsi, %r14
	movq	%rdx, %r13
	movq	%rsi, %rbp
	je	.L649
	.cfi_offset 15, -16
	.cfi_offset 12, -40
	movl	(%rdx), %r12d
	cmpl	32(%rsi), %r12d
	jge	.L612
	movq	24(%rdi), %r15
	cmpq	%rsi, %r15
	je	.L615
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_decrementPKSt18_Rb_tree_node_base
	cmpl	32(%rax), %r12d
	jle	.L614
	cmpq	$0, 24(%rax)
	je	.L650
.L615:
	movq	%rbp, %rdx
	movq	%rbp, %rsi
	movq	%r13, %rcx
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
.L605:
	movq	%rbp, %rax
	movq	8(%rsp), %rbx
	movq	16(%rsp), %rbp
	movq	24(%rsp), %r12
	movq	32(%rsp), %r13
	movq	40(%rsp), %r14
	movq	48(%rsp), %r15
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L612:
	.cfi_restore_state
	jle	.L605
	cmpq	%rsi, 32(%rdi)
	je	.L647
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	cmpl	32(%rax), %r12d
	jge	.L624
	cmpq	$0, 24(%rbp)
	je	.L647
	movq	%r13, %rcx
	movq	%rax, %rdx
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L605
	.p2align 4,,10
	.p2align 3
.L649:
	cmpq	$0, 40(%rdi)
	je	.L604
	movq	32(%rdi), %rdx
	movl	0(%r13), %eax
	cmpl	%eax, 32(%rdx)
	jl	.L646
.L604:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	je	.L639
	movl	0(%r13), %ecx
	jmp	.L608
	.p2align 4,,10
	.p2align 3
.L652:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %esi
.L607:
	testq	%rax, %rax
	je	.L651
.L608:
	cmpl	32(%rax), %ecx
	jl	.L652
	movq	%rax, %rbp
	xorl	%esi, %esi
	movq	24(%rax), %rax
	jmp	.L607
.L657:
	movq	%r14, %rbp
	.p2align 4,,10
	.p2align 3
.L616:
	cmpq	%rbp, %r15
	je	.L647
.L631:
	movq	%rbp, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbp, %rdx
	movq	%rax, %rbp
.L630:
	cmpl	32(%rbp), %r12d
	jle	.L605
.L646:
	movq	%r13, %rcx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L605
	.p2align 4,,10
	.p2align 3
.L614:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	jne	.L640
	jmp	.L657
	.p2align 4,,10
	.p2align 3
.L654:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %ecx
.L618:
	testq	%rax, %rax
	je	.L653
.L640:
	cmpl	32(%rax), %r12d
	jl	.L654
	movq	%rax, %rbp
	xorl	%ecx, %ecx
	movq	24(%rax), %rax
	jmp	.L618
	.p2align 4,,10
	.p2align 3
.L653:
	testb	%cl, %cl
	movq	%rbp, %rdx
	je	.L630
	jmp	.L616
	.p2align 4,,10
	.p2align 3
.L651:
	testb	%sil, %sil
	movq	%rbp, %rdx
	jne	.L633
.L609:
	cmpl	%ecx, 32(%rbp)
	.p2align 4,,2
	jge	.L605
	.p2align 4,,2
	jmp	.L646
	.p2align 4,,10
	.p2align 3
.L624:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	jne	.L641
	.p2align 4,,4
	jmp	.L658
	.p2align 4,,10
	.p2align 3
.L656:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %ecx
.L628:
	testq	%rax, %rax
	je	.L655
.L641:
	cmpl	32(%rax), %r12d
	jl	.L656
	movq	%rax, %rbp
	xorl	%ecx, %ecx
	movq	24(%rax), %rax
	jmp	.L628
	.p2align 4,,10
	.p2align 3
.L639:
	movq	%r14, %rbp
.L633:
	cmpq	24(%rbx), %rbp
	je	.L647
	movq	%rbp, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbp, %rdx
	movl	0(%r13), %ecx
	movq	%rax, %rbp
	jmp	.L609
	.p2align 4,,10
	.p2align 3
.L650:
	movq	%r13, %rcx
	movq	%rax, %rdx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L605
	.p2align 4,,10
	.p2align 3
.L655:
	testb	%cl, %cl
	movq	%rbp, %rdx
	je	.L630
.L626:
	cmpq	24(%rbx), %rbp
	jne	.L631
	.p2align 4,,10
	.p2align 3
.L647:
	movq	%rbp, %rdx
	movq	%r13, %rcx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L605
.L658:
	movq	%r14, %rbp
	jmp	.L626
	.cfi_endproc
.LFE3834:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_, .-_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
	.section	.text._ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,"axG",@progbits,_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
	.type	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv, @function
_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv:
.LFB3594:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3594
	pushq	%r15
	.cfi_def_cfa_offset 16
	movabsq	$4598175219545276416, %r11
	pushq	%r14
	.cfi_def_cfa_offset 24
	movq	%rdi, %r14
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	movabsq	$4598175219545276416, %rbp
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	pushq	%rbx
	.cfi_def_cfa_offset 56
	movabsq	$4598175219545276416, %rbx
	.cfi_offset 3, -56
	subq	$4200, %rsp
	.cfi_def_cfa_offset 4256
	leaq	4168(%rsp), %rcx
	leaq	4176(%rsp), %rdx
	leaq	4184(%rsp), %rsi
	leaq	3504(%rsp), %rdi
	movq	%rbp, 4184(%rsp)
	movq	$0, 3728(%rsp)
	movq	$0, 3744(%rsp)
	movq	$0, 3736(%rsp)
	leaq	3728(%rsp), %rbp
	movq	%r11, 4168(%rsp)
	movq	%rbx, 4176(%rsp)
.LEHB75:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE75:
	leaq	3504(%rsp), %rsi
	leaq	1984(%rsp), %rdi
.LEHB76:
	call	_ZN3fem5pointC1ERKS0_
.LEHE76:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4595172819793696085, %r10
	movq	%r10, 2016(%rsp)
	je	.L660
	testq	%rbx, %rbx
	je	.L661
	leaq	1984(%rsp), %rsi
	movq	%rbx, %rdi
	leaq	3728(%rsp), %rbp
.LEHB77:
	call	_ZN3fem5pointC1ERKS0_
.LEHE77:
	movq	2016(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L661:
	addq	$40, %rbx
	leaq	3728(%rsp), %rbp
	movq	%rbx, 3736(%rsp)
.L662:
	leaq	1984(%rsp), %rdi
.LEHB78:
	call	_ZN3fem5pointD1Ev
.LEHE78:
	leaq	3504(%rsp), %rdi
.LEHB79:
	call	_ZN3fem5pointD1Ev
	leaq	24(%r14), %r12
	movq	32(%r14), %rax
	movq	%r12, %r13
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1246:
	testq	%rax, %rax
	je	.L665
.L1251:
	movl	32(%rax), %r9d
	testl	%r9d, %r9d
	jle	.L666
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1251
.L665:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L669
	cmpl	$1, 32(%rsi)
	jg	.L669
.L688:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE79:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L693
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L696:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB80:
	call	_ZN3fem5pointD1Ev
.LEHE80:
	cmpq	%rbx, %r15
	jne	.L696
.L693:
	movabsq	$4594147077581179155, %rsi
	movabsq	$4594147077581179155, %rdi
	movq	8(%rsp), %rax
	movq	%rsi, 4144(%rsp)
	movq	%rdi, 4152(%rsp)
	leaq	4144(%rsp), %rcx
	leaq	4152(%rsp), %rdx
	leaq	4160(%rsp), %rsi
	leaq	3472(%rsp), %rdi
	movabsq	$4603448125832034609, %r8
	movq	%rax, 3736(%rsp)
	movq	%r8, 4160(%rsp)
.LEHB81:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE81:
	leaq	3472(%rsp), %rsi
	leaq	1936(%rsp), %rdi
.LEHB82:
	call	_ZN3fem5pointC1ERKS0_
.LEHE82:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %rcx
	movq	%rcx, 1968(%rsp)
	je	.L697
	testq	%rbx, %rbx
	je	.L698
	leaq	1936(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB83:
	call	_ZN3fem5pointC1ERKS0_
.LEHE83:
	movq	1968(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L698:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L699:
	leaq	1936(%rsp), %rdi
.LEHB84:
	call	_ZN3fem5pointD1Ev
.LEHE84:
	leaq	3472(%rsp), %rdi
.LEHB85:
	call	_ZN3fem5pointD1Ev
	movabsq	$4594147077581179155, %rdx
	movabsq	$4594147077581179155, %rax
	leaq	4120(%rsp), %rcx
	movq	%rdx, 4136(%rsp)
	leaq	4136(%rsp), %rsi
	leaq	4128(%rsp), %rdx
	leaq	3440(%rsp), %rdi
	movq	%rax, 4120(%rsp)
	movabsq	$4603448125832034609, %rax
	movq	%rax, 4128(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE85:
	leaq	3440(%rsp), %rsi
	leaq	1888(%rsp), %rdi
.LEHB86:
	call	_ZN3fem5pointC1ERKS0_
.LEHE86:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %rax
	movq	%rax, 1920(%rsp)
	je	.L702
	testq	%rbx, %rbx
	je	.L703
	leaq	1888(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB87:
	call	_ZN3fem5pointC1ERKS0_
.LEHE87:
	movq	1920(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L703:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L704:
	leaq	1888(%rsp), %rdi
.LEHB88:
	call	_ZN3fem5pointD1Ev
.LEHE88:
	leaq	3440(%rsp), %rdi
.LEHB89:
	call	_ZN3fem5pointD1Ev
	movabsq	$4603448125832034609, %rax
	leaq	4096(%rsp), %rcx
	leaq	4104(%rsp), %rdx
	movq	%rax, 4096(%rsp)
	leaq	4112(%rsp), %rsi
	movabsq	$4594147077581179155, %rax
	leaq	3408(%rsp), %rdi
	movq	%rax, 4104(%rsp)
	movabsq	$4594147077581179155, %rax
	movq	%rax, 4112(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE89:
	leaq	3408(%rsp), %rsi
	leaq	1840(%rsp), %rdi
.LEHB90:
	call	_ZN3fem5pointC1ERKS0_
.LEHE90:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %r15
	movq	%r15, 1872(%rsp)
	je	.L707
	testq	%rbx, %rbx
	je	.L708
	leaq	1840(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB91:
	call	_ZN3fem5pointC1ERKS0_
.LEHE91:
	movq	1872(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L708:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L709:
	leaq	1840(%rsp), %rdi
.LEHB92:
	call	_ZN3fem5pointD1Ev
.LEHE92:
	leaq	3408(%rsp), %rdi
.LEHB93:
	call	_ZN3fem5pointD1Ev
	leaq	4072(%rsp), %rcx
	leaq	4080(%rsp), %rdx
	leaq	4088(%rsp), %rsi
	leaq	3376(%rsp), %rdi
	movabsq	$4594147077581179155, %r10
	movabsq	$4594147077581179155, %r11
	movabsq	$4594147077581179155, %rbx
	movq	%r10, 4072(%rsp)
	movq	%r11, 4080(%rsp)
	movq	%rbx, 4088(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE93:
	leaq	3376(%rsp), %rsi
	leaq	1792(%rsp), %rdi
.LEHB94:
	call	_ZN3fem5pointC1ERKS0_
.LEHE94:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %r9
	movq	%r9, 1824(%rsp)
	je	.L712
	testq	%rbx, %rbx
	je	.L713
	leaq	1792(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB95:
	call	_ZN3fem5pointC1ERKS0_
.LEHE95:
	movq	1824(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L713:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L714:
	leaq	1792(%rsp), %rdi
.LEHB96:
	call	_ZN3fem5pointD1Ev
.LEHE96:
	leaq	3376(%rsp), %rdi
.LEHB97:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1247:
	testq	%rax, %rax
	je	.L717
.L1252:
	cmpl	$1, 32(%rax)
	jle	.L718
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1252
.L717:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L721
	cmpl	$2, 32(%rsi)
	jg	.L721
.L740:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE97:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L744
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L747:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB98:
	call	_ZN3fem5pointD1Ev
.LEHE98:
	cmpq	%rbx, %r15
	jne	.L747
.L744:
	movabsq	$4599581327957372809, %rsi
	movabsq	$4592371144199657310, %rdi
	movq	8(%rsp), %rax
	leaq	3696(%rsp), %rcx
	movq	%rsi, 3696(%rsp)
	movq	%rdi, 3704(%rsp)
	leaq	4064(%rsp), %rsi
	leaq	3344(%rsp), %rdi
	movabsq	$4580221611665724992, %r8
	movq	%rcx, %rdx
	movq	%rax, 3736(%rsp)
	movq	%r8, 4064(%rsp)
.LEHB99:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE99:
	leaq	3344(%rsp), %rsi
	leaq	1744(%rsp), %rdi
.LEHB100:
	call	_ZN3fem5pointC1ERKS0_
.LEHE100:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rcx
	movq	%rcx, 1776(%rsp)
	je	.L748
	testq	%rbx, %rbx
	je	.L749
	leaq	1744(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB101:
	call	_ZN3fem5pointC1ERKS0_
.LEHE101:
	movq	1776(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L749:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L750:
	leaq	1744(%rsp), %rdi
.LEHB102:
	call	_ZN3fem5pointD1Ev
.LEHE102:
	leaq	3344(%rsp), %rdi
.LEHB103:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC0(%rip), %xmm1
	leaq	4056(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	3312(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4056(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE103:
	leaq	3312(%rsp), %rsi
	leaq	1696(%rsp), %rdi
.LEHB104:
	call	_ZN3fem5pointC1ERKS0_
.LEHE104:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rdx
	movq	%rdx, 1728(%rsp)
	je	.L753
	testq	%rbx, %rbx
	je	.L754
	leaq	1696(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB105:
	call	_ZN3fem5pointC1ERKS0_
.LEHE105:
	movq	1728(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L754:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L755:
	leaq	1696(%rsp), %rdi
.LEHB106:
	call	_ZN3fem5pointD1Ev
.LEHE106:
	leaq	3312(%rsp), %rdi
.LEHB107:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	4048(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	3280(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4048(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE107:
	leaq	3280(%rsp), %rsi
	leaq	1648(%rsp), %rdi
.LEHB108:
	call	_ZN3fem5pointC1ERKS0_
.LEHE108:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rax
	movq	%rax, 1680(%rsp)
	je	.L758
	testq	%rbx, %rbx
	je	.L759
	leaq	1648(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB109:
	call	_ZN3fem5pointC1ERKS0_
.LEHE109:
	movq	1680(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L759:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L760:
	leaq	1648(%rsp), %rdi
.LEHB110:
	call	_ZN3fem5pointD1Ev
.LEHE110:
	leaq	3280(%rsp), %rdi
.LEHB111:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	3248(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE111:
	leaq	3248(%rsp), %rsi
	leaq	1600(%rsp), %rdi
.LEHB112:
	call	_ZN3fem5pointC1ERKS0_
.LEHE112:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rax
	movq	%rax, 1632(%rsp)
	je	.L763
	testq	%rbx, %rbx
	je	.L764
	leaq	1600(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB113:
	call	_ZN3fem5pointC1ERKS0_
.LEHE113:
	movq	1632(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L764:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L765:
	leaq	1600(%rsp), %rdi
.LEHB114:
	call	_ZN3fem5pointD1Ev
.LEHE114:
	leaq	3248(%rsp), %rdi
.LEHB115:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	4040(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	3216(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4040(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE115:
	leaq	3216(%rsp), %rsi
	leaq	1552(%rsp), %rdi
.LEHB116:
	call	_ZN3fem5pointC1ERKS0_
.LEHE116:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1584(%rsp)
	je	.L768
	testq	%rbx, %rbx
	je	.L769
	leaq	1552(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB117:
	call	_ZN3fem5pointC1ERKS0_
.LEHE117:
	movq	1584(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L769:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L770:
	leaq	1552(%rsp), %rdi
.LEHB118:
	call	_ZN3fem5pointD1Ev
.LEHE118:
	leaq	3216(%rsp), %rdi
.LEHB119:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm1
	leaq	4032(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	3184(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4032(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE119:
	leaq	3184(%rsp), %rsi
	leaq	1504(%rsp), %rdi
.LEHB120:
	call	_ZN3fem5pointC1ERKS0_
.LEHE120:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1536(%rsp)
	je	.L773
	testq	%rbx, %rbx
	je	.L774
	leaq	1504(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB121:
	call	_ZN3fem5pointC1ERKS0_
.LEHE121:
	movq	1536(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L774:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L775:
	leaq	1504(%rsp), %rdi
.LEHB122:
	call	_ZN3fem5pointD1Ev
.LEHE122:
	leaq	3184(%rsp), %rdi
.LEHB123:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm1
	leaq	4024(%rsp), %rcx
	mulsd	3704(%rsp), %xmm0
	leaq	3152(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4024(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE123:
	leaq	3152(%rsp), %rsi
	leaq	1456(%rsp), %rdi
.LEHB124:
	call	_ZN3fem5pointC1ERKS0_
.LEHE124:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1488(%rsp)
	je	.L778
	testq	%rbx, %rbx
	je	.L779
	leaq	1456(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB125:
	call	_ZN3fem5pointC1ERKS0_
.LEHE125:
	movq	1488(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L779:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L780:
	leaq	1456(%rsp), %rdi
.LEHB126:
	call	_ZN3fem5pointD1Ev
.LEHE126:
	leaq	3152(%rsp), %rdi
.LEHB127:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	3120(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE127:
	leaq	3120(%rsp), %rsi
	leaq	1408(%rsp), %rdi
.LEHB128:
	call	_ZN3fem5pointC1ERKS0_
.LEHE128:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1440(%rsp)
	je	.L783
	testq	%rbx, %rbx
	je	.L784
	leaq	1408(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB129:
	call	_ZN3fem5pointC1ERKS0_
.LEHE129:
	movq	1440(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L784:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L785:
	leaq	1408(%rsp), %rdi
.LEHB130:
	call	_ZN3fem5pointD1Ev
.LEHE130:
	leaq	3120(%rsp), %rdi
.LEHB131:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1248:
	testq	%rax, %rax
	je	.L788
.L1253:
	cmpl	$2, 32(%rax)
	jle	.L789
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1253
.L788:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L792
	cmpl	$3, 32(%rsi)
	jg	.L792
.L811:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE131:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L815
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L818:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB132:
	call	_ZN3fem5pointD1Ev
.LEHE132:
	cmpq	%rbx, %r15
	jne	.L818
.L815:
	movq	8(%rsp), %rax
	leaq	3696(%rsp), %rcx
	leaq	4016(%rsp), %rsi
	leaq	3088(%rsp), %rdi
	movabsq	$4591346699683072758, %r10
	movabsq	$4599272042758501659, %r11
	movabsq	$4601859097312869900, %rbx
	movabsq	$4604676564167551972, %r15
	movq	%rcx, %rdx
	movq	%rax, 3736(%rsp)
	movq	%r10, 3696(%rsp)
	movq	%r11, 3704(%rsp)
	movq	%rbx, 3712(%rsp)
	movq	%r15, 4016(%rsp)
.LEHB133:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE133:
	leaq	3088(%rsp), %rsi
	leaq	1360(%rsp), %rdi
.LEHB134:
	call	_ZN3fem5pointC1ERKS0_
.LEHE134:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %r9
	movq	%r9, 1392(%rsp)
	je	.L819
	testq	%rbx, %rbx
	je	.L820
	leaq	1360(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB135:
	call	_ZN3fem5pointC1ERKS0_
.LEHE135:
	movq	1392(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L820:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L821:
	leaq	1360(%rsp), %rdi
.LEHB136:
	call	_ZN3fem5pointD1Ev
.LEHE136:
	leaq	3088(%rsp), %rdi
.LEHB137:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC0(%rip), %xmm1
	leaq	4008(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	3056(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4008(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE137:
	leaq	3056(%rsp), %rsi
	leaq	1312(%rsp), %rdi
.LEHB138:
	call	_ZN3fem5pointC1ERKS0_
.LEHE138:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %r8
	movq	%r8, 1344(%rsp)
	je	.L824
	testq	%rbx, %rbx
	je	.L825
	leaq	1312(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB139:
	call	_ZN3fem5pointC1ERKS0_
.LEHE139:
	movq	1344(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L825:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L826:
	leaq	1312(%rsp), %rdi
.LEHB140:
	call	_ZN3fem5pointD1Ev
.LEHE140:
	leaq	3056(%rsp), %rdi
.LEHB141:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	4000(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	3024(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4000(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE141:
	leaq	3024(%rsp), %rsi
	leaq	1264(%rsp), %rdi
.LEHB142:
	call	_ZN3fem5pointC1ERKS0_
.LEHE142:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %rdi
	movq	%rdi, 1296(%rsp)
	je	.L829
	testq	%rbx, %rbx
	je	.L830
	leaq	1264(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB143:
	call	_ZN3fem5pointC1ERKS0_
.LEHE143:
	movq	1296(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L830:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L831:
	leaq	1264(%rsp), %rdi
.LEHB144:
	call	_ZN3fem5pointD1Ev
.LEHE144:
	leaq	3024(%rsp), %rdi
.LEHB145:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	2992(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE145:
	leaq	2992(%rsp), %rsi
	leaq	1216(%rsp), %rdi
.LEHB146:
	call	_ZN3fem5pointC1ERKS0_
.LEHE146:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %rsi
	movq	%rsi, 1248(%rsp)
	je	.L834
	testq	%rbx, %rbx
	je	.L835
	leaq	1216(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB147:
	call	_ZN3fem5pointC1ERKS0_
.LEHE147:
	movq	1248(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L835:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L836:
	leaq	1216(%rsp), %rdi
.LEHB148:
	call	_ZN3fem5pointD1Ev
.LEHE148:
	leaq	2992(%rsp), %rdi
.LEHB149:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	3992(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	2960(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3992(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE149:
	leaq	2960(%rsp), %rsi
	leaq	1168(%rsp), %rdi
.LEHB150:
	call	_ZN3fem5pointC1ERKS0_
.LEHE150:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rcx
	movq	%rcx, 1200(%rsp)
	je	.L839
	testq	%rbx, %rbx
	je	.L840
	leaq	1168(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB151:
	call	_ZN3fem5pointC1ERKS0_
.LEHE151:
	movq	1200(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L840:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L841:
	leaq	1168(%rsp), %rdi
.LEHB152:
	call	_ZN3fem5pointD1Ev
.LEHE152:
	leaq	2960(%rsp), %rdi
.LEHB153:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm1
	leaq	3984(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	2928(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3984(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE153:
	leaq	2928(%rsp), %rsi
	leaq	1120(%rsp), %rdi
.LEHB154:
	call	_ZN3fem5pointC1ERKS0_
.LEHE154:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rdx
	movq	%rdx, 1152(%rsp)
	je	.L844
	testq	%rbx, %rbx
	je	.L845
	leaq	1120(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB155:
	call	_ZN3fem5pointC1ERKS0_
.LEHE155:
	movq	1152(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L845:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L846:
	leaq	1120(%rsp), %rdi
.LEHB156:
	call	_ZN3fem5pointD1Ev
.LEHE156:
	leaq	2928(%rsp), %rdi
.LEHB157:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm1
	leaq	3976(%rsp), %rcx
	mulsd	3704(%rsp), %xmm0
	leaq	2896(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3976(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE157:
	leaq	2896(%rsp), %rsi
	leaq	1072(%rsp), %rdi
.LEHB158:
	call	_ZN3fem5pointC1ERKS0_
.LEHE158:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rax
	movq	%rax, 1104(%rsp)
	je	.L849
	testq	%rbx, %rbx
	je	.L850
	leaq	1072(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB159:
	call	_ZN3fem5pointC1ERKS0_
.LEHE159:
	movq	1104(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L850:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L851:
	leaq	1072(%rsp), %rdi
.LEHB160:
	call	_ZN3fem5pointD1Ev
.LEHE160:
	leaq	2896(%rsp), %rdi
.LEHB161:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	2864(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE161:
	leaq	2864(%rsp), %rsi
	leaq	1024(%rsp), %rdi
.LEHB162:
	call	_ZN3fem5pointC1ERKS0_
.LEHE162:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rax
	movq	%rax, 1056(%rsp)
	je	.L854
	testq	%rbx, %rbx
	je	.L855
	leaq	1024(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB163:
	call	_ZN3fem5pointC1ERKS0_
.LEHE163:
	movq	1056(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L855:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L856:
	leaq	1024(%rsp), %rdi
.LEHB164:
	call	_ZN3fem5pointD1Ev
.LEHE164:
	leaq	2864(%rsp), %rdi
.LEHB165:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rcx
	leaq	3960(%rsp), %rdx
	leaq	3968(%rsp), %rsi
	leaq	2832(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3960(%rsp)
	movsd	%xmm0, 3968(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE165:
	leaq	2832(%rsp), %rsi
	leaq	976(%rsp), %rdi
.LEHB166:
	call	_ZN3fem5pointC1ERKS0_
.LEHE166:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 1008(%rsp)
	je	.L859
	testq	%rbx, %rbx
	je	.L860
	leaq	976(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB167:
	call	_ZN3fem5pointC1ERKS0_
.LEHE167:
	movq	1008(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L860:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L861:
	leaq	976(%rsp), %rdi
.LEHB168:
	call	_ZN3fem5pointD1Ev
.LEHE168:
	leaq	2832(%rsp), %rdi
.LEHB169:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3944(%rsp), %rcx
	leaq	3952(%rsp), %rsi
	leaq	2800(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3944(%rsp)
	movsd	%xmm0, 3952(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE169:
	leaq	2800(%rsp), %rsi
	leaq	928(%rsp), %rdi
.LEHB170:
	call	_ZN3fem5pointC1ERKS0_
.LEHE170:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 960(%rsp)
	je	.L864
	testq	%rbx, %rbx
	je	.L865
	leaq	928(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB171:
	call	_ZN3fem5pointC1ERKS0_
.LEHE171:
	movq	960(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L865:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L866:
	leaq	928(%rsp), %rdi
.LEHB172:
	call	_ZN3fem5pointD1Ev
.LEHE172:
	leaq	2800(%rsp), %rdi
.LEHB173:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3936(%rsp), %rsi
	leaq	2768(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rdx, %rcx
	movsd	%xmm0, 3936(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE173:
	leaq	2768(%rsp), %rsi
	leaq	880(%rsp), %rdi
.LEHB174:
	call	_ZN3fem5pointC1ERKS0_
.LEHE174:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 912(%rsp)
	je	.L869
	testq	%rbx, %rbx
	je	.L870
	leaq	880(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB175:
	call	_ZN3fem5pointC1ERKS0_
.LEHE175:
	movq	912(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L870:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L871:
	leaq	880(%rsp), %rdi
.LEHB176:
	call	_ZN3fem5pointD1Ev
.LEHE176:
	leaq	2768(%rsp), %rdi
.LEHB177:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3920(%rsp), %rcx
	leaq	3928(%rsp), %rdx
	leaq	2736(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3920(%rsp)
	movsd	%xmm0, 3928(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE177:
	leaq	2736(%rsp), %rsi
	leaq	832(%rsp), %rdi
.LEHB178:
	call	_ZN3fem5pointC1ERKS0_
.LEHE178:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 864(%rsp)
	je	.L874
	testq	%rbx, %rbx
	je	.L875
	leaq	832(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB179:
	call	_ZN3fem5pointC1ERKS0_
.LEHE179:
	movq	864(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L875:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L876:
	leaq	832(%rsp), %rdi
.LEHB180:
	call	_ZN3fem5pointD1Ev
.LEHE180:
	leaq	2736(%rsp), %rdi
.LEHB181:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3912(%rsp), %rdx
	leaq	2704(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rcx
	movsd	%xmm0, 3912(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE181:
	leaq	2704(%rsp), %rsi
	leaq	784(%rsp), %rdi
.LEHB182:
	call	_ZN3fem5pointC1ERKS0_
.LEHE182:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %r15
	movq	%r15, 816(%rsp)
	je	.L879
	testq	%rbx, %rbx
	je	.L880
	leaq	784(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB183:
	call	_ZN3fem5pointC1ERKS0_
.LEHE183:
	movq	816(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L880:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L881:
	leaq	784(%rsp), %rdi
.LEHB184:
	call	_ZN3fem5pointD1Ev
.LEHE184:
	leaq	2704(%rsp), %rdi
.LEHB185:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3904(%rsp), %rcx
	leaq	2672(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rdx
	movsd	%xmm0, 3904(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE185:
	leaq	2672(%rsp), %rsi
	leaq	736(%rsp), %rdi
.LEHB186:
	call	_ZN3fem5pointC1ERKS0_
.LEHE186:
	movabsq	$4574825392535240915, %rbx
	movq	%rbx, 768(%rsp)
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	je	.L884
	testq	%rbx, %rbx
	je	.L885
	leaq	736(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB187:
	call	_ZN3fem5pointC1ERKS0_
.LEHE187:
	movq	768(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L885:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L886:
	leaq	736(%rsp), %rdi
.LEHB188:
	call	_ZN3fem5pointD1Ev
.LEHE188:
	leaq	2672(%rsp), %rdi
.LEHB189:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1249:
	testq	%rax, %rax
	je	.L889
.L1254:
	cmpl	$3, 32(%rax)
	jle	.L890
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1254
.L889:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L893
	cmpl	$4, 32(%rsi)
	jg	.L893
.L912:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE189:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L916
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L919:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB190:
	call	_ZN3fem5pointD1Ev
.LEHE190:
	cmpq	%rbx, %r15
	jne	.L919
.L916:
	movq	8(%rsp), %rax
	leaq	3696(%rsp), %rcx
	leaq	3896(%rsp), %rsi
	leaq	2640(%rsp), %rdi
	movabsq	$4591291635268718628, %r8
	movabsq	$-4632080401586057180, %r9
	movabsq	$4588281831887091424, %r10
	movabsq	$4604697213322934770, %r11
	movq	%rcx, %rdx
	movq	%rax, 3736(%rsp)
	movq	%r8, 3696(%rsp)
	movq	%r9, 3704(%rsp)
	movq	%r10, 3712(%rsp)
	movq	%r11, 3896(%rsp)
.LEHB191:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE191:
	leaq	2640(%rsp), %rsi
	leaq	688(%rsp), %rdi
.LEHB192:
	call	_ZN3fem5pointC1ERKS0_
.LEHE192:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rdi
	movq	%rdi, 720(%rsp)
	je	.L920
	testq	%rbx, %rbx
	je	.L921
	leaq	688(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB193:
	call	_ZN3fem5pointC1ERKS0_
.LEHE193:
	movq	720(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L921:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L922:
	leaq	688(%rsp), %rdi
.LEHB194:
	call	_ZN3fem5pointD1Ev
.LEHE194:
	leaq	2640(%rsp), %rdi
.LEHB195:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC0(%rip), %xmm1
	leaq	3888(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	2608(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3888(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE195:
	leaq	2608(%rsp), %rsi
	leaq	640(%rsp), %rdi
.LEHB196:
	call	_ZN3fem5pointC1ERKS0_
.LEHE196:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rsi
	movq	%rsi, 672(%rsp)
	je	.L925
	testq	%rbx, %rbx
	je	.L926
	leaq	640(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB197:
	call	_ZN3fem5pointC1ERKS0_
.LEHE197:
	movq	672(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L926:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L927:
	leaq	640(%rsp), %rdi
.LEHB198:
	call	_ZN3fem5pointD1Ev
.LEHE198:
	leaq	2608(%rsp), %rdi
.LEHB199:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	3880(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	2576(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3880(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE199:
	leaq	2576(%rsp), %rsi
	leaq	592(%rsp), %rdi
.LEHB200:
	call	_ZN3fem5pointC1ERKS0_
.LEHE200:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rcx
	movq	%rcx, 624(%rsp)
	je	.L930
	testq	%rbx, %rbx
	je	.L931
	leaq	592(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB201:
	call	_ZN3fem5pointC1ERKS0_
.LEHE201:
	movq	624(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L931:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L932:
	leaq	592(%rsp), %rdi
.LEHB202:
	call	_ZN3fem5pointD1Ev
.LEHE202:
	leaq	2576(%rsp), %rdi
.LEHB203:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	2544(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE203:
	leaq	2544(%rsp), %rsi
	leaq	544(%rsp), %rdi
.LEHB204:
	call	_ZN3fem5pointC1ERKS0_
.LEHE204:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rdx
	movq	%rdx, 576(%rsp)
	je	.L935
	testq	%rbx, %rbx
	je	.L936
	leaq	544(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB205:
	call	_ZN3fem5pointC1ERKS0_
.LEHE205:
	movq	576(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L936:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L937:
	leaq	544(%rsp), %rdi
.LEHB206:
	call	_ZN3fem5pointD1Ev
.LEHE206:
	leaq	2544(%rsp), %rdi
.LEHB207:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC0(%rip), %xmm1
	leaq	3872(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	2512(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3872(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE207:
	leaq	2512(%rsp), %rsi
	leaq	496(%rsp), %rdi
.LEHB208:
	call	_ZN3fem5pointC1ERKS0_
.LEHE208:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 528(%rsp)
	je	.L940
	testq	%rbx, %rbx
	je	.L941
	leaq	496(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB209:
	call	_ZN3fem5pointC1ERKS0_
.LEHE209:
	movq	528(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L941:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L942:
	leaq	496(%rsp), %rdi
.LEHB210:
	call	_ZN3fem5pointD1Ev
.LEHE210:
	leaq	2512(%rsp), %rdi
.LEHB211:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm1
	leaq	3864(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	2480(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3864(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE211:
	leaq	2480(%rsp), %rsi
	leaq	448(%rsp), %rdi
.LEHB212:
	call	_ZN3fem5pointC1ERKS0_
.LEHE212:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 480(%rsp)
	je	.L945
	testq	%rbx, %rbx
	je	.L946
	leaq	448(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB213:
	call	_ZN3fem5pointC1ERKS0_
.LEHE213:
	movq	480(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L946:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L947:
	leaq	448(%rsp), %rdi
.LEHB214:
	call	_ZN3fem5pointD1Ev
.LEHE214:
	leaq	2480(%rsp), %rdi
.LEHB215:
	call	_ZN3fem5pointD1Ev
	movsd	.LC13(%rip), %xmm1
	leaq	3704(%rsp), %rsi
	movsd	.LC0(%rip), %xmm0
	leaq	3856(%rsp), %rcx
	mulsd	3704(%rsp), %xmm1
	leaq	2448(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm1, %xmm0
	movsd	%xmm0, 3856(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE215:
	leaq	2448(%rsp), %rsi
	leaq	400(%rsp), %rdi
.LEHB216:
	call	_ZN3fem5pointC1ERKS0_
.LEHE216:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 432(%rsp)
	je	.L950
	testq	%rbx, %rbx
	je	.L951
	leaq	400(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB217:
	call	_ZN3fem5pointC1ERKS0_
.LEHE217:
	movq	432(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L951:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L952:
	leaq	400(%rsp), %rdi
.LEHB218:
	call	_ZN3fem5pointD1Ev
.LEHE218:
	leaq	2448(%rsp), %rdi
.LEHB219:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	2416(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE219:
	leaq	2416(%rsp), %rsi
	leaq	352(%rsp), %rdi
.LEHB220:
	call	_ZN3fem5pointC1ERKS0_
.LEHE220:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 384(%rsp)
	je	.L955
	testq	%rbx, %rbx
	je	.L956
	leaq	352(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB221:
	call	_ZN3fem5pointC1ERKS0_
.LEHE221:
	movq	384(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L956:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L957:
	leaq	352(%rsp), %rdi
.LEHB222:
	call	_ZN3fem5pointD1Ev
.LEHE222:
	leaq	2416(%rsp), %rdi
.LEHB223:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rcx
	leaq	3840(%rsp), %rdx
	leaq	3848(%rsp), %rsi
	leaq	2384(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3840(%rsp)
	movsd	%xmm0, 3848(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE223:
	leaq	2384(%rsp), %rsi
	leaq	304(%rsp), %rdi
.LEHB224:
	call	_ZN3fem5pointC1ERKS0_
.LEHE224:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %rax
	movq	%rax, 336(%rsp)
	je	.L960
	testq	%rbx, %rbx
	je	.L961
	leaq	304(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB225:
	call	_ZN3fem5pointC1ERKS0_
.LEHE225:
	movq	336(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L961:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L962:
	leaq	304(%rsp), %rdi
.LEHB226:
	call	_ZN3fem5pointD1Ev
.LEHE226:
	leaq	2384(%rsp), %rdi
.LEHB227:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3824(%rsp), %rcx
	leaq	3832(%rsp), %rsi
	leaq	2352(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3824(%rsp)
	movsd	%xmm0, 3832(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE227:
	leaq	2352(%rsp), %rsi
	leaq	256(%rsp), %rdi
.LEHB228:
	call	_ZN3fem5pointC1ERKS0_
.LEHE228:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %rax
	movq	%rax, 288(%rsp)
	je	.L965
	testq	%rbx, %rbx
	je	.L966
	leaq	256(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB229:
	call	_ZN3fem5pointC1ERKS0_
.LEHE229:
	movq	288(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L966:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L967:
	leaq	256(%rsp), %rdi
.LEHB230:
	call	_ZN3fem5pointD1Ev
.LEHE230:
	leaq	2352(%rsp), %rdi
.LEHB231:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3816(%rsp), %rsi
	leaq	2320(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rdx, %rcx
	movsd	%xmm0, 3816(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE231:
	leaq	2320(%rsp), %rsi
	leaq	208(%rsp), %rdi
.LEHB232:
	call	_ZN3fem5pointC1ERKS0_
.LEHE232:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r15
	movq	%r15, 240(%rsp)
	je	.L970
	testq	%rbx, %rbx
	je	.L971
	leaq	208(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB233:
	call	_ZN3fem5pointC1ERKS0_
.LEHE233:
	movq	240(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L971:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L972:
	leaq	208(%rsp), %rdi
.LEHB234:
	call	_ZN3fem5pointD1Ev
.LEHE234:
	leaq	2320(%rsp), %rdi
.LEHB235:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3800(%rsp), %rcx
	leaq	3808(%rsp), %rdx
	leaq	2288(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3800(%rsp)
	movsd	%xmm0, 3808(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE235:
	leaq	2288(%rsp), %rsi
	leaq	160(%rsp), %rdi
.LEHB236:
	call	_ZN3fem5pointC1ERKS0_
.LEHE236:
	movabsq	$4576237049931877280, %rbx
	movq	%rbx, 192(%rsp)
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	je	.L975
	testq	%rbx, %rbx
	je	.L976
	leaq	160(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB237:
	call	_ZN3fem5pointC1ERKS0_
.LEHE237:
	movq	192(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L976:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L977:
	leaq	160(%rsp), %rdi
.LEHB238:
	call	_ZN3fem5pointD1Ev
.LEHE238:
	leaq	2288(%rsp), %rdi
.LEHB239:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3792(%rsp), %rdx
	leaq	2256(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rcx
	movsd	%xmm0, 3792(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE239:
	leaq	2256(%rsp), %rsi
	leaq	112(%rsp), %rdi
.LEHB240:
	call	_ZN3fem5pointC1ERKS0_
.LEHE240:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r11
	movq	%r11, 144(%rsp)
	je	.L980
	testq	%rbx, %rbx
	je	.L981
	leaq	112(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB241:
	call	_ZN3fem5pointC1ERKS0_
.LEHE241:
	movq	144(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L981:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L982:
	leaq	112(%rsp), %rdi
.LEHB242:
	call	_ZN3fem5pointD1Ev
.LEHE242:
	leaq	2256(%rsp), %rdi
.LEHB243:
	call	_ZN3fem5pointD1Ev
	movsd	.LC21(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3784(%rsp), %rcx
	leaq	2224(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rdx
	movsd	%xmm0, 3784(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE243:
	leaq	2224(%rsp), %rsi
	leaq	64(%rsp), %rdi
.LEHB244:
	call	_ZN3fem5pointC1ERKS0_
.LEHE244:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r10
	movq	%r10, 96(%rsp)
	je	.L985
	testq	%rbx, %rbx
	je	.L986
	leaq	64(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB245:
	call	_ZN3fem5pointC1ERKS0_
.LEHE245:
	movq	96(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L986:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L987:
	leaq	64(%rsp), %rdi
.LEHB246:
	call	_ZN3fem5pointD1Ev
.LEHE246:
	leaq	2224(%rsp), %rdi
.LEHB247:
	call	_ZN3fem5pointD1Ev
	movabsq	$4598175219545276416, %rdi
	leaq	3760(%rsp), %rcx
	leaq	3768(%rsp), %rdx
	movq	%rdi, 3760(%rsp)
	leaq	3776(%rsp), %rsi
	leaq	2192(%rsp), %rdi
	movabsq	$4598175219545276416, %r8
	movabsq	$4598175219545276416, %r9
	movq	%r8, 3768(%rsp)
	movq	%r9, 3776(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE247:
	leaq	2192(%rsp), %rsi
	leaq	16(%rsp), %rdi
.LEHB248:
	call	_ZN3fem5pointC1ERKS0_
.LEHE248:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581350660937346637, %rsi
	movq	%rsi, 48(%rsp)
	je	.L990
	testq	%rbx, %rbx
	je	.L991
	leaq	16(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB249:
	call	_ZN3fem5pointC1ERKS0_
.LEHE249:
	movq	48(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L991:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L992:
	leaq	16(%rsp), %rdi
.LEHB250:
	call	_ZN3fem5pointD1Ev
.LEHE250:
	leaq	2192(%rsp), %rdi
.LEHB251:
	call	_ZN3fem5pointD1Ev
.LEHE251:
	movq	32(%r14), %rax
	.p2align 4,,10
	.p2align 3
.L1250:
	testq	%rax, %rax
	je	.L995
.L1255:
	cmpl	$4, 32(%rax)
	jle	.L996
	movq	%rax, %r13
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1255
.L995:
	cmpq	%r13, %r12
	movq	%r13, %r15
	je	.L999
	cmpl	$5, 32(%r13)
	jle	.L1018
.L999:
	leaq	16(%r14), %rdi
	leaq	2032(%rsp), %rdx
	movq	%r13, %rsi
	movq	$0, 3536(%rsp)
	movq	$0, 3544(%rsp)
	movq	$0, 3552(%rsp)
	movl	$5, 2032(%rsp)
	movq	$0, 2040(%rsp)
	movq	$0, 2056(%rsp)
	movq	$0, 2048(%rsp)
.LEHB252:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE252:
	movq	2048(%rsp), %r12
	movq	2040(%rsp), %rbx
	movq	%rax, %r15
	cmpq	%rbx, %r12
	je	.L1001
	.p2align 4,,10
	.p2align 3
.L1211:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB253:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	jne	.L1211
	movq	2040(%rsp), %rbx
.L1001:
	testq	%rbx, %rbx
	je	.L1010
	movq	%rbx, %rdi
	call	_ZdlPv
.L1010:
	movq	3544(%rsp), %r12
	movq	3536(%rsp), %rbx
	cmpq	%rbx, %r12
	je	.L1011
	.p2align 4,,10
	.p2align 3
.L1210:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE253:
	cmpq	%rbx, %r12
	jne	.L1210
	movq	3536(%rsp), %rbx
.L1011:
	testq	%rbx, %rbx
	je	.L1018
	movq	%rbx, %rdi
	call	_ZdlPv
.L1018:
	leaq	40(%r15), %rdi
	movq	%rbp, %rsi
.LEHB254:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE254:
	movq	3736(%rsp), %rbp
	movq	3728(%rsp), %rbx
	cmpq	%rbx, %rbp
	je	.L1022
	.p2align 4,,10
	.p2align 3
.L1209:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB255:
	call	_ZN3fem5pointD1Ev
.LEHE255:
	cmpq	%rbx, %rbp
	jne	.L1209
	movq	3728(%rsp), %rbx
.L1022:
	testq	%rbx, %rbx
	je	.L659
	movq	%rbx, %rdi
	call	_ZdlPv
.L659:
	addq	$4200, %rsp
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
	.p2align 4,,10
	.p2align 3
.L666:
	.cfi_restore_state
	movq	24(%rax), %rax
	jmp	.L1246
	.p2align 4,,10
	.p2align 3
.L718:
	movq	24(%rax), %rax
	jmp	.L1247
	.p2align 4,,10
	.p2align 3
.L789:
	movq	24(%rax), %rax
	jmp	.L1248
	.p2align 4,,10
	.p2align 3
.L890:
	movq	24(%rax), %rax
	jmp	.L1249
	.p2align 4,,10
	.p2align 3
.L996:
	movq	24(%rax), %rax
	jmp	.L1250
	.p2align 4,,10
	.p2align 3
.L697:
	leaq	1936(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB256:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE256:
	jmp	.L699
	.p2align 4,,10
	.p2align 3
.L660:
	leaq	3728(%rsp), %rbp
	leaq	1984(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB257:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE257:
	jmp	.L662
	.p2align 4,,10
	.p2align 3
.L712:
	leaq	1792(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB258:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE258:
	jmp	.L714
	.p2align 4,,10
	.p2align 3
.L707:
	leaq	1840(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB259:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE259:
	jmp	.L709
	.p2align 4,,10
	.p2align 3
.L702:
	leaq	1888(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB260:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE260:
	jmp	.L704
	.p2align 4,,10
	.p2align 3
.L748:
	leaq	1744(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB261:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE261:
	jmp	.L750
	.p2align 4,,10
	.p2align 3
.L753:
	leaq	1696(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB262:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE262:
	jmp	.L755
	.p2align 4,,10
	.p2align 3
.L768:
	leaq	1552(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB263:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE263:
	jmp	.L770
	.p2align 4,,10
	.p2align 3
.L763:
	leaq	1600(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB264:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE264:
	jmp	.L765
	.p2align 4,,10
	.p2align 3
.L758:
	leaq	1648(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB265:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE265:
	jmp	.L760
	.p2align 4,,10
	.p2align 3
.L990:
	leaq	16(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB266:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE266:
	jmp	.L992
	.p2align 4,,10
	.p2align 3
.L783:
	leaq	1408(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB267:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE267:
	jmp	.L785
	.p2align 4,,10
	.p2align 3
.L824:
	leaq	1312(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB268:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE268:
	jmp	.L826
	.p2align 4,,10
	.p2align 3
.L819:
	leaq	1360(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB269:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE269:
	jmp	.L821
	.p2align 4,,10
	.p2align 3
.L778:
	leaq	1456(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB270:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE270:
	jmp	.L780
	.p2align 4,,10
	.p2align 3
.L773:
	leaq	1504(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB271:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE271:
	jmp	.L775
	.p2align 4,,10
	.p2align 3
.L849:
	leaq	1072(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB272:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE272:
	jmp	.L851
	.p2align 4,,10
	.p2align 3
.L844:
	leaq	1120(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB273:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE273:
	jmp	.L846
	.p2align 4,,10
	.p2align 3
.L839:
	leaq	1168(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB274:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE274:
	jmp	.L841
	.p2align 4,,10
	.p2align 3
.L834:
	leaq	1216(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB275:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE275:
	jmp	.L836
	.p2align 4,,10
	.p2align 3
.L829:
	leaq	1264(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB276:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE276:
	jmp	.L831
	.p2align 4,,10
	.p2align 3
.L920:
	leaq	688(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB277:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE277:
	jmp	.L922
	.p2align 4,,10
	.p2align 3
.L884:
	leaq	736(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB278:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE278:
	jmp	.L886
	.p2align 4,,10
	.p2align 3
.L879:
	leaq	784(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB279:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE279:
	jmp	.L881
	.p2align 4,,10
	.p2align 3
.L930:
	leaq	592(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB280:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE280:
	jmp	.L932
	.p2align 4,,10
	.p2align 3
.L925:
	leaq	640(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB281:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE281:
	jmp	.L927
	.p2align 4,,10
	.p2align 3
.L874:
	leaq	832(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB282:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE282:
	jmp	.L876
	.p2align 4,,10
	.p2align 3
.L869:
	leaq	880(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB283:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE283:
	jmp	.L871
	.p2align 4,,10
	.p2align 3
.L864:
	leaq	928(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB284:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE284:
	jmp	.L866
	.p2align 4,,10
	.p2align 3
.L859:
	leaq	976(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB285:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE285:
	jmp	.L861
	.p2align 4,,10
	.p2align 3
.L854:
	leaq	1024(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB286:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE286:
	jmp	.L856
	.p2align 4,,10
	.p2align 3
.L985:
	leaq	64(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB287:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE287:
	jmp	.L987
	.p2align 4,,10
	.p2align 3
.L980:
	leaq	112(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB288:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE288:
	jmp	.L982
	.p2align 4,,10
	.p2align 3
.L975:
	leaq	160(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB289:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE289:
	jmp	.L977
	.p2align 4,,10
	.p2align 3
.L970:
	leaq	208(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB290:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE290:
	jmp	.L972
	.p2align 4,,10
	.p2align 3
.L965:
	leaq	256(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB291:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE291:
	jmp	.L967
	.p2align 4,,10
	.p2align 3
.L960:
	leaq	304(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB292:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE292:
	jmp	.L962
	.p2align 4,,10
	.p2align 3
.L955:
	leaq	352(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB293:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE293:
	jmp	.L957
	.p2align 4,,10
	.p2align 3
.L950:
	leaq	400(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB294:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE294:
	jmp	.L952
	.p2align 4,,10
	.p2align 3
.L945:
	leaq	448(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB295:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE295:
	jmp	.L947
	.p2align 4,,10
	.p2align 3
.L940:
	leaq	496(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB296:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE296:
	jmp	.L942
	.p2align 4,,10
	.p2align 3
.L935:
	leaq	544(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB297:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE297:
	jmp	.L937
	.p2align 4,,10
	.p2align 3
.L669:
	leaq	16(%r14), %rdi
	leaq	2160(%rsp), %rdx
	movq	$0, 3664(%rsp)
	movq	$0, 3672(%rsp)
	movq	$0, 3680(%rsp)
	movl	$1, 2160(%rsp)
	movq	$0, 2168(%rsp)
	movq	$0, 2184(%rsp)
	movq	$0, 2176(%rsp)
.LEHB298:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE298:
	movq	2176(%rsp), %r15
	movq	2168(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L671
	.p2align 4,,10
	.p2align 3
.L1220:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB299:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1220
	movq	2168(%rsp), %rbx
.L671:
	testq	%rbx, %rbx
	je	.L680
	movq	%rbx, %rdi
	call	_ZdlPv
.L680:
	movq	3672(%rsp), %r15
	movq	3664(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L681
	.p2align 4,,10
	.p2align 3
.L1219:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE299:
	cmpq	%rbx, %r15
	jne	.L1219
	movq	3664(%rsp), %rbx
.L681:
	testq	%rbx, %rbx
	je	.L688
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L688
	.p2align 4,,10
	.p2align 3
.L721:
	leaq	16(%r14), %rdi
	leaq	2128(%rsp), %rdx
	movq	$0, 3632(%rsp)
	movq	$0, 3640(%rsp)
	movq	$0, 3648(%rsp)
	movl	$2, 2128(%rsp)
	movq	$0, 2136(%rsp)
	movq	$0, 2152(%rsp)
	movq	$0, 2144(%rsp)
.LEHB300:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE300:
	movq	2144(%rsp), %r15
	movq	2136(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L723
	.p2align 4,,10
	.p2align 3
.L1218:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB301:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1218
	movq	2136(%rsp), %rbx
.L723:
	testq	%rbx, %rbx
	je	.L732
	movq	%rbx, %rdi
	call	_ZdlPv
.L732:
	movq	3640(%rsp), %r15
	movq	3632(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L733
	.p2align 4,,10
	.p2align 3
.L1217:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE301:
	cmpq	%rbx, %r15
	jne	.L1217
	movq	3632(%rsp), %rbx
.L733:
	testq	%rbx, %rbx
	je	.L740
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L740
	.p2align 4,,10
	.p2align 3
.L792:
	leaq	16(%r14), %rdi
	leaq	2096(%rsp), %rdx
	movq	$0, 3600(%rsp)
	movq	$0, 3608(%rsp)
	movq	$0, 3616(%rsp)
	movl	$3, 2096(%rsp)
	movq	$0, 2104(%rsp)
	movq	$0, 2120(%rsp)
	movq	$0, 2112(%rsp)
.LEHB302:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE302:
	movq	2112(%rsp), %r15
	movq	2104(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L794
	.p2align 4,,10
	.p2align 3
.L1216:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB303:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1216
	movq	2104(%rsp), %rbx
.L794:
	testq	%rbx, %rbx
	je	.L803
	movq	%rbx, %rdi
	call	_ZdlPv
.L803:
	movq	3608(%rsp), %r15
	movq	3600(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L804
	.p2align 4,,10
	.p2align 3
.L1215:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE303:
	cmpq	%rbx, %r15
	jne	.L1215
	movq	3600(%rsp), %rbx
.L804:
	testq	%rbx, %rbx
	je	.L811
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L811
	.p2align 4,,10
	.p2align 3
.L893:
	leaq	16(%r14), %rdi
	leaq	2064(%rsp), %rdx
	movq	$0, 3568(%rsp)
	movq	$0, 3576(%rsp)
	movq	$0, 3584(%rsp)
	movl	$4, 2064(%rsp)
	movq	$0, 2072(%rsp)
	movq	$0, 2088(%rsp)
	movq	$0, 2080(%rsp)
.LEHB304:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE304:
	movq	2080(%rsp), %r15
	movq	2072(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L895
	.p2align 4,,10
	.p2align 3
.L1214:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB305:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1214
	movq	2072(%rsp), %rbx
.L895:
	testq	%rbx, %rbx
	je	.L904
	movq	%rbx, %rdi
	call	_ZdlPv
.L904:
	movq	3576(%rsp), %r15
	movq	3568(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L905
	.p2align 4,,10
	.p2align 3
.L1213:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1213
	movq	3568(%rsp), %rbx
.L905:
	testq	%rbx, %rbx
	je	.L912
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L912
.L1208:
	leaq	2040(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3536(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
.L692:
	movq	%rbp, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE305:
.L1143:
	leaq	1456(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1054:
	leaq	3152(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1156:
	movq	%rax, %rbx
.L1068:
	leaq	2928(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1155:
	leaq	1168(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1066:
	leaq	2960(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1140:
	movq	%rax, %rbx
.L1052:
	leaq	3184(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1139:
	leaq	1552(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1050:
	leaq	3216(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1141:
	leaq	1504(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1052
.L1159:
	leaq	1072(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1070:
	leaq	2896(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1158:
	movq	%rax, %rbx
	jmp	.L1070
.L1157:
	leaq	1120(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1068
.L1127:
	leaq	1840(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1038:
	leaq	3408(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1124:
	movq	%rax, %rbx
.L1036:
	leaq	3440(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1126:
	movq	%rax, %rbx
	jmp	.L1038
.L1125:
	leaq	1888(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1036
.L1122:
	movq	%rax, %rbx
.L1034:
	leaq	3472(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1123:
	leaq	1936(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1034
.L1120:
	leaq	3728(%rsp), %rbp
	movq	%rax, %rbx
.L1032:
	leaq	3504(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1119:
	movq	%rax, %rbx
	jmp	.L692
.L1130:
	movq	%rax, %rbx
.L1042:
	leaq	3344(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1133:
	leaq	1696(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1044:
	leaq	3312(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1132:
	movq	%rax, %rbx
	jmp	.L1044
.L1131:
	leaq	1744(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1042
.L1121:
	leaq	1984(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1032
.L1128:
	movq	%rax, %rbx
.L1040:
	leaq	3376(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1146:
	movq	%rax, %rbx
.L1058:
	leaq	3088(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1129:
	leaq	1792(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1040
.L1163:
	leaq	976(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1074:
	leaq	2832(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1160:
	movq	%rax, %rbx
.L1072:
	leaq	2864(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1162:
	movq	%rax, %rbx
	jmp	.L1074
.L1161:
	leaq	1024(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1072
.L1166:
	movq	%rax, %rbx
.L1078:
	leaq	2768(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1165:
	leaq	928(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1076:
	leaq	2800(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1167:
	leaq	880(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1078
.L1195:
	leaq	208(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1106:
	leaq	2320(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1189:
	leaq	352(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1100:
	leaq	2416(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1186:
	movq	%rax, %rbx
.L1098:
	leaq	2448(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1188:
	movq	%rax, %rbx
	jmp	.L1100
.L1187:
	leaq	400(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1098
.L1192:
	movq	%rax, %rbx
.L1104:
	leaq	2352(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1191:
	leaq	304(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1102:
	leaq	2384(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1193:
	leaq	256(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1104
.L1190:
	movq	%rax, %rbx
	jmp	.L1102
.L1152:
	movq	%rax, %rbx
.L1064:
	leaq	2992(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1151:
	leaq	1264(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1062:
	leaq	3024(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1150:
	movq	%rax, %rbx
	jmp	.L1062
.L1149:
	leaq	1312(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1060:
	leaq	3056(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1147:
	leaq	1360(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1058
.L1142:
	movq	%rax, %rbx
	jmp	.L1054
.L1144:
	movq	%rax, %rbx
.L1056:
	leaq	3120(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1182:
	movq	%rax, %rbx
.L1094:
	leaq	2512(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1200:
	movq	%rax, %rbx
.L1112:
	leaq	2224(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1199:
	leaq	112(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1110:
	leaq	2256(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1201:
	leaq	64(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1112
.L1198:
	movq	%rax, %rbx
	jmp	.L1110
.L1197:
	leaq	160(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1108:
	leaq	2288(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1194:
	movq	%rax, %rbx
	jmp	.L1106
.L1196:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1108
.L1179:
	leaq	592(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1090:
	leaq	2576(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1134:
	movq	%rax, %rbx
.L1046:
	leaq	3280(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1202:
	movq	%rax, %rbx
.L1114:
	leaq	2192(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1145:
	leaq	1408(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1056
.L1148:
	movq	%rax, %rbx
	jmp	.L1060
.L1138:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1050
.L1137:
	leaq	1600(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1048:
	leaq	3248(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1136:
	movq	%rax, %rbx
	jmp	.L1048
.L1164:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1076
.L1154:
	movq	%rax, %rbx
	.p2align 4,,2
	jmp	.L1066
.L1153:
	leaq	1216(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1064
.L1203:
	leaq	16(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1114
.L1173:
	leaq	736(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1084:
	leaq	2672(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1177:
	leaq	640(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1088:
	leaq	2608(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1168:
	movq	%rax, %rbx
.L1080:
	leaq	2736(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1170:
	movq	%rax, %rbx
.L1082:
	leaq	2704(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1169:
	leaq	832(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1080
.L1174:
	movq	%rax, %rbx
.L1086:
	leaq	2640(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1172:
	movq	%rax, %rbx
	jmp	.L1084
.L1176:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1088
.L1175:
	leaq	688(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1086
.L1171:
	leaq	784(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1082
.L1178:
	movq	%rax, %rbx
	jmp	.L1090
.L1180:
	movq	%rax, %rbx
.L1092:
	leaq	2544(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1181:
	leaq	544(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1092
.L1184:
	movq	%rax, %rbx
.L1096:
	leaq	2480(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L692
.L1183:
	leaq	496(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1094
.L1185:
	leaq	448(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1096
.L1135:
	leaq	1648(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1046
.L1207:
	leaq	2072(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3568(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L692
.L1206:
	leaq	2104(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3600(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L692
.L1205:
	leaq	2136(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3632(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L692
.L1204:
	leaq	2168(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3664(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L692
	.cfi_endproc
.LFE3594:
	.size	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv, .-_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
	.section	.gcc_except_table
	.align 4
.LLSDA3594:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT3594-.LLSDATTD3594
.LLSDATTD3594:
	.byte	0x1
	.uleb128 .LLSDACSE3594-.LLSDACSB3594
.LLSDACSB3594:
	.uleb128 .LEHB75-.LFB3594
	.uleb128 .LEHE75-.LEHB75
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB76-.LFB3594
	.uleb128 .LEHE76-.LEHB76
	.uleb128 .L1120-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB77-.LFB3594
	.uleb128 .LEHE77-.LEHB77
	.uleb128 .L1121-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB78-.LFB3594
	.uleb128 .LEHE78-.LEHB78
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB79-.LFB3594
	.uleb128 .LEHE79-.LEHB79
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB80-.LFB3594
	.uleb128 .LEHE80-.LEHB80
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB81-.LFB3594
	.uleb128 .LEHE81-.LEHB81
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB82-.LFB3594
	.uleb128 .LEHE82-.LEHB82
	.uleb128 .L1122-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB83-.LFB3594
	.uleb128 .LEHE83-.LEHB83
	.uleb128 .L1123-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB84-.LFB3594
	.uleb128 .LEHE84-.LEHB84
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB85-.LFB3594
	.uleb128 .LEHE85-.LEHB85
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB86-.LFB3594
	.uleb128 .LEHE86-.LEHB86
	.uleb128 .L1124-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB87-.LFB3594
	.uleb128 .LEHE87-.LEHB87
	.uleb128 .L1125-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB88-.LFB3594
	.uleb128 .LEHE88-.LEHB88
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB89-.LFB3594
	.uleb128 .LEHE89-.LEHB89
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB90-.LFB3594
	.uleb128 .LEHE90-.LEHB90
	.uleb128 .L1126-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB91-.LFB3594
	.uleb128 .LEHE91-.LEHB91
	.uleb128 .L1127-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB92-.LFB3594
	.uleb128 .LEHE92-.LEHB92
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB93-.LFB3594
	.uleb128 .LEHE93-.LEHB93
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB94-.LFB3594
	.uleb128 .LEHE94-.LEHB94
	.uleb128 .L1128-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB95-.LFB3594
	.uleb128 .LEHE95-.LEHB95
	.uleb128 .L1129-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB96-.LFB3594
	.uleb128 .LEHE96-.LEHB96
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB97-.LFB3594
	.uleb128 .LEHE97-.LEHB97
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB98-.LFB3594
	.uleb128 .LEHE98-.LEHB98
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB99-.LFB3594
	.uleb128 .LEHE99-.LEHB99
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB100-.LFB3594
	.uleb128 .LEHE100-.LEHB100
	.uleb128 .L1130-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB101-.LFB3594
	.uleb128 .LEHE101-.LEHB101
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB102-.LFB3594
	.uleb128 .LEHE102-.LEHB102
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB103-.LFB3594
	.uleb128 .LEHE103-.LEHB103
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB104-.LFB3594
	.uleb128 .LEHE104-.LEHB104
	.uleb128 .L1132-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB105-.LFB3594
	.uleb128 .LEHE105-.LEHB105
	.uleb128 .L1133-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB106-.LFB3594
	.uleb128 .LEHE106-.LEHB106
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB107-.LFB3594
	.uleb128 .LEHE107-.LEHB107
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB108-.LFB3594
	.uleb128 .LEHE108-.LEHB108
	.uleb128 .L1134-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB109-.LFB3594
	.uleb128 .LEHE109-.LEHB109
	.uleb128 .L1135-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB110-.LFB3594
	.uleb128 .LEHE110-.LEHB110
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB111-.LFB3594
	.uleb128 .LEHE111-.LEHB111
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB112-.LFB3594
	.uleb128 .LEHE112-.LEHB112
	.uleb128 .L1136-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB113-.LFB3594
	.uleb128 .LEHE113-.LEHB113
	.uleb128 .L1137-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB114-.LFB3594
	.uleb128 .LEHE114-.LEHB114
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB115-.LFB3594
	.uleb128 .LEHE115-.LEHB115
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB116-.LFB3594
	.uleb128 .LEHE116-.LEHB116
	.uleb128 .L1138-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB117-.LFB3594
	.uleb128 .LEHE117-.LEHB117
	.uleb128 .L1139-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB118-.LFB3594
	.uleb128 .LEHE118-.LEHB118
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB119-.LFB3594
	.uleb128 .LEHE119-.LEHB119
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB120-.LFB3594
	.uleb128 .LEHE120-.LEHB120
	.uleb128 .L1140-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB121-.LFB3594
	.uleb128 .LEHE121-.LEHB121
	.uleb128 .L1141-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB122-.LFB3594
	.uleb128 .LEHE122-.LEHB122
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB123-.LFB3594
	.uleb128 .LEHE123-.LEHB123
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB124-.LFB3594
	.uleb128 .LEHE124-.LEHB124
	.uleb128 .L1142-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB125-.LFB3594
	.uleb128 .LEHE125-.LEHB125
	.uleb128 .L1143-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB126-.LFB3594
	.uleb128 .LEHE126-.LEHB126
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB127-.LFB3594
	.uleb128 .LEHE127-.LEHB127
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB128-.LFB3594
	.uleb128 .LEHE128-.LEHB128
	.uleb128 .L1144-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB129-.LFB3594
	.uleb128 .LEHE129-.LEHB129
	.uleb128 .L1145-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB130-.LFB3594
	.uleb128 .LEHE130-.LEHB130
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB131-.LFB3594
	.uleb128 .LEHE131-.LEHB131
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB132-.LFB3594
	.uleb128 .LEHE132-.LEHB132
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB133-.LFB3594
	.uleb128 .LEHE133-.LEHB133
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB134-.LFB3594
	.uleb128 .LEHE134-.LEHB134
	.uleb128 .L1146-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB135-.LFB3594
	.uleb128 .LEHE135-.LEHB135
	.uleb128 .L1147-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB136-.LFB3594
	.uleb128 .LEHE136-.LEHB136
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB137-.LFB3594
	.uleb128 .LEHE137-.LEHB137
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB138-.LFB3594
	.uleb128 .LEHE138-.LEHB138
	.uleb128 .L1148-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB139-.LFB3594
	.uleb128 .LEHE139-.LEHB139
	.uleb128 .L1149-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB140-.LFB3594
	.uleb128 .LEHE140-.LEHB140
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB141-.LFB3594
	.uleb128 .LEHE141-.LEHB141
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB142-.LFB3594
	.uleb128 .LEHE142-.LEHB142
	.uleb128 .L1150-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB143-.LFB3594
	.uleb128 .LEHE143-.LEHB143
	.uleb128 .L1151-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB144-.LFB3594
	.uleb128 .LEHE144-.LEHB144
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB145-.LFB3594
	.uleb128 .LEHE145-.LEHB145
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB146-.LFB3594
	.uleb128 .LEHE146-.LEHB146
	.uleb128 .L1152-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB147-.LFB3594
	.uleb128 .LEHE147-.LEHB147
	.uleb128 .L1153-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB148-.LFB3594
	.uleb128 .LEHE148-.LEHB148
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB149-.LFB3594
	.uleb128 .LEHE149-.LEHB149
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB150-.LFB3594
	.uleb128 .LEHE150-.LEHB150
	.uleb128 .L1154-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB151-.LFB3594
	.uleb128 .LEHE151-.LEHB151
	.uleb128 .L1155-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB152-.LFB3594
	.uleb128 .LEHE152-.LEHB152
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB153-.LFB3594
	.uleb128 .LEHE153-.LEHB153
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB154-.LFB3594
	.uleb128 .LEHE154-.LEHB154
	.uleb128 .L1156-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB155-.LFB3594
	.uleb128 .LEHE155-.LEHB155
	.uleb128 .L1157-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB156-.LFB3594
	.uleb128 .LEHE156-.LEHB156
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB157-.LFB3594
	.uleb128 .LEHE157-.LEHB157
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB158-.LFB3594
	.uleb128 .LEHE158-.LEHB158
	.uleb128 .L1158-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB159-.LFB3594
	.uleb128 .LEHE159-.LEHB159
	.uleb128 .L1159-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB160-.LFB3594
	.uleb128 .LEHE160-.LEHB160
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB161-.LFB3594
	.uleb128 .LEHE161-.LEHB161
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB162-.LFB3594
	.uleb128 .LEHE162-.LEHB162
	.uleb128 .L1160-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB163-.LFB3594
	.uleb128 .LEHE163-.LEHB163
	.uleb128 .L1161-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB164-.LFB3594
	.uleb128 .LEHE164-.LEHB164
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB165-.LFB3594
	.uleb128 .LEHE165-.LEHB165
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB166-.LFB3594
	.uleb128 .LEHE166-.LEHB166
	.uleb128 .L1162-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB167-.LFB3594
	.uleb128 .LEHE167-.LEHB167
	.uleb128 .L1163-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB168-.LFB3594
	.uleb128 .LEHE168-.LEHB168
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB169-.LFB3594
	.uleb128 .LEHE169-.LEHB169
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB170-.LFB3594
	.uleb128 .LEHE170-.LEHB170
	.uleb128 .L1164-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB171-.LFB3594
	.uleb128 .LEHE171-.LEHB171
	.uleb128 .L1165-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB172-.LFB3594
	.uleb128 .LEHE172-.LEHB172
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB173-.LFB3594
	.uleb128 .LEHE173-.LEHB173
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB174-.LFB3594
	.uleb128 .LEHE174-.LEHB174
	.uleb128 .L1166-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB175-.LFB3594
	.uleb128 .LEHE175-.LEHB175
	.uleb128 .L1167-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB176-.LFB3594
	.uleb128 .LEHE176-.LEHB176
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB177-.LFB3594
	.uleb128 .LEHE177-.LEHB177
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB178-.LFB3594
	.uleb128 .LEHE178-.LEHB178
	.uleb128 .L1168-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB179-.LFB3594
	.uleb128 .LEHE179-.LEHB179
	.uleb128 .L1169-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB180-.LFB3594
	.uleb128 .LEHE180-.LEHB180
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB181-.LFB3594
	.uleb128 .LEHE181-.LEHB181
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB182-.LFB3594
	.uleb128 .LEHE182-.LEHB182
	.uleb128 .L1170-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB183-.LFB3594
	.uleb128 .LEHE183-.LEHB183
	.uleb128 .L1171-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB184-.LFB3594
	.uleb128 .LEHE184-.LEHB184
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB185-.LFB3594
	.uleb128 .LEHE185-.LEHB185
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB186-.LFB3594
	.uleb128 .LEHE186-.LEHB186
	.uleb128 .L1172-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB187-.LFB3594
	.uleb128 .LEHE187-.LEHB187
	.uleb128 .L1173-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB188-.LFB3594
	.uleb128 .LEHE188-.LEHB188
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB189-.LFB3594
	.uleb128 .LEHE189-.LEHB189
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB190-.LFB3594
	.uleb128 .LEHE190-.LEHB190
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB191-.LFB3594
	.uleb128 .LEHE191-.LEHB191
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB192-.LFB3594
	.uleb128 .LEHE192-.LEHB192
	.uleb128 .L1174-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB193-.LFB3594
	.uleb128 .LEHE193-.LEHB193
	.uleb128 .L1175-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB194-.LFB3594
	.uleb128 .LEHE194-.LEHB194
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB195-.LFB3594
	.uleb128 .LEHE195-.LEHB195
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB196-.LFB3594
	.uleb128 .LEHE196-.LEHB196
	.uleb128 .L1176-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB197-.LFB3594
	.uleb128 .LEHE197-.LEHB197
	.uleb128 .L1177-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB198-.LFB3594
	.uleb128 .LEHE198-.LEHB198
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB199-.LFB3594
	.uleb128 .LEHE199-.LEHB199
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB200-.LFB3594
	.uleb128 .LEHE200-.LEHB200
	.uleb128 .L1178-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB201-.LFB3594
	.uleb128 .LEHE201-.LEHB201
	.uleb128 .L1179-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB202-.LFB3594
	.uleb128 .LEHE202-.LEHB202
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB203-.LFB3594
	.uleb128 .LEHE203-.LEHB203
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB204-.LFB3594
	.uleb128 .LEHE204-.LEHB204
	.uleb128 .L1180-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB205-.LFB3594
	.uleb128 .LEHE205-.LEHB205
	.uleb128 .L1181-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB206-.LFB3594
	.uleb128 .LEHE206-.LEHB206
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB207-.LFB3594
	.uleb128 .LEHE207-.LEHB207
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB208-.LFB3594
	.uleb128 .LEHE208-.LEHB208
	.uleb128 .L1182-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB209-.LFB3594
	.uleb128 .LEHE209-.LEHB209
	.uleb128 .L1183-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB210-.LFB3594
	.uleb128 .LEHE210-.LEHB210
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB211-.LFB3594
	.uleb128 .LEHE211-.LEHB211
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB212-.LFB3594
	.uleb128 .LEHE212-.LEHB212
	.uleb128 .L1184-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB213-.LFB3594
	.uleb128 .LEHE213-.LEHB213
	.uleb128 .L1185-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB214-.LFB3594
	.uleb128 .LEHE214-.LEHB214
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB215-.LFB3594
	.uleb128 .LEHE215-.LEHB215
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB216-.LFB3594
	.uleb128 .LEHE216-.LEHB216
	.uleb128 .L1186-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB217-.LFB3594
	.uleb128 .LEHE217-.LEHB217
	.uleb128 .L1187-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB218-.LFB3594
	.uleb128 .LEHE218-.LEHB218
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB219-.LFB3594
	.uleb128 .LEHE219-.LEHB219
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB220-.LFB3594
	.uleb128 .LEHE220-.LEHB220
	.uleb128 .L1188-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB221-.LFB3594
	.uleb128 .LEHE221-.LEHB221
	.uleb128 .L1189-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB222-.LFB3594
	.uleb128 .LEHE222-.LEHB222
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB223-.LFB3594
	.uleb128 .LEHE223-.LEHB223
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB224-.LFB3594
	.uleb128 .LEHE224-.LEHB224
	.uleb128 .L1190-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB225-.LFB3594
	.uleb128 .LEHE225-.LEHB225
	.uleb128 .L1191-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB226-.LFB3594
	.uleb128 .LEHE226-.LEHB226
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB227-.LFB3594
	.uleb128 .LEHE227-.LEHB227
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB228-.LFB3594
	.uleb128 .LEHE228-.LEHB228
	.uleb128 .L1192-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB229-.LFB3594
	.uleb128 .LEHE229-.LEHB229
	.uleb128 .L1193-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB230-.LFB3594
	.uleb128 .LEHE230-.LEHB230
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB231-.LFB3594
	.uleb128 .LEHE231-.LEHB231
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB232-.LFB3594
	.uleb128 .LEHE232-.LEHB232
	.uleb128 .L1194-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB233-.LFB3594
	.uleb128 .LEHE233-.LEHB233
	.uleb128 .L1195-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB234-.LFB3594
	.uleb128 .LEHE234-.LEHB234
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB235-.LFB3594
	.uleb128 .LEHE235-.LEHB235
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB236-.LFB3594
	.uleb128 .LEHE236-.LEHB236
	.uleb128 .L1196-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB237-.LFB3594
	.uleb128 .LEHE237-.LEHB237
	.uleb128 .L1197-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB238-.LFB3594
	.uleb128 .LEHE238-.LEHB238
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB239-.LFB3594
	.uleb128 .LEHE239-.LEHB239
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB240-.LFB3594
	.uleb128 .LEHE240-.LEHB240
	.uleb128 .L1198-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB241-.LFB3594
	.uleb128 .LEHE241-.LEHB241
	.uleb128 .L1199-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB242-.LFB3594
	.uleb128 .LEHE242-.LEHB242
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB243-.LFB3594
	.uleb128 .LEHE243-.LEHB243
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB244-.LFB3594
	.uleb128 .LEHE244-.LEHB244
	.uleb128 .L1200-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB245-.LFB3594
	.uleb128 .LEHE245-.LEHB245
	.uleb128 .L1201-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB246-.LFB3594
	.uleb128 .LEHE246-.LEHB246
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB247-.LFB3594
	.uleb128 .LEHE247-.LEHB247
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB248-.LFB3594
	.uleb128 .LEHE248-.LEHB248
	.uleb128 .L1202-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB249-.LFB3594
	.uleb128 .LEHE249-.LEHB249
	.uleb128 .L1203-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB250-.LFB3594
	.uleb128 .LEHE250-.LEHB250
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB251-.LFB3594
	.uleb128 .LEHE251-.LEHB251
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB252-.LFB3594
	.uleb128 .LEHE252-.LEHB252
	.uleb128 .L1208-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB253-.LFB3594
	.uleb128 .LEHE253-.LEHB253
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB254-.LFB3594
	.uleb128 .LEHE254-.LEHB254
	.uleb128 .L1119-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB255-.LFB3594
	.uleb128 .LEHE255-.LEHB255
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB256-.LFB3594
	.uleb128 .LEHE256-.LEHB256
	.uleb128 .L1123-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB257-.LFB3594
	.uleb128 .LEHE257-.LEHB257
	.uleb128 .L1121-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB258-.LFB3594
	.uleb128 .LEHE258-.LEHB258
	.uleb128 .L1129-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB259-.LFB3594
	.uleb128 .LEHE259-.LEHB259
	.uleb128 .L1127-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB260-.LFB3594
	.uleb128 .LEHE260-.LEHB260
	.uleb128 .L1125-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB261-.LFB3594
	.uleb128 .LEHE261-.LEHB261
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB262-.LFB3594
	.uleb128 .LEHE262-.LEHB262
	.uleb128 .L1133-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB263-.LFB3594
	.uleb128 .LEHE263-.LEHB263
	.uleb128 .L1139-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB264-.LFB3594
	.uleb128 .LEHE264-.LEHB264
	.uleb128 .L1137-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB265-.LFB3594
	.uleb128 .LEHE265-.LEHB265
	.uleb128 .L1135-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB266-.LFB3594
	.uleb128 .LEHE266-.LEHB266
	.uleb128 .L1203-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB267-.LFB3594
	.uleb128 .LEHE267-.LEHB267
	.uleb128 .L1145-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB268-.LFB3594
	.uleb128 .LEHE268-.LEHB268
	.uleb128 .L1149-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB269-.LFB3594
	.uleb128 .LEHE269-.LEHB269
	.uleb128 .L1147-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB270-.LFB3594
	.uleb128 .LEHE270-.LEHB270
	.uleb128 .L1143-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB271-.LFB3594
	.uleb128 .LEHE271-.LEHB271
	.uleb128 .L1141-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB272-.LFB3594
	.uleb128 .LEHE272-.LEHB272
	.uleb128 .L1159-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB273-.LFB3594
	.uleb128 .LEHE273-.LEHB273
	.uleb128 .L1157-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB274-.LFB3594
	.uleb128 .LEHE274-.LEHB274
	.uleb128 .L1155-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB275-.LFB3594
	.uleb128 .LEHE275-.LEHB275
	.uleb128 .L1153-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB276-.LFB3594
	.uleb128 .LEHE276-.LEHB276
	.uleb128 .L1151-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB277-.LFB3594
	.uleb128 .LEHE277-.LEHB277
	.uleb128 .L1175-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB278-.LFB3594
	.uleb128 .LEHE278-.LEHB278
	.uleb128 .L1173-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB279-.LFB3594
	.uleb128 .LEHE279-.LEHB279
	.uleb128 .L1171-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB280-.LFB3594
	.uleb128 .LEHE280-.LEHB280
	.uleb128 .L1179-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB281-.LFB3594
	.uleb128 .LEHE281-.LEHB281
	.uleb128 .L1177-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB282-.LFB3594
	.uleb128 .LEHE282-.LEHB282
	.uleb128 .L1169-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB283-.LFB3594
	.uleb128 .LEHE283-.LEHB283
	.uleb128 .L1167-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB284-.LFB3594
	.uleb128 .LEHE284-.LEHB284
	.uleb128 .L1165-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB285-.LFB3594
	.uleb128 .LEHE285-.LEHB285
	.uleb128 .L1163-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB286-.LFB3594
	.uleb128 .LEHE286-.LEHB286
	.uleb128 .L1161-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB287-.LFB3594
	.uleb128 .LEHE287-.LEHB287
	.uleb128 .L1201-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB288-.LFB3594
	.uleb128 .LEHE288-.LEHB288
	.uleb128 .L1199-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB289-.LFB3594
	.uleb128 .LEHE289-.LEHB289
	.uleb128 .L1197-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB290-.LFB3594
	.uleb128 .LEHE290-.LEHB290
	.uleb128 .L1195-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB291-.LFB3594
	.uleb128 .LEHE291-.LEHB291
	.uleb128 .L1193-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB292-.LFB3594
	.uleb128 .LEHE292-.LEHB292
	.uleb128 .L1191-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB293-.LFB3594
	.uleb128 .LEHE293-.LEHB293
	.uleb128 .L1189-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB294-.LFB3594
	.uleb128 .LEHE294-.LEHB294
	.uleb128 .L1187-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB295-.LFB3594
	.uleb128 .LEHE295-.LEHB295
	.uleb128 .L1185-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB296-.LFB3594
	.uleb128 .LEHE296-.LEHB296
	.uleb128 .L1183-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB297-.LFB3594
	.uleb128 .LEHE297-.LEHB297
	.uleb128 .L1181-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB298-.LFB3594
	.uleb128 .LEHE298-.LEHB298
	.uleb128 .L1204-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB299-.LFB3594
	.uleb128 .LEHE299-.LEHB299
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB300-.LFB3594
	.uleb128 .LEHE300-.LEHB300
	.uleb128 .L1205-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB301-.LFB3594
	.uleb128 .LEHE301-.LEHB301
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB302-.LFB3594
	.uleb128 .LEHE302-.LEHB302
	.uleb128 .L1206-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB303-.LFB3594
	.uleb128 .LEHE303-.LEHB303
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB304-.LFB3594
	.uleb128 .LEHE304-.LEHB304
	.uleb128 .L1207-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB305-.LFB3594
	.uleb128 .LEHE305-.LEHB305
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3594:
	.align 4
	.long	0

.LLSDATT3594:
	.section	.text._ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,"axG",@progbits,_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,comdat
	.section	.text._ZN3fem12Tetrahedron4IdEC2Ev,"axG",@progbits,_ZN3fem12Tetrahedron4IdEC5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdEC2Ev
	.type	_ZN3fem12Tetrahedron4IdEC2Ev, @function
_ZN3fem12Tetrahedron4IdEC2Ev:
.LFB3535:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3535
	pushq	%r13
	.cfi_def_cfa_offset 16
	leaq	24(%rdi), %rax
	pushq	%r12
	.cfi_def_cfa_offset 24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rdi, %rbx
	.cfi_offset 3, -40
	.cfi_offset 6, -32
	.cfi_offset 12, -24
	.cfi_offset 13, -16
	subq	$56, %rsp
	.cfi_def_cfa_offset 96
	movl	$0, 24(%rdi)
	movq	$0, 32(%rdi)
	movq	$0, 56(%rdi)
	movq	%rax, 40(%rdi)
	movq	%rax, 48(%rdi)
	movq	$0, 64(%rdi)
	movq	$0, 72(%rdi)
	movq	$0, 80(%rdi)
	movq	$0, 88(%rdi)
	movq	$0, 96(%rdi)
	movq	$0, 104(%rdi)
	movq	$0, 112(%rdi)
	movq	$0, 120(%rdi)
	movq	$0, 128(%rdi)
	movq	$0, 136(%rdi)
	movq	$0, 144(%rdi)
	movq	$0, 152(%rdi)
	movq	$0, 160(%rdi)
	movq	$0, 168(%rdi)
	movq	$0, 176(%rdi)
	movq	$0, 192(%rdi)
	movq	$0, 200(%rdi)
	movq	$0, 208(%rdi)
	movq	$_ZTVN3fem17TetrahedronFamilyIdEE+16, (%rdi)
.LEHB306:
	call	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
.LEHE306:
	movq	$_ZTVN3fem12Tetrahedron4IdEE+16, (%rbx)
	movl	$4, 216(%rbx)
	movq	%rsp, %rdi
	movl	$1, 8(%rbx)
	movl	$1, 12(%rbx)
.LEHB307:
	call	_ZN3fem5pointC1Ev
.LEHE307:
	movq	72(%rbx), %r12
	movq	64(%rbx), %r13
	movq	%r12, %rax
	subq	%r13, %rax
	sarq	$5, %rax
	cmpq	$4, %rax
	jbe	.L1259
	subq	$-128, %r13
	cmpq	%r13, %r12
	je	.L1260
	movq	%r13, %rbp
	.p2align 4,,10
	.p2align 3
.L1261:
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB308:
	call	*(%rax)
.LEHE308:
	addq	$32, %rbp
	cmpq	%rbp, %r12
	jne	.L1261
.L1260:
	movq	%r13, 72(%rbx)
.L1262:
	movq	%rsp, %rdi
.LEHB309:
	call	_ZN3fem5pointD1Ev
	movq	96(%rbx), %rsi
	movq	88(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$4, %rax
	jbe	.L1263
	addq	$32, %rdx
	movq	%rdx, 96(%rbx)
.L1264:
	movq	120(%rbx), %rsi
	movq	112(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$4, %rax
	jbe	.L1265
	addq	$32, %rdx
	movq	%rdx, 120(%rbx)
.L1266:
	movq	144(%rbx), %rsi
	movq	136(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$4, %rax
	jbe	.L1267
	addq	$32, %rdx
	movq	%rdx, 144(%rbx)
.L1268:
	movq	168(%rbx), %rsi
	movq	160(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$4, %rax
	jbe	.L1269
	addq	$32, %rdx
	movq	%rdx, 168(%rbx)
	addq	$56, %rsp
	.cfi_remember_state
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
	.p2align 4,,10
	.p2align 3
.L1263:
	.cfi_restore_state
	movl	$4, %edx
	leaq	88(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	jmp	.L1264
	.p2align 4,,10
	.p2align 3
.L1269:
	movl	$4, %edx
	leaq	160(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	addq	$56, %rsp
	.cfi_remember_state
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
	.p2align 4,,10
	.p2align 3
.L1267:
	.cfi_restore_state
	movl	$4, %edx
	leaq	136(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	jmp	.L1268
	.p2align 4,,10
	.p2align 3
.L1265:
	movl	$4, %edx
	leaq	112(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
.LEHE309:
	jmp	.L1266
	.p2align 4,,10
	.p2align 3
.L1259:
	movl	$4, %edx
	leaq	64(%rbx), %rdi
	movq	%rsp, %rcx
	subq	%rax, %rdx
	movq	%r12, %rsi
.LEHB310:
	call	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
.LEHE310:
	jmp	.L1262
.L1274:
	movq	%rax, %rbp
.L1272:
	movq	%rbx, %rdi
	movq	$_ZTVN3fem17TetrahedronFamilyIdEE+16, (%rbx)
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB311:
	call	_Unwind_Resume
.LEHE311:
.L1275:
	movq	%rsp, %rdi
	movq	%rax, %rbp
	call	_ZN3fem5pointD1Ev
	jmp	.L1272
.L1276:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB312:
	call	_Unwind_Resume
.LEHE312:
	.cfi_endproc
.LFE3535:
	.size	_ZN3fem12Tetrahedron4IdEC2Ev, .-_ZN3fem12Tetrahedron4IdEC2Ev
	.section	.gcc_except_table
.LLSDA3535:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3535-.LLSDACSB3535
.LLSDACSB3535:
	.uleb128 .LEHB306-.LFB3535
	.uleb128 .LEHE306-.LEHB306
	.uleb128 .L1276-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB307-.LFB3535
	.uleb128 .LEHE307-.LEHB307
	.uleb128 .L1274-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB308-.LFB3535
	.uleb128 .LEHE308-.LEHB308
	.uleb128 .L1275-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB309-.LFB3535
	.uleb128 .LEHE309-.LEHB309
	.uleb128 .L1274-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB310-.LFB3535
	.uleb128 .LEHE310-.LEHB310
	.uleb128 .L1275-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB311-.LFB3535
	.uleb128 .LEHE311-.LEHB311
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB312-.LFB3535
	.uleb128 .LEHE312-.LEHB312
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3535:
	.section	.text._ZN3fem12Tetrahedron4IdEC2Ev,"axG",@progbits,_ZN3fem12Tetrahedron4IdEC5Ev,comdat
	.weak	_ZN3fem12Tetrahedron4IdEC1Ev
	.set	_ZN3fem12Tetrahedron4IdEC1Ev,_ZN3fem12Tetrahedron4IdEC2Ev
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB3494:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3494
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$264, %rsp
	.cfi_def_cfa_offset 288
	movq	%rsp, %rdi
.LEHB313:
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	call	_ZN3fem12Tetrahedron4IdEC1Ev
.LEHE313:
	leaq	224(%rsp), %rdi
.LEHB314:
	call	_ZN3fem5pointC1Ev
	movsd	.LC0(%rip), %xmm0
	movq	88(%rsp), %rax
	leaq	224(%rsp), %rdi
	subsd	248(%rsp), %xmm0
	subsd	240(%rsp), %xmm0
	subsd	232(%rsp), %xmm0
	movsd	%xmm0, (%rax)
	movq	232(%rsp), %rdx
	movq	%rdx, 8(%rax)
	movq	240(%rsp), %rdx
	movq	%rdx, 16(%rax)
	movq	248(%rsp), %rdx
	movq	%rdx, 24(%rax)
	call	_ZN3fem5pointD1Ev
.LEHE314:
	movq	192(%rsp), %rdi
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rsp)
	testq	%rdi, %rdi
	je	.L1284
	call	_ZdlPv
.L1284:
	movq	160(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1289
	call	_ZdlPv
.L1289:
	movq	136(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1294
	call	_ZdlPv
.L1294:
	movq	112(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1299
	call	_ZdlPv
.L1299:
	movq	88(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1304
	call	_ZdlPv
.L1304:
	movq	72(%rsp), %rbp
	movq	64(%rsp), %rbx
	cmpq	%rbx, %rbp
	je	.L1305
	.p2align 4,,10
	.p2align 3
.L1329:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB315:
	call	*(%rax)
.LEHE315:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L1329
	movq	64(%rsp), %rbx
.L1305:
	testq	%rbx, %rbx
	je	.L1317
	movq	%rbx, %rdi
	call	_ZdlPv
.L1317:
	movq	32(%rsp), %rsi
	leaq	16(%rsp), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE8_M_eraseEPSt13_Rb_tree_nodeISC_E
	addq	$264, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L1327:
	.cfi_restore_state
	movq	%rax, %rbx
	movq	%rsp, %rdi
	call	_ZN3fem12Tetrahedron4IdED1Ev
	movq	%rbx, %rdi
.LEHB316:
	call	_Unwind_Resume
.L1328:
	movq	64(%rsp), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L1312
	call	_ZdlPv
.L1312:
	leaq	16(%rsp), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE316:
	.cfi_endproc
.LFE3494:
	.size	main, .-main
	.section	.gcc_except_table
.LLSDA3494:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3494-.LLSDACSB3494
.LLSDACSB3494:
	.uleb128 .LEHB313-.LFB3494
	.uleb128 .LEHE313-.LEHB313
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB314-.LFB3494
	.uleb128 .LEHE314-.LEHB314
	.uleb128 .L1327-.LFB3494
	.uleb128 0x0
	.uleb128 .LEHB315-.LFB3494
	.uleb128 .LEHE315-.LEHB315
	.uleb128 .L1328-.LFB3494
	.uleb128 0x0
	.uleb128 .LEHB316-.LFB3494
	.uleb128 .LEHE316-.LEHB316
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3494:
	.text
	.section	.text._ZNSt6vectorImSaImEEaSERKS1_,"axG",@progbits,_ZNSt6vectorImSaImEEaSERKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorImSaImEEaSERKS1_
	.type	_ZNSt6vectorImSaImEEaSERKS1_, @function
_ZNSt6vectorImSaImEEaSERKS1_:
.LFB4046:
	.cfi_startproc
	movq	%rbx, -40(%rsp)
	movq	%r12, -24(%rsp)
	movq	%rdi, %rbx
	.cfi_offset 12, -32
	.cfi_offset 3, -48
	movq	%rbp, -32(%rsp)
	movq	%r13, -16(%rsp)
	movq	%rsi, %r12
	movq	%r14, -8(%rsp)
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	cmpq	%rdi, %rsi
	je	.L1332
	.cfi_offset 14, -16
	.cfi_offset 13, -24
	.cfi_offset 6, -40
	movq	8(%rsi), %rcx
	movq	(%rdi), %rdi
	movq	(%rsi), %r14
	movq	16(%rbx), %rdx
	movq	%rcx, %rbp
	movq	%rdi, %rax
	subq	%r14, %rbp
	subq	%rdi, %rdx
	sarq	$3, %rbp
	sarq	$3, %rdx
	cmpq	%rdx, %rbp
	jbe	.L1333
	testq	%rbp, %rbp
	je	.L1343
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbp
	ja	.L1348
	leaq	0(,%rbp,8), %r13
	movq	%r13, %rdi
	call	_Znwm
	testq	%rbp, %rbp
	movq	%rax, %r12
	jne	.L1349
.L1346:
	movq	(%rbx), %rdi
.L1336:
	testq	%rdi, %rdi
	je	.L1337
	call	_ZdlPv
.L1337:
	movq	%r12, (%rbx)
	addq	%r13, %r12
	movq	%r12, 16(%rbx)
.L1338:
	movq	%r12, 8(%rbx)
.L1332:
	movq	%rbx, %rax
	movq	8(%rsp), %rbp
	movq	(%rsp), %rbx
	movq	16(%rsp), %r12
	movq	24(%rsp), %r13
	movq	32(%rsp), %r14
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L1333:
	.cfi_restore_state
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%rax, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %rbp
	ja	.L1339
	testq	%rbp, %rbp
	jne	.L1350
.L1347:
	leaq	0(,%rbp,8), %r12
	addq	(%rbx), %r12
	jmp	.L1338
	.p2align 4,,10
	.p2align 3
.L1339:
	testq	%rdx, %rdx
	leaq	(%r14,%rdx,8), %rsi
	jne	.L1351
.L1341:
	subq	%rsi, %rcx
	leaq	(%rax,%rbp,8), %r12
	sarq	$3, %rcx
	testq	%rcx, %rcx
	je	.L1338
	leaq	0(,%rcx,8), %rdx
	call	memmove
	jmp	.L1347
	.p2align 4,,10
	.p2align 3
.L1349:
	movq	%r13, %rdx
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	memmove
	jmp	.L1346
	.p2align 4,,10
	.p2align 3
.L1350:
	leaq	0(,%rbp,8), %rdx
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	memmove
	jmp	.L1347
	.p2align 4,,10
	.p2align 3
.L1351:
	movq	%r14, %rsi
	movq	%rax, %rdi
	salq	$3, %rdx
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %rax
	movq	8(%r12), %rcx
	movq	%rdi, %rsi
	subq	%rax, %rsi
	andq	$-8, %rsi
	addq	(%r12), %rsi
	jmp	.L1341
	.p2align 4,,10
	.p2align 3
.L1343:
	xorl	%r13d, %r13d
	xorl	%r12d, %r12d
	jmp	.L1336
.L1348:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE4046:
	.size	_ZNSt6vectorImSaImEEaSERKS1_, .-_ZNSt6vectorImSaImEEaSERKS1_
	.section	.rodata.str1.1
.LC31:
	.string	"Tetrahedron4.h++"
.LC32:
	.string	"nodes.size() == 4"
	.section	.text._ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE,"axG",@progbits,_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE
	.type	_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE, @function
_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE:
.LFB4042:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rsi), %rax
	subq	(%rsi), %rax
	sarq	$3, %rax
	cmpq	$4, %rax
	jne	.L1354
	addq	$192, %rdi
	call	_ZNSt6vectorImSaImEEaSERKS1_
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L1354:
	.cfi_restore_state
	movl	$_ZZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, %ecx
	movl	$162, %edx
	movl	$.LC31, %esi
	movl	$.LC32, %edi
	call	__assert_fail
	.cfi_endproc
.LFE4042:
	.size	_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE, .-_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE
	.text
	.p2align 4,,15
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB4089:
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
.LFE4089:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__I_main
	.local	_ZN5boost6tuplesL6ignoreE
	.comm	_ZN5boost6tuplesL6ignoreE,1,1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.weak	_ZTVN3fem12Tetrahedron4IdEE
	.section	.rodata._ZTVN3fem12Tetrahedron4IdEE,"aG",@progbits,_ZTVN3fem12Tetrahedron4IdEE,comdat
	.align 32
	.type	_ZTVN3fem12Tetrahedron4IdEE, @object
	.size	_ZTVN3fem12Tetrahedron4IdEE, 112
_ZTVN3fem12Tetrahedron4IdEE:
	.quad	0
	.quad	_ZTIN3fem12Tetrahedron4IdEE
	.quad	_ZN3fem12Tetrahedron4IdE14setCoordinatesEv
	.quad	_ZN3fem12Tetrahedron4IdE4setNERKNS_5pointE
	.quad	_ZN3fem12Tetrahedron4IdE4setNERKdS3_S3_
	.quad	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKNS_5pointE
	.quad	_ZN3fem12Tetrahedron4IdE9setdNdcsiERKdS3_S3_
	.quad	_ZN3fem12Tetrahedron4IdE9setdNdetaERKNS_5pointE
	.quad	_ZN3fem12Tetrahedron4IdE9setdNdetaERKdS3_S3_
	.quad	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKNS_5pointE
	.quad	_ZN3fem12Tetrahedron4IdE10setdNdzetaERKdS3_S3_
	.quad	_ZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEE
	.quad	_ZNK3fem12Tetrahedron4IdE11node_numberEv
	.quad	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
	.section	.rodata
	.align 32
	.type	_ZZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, @object
	.size	_ZZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, 184
_ZZN3fem12Tetrahedron4IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__:
	.string	"typename fem::BaseElement<T>::Error fem::Tetrahedron4<T>::set(std::vector<long unsigned int>&) [with T = double, typename fem::BaseElement<T>::Error = fem::BaseElement<double>::Error]"
	.weak	_ZTVN3fem17TetrahedronFamilyIdEE
	.section	.rodata._ZTVN3fem17TetrahedronFamilyIdEE,"aG",@progbits,_ZTVN3fem17TetrahedronFamilyIdEE,comdat
	.align 32
	.type	_ZTVN3fem17TetrahedronFamilyIdEE, @object
	.size	_ZTVN3fem17TetrahedronFamilyIdEE, 112
_ZTVN3fem17TetrahedronFamilyIdEE:
	.quad	0
	.quad	_ZTIN3fem17TetrahedronFamilyIdEE
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
	.quad	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
	.weak	_ZTVN3fem11BaseElementIdEE
	.section	.rodata._ZTVN3fem11BaseElementIdEE,"aG",@progbits,_ZTVN3fem11BaseElementIdEE,comdat
	.align 32
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
	.weak	_ZTIN3fem12Tetrahedron4IdEE
	.section	.rodata._ZTIN3fem12Tetrahedron4IdEE,"aG",@progbits,_ZTIN3fem12Tetrahedron4IdEE,comdat
	.align 16
	.type	_ZTIN3fem12Tetrahedron4IdEE, @object
	.size	_ZTIN3fem12Tetrahedron4IdEE, 24
_ZTIN3fem12Tetrahedron4IdEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3fem12Tetrahedron4IdEE
	.quad	_ZTIN3fem17TetrahedronFamilyIdEE
	.weak	_ZTIN3fem17TetrahedronFamilyIdEE
	.section	.rodata._ZTIN3fem17TetrahedronFamilyIdEE,"aG",@progbits,_ZTIN3fem17TetrahedronFamilyIdEE,comdat
	.align 16
	.type	_ZTIN3fem17TetrahedronFamilyIdEE, @object
	.size	_ZTIN3fem17TetrahedronFamilyIdEE, 24
_ZTIN3fem17TetrahedronFamilyIdEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3fem17TetrahedronFamilyIdEE
	.quad	_ZTIN3fem11BaseElementIdEE
	.weak	_ZTIN3fem11BaseElementIdEE
	.section	.rodata._ZTIN3fem11BaseElementIdEE,"aG",@progbits,_ZTIN3fem11BaseElementIdEE,comdat
	.align 16
	.type	_ZTIN3fem11BaseElementIdEE, @object
	.size	_ZTIN3fem11BaseElementIdEE, 16
_ZTIN3fem11BaseElementIdEE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN3fem11BaseElementIdEE
	.weak	_ZTSN3fem12Tetrahedron4IdEE
	.section	.rodata._ZTSN3fem12Tetrahedron4IdEE,"aG",@progbits,_ZTSN3fem12Tetrahedron4IdEE,comdat
	.align 16
	.type	_ZTSN3fem12Tetrahedron4IdEE, @object
	.size	_ZTSN3fem12Tetrahedron4IdEE, 24
_ZTSN3fem12Tetrahedron4IdEE:
	.string	"N3fem12Tetrahedron4IdEE"
	.weak	_ZTSN3fem17TetrahedronFamilyIdEE
	.section	.rodata._ZTSN3fem17TetrahedronFamilyIdEE,"aG",@progbits,_ZTSN3fem17TetrahedronFamilyIdEE,comdat
	.align 16
	.type	_ZTSN3fem17TetrahedronFamilyIdEE, @object
	.size	_ZTSN3fem17TetrahedronFamilyIdEE, 29
_ZTSN3fem17TetrahedronFamilyIdEE:
	.string	"N3fem17TetrahedronFamilyIdEE"
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
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC13:
	.long	0
	.long	1074266112
	.align 8
.LC21:
	.long	0
	.long	1071644672
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
