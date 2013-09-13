	.file	"main.c++"
	.section	.text._ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE,"axG",@progbits,_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE
	.type	_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE, @function
_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE:
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
	.size	_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE, .-_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE
	.section	.text._ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_,"axG",@progbits,_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_
	.type	_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_, @function
_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_:
.LFB3574:
	.cfi_startproc
	movsd	(%rcx), %xmm1
	movq	88(%rdi), %rax
	movsd	.LC0(%rip), %xmm0
	movsd	.LC1(%rip), %xmm4
	xorpd	%xmm0, %xmm1
	movsd	.LC2(%rip), %xmm3
	subsd	(%rdx), %xmm1
	subsd	(%rsi), %xmm1
	movapd	%xmm1, %xmm2
	addsd	%xmm3, %xmm1
	addsd	%xmm4, %xmm2
	addsd	%xmm2, %xmm2
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, (%rax)
	movsd	(%rsi), %xmm2
	movapd	%xmm2, %xmm1
	subsd	%xmm4, %xmm1
	addsd	%xmm1, %xmm1
	mulsd	%xmm2, %xmm1
	movsd	%xmm1, 8(%rax)
	movsd	(%rdx), %xmm2
	movapd	%xmm2, %xmm1
	subsd	%xmm4, %xmm1
	addsd	%xmm1, %xmm1
	mulsd	%xmm2, %xmm1
	movsd	%xmm1, 16(%rax)
	movsd	(%rcx), %xmm2
	movapd	%xmm2, %xmm1
	subsd	%xmm4, %xmm1
	addsd	%xmm1, %xmm1
	mulsd	%xmm2, %xmm1
	movsd	.LC3(%rip), %xmm2
	movsd	%xmm1, 24(%rax)
	movsd	(%rcx), %xmm1
	movsd	(%rsi), %xmm5
	xorpd	%xmm0, %xmm1
	movapd	%xmm5, %xmm4
	subsd	(%rdx), %xmm1
	mulsd	%xmm2, %xmm4
	subsd	%xmm5, %xmm1
	addsd	%xmm3, %xmm1
	mulsd	%xmm1, %xmm4
	movsd	%xmm4, 32(%rax)
	movsd	(%rsi), %xmm1
	mulsd	%xmm2, %xmm1
	mulsd	(%rdx), %xmm1
	movsd	%xmm1, 40(%rax)
	movsd	(%rcx), %xmm1
	movsd	(%rdx), %xmm5
	xorpd	%xmm0, %xmm1
	movapd	%xmm5, %xmm4
	subsd	%xmm5, %xmm1
	mulsd	%xmm2, %xmm4
	subsd	(%rsi), %xmm1
	addsd	%xmm3, %xmm1
	mulsd	%xmm1, %xmm4
	movsd	%xmm4, 48(%rax)
	movsd	(%rcx), %xmm1
	xorpd	%xmm1, %xmm0
	subsd	(%rdx), %xmm0
	subsd	(%rsi), %xmm0
	addsd	%xmm3, %xmm0
	mulsd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 56(%rax)
	movsd	(%rdx), %xmm0
	mulsd	%xmm2, %xmm0
	mulsd	(%rcx), %xmm0
	movsd	%xmm0, 64(%rax)
	mulsd	(%rsi), %xmm2
	mulsd	(%rcx), %xmm2
	movsd	%xmm2, 72(%rax)
	leaq	88(%rdi), %rax
	ret
	.cfi_endproc
.LFE3574:
	.size	_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_, .-_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_
	.section	.text._ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE,"axG",@progbits,_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE
	.type	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE, @function
_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE:
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
	.size	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE, .-_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE
	.section	.text._ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_,"axG",@progbits,_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_
	.type	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_, @function
_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_:
.LFB4037:
	.cfi_startproc
	movsd	(%rcx), %xmm0
	movq	112(%rdi), %rax
	movsd	.LC0(%rip), %xmm4
	xorl	%r8d, %r8d
	movsd	.LC2(%rip), %xmm3
	xorpd	%xmm4, %xmm0
	movsd	.LC1(%rip), %xmm2
	subsd	(%rdx), %xmm0
	subsd	(%rsi), %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm2, %xmm0
	addsd	%xmm3, %xmm1
	addsd	%xmm0, %xmm0
	mulsd	.LC4(%rip), %xmm1
	subsd	%xmm0, %xmm1
	movsd	%xmm1, (%rax)
	movsd	(%rsi), %xmm0
	movq	%r8, 16(%rax)
	movq	%r8, 24(%rax)
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	subsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, 8(%rax)
	movsd	.LC3(%rip), %xmm1
	movsd	(%rcx), %xmm0
	movsd	(%rsi), %xmm2
	xorpd	%xmm4, %xmm0
	subsd	(%rdx), %xmm0
	subsd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm2
	addsd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	subsd	%xmm2, %xmm0
	movsd	%xmm0, 32(%rax)
	movsd	(%rdx), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 40(%rax)
	movsd	.LC6(%rip), %xmm0
	movsd	(%rdx), %xmm2
	mulsd	%xmm0, %xmm2
	movsd	%xmm2, 48(%rax)
	mulsd	(%rcx), %xmm0
	movq	%r8, 64(%rax)
	movsd	%xmm0, 56(%rax)
	mulsd	(%rcx), %xmm1
	movsd	%xmm1, 72(%rax)
	leaq	112(%rdi), %rax
	ret
	.cfi_endproc
.LFE4037:
	.size	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_, .-_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_
	.section	.text._ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE,"axG",@progbits,_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE
	.type	_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE, @function
_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE:
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
	.size	_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE, .-_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE
	.section	.text._ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_,"axG",@progbits,_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_
	.type	_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_, @function
_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_:
.LFB4039:
	.cfi_startproc
	movsd	(%rcx), %xmm0
	movq	136(%rdi), %rax
	movsd	.LC0(%rip), %xmm5
	xorl	%r8d, %r8d
	movsd	.LC2(%rip), %xmm4
	xorpd	%xmm5, %xmm0
	movsd	.LC1(%rip), %xmm2
	subsd	(%rdx), %xmm0
	subsd	(%rsi), %xmm0
	movq	%r8, 8(%rax)
	movapd	%xmm0, %xmm1
	addsd	%xmm2, %xmm0
	addsd	%xmm4, %xmm1
	addsd	%xmm0, %xmm0
	mulsd	.LC4(%rip), %xmm1
	subsd	%xmm0, %xmm1
	movsd	%xmm1, (%rax)
	movsd	(%rdx), %xmm0
	movq	%r8, 24(%rax)
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	subsd	%xmm2, %xmm0
	movsd	.LC6(%rip), %xmm2
	addsd	%xmm0, %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, 16(%rax)
	movsd	.LC3(%rip), %xmm1
	movsd	(%rsi), %xmm0
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, 32(%rax)
	movsd	(%rsi), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 40(%rax)
	movsd	(%rcx), %xmm0
	movsd	(%rdx), %xmm3
	xorpd	%xmm5, %xmm0
	subsd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm3
	subsd	(%rsi), %xmm0
	addsd	%xmm4, %xmm0
	mulsd	%xmm1, %xmm0
	subsd	%xmm3, %xmm0
	movsd	%xmm0, 48(%rax)
	mulsd	(%rcx), %xmm2
	movsd	%xmm2, 56(%rax)
	mulsd	(%rcx), %xmm1
	movq	%r8, 72(%rax)
	movsd	%xmm1, 64(%rax)
	leaq	136(%rdi), %rax
	ret
	.cfi_endproc
.LFE4039:
	.size	_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_, .-_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_
	.section	.text._ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE,"axG",@progbits,_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE
	.type	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE, @function
_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE:
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
	.size	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE, .-_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE
	.section	.text._ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_,"axG",@progbits,_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_
	.type	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_, @function
_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_:
.LFB4041:
	.cfi_startproc
	movsd	(%rcx), %xmm1
	movq	160(%rdi), %rax
	movsd	.LC0(%rip), %xmm0
	xorl	%r8d, %r8d
	movsd	.LC2(%rip), %xmm3
	xorpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm4
	subsd	(%rdx), %xmm1
	subsd	(%rsi), %xmm1
	movq	%r8, 8(%rax)
	movq	%r8, 16(%rax)
	movapd	%xmm1, %xmm2
	addsd	%xmm4, %xmm1
	addsd	%xmm3, %xmm2
	addsd	%xmm1, %xmm1
	mulsd	.LC4(%rip), %xmm2
	subsd	%xmm1, %xmm2
	movsd	%xmm2, (%rax)
	movsd	(%rcx), %xmm1
	movapd	%xmm1, %xmm2
	addsd	%xmm1, %xmm2
	subsd	%xmm4, %xmm1
	addsd	%xmm1, %xmm1
	addsd	%xmm1, %xmm2
	movsd	.LC6(%rip), %xmm1
	movsd	%xmm2, 24(%rax)
	movsd	(%rsi), %xmm2
	movq	%r8, 40(%rax)
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, 32(%rax)
	mulsd	(%rdx), %xmm1
	movsd	%xmm1, 48(%rax)
	movsd	.LC3(%rip), %xmm1
	movsd	(%rcx), %xmm2
	xorpd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm2
	subsd	(%rdx), %xmm0
	subsd	(%rsi), %xmm0
	addsd	%xmm3, %xmm0
	mulsd	%xmm1, %xmm0
	subsd	%xmm2, %xmm0
	movsd	%xmm0, 56(%rax)
	movsd	(%rdx), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 64(%rax)
	mulsd	(%rsi), %xmm1
	movsd	%xmm1, 72(%rax)
	leaq	160(%rdi), %rax
	ret
	.cfi_endproc
.LFE4041:
	.size	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_, .-_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_
	.section	.text._ZNK3fem13Tetrahedron10IdE11node_numberEv,"axG",@progbits,_ZNK3fem13Tetrahedron10IdE11node_numberEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNK3fem13Tetrahedron10IdE11node_numberEv
	.type	_ZNK3fem13Tetrahedron10IdE11node_numberEv, @function
_ZNK3fem13Tetrahedron10IdE11node_numberEv:
.LFB4043:
	.cfi_startproc
	movl	$10, %eax
	ret
	.cfi_endproc
.LFE4043:
	.size	_ZNK3fem13Tetrahedron10IdE11node_numberEv, .-_ZNK3fem13Tetrahedron10IdE11node_numberEv
	.section	.text._ZN3fem13Tetrahedron10IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem13Tetrahedron10IdE14setCoordinatesEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE14setCoordinatesEv
	.type	_ZN3fem13Tetrahedron10IdE14setCoordinatesEv, @function
_ZN3fem13Tetrahedron10IdE14setCoordinatesEv:
.LFB4035:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA4035
	pushq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rdi, %rbx
	.cfi_offset 3, -16
	subq	$880, %rsp
	.cfi_def_cfa_offset 896
	leaq	864(%rsp), %rdx
	leaq	872(%rsp), %rsi
	leaq	608(%rsp), %rdi
	leaq	856(%rsp), %rcx
	movq	$0, 856(%rsp)
	movq	$0, 864(%rsp)
	movq	$0, 872(%rsp)
.LEHB0:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE0:
	movq	64(%rbx), %rsi
	leaq	608(%rsp), %rdx
	leaq	576(%rsp), %rdi
