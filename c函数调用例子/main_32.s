	.text
swap:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$16, -4(%ebp)
	movl	$32, -8(%ebp)
	leal	-8(%ebp), %eax
	pushl	%eax
	leal	-4(%ebp), %eax
	pushl	%eax
	call	swap
	addl	$8, %esp
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	leave
	ret
__x86.get_pc_thunk.ax:
	movl	(%esp), %eax
	ret
