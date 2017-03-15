#include <iostream>

bool Find(int (*matrix)[4], int rows, int columns, int number)
{
    std::cout << "sizeof matrix = " << sizeof(matrix) << std::endl; // 8 bytes, because it is a pointer to array of 4 int
    if (matrix && rows > 0 && columns > 0) {
        int x = 0, y = columns - 1;
        while (x >= 0 && x < rows && y >= 0 && y < columns) {
            if (matrix[x][y] == number) {
                std::cout << x << " " << y << std::endl;
                return true;
            } else if (matrix[x][y] > number) {
                --y;
            } else {
                ++x;
            }
        }
    }

    return false;
}


int main(void)
{
    int a[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    std::cout << Find(NULL, 4, 4, 18) << std::endl;

    return 0;
}

