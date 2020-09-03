readme.txt

:Author: kalipy
:Email: kalipy@debian
:Date: 2020-09-03 16:53

64位机器上编译运行32汇编及c程序的方法：
    1.sudo apt-get install gcc-multilib 

    2.as -o callee.o callee.s --32

    3.gcc -o caller caller.c callee.o -m32

不推荐的邪门歪道：
   汇编程序最开始加：
        .code32

    为什么不推荐?
        会发生内存访问错误
 

