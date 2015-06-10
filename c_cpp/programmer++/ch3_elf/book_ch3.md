```
$ objdump -h SimpleSection.o
    -h為列出各segment的headers summary info

SimpleSection.o:     file format elf64-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000054  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  00000094  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  0000009c  2**2
                  ALLOC
  3 .rodata       00000004  0000000000000000  0000000000000000  0000009c  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      00000025  0000000000000000  0000000000000000  000000a0  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000c5  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000058  0000000000000000  0000000000000000  000000c8  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
```

```
$ objdump -x SimpleSection.o

會多印出header(file description) and symbol table
header有elf檔案版本，目的機器型號，starting address等等。
```

```
$ size SimpleSection.o

查看ELF檔的text section, data section, bss section的size, 總size，及總size的hex
```

```
$ objdump -x SimpleSection.o

SimpleSection.o:     file format elf64-x86-64
SimpleSection.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000054  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  00000094  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  0000009c  2**2
                  ALLOC
  3 .rodata       00000004  0000000000000000  0000000000000000  0000009c  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      00000025  0000000000000000  0000000000000000  000000a0  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000c5  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000058  0000000000000000  0000000000000000  000000c8  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 SimpleSection.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000004 l     O .data	0000000000000004 static_var.1731
0000000000000000 l     O .bss	0000000000000004 static_var2.1732
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     O .data	0000000000000004 global_init_var
0000000000000004       O *COM*	0000000000000004 global_uninit_var
0000000000000000 g     F .text	0000000000000021 func1
0000000000000000         *UND*	0000000000000000 printf
0000000000000021 g     F .text	0000000000000033 main


RELOCATION RECORDS FOR [.text]:
OFFSET           TYPE              VALUE
0000000000000011 R_X86_64_32       .rodata
000000000000001b R_X86_64_PC32     printf-0x0000000000000004
0000000000000032 R_X86_64_PC32     .data
0000000000000038 R_X86_64_PC32     .bss-0x0000000000000004
000000000000004b R_X86_64_PC32     func1-0x0000000000000004


RELOCATION RECORDS FOR [.eh_frame]:
OFFSET           TYPE              VALUE
0000000000000020 R_X86_64_PC32     .text
0000000000000040 R_X86_64_PC32     .text+0x0000000000000021

從symbol table可看到static_var2.1732在.bss
```

```
$ objcopy -I binary -O elf32-i386 -B i386 image.jpeg image.o
將images.jpeg以binary格式讀入(-I)，以elf32-i386格式輸出(-O)，而output file的architecture為i386(-b)。
($ man objcopy :You can access this binary data inside a program by referencing the special
           symbols that are created by the conversion process.  These symbols are called
           _binary_objfile_start, _binary_objfile_end and _binary_objfile_size.)
用此architecture輸出則我們reference _binary_image_jpg_start, _binary_image_jpg_end, _binary_image_jpg_size
這些symbol來access這個binary data。

$ objdump -x image.o
or  objdump -ht image.o
可看到image塞在image.o裡

http://blog.linux.org.tw/~jserv/archives/001767.html
```

```
$ gcc -c selfdefine.c -o selfdefine.o
必須將__attribute__((section("FOO"))) int global = 42; 寫成global變數，而非local。不然會產生error。
這很合理因為local int一定會被放在.text。
另外，自訂section的名稱不要以.為開頭，以.為開頭的是預留給系統使用。
```

