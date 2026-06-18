#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>  //14주차 실습문제 코드 

typedef struct { // 1. 구조체를 함수의 매개변수 포인터 형태로 전달하여 구조체 내용을 수정하는 코드 내용 
    int x;
    int y;
} Point;


void print_point(Point point) {
    printf("point x=%d, y=%d\n", point.x, point.y);
}

void set_point(Point* point, int x, int y) {
    point->x = x;
    point->y = y;
}

void ex01(void) {
    Point point;
    printf("--- [1번 문제] 구조체 포인터 수정 (ex01) ---\n");
    set_point(&point, 3, 5);
    print_point(point);
    printf("\n");
}


void ex02(void) { // 2. 0-9를 바이너리 형태로 데이터를 저장하는 코드를 작성 
    short i;
    short read_data;

    printf("--- [2번 문제] 0~9 바이너리 입출력 (ex02) ---\n");

    FILE* fout = fopen("out.dat", "wb");
    if (fout == NULL) return;

    for (i = 0; i <= 9; i++) {
        fwrite(&i, sizeof(short), 1, fout);
    }
    fclose(fout);
    printf("1. 'out.dat' 파일에 0~9 바이너리 저장 완료.\n");

    FILE* fin = fopen("out.dat", "rb");
    if (fin == NULL) return;

    printf("2. 'out.dat' 파일로부터 읽어온 데이터: ");
    while (fread(&read_data, sizeof(short), 1, fin) == 1) {
        printf("%d ", read_data);
    }
    printf("\n\n");
    fclose(fin);
}


int** alloc_matrix(int rows, int cols) {
    int** mat = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(sizeof(int) * cols);
    }
    return mat;
}

void free_matrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

void print_matrix(const char* name, int** mat, int rows, int cols) {
    printf("[%s 행렬 출력 (%dx%d)]\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void set_mat(int** mat, int rows, int cols) {
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = value++;
        }
    }
}

void ex05(void) {
    printf("--- [5번 문제] 이중 포인터 3x5 행렬 세팅 (ex05) ---\n"); //이중 포인터로 3x5 행렬을 1~15까지 순차적으로 들어가는 함수 출력

    int rows = 3, cols = 5;
    int** matrix = alloc_matrix(rows, cols);

    set_mat(matrix, rows, cols);
    print_matrix("Matrix A", matrix, rows, cols);

    free_matrix(matrix, rows);
}


void mat_add(int** mat1, int** mat2, int** res, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void mat_sub(int** mat1, int** mat2, int** res, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

int** mat_transpose(int** src, int rows, int cols) {
    int** dst = alloc_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dst[j][i] = src[i][j];
        }
    }
    return dst;
}

void mat_mul(int** mat1, int** mat2_T, int** res, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2_T[k][j];
            }
        }
    }
}

void ex06(void) {
    printf("--- [6번 문제] 이중 포인터 행렬 연산 (ex06) ---\n"); // 이중 포인터 2개 생성해서 덧셈, 뺄셈, 곱셈 계산하기 

    int rows = 3, cols = 5;

    int** mat1 = alloc_matrix(rows, cols);
    int** mat2 = alloc_matrix(rows, cols);

    set_mat(mat1, rows, cols);
    set_mat(mat2, rows, cols);

    int** res_add = alloc_matrix(rows, cols);
    int** res_sub = alloc_matrix(rows, cols);
    int** res_mul = alloc_matrix(rows, rows);

    mat_add(mat1, mat2, res_add, rows, cols);
    print_matrix("행렬 덧셈 결과", res_add, rows, cols);

    mat_sub(mat1, mat2, res_sub, rows, cols);
    print_matrix("행렬 뺄셈 결과", res_sub, rows, cols);

    int** mat2_T = mat_transpose(mat2, rows, cols);
    print_matrix("mat2의 전치 행렬(Transpose)", mat2_T, cols, rows);

    mat_mul(mat1, mat2_T, res_mul, rows, cols, rows);
    print_matrix("행렬 곱셈 결과 (mat1 * mat2_T)", res_mul, rows, rows);

    free_matrix(mat1, rows);
    free_matrix(mat2, rows);
    free_matrix(mat2_T, cols);
    free_matrix(res_add, rows);
    free_matrix(res_sub, rows);
    free_matrix(res_mul, rows);
}


int main(void) {
    //ex01();
    //ex02();
    //ex05();
   //ex06();

    return 0;
}