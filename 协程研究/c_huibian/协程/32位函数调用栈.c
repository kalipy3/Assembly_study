#include <stdio.h>
#include <stdlib.h>

int i, j, k = 0;
unsigned char *stack_buffer;
unsigned int *p;

void nop(void)
{
    printf("nop!!!\n");
}

void foo(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int main_b = 0x66666666;
    unsigned int main_c = 0x77777777;
	stack_buffer = (unsigned char *)&main_b;
    stack_buffer -= 32;

	printf("----begin stack----\n");
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 4; j++) {
			printf(" %.2x", stack_buffer[k]);
			k++;
		}
		printf("\n");
	}
	printf("----end stack----\n");


    //替换返回地址，使得exec返回的时候，跳转到我们的代码。
	p = (void*)((int)&main_b + 20);
    printf("return addr:%p\n", *p);
	*p = (unsigned int)nop;

}

int main(void)
{
    unsigned int main_a = 0x11223344;
    foo(0x22222222, 0x33333333, 0x44444444, 0x55555555);
}