.LEHB1:
	call	_ZN3fem5pointaSERKS0_
	leaq	576(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE1:
	leaq	608(%rsp), %rdi
.LEHB2:
	call	_ZN3fem5pointD1Ev
	leaq	840(%rsp), %rdx
	leaq	848(%rsp), %rsi
	leaq	544(%rsp), %rdi
	leaq	832(%rsp), %rcx
	movabsq	$4607182418800017408, %rax
	movq	$0, 832(%rsp)
	movq	$0, 840(%rsp)
	movq	%rax, 848(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE2:
	movq	64(%rbx), %rsi
	leaq	544(%rsp), %rdx
	leaq	512(%rsp), %rdi
	addq	$32, %rsi
.LEHB3:
	call	_ZN3fem5pointaSERKS0_
	leaq	512(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE3:
	leaq	544(%rsp), %rdi
.LEHB4:
	call	_ZN3fem5pointD1Ev
	leaq	816(%rsp), %rdx
	leaq	824(%rsp), %rsi
	leaq	480(%rsp), %rdi
	leaq	808(%rsp), %rcx
	movabsq	$4607182418800017408, %rax
	movq	$0, 808(%rsp)
	movq	%rax, 816(%rsp)
	movq	$0, 824(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE4:
	movq	64(%rbx), %rsi
	leaq	480(%rsp), %rdx
	leaq	448(%rsp), %rdi
	addq	$64, %rsi
.LEHB5:
	call	_ZN3fem5pointaSERKS0_
	leaq	448(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE5:
	leaq	480(%rsp), %rdi
.LEHB6:
	call	_ZN3fem5pointD1Ev
	leaq	792(%rsp), %rdx
	leaq	800(%rsp), %rsi
	leaq	416(%rsp), %rdi
	leaq	784(%rsp), %rcx
	movabsq	$4607182418800017408, %rax
	movq	$0, 792(%rsp)
	movq	%rax, 784(%rsp)
	movq	$0, 800(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE6:
	movq	64(%rbx), %rsi
	leaq	416(%rsp), %rdx
	leaq	384(%rsp), %rdi
	addq	$96, %rsi
.LEHB7:
	call	_ZN3fem5pointaSERKS0_
	leaq	384(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE7:
	leaq	416(%rsp), %rdi
.LEHB8:
	call	_ZN3fem5pointD1Ev
	leaq	768(%rsp), %rdx
	leaq	776(%rsp), %rsi
	leaq	352(%rsp), %rdi
	leaq	760(%rsp), %rcx
	movabsq	$4602678819172646912, %rax
	movq	$0, 760(%rsp)
	movq	$0, 768(%rsp)
	movq	%rax, 776(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE8:
	movq	64(%rbx), %rsi
	leaq	352(%rsp), %rdx
	leaq	320(%rsp), %rdi
	subq	$-128, %rsi
.LEHB9:
	call	_ZN3fem5pointaSERKS0_
	leaq	320(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE9:
	leaq	352(%rsp), %rdi
.LEHB10:
	call	_ZN3fem5pointD1Ev
	leaq	744(%rsp), %rdx
	leaq	752(%rsp), %rsi
	leaq	288(%rsp), %rdi
	leaq	736(%rsp), %rcx
	movabsq	$4602678819172646912, %r10
	movabsq	$4602678819172646912, %r11
	movq	$0, 736(%rsp)
	movq	%r10, 744(%rsp)
	movq	%r11, 752(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE10:
	movq	64(%rbx), %rsi
	leaq	288(%rsp), %rdx
	leaq	256(%rsp), %rdi
	addq	$160, %rsi
.LEHB11:
	call	_ZN3fem5pointaSERKS0_
	leaq	256(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE11:
	leaq	288(%rsp), %rdi
.LEHB12:
	call	_ZN3fem5pointD1Ev
	leaq	720(%rsp), %rdx
	leaq	728(%rsp), %rsi
	leaq	224(%rsp), %rdi
	leaq	712(%rsp), %rcx
	movabsq	$4602678819172646912, %r9
	movq	$0, 712(%rsp)
	movq	%r9, 720(%rsp)
	movq	$0, 728(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE12:
	movq	64(%rbx), %rsi
	leaq	224(%rsp), %rdx
	leaq	192(%rsp), %rdi
	addq	$192, %rsi
.LEHB13:
	call	_ZN3fem5pointaSERKS0_
	leaq	192(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE13:
	leaq	224(%rsp), %rdi
.LEHB14:
	call	_ZN3fem5pointD1Ev
	leaq	696(%rsp), %rdx
	leaq	704(%rsp), %rsi
	leaq	160(%rsp), %rdi
	leaq	688(%rsp), %rcx
	movabsq	$4602678819172646912, %r8
	movq	$0, 696(%rsp)
	movq	%r8, 688(%rsp)
	movq	$0, 704(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE14:
	movq	64(%rbx), %rsi
	leaq	160(%rsp), %rdx
	leaq	128(%rsp), %rdi
	addq	$224, %rsi
.LEHB15:
	call	_ZN3fem5pointaSERKS0_
	leaq	128(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE15:
	leaq	160(%rsp), %rdi
.LEHB16:
	call	_ZN3fem5pointD1Ev
	movabsq	$4602678819172646912, %rsi
	movabsq	$4602678819172646912, %rdi
	leaq	672(%rsp), %rdx
	movq	%rsi, 664(%rsp)
	movq	%rdi, 672(%rsp)
	leaq	680(%rsp), %rsi
	leaq	96(%rsp), %rdi
	leaq	664(%rsp), %rcx
	movq	$0, 680(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE16:
	movq	64(%rbx), %rsi
	leaq	96(%rsp), %rdx
	leaq	64(%rsp), %rdi
	addq	$256, %rsi
.LEHB17:
	call	_ZN3fem5pointaSERKS0_
	leaq	64(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE17:
	leaq	96(%rsp), %rdi
.LEHB18:
	call	_ZN3fem5pointD1Ev
	movabsq	$4602678819172646912, %rdx
	movabsq	$4602678819172646912, %rcx
	leaq	656(%rsp), %rsi
	movq	%rdx, 648(%rsp)
	movq	%rcx, 656(%rsp)
	leaq	648(%rsp), %rdx
	leaq	32(%rsp), %rdi
	leaq	640(%rsp), %rcx
	movabsq	$4602678819172646912, %rax
	movq	%rax, 640(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE18:
	movq	64(%rbx), %rsi
	leaq	32(%rsp), %rdx
	movq	%rsp, %rdi
	addq	$288, %rsi
.LEHB19:
	call	_ZN3fem5pointaSERKS0_
	movq	%rsp, %rdi
	call	_ZN3fem5pointD1Ev
.LEHE19:
	leaq	32(%rsp), %rdi
.LEHB20:
	call	_ZN3fem5pointD1Ev
.LEHE20:
	leaq	64(%rbx), %rax
	addq	$880, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	leaq	608(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB21:
	call	_Unwind_Resume
.LEHE21:
.L30:
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB22:
	call	_Unwind_Resume
.LEHE22:
.L29:
	leaq	96(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB23:
	call	_Unwind_Resume
.LEHE23:
.L28:
	leaq	160(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB24:
	call	_Unwind_Resume
.LEHE24:
.L27:
	leaq	224(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB25:
	call	_Unwind_Resume
.LEHE25:
.L26:
	leaq	288(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB26:
	call	_Unwind_Resume
.LEHE26:
.L25:
	leaq	352(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB27:
	call	_Unwind_Resume
.LEHE27:
.L24:
	leaq	416(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB28:
	call	_Unwind_Resume
.LEHE28:
.L23:
	leaq	480(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB29:
	call	_Unwind_Resume
.LEHE29:
.L22:
	leaq	544(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB30:
	call	_Unwind_Resume
.LEHE30:
	.cfi_endproc
.LFE4035:
	.size	_ZN3fem13Tetrahedron10IdE14setCoordinatesEv, .-_ZN3fem13Tetrahedron10IdE14setCoordinatesEv
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
	.uleb128 .L21-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB2-.LFB4035
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB3-.LFB4035
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L22-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB4-.LFB4035
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB5-.LFB4035
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L23-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB6-.LFB4035
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB7-.LFB4035
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L24-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB8-.LFB4035
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB9-.LFB4035
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L25-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB10-.LFB4035
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB11-.LFB4035
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L26-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB12-.LFB4035
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB13-.LFB4035
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L27-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB14-.LFB4035
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB15-.LFB4035
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L28-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB16-.LFB4035
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB17-.LFB4035
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L29-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB18-.LFB4035
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB19-.LFB4035
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L30-.LFB4035
	.uleb128 0x0
	.uleb128 .LEHB20-.LFB4035
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB21-.LFB4035
	.uleb128 .LEHE21-.LEHB21
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB22-.LFB4035
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB23-.LFB4035
	.uleb128 .LEHE23-.LEHB23
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB24-.LFB4035
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB25-.LFB4035
	.uleb128 .LEHE25-.LEHB25
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB26-.LFB4035
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB27-.LFB4035
	.uleb128 .LEHE27-.LEHB27
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB28-.LFB4035
	.uleb128 .LEHE28-.LEHB28
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB29-.LFB4035
	.uleb128 .LEHE29-.LEHB29
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB30-.LFB4035
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE4035:
	.section	.text._ZN3fem13Tetrahedron10IdE14setCoordinatesEv,"axG",@progbits,_ZN3fem13Tetrahedron10IdE14setCoordinatesEv,comdat
	.text
	.align 2
	.p2align 4,,15
	.type	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33, @function
_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33:
.LFB4123:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L32
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L32:
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
	je	.L38
	.p2align 4,,10
	.p2align 3
.L47:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L47
.L38:
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L37
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
.L37:
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
.L50:
	cmpq	$0, 56(%rsp)
	je	.L190
	.cfi_offset 3, -56
	movq	56(%rsp), %rax
	movq	24(%rax), %r13
.L51:
	testq	%r13, %r13
	je	.L191
	movq	24(%r13), %r14
.L52:
	testq	%r14, %r14
	je	.L192
	movq	24(%r14), %r15
.L53:
	testq	%r15, %r15
	je	.L193
	movq	24(%r15), %rdx
	movq	%rdx, 32(%rsp)
.L54:
	cmpq	$0, 32(%rsp)
	je	.L194
	movq	32(%rsp), %rax
	movq	24(%rax), %rax
	movq	%rax, 40(%rsp)
.L55:
	cmpq	$0, 40(%rsp)
	je	.L195
	movq	40(%rsp), %rdx
	movq	24(%rdx), %rdx
	testq	%rdx, %rdx
	movq	%rdx, 48(%rsp)
	je	.L56
.L187:
	movq	48(%rsp), %rdx
	movq	24(%rdx), %r12
	testq	%r12, %r12
	je	.L57
.L188:
	movq	24(%r12), %rbx
	testq	%rbx, %rbx
	je	.L58
	.p2align 4,,10
	.p2align 3
.L189:
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
	je	.L59
	.p2align 4,,10
	.p2align 3
.L182:
	movq	%rax, %rdi
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
	addq	$40, %rax
	cmpq	%rax, 8(%rsp)
	jne	.L182
.L59:
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L70
	call	_ZdlPv
.L70:
	movq	%rbx, %rdi
	call	_ZdlPv
	cmpq	$0, 16(%rsp)
	je	.L58
	movq	16(%rsp), %rbx
	jmp	.L189
.L58:
	movq	16(%r12), %rax
	movq	40(%r12), %rbx
	leaq	40(%r12), %rdx
	movq	%rdx, 24(%rsp)
	movq	%rax, 16(%rsp)
	movq	48(%r12), %rax
	cmpq	%rbx, %rax
	movq	%rax, 8(%rsp)
	je	.L72
	.p2align 4,,10
	.p2align 3
.L181:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, 8(%rsp)
	jne	.L181
.L72:
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L83
	call	_ZdlPv
.L83:
	movq	%r12, %rdi
	call	_ZdlPv
	cmpq	$0, 16(%rsp)
	je	.L57
	movq	16(%rsp), %r12
	jmp	.L188
.L57:
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
	je	.L85
.L180:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	jne	.L180
.L85:
	movq	16(%rsp), %rdx
	movq	(%rdx), %rdi
	testq	%rdi, %rdi
	je	.L96
	call	_ZdlPv
.L96:
	movq	48(%rsp), %rdi
	call	_ZdlPv
	cmpq	$0, 8(%rsp)
	je	.L56
	movq	8(%rsp), %rax
	movq	%rax, 48(%rsp)
	jmp	.L187
.L56:
	movq	40(%rsp), %rax
	movq	40(%rsp), %rdx
	movq	16(%rax), %rax
	movq	48(%rdx), %r12
	movq	40(%rdx), %rbx
	movq	%rax, 8(%rsp)
	movq	40(%rsp), %rax
	addq	$40, %rax
	cmpq	%rbx, %r12
	je	.L98
.L179:
	movq	%rbx, %rdi
	addq	$40, %rbx
	movq	%rax, (%rsp)
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	movq	(%rsp), %rax
	jne	.L179
.L98:
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L109
	call	_ZdlPv
.L109:
	movq	40(%rsp), %rdi
	call	_ZdlPv
	movq	8(%rsp), %rax
	movq	%rax, 40(%rsp)
	jmp	.L55
.L195:
	movq	32(%rsp), %rdx
	movq	%rdx, %rax
	movq	16(%rdx), %r12
	movq	48(%rdx), %rdx
	addq	$40, %rax
	movq	%rdx, 8(%rsp)
	movq	32(%rsp), %rdx
	movq	40(%rdx), %rbx
	jmp	.L111
.L114:
	movq	%rbx, %rdi
	movq	%rax, (%rsp)
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
.L111:
	cmpq	%rbx, 8(%rsp)
	jne	.L114
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L122
	call	_ZdlPv
.L122:
	movq	32(%rsp), %rdi
	call	_ZdlPv
	movq	%r12, 32(%rsp)
	jmp	.L54
.L194:
	movq	48(%r15), %rdx
	movq	16(%r15), %r12
	leaq	40(%r15), %rax
	movq	40(%r15), %rbx
	movq	%rdx, 8(%rsp)
.L124:
	cmpq	%rbx, 8(%rsp)
	je	.L196
	movq	%rbx, %rdi
	movq	%rax, (%rsp)
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	movq	(%rsp), %rax
	jmp	.L124
.L196:
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L135
	call	_ZdlPv
.L135:
	movq	%r15, %rdi
	movq	%r12, %r15
	call	_ZdlPv
	jmp	.L53
.L193:
	movq	48(%r14), %rax
	movq	16(%r14), %r12
	leaq	40(%r14), %r15
	movq	40(%r14), %rbx
	movq	%rax, 8(%rsp)
.L137:
	cmpq	%rbx, 8(%rsp)
	je	.L197
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L137
.L192:
	movq	16(%r13), %r12
	movq	48(%r13), %r15
	leaq	40(%r13), %r14
	movq	40(%r13), %rbx
.L150:
	cmpq	%rbx, %r15
	je	.L198
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L150
.L197:
	movq	(%r15), %rdi
	testq	%rdi, %rdi
	je	.L148
	.p2align 4,,5
	call	_ZdlPv
.L148:
	movq	%r14, %rdi
	movq	%r12, %r14
	call	_ZdlPv
	jmp	.L52
.L198:
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L161
	.p2align 4,,5
	call	_ZdlPv
.L161:
	movq	%r13, %rdi
	movq	%r12, %r13
	call	_ZdlPv
	jmp	.L51
.L191:
	movq	56(%rsp), %rdx
	movq	16(%rdx), %r12
	movq	48(%rdx), %r14
	movq	%rdx, %r13
	movq	40(%rdx), %rbx
	addq	$40, %r13
.L163:
	cmpq	%rbx, %r14
	je	.L199
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	jmp	.L163
.L190:
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
.L199:
	.cfi_restore_state
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L174
	call	_ZdlPv
.L174:
	movq	56(%rsp), %rdi
	call	_ZdlPv
	movq	%r12, 56(%rsp)
	jmp	.L50
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
	je	.L210
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	call	_ZdlPv
.L210:
	movq	160(%r12), %rdi
	testq	%rdi, %rdi
	je	.L215
	call	_ZdlPv
.L215:
	movq	136(%r12), %rdi
	testq	%rdi, %rdi
	je	.L220
	call	_ZdlPv
.L220:
	movq	112(%r12), %rdi
	testq	%rdi, %rdi
	je	.L225
	call	_ZdlPv
.L225:
	movq	88(%r12), %rdi
	testq	%rdi, %rdi
	je	.L230
	call	_ZdlPv
.L230:
	movq	72(%r12), %rbp
	movq	64(%r12), %rbx
	cmpq	%rbx, %rbp
	je	.L231
	.p2align 4,,10
	.p2align 3
.L251:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB31:
	call	*(%rax)
.LEHE31:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L251
.L231:
	movq	64(%r12), %rdi
	testq	%rdi, %rdi
	je	.L243
	call	_ZdlPv
.L243:
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
.L250:
	.cfi_restore_state
	movq	64(%r12), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L238
	call	_ZdlPv
.L238:
	leaq	16(%r12), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
.LEHB32:
	call	_Unwind_Resume
.LEHE32:
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
	.uleb128 .LEHB31-.LFB3570
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L250-.LFB3570
	.uleb128 0x0
	.uleb128 .LEHB32-.LFB3570
	.uleb128 .LEHE32-.LEHB32
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3570:
	.section	.text._ZN3fem11BaseElementIdED2Ev,"axG",@progbits,_ZN3fem11BaseElementIdED5Ev,comdat
	.weak	_ZN3fem11BaseElementIdED1Ev
	.set	_ZN3fem11BaseElementIdED1Ev,_ZN3fem11BaseElementIdED2Ev
	.section	.text._ZN3fem13Tetrahedron10IdED2Ev,"axG",@progbits,_ZN3fem13Tetrahedron10IdED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdED2Ev
	.type	_ZN3fem13Tetrahedron10IdED2Ev, @function
_ZN3fem13Tetrahedron10IdED2Ev:
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
	je	.L258
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	call	_ZdlPv
.L258:
	movq	160(%r12), %rdi
	testq	%rdi, %rdi
	je	.L263
	call	_ZdlPv
.L263:
	movq	136(%r12), %rdi
	testq	%rdi, %rdi
	je	.L268
	call	_ZdlPv
.L268:
	movq	112(%r12), %rdi
	testq	%rdi, %rdi
	je	.L273
	call	_ZdlPv
.L273:
	movq	88(%r12), %rdi
	testq	%rdi, %rdi
	je	.L278
	call	_ZdlPv
.L278:
	movq	72(%r12), %rbp
	movq	64(%r12), %rbx
	cmpq	%rbx, %rbp
	je	.L279
	.p2align 4,,10
	.p2align 3
.L301:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB33:
	call	*(%rax)
.LEHE33:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L301
.L279:
	movq	64(%r12), %rdi
	testq	%rdi, %rdi
	je	.L291
	call	_ZdlPv
.L291:
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
.L300:
	.cfi_restore_state
	movq	64(%r12), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L286
	call	_ZdlPv
.L286:
	leaq	16(%r12), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
.LEHB34:
	call	_Unwind_Resume
.LEHE34:
	.cfi_endproc
.LFE3538:
	.size	_ZN3fem13Tetrahedron10IdED2Ev, .-_ZN3fem13Tetrahedron10IdED2Ev
	.section	.gcc_except_table
.LLSDA3538:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3538-.LLSDACSB3538
.LLSDACSB3538:
	.uleb128 .LEHB33-.LFB3538
	.uleb128 .LEHE33-.LEHB33
	.uleb128 .L300-.LFB3538
	.uleb128 0x0
	.uleb128 .LEHB34-.LFB3538
	.uleb128 .LEHE34-.LEHB34
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3538:
	.section	.text._ZN3fem13Tetrahedron10IdED2Ev,"axG",@progbits,_ZN3fem13Tetrahedron10IdED5Ev,comdat
	.weak	_ZN3fem13Tetrahedron10IdED1Ev
	.set	_ZN3fem13Tetrahedron10IdED1Ev,_ZN3fem13Tetrahedron10IdED2Ev
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC7:
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
	je	.L303
	.cfi_offset 3, -56
	movq	8(%rdi), %rdx
	movq	16(%rdi), %rax
	subq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, 8(%rsp)
	jbe	.L401
	movq	(%rdi), %rcx
	movq	%rdx, %rax
	movabsq	$576460752303423487, %rsi
	movq	%rsi, %rdx
	subq	%rcx, %rax
	sarq	$5, %rax
	subq	%rax, %rdx
	cmpq	%rdx, 8(%rsp)
	ja	.L402
	cmpq	8(%rsp), %rax
	movq	8(%rsp), %rdx
	cmovae	%rax, %rdx
	addq	%rax, %rdx
	movq	%rdx, 32(%rsp)
	jb	.L337
	cmpq	%rsi, %rdx
	jbe	.L403
.L337:
	movq	%r13, %rax
	movq	$-32, %rdi
	subq	%rcx, %rax
	sarq	$5, %rax
	movq	%rax, 24(%rsp)
	movabsq	$576460752303423487, %rax
	movq	%rax, 32(%rsp)
.L374:
.LEHB35:
	call	_Znwm
.LEHE35:
	movq	%rax, 16(%rsp)
.L338:
	movq	24(%rsp), %rax
	movq	8(%rsp), %r12
	salq	$5, %rax
	addq	16(%rsp), %rax
	movq	%rax, 40(%rsp)
	movq	%rax, %rbx
	jmp	.L341
	.p2align 4,,10
	.p2align 3
.L404:
	addq	$32, %rbx
.L341:
	testq	%rbx, %rbx
	je	.L339
	movq	%r14, %rsi
	movq	%rbx, %rdi
.LEHB36:
	call	_ZN3fem5pointC1ERKS0_
.LEHE36:
.L339:
	subq	$1, %r12
	jne	.L404
	movq	(%r15), %r12
	cmpq	%r13, %r12
	je	.L376
	movq	16(%rsp), %rbx
	.p2align 4,,10
	.p2align 3
.L349:
	testq	%rbx, %rbx
	je	.L348
	movq	%r12, %rsi
	movq	%rbx, %rdi
.LEHB37:
	call	_ZN3fem5pointC1ERKS0_
.LEHE37:
.L348:
	addq	$32, %r12
	addq	$32, %rbx
	cmpq	%r12, %r13
	jne	.L349
.L347:
	movq	8(%rsp), %r14
	movq	8(%r15), %r12
	salq	$5, %r14
	cmpq	%r13, %r12
	leaq	(%rbx,%r14), %r14
	movq	%r14, %rbx
	je	.L351
	.p2align 4,,10
	.p2align 3
.L394:
	testq	%rbx, %rbx
	je	.L357
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB38:
	call	_ZN3fem5pointC1ERKS0_
.LEHE38:
.L357:
	addq	$32, %rbp
	addq	$32, %rbx
	cmpq	%rbp, %r12
	jne	.L394
	movq	8(%r15), %r12
.L351:
	movq	(%r15), %rbp
	cmpq	%r12, %rbp
	je	.L360
	.p2align 4,,10
	.p2align 3
.L393:
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
	addq	$32, %rbp
.LEHB39:
	call	*(%rax)
	cmpq	%r12, %rbp
	jne	.L393
	movq	(%r15), %rbp
.L360:
	testq	%rbp, %rbp
	je	.L366
	movq	%rbp, %rdi
	call	_ZdlPv
.L366:
	movq	16(%rsp), %rax
	movq	%rbx, 8(%r15)
	movq	%rax, (%r15)
	movq	32(%rsp), %rax
	salq	$5, %rax
	addq	16(%rsp), %rax
	movq	%rax, 16(%r15)
.L303:
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
.L401:
	.cfi_restore_state
	leaq	144(%rsp), %rdi
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKS0_
.LEHE39:
	movq	8(%r15), %r14
	movq	%r14, %rax
	subq	%r13, %rax
	sarq	$5, %rax
	cmpq	%rax, 8(%rsp)
	movq	%rax, 16(%rsp)
	jae	.L306
	movq	8(%rsp), %rdx
	movq	%r14, %rax
	salq	$5, %rdx
	subq	%rdx, %rax
	movq	%rdx, 16(%rsp)
	cmpq	%rax, %r14
	movq	%rax, 8(%rsp)
	je	.L307
	movq	%rax, %r12
	movq	%r14, %rbx
	jmp	.L309
	.p2align 4,,10
	.p2align 3
.L405:
	addq	$32, %rbx
.L309:
	testq	%rbx, %rbx
	je	.L308
	movq	%r12, %rsi
	movq	%rbx, %rdi
.LEHB40:
	call	_ZN3fem5pointC1ERKS0_
.LEHE40:
.L308:
	addq	$32, %r12
	cmpq	%r12, %r14
	jne	.L405
.L307:
	movq	8(%rsp), %rbx
	movq	16(%rsp), %rdx
	addq	%rdx, 8(%r15)
	subq	%r13, %rbx
	sarq	$5, %rbx
	testq	%rbx, %rbx
	jle	.L311
	.p2align 4,,10
	.p2align 3
.L392:
	subq	$32, 8(%rsp)
	subq	$32, %r14
	leaq	112(%rsp), %rdi
	movq	8(%rsp), %rdx
	movq	%r14, %rsi
.LEHB41:
	call	_ZN3fem5pointaSERKS0_
	leaq	112(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	subq	$1, %rbx
	testq	%rbx, %rbx
	jg	.L392
.L311:
	movq	16(%rsp), %rbx
	leaq	0(%r13,%rbx), %rbx
	cmpq	%r13, %rbx
	je	.L318
	.p2align 4,,10
	.p2align 3
.L319:
	leaq	144(%rsp), %rdx
	leaq	80(%rsp), %rdi
	movq	%rbp, %rsi
	call	_ZN3fem5pointaSERKS0_
	leaq	80(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE41:
	addq	$32, %rbp
	cmpq	%rbp, %rbx
	jne	.L319
.L318:
	leaq	144(%rsp), %rdi
.LEHB42:
	call	_ZN3fem5pointD1Ev
.LEHE42:
	jmp	.L303
	.p2align 4,,10
	.p2align 3
.L403:
	movq	%r13, %rdx
	subq	%rcx, %rdx
	sarq	$5, %rdx
	cmpq	$0, 32(%rsp)
	movq	%rdx, 24(%rsp)
	jne	.L406
	movq	$0, 16(%rsp)
	jmp	.L338
.L306:
	movq	8(%rsp), %rax
	subq	16(%rsp), %rax
	movq	%rax, 8(%rsp)
	je	.L320
	movq	%rax, %r12
	movq	%r14, %rbx
	jmp	.L322
	.p2align 4,,10
	.p2align 3
.L407:
	addq	$32, %rbx
.L322:
	testq	%rbx, %rbx
	je	.L321
	leaq	144(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB43:
	call	_ZN3fem5pointC1ERKS0_
.LEHE43:
.L321:
	subq	$1, %r12
	jne	.L407
.L320:
	movq	8(%rsp), %r12
	salq	$5, %r12
	addq	8(%r15), %r12
	cmpq	%r13, %r14
	movq	%r12, 8(%r15)
	je	.L327
	movq	%r12, %rbx
	jmp	.L330
	.p2align 4,,10
	.p2align 3
.L408:
	addq	$32, %rbx
.L330:
	testq	%rbx, %rbx
	je	.L328
	movq	%r13, %rsi
	movq	%rbx, %rdi
.LEHB44:
	call	_ZN3fem5pointC1ERKS0_
.LEHE44:
.L328:
	addq	$32, %r13
	cmpq	%r13, %r14
	jne	.L408
	movq	16(%rsp), %rax
	salq	$5, %rax
	addq	%rax, 8(%r15)
	.p2align 4,,10
	.p2align 3
.L331:
	leaq	144(%rsp), %rdx
	leaq	48(%rsp), %rdi
	movq	%rbp, %rsi
.LEHB45:
	call	_ZN3fem5pointaSERKS0_
	leaq	48(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE45:
	addq	$32, %rbp
	cmpq	%rbp, %r14
	jne	.L331
	jmp	.L318
.L376:
	movq	16(%rsp), %rbx
	jmp	.L347
.L327:
	movq	16(%rsp), %rax
	salq	$5, %rax
	leaq	(%r12,%rax), %rax
	movq	%rax, 8(%r15)
	jmp	.L318
.L384:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L334:
	cmpq	%rbx, %r12
	je	.L409
	movq	(%r12), %rax
	movq	%r12, %rdi
.LEHB46:
	call	*(%rax)
.LEHE46:
	addq	$32, %r12
	jmp	.L334
.L382:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L325:
	cmpq	%r14, %rbx
	je	.L410
	movq	(%r14), %rax
	movq	%r14, %rdi
.LEHB47:
	call	*(%rax)
.LEHE47:
	addq	$32, %r14
	jmp	.L325
.L377:
	movq	%rax, %rbx
.L313:
	leaq	144(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	movq	%rbx, %rdi
.LEHB48:
	call	_Unwind_Resume
.LEHE48:
.L381:
	movq	%rax, %rbx
	call	__cxa_end_catch
	jmp	.L313
.L410:
	.p2align 4,,5
.LEHB49:
	call	__cxa_rethrow
.LEHE49:
.L388:
	movq	%rax, %rdi
	.p2align 4,,5
	call	__cxa_begin_catch
	movq	16(%rsp), %rbp
.L355:
	cmpq	%rbp, %rbx
	je	.L411
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB50:
	call	*(%rax)
.LEHE50:
	addq	$32, %rbp
	jmp	.L355
.L390:
	movq	%rax, %rdi
	movq	%r14, %rbp
	call	__cxa_begin_catch
.L363:
	cmpq	%rbp, %rbx
	je	.L412
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB51:
	call	*(%rax)
.LEHE51:
	addq	$32, %rbp
	jmp	.L363
.L387:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
.L353:
	movq	24(%rsp), %rbx
	addq	8(%rsp), %rbx
	salq	$5, %rbx
	addq	16(%rsp), %rbx
.L369:
	cmpq	40(%rsp), %rbx
	je	.L371
	movq	40(%rsp), %rdx
	movq	(%rdx), %rax
	movq	%rdx, %rdi
.LEHB52:
	call	*(%rax)
.LEHE52:
	addq	$32, 40(%rsp)
	jmp	.L369
.L411:
.LEHB53:
	call	__cxa_rethrow
.LEHE53:
.L378:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB54:
	call	_Unwind_Resume
.LEHE54:
.L371:
	cmpq	$0, 16(%rsp)
	je	.L373
	movq	16(%rsp), %rdi
	call	_ZdlPv
.L373:
.LEHB55:
	call	__cxa_rethrow
.LEHE55:
.L406:
	movq	32(%rsp), %rdi
	salq	$5, %rdi
	jmp	.L374
.L380:
	movq	%rax, %rdi
	call	__cxa_begin_catch
.L315:
	cmpq	%rbx, %r14
	je	.L413
	movq	(%r14), %rax
	movq	%r14, %rdi
.LEHB56:
	call	*(%rax)
.LEHE56:
	addq	$32, %r14
	jmp	.L315
.L383:
	movq	%rax, %rbx
	call	__cxa_end_catch
	jmp	.L313
.L409:
	.p2align 4,,5
.LEHB57:
	call	__cxa_rethrow
.LEHE57:
.L379:
	movq	%rax, %rbx
	.p2align 4,,5
	call	__cxa_end_catch
	.p2align 4,,2
	jmp	.L313
.L413:
	.p2align 4,,5
.LEHB58:
	call	__cxa_rethrow
.LEHE58:
.L386:
	movq	%rax, %rdi
	.p2align 4,,5
	call	__cxa_begin_catch
	movq	40(%rsp), %rbp
.L345:
	cmpq	%rbp, %rbx
	je	.L414
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB59:
	call	*(%rax)
.LEHE59:
	addq	$32, %rbp
	jmp	.L345
.L402:
	movl	$.LC7, %edi
.LEHB60:
	call	_ZSt20__throw_length_errorPKc
.LEHE60:
.L385:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	16(%rsp), %r14
	movq	%rbx, %rdi
.L343:
	call	__cxa_begin_catch
	testq	%r14, %r14
	je	.L353
	movq	16(%rsp), %rbx
.L368:
	cmpq	%rbx, %r14
	je	.L371
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB61:
	call	*(%rax)
.LEHE61:
	addq	$32, %rbx
	jmp	.L368
.L414:
.LEHB62:
	call	__cxa_rethrow
.LEHE62:
.L389:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	jmp	.L343
.L412:
.LEHB63:
	call	__cxa_rethrow
.LEHE63:
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
	.uleb128 .LEHB35-.LFB3689
	.uleb128 .LEHE35-.LEHB35
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB36-.LFB3689
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L386-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB37-.LFB3689
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L388-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB38-.LFB3689
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L390-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB39-.LFB3689
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB40-.LFB3689
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L380-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB41-.LFB3689
	.uleb128 .LEHE41-.LEHB41
	.uleb128 .L377-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB42-.LFB3689
	.uleb128 .LEHE42-.LEHB42
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB43-.LFB3689
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L382-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB44-.LFB3689
	.uleb128 .LEHE44-.LEHB44
	.uleb128 .L384-.LFB3689
	.uleb128 0x1
	.uleb128 .LEHB45-.LFB3689
	.uleb128 .LEHE45-.LEHB45
	.uleb128 .L377-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB46-.LFB3689
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L383-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB47-.LFB3689
	.uleb128 .LEHE47-.LEHB47
	.uleb128 .L381-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB48-.LFB3689
	.uleb128 .LEHE48-.LEHB48
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB49-.LFB3689
	.uleb128 .LEHE49-.LEHB49
	.uleb128 .L381-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB50-.LFB3689
	.uleb128 .LEHE50-.LEHB50
	.uleb128 .L387-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB51-.LFB3689
	.uleb128 .LEHE51-.LEHB51
	.uleb128 .L389-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB52-.LFB3689
	.uleb128 .LEHE52-.LEHB52
	.uleb128 .L378-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB53-.LFB3689
	.uleb128 .LEHE53-.LEHB53
	.uleb128 .L387-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB54-.LFB3689
	.uleb128 .LEHE54-.LEHB54
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB55-.LFB3689
	.uleb128 .LEHE55-.LEHB55
	.uleb128 .L378-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB56-.LFB3689
	.uleb128 .LEHE56-.LEHB56
	.uleb128 .L379-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB57-.LFB3689
	.uleb128 .LEHE57-.LEHB57
	.uleb128 .L383-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB58-.LFB3689
	.uleb128 .LEHE58-.LEHB58
	.uleb128 .L379-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB59-.LFB3689
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L385-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB60-.LFB3689
	.uleb128 .LEHE60-.LEHB60
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB61-.LFB3689
	.uleb128 .LEHE61-.LEHB61
	.uleb128 .L378-.LFB3689
	.uleb128 0x0
	.uleb128 .LEHB62-.LFB3689
	.uleb128 .LEHE62-.LEHB62
	.uleb128 .L385-.LFB3689
	.uleb128 0x3
	.uleb128 .LEHB63-.LFB3689
	.uleb128 .LEHE63-.LEHB63
	.uleb128 .L389-.LFB3689
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
	je	.L415
	movq	8(%rdi), %r13
	movq	16(%rdi), %rax
	subq	%r13, %rax
	sarq	$3, %rax
	cmpq	%rax, %rdx
	ja	.L417
	movq	%r13, %r9
	movsd	(%rcx), %xmm0
	subq	%rsi, %r9
	sarq	$3, %r9
	cmpq	%r9, %rdx
	jb	.L472
	subq	%r9, %rbx
	je	.L425
	movq	%r13, %rax
	andl	$15, %eax
	shrq	$3, %rax
	cmpq	%rbx, %rax
	cmova	%rbx, %rax
	testq	%rax, %rax
	je	.L453
	cmpq	%rax, %rbx
	movsd	%xmm0, 0(%r13)
	leaq	-1(%rbx), %rdx
	leaq	8(%r13), %rcx
	je	.L425
.L426:
	movq	%rbx, %r11
	subq	%rax, %r11
	movq	%r11, %rdi
	shrq	%rdi
	movq	%rdi, %r10
	addq	%r10, %r10
	je	.L461
	movapd	%xmm0, %xmm2
	leaq	0(%r13,%rax,8), %r8
	xorl	%eax, %eax
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L429:
	movq	%rax, %rsi
	addq	$1, %rax
	salq	$4, %rsi
	cmpq	%rax, %rdi
	movapd	%xmm1, (%r8,%rsi)
	ja	.L429
	subq	%r10, %rdx
	cmpq	%r10, %r11
	leaq	(%rcx,%r10,8), %rcx
	je	.L425
	.p2align 4,,10
	.p2align 3
.L461:
	movsd	%xmm0, (%rcx)
	addq	$8, %rcx
	subq	$1, %rdx
	jne	.L461
.L425:
	leaq	0(%r13,%rbx,8), %rdi
	xorl	%ebx, %ebx
	testq	%r9, %r9
	movq	%rdi, 8(%rbp)
	jne	.L473
.L433:
	addq	%rbx, %rdi
	cmpq	%r12, %r13
	movq	%rdi, 8(%rbp)
	je	.L415
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
	je	.L454
	cmpq	%rdx, %rcx
	movsd	%xmm0, (%r12)
	je	.L415
.L434:
	movq	%rcx, %r9
	subq	%rdx, %r9
	movq	%r9, %rsi
	shrq	%rsi
	movq	%rsi, %r8
	addq	%r8, %r8
	je	.L460
	movapd	%xmm0, %xmm2
	leaq	(%r12,%rdx,8), %rdi
	xorl	%edx, %edx
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L436:
	movq	%rdx, %rcx
	addq	$1, %rdx
	salq	$4, %rcx
	cmpq	%rdx, %rsi
	movapd	%xmm1, (%rdi,%rcx)
	ja	.L436
	cmpq	%r8, %r9
	leaq	(%rax,%r8,8), %rax
	je	.L415
	.p2align 4,,10
	.p2align 3
.L460:
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %r13
	jne	.L460
.L415:
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
.L417:
	.cfi_restore_state
	movq	(%rdi), %rsi
	movabsq	$2305843009213693951, %rax
	movq	%rax, %rdx
	subq	%rsi, %r13
	sarq	$3, %r13
	subq	%r13, %rdx
	cmpq	%rdx, %rbx
	ja	.L474
	cmpq	%rbx, %r13
	movq	%rbx, %r15
	cmovae	%r13, %r15
	addq	%r15, %r13
	jb	.L439
	cmpq	%rax, %r13
	ja	.L439
	movq	%r12, %r14
	subq	%rsi, %r14
	sarq	$3, %r14
	testq	%r13, %r13
	jne	.L475
	xorl	%r15d, %r15d
	xorl	%r13d, %r13d
.L440:
	leaq	0(%r13,%r14,8), %rax
	movsd	(%rcx), %xmm0
	movq	%rax, %rdi
	andl	$15, %edi
	shrq	$3, %rdi
	cmpq	%rbx, %rdi
	cmova	%rbx, %rdi
	testq	%rdi, %rdi
	je	.L456
	cmpq	%rdi, %rbx
	movsd	%xmm0, (%rax)
	leaq	-1(%rbx), %rdx
	leaq	8(%rax), %rcx
	je	.L442
.L441:
	movq	%rbx, %r11
	subq	%rdi, %r11
	movq	%r11, %r8
	shrq	%r8
	movq	%r8, %r10
	addq	%r10, %r10
	je	.L462
	movapd	%xmm0, %xmm2
	leaq	(%rax,%rdi,8), %r9
	xorl	%eax, %eax
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L444:
	movq	%rax, %rdi
	addq	$1, %rax
	salq	$4, %rdi
	cmpq	%rax, %r8
	movapd	%xmm1, (%r9,%rdi)
	ja	.L444
	subq	%r10, %rdx
	cmpq	%r10, %r11
	leaq	(%rcx,%r10,8), %rcx
	je	.L442
	.p2align 4,,10
	.p2align 3
.L462:
	movsd	%xmm0, (%rcx)
	addq	$8, %rcx
	subq	$1, %rdx
	jne	.L462
.L442:
	movq	%r12, %rax
	xorl	%r14d, %r14d
	subq	%rsi, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L476
.L447:
	movq	8(%rbp), %rax
	leaq	0(%r13,%r14), %r14
	leaq	(%r14,%rbx,8), %r14
	xorl	%ebx, %ebx
	subq	%r12, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L477
.L448:
	movq	0(%rbp), %rdi
	leaq	(%r14,%rbx), %rbx
	testq	%rdi, %rdi
	je	.L449
	call	_ZdlPv
.L449:
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
.L439:
	.cfi_restore_state
	movq	%r12, %r14
	movq	$-8, %r15
	subq	%rsi, %r14
	sarq	$3, %r14
.L450:
	movq	%r15, %rdi
	movq	%rcx, (%rsp)
	call	_Znwm
	movq	0(%rbp), %rsi
	movq	%rax, %r13
	movq	(%rsp), %rcx
	jmp	.L440
	.p2align 4,,10
	.p2align 3
.L477:
	leaq	0(,%rax,8), %rbx
	movq	%r12, %rsi
	movq	%r14, %rdi
	movq	%rbx, %rdx
	call	memmove
	jmp	.L448
	.p2align 4,,10
	.p2align 3
.L476:
	leaq	0(,%rax,8), %r14
	movq	%r13, %rdi
	movq	%r14, %rdx
	call	memmove
	jmp	.L447
	.p2align 4,,10
	.p2align 3
.L473:
	leaq	0(,%r9,8), %rbx
	movq	%r12, %rsi
	movsd	%xmm0, (%rsp)
	movq	%rbx, %rdx
	call	memmove
	movq	8(%rbp), %rdi
	movsd	(%rsp), %xmm0
	jmp	.L433
	.p2align 4,,10
	.p2align 3
.L472:
	salq	$3, %rbx
	movq	%r13, %r14
	movq	%r13, %rax
	movq	%rbx, %rdx
	subq	%rbx, %r14
	sarq	$3, %rdx
	testq	%rdx, %rdx
	je	.L419
	salq	$3, %rdx
	movq	%r14, %rsi
	movq	%r13, %rdi
	movsd	%xmm0, (%rsp)
	call	memmove
	movq	8(%rbp), %rax
	movsd	(%rsp), %xmm0
.L419:
	subq	%r12, %r14
	addq	%rbx, %rax
	sarq	$3, %r14
	movq	%rax, 8(%rbp)
	testq	%r14, %r14
	je	.L420
	leaq	0(,%r14,8), %rdx
	movq	%r13, %rdi
	movq	%r12, %rsi
	movsd	%xmm0, (%rsp)
	subq	%rdx, %rdi
	call	memmove
	movsd	(%rsp), %xmm0
.L420:
	leaq	(%r12,%rbx), %rbx
	cmpq	%r12, %rbx
	je	.L415
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
	je	.L452
	cmpq	%rcx, %rdx
	movsd	%xmm0, (%r12)
	je	.L415
.L421:
	movq	%rcx, %r9
	subq	%rdx, %r9
	movq	%r9, %rsi
	shrq	%rsi
	movq	%rsi, %r8
	addq	%r8, %r8
	je	.L459
	movapd	%xmm0, %xmm2
	leaq	(%r12,%rdx,8), %rdi
	xorl	%edx, %edx
	unpcklpd	%xmm2, %xmm2
	movapd	%xmm2, %xmm1
	.p2align 4,,10
	.p2align 3
.L423:
	movq	%rdx, %rcx
	addq	$1, %rdx
	salq	$4, %rcx
	cmpq	%rdx, %rsi
	movapd	%xmm1, (%rdi,%rcx)
	ja	.L423
	cmpq	%r8, %r9
	leaq	(%rax,%r8,8), %rax
	je	.L415
	.p2align 4,,10
	.p2align 3
.L459:
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %rbx
	je	.L415
	movsd	%xmm0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %rbx
	jne	.L459
	jmp	.L415
.L475:
	leaq	0(,%r13,8), %r15
	jmp	.L450
.L474:
	movl	$.LC7, %edi
	call	_ZSt20__throw_length_errorPKc
.L456:
	movq	%rbx, %rdx
	movq	%rax, %rcx
	jmp	.L441
.L452:
	movq	%r12, %rax
	jmp	.L421
.L453:
	movq	%rbx, %rdx
	movq	%r13, %rcx
	jmp	.L426
.L454:
	movq	%r12, %rax
	jmp	.L434
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
	je	.L478
	.p2align 4,,10
	.p2align 3
.L483:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L483
.L478:
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
	je	.L486
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
	ja	.L530
	movq	8(%r13), %r15
	movq	%r15, %rdx
	subq	%rax, %rdx
	sarq	$3, %rdx
	movq	%rdx, %rsi
	imulq	%rdi, %rsi
	cmpq	%rsi, %r14
	ja	.L503
	testq	%r14, %r14
	jle	.L504
	movq	%rax, %rbp
	.p2align 4,,10
	.p2align 3
.L505:
	leaq	64(%rsp), %rdi
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movq	%rax, 8(%rsp)
	movq	%rcx, 16(%rsp)
.LEHB64:
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
	jg	.L505
	leaq	(%r14,%r14,4), %rdx
	leaq	(%rax,%rdx,8), %rax
.L504:
	cmpq	%rax, %r15
	je	.L506
	.p2align 4,,10
	.p2align 3
.L525:
	movq	%rax, %rdi
	movq	%rax, 8(%rsp)
	call	_ZN3fem5pointD1Ev
	movq	8(%rsp), %rax
	addq	$40, %rax
	cmpq	%rax, %r15
	jne	.L525
.L506:
	movq	0(%r13), %rdx
	leaq	(%r14,%r14,4), %rax
	leaq	(%rdx,%rax,8), %rax
.L501:
	movq	%rax, 8(%r13)
.L486:
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
.L503:
	.cfi_restore_state
	movq	%rdx, %rcx
	leaq	(%rbx,%rdx,8), %rbp
	imulq	%rdi, %rcx
	testq	%rcx, %rcx
	jle	.L510
	.p2align 4,,10
	.p2align 3
.L511:
	leaq	32(%rsp), %rdi
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movq	%rax, 8(%rsp)
	movq	%rcx, 16(%rsp)
	call	_ZN3fem5pointaSERKS0_
	leaq	32(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE64:
	movq	16(%rsp), %rcx
	movq	32(%rbx), %rdx
	addq	$40, %rbx
	movq	8(%rsp), %rax
	subq	$1, %rcx
	movq	%rdx, 32(%rax)
	addq	$40, %rax
	testq	%rcx, %rcx
	jg	.L511
	movq	24(%rsp), %rax
	movq	8(%r13), %r15
	movq	24(%rsp), %rdx
	movq	8(%rax), %r12
	movq	0(%r13), %rax
	movq	%r15, %rbp
	subq	%rax, %rbp
	andq	$-8, %rbp
	addq	(%rdx), %rbp
.L510:
	leaq	(%r14,%r14,4), %rdx
	cmpq	%r12, %rbp
	movq	%r15, %rbx
	leaq	(%rax,%rdx,8), %rax
	jne	.L513
	jmp	.L501
	.p2align 4,,10
	.p2align 3
.L515:
	addq	$40, %rbx
.L513:
	testq	%rbx, %rbx
	je	.L514
	movq	%rbp, %rsi
	movq	%rbx, %rdi
.LEHB65:
	call	_ZN3fem5pointC1ERKS0_
.LEHE65:
	movq	32(%rbp), %rax
	movq	%rax, 32(%rbx)
.L514:
	addq	$40, %rbp
	cmpq	%r12, %rbp
	jne	.L515
	jmp	.L506
	.p2align 4,,10
	.p2align 3
.L530:
	testq	%r14, %r14
	je	.L518
	movabsq	$461168601842738790, %rax
	cmpq	%rax, %r14
	ja	.L531
	leaq	0(,%rsi,8), %rdi
.LEHB66:
	call	_Znwm
.LEHE66:
	movq	%rax, %r15
.L488:
	cmpq	%r12, %rbx
	je	.L490
	movq	%r15, %rbp
	jmp	.L492
	.p2align 4,,10
	.p2align 3
.L532:
	addq	$40, %rbp
.L492:
	testq	%rbp, %rbp
	je	.L491
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB67:
	call	_ZN3fem5pointC1ERKS0_
.LEHE67:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L491:
	addq	$40, %rbx
	cmpq	%rbx, %r12
	jne	.L532
.L490:
	movq	8(%r13), %rbp
	movq	0(%r13), %rbx
	cmpq	%rbx, %rbp
	je	.L494
	.p2align 4,,10
	.p2align 3
.L524:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB68:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %rbp
	jne	.L524
	movq	0(%r13), %rbx
.L494:
	testq	%rbx, %rbx
	je	.L500
	movq	%rbx, %rdi
	call	_ZdlPv
.L500:
	leaq	(%r14,%r14,4), %rax
	movq	%r15, 0(%r13)
	leaq	(%r15,%rax,8), %rax
	movq	%rax, 16(%r13)
	jmp	.L501
	.p2align 4,,10
	.p2align 3
.L518:
	xorl	%r15d, %r15d
	jmp	.L488
.L531:
	call	_ZSt17__throw_bad_allocv
.LEHE68:
.L523:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbx, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB69:
	call	__cxa_rethrow
.LEHE69:
.L521:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB70:
	call	__cxa_rethrow
.LEHE70:
.L522:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB71:
	call	_Unwind_Resume
.LEHE71:
.L520:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
	movq	%r15, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
.LEHB72:
	call	__cxa_rethrow
.LEHE72:
.L519:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB73:
	call	_Unwind_Resume
.LEHE73:
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
	.uleb128 .LEHB64-.LFB3656
	.uleb128 .LEHE64-.LEHB64
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB65-.LFB3656
	.uleb128 .LEHE65-.LEHB65
	.uleb128 .L523-.LFB3656
	.uleb128 0x1
	.uleb128 .LEHB66-.LFB3656
	.uleb128 .LEHE66-.LEHB66
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB67-.LFB3656
	.uleb128 .LEHE67-.LEHB67
	.uleb128 .L521-.LFB3656
	.uleb128 0x1
	.uleb128 .LEHB68-.LFB3656
	.uleb128 .LEHE68-.LEHB68
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB69-.LFB3656
	.uleb128 .LEHE69-.LEHB69
	.uleb128 .L522-.LFB3656
	.uleb128 0x0
	.uleb128 .LEHB70-.LFB3656
	.uleb128 .LEHE70-.LEHB70
	.uleb128 .L520-.LFB3656
	.uleb128 0x3
	.uleb128 .LEHB71-.LFB3656
	.uleb128 .LEHE71-.LEHB71
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB72-.LFB3656
	.uleb128 .LEHE72-.LEHB72
	.uleb128 .L519-.LFB3656
	.uleb128 0x0
	.uleb128 .LEHB73-.LFB3656
	.uleb128 .LEHE73-.LEHB73
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
	je	.L534
	testq	%r12, %r12
	je	.L535
	leaq	-40(%r12), %rsi
	movq	%r12, %rdi
.LEHB74:
	call	_ZN3fem5pointC1ERKS0_
	movq	-8(%r12), %rax
	movq	%rax, 32(%r12)
	movq	8(%r14), %r12
.L535:
	addq	$40, %r12
	leaq	32(%rsp), %rdi
	movq	%rbp, %rsi
	movq	%r12, 8(%r14)
	call	_ZN3fem5pointC1ERKS0_
.LEHE74:
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
	jle	.L536
	.p2align 4,,10
	.p2align 3
.L537:
	subq	$40, %rbx
	leaq	112(%rsp), %rdi
	leaq	40(%rbx), %rsi
	movq	%rbx, %rdx
.LEHB75:
	call	_ZN3fem5pointaSERKS0_
	leaq	112(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	movq	32(%rbx), %rax
	subq	$1, %rbp
	testq	%rbp, %rbp
	movq	%rax, 72(%rbx)
	jg	.L537
.L536:
	leaq	32(%rsp), %rdx
	leaq	80(%rsp), %rdi
	movq	%r13, %rsi
	call	_ZN3fem5pointaSERKS0_
	leaq	80(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE75:
	movq	64(%rsp), %rax
	leaq	32(%rsp), %rdi
	movq	%rax, 32(%r13)
.LEHB76:
	call	_ZN3fem5pointD1Ev
.L533:
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
.L534:
	.cfi_restore_state
	movq	(%rdi), %rax
	movabsq	$-3689348814741910323, %rdx
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
	testq	%r12, %r12
	je	.L539
	leaq	(%r12,%r12), %rcx
	cmpq	%rcx, %r12
	movq	%rcx, 8(%rsp)
	jbe	.L585
.L540:
	movq	%r13, %r12
	movabsq	$461168601842738790, %rcx
	movq	$-16, %rdi
	subq	%rax, %r12
	movabsq	$-3689348814741910323, %rax
	movq	%rcx, 8(%rsp)
	sarq	$3, %r12
	imulq	%rax, %r12
.L568:
	call	_Znwm
.LEHE76:
	movq	%rax, %r15
.L541:
	leaq	(%r12,%r12,4), %rax
	leaq	(%r15,%rax,8), %rax
	testq	%rax, %rax
	movq	%rax, 16(%rsp)
	je	.L542
	movq	%rbp, %rsi
	movq	%rax, %rdi
.LEHB77:
	call	_ZN3fem5pointC1ERKS0_
.LEHE77:
	movq	32(%rbp), %rax
	movq	16(%rsp), %rdx
	movq	%rax, 32(%rdx)
.L542:
	movq	(%r14), %rbp
	cmpq	%r13, %rbp
	je	.L571
	movq	%r15, %r12
	.p2align 4,,10
	.p2align 3
.L545:
	testq	%r12, %r12
	je	.L544
	movq	%rbp, %rsi
	movq	%r12, %rdi
.LEHB78:
	call	_ZN3fem5pointC1ERKS0_
.LEHE78:
	movq	32(%rbp), %rax
	movq	%rax, 32(%r12)
.L544:
	addq	$40, %rbp
	addq	$40, %r12
	cmpq	%rbp, %r13
	jne	.L545
.L543:
	addq	$40, %r12
	movq	%r12, 24(%rsp)
	movq	8(%r14), %r12
	movq	24(%rsp), %rbp
	cmpq	%r13, %r12
	je	.L547
	.p2align 4,,10
	.p2align 3
.L580:
	testq	%rbp, %rbp
	je	.L551
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB79:
	call	_ZN3fem5pointC1ERKS0_
.LEHE79:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L551:
	addq	$40, %rbx
	addq	$40, %rbp
	cmpq	%rbx, %r12
	jne	.L580
	movq	8(%r14), %r12
.L547:
	movq	(%r14), %rbx
	cmpq	%r12, %rbx
	je	.L554
	.p2align 4,,10
	.p2align 3
.L579:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB80:
	call	_ZN3fem5pointD1Ev
.LEHE80:
	cmpq	%rbx, %r12
	jne	.L579
	movq	(%r14), %rbx
.L554:
	testq	%rbx, %rbx
	je	.L561
	movq	%rbx, %rdi
	call	_ZdlPv
.L561:
	movq	8(%rsp), %rcx
	movq	%r15, (%r14)
	movq	%rbp, 8(%r14)
	leaq	(%rcx,%rcx,4), %rax
	leaq	(%r15,%rax,8), %rax
	movq	%rax, 16(%r14)
	jmp	.L533
	.p2align 4,,10
	.p2align 3
.L539:
	movq	%rsi, %r12
	movq	$1, 8(%rsp)
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
.L569:
	imulq	$40, 8(%rsp), %rdi
	jmp	.L568
	.p2align 4,,10
	.p2align 3
.L571:
	movq	%r15, %r12
	jmp	.L543
.L573:
	movq	%r15, 24(%rsp)
.L556:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	cmpq	$0, 24(%rsp)
	je	.L549
	movq	24(%rsp), %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.L567:
	movq	%r15, %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
.LEHB81:
	call	__cxa_rethrow
.LEHE81:
.L585:
	movabsq	$461168601842738790, %rcx
	cmpq	%rcx, 8(%rsp)
	ja	.L540
	movq	%rsi, %r12
	xorl	%r15d, %r15d
	subq	%rax, %r12
	sarq	$3, %r12
	imulq	%rdx, %r12
	cmpq	$0, 8(%rsp)
	je	.L541
	jmp	.L569
.L572:
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	movq	%rbx, %rdi
.LEHB82:
	call	_Unwind_Resume
.LEHE82:
.L578:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	24(%rsp), %rdi
	movq	%rbp, %rsi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB83:
	call	__cxa_rethrow
.LEHE83:
.L576:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r12, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB84:
	call	__cxa_rethrow
.LEHE84:
.L577:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	jmp	.L556
.L575:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
.L549:
	movq	16(%rsp), %rdi
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L567
.L574:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB85:
	call	_Unwind_Resume
.LEHE85:
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
	.uleb128 .LEHB74-.LFB3728
	.uleb128 .LEHE74-.LEHB74
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB75-.LFB3728
	.uleb128 .LEHE75-.LEHB75
	.uleb128 .L572-.LFB3728
	.uleb128 0x0
	.uleb128 .LEHB76-.LFB3728
	.uleb128 .LEHE76-.LEHB76
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB77-.LFB3728
	.uleb128 .LEHE77-.LEHB77
	.uleb128 .L573-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB78-.LFB3728
	.uleb128 .LEHE78-.LEHB78
	.uleb128 .L576-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB79-.LFB3728
	.uleb128 .LEHE79-.LEHB79
	.uleb128 .L578-.LFB3728
	.uleb128 0x1
	.uleb128 .LEHB80-.LFB3728
	.uleb128 .LEHE80-.LEHB80
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB81-.LFB3728
	.uleb128 .LEHE81-.LEHB81
	.uleb128 .L574-.LFB3728
	.uleb128 0x0
	.uleb128 .LEHB82-.LFB3728
	.uleb128 .LEHE82-.LEHB82
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB83-.LFB3728
	.uleb128 .LEHE83-.LEHB83
	.uleb128 .L577-.LFB3728
	.uleb128 0x3
	.uleb128 .LEHB84-.LFB3728
	.uleb128 .LEHE84-.LEHB84
	.uleb128 .L575-.LFB3728
	.uleb128 0x3
	.uleb128 .LEHB85-.LFB3728
	.uleb128 .LEHE85-.LEHB85
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
	je	.L612
.L587:
	movl	$64, %edi
.LEHB86:
	call	_Znwm
.LEHE86:
	cmpq	$-32, %rax
	movq	%rax, %r13
	je	.L601
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
	je	.L605
	movabsq	$461168601842738790, %rdx
	cmpq	%rdx, %rax
	ja	.L613
	salq	$3, %rbp
	movq	%rbp, %rdi
.LEHB87:
	call	_Znwm
.LEHE87:
	movq	%rax, %r15
.L589:
	movq	%r15, 40(%r13)
	movq	%r15, 48(%r13)
	leaq	(%r15,%rbp), %rbp
	movq	16(%rbx), %r12
	movq	8(%rbx), %rbx
	movq	%rbp, 56(%r13)
	cmpq	%rbx, %r12
	je	.L606
	movq	%r15, %rbp
	.p2align 4,,10
	.p2align 3
.L593:
	testq	%rbp, %rbp
	je	.L592
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB88:
	call	_ZN3fem5pointC1ERKS0_
.LEHE88:
	movq	32(%rbx), %rax
	movq	%rax, 32(%rbp)
.L592:
	addq	$40, %rbx
	addq	$40, %rbp
	cmpq	%rbx, %r12
	jne	.L593
.L591:
	movq	%rbp, 48(%r13)
.L601:
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
.L605:
	.cfi_restore_state
	xorl	%ebp, %ebp
	xorl	%r15d, %r15d
	jmp	.L589
.L612:
	leaq	8(%rdi), %rax
	cmpq	%rax, %rdx
	je	.L587
	movl	32(%rdx), %eax
	cmpl	%eax, (%rcx)
	setl	15(%rsp)
	jmp	.L587
.L606:
	movq	%r15, %rbp
	jmp	.L591
.L607:
.L600:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r13, %rdi
	call	_ZdlPv
.LEHB89:
	call	__cxa_rethrow
.LEHE89:
.L613:
.LEHB90:
	call	_ZSt17__throw_bad_allocv
.LEHE90:
.L610:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%rbp, %rsi
	movq	%r15, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPN5boost6tuples5tupleIN3fem5pointEdNS3_9null_typeES7_S7_S7_S7_S7_S7_S7_EEEEvT_SA_
.LEHB91:
	call	__cxa_rethrow
.LEHE91:
.L608:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB92:
	call	_Unwind_Resume
.LEHE92:
.L609:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	40(%r13), %rdi
	call	_ZNSt12_Vector_baseIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_deallocateEPS6_m.clone.33
	movq	%rbx, %rax
	jmp	.L600
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
	.uleb128 .LEHB86-.LFB3921
	.uleb128 .LEHE86-.LEHB86
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB87-.LFB3921
	.uleb128 .LEHE87-.LEHB87
	.uleb128 .L607-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB88-.LFB3921
	.uleb128 .LEHE88-.LEHB88
	.uleb128 .L610-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB89-.LFB3921
	.uleb128 .LEHE89-.LEHB89
	.uleb128 .L608-.LFB3921
	.uleb128 0x0
	.uleb128 .LEHB90-.LFB3921
	.uleb128 .LEHE90-.LEHB90
	.uleb128 .L607-.LFB3921
	.uleb128 0x1
	.uleb128 .LEHB91-.LFB3921
	.uleb128 .LEHE91-.LEHB91
	.uleb128 .L609-.LFB3921
	.uleb128 0x3
	.uleb128 .LEHB92-.LFB3921
	.uleb128 .LEHE92-.LEHB92
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
	je	.L661
	.cfi_offset 15, -16
	.cfi_offset 12, -40
	movl	(%rdx), %r12d
	cmpl	32(%rsi), %r12d
	jge	.L624
	movq	24(%rdi), %r15
	cmpq	%rsi, %r15
	je	.L627
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_decrementPKSt18_Rb_tree_node_base
	cmpl	32(%rax), %r12d
	jle	.L626
	cmpq	$0, 24(%rax)
	je	.L662
.L627:
	movq	%rbp, %rdx
	movq	%rbp, %rsi
	movq	%r13, %rcx
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
.L617:
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
.L624:
	.cfi_restore_state
	jle	.L617
	cmpq	%rsi, 32(%rdi)
	je	.L659
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	cmpl	32(%rax), %r12d
	jge	.L636
	cmpq	$0, 24(%rbp)
	je	.L659
	movq	%r13, %rcx
	movq	%rax, %rdx
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L617
	.p2align 4,,10
	.p2align 3
.L661:
	cmpq	$0, 40(%rdi)
	je	.L616
	movq	32(%rdi), %rdx
	movl	0(%r13), %eax
	cmpl	%eax, 32(%rdx)
	jl	.L658
.L616:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	je	.L651
	movl	0(%r13), %ecx
	jmp	.L620
	.p2align 4,,10
	.p2align 3
.L664:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %esi
.L619:
	testq	%rax, %rax
	je	.L663
.L620:
	cmpl	32(%rax), %ecx
	jl	.L664
	movq	%rax, %rbp
	xorl	%esi, %esi
	movq	24(%rax), %rax
	jmp	.L619
.L669:
	movq	%r14, %rbp
	.p2align 4,,10
	.p2align 3
.L628:
	cmpq	%rbp, %r15
	je	.L659
.L643:
	movq	%rbp, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbp, %rdx
	movq	%rax, %rbp
.L642:
	cmpl	32(%rbp), %r12d
	jle	.L617
.L658:
	movq	%r13, %rcx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L617
	.p2align 4,,10
	.p2align 3
.L626:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	jne	.L652
	jmp	.L669
	.p2align 4,,10
	.p2align 3
.L666:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %ecx
.L630:
	testq	%rax, %rax
	je	.L665
.L652:
	cmpl	32(%rax), %r12d
	jl	.L666
	movq	%rax, %rbp
	xorl	%ecx, %ecx
	movq	24(%rax), %rax
	jmp	.L630
	.p2align 4,,10
	.p2align 3
.L665:
	testb	%cl, %cl
	movq	%rbp, %rdx
	je	.L642
	jmp	.L628
	.p2align 4,,10
	.p2align 3
.L663:
	testb	%sil, %sil
	movq	%rbp, %rdx
	jne	.L645
.L621:
	cmpl	%ecx, 32(%rbp)
	.p2align 4,,2
	jge	.L617
	.p2align 4,,2
	jmp	.L658
	.p2align 4,,10
	.p2align 3
.L636:
	movq	16(%rbx), %rax
	testq	%rax, %rax
	jne	.L653
	.p2align 4,,4
	jmp	.L670
	.p2align 4,,10
	.p2align 3
.L668:
	movq	%rax, %rbp
	movq	16(%rax), %rax
	movl	$1, %ecx
.L640:
	testq	%rax, %rax
	je	.L667
.L653:
	cmpl	32(%rax), %r12d
	jl	.L668
	movq	%rax, %rbp
	xorl	%ecx, %ecx
	movq	24(%rax), %rax
	jmp	.L640
	.p2align 4,,10
	.p2align 3
.L651:
	movq	%r14, %rbp
.L645:
	cmpq	24(%rbx), %rbp
	je	.L659
	movq	%rbp, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbp, %rdx
	movl	0(%r13), %ecx
	movq	%rax, %rbp
	jmp	.L621
	.p2align 4,,10
	.p2align 3
.L662:
	movq	%r13, %rcx
	movq	%rax, %rdx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L617
	.p2align 4,,10
	.p2align 3
.L667:
	testb	%cl, %cl
	movq	%rbp, %rdx
	je	.L642
.L638:
	cmpq	24(%rbx), %rbp
	jne	.L643
	.p2align 4,,10
	.p2align 3
.L659:
	movq	%rbp, %rdx
	movq	%r13, %rcx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE10_M_insert_EPKSt18_Rb_tree_node_baseSL_RKSC_
	movq	%rax, %rbp
	jmp	.L617
.L670:
	movq	%r14, %rbp
	jmp	.L638
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
.LEHB93:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE93:
	leaq	3504(%rsp), %rsi
	leaq	1984(%rsp), %rdi
.LEHB94:
	call	_ZN3fem5pointC1ERKS0_
.LEHE94:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4595172819793696085, %r10
	movq	%r10, 2016(%rsp)
	je	.L672
	testq	%rbx, %rbx
	je	.L673
	leaq	1984(%rsp), %rsi
	movq	%rbx, %rdi
	leaq	3728(%rsp), %rbp
.LEHB95:
	call	_ZN3fem5pointC1ERKS0_
.LEHE95:
	movq	2016(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L673:
	addq	$40, %rbx
	leaq	3728(%rsp), %rbp
	movq	%rbx, 3736(%rsp)
.L674:
	leaq	1984(%rsp), %rdi
.LEHB96:
	call	_ZN3fem5pointD1Ev
.LEHE96:
	leaq	3504(%rsp), %rdi
.LEHB97:
	call	_ZN3fem5pointD1Ev
	leaq	24(%r14), %r12
	movq	32(%r14), %rax
	movq	%r12, %r13
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1258:
	testq	%rax, %rax
	je	.L677
.L1263:
	movl	32(%rax), %r9d
	testl	%r9d, %r9d
	jle	.L678
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1263
.L677:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L681
	cmpl	$1, 32(%rsi)
	jg	.L681
.L700:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE97:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L705
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L708:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB98:
	call	_ZN3fem5pointD1Ev
.LEHE98:
	cmpq	%rbx, %r15
	jne	.L708
.L705:
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
.LEHB99:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE99:
	leaq	3472(%rsp), %rsi
	leaq	1936(%rsp), %rdi
.LEHB100:
	call	_ZN3fem5pointC1ERKS0_
.LEHE100:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %rcx
	movq	%rcx, 1968(%rsp)
	je	.L709
	testq	%rbx, %rbx
	je	.L710
	leaq	1936(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB101:
	call	_ZN3fem5pointC1ERKS0_
.LEHE101:
	movq	1968(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L710:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L711:
	leaq	1936(%rsp), %rdi
.LEHB102:
	call	_ZN3fem5pointD1Ev
.LEHE102:
	leaq	3472(%rsp), %rdi
.LEHB103:
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
.LEHE103:
	leaq	3440(%rsp), %rsi
	leaq	1888(%rsp), %rdi
.LEHB104:
	call	_ZN3fem5pointC1ERKS0_
.LEHE104:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %rax
	movq	%rax, 1920(%rsp)
	je	.L714
	testq	%rbx, %rbx
	je	.L715
	leaq	1888(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB105:
	call	_ZN3fem5pointC1ERKS0_
.LEHE105:
	movq	1920(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L715:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L716:
	leaq	1888(%rsp), %rdi
.LEHB106:
	call	_ZN3fem5pointD1Ev
.LEHE106:
	leaq	3440(%rsp), %rdi
.LEHB107:
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
.LEHE107:
	leaq	3408(%rsp), %rsi
	leaq	1840(%rsp), %rdi
.LEHB108:
	call	_ZN3fem5pointC1ERKS0_
.LEHE108:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %r15
	movq	%r15, 1872(%rsp)
	je	.L719
	testq	%rbx, %rbx
	je	.L720
	leaq	1840(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB109:
	call	_ZN3fem5pointC1ERKS0_
.LEHE109:
	movq	1872(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L720:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L721:
	leaq	1840(%rsp), %rdi
.LEHB110:
	call	_ZN3fem5pointD1Ev
.LEHE110:
	leaq	3408(%rsp), %rdi
.LEHB111:
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
.LEHE111:
	leaq	3376(%rsp), %rsi
	leaq	1792(%rsp), %rdi
.LEHB112:
	call	_ZN3fem5pointC1ERKS0_
.LEHE112:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4586165620538955093, %r9
	movq	%r9, 1824(%rsp)
	je	.L724
	testq	%rbx, %rbx
	je	.L725
	leaq	1792(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB113:
	call	_ZN3fem5pointC1ERKS0_
.LEHE113:
	movq	1824(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L725:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L726:
	leaq	1792(%rsp), %rdi
.LEHB114:
	call	_ZN3fem5pointD1Ev
.LEHE114:
	leaq	3376(%rsp), %rdi
.LEHB115:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1259:
	testq	%rax, %rax
	je	.L729
.L1264:
	cmpl	$1, 32(%rax)
	jle	.L730
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1264
.L729:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L733
	cmpl	$2, 32(%rsi)
	jg	.L733
.L752:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE115:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L756
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L759:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB116:
	call	_ZN3fem5pointD1Ev
.LEHE116:
	cmpq	%rbx, %r15
	jne	.L759
.L756:
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
.LEHB117:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE117:
	leaq	3344(%rsp), %rsi
	leaq	1744(%rsp), %rdi
.LEHB118:
	call	_ZN3fem5pointC1ERKS0_
.LEHE118:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rcx
	movq	%rcx, 1776(%rsp)
	je	.L760
	testq	%rbx, %rbx
	je	.L761
	leaq	1744(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB119:
	call	_ZN3fem5pointC1ERKS0_
.LEHE119:
	movq	1776(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L761:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L762:
	leaq	1744(%rsp), %rdi
.LEHB120:
	call	_ZN3fem5pointD1Ev
.LEHE120:
	leaq	3344(%rsp), %rdi
.LEHB121:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC2(%rip), %xmm1
	leaq	4056(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	3312(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4056(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE121:
	leaq	3312(%rsp), %rsi
	leaq	1696(%rsp), %rdi
.LEHB122:
	call	_ZN3fem5pointC1ERKS0_
.LEHE122:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rdx
	movq	%rdx, 1728(%rsp)
	je	.L765
	testq	%rbx, %rbx
	je	.L766
	leaq	1696(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB123:
	call	_ZN3fem5pointC1ERKS0_
.LEHE123:
	movq	1728(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L766:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L767:
	leaq	1696(%rsp), %rdi
.LEHB124:
	call	_ZN3fem5pointD1Ev
.LEHE124:
	leaq	3312(%rsp), %rdi
.LEHB125:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	4048(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	3280(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4048(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE125:
	leaq	3280(%rsp), %rsi
	leaq	1648(%rsp), %rdi
.LEHB126:
	call	_ZN3fem5pointC1ERKS0_
.LEHE126:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rax
	movq	%rax, 1680(%rsp)
	je	.L770
	testq	%rbx, %rbx
	je	.L771
	leaq	1648(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB127:
	call	_ZN3fem5pointC1ERKS0_
.LEHE127:
	movq	1680(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L771:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L772:
	leaq	1648(%rsp), %rdi
.LEHB128:
	call	_ZN3fem5pointD1Ev
.LEHE128:
	leaq	3280(%rsp), %rdi
.LEHB129:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	3248(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE129:
	leaq	3248(%rsp), %rsi
	leaq	1600(%rsp), %rdi
.LEHB130:
	call	_ZN3fem5pointC1ERKS0_
.LEHE130:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4582311882724298228, %rax
	movq	%rax, 1632(%rsp)
	je	.L775
	testq	%rbx, %rbx
	je	.L776
	leaq	1600(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB131:
	call	_ZN3fem5pointC1ERKS0_
.LEHE131:
	movq	1632(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L776:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L777:
	leaq	1600(%rsp), %rdi
.LEHB132:
	call	_ZN3fem5pointD1Ev
.LEHE132:
	leaq	3248(%rsp), %rdi
.LEHB133:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	4040(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	3216(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4040(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE133:
	leaq	3216(%rsp), %rsi
	leaq	1552(%rsp), %rdi
.LEHB134:
	call	_ZN3fem5pointC1ERKS0_
.LEHE134:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1584(%rsp)
	je	.L780
	testq	%rbx, %rbx
	je	.L781
	leaq	1552(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB135:
	call	_ZN3fem5pointC1ERKS0_
.LEHE135:
	movq	1584(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L781:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L782:
	leaq	1552(%rsp), %rdi
.LEHB136:
	call	_ZN3fem5pointD1Ev
.LEHE136:
	leaq	3216(%rsp), %rdi
.LEHB137:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm1
	leaq	4032(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	3184(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4032(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE137:
	leaq	3184(%rsp), %rsi
	leaq	1504(%rsp), %rdi
.LEHB138:
	call	_ZN3fem5pointC1ERKS0_
.LEHE138:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1536(%rsp)
	je	.L785
	testq	%rbx, %rbx
	je	.L786
	leaq	1504(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB139:
	call	_ZN3fem5pointC1ERKS0_
.LEHE139:
	movq	1536(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L786:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L787:
	leaq	1504(%rsp), %rdi
.LEHB140:
	call	_ZN3fem5pointD1Ev
.LEHE140:
	leaq	3184(%rsp), %rdi
.LEHB141:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm1
	leaq	4024(%rsp), %rcx
	mulsd	3704(%rsp), %xmm0
	leaq	3152(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4024(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE141:
	leaq	3152(%rsp), %rsi
	leaq	1456(%rsp), %rdi
.LEHB142:
	call	_ZN3fem5pointC1ERKS0_
.LEHE142:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1488(%rsp)
	je	.L790
	testq	%rbx, %rbx
	je	.L791
	leaq	1456(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB143:
	call	_ZN3fem5pointC1ERKS0_
.LEHE143:
	movq	1488(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L791:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L792:
	leaq	1456(%rsp), %rdi
.LEHB144:
	call	_ZN3fem5pointD1Ev
.LEHE144:
	leaq	3152(%rsp), %rdi
.LEHB145:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	3120(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE145:
	leaq	3120(%rsp), %rsi
	leaq	1408(%rsp), %rdi
.LEHB146:
	call	_ZN3fem5pointC1ERKS0_
.LEHE146:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581012159098870966, %rax
	movq	%rax, 1440(%rsp)
	je	.L795
	testq	%rbx, %rbx
	je	.L796
	leaq	1408(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB147:
	call	_ZN3fem5pointC1ERKS0_
.LEHE147:
	movq	1440(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L796:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L797:
	leaq	1408(%rsp), %rdi
.LEHB148:
	call	_ZN3fem5pointD1Ev
.LEHE148:
	leaq	3120(%rsp), %rdi
.LEHB149:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1260:
	testq	%rax, %rax
	je	.L800
.L1265:
	cmpl	$2, 32(%rax)
	jle	.L801
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1265
.L800:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L804
	cmpl	$3, 32(%rsi)
	jg	.L804
.L823:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE149:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L827
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L830:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB150:
	call	_ZN3fem5pointD1Ev
.LEHE150:
	cmpq	%rbx, %r15
	jne	.L830
.L827:
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
.LEHB151:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE151:
	leaq	3088(%rsp), %rsi
	leaq	1360(%rsp), %rdi
.LEHB152:
	call	_ZN3fem5pointC1ERKS0_
.LEHE152:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %r9
	movq	%r9, 1392(%rsp)
	je	.L831
	testq	%rbx, %rbx
	je	.L832
	leaq	1360(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB153:
	call	_ZN3fem5pointC1ERKS0_
.LEHE153:
	movq	1392(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L832:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L833:
	leaq	1360(%rsp), %rdi
.LEHB154:
	call	_ZN3fem5pointD1Ev
.LEHE154:
	leaq	3088(%rsp), %rdi
.LEHB155:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC2(%rip), %xmm1
	leaq	4008(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	3056(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4008(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE155:
	leaq	3056(%rsp), %rsi
	leaq	1312(%rsp), %rdi
.LEHB156:
	call	_ZN3fem5pointC1ERKS0_
.LEHE156:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %r8
	movq	%r8, 1344(%rsp)
	je	.L836
	testq	%rbx, %rbx
	je	.L837
	leaq	1312(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB157:
	call	_ZN3fem5pointC1ERKS0_
.LEHE157:
	movq	1344(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L837:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L838:
	leaq	1312(%rsp), %rdi
.LEHB158:
	call	_ZN3fem5pointD1Ev
.LEHE158:
	leaq	3056(%rsp), %rdi
.LEHB159:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	4000(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	3024(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 4000(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE159:
	leaq	3024(%rsp), %rsi
	leaq	1264(%rsp), %rdi
.LEHB160:
	call	_ZN3fem5pointC1ERKS0_
.LEHE160:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %rdi
	movq	%rdi, 1296(%rsp)
	je	.L841
	testq	%rbx, %rbx
	je	.L842
	leaq	1264(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB161:
	call	_ZN3fem5pointC1ERKS0_
.LEHE161:
	movq	1296(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L842:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L843:
	leaq	1264(%rsp), %rdi
.LEHB162:
	call	_ZN3fem5pointD1Ev
.LEHE162:
	leaq	3024(%rsp), %rdi
.LEHB163:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	2992(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE163:
	leaq	2992(%rsp), %rsi
	leaq	1216(%rsp), %rdi
.LEHB164:
	call	_ZN3fem5pointC1ERKS0_
.LEHE164:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578214597601707707, %rsi
	movq	%rsi, 1248(%rsp)
	je	.L846
	testq	%rbx, %rbx
	je	.L847
	leaq	1216(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB165:
	call	_ZN3fem5pointC1ERKS0_
.LEHE165:
	movq	1248(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L847:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L848:
	leaq	1216(%rsp), %rdi
.LEHB166:
	call	_ZN3fem5pointD1Ev
.LEHE166:
	leaq	2992(%rsp), %rdi
.LEHB167:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	3992(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	2960(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3992(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE167:
	leaq	2960(%rsp), %rsi
	leaq	1168(%rsp), %rdi
.LEHB168:
	call	_ZN3fem5pointC1ERKS0_
.LEHE168:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rcx
	movq	%rcx, 1200(%rsp)
	je	.L851
	testq	%rbx, %rbx
	je	.L852
	leaq	1168(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB169:
	call	_ZN3fem5pointC1ERKS0_
.LEHE169:
	movq	1200(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L852:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L853:
	leaq	1168(%rsp), %rdi
.LEHB170:
	call	_ZN3fem5pointD1Ev
.LEHE170:
	leaq	2960(%rsp), %rdi
.LEHB171:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm1
	leaq	3984(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	2928(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3984(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE171:
	leaq	2928(%rsp), %rsi
	leaq	1120(%rsp), %rdi
.LEHB172:
	call	_ZN3fem5pointC1ERKS0_
.LEHE172:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rdx
	movq	%rdx, 1152(%rsp)
	je	.L856
	testq	%rbx, %rbx
	je	.L857
	leaq	1120(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB173:
	call	_ZN3fem5pointC1ERKS0_
.LEHE173:
	movq	1152(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L857:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L858:
	leaq	1120(%rsp), %rdi
.LEHB174:
	call	_ZN3fem5pointD1Ev
.LEHE174:
	leaq	2928(%rsp), %rdi
.LEHB175:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm1
	leaq	3976(%rsp), %rcx
	mulsd	3704(%rsp), %xmm0
	leaq	2896(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3976(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE175:
	leaq	2896(%rsp), %rsi
	leaq	1072(%rsp), %rdi
.LEHB176:
	call	_ZN3fem5pointC1ERKS0_
.LEHE176:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rax
	movq	%rax, 1104(%rsp)
	je	.L861
	testq	%rbx, %rbx
	je	.L862
	leaq	1072(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB177:
	call	_ZN3fem5pointC1ERKS0_
.LEHE177:
	movq	1104(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L862:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L863:
	leaq	1072(%rsp), %rdi
.LEHB178:
	call	_ZN3fem5pointD1Ev
.LEHE178:
	leaq	2896(%rsp), %rdi
.LEHB179:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	2864(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE179:
	leaq	2864(%rsp), %rsi
	leaq	1024(%rsp), %rdi
.LEHB180:
	call	_ZN3fem5pointC1ERKS0_
.LEHE180:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581070568611333886, %rax
	movq	%rax, 1056(%rsp)
	je	.L866
	testq	%rbx, %rbx
	je	.L867
	leaq	1024(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB181:
	call	_ZN3fem5pointC1ERKS0_
.LEHE181:
	movq	1056(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L867:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L868:
	leaq	1024(%rsp), %rdi
.LEHB182:
	call	_ZN3fem5pointD1Ev
.LEHE182:
	leaq	2864(%rsp), %rdi
.LEHB183:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rcx
	leaq	3960(%rsp), %rdx
	leaq	3968(%rsp), %rsi
	leaq	2832(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3960(%rsp)
	movsd	%xmm0, 3968(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE183:
	leaq	2832(%rsp), %rsi
	leaq	976(%rsp), %rdi
.LEHB184:
	call	_ZN3fem5pointC1ERKS0_
.LEHE184:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 1008(%rsp)
	je	.L871
	testq	%rbx, %rbx
	je	.L872
	leaq	976(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB185:
	call	_ZN3fem5pointC1ERKS0_
.LEHE185:
	movq	1008(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L872:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L873:
	leaq	976(%rsp), %rdi
.LEHB186:
	call	_ZN3fem5pointD1Ev
.LEHE186:
	leaq	2832(%rsp), %rdi
.LEHB187:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3944(%rsp), %rcx
	leaq	3952(%rsp), %rsi
	leaq	2800(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3944(%rsp)
	movsd	%xmm0, 3952(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE187:
	leaq	2800(%rsp), %rsi
	leaq	928(%rsp), %rdi
.LEHB188:
	call	_ZN3fem5pointC1ERKS0_
.LEHE188:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 960(%rsp)
	je	.L876
	testq	%rbx, %rbx
	je	.L877
	leaq	928(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB189:
	call	_ZN3fem5pointC1ERKS0_
.LEHE189:
	movq	960(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L877:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L878:
	leaq	928(%rsp), %rdi
.LEHB190:
	call	_ZN3fem5pointD1Ev
.LEHE190:
	leaq	2800(%rsp), %rdi
.LEHB191:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3936(%rsp), %rsi
	leaq	2768(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rdx, %rcx
	movsd	%xmm0, 3936(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE191:
	leaq	2768(%rsp), %rsi
	leaq	880(%rsp), %rdi
.LEHB192:
	call	_ZN3fem5pointC1ERKS0_
.LEHE192:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 912(%rsp)
	je	.L881
	testq	%rbx, %rbx
	je	.L882
	leaq	880(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB193:
	call	_ZN3fem5pointC1ERKS0_
.LEHE193:
	movq	912(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L882:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L883:
	leaq	880(%rsp), %rdi
.LEHB194:
	call	_ZN3fem5pointD1Ev
.LEHE194:
	leaq	2768(%rsp), %rdi
.LEHB195:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3920(%rsp), %rcx
	leaq	3928(%rsp), %rdx
	leaq	2736(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3920(%rsp)
	movsd	%xmm0, 3928(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE195:
	leaq	2736(%rsp), %rsi
	leaq	832(%rsp), %rdi
.LEHB196:
	call	_ZN3fem5pointC1ERKS0_
.LEHE196:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %rax
	movq	%rax, 864(%rsp)
	je	.L886
	testq	%rbx, %rbx
	je	.L887
	leaq	832(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB197:
	call	_ZN3fem5pointC1ERKS0_
.LEHE197:
	movq	864(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L887:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L888:
	leaq	832(%rsp), %rdi
.LEHB198:
	call	_ZN3fem5pointD1Ev
.LEHE198:
	leaq	2736(%rsp), %rdi
.LEHB199:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3912(%rsp), %rdx
	leaq	2704(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rcx
	movsd	%xmm0, 3912(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE199:
	leaq	2704(%rsp), %rsi
	leaq	784(%rsp), %rdi
.LEHB200:
	call	_ZN3fem5pointC1ERKS0_
.LEHE200:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4574825392535240915, %r15
	movq	%r15, 816(%rsp)
	je	.L891
	testq	%rbx, %rbx
	je	.L892
	leaq	784(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB201:
	call	_ZN3fem5pointC1ERKS0_
.LEHE201:
	movq	816(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L892:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L893:
	leaq	784(%rsp), %rdi
.LEHB202:
	call	_ZN3fem5pointD1Ev
.LEHE202:
	leaq	2704(%rsp), %rdi
.LEHB203:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3904(%rsp), %rcx
	leaq	2672(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rdx
	movsd	%xmm0, 3904(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE203:
	leaq	2672(%rsp), %rsi
	leaq	736(%rsp), %rdi
.LEHB204:
	call	_ZN3fem5pointC1ERKS0_
.LEHE204:
	movabsq	$4574825392535240915, %rbx
	movq	%rbx, 768(%rsp)
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	je	.L896
	testq	%rbx, %rbx
	je	.L897
	leaq	736(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB205:
	call	_ZN3fem5pointC1ERKS0_
.LEHE205:
	movq	768(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L897:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L898:
	leaq	736(%rsp), %rdi
.LEHB206:
	call	_ZN3fem5pointD1Ev
.LEHE206:
	leaq	2672(%rsp), %rdi
.LEHB207:
	call	_ZN3fem5pointD1Ev
	movq	32(%r14), %rax
	movq	%r12, %rsi
	.p2align 4,,10
	.p2align 3
.L1261:
	testq	%rax, %rax
	je	.L901
.L1266:
	cmpl	$3, 32(%rax)
	jle	.L902
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1266
.L901:
	cmpq	%rsi, %r12
	movq	%rsi, 8(%rsp)
	je	.L905
	cmpl	$4, 32(%rsi)
	jg	.L905
.L924:
	movq	8(%rsp), %rdi
	movq	%rbp, %rsi
	addq	$40, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE207:
	movq	3728(%rsp), %rax
	movq	3736(%rsp), %r15
	cmpq	%r15, %rax
	movq	%rax, 8(%rsp)
	je	.L928
	movq	%rax, %rbx
	.p2align 4,,10
	.p2align 3
.L931:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB208:
	call	_ZN3fem5pointD1Ev
.LEHE208:
	cmpq	%rbx, %r15
	jne	.L931
.L928:
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
.LEHB209:
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE209:
	leaq	2640(%rsp), %rsi
	leaq	688(%rsp), %rdi
.LEHB210:
	call	_ZN3fem5pointC1ERKS0_
.LEHE210:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rdi
	movq	%rdi, 720(%rsp)
	je	.L932
	testq	%rbx, %rbx
	je	.L933
	leaq	688(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB211:
	call	_ZN3fem5pointC1ERKS0_
.LEHE211:
	movq	720(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L933:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L934:
	leaq	688(%rsp), %rdi
.LEHB212:
	call	_ZN3fem5pointD1Ev
.LEHE212:
	leaq	2640(%rsp), %rdi
.LEHB213:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rcx
	movsd	.LC2(%rip), %xmm1
	leaq	3888(%rsp), %rdx
	mulsd	3696(%rsp), %xmm0
	leaq	2608(%rsp), %rdi
	movq	%rcx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3888(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE213:
	leaq	2608(%rsp), %rsi
	leaq	640(%rsp), %rdi
.LEHB214:
	call	_ZN3fem5pointC1ERKS0_
.LEHE214:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rsi
	movq	%rsi, 672(%rsp)
	je	.L937
	testq	%rbx, %rbx
	je	.L938
	leaq	640(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB215:
	call	_ZN3fem5pointC1ERKS0_
.LEHE215:
	movq	672(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L938:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L939:
	leaq	640(%rsp), %rdi
.LEHB216:
	call	_ZN3fem5pointD1Ev
.LEHE216:
	leaq	2608(%rsp), %rdi
.LEHB217:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3696(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	3880(%rsp), %rcx
	mulsd	3696(%rsp), %xmm0
	leaq	2576(%rsp), %rdi
	movq	%rdx, %rsi
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3880(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE217:
	leaq	2576(%rsp), %rsi
	leaq	592(%rsp), %rdi
.LEHB218:
	call	_ZN3fem5pointC1ERKS0_
.LEHE218:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rcx
	movq	%rcx, 624(%rsp)
	je	.L942
	testq	%rbx, %rbx
	je	.L943
	leaq	592(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB219:
	call	_ZN3fem5pointC1ERKS0_
.LEHE219:
	movq	624(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L943:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L944:
	leaq	592(%rsp), %rdi
.LEHB220:
	call	_ZN3fem5pointD1Ev
.LEHE220:
	leaq	2576(%rsp), %rdi
.LEHB221:
	call	_ZN3fem5pointD1Ev
	leaq	3696(%rsp), %rcx
	leaq	2544(%rsp), %rdi
	movq	%rcx, %rdx
	movq	%rcx, %rsi
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE221:
	leaq	2544(%rsp), %rsi
	leaq	544(%rsp), %rdi
.LEHB222:
	call	_ZN3fem5pointC1ERKS0_
.LEHE222:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4578065106020014687, %rdx
	movq	%rdx, 576(%rsp)
	je	.L947
	testq	%rbx, %rbx
	je	.L948
	leaq	544(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB223:
	call	_ZN3fem5pointC1ERKS0_
.LEHE223:
	movq	576(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L948:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L949:
	leaq	544(%rsp), %rdi
.LEHB224:
	call	_ZN3fem5pointD1Ev
.LEHE224:
	leaq	2544(%rsp), %rdi
.LEHB225:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rdx
	movsd	.LC2(%rip), %xmm1
	leaq	3872(%rsp), %rsi
	mulsd	3704(%rsp), %xmm0
	leaq	2512(%rsp), %rdi
	movq	%rdx, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3872(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE225:
	leaq	2512(%rsp), %rsi
	leaq	496(%rsp), %rdi
.LEHB226:
	call	_ZN3fem5pointC1ERKS0_
.LEHE226:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 528(%rsp)
	je	.L952
	testq	%rbx, %rbx
	je	.L953
	leaq	496(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB227:
	call	_ZN3fem5pointC1ERKS0_
.LEHE227:
	movq	528(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L953:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L954:
	leaq	496(%rsp), %rdi
.LEHB228:
	call	_ZN3fem5pointD1Ev
.LEHE228:
	leaq	2512(%rsp), %rdi
.LEHB229:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm0
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm1
	leaq	3864(%rsp), %rdx
	mulsd	3704(%rsp), %xmm0
	leaq	2480(%rsp), %rdi
	movq	%rsi, %rcx
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 3864(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE229:
	leaq	2480(%rsp), %rsi
	leaq	448(%rsp), %rdi
.LEHB230:
	call	_ZN3fem5pointC1ERKS0_
.LEHE230:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 480(%rsp)
	je	.L957
	testq	%rbx, %rbx
	je	.L958
	leaq	448(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB231:
	call	_ZN3fem5pointC1ERKS0_
.LEHE231:
	movq	480(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L958:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L959:
	leaq	448(%rsp), %rdi
.LEHB232:
	call	_ZN3fem5pointD1Ev
.LEHE232:
	leaq	2480(%rsp), %rdi
.LEHB233:
	call	_ZN3fem5pointD1Ev
	movsd	.LC17(%rip), %xmm1
	leaq	3704(%rsp), %rsi
	movsd	.LC2(%rip), %xmm0
	leaq	3856(%rsp), %rcx
	mulsd	3704(%rsp), %xmm1
	leaq	2448(%rsp), %rdi
	movq	%rsi, %rdx
	subsd	%xmm1, %xmm0
	movsd	%xmm0, 3856(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE233:
	leaq	2448(%rsp), %rsi
	leaq	400(%rsp), %rdi
.LEHB234:
	call	_ZN3fem5pointC1ERKS0_
.LEHE234:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 432(%rsp)
	je	.L962
	testq	%rbx, %rbx
	je	.L963
	leaq	400(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB235:
	call	_ZN3fem5pointC1ERKS0_
.LEHE235:
	movq	432(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L963:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L964:
	leaq	400(%rsp), %rdi
.LEHB236:
	call	_ZN3fem5pointD1Ev
.LEHE236:
	leaq	2448(%rsp), %rdi
.LEHB237:
	call	_ZN3fem5pointD1Ev
	leaq	3704(%rsp), %rsi
	leaq	2416(%rsp), %rdi
	movq	%rsi, %rcx
	movq	%rsi, %rdx
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE237:
	leaq	2416(%rsp), %rsi
	leaq	352(%rsp), %rdi
.LEHB238:
	call	_ZN3fem5pointC1ERKS0_
.LEHE238:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4577789473564037728, %rax
	movq	%rax, 384(%rsp)
	je	.L967
	testq	%rbx, %rbx
	je	.L968
	leaq	352(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB239:
	call	_ZN3fem5pointC1ERKS0_
.LEHE239:
	movq	384(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L968:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L969:
	leaq	352(%rsp), %rdi
.LEHB240:
	call	_ZN3fem5pointD1Ev
.LEHE240:
	leaq	2416(%rsp), %rdi
.LEHB241:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rcx
	leaq	3840(%rsp), %rdx
	leaq	3848(%rsp), %rsi
	leaq	2384(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3840(%rsp)
	movsd	%xmm0, 3848(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE241:
	leaq	2384(%rsp), %rsi
	leaq	304(%rsp), %rdi
.LEHB242:
	call	_ZN3fem5pointC1ERKS0_
.LEHE242:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %rax
	movq	%rax, 336(%rsp)
	je	.L972
	testq	%rbx, %rbx
	je	.L973
	leaq	304(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB243:
	call	_ZN3fem5pointC1ERKS0_
.LEHE243:
	movq	336(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L973:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L974:
	leaq	304(%rsp), %rdi
.LEHB244:
	call	_ZN3fem5pointD1Ev
.LEHE244:
	leaq	2384(%rsp), %rdi
.LEHB245:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3824(%rsp), %rcx
	leaq	3832(%rsp), %rsi
	leaq	2352(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3824(%rsp)
	movsd	%xmm0, 3832(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE245:
	leaq	2352(%rsp), %rsi
	leaq	256(%rsp), %rdi
.LEHB246:
	call	_ZN3fem5pointC1ERKS0_
.LEHE246:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %rax
	movq	%rax, 288(%rsp)
	je	.L977
	testq	%rbx, %rbx
	je	.L978
	leaq	256(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB247:
	call	_ZN3fem5pointC1ERKS0_
.LEHE247:
	movq	288(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L978:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L979:
	leaq	256(%rsp), %rdi
.LEHB248:
	call	_ZN3fem5pointD1Ev
.LEHE248:
	leaq	2352(%rsp), %rdi
.LEHB249:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rdx
	leaq	3816(%rsp), %rsi
	leaq	2320(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rdx, %rcx
	movsd	%xmm0, 3816(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE249:
	leaq	2320(%rsp), %rsi
	leaq	208(%rsp), %rdi
.LEHB250:
	call	_ZN3fem5pointC1ERKS0_
.LEHE250:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r15
	movq	%r15, 240(%rsp)
	je	.L982
	testq	%rbx, %rbx
	je	.L983
	leaq	208(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB251:
	call	_ZN3fem5pointC1ERKS0_
.LEHE251:
	movq	240(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L983:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L984:
	leaq	208(%rsp), %rdi
.LEHB252:
	call	_ZN3fem5pointD1Ev
.LEHE252:
	leaq	2320(%rsp), %rdi
.LEHB253:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3800(%rsp), %rcx
	leaq	3808(%rsp), %rdx
	leaq	2288(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movsd	%xmm0, 3800(%rsp)
	movsd	%xmm0, 3808(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE253:
	leaq	2288(%rsp), %rsi
	leaq	160(%rsp), %rdi
.LEHB254:
	call	_ZN3fem5pointC1ERKS0_
.LEHE254:
	movabsq	$4576237049931877280, %rbx
	movq	%rbx, 192(%rsp)
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	je	.L987
	testq	%rbx, %rbx
	je	.L988
	leaq	160(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB255:
	call	_ZN3fem5pointC1ERKS0_
.LEHE255:
	movq	192(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L988:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L989:
	leaq	160(%rsp), %rdi
.LEHB256:
	call	_ZN3fem5pointD1Ev
.LEHE256:
	leaq	2288(%rsp), %rdi
.LEHB257:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3792(%rsp), %rdx
	leaq	2256(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rcx
	movsd	%xmm0, 3792(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE257:
	leaq	2256(%rsp), %rsi
	leaq	112(%rsp), %rdi
.LEHB258:
	call	_ZN3fem5pointC1ERKS0_
.LEHE258:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r11
	movq	%r11, 144(%rsp)
	je	.L992
	testq	%rbx, %rbx
	je	.L993
	leaq	112(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB259:
	call	_ZN3fem5pointC1ERKS0_
.LEHE259:
	movq	144(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L993:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L994:
	leaq	112(%rsp), %rdi
.LEHB260:
	call	_ZN3fem5pointD1Ev
.LEHE260:
	leaq	2256(%rsp), %rdi
.LEHB261:
	call	_ZN3fem5pointD1Ev
	movsd	.LC1(%rip), %xmm0
	leaq	3712(%rsp), %rsi
	leaq	3784(%rsp), %rcx
	leaq	2224(%rsp), %rdi
	subsd	3712(%rsp), %xmm0
	movq	%rsi, %rdx
	movsd	%xmm0, 3784(%rsp)
	call	_ZN3fem5pointC1ERKdS2_S2_
.LEHE261:
	leaq	2224(%rsp), %rsi
	leaq	64(%rsp), %rdi
.LEHB262:
	call	_ZN3fem5pointC1ERKS0_
.LEHE262:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4576237049931877280, %r10
	movq	%r10, 96(%rsp)
	je	.L997
	testq	%rbx, %rbx
	je	.L998
	leaq	64(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB263:
	call	_ZN3fem5pointC1ERKS0_
.LEHE263:
	movq	96(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L998:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L999:
	leaq	64(%rsp), %rdi
.LEHB264:
	call	_ZN3fem5pointD1Ev
.LEHE264:
	leaq	2224(%rsp), %rdi
.LEHB265:
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
.LEHE265:
	leaq	2192(%rsp), %rsi
	leaq	16(%rsp), %rdi
.LEHB266:
	call	_ZN3fem5pointC1ERKS0_
.LEHE266:
	movq	3736(%rsp), %rbx
	cmpq	3744(%rsp), %rbx
	movabsq	$4581350660937346637, %rsi
	movq	%rsi, 48(%rsp)
	je	.L1002
	testq	%rbx, %rbx
	je	.L1003
	leaq	16(%rsp), %rsi
	movq	%rbx, %rdi
.LEHB267:
	call	_ZN3fem5pointC1ERKS0_
.LEHE267:
	movq	48(%rsp), %rax
	movq	%rax, 32(%rbx)
	movq	3736(%rsp), %rbx
.L1003:
	addq	$40, %rbx
	movq	%rbx, 3736(%rsp)
.L1004:
	leaq	16(%rsp), %rdi
.LEHB268:
	call	_ZN3fem5pointD1Ev
.LEHE268:
	leaq	2192(%rsp), %rdi
.LEHB269:
	call	_ZN3fem5pointD1Ev
.LEHE269:
	movq	32(%r14), %rax
	.p2align 4,,10
	.p2align 3
.L1262:
	testq	%rax, %rax
	je	.L1007
.L1267:
	cmpl	$4, 32(%rax)
	jle	.L1008
	movq	%rax, %r13
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L1267
.L1007:
	cmpq	%r13, %r12
	movq	%r13, %r15
	je	.L1011
	cmpl	$5, 32(%r13)
	jle	.L1030
.L1011:
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
.LEHB270:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE270:
	movq	2048(%rsp), %r12
	movq	2040(%rsp), %rbx
	movq	%rax, %r15
	cmpq	%rbx, %r12
	je	.L1013
	.p2align 4,,10
	.p2align 3
.L1223:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB271:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r12
	jne	.L1223
	movq	2040(%rsp), %rbx
.L1013:
	testq	%rbx, %rbx
	je	.L1022
	movq	%rbx, %rdi
	call	_ZdlPv
.L1022:
	movq	3544(%rsp), %r12
	movq	3536(%rsp), %rbx
	cmpq	%rbx, %r12
	je	.L1023
	.p2align 4,,10
	.p2align 3
.L1222:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE271:
	cmpq	%rbx, %r12
	jne	.L1222
	movq	3536(%rsp), %rbx
.L1023:
	testq	%rbx, %rbx
	je	.L1030
	movq	%rbx, %rdi
	call	_ZdlPv
.L1030:
	leaq	40(%r15), %rdi
	movq	%rbp, %rsi
.LEHB272:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EEaSERKS8_
.LEHE272:
	movq	3736(%rsp), %rbp
	movq	3728(%rsp), %rbx
	cmpq	%rbx, %rbp
	je	.L1034
	.p2align 4,,10
	.p2align 3
.L1221:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB273:
	call	_ZN3fem5pointD1Ev
.LEHE273:
	cmpq	%rbx, %rbp
	jne	.L1221
	movq	3728(%rsp), %rbx
.L1034:
	testq	%rbx, %rbx
	je	.L671
	movq	%rbx, %rdi
	call	_ZdlPv
.L671:
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
.L678:
	.cfi_restore_state
	movq	24(%rax), %rax
	jmp	.L1258
	.p2align 4,,10
	.p2align 3
.L730:
	movq	24(%rax), %rax
	jmp	.L1259
	.p2align 4,,10
	.p2align 3
.L801:
	movq	24(%rax), %rax
	jmp	.L1260
	.p2align 4,,10
	.p2align 3
.L902:
	movq	24(%rax), %rax
	jmp	.L1261
	.p2align 4,,10
	.p2align 3
.L1008:
	movq	24(%rax), %rax
	jmp	.L1262
	.p2align 4,,10
	.p2align 3
.L709:
	leaq	1936(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB274:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE274:
	jmp	.L711
	.p2align 4,,10
	.p2align 3
.L672:
	leaq	3728(%rsp), %rbp
	leaq	1984(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB275:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE275:
	jmp	.L674
	.p2align 4,,10
	.p2align 3
.L724:
	leaq	1792(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB276:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE276:
	jmp	.L726
	.p2align 4,,10
	.p2align 3
.L719:
	leaq	1840(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB277:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE277:
	jmp	.L721
	.p2align 4,,10
	.p2align 3
.L714:
	leaq	1888(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB278:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE278:
	jmp	.L716
	.p2align 4,,10
	.p2align 3
.L760:
	leaq	1744(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB279:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE279:
	jmp	.L762
	.p2align 4,,10
	.p2align 3
.L765:
	leaq	1696(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB280:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE280:
	jmp	.L767
	.p2align 4,,10
	.p2align 3
.L780:
	leaq	1552(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB281:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE281:
	jmp	.L782
	.p2align 4,,10
	.p2align 3
.L775:
	leaq	1600(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB282:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE282:
	jmp	.L777
	.p2align 4,,10
	.p2align 3
.L770:
	leaq	1648(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB283:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE283:
	jmp	.L772
	.p2align 4,,10
	.p2align 3
.L1002:
	leaq	16(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB284:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE284:
	jmp	.L1004
	.p2align 4,,10
	.p2align 3
.L795:
	leaq	1408(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB285:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE285:
	jmp	.L797
	.p2align 4,,10
	.p2align 3
.L836:
	leaq	1312(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB286:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE286:
	jmp	.L838
	.p2align 4,,10
	.p2align 3
.L831:
	leaq	1360(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB287:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE287:
	jmp	.L833
	.p2align 4,,10
	.p2align 3
.L790:
	leaq	1456(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB288:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE288:
	jmp	.L792
	.p2align 4,,10
	.p2align 3
.L785:
	leaq	1504(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB289:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE289:
	jmp	.L787
	.p2align 4,,10
	.p2align 3
.L861:
	leaq	1072(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB290:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE290:
	jmp	.L863
	.p2align 4,,10
	.p2align 3
.L856:
	leaq	1120(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB291:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE291:
	jmp	.L858
	.p2align 4,,10
	.p2align 3
.L851:
	leaq	1168(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB292:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE292:
	jmp	.L853
	.p2align 4,,10
	.p2align 3
.L846:
	leaq	1216(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB293:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE293:
	jmp	.L848
	.p2align 4,,10
	.p2align 3
.L841:
	leaq	1264(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB294:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE294:
	jmp	.L843
	.p2align 4,,10
	.p2align 3
.L932:
	leaq	688(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB295:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE295:
	jmp	.L934
	.p2align 4,,10
	.p2align 3
.L896:
	leaq	736(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB296:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE296:
	jmp	.L898
	.p2align 4,,10
	.p2align 3
.L891:
	leaq	784(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB297:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE297:
	jmp	.L893
	.p2align 4,,10
	.p2align 3
.L942:
	leaq	592(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB298:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE298:
	jmp	.L944
	.p2align 4,,10
	.p2align 3
.L937:
	leaq	640(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB299:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE299:
	jmp	.L939
	.p2align 4,,10
	.p2align 3
.L886:
	leaq	832(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB300:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE300:
	jmp	.L888
	.p2align 4,,10
	.p2align 3
.L881:
	leaq	880(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB301:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE301:
	jmp	.L883
	.p2align 4,,10
	.p2align 3
.L876:
	leaq	928(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB302:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE302:
	jmp	.L878
	.p2align 4,,10
	.p2align 3
.L871:
	leaq	976(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB303:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE303:
	jmp	.L873
	.p2align 4,,10
	.p2align 3
.L866:
	leaq	1024(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB304:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE304:
	jmp	.L868
	.p2align 4,,10
	.p2align 3
.L997:
	leaq	64(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB305:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE305:
	jmp	.L999
	.p2align 4,,10
	.p2align 3
.L992:
	leaq	112(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB306:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE306:
	jmp	.L994
	.p2align 4,,10
	.p2align 3
.L987:
	leaq	160(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB307:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE307:
	jmp	.L989
	.p2align 4,,10
	.p2align 3
.L982:
	leaq	208(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB308:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE308:
	jmp	.L984
	.p2align 4,,10
	.p2align 3
.L977:
	leaq	256(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB309:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE309:
	jmp	.L979
	.p2align 4,,10
	.p2align 3
.L972:
	leaq	304(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB310:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE310:
	jmp	.L974
	.p2align 4,,10
	.p2align 3
.L967:
	leaq	352(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB311:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE311:
	jmp	.L969
	.p2align 4,,10
	.p2align 3
.L962:
	leaq	400(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB312:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE312:
	jmp	.L964
	.p2align 4,,10
	.p2align 3
.L957:
	leaq	448(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB313:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE313:
	jmp	.L959
	.p2align 4,,10
	.p2align 3
.L952:
	leaq	496(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB314:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE314:
	jmp	.L954
	.p2align 4,,10
	.p2align 3
.L947:
	leaq	544(%rsp), %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
.LEHB315:
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS6_S8_EERKS6_
.LEHE315:
	jmp	.L949
	.p2align 4,,10
	.p2align 3
.L681:
	leaq	16(%r14), %rdi
	leaq	2160(%rsp), %rdx
	movq	$0, 3664(%rsp)
	movq	$0, 3672(%rsp)
	movq	$0, 3680(%rsp)
	movl	$1, 2160(%rsp)
	movq	$0, 2168(%rsp)
	movq	$0, 2184(%rsp)
	movq	$0, 2176(%rsp)
.LEHB316:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE316:
	movq	2176(%rsp), %r15
	movq	2168(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L683
	.p2align 4,,10
	.p2align 3
.L1232:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB317:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1232
	movq	2168(%rsp), %rbx
.L683:
	testq	%rbx, %rbx
	je	.L692
	movq	%rbx, %rdi
	call	_ZdlPv
.L692:
	movq	3672(%rsp), %r15
	movq	3664(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L693
	.p2align 4,,10
	.p2align 3
.L1231:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE317:
	cmpq	%rbx, %r15
	jne	.L1231
	movq	3664(%rsp), %rbx
.L693:
	testq	%rbx, %rbx
	je	.L700
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L700
	.p2align 4,,10
	.p2align 3
.L733:
	leaq	16(%r14), %rdi
	leaq	2128(%rsp), %rdx
	movq	$0, 3632(%rsp)
	movq	$0, 3640(%rsp)
	movq	$0, 3648(%rsp)
	movl	$2, 2128(%rsp)
	movq	$0, 2136(%rsp)
	movq	$0, 2152(%rsp)
	movq	$0, 2144(%rsp)
.LEHB318:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE318:
	movq	2144(%rsp), %r15
	movq	2136(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L735
	.p2align 4,,10
	.p2align 3
.L1230:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB319:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1230
	movq	2136(%rsp), %rbx
.L735:
	testq	%rbx, %rbx
	je	.L744
	movq	%rbx, %rdi
	call	_ZdlPv
.L744:
	movq	3640(%rsp), %r15
	movq	3632(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L745
	.p2align 4,,10
	.p2align 3
.L1229:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE319:
	cmpq	%rbx, %r15
	jne	.L1229
	movq	3632(%rsp), %rbx
.L745:
	testq	%rbx, %rbx
	je	.L752
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L752
	.p2align 4,,10
	.p2align 3
.L804:
	leaq	16(%r14), %rdi
	leaq	2096(%rsp), %rdx
	movq	$0, 3600(%rsp)
	movq	$0, 3608(%rsp)
	movq	$0, 3616(%rsp)
	movl	$3, 2096(%rsp)
	movq	$0, 2104(%rsp)
	movq	$0, 2120(%rsp)
	movq	$0, 2112(%rsp)
.LEHB320:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE320:
	movq	2112(%rsp), %r15
	movq	2104(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L806
	.p2align 4,,10
	.p2align 3
.L1228:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB321:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1228
	movq	2104(%rsp), %rbx
.L806:
	testq	%rbx, %rbx
	je	.L815
	movq	%rbx, %rdi
	call	_ZdlPv
.L815:
	movq	3608(%rsp), %r15
	movq	3600(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L816
	.p2align 4,,10
	.p2align 3
.L1227:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
.LEHE321:
	cmpq	%rbx, %r15
	jne	.L1227
	movq	3600(%rsp), %rbx
.L816:
	testq	%rbx, %rbx
	je	.L823
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L823
	.p2align 4,,10
	.p2align 3
.L905:
	leaq	16(%r14), %rdi
	leaq	2064(%rsp), %rdx
	movq	$0, 3568(%rsp)
	movq	$0, 3576(%rsp)
	movq	$0, 3584(%rsp)
	movl	$4, 2064(%rsp)
	movq	$0, 2072(%rsp)
	movq	$0, 2088(%rsp)
	movq	$0, 2080(%rsp)
.LEHB322:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EE17_M_insert_unique_ESt23_Rb_tree_const_iteratorISC_ERKSC_
.LEHE322:
	movq	2080(%rsp), %r15
	movq	2072(%rsp), %rbx
	movq	%rax, 8(%rsp)
	cmpq	%rbx, %r15
	je	.L907
	.p2align 4,,10
	.p2align 3
.L1226:
	movq	%rbx, %rdi
	addq	$40, %rbx
.LEHB323:
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1226
	movq	2072(%rsp), %rbx
.L907:
	testq	%rbx, %rbx
	je	.L916
	movq	%rbx, %rdi
	call	_ZdlPv
.L916:
	movq	3576(%rsp), %r15
	movq	3568(%rsp), %rbx
	cmpq	%rbx, %r15
	je	.L917
	.p2align 4,,10
	.p2align 3
.L1225:
	movq	%rbx, %rdi
	addq	$40, %rbx
	call	_ZN3fem5pointD1Ev
	cmpq	%rbx, %r15
	jne	.L1225
	movq	3568(%rsp), %rbx
.L917:
	testq	%rbx, %rbx
	je	.L924
	movq	%rbx, %rdi
	call	_ZdlPv
	jmp	.L924
.L1220:
	leaq	2040(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3536(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
.L704:
	movq	%rbp, %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE323:
.L1155:
	leaq	1456(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1066:
	leaq	3152(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1168:
	movq	%rax, %rbx
.L1080:
	leaq	2928(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1167:
	leaq	1168(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1078:
	leaq	2960(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1152:
	movq	%rax, %rbx
.L1064:
	leaq	3184(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1151:
	leaq	1552(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1062:
	leaq	3216(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1153:
	leaq	1504(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1064
.L1171:
	leaq	1072(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1082:
	leaq	2896(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1170:
	movq	%rax, %rbx
	jmp	.L1082
.L1169:
	leaq	1120(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1080
.L1139:
	leaq	1840(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1050:
	leaq	3408(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1136:
	movq	%rax, %rbx
.L1048:
	leaq	3440(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1138:
	movq	%rax, %rbx
	jmp	.L1050
.L1137:
	leaq	1888(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1048
.L1134:
	movq	%rax, %rbx
.L1046:
	leaq	3472(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1135:
	leaq	1936(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1046
.L1132:
	leaq	3728(%rsp), %rbp
	movq	%rax, %rbx
.L1044:
	leaq	3504(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1131:
	movq	%rax, %rbx
	jmp	.L704
.L1142:
	movq	%rax, %rbx
.L1054:
	leaq	3344(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1145:
	leaq	1696(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1056:
	leaq	3312(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1144:
	movq	%rax, %rbx
	jmp	.L1056
.L1143:
	leaq	1744(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1054
.L1133:
	leaq	1984(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1044
.L1140:
	movq	%rax, %rbx
.L1052:
	leaq	3376(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1158:
	movq	%rax, %rbx
.L1070:
	leaq	3088(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1141:
	leaq	1792(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1052
.L1175:
	leaq	976(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1086:
	leaq	2832(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1172:
	movq	%rax, %rbx
.L1084:
	leaq	2864(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1174:
	movq	%rax, %rbx
	jmp	.L1086
.L1173:
	leaq	1024(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1084
.L1178:
	movq	%rax, %rbx
.L1090:
	leaq	2768(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1177:
	leaq	928(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1088:
	leaq	2800(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1179:
	leaq	880(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1090
.L1207:
	leaq	208(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1118:
	leaq	2320(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1201:
	leaq	352(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1112:
	leaq	2416(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1198:
	movq	%rax, %rbx
.L1110:
	leaq	2448(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1200:
	movq	%rax, %rbx
	jmp	.L1112
.L1199:
	leaq	400(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1110
.L1204:
	movq	%rax, %rbx
.L1116:
	leaq	2352(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1203:
	leaq	304(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1114:
	leaq	2384(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1205:
	leaq	256(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1116
.L1202:
	movq	%rax, %rbx
	jmp	.L1114
.L1164:
	movq	%rax, %rbx
.L1076:
	leaq	2992(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1163:
	leaq	1264(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1074:
	leaq	3024(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1162:
	movq	%rax, %rbx
	jmp	.L1074
.L1161:
	leaq	1312(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1072:
	leaq	3056(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1159:
	leaq	1360(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1070
.L1154:
	movq	%rax, %rbx
	jmp	.L1066
.L1156:
	movq	%rax, %rbx
.L1068:
	leaq	3120(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1194:
	movq	%rax, %rbx
.L1106:
	leaq	2512(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1212:
	movq	%rax, %rbx
.L1124:
	leaq	2224(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1211:
	leaq	112(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1122:
	leaq	2256(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1213:
	leaq	64(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1124
.L1210:
	movq	%rax, %rbx
	jmp	.L1122
.L1209:
	leaq	160(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1120:
	leaq	2288(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1206:
	movq	%rax, %rbx
	jmp	.L1118
.L1208:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1120
.L1191:
	leaq	592(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1102:
	leaq	2576(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1146:
	movq	%rax, %rbx
.L1058:
	leaq	3280(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1214:
	movq	%rax, %rbx
.L1126:
	leaq	2192(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1157:
	leaq	1408(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1068
.L1160:
	movq	%rax, %rbx
	jmp	.L1072
.L1150:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1062
.L1149:
	leaq	1600(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1060:
	leaq	3248(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1148:
	movq	%rax, %rbx
	jmp	.L1060
.L1176:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1088
.L1166:
	movq	%rax, %rbx
	.p2align 4,,2
	jmp	.L1078
.L1165:
	leaq	1216(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1076
.L1215:
	leaq	16(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1126
.L1185:
	leaq	736(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1096:
	leaq	2672(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1189:
	leaq	640(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
.L1100:
	leaq	2608(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1180:
	movq	%rax, %rbx
.L1092:
	leaq	2736(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1182:
	movq	%rax, %rbx
.L1094:
	leaq	2704(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1181:
	leaq	832(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1092
.L1186:
	movq	%rax, %rbx
.L1098:
	leaq	2640(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1184:
	movq	%rax, %rbx
	jmp	.L1096
.L1188:
	movq	%rax, %rbx
	.p2align 4,,5
	jmp	.L1100
.L1187:
	leaq	688(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1098
.L1183:
	leaq	784(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1094
.L1190:
	movq	%rax, %rbx
	jmp	.L1102
.L1192:
	movq	%rax, %rbx
.L1104:
	leaq	2544(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1193:
	leaq	544(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1104
.L1196:
	movq	%rax, %rbx
.L1108:
	leaq	2480(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
	jmp	.L704
.L1195:
	leaq	496(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1106
.L1197:
	leaq	448(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1108
.L1147:
	leaq	1648(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZN5boost6tuples5tupleIN3fem5pointEdNS0_9null_typeES4_S4_S4_S4_S4_S4_S4_ED1Ev
	jmp	.L1058
.L1219:
	leaq	2072(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3568(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L704
.L1218:
	leaq	2104(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3600(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L704
.L1217:
	leaq	2136(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3632(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L704
.L1216:
	leaq	2168(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	leaq	3664(%rsp), %rdi
	call	_ZNSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS1_9null_typeES5_S5_S5_S5_S5_S5_S5_EESaIS6_EED1Ev
	jmp	.L704
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
	.uleb128 .LEHB93-.LFB3594
	.uleb128 .LEHE93-.LEHB93
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB94-.LFB3594
	.uleb128 .LEHE94-.LEHB94
	.uleb128 .L1132-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB95-.LFB3594
	.uleb128 .LEHE95-.LEHB95
	.uleb128 .L1133-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB96-.LFB3594
	.uleb128 .LEHE96-.LEHB96
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB97-.LFB3594
	.uleb128 .LEHE97-.LEHB97
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB98-.LFB3594
	.uleb128 .LEHE98-.LEHB98
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB99-.LFB3594
	.uleb128 .LEHE99-.LEHB99
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB100-.LFB3594
	.uleb128 .LEHE100-.LEHB100
	.uleb128 .L1134-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB101-.LFB3594
	.uleb128 .LEHE101-.LEHB101
	.uleb128 .L1135-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB102-.LFB3594
	.uleb128 .LEHE102-.LEHB102
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB103-.LFB3594
	.uleb128 .LEHE103-.LEHB103
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB104-.LFB3594
	.uleb128 .LEHE104-.LEHB104
	.uleb128 .L1136-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB105-.LFB3594
	.uleb128 .LEHE105-.LEHB105
	.uleb128 .L1137-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB106-.LFB3594
	.uleb128 .LEHE106-.LEHB106
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB107-.LFB3594
	.uleb128 .LEHE107-.LEHB107
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB108-.LFB3594
	.uleb128 .LEHE108-.LEHB108
	.uleb128 .L1138-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB109-.LFB3594
	.uleb128 .LEHE109-.LEHB109
	.uleb128 .L1139-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB110-.LFB3594
	.uleb128 .LEHE110-.LEHB110
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB111-.LFB3594
	.uleb128 .LEHE111-.LEHB111
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB112-.LFB3594
	.uleb128 .LEHE112-.LEHB112
	.uleb128 .L1140-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB113-.LFB3594
	.uleb128 .LEHE113-.LEHB113
	.uleb128 .L1141-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB114-.LFB3594
	.uleb128 .LEHE114-.LEHB114
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB115-.LFB3594
	.uleb128 .LEHE115-.LEHB115
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB116-.LFB3594
	.uleb128 .LEHE116-.LEHB116
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB117-.LFB3594
	.uleb128 .LEHE117-.LEHB117
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB118-.LFB3594
	.uleb128 .LEHE118-.LEHB118
	.uleb128 .L1142-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB119-.LFB3594
	.uleb128 .LEHE119-.LEHB119
	.uleb128 .L1143-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB120-.LFB3594
	.uleb128 .LEHE120-.LEHB120
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB121-.LFB3594
	.uleb128 .LEHE121-.LEHB121
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB122-.LFB3594
	.uleb128 .LEHE122-.LEHB122
	.uleb128 .L1144-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB123-.LFB3594
	.uleb128 .LEHE123-.LEHB123
	.uleb128 .L1145-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB124-.LFB3594
	.uleb128 .LEHE124-.LEHB124
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB125-.LFB3594
	.uleb128 .LEHE125-.LEHB125
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB126-.LFB3594
	.uleb128 .LEHE126-.LEHB126
	.uleb128 .L1146-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB127-.LFB3594
	.uleb128 .LEHE127-.LEHB127
	.uleb128 .L1147-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB128-.LFB3594
	.uleb128 .LEHE128-.LEHB128
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB129-.LFB3594
	.uleb128 .LEHE129-.LEHB129
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB130-.LFB3594
	.uleb128 .LEHE130-.LEHB130
	.uleb128 .L1148-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB131-.LFB3594
	.uleb128 .LEHE131-.LEHB131
	.uleb128 .L1149-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB132-.LFB3594
	.uleb128 .LEHE132-.LEHB132
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB133-.LFB3594
	.uleb128 .LEHE133-.LEHB133
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB134-.LFB3594
	.uleb128 .LEHE134-.LEHB134
	.uleb128 .L1150-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB135-.LFB3594
	.uleb128 .LEHE135-.LEHB135
	.uleb128 .L1151-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB136-.LFB3594
	.uleb128 .LEHE136-.LEHB136
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB137-.LFB3594
	.uleb128 .LEHE137-.LEHB137
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB138-.LFB3594
	.uleb128 .LEHE138-.LEHB138
	.uleb128 .L1152-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB139-.LFB3594
	.uleb128 .LEHE139-.LEHB139
	.uleb128 .L1153-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB140-.LFB3594
	.uleb128 .LEHE140-.LEHB140
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB141-.LFB3594
	.uleb128 .LEHE141-.LEHB141
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB142-.LFB3594
	.uleb128 .LEHE142-.LEHB142
	.uleb128 .L1154-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB143-.LFB3594
	.uleb128 .LEHE143-.LEHB143
	.uleb128 .L1155-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB144-.LFB3594
	.uleb128 .LEHE144-.LEHB144
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB145-.LFB3594
	.uleb128 .LEHE145-.LEHB145
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB146-.LFB3594
	.uleb128 .LEHE146-.LEHB146
	.uleb128 .L1156-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB147-.LFB3594
	.uleb128 .LEHE147-.LEHB147
	.uleb128 .L1157-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB148-.LFB3594
	.uleb128 .LEHE148-.LEHB148
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB149-.LFB3594
	.uleb128 .LEHE149-.LEHB149
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB150-.LFB3594
	.uleb128 .LEHE150-.LEHB150
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB151-.LFB3594
	.uleb128 .LEHE151-.LEHB151
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB152-.LFB3594
	.uleb128 .LEHE152-.LEHB152
	.uleb128 .L1158-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB153-.LFB3594
	.uleb128 .LEHE153-.LEHB153
	.uleb128 .L1159-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB154-.LFB3594
	.uleb128 .LEHE154-.LEHB154
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB155-.LFB3594
	.uleb128 .LEHE155-.LEHB155
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB156-.LFB3594
	.uleb128 .LEHE156-.LEHB156
	.uleb128 .L1160-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB157-.LFB3594
	.uleb128 .LEHE157-.LEHB157
	.uleb128 .L1161-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB158-.LFB3594
	.uleb128 .LEHE158-.LEHB158
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB159-.LFB3594
	.uleb128 .LEHE159-.LEHB159
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB160-.LFB3594
	.uleb128 .LEHE160-.LEHB160
	.uleb128 .L1162-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB161-.LFB3594
	.uleb128 .LEHE161-.LEHB161
	.uleb128 .L1163-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB162-.LFB3594
	.uleb128 .LEHE162-.LEHB162
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB163-.LFB3594
	.uleb128 .LEHE163-.LEHB163
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB164-.LFB3594
	.uleb128 .LEHE164-.LEHB164
	.uleb128 .L1164-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB165-.LFB3594
	.uleb128 .LEHE165-.LEHB165
	.uleb128 .L1165-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB166-.LFB3594
	.uleb128 .LEHE166-.LEHB166
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB167-.LFB3594
	.uleb128 .LEHE167-.LEHB167
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB168-.LFB3594
	.uleb128 .LEHE168-.LEHB168
	.uleb128 .L1166-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB169-.LFB3594
	.uleb128 .LEHE169-.LEHB169
	.uleb128 .L1167-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB170-.LFB3594
	.uleb128 .LEHE170-.LEHB170
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB171-.LFB3594
	.uleb128 .LEHE171-.LEHB171
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB172-.LFB3594
	.uleb128 .LEHE172-.LEHB172
	.uleb128 .L1168-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB173-.LFB3594
	.uleb128 .LEHE173-.LEHB173
	.uleb128 .L1169-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB174-.LFB3594
	.uleb128 .LEHE174-.LEHB174
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB175-.LFB3594
	.uleb128 .LEHE175-.LEHB175
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB176-.LFB3594
	.uleb128 .LEHE176-.LEHB176
	.uleb128 .L1170-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB177-.LFB3594
	.uleb128 .LEHE177-.LEHB177
	.uleb128 .L1171-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB178-.LFB3594
	.uleb128 .LEHE178-.LEHB178
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB179-.LFB3594
	.uleb128 .LEHE179-.LEHB179
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB180-.LFB3594
	.uleb128 .LEHE180-.LEHB180
	.uleb128 .L1172-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB181-.LFB3594
	.uleb128 .LEHE181-.LEHB181
	.uleb128 .L1173-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB182-.LFB3594
	.uleb128 .LEHE182-.LEHB182
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB183-.LFB3594
	.uleb128 .LEHE183-.LEHB183
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB184-.LFB3594
	.uleb128 .LEHE184-.LEHB184
	.uleb128 .L1174-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB185-.LFB3594
	.uleb128 .LEHE185-.LEHB185
	.uleb128 .L1175-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB186-.LFB3594
	.uleb128 .LEHE186-.LEHB186
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB187-.LFB3594
	.uleb128 .LEHE187-.LEHB187
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB188-.LFB3594
	.uleb128 .LEHE188-.LEHB188
	.uleb128 .L1176-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB189-.LFB3594
	.uleb128 .LEHE189-.LEHB189
	.uleb128 .L1177-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB190-.LFB3594
	.uleb128 .LEHE190-.LEHB190
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB191-.LFB3594
	.uleb128 .LEHE191-.LEHB191
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB192-.LFB3594
	.uleb128 .LEHE192-.LEHB192
	.uleb128 .L1178-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB193-.LFB3594
	.uleb128 .LEHE193-.LEHB193
	.uleb128 .L1179-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB194-.LFB3594
	.uleb128 .LEHE194-.LEHB194
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB195-.LFB3594
	.uleb128 .LEHE195-.LEHB195
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB196-.LFB3594
	.uleb128 .LEHE196-.LEHB196
	.uleb128 .L1180-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB197-.LFB3594
	.uleb128 .LEHE197-.LEHB197
	.uleb128 .L1181-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB198-.LFB3594
	.uleb128 .LEHE198-.LEHB198
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB199-.LFB3594
	.uleb128 .LEHE199-.LEHB199
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB200-.LFB3594
	.uleb128 .LEHE200-.LEHB200
	.uleb128 .L1182-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB201-.LFB3594
	.uleb128 .LEHE201-.LEHB201
	.uleb128 .L1183-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB202-.LFB3594
	.uleb128 .LEHE202-.LEHB202
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB203-.LFB3594
	.uleb128 .LEHE203-.LEHB203
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB204-.LFB3594
	.uleb128 .LEHE204-.LEHB204
	.uleb128 .L1184-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB205-.LFB3594
	.uleb128 .LEHE205-.LEHB205
	.uleb128 .L1185-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB206-.LFB3594
	.uleb128 .LEHE206-.LEHB206
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB207-.LFB3594
	.uleb128 .LEHE207-.LEHB207
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB208-.LFB3594
	.uleb128 .LEHE208-.LEHB208
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB209-.LFB3594
	.uleb128 .LEHE209-.LEHB209
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB210-.LFB3594
	.uleb128 .LEHE210-.LEHB210
	.uleb128 .L1186-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB211-.LFB3594
	.uleb128 .LEHE211-.LEHB211
	.uleb128 .L1187-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB212-.LFB3594
	.uleb128 .LEHE212-.LEHB212
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB213-.LFB3594
	.uleb128 .LEHE213-.LEHB213
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB214-.LFB3594
	.uleb128 .LEHE214-.LEHB214
	.uleb128 .L1188-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB215-.LFB3594
	.uleb128 .LEHE215-.LEHB215
	.uleb128 .L1189-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB216-.LFB3594
	.uleb128 .LEHE216-.LEHB216
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB217-.LFB3594
	.uleb128 .LEHE217-.LEHB217
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB218-.LFB3594
	.uleb128 .LEHE218-.LEHB218
	.uleb128 .L1190-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB219-.LFB3594
	.uleb128 .LEHE219-.LEHB219
	.uleb128 .L1191-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB220-.LFB3594
	.uleb128 .LEHE220-.LEHB220
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB221-.LFB3594
	.uleb128 .LEHE221-.LEHB221
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB222-.LFB3594
	.uleb128 .LEHE222-.LEHB222
	.uleb128 .L1192-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB223-.LFB3594
	.uleb128 .LEHE223-.LEHB223
	.uleb128 .L1193-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB224-.LFB3594
	.uleb128 .LEHE224-.LEHB224
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB225-.LFB3594
	.uleb128 .LEHE225-.LEHB225
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB226-.LFB3594
	.uleb128 .LEHE226-.LEHB226
	.uleb128 .L1194-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB227-.LFB3594
	.uleb128 .LEHE227-.LEHB227
	.uleb128 .L1195-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB228-.LFB3594
	.uleb128 .LEHE228-.LEHB228
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB229-.LFB3594
	.uleb128 .LEHE229-.LEHB229
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB230-.LFB3594
	.uleb128 .LEHE230-.LEHB230
	.uleb128 .L1196-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB231-.LFB3594
	.uleb128 .LEHE231-.LEHB231
	.uleb128 .L1197-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB232-.LFB3594
	.uleb128 .LEHE232-.LEHB232
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB233-.LFB3594
	.uleb128 .LEHE233-.LEHB233
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB234-.LFB3594
	.uleb128 .LEHE234-.LEHB234
	.uleb128 .L1198-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB235-.LFB3594
	.uleb128 .LEHE235-.LEHB235
	.uleb128 .L1199-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB236-.LFB3594
	.uleb128 .LEHE236-.LEHB236
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB237-.LFB3594
	.uleb128 .LEHE237-.LEHB237
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB238-.LFB3594
	.uleb128 .LEHE238-.LEHB238
	.uleb128 .L1200-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB239-.LFB3594
	.uleb128 .LEHE239-.LEHB239
	.uleb128 .L1201-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB240-.LFB3594
	.uleb128 .LEHE240-.LEHB240
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB241-.LFB3594
	.uleb128 .LEHE241-.LEHB241
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB242-.LFB3594
	.uleb128 .LEHE242-.LEHB242
	.uleb128 .L1202-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB243-.LFB3594
	.uleb128 .LEHE243-.LEHB243
	.uleb128 .L1203-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB244-.LFB3594
	.uleb128 .LEHE244-.LEHB244
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB245-.LFB3594
	.uleb128 .LEHE245-.LEHB245
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB246-.LFB3594
	.uleb128 .LEHE246-.LEHB246
	.uleb128 .L1204-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB247-.LFB3594
	.uleb128 .LEHE247-.LEHB247
	.uleb128 .L1205-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB248-.LFB3594
	.uleb128 .LEHE248-.LEHB248
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB249-.LFB3594
	.uleb128 .LEHE249-.LEHB249
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB250-.LFB3594
	.uleb128 .LEHE250-.LEHB250
	.uleb128 .L1206-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB251-.LFB3594
	.uleb128 .LEHE251-.LEHB251
	.uleb128 .L1207-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB252-.LFB3594
	.uleb128 .LEHE252-.LEHB252
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB253-.LFB3594
	.uleb128 .LEHE253-.LEHB253
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB254-.LFB3594
	.uleb128 .LEHE254-.LEHB254
	.uleb128 .L1208-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB255-.LFB3594
	.uleb128 .LEHE255-.LEHB255
	.uleb128 .L1209-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB256-.LFB3594
	.uleb128 .LEHE256-.LEHB256
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB257-.LFB3594
	.uleb128 .LEHE257-.LEHB257
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB258-.LFB3594
	.uleb128 .LEHE258-.LEHB258
	.uleb128 .L1210-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB259-.LFB3594
	.uleb128 .LEHE259-.LEHB259
	.uleb128 .L1211-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB260-.LFB3594
	.uleb128 .LEHE260-.LEHB260
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB261-.LFB3594
	.uleb128 .LEHE261-.LEHB261
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB262-.LFB3594
	.uleb128 .LEHE262-.LEHB262
	.uleb128 .L1212-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB263-.LFB3594
	.uleb128 .LEHE263-.LEHB263
	.uleb128 .L1213-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB264-.LFB3594
	.uleb128 .LEHE264-.LEHB264
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB265-.LFB3594
	.uleb128 .LEHE265-.LEHB265
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB266-.LFB3594
	.uleb128 .LEHE266-.LEHB266
	.uleb128 .L1214-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB267-.LFB3594
	.uleb128 .LEHE267-.LEHB267
	.uleb128 .L1215-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB268-.LFB3594
	.uleb128 .LEHE268-.LEHB268
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB269-.LFB3594
	.uleb128 .LEHE269-.LEHB269
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB270-.LFB3594
	.uleb128 .LEHE270-.LEHB270
	.uleb128 .L1220-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB271-.LFB3594
	.uleb128 .LEHE271-.LEHB271
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB272-.LFB3594
	.uleb128 .LEHE272-.LEHB272
	.uleb128 .L1131-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB273-.LFB3594
	.uleb128 .LEHE273-.LEHB273
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB274-.LFB3594
	.uleb128 .LEHE274-.LEHB274
	.uleb128 .L1135-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB275-.LFB3594
	.uleb128 .LEHE275-.LEHB275
	.uleb128 .L1133-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB276-.LFB3594
	.uleb128 .LEHE276-.LEHB276
	.uleb128 .L1141-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB277-.LFB3594
	.uleb128 .LEHE277-.LEHB277
	.uleb128 .L1139-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB278-.LFB3594
	.uleb128 .LEHE278-.LEHB278
	.uleb128 .L1137-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB279-.LFB3594
	.uleb128 .LEHE279-.LEHB279
	.uleb128 .L1143-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB280-.LFB3594
	.uleb128 .LEHE280-.LEHB280
	.uleb128 .L1145-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB281-.LFB3594
	.uleb128 .LEHE281-.LEHB281
	.uleb128 .L1151-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB282-.LFB3594
	.uleb128 .LEHE282-.LEHB282
	.uleb128 .L1149-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB283-.LFB3594
	.uleb128 .LEHE283-.LEHB283
	.uleb128 .L1147-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB284-.LFB3594
	.uleb128 .LEHE284-.LEHB284
	.uleb128 .L1215-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB285-.LFB3594
	.uleb128 .LEHE285-.LEHB285
	.uleb128 .L1157-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB286-.LFB3594
	.uleb128 .LEHE286-.LEHB286
	.uleb128 .L1161-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB287-.LFB3594
	.uleb128 .LEHE287-.LEHB287
	.uleb128 .L1159-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB288-.LFB3594
	.uleb128 .LEHE288-.LEHB288
	.uleb128 .L1155-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB289-.LFB3594
	.uleb128 .LEHE289-.LEHB289
	.uleb128 .L1153-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB290-.LFB3594
	.uleb128 .LEHE290-.LEHB290
	.uleb128 .L1171-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB291-.LFB3594
	.uleb128 .LEHE291-.LEHB291
	.uleb128 .L1169-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB292-.LFB3594
	.uleb128 .LEHE292-.LEHB292
	.uleb128 .L1167-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB293-.LFB3594
	.uleb128 .LEHE293-.LEHB293
	.uleb128 .L1165-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB294-.LFB3594
	.uleb128 .LEHE294-.LEHB294
	.uleb128 .L1163-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB295-.LFB3594
	.uleb128 .LEHE295-.LEHB295
	.uleb128 .L1187-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB296-.LFB3594
	.uleb128 .LEHE296-.LEHB296
	.uleb128 .L1185-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB297-.LFB3594
	.uleb128 .LEHE297-.LEHB297
	.uleb128 .L1183-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB298-.LFB3594
	.uleb128 .LEHE298-.LEHB298
	.uleb128 .L1191-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB299-.LFB3594
	.uleb128 .LEHE299-.LEHB299
	.uleb128 .L1189-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB300-.LFB3594
	.uleb128 .LEHE300-.LEHB300
	.uleb128 .L1181-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB301-.LFB3594
	.uleb128 .LEHE301-.LEHB301
	.uleb128 .L1179-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB302-.LFB3594
	.uleb128 .LEHE302-.LEHB302
	.uleb128 .L1177-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB303-.LFB3594
	.uleb128 .LEHE303-.LEHB303
	.uleb128 .L1175-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB304-.LFB3594
	.uleb128 .LEHE304-.LEHB304
	.uleb128 .L1173-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB305-.LFB3594
	.uleb128 .LEHE305-.LEHB305
	.uleb128 .L1213-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB306-.LFB3594
	.uleb128 .LEHE306-.LEHB306
	.uleb128 .L1211-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB307-.LFB3594
	.uleb128 .LEHE307-.LEHB307
	.uleb128 .L1209-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB308-.LFB3594
	.uleb128 .LEHE308-.LEHB308
	.uleb128 .L1207-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB309-.LFB3594
	.uleb128 .LEHE309-.LEHB309
	.uleb128 .L1205-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB310-.LFB3594
	.uleb128 .LEHE310-.LEHB310
	.uleb128 .L1203-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB311-.LFB3594
	.uleb128 .LEHE311-.LEHB311
	.uleb128 .L1201-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB312-.LFB3594
	.uleb128 .LEHE312-.LEHB312
	.uleb128 .L1199-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB313-.LFB3594
	.uleb128 .LEHE313-.LEHB313
	.uleb128 .L1197-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB314-.LFB3594
	.uleb128 .LEHE314-.LEHB314
	.uleb128 .L1195-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB315-.LFB3594
	.uleb128 .LEHE315-.LEHB315
	.uleb128 .L1193-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB316-.LFB3594
	.uleb128 .LEHE316-.LEHB316
	.uleb128 .L1216-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB317-.LFB3594
	.uleb128 .LEHE317-.LEHB317
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB318-.LFB3594
	.uleb128 .LEHE318-.LEHB318
	.uleb128 .L1217-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB319-.LFB3594
	.uleb128 .LEHE319-.LEHB319
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB320-.LFB3594
	.uleb128 .LEHE320-.LEHB320
	.uleb128 .L1218-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB321-.LFB3594
	.uleb128 .LEHE321-.LEHB321
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB322-.LFB3594
	.uleb128 .LEHE322-.LEHB322
	.uleb128 .L1219-.LFB3594
	.uleb128 0x0
	.uleb128 .LEHB323-.LFB3594
	.uleb128 .LEHE323-.LEHB323
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3594:
	.align 4
	.long	0

.LLSDATT3594:
	.section	.text._ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,"axG",@progbits,_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv,comdat
	.section	.text._ZN3fem13Tetrahedron10IdEC2Ev,"axG",@progbits,_ZN3fem13Tetrahedron10IdEC5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdEC2Ev
	.type	_ZN3fem13Tetrahedron10IdEC2Ev, @function
_ZN3fem13Tetrahedron10IdEC2Ev:
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
.LEHB324:
	call	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
.LEHE324:
	movq	$_ZTVN3fem13Tetrahedron10IdEE+16, (%rbx)
	movl	$11, 216(%rbx)
	movq	%rsp, %rdi
	movl	$2, 8(%rbx)
	movl	$2, 12(%rbx)
.LEHB325:
	call	_ZN3fem5pointC1Ev
.LEHE325:
	movq	72(%rbx), %r12
	movq	64(%rbx), %r13
	movq	%r12, %rax
	subq	%r13, %rax
	sarq	$5, %rax
	cmpq	$10, %rax
	jbe	.L1271
	addq	$320, %r13
	cmpq	%r13, %r12
	je	.L1272
	movq	%r13, %rbp
	.p2align 4,,10
	.p2align 3
.L1273:
	movq	0(%rbp), %rax
	movq	%rbp, %rdi
.LEHB326:
	call	*(%rax)
.LEHE326:
	addq	$32, %rbp
	cmpq	%rbp, %r12
	jne	.L1273
.L1272:
	movq	%r13, 72(%rbx)
.L1274:
	movq	%rsp, %rdi
.LEHB327:
	call	_ZN3fem5pointD1Ev
	movq	96(%rbx), %rsi
	movq	88(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$10, %rax
	jbe	.L1275
	addq	$80, %rdx
	movq	%rdx, 96(%rbx)
.L1276:
	movq	120(%rbx), %rsi
	movq	112(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$10, %rax
	jbe	.L1277
	addq	$80, %rdx
	movq	%rdx, 120(%rbx)
.L1278:
	movq	144(%rbx), %rsi
	movq	136(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$10, %rax
	jbe	.L1279
	addq	$80, %rdx
	movq	%rdx, 144(%rbx)
.L1280:
	movq	168(%rbx), %rsi
	movq	160(%rbx), %rdx
	movq	$0, 32(%rsp)
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	cmpq	$10, %rax
	jbe	.L1281
	addq	$80, %rdx
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
.L1275:
	.cfi_restore_state
	movl	$10, %edx
	leaq	88(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	jmp	.L1276
	.p2align 4,,10
	.p2align 3
.L1281:
	movl	$10, %edx
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
.L1279:
	.cfi_restore_state
	movl	$10, %edx
	leaq	136(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
	jmp	.L1280
	.p2align 4,,10
	.p2align 3
.L1277:
	movl	$10, %edx
	leaq	112(%rbx), %rdi
	leaq	32(%rsp), %rcx
	subq	%rax, %rdx
	call	_ZNSt6vectorIdSaIdEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPdS1_EEmRKd
.LEHE327:
	jmp	.L1278
	.p2align 4,,10
	.p2align 3
.L1271:
	movl	$10, %edx
	leaq	64(%rbx), %rdi
	movq	%rsp, %rcx
	subq	%rax, %rdx
	movq	%r12, %rsi
.LEHB328:
	call	_ZNSt6vectorIN3fem5pointESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_
.LEHE328:
	jmp	.L1274
.L1286:
	movq	%rax, %rbp
.L1284:
	movq	%rbx, %rdi
	movq	$_ZTVN3fem17TetrahedronFamilyIdEE+16, (%rbx)
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB329:
	call	_Unwind_Resume
.LEHE329:
.L1287:
	movq	%rsp, %rdi
	movq	%rax, %rbp
	call	_ZN3fem5pointD1Ev
	jmp	.L1284
.L1288:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZN3fem11BaseElementIdED2Ev
	movq	%rbp, %rdi
.LEHB330:
	call	_Unwind_Resume
.LEHE330:
	.cfi_endproc
.LFE3535:
	.size	_ZN3fem13Tetrahedron10IdEC2Ev, .-_ZN3fem13Tetrahedron10IdEC2Ev
	.section	.gcc_except_table
.LLSDA3535:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3535-.LLSDACSB3535
.LLSDACSB3535:
	.uleb128 .LEHB324-.LFB3535
	.uleb128 .LEHE324-.LEHB324
	.uleb128 .L1288-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB325-.LFB3535
	.uleb128 .LEHE325-.LEHB325
	.uleb128 .L1286-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB326-.LFB3535
	.uleb128 .LEHE326-.LEHB326
	.uleb128 .L1287-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB327-.LFB3535
	.uleb128 .LEHE327-.LEHB327
	.uleb128 .L1286-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB328-.LFB3535
	.uleb128 .LEHE328-.LEHB328
	.uleb128 .L1287-.LFB3535
	.uleb128 0x0
	.uleb128 .LEHB329-.LFB3535
	.uleb128 .LEHE329-.LEHB329
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB330-.LFB3535
	.uleb128 .LEHE330-.LEHB330
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE3535:
	.section	.text._ZN3fem13Tetrahedron10IdEC2Ev,"axG",@progbits,_ZN3fem13Tetrahedron10IdEC5Ev,comdat
	.weak	_ZN3fem13Tetrahedron10IdEC1Ev
	.set	_ZN3fem13Tetrahedron10IdEC1Ev,_ZN3fem13Tetrahedron10IdEC2Ev
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
.LEHB331:
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	call	_ZN3fem13Tetrahedron10IdEC1Ev
.LEHE331:
	leaq	224(%rsp), %rdi
.LEHB332:
	call	_ZN3fem5pointC1Ev
	leaq	248(%rsp), %rcx
	leaq	240(%rsp), %rdx
	leaq	232(%rsp), %rsi
	movq	%rsp, %rdi
	call	_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_
	leaq	224(%rsp), %rdi
	call	_ZN3fem5pointD1Ev
.LEHE332:
	movq	192(%rsp), %rdi
	movq	$_ZTVN3fem11BaseElementIdEE+16, (%rsp)
	testq	%rdi, %rdi
	je	.L1296
	call	_ZdlPv
.L1296:
	movq	160(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1301
	call	_ZdlPv
.L1301:
	movq	136(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1306
	call	_ZdlPv
.L1306:
	movq	112(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1311
	call	_ZdlPv
.L1311:
	movq	88(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1316
	call	_ZdlPv
.L1316:
	movq	72(%rsp), %rbp
	movq	64(%rsp), %rbx
	cmpq	%rbx, %rbp
	je	.L1317
	.p2align 4,,10
	.p2align 3
.L1341:
	movq	(%rbx), %rax
	movq	%rbx, %rdi
.LEHB333:
	call	*(%rax)
.LEHE333:
	addq	$32, %rbx
	cmpq	%rbx, %rbp
	jne	.L1341
	movq	64(%rsp), %rbx
.L1317:
	testq	%rbx, %rbx
	je	.L1329
	movq	%rbx, %rdi
	call	_ZdlPv
.L1329:
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
.L1339:
	.cfi_restore_state
	movq	%rax, %rbx
	movq	%rsp, %rdi
	call	_ZN3fem13Tetrahedron10IdED1Ev
	movq	%rbx, %rdi
.LEHB334:
	call	_Unwind_Resume
.L1340:
	movq	64(%rsp), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L1324
	call	_ZdlPv
.L1324:
	leaq	16(%rsp), %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorIN5boost6tuples5tupleIN3fem5pointEdNS4_9null_typeES8_S8_S8_S8_S8_S8_S8_EESaIS9_EEESt10_Select1stISC_ESt4lessIiESaISC_EED1Ev
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE334:
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
	.uleb128 .LEHB331-.LFB3494
	.uleb128 .LEHE331-.LEHB331
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB332-.LFB3494
	.uleb128 .LEHE332-.LEHB332
	.uleb128 .L1339-.LFB3494
	.uleb128 0x0
	.uleb128 .LEHB333-.LFB3494
	.uleb128 .LEHE333-.LEHB333
	.uleb128 .L1340-.LFB3494
	.uleb128 0x0
	.uleb128 .LEHB334-.LFB3494
	.uleb128 .LEHE334-.LEHB334
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
	je	.L1344
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
	jbe	.L1345
	testq	%rbp, %rbp
	je	.L1355
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbp
	ja	.L1360
	leaq	0(,%rbp,8), %r13
	movq	%r13, %rdi
	call	_Znwm
	testq	%rbp, %rbp
	movq	%rax, %r12
	jne	.L1361
.L1358:
	movq	(%rbx), %rdi
.L1348:
	testq	%rdi, %rdi
	je	.L1349
	call	_ZdlPv
.L1349:
	movq	%r12, (%rbx)
	addq	%r13, %r12
	movq	%r12, 16(%rbx)
.L1350:
	movq	%r12, 8(%rbx)
.L1344:
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
.L1345:
	.cfi_restore_state
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%rax, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %rbp
	ja	.L1351
	testq	%rbp, %rbp
	jne	.L1362
.L1359:
	leaq	0(,%rbp,8), %r12
	addq	(%rbx), %r12
	jmp	.L1350
	.p2align 4,,10
	.p2align 3
.L1351:
	testq	%rdx, %rdx
	leaq	(%r14,%rdx,8), %rsi
	jne	.L1363
.L1353:
	subq	%rsi, %rcx
	leaq	(%rax,%rbp,8), %r12
	sarq	$3, %rcx
	testq	%rcx, %rcx
	je	.L1350
	leaq	0(,%rcx,8), %rdx
	call	memmove
	jmp	.L1359
	.p2align 4,,10
	.p2align 3
.L1361:
	movq	%r13, %rdx
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	memmove
	jmp	.L1358
	.p2align 4,,10
	.p2align 3
.L1362:
	leaq	0(,%rbp,8), %rdx
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	memmove
	jmp	.L1359
	.p2align 4,,10
	.p2align 3
.L1363:
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
	jmp	.L1353
	.p2align 4,,10
	.p2align 3
.L1355:
	xorl	%r13d, %r13d
	xorl	%r12d, %r12d
	jmp	.L1348
.L1360:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE4046:
	.size	_ZNSt6vectorImSaImEEaSERKS1_, .-_ZNSt6vectorImSaImEEaSERKS1_
	.section	.rodata.str1.1
.LC34:
	.string	"Tetrahedron10.h++"
.LC35:
	.string	"nodes.size() == 10"
	.section	.text._ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE,"axG",@progbits,_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE
	.type	_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE, @function
_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE:
.LFB4042:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rsi), %rax
	subq	(%rsi), %rax
	sarq	$3, %rax
	cmpq	$10, %rax
	jne	.L1366
	addq	$192, %rdi
	call	_ZNSt6vectorImSaImEEaSERKS1_
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L1366:
	.cfi_restore_state
	movl	$_ZZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, %ecx
	movl	$194, %edx
	movl	$.LC34, %esi
	movl	$.LC35, %edi
	call	__assert_fail
	.cfi_endproc
.LFE4042:
	.size	_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE, .-_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE
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
	.weak	_ZTVN3fem13Tetrahedron10IdEE
	.section	.rodata._ZTVN3fem13Tetrahedron10IdEE,"aG",@progbits,_ZTVN3fem13Tetrahedron10IdEE,comdat
	.align 32
	.type	_ZTVN3fem13Tetrahedron10IdEE, @object
	.size	_ZTVN3fem13Tetrahedron10IdEE, 112
_ZTVN3fem13Tetrahedron10IdEE:
	.quad	0
	.quad	_ZTIN3fem13Tetrahedron10IdEE
	.quad	_ZN3fem13Tetrahedron10IdE14setCoordinatesEv
	.quad	_ZN3fem13Tetrahedron10IdE4setNERKNS_5pointE
	.quad	_ZN3fem13Tetrahedron10IdE4setNERKdS3_S3_
	.quad	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKNS_5pointE
	.quad	_ZN3fem13Tetrahedron10IdE9setdNdcsiERKdS3_S3_
	.quad	_ZN3fem13Tetrahedron10IdE9setdNdetaERKNS_5pointE
	.quad	_ZN3fem13Tetrahedron10IdE9setdNdetaERKdS3_S3_
	.quad	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKNS_5pointE
	.quad	_ZN3fem13Tetrahedron10IdE10setdNdzetaERKdS3_S3_
	.quad	_ZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEE
	.quad	_ZNK3fem13Tetrahedron10IdE11node_numberEv
	.quad	_ZN3fem17TetrahedronFamilyIdE22generateQuadratureDataEv
	.section	.rodata
	.align 32
	.type	_ZZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, @object
	.size	_ZZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__, 185
_ZZN3fem13Tetrahedron10IdE3setERSt6vectorImSaImEEE19__PRETTY_FUNCTION__:
	.string	"typename fem::BaseElement<T>::Error fem::Tetrahedron10<T>::set(std::vector<long unsigned int>&) [with T = double, typename fem::BaseElement<T>::Error = fem::BaseElement<double>::Error]"
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
	.weak	_ZTIN3fem13Tetrahedron10IdEE
	.section	.rodata._ZTIN3fem13Tetrahedron10IdEE,"aG",@progbits,_ZTIN3fem13Tetrahedron10IdEE,comdat
	.align 16
	.type	_ZTIN3fem13Tetrahedron10IdEE, @object
	.size	_ZTIN3fem13Tetrahedron10IdEE, 24
_ZTIN3fem13Tetrahedron10IdEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3fem13Tetrahedron10IdEE
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
	.weak	_ZTSN3fem13Tetrahedron10IdEE
	.section	.rodata._ZTSN3fem13Tetrahedron10IdEE,"aG",@progbits,_ZTSN3fem13Tetrahedron10IdEE,comdat
	.align 16
	.type	_ZTSN3fem13Tetrahedron10IdEE, @object
	.size	_ZTSN3fem13Tetrahedron10IdEE, 25
_ZTSN3fem13Tetrahedron10IdEE:
	.string	"N3fem13Tetrahedron10IdEE"
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
	.long	1071644672
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC3:
	.long	0
	.long	1074790400
	.align 8
.LC4:
	.long	0
	.long	-1073741824
	.align 8
.LC6:
	.long	0
	.long	-1072693248
	.align 8
.LC17:
	.long	0
	.long	1074266112
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