```
$ readelf -h SimpleSection.o
查看elf檔的header

ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF64
  Data:                              2的 complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              REL (Relocatable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x0
  Start of program headers:          0 (bytes into file)
  Start of section headers:          392 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           0 (bytes)
  Number of program headers:         0
  Size of section headers:           64 (bytes)
  Number of section headers:         13
  Section header string table index: 10

elf heade結構與相關常數定義在/usr/include/elf.h裡。

/* Type for a 16-bit quantity.  */
typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;

/* Types for signed and unsigned 32-bit quantities.  */
typedef uint32_t Elf32_Word;
typedef int32_t  Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef int32_t  Elf64_Sword;

typedef struct
{
  unsigned char e_ident[EI_NIDENT]; /* Magic number and other info */
  Elf64_Half    e_type;         /* Object file type */
  Elf64_Half    e_machine;      /* Architecture */
  Elf64_Word    e_version;      /* Object file version */
  Elf64_Addr    e_entry;        /* Entry point virtual address */
  Elf64_Off e_phoff;        /* Program header table file offset */
  Elf64_Off e_shoff;        /* Section header table file offset */
  Elf64_Word    e_flags;        /* Processor-specific flags */
  Elf64_Half    e_ehsize;       /* ELF header size in bytes */
  Elf64_Half    e_phentsize;        /* Program header table entry size */
  Elf64_Half    e_phnum;        /* Program header table entry count */
  Elf64_Half    e_shentsize;        /* Section header table entry size */
  Elf64_Half    e_shnum;        /* Section header table entry count */
  Elf64_Half    e_shstrndx;     /* Section header string table index */
} Elf64_Ehdr;

可看出Elf64_Ehdr與readelf看到的elf header很多是一一對應的，除了e_ident以外(對到魔數那些bytes)

```

typedef struct
{
  Elf64_Word    sh_name;        /* Section name (string tbl index) */  位於.shstrtab中的位移量（.shstrtab存放一堆字串，這個section的name也存在裡面，而sh_name為其在字串表中的偏移）
  Elf64_Word    sh_type;        /* Section type */
  Elf64_Xword   sh_flags;       /* Section flags */
  Elf64_Addr    sh_addr;        /* Section virtual addr at execution */
  Elf64_Off sh_offset;      /* Section file offset */ 該section在檔案中的偏移量
  Elf64_Xword   sh_size;        /* Section size in bytes */
  Elf64_Word    sh_link;        /* Link to another section */
  Elf64_Word    sh_info;        /* Additional section information */
  Elf64_Xword   sh_addralign;       /* Section alignment */ 3 表示為2^3
  Elf64_Xword   sh_entsize;     /* Entry size if section holds table */ ？
} Elf64_Shdr; （此為段述項，描述Section Header的一項）

sh_type各種value在elf.h:317

sh_flags在elf.h:356


##Relocation Table

```
$ readelf -S SimpleSection.o
There are 13 section headers, starting at offset 0x188:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .text             PROGBITS         0000000000000000  00000040
       0000000000000054  0000000000000000  AX       0     0     1
  [ 2] .rela.text        RELA             0000000000000000  000006b0
       0000000000000078  0000000000000018          11     1     8
  [ 3] .data             PROGBITS         0000000000000000  00000094
       0000000000000008  0000000000000000  WA       0     0     4
  [ 4] .bss              NOBITS           0000000000000000  0000009c
       0000000000000004  0000000000000000  WA       0     0     4
  [ 5] .rodata           PROGBITS         0000000000000000  0000009c
       0000000000000004  0000000000000000   A       0     0     1
  [ 6] .comment          PROGBITS         0000000000000000  000000a0
       0000000000000025  0000000000000001  MS       0     0     1
  [ 7] .note.GNU-stack   PROGBITS         0000000000000000  000000c5
       0000000000000000  0000000000000000           0     0     1
  [ 8] .eh_frame         PROGBITS         0000000000000000  000000c8
       0000000000000058  0000000000000000   A       0     0     8
  [ 9] .rela.eh_frame    RELA             0000000000000000  00000728
       0000000000000030  0000000000000018          11     8     8
  [10] .shstrtab         STRTAB           0000000000000000  00000120
       0000000000000061  0000000000000000           0     0     1
  [11] .symtab           SYMTAB           0000000000000000  000004c8
       0000000000000180  0000000000000018          12    11     8
  [12] .strtab           STRTAB           0000000000000000  00000648
       0000000000000066  0000000000000000           0     0     1
```

可看到.rela.text就是.text對應的重定表（每個需要重定的程式碼區段或資料區段都會有一個對應的重定表）
其sh_link為11表示其所需要的symbol table位於section header table的index為11，sh_info表示其為在section headers table中index為1的section的重定表。


## 字串表
- ELF檔將用到的字串集中放在字串表中，因此其他用到一些字串的地方只要放『在字串表中的offset就好』
- .strtab保留普通的字串，而.shstrtab用來保存section header用到的字串。
- 檔頭中的e_shstrndx就是記說.shstrtab在section header table中的index (readelf -h 可看到 e_shstrndx)


