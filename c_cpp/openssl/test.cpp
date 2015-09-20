#include <iostream>

#include <openssl/sha.h>

int main(void)
{
    SHA512_CTX c;
    int a = SHA512_Init(&c);

    std::cout << a << std::endl;

    return 0;
}

