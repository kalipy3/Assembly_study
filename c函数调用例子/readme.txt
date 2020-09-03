readme.txt

:Author: kalipy
:Email: kalipy@debian
:Date: 2020-09-03 12:42

默认生成64位汇编代码：
gcc -Wall -S -o main_32.s main.c

-m32生成32位汇编:
gcc -Wall -S -o main_32.s main.c -m32
