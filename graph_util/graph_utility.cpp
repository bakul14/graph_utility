#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define size 10

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

int main(void) {
    FILE* myfile_in;
    FILE* myfile_out;
    int matrix[5][5] = {0};
    int i = 0; //строка
    int j = 0; //столбец
    int chislo = 0;

    myfile_in = fopen("input2.txt", "r");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            fscanf(myfile_in, "%d", &chislo);
            matrix[i][j] = chislo;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) printf("%d ", matrix[i][j]);
        printf("\n\r");
    }

    printf("\n\ngraph flita {\n\r");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < (5-i); j++) {
            if (matrix[i][j] != 0) printf("%c -- %c [label = %d]\n\r", ('A' + i), ('A' + j), (matrix[i][j]));
        }
    }
    printf("}\n\n");

    myfile_out = fopen("output.txt", "w");
    fprintf(myfile_out, "graph flita {\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < (5 - i); j++) {
            if (matrix[i][j] != 0) fprintf(myfile_out, "%c -- %c [label = %d]\n", ('A' + i), ('A' + j), (matrix[i][j]));
        }
    }
    fprintf(myfile_out, "}");
    printf("Success write data to file\n\n");

    return 0;
}