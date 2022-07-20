int g(int x)
{
    int a = 33333333;
    return x + 3;
}

int f(int x, int y, int z, int k, int t)
{
    int a = 22222222;
    return g(x);
}

int main(void)
{
    int a = 44444444;
    int b = 55555555;
    int c = 66666666;
    int d = 77777777;

    return f(8, 7, 6, 5, 4) + 1;
}

//请对比32位和64位机器函数参数传递区别，32位是通过push压栈，64位是通过寄存器(寄存器不够，再通过push)

/*64位机器
g:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -20(%rbp)
	movl	$33333333, -4(%rbp)
	movl	-20(%rbp), %eax
	addl	$3, %eax
	popq	%rbp
	ret
f:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$40, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	$22222222, -4(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	g
	leave
	ret
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$44444444, -4(%rbp)
	movl	$55555555, -8(%rbp)
	movl	$66666666, -12(%rbp)
	movl	$77777777, -16(%rbp)
	movl	$4, %r8d
	movl	$5, %ecx
	movl	$6, %edx
	movl	$7, %esi
	movl	$8, %edi
	call	f
	addl	$1, %eax
	leave
	ret
*/

/*32位机器
g:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$33333333, -4(%ebp)
	movl	8(%ebp), %eax
	addl	$3, %eax
	leave
	ret
f:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$22222222, -4(%ebp)
	pushl	8(%ebp)
	call	g
	addl	$4, %esp
	leave
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$44444444, -4(%ebp)
	movl	$55555555, -8(%ebp)
	movl	$66666666, -12(%ebp)
	movl	$77777777, -16(%ebp)
	pushl	$4
	pushl	$5
	pushl	$6
	pushl	$7
	pushl	$8
	call	f
	addl	$20, %esp
	addl	$1, %eax
	leave
	ret
*/

