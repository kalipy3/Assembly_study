int g(int x)
{
    int a = 0x33333333;
    return x + 3;
}

int f(int x)
{
    int a = 0x22222222;
    return g(x);
}

int main(void)
{

    return f(8) + 1;
}
/*
 * 32位机器
g:
	pushl	%ebp//因为esp是32位的，所以pushl的esp指针step为：esp = esp - 4；16为机器则是esp = esp - 2; 64位则是esp = esp - 8;
	movl	%esp, %ebp
	subl	$16, %esp;立即数16给esp寄存器
	movl	$33333333, -4(%ebp);-4表示ebp寄存器的内容减4个字节
	movl	8(%ebp), %eax//ebp寄存器的内容加8个字节处的内容给eax寄存器
	addl	$3, %eax
	leave;等价为：1.movl %ebp, %esp; 2.popl %ebp
	ret;等价于：popl %eip
f:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$22222222, -4(%ebp)
	pushl	8(%ebp)
	call	g;等价于：1. pushl %eip; 2. movl $(&g), %eip;
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
    */
