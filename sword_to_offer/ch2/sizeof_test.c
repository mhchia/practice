#include <stdio.h>

int GetSize(int data[])
{
    return sizeof(data);
}


int main(int argc, char* argv[])
{
    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1); // 20, sizeof recognize the array rather than a pointer

    int* data2 = data1;
    int size2 = sizeof(data2); // 8, data2 is only a pointer

    int size3 = GetSize(data1); // 8, because that the parameter data is a pointer

    printf("%d, %d, %d", size1, size2, size3);

    return 0;
}

