#include <iostream>

template<typename T>
void PrintBinaryString(const T &bits)
{
    T off = (1 << (sizeof(T) * 8 - 1));
    while (off > 0) {
        if ((bits & off) != 0) // fuck, parenthesis is very very very important! it waste me half hour to debug this shit.
            std::cout << "1";
        else
            std::cout << "0";
        off >>= 1;
    }
    std::cout << std::endl;
}

int main(void)
{
    unsigned int bits = 0233;
    PrintBinaryString<unsigned int>(bits);
    PrintBinaryString<unsigned int>(~bits);

    unsigned char b1 = 0145;
    unsigned char b2 = 0257;
    std::cout << "b1\t:\t";
    PrintBinaryString<unsigned char>(b1);
    std::cout << "b2\t:\t";
    PrintBinaryString<unsigned char>(b2);
    std::cout << "b1 & b2\t:\t";
    PrintBinaryString<unsigned char>(b1 & b2);
    std::cout << "b1 | b2\t:\t";
    PrintBinaryString<unsigned char>(b1 | b2);
    std::cout << "b1 ^ b2\t:\t";
    PrintBinaryString<unsigned char>(b1 ^ b2);

    /* teacher students */
    unsigned long quiz1 = 0; // initialized to 0, ul is promised to be at least 32 bits.
    // set the 27th student pass
    quiz1 |= (1UL << 27);
    // when the teacher found that student actually failed.
    quiz1 &= ~(1UL << 27);
    // see if the 27th student pass or fail
    bool status = (quiz1 & (1UL << 27));

}

