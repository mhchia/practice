int shared = 100000000;

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}
