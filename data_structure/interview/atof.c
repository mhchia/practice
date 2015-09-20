#include <stdio.h>
#include <string.h>

#include <math.h>

double atof_mine(char a[])
{
    int dot_pos = -1;
    int i;
    for (i = 0; i < strlen(a); ++i) {
        if (a[i] == '.') {
            dot_pos = i;
            break;
        }
    }

    double sum = 0;
    for (i = strlen(a) - 1; i >= 0; --i) {
        if (dot_pos == i)
            continue;
        if (dot_pos == -1) {
            sum += (a[i] - '0') * pow(10, strlen(a) - i - 1);
        } else {
            if (dot_pos - i > 0)
                sum += (a[i] - '0') * pow(10, dot_pos - i - 1);
            else
                sum += (a[i] - '0') * pow(10, dot_pos - i);
        }
    }

    return sum;
}


int main(void)
{
    char a[] = "12222.28128218";
    printf("%f\n", atof_mine(a));
}

