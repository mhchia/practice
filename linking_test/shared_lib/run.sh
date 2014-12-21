#!/bin/bash

: '
Shared library是在程式執行起始時才會自動載入(runtime?)，
因為lib和exe是分離的，維護的彈性較好。
shared library是在程式起始時就要載入，而不是執行中用到才載入(dynamic loading library才是這樣)，
而且在連結時就需要有該程式庫才能進行連結。

soname 用來表示一個特定library的名稱。e.g. libtest.so.1，
以lib為開頭，接下來是library的名稱，再來是.so，最後是版號(版號表示界面的版本，若界面有改變則版號就會變)

realname是實際放有library程式的檔案名稱，後面還會有minor版號與release版號，e.g. libtest.so.1.0.0
release版號用在說程式內容的修正，界面完全沒變。
minor版號表示有新增加界面，但舊的界面沒變，因此仍與舊版相容。
最前面的version版號用於原界面有移除或修改，因此與舊版不相容。

linker name用於連結時的名稱，就是不含版號的soname，e.g. libtest.so
通常linker name和soname是用ln指到相應的real name。
e.g.

#$ ln -s libtest.so.1.0.0 libtest.so  # 後者為linker name檔
#$ ln -s libtest.so.1.0.0 libtest.so.1 # 後者為soname檔
'
# 產生position-independent code, 也可用-fpic，但-fPIC比較通用於不同平台，產生的code比較大。
gcc -c -fPIC haha1.c haha2.c

# 將haha1.o haha2.o編譯成shared library，-shared表示要編譯成sharedlib, -Wl表示後面加的是
# 要傳給linker的參數記得中間用逗號隔開不能有空白，-soname表示要加上soname叫做libtest.so.1
# 如果不加-soname應該也可編譯，只是你用objdump -p就看不到SONAME了。
# 而且在link時linker會去找libtest.so而非libtest.so.1
# $ ldd a.out 就可知道差別（後述）
# [NOTE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!]
gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.0 haha1.o haha2.o
# gcc -shared -o libtest.so.1.0.0 haha1.o haha2.o

# 此時如果要看這個object file(.so)的內容，可利用
# $ objdump -p libtest.so ，其中SONAME這欄位就是-soname參數所加上的那個lib soname

# 將realname link成linker name與soname，linker 在link時都會用linker name。
ln -s libtest.so.1.0.0 libtest.so
ln -s libtest.so.1.0.0 libtest.so.1

# 使用shared library
gcc main.c libtest.so

: '
Note:
1.也可使用
 $ gcc main.c -L. -ltest
 linker就會去.找尋libtest.so(或libtest.a)來進行連結
 這樣很annoying阿，如果同時有static和shared在同個目錄，他會選擇哪個link呢？
 答案是linker會優先選擇shared lib

2.若你想要只用static來編譯的話，可以加上-static
但注意到這樣你程式裡面用到的所有library都會是以static來link了(e.g. libc, ...)，
執行檔的size會非常大。

3.若要看執行檔與shared的相依性，可用ldd

case 1: 若當時執行
$ gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.0 haha1.o haha2.o
則
$ ldd a.out
    linux-vdso.so.1 =>  (0x00007fffa71fe000)
    libtest.so.1 => not found
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f1549979000)
    /lib64/ld-linux-x86-64.so.2 (0x00007f1549d63000)
可看出linker會去找的是libtest.so.1，執行檔要求載入libtest.so.1

case 2: 若當時執行
$ gcc -shared -o libtest.so.1.0.0 haha1.o haha2.o
則
$ ldd a.out
    linux-vdso.so.1 =>  (0x00007fff77913000)
    libtest.so => not found
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f8d14c6d000)
    /lib64/ld-linux-x86-64.so.2 (0x00007f8d15057000)
可看出linker會去找libtest.so來連結，執行檔會要求載入libtest.so
'
./a.out
:'
    此時因為找不到libtest.so.1所以無法執行程式，可用以下三種方法解決：
1. 將libtest.so.1安裝到系統library目錄，e.g. /usr/lib 底下
2. 設定/etc/ld.so.conf，加入一個library搜尋目錄，並執行ldconfig更新cache
3. 設定LD_LIBRARY_PATH這個環境變數，來搜尋library
e.g.
設定LD_LIBRARY_PATH並執行a.out
'
LD_LIBRARY_PATH=. ./a.out

