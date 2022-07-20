#include <stdio.h>
#include <stdlib.h>

int i, j, k = 0;
unsigned char *stack_buffer;
unsigned long *p;

void nop(){
    printf("nop!!!!\n");
}

void foo(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    unsigned long main_b = 0x5555555555555555;
    unsigned long main_c = 0x6666666666666666;
	p = (unsigned char *)&main_b;
	stack_buffer = (unsigned char *)&main_b;
    stack_buffer -= 32;

	printf("----begin stack----\n");
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 8; j++) {
			printf(" %.2x", stack_buffer[k]);
			k++;
		}
		printf("\n");
	}
	printf("----end stack----\n");

    // 替换返回地址，使得exec返回的时候，跳转到我们的代码。
	p = (void*)((long)&main_b + 24);//((long)&main_b) + 24;
    //请单独测试&a+1和(int)&a + 1区别：
    //int a = 1;
    //printf("&a1:%p\n", &a);
    //printf("&a2:%p\n", (&a + 1));
    //printf("&a3:%p\n", ((int)&a + 1));
    printf("return addr:%p\n", *p);
	*p = (unsigned long)nop;
}

int main(void)
{
    unsigned long main_a = 0x1122334455667788;
    printf("main addr:%p\n", &main);
    printf("foo addr:%p\n", &foo);
    foo(0x1111111111111111, 0x2222222222222222, 0x3333333333333333, 0x4444444444444444);
}
