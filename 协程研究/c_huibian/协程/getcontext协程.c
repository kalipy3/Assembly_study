#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>

static ucontext_t _main;
static ucontext_t uctx[3];
char stack1[4096];
char stack2[4096];
char stack3[4096];

static int idx = -1;

// 调度切换例程
// 1. 目前采用轮转调度，比较简单
// 2. 如果采用策略调度，则需要保存curr元数据，精确定位swapcontext第一个参数为当前线程的context
void schedule()
{
	idx ++;
	if (swapcontext(&uctx[idx%3], &uctx[(idx+1)%3]) == -1) {
		exit(-1);
	}
}

// 此下3个函数为3个线程的线程处理函数，各自打印各自的序列。
static void thread1(void)
{
	int i = 1;

	while (i++) {
		printf("Thread 1, working:%d\n", i);
		sleep(1);
		if (i%3 == 0) {
			// 线程意识到自己该切换的时候，自主切换
			schedule();
		}
	}
}

static void thread2(void)
{
	int i = 0xfff;

	while (i++) {
		printf("Thread 2, working:%d\n", i);
		sleep(1);
		if (i%3 == 0) {
			schedule();
		}
	}
}

static void thread3(void)
{
	int i = 0xfffff;

	while (i++) {
		printf("Thread 3, working:%d\n", i);
		sleep(1);
		if (i%3 == 0) {
			schedule();
		}
	}
}

int main(int argc, char *argv[])
{
	// 初始化3个线程的上下文结构体，注意，一定要独立堆栈。
	getcontext(&uctx[0]);
	uctx[0].uc_stack.ss_sp = stack1;
	uctx[0].uc_stack.ss_size = sizeof(stack1);
	makecontext(&uctx[0], thread1, 0);

	getcontext(&uctx[1]);
	uctx[1].uc_stack.ss_sp = stack2;
	uctx[1].uc_stack.ss_size = sizeof(stack2);
	makecontext(&uctx[1], thread2, 0);

	getcontext(&uctx[2]);
	uctx[2].uc_stack.ss_sp = stack3;
	uctx[2].uc_stack.ss_size = sizeof(stack3);
	makecontext(&uctx[2], thread3, 0);

	printf("start thread 1\n");
	swapcontext(&_main, &uctx[0]);

	return 0;
}
