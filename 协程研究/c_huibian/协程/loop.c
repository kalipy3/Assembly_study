#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>

int main()
{
    int a = 1;
    ucontext_t ctx_1;
    getcontext(&ctx_1); //将当前上下文保存到ctx_1中

    a++;
    printf("%d\n", a);

    setcontext(&ctx_1); //恢复ctx_1保存的上下文

    return 0;
}
