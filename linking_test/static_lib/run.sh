#!/bin/bash

# 這段程式碼是在test如何建立自己的static library(靜態連結),
# 然後如何去link他。
# static lib用於靜態連結，把一堆object file用ar(archiver)包裝起來，以.a為結尾。
# 優點是說效能較好，而且執行時不會找不到library或因為版本而有問題（因為exe檔已經將他們連結好了）
# 缺點是說檔案大，不好維護。若lib改版了還要重新linking。

# generate object files
gcc haha1.c haha2.c -c

# pack object files into .a (static library)
ar rcs libtest.a haha1.o haha2.o

# link main.c with libtest.a
gcc main.c libtest.a
# or gcc main.c -L. -ltest \
#  -L means search the current dir \
#  -l means the linking with the libtest.a, which must have the prefix 'lib'

