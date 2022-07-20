
int g(int x)
{
    return x + 3;
}

int f(int x)
{
    return g(x);
}

int main(void)
{

    return f(8) + 1;
}

g:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$3, %eax
	popl	%ebp
	ret
f:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	8(%ebp)
	call	g
	addl	$4, %esp
	leave
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	$8
	call	f
	addl	$4, %esp
	addl	$1, %eax
	leave
	ret
 
 /*
 说明1：
    enter
        pushl %ebp
        movl %esp, %ebp

    leave
        movl %ebp, %esp
        popl %ebp

 说明2:
    函数的返回值默认使用eax寄存器存储
 */
