#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

unsigned char *code;

void nop(void)
{
    printf("nop!!!\n");
}

void exec()
{
	unsigned long a, *p;
	// 替换返回地址，使得exec返回的时候，跳转到我们的代码。
	p = (void*)((long)&a + 24);
	*p = (unsigned long)code;
}

int main(int argc, char **argv)
{
    code = &nop;
	exec();
	printf("end\n");
}
