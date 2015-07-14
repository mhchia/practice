# compile Lib.c to a Dynamic Shared Object file
gcc -fPIC -shared -o Lib.so Lib.c
# compile Program1.c and linking the object file with Lib.so
# 上面寫錯了！此時還沒做linking，linker只會對可執行檔Program1
# 的未定義符號作搜尋，若其在Lib.so被定義則標記說是動態連結符號。
# 不然，就是undefined reference error!
gcc -o Program1 Program1.c Lib.so
# compile Program2.c and linking the object file with Lib.so
# 上面寫錯了！此時還沒做linking
gcc -o Program2 Program2.c Lib.so
