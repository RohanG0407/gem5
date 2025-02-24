
hello-dynamic:     file format elf64-littleaarch64


Disassembly of section .init:

00000000000005c0 <_init>:
 5c0:	d503201f 	nop
 5c4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 5c8:	910003fd 	mov	x29, sp
 5cc:	9400003a 	bl	6b4 <call_weak_fn>
 5d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 5d4:	d65f03c0 	ret

Disassembly of section .plt:

00000000000005e0 <.plt>:
 5e0:	a9bf7bf0 	stp	x16, x30, [sp, #-16]!
 5e4:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 5e8:	f947d211 	ldr	x17, [x16, #4000]
 5ec:	913e8210 	add	x16, x16, #0xfa0
 5f0:	d61f0220 	br	x17
 5f4:	d503201f 	nop
 5f8:	d503201f 	nop
 5fc:	d503201f 	nop

0000000000000600 <__libc_start_main@plt>:
 600:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 604:	f947d611 	ldr	x17, [x16, #4008]
 608:	913ea210 	add	x16, x16, #0xfa8
 60c:	d61f0220 	br	x17

0000000000000610 <__cxa_finalize@plt>:
 610:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 614:	f947da11 	ldr	x17, [x16, #4016]
 618:	913ec210 	add	x16, x16, #0xfb0
 61c:	d61f0220 	br	x17

0000000000000620 <__printf_chk@plt>:
 620:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 624:	f947de11 	ldr	x17, [x16, #4024]
 628:	913ee210 	add	x16, x16, #0xfb8
 62c:	d61f0220 	br	x17

0000000000000630 <__gmon_start__@plt>:
 630:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 634:	f947e211 	ldr	x17, [x16, #4032]
 638:	913f0210 	add	x16, x16, #0xfc0
 63c:	d61f0220 	br	x17

0000000000000640 <abort@plt>:
 640:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf6e0>
 644:	f947e611 	ldr	x17, [x16, #4040]
 648:	913f2210 	add	x16, x16, #0xfc8
 64c:	d61f0220 	br	x17

Disassembly of section .text:

0000000000000680 <_start>:
 680:	d503201f 	nop
 684:	d280001d 	mov	x29, #0x0                   	// #0
 688:	d280001e 	mov	x30, #0x0                   	// #0
 68c:	aa0003e5 	mov	x5, x0
 690:	f94003e1 	ldr	x1, [sp]
 694:	910023e2 	add	x2, sp, #0x8
 698:	910003e6 	mov	x6, sp
 69c:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf6e0>
 6a0:	f947f800 	ldr	x0, [x0, #4080]
 6a4:	d2800003 	mov	x3, #0x0                   	// #0
 6a8:	d2800004 	mov	x4, #0x0                   	// #0
 6ac:	97ffffd5 	bl	600 <__libc_start_main@plt>
 6b0:	97ffffe4 	bl	640 <abort@plt>

00000000000006b4 <call_weak_fn>:
 6b4:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf6e0>
 6b8:	f947f400 	ldr	x0, [x0, #4072]
 6bc:	b4000040 	cbz	x0, 6c4 <call_weak_fn+0x10>
 6c0:	17ffffdc 	b	630 <__gmon_start__@plt>
 6c4:	d65f03c0 	ret
 6c8:	d503201f 	nop
 6cc:	d503201f 	nop

00000000000006d0 <deregister_tm_clones>:
 6d0:	b0000080 	adrp	x0, 11000 <__data_start>
 6d4:	91004000 	add	x0, x0, #0x10
 6d8:	b0000081 	adrp	x1, 11000 <__data_start>
 6dc:	91004021 	add	x1, x1, #0x10
 6e0:	eb00003f 	cmp	x1, x0
 6e4:	540000c0 	b.eq	6fc <deregister_tm_clones+0x2c>  // b.none
 6e8:	90000081 	adrp	x1, 10000 <__FRAME_END__+0xf6e0>
 6ec:	f947ec21 	ldr	x1, [x1, #4056]
 6f0:	b4000061 	cbz	x1, 6fc <deregister_tm_clones+0x2c>
 6f4:	aa0103f0 	mov	x16, x1
 6f8:	d61f0200 	br	x16
 6fc:	d65f03c0 	ret

0000000000000700 <register_tm_clones>:
 700:	b0000080 	adrp	x0, 11000 <__data_start>
 704:	91004000 	add	x0, x0, #0x10
 708:	b0000081 	adrp	x1, 11000 <__data_start>
 70c:	91004021 	add	x1, x1, #0x10
 710:	cb000021 	sub	x1, x1, x0
 714:	d37ffc22 	lsr	x2, x1, #63
 718:	8b810c41 	add	x1, x2, x1, asr #3
 71c:	9341fc21 	asr	x1, x1, #1
 720:	b40000c1 	cbz	x1, 738 <register_tm_clones+0x38>
 724:	90000082 	adrp	x2, 10000 <__FRAME_END__+0xf6e0>
 728:	f947fc42 	ldr	x2, [x2, #4088]
 72c:	b4000062 	cbz	x2, 738 <register_tm_clones+0x38>
 730:	aa0203f0 	mov	x16, x2
 734:	d61f0200 	br	x16
 738:	d65f03c0 	ret
 73c:	d503201f 	nop

0000000000000740 <__do_global_dtors_aux>:
 740:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
 744:	910003fd 	mov	x29, sp
 748:	f9000bf3 	str	x19, [sp, #16]
 74c:	b0000093 	adrp	x19, 11000 <__data_start>
 750:	39404260 	ldrb	w0, [x19, #16]
 754:	35000140 	cbnz	w0, 77c <__do_global_dtors_aux+0x3c>
 758:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf6e0>
 75c:	f947f000 	ldr	x0, [x0, #4064]
 760:	b4000080 	cbz	x0, 770 <__do_global_dtors_aux+0x30>
 764:	b0000080 	adrp	x0, 11000 <__data_start>
 768:	f9400400 	ldr	x0, [x0, #8]
 76c:	97ffffa9 	bl	610 <__cxa_finalize@plt>
 770:	97ffffd8 	bl	6d0 <deregister_tm_clones>
 774:	52800020 	mov	w0, #0x1                   	// #1
 778:	39004260 	strb	w0, [x19, #16]
 77c:	f9400bf3 	ldr	x19, [sp, #16]
 780:	a8c27bfd 	ldp	x29, x30, [sp], #32
 784:	d65f03c0 	ret
 788:	d503201f 	nop
 78c:	d503201f 	nop

0000000000000790 <frame_dummy>:
 790:	17ffffdc 	b	700 <register_tm_clones>

0000000000000794 <main>:
 794:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 798:	910003fd 	mov	x29, sp
 79c:	d5033fdf 	isb
 7a0:	d503415f 	msr	dit, #0x1
 7a4:	d503405f 	msr	dit, #0x0
 7a8:	d503415f 	msr	dit, #0x1
 7ac:	d503405f 	msr	dit, #0x0
 7b0:	d2800402 	mov	x2, #0x20                  	// #32
 7b4:	90000001 	adrp	x1, 0 <__abi_tag-0x278>
 7b8:	91200021 	add	x1, x1, #0x800
 7bc:	52800020 	mov	w0, #0x1                   	// #1
 7c0:	97ffff98 	bl	620 <__printf_chk@plt>
 7c4:	d2900002 	mov	x2, #0x8000                	// #32768
 7c8:	90000001 	adrp	x1, 0 <__abi_tag-0x278>
 7cc:	91208021 	add	x1, x1, #0x820
 7d0:	52800020 	mov	w0, #0x1                   	// #1
 7d4:	97ffff93 	bl	620 <__printf_chk@plt>
 7d8:	52800000 	mov	w0, #0x0                   	// #0
 7dc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7e0:	d65f03c0 	ret

Disassembly of section .fini:

00000000000007e4 <_fini>:
 7e4:	d503201f 	nop
 7e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 7ec:	910003fd 	mov	x29, sp
 7f0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 7f4:	d65f03c0 	ret
