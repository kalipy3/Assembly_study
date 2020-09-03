readme.txt

:Author: kalipy
:Email: kalipy@debian
:Date: 2020-09-03 01:53

ld86 -0 -s -o boot boot.o//注意是数字0,不是字母O
dd bs=32 if=boot of=hd.img skip=1 conv=notrunc
