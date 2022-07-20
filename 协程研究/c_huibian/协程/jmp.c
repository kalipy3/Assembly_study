#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

// 我们想直接执行这段指令，当然，它保存于某个文件，可以从文件里读出到code内存空间。
void nop(void)
{
    printf("nop!!!\n");
}

unsigned char *code;

int main(void)
{
    code = &nop;

	asm ( "jmp %0"
          :           
          :"r"(code)
          :);

	printf("end\n");
}
