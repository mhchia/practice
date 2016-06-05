// shellcode

time_t z()
{
  return time(0) - 1456113600;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  char v4; // [sp+1Bh] [bp-5h]@1
  unsigned int v5; // [sp+1Ch] [bp-4h]@1

  alarm(0x3Cu);
  setvbuf(stdout, 0, 2, 0);
  v5 = z() / 0x2710u;
  printf("Echo string (less than %d bytes): ", v5);
  read(0, &v4, v5);
  strcpy(buf, &v4);
  puts(buf);
  return 0;
}
