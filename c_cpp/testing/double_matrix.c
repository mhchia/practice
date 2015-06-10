#include <stdio.h>
#include <stdlib.h>

double **dmatrix(int nr, int nc)
{
    /*
    double **mat;
    mat = (double **)malloc(nr * sizeof(double *));
    if (mat == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < nr; i++) {
        mat[i] = (double *)malloc(nc * sizeof(double));
        if (mat[i] == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(EXIT_FAILURE);
        }
    }
    */

    double *mat = (double *)malloc(nr * nc * sizeof(double));
    return mat;
}

void matmult(double **a, double **b, double **c, int n1, int n2, int n3)
{
    int i, j, k;
    for (i = 0; i < n1; i++)
        for (j = 0; j < n3; j++) {
            c[i][j] = 0.0;
            for (k = 0; k < n2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int main(void)
{
    /*
    int n1 = 3, n2 = 3, n3 = 3;
    double **a = dmatrix(n1, n2);
    a[0][0] = 5.0;
    a[0][1] = 2.0;
    a[0][2] = 3.0;
    a[1][0] = 4.0;
    a[1][1] = 5.0;
    a[1][2] = 6.0;
    a[2][0] = 7.0;
    a[2][1] = 8.0;
    a[2][2] = 9.0;
    double **b = dmatrix(n2, n3);
    b[0][0] = 0.25;
    b[0][1] = -0.5;
    b[0][2] = 0.25;
    b[1][0] = -0.5;
    b[1][1] = -2;
    b[1][2] = 1.5;
    b[2][0] = 0.25;
    b[2][1] = 2.16667;
    b[2][2] = -1.41667;
    double **c = dmatrix(n1, n3);

    matmult(a, b, c, n1, n2, n3);
    */
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n3; j++)
            printf("%lf ", c[i][j]);
        printf("\n");
    }
}
