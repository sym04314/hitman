#include <stdio.h> //10, 11주차 포인터 실습 문제 

#define _CRT_SECURE_NO_WARNINGS

void ex01(void) { //  1. 2개의 정수의 합과 차를 동시에 반환하는 함수를 작성하고 테스트 하시오. 
    int num1 = 10;
    int num2 = 5;
    int s_result = 0;
    int d_result = 0;

    int* sum = &s_result;
    int* diff = &d_result;

    *sum = num1 + num2;
    *diff = num1 - num2;

    printf("두 수의 합: %d\n", s_result);
    printf("두 수의 차: %d\n", d_result);
}

#define SORTED_LENGTH 4
#define TOTAL_LENGTH (2 * SORTED_LENGTH)

// 배열을 출력하기 위한 함수
void print_array(int* arr, int total_length)
{
    for (int i = 0; i < total_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ex02 형태로 구현한 병합 함수 // 2.size가 같은 2개의 정렬된 정수 배열 A와 B가 있을 때 이 2개의 배열을 합쳐서 하나의 정렬된 배열을 완성

void ex02(void)
{
    int a[SORTED_LENGTH] = { 2, 5, 7, 8 };
    int b[SORTED_LENGTH] = { 1, 3, 4, 6 };
    int c[TOTAL_LENGTH];

    // 포인터 변수 선언 (각 배열의 시작 주소를 가리킴)
    int* p_a = a;
    int* p_b = b;
    int* p_c = c;

    int i = 0; // 배열 a의 인덱스
    int j = 0; // 배열 b의 인덱스
    int k = 0; // 병합될 배열 c의 인덱스

    // 1. 두 배열 중 하나가 끝날 때까지 비교하며 합치기
    while (i < SORTED_LENGTH && j < SORTED_LENGTH) {
        if (*(p_a + i) < *(p_b + j)) {
            *(p_c + k) = *(p_a + i);
            i++;
        }
        else {
            *(p_c + k) = *(p_b + j);
            j++;
        }
        k++;
    }

    // 2. 배열 a에 남은 데이터가 있다면 마저 채워넣기
    while (i < SORTED_LENGTH) {
        *(p_c + k) = *(p_a + i);
        i++;
        k++;
    }

    // 3. 배열 b에 남은 데이터가 있다면 마저 채워넣기
    while (j < SORTED_LENGTH) {
        *(p_c + k) = *(p_b + j);
        j++;
        k++;
    }

    // 결과 출력
    print_array(c, TOTAL_LENGTH);
}

#include <stdio.h> //3. 1차원 배열의 주소와 길이를 받아서 각 요소의 값이 1씩 증가하는 코드를 작성하고 테스트해 보시오. 

#define ARRAY_LENGTH 5

void increase_array(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        *(arr + i) = *(arr + i) + 1;
    }
}

void print_array_ex03(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void ex03(void)
{
    int data[ARRAY_LENGTH] = { 10, 20, 30, 40, 50 };

    printf("증가 전 배열: ");
    print_array_ex03(data, ARRAY_LENGTH);

    increase_array(data, ARRAY_LENGTH);

    printf("증가 후 배열: ");
    print_array_ex03(data, ARRAY_LENGTH);
}

#define MAT_ROWS 4
#define MAT_COLS 4

void ex04(void) //4. 2차원 배열을 1차원 배열로 포인터로 변환하는 코드를 작성하고 코드 내용을 이해하시오
{
    int mat2d[MAT_ROWS][MAT_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int mat1d[MAT_ROWS * MAT_COLS] = { 0 };
    int k;

    // Method 1
    k = 0;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            *(mat1d + k) = *(*(mat2d + i) + j);
            k++;
        }
    }
    printf("Method 1: ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");

    // Method 2
    int* p_mat2d = (int*)mat2d;
    k = 0;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            *(mat1d + k) = *(p_mat2d + (i * MAT_COLS + j));
            k++;
        }
    }
    printf("Method 2: ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");

    // Method 3
    int total_elements = MAT_ROWS * MAT_COLS;
    for (int i = 0; i < total_elements; i++) {
        *(mat1d + i) = *(p_mat2d + i);
    }
    printf("Method 3: ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");
}

#define MAT_ROWS 4
#define MAT_COLS 4

void ex05(void) //5.2차원 배열을 1차원 배열로 변환하고 각각의 요소들을 Transpose 해서 제곱하는 함수를 작성하시오
{
    int mat2d[MAT_ROWS][MAT_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int mat1d[MAT_ROWS * MAT_COLS] = { 0 };
    int k;

    // Method 1 (Using *(*(mat2d + i) + j))
    k = 0;
    for (int j = 0; j < MAT_COLS; j++) {
        for (int i = 0; i < MAT_ROWS; i++) {
            int val = *(*(mat2d + i) + j);
            *(mat1d + k) = val * val;
            k++;
        }
    }
    printf("Method 1 (Transpose + Square): ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");

    // Method 2 (Using *(p_mat2d + (i * MAT_COLS + j)))
    int* p_mat2d = (int*)mat2d;
    k = 0;
    for (int j = 0; j < MAT_COLS; j++) {
        for (int i = 0; i < MAT_ROWS; i++) {
            int val = *(p_mat2d + (i * MAT_COLS + j));
            *(mat1d + k) = val * val;
            k++;
        }
    }
    printf("Method 2 (Transpose + Square): ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");

    // Method 3 (Using Flat Index Arithmetic)
    int total_elements = MAT_ROWS * MAT_COLS;
    for (int i = 0; i < total_elements; i++) {
        int r = i / MAT_ROWS;
        int c = i % MAT_ROWS;
        int target_index = c * MAT_COLS + r;
        int val = *(p_mat2d + target_index);
        *(mat1d + i) = val * val;
    }
    printf("Method 3 (Transpose + Square): ");
    for (int i = 0; i < MAT_ROWS * MAT_COLS; i++) {
        printf("%d ", *(mat1d + i));
    }
    printf("\n");
}


#define MAT_ROWS 4
#define MAT_COLS 4

void ex06(void)  //6. 2차원 배열에서 특정행만 모두 0으로 변경하는 함수를 작성하시오
{
    int mat2d[MAT_ROWS][MAT_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int target_row = 1;

    // Method 1 (Using mat2d[index][j])
    for (int j = 0; j < MAT_COLS; j++) {
        mat2d[target_row][j] = 0;
    }
    printf("Method 1 (Row %d to 0):\n", target_row);
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", mat2d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    int val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // Method 2 (Using *(*(mat2d + index) + j))
    for (int j = 0; j < MAT_COLS; j++) {
        *(*(mat2d + target_row) + j) = 0;
    }
    printf("Method 2 (Row %d to 0):\n", target_row);
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(*(mat2d + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // Method 3 (Using 1D Pointer Arithmetic: *(p_mat2d + (index * MAT_COLS + j)))
    int* p_mat2d = (int*)mat2d;
    for (int j = 0; j < MAT_COLS; j++) {
        *(p_mat2d + (target_row * MAT_COLS + j)) = 0;
    }
    printf("Method 3 (Row %d to 0):\n", target_row);
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(p_mat2d + (i * MAT_COLS + j)));
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // Method 4 (Using Pointer to Row Directly)
    int* p_row = *(mat2d + target_row);
    for (int j = 0; j < MAT_COLS; j++) {
        *(p_row + j) = 0;
    }
    printf("Method 4 (Row %d to 0):\n", target_row);
    for (int i = 0; i < MAT_ROWS; i++) {
        int* p_print = *(mat2d + i);
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(p_print + j));
        }
        printf("\n");
    }
    printf("\n");
}

#include <stdio.h>

#define MAT_ROWS 4
#define MAT_COLS 4

void ex07(void) // 7. 2차원 배열의 짝수, 홀수 행만 모두 0으로 변경하는 함수를 작성하시오 
{
    int mat2d[MAT_ROWS][MAT_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int val;

    // ==========================================
    // 1. padding_0_rows_even (Method 1 & Method 2)
    // ==========================================

    // Method 1 (Using mat2d[i][j]) - Even Rows to 0
    for (int i = 0; i < MAT_ROWS; i += 2) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = 0;
        }
    }
    printf("Method 1 (Even rows to 0):\n");
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", mat2d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // Method 2 (Using *(*(mat2d + i) + j)) - Even Rows to 0
    for (int i = 0; i < MAT_ROWS; i += 2) {
        for (int j = 0; j < MAT_COLS; j++) {
            *(*(mat2d + i) + j) = 0;
        }
    }
    printf("Method 2 (Even rows to 0):\n");
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(*(mat2d + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // ==========================================
    // 2. padding_0_rows_odd (Method 3 & Method 4)
    // ==========================================

    // Method 3 (Using 1D Pointer Arithmetic: *(p_mat2d + (i * MAT_COLS + j))) - Odd Rows to 0
    int* p_mat2d = (int*)mat2d;
    for (int i = 1; i < MAT_ROWS; i += 2) {
        for (int j = 0; j < MAT_COLS; j++) {
            *(p_mat2d + (i * MAT_COLS + j)) = 0;
        }
    }
    printf("Method 3 (Odd rows to 0):\n");
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(p_mat2d + (i * MAT_COLS + j)));
        }
        printf("\n");
    }
    printf("\n");

    // Reset Array
    val = 1;
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat2d[i][j] = val++;
        }
    }

    // Method 4 (Using Pointer to Row Directly) - Odd Rows to 0
    for (int i = 1; i < MAT_ROWS; i += 2) {
        int* p_row = *(mat2d + i);
        for (int j = 0; j < MAT_COLS; j++) {
            *(p_row + j) = 0;
        }
    }
    printf("Method 4 (Odd rows to 0):\n");
    for (int i = 0; i < MAT_ROWS; i++) {
        int* p_print = *(mat2d + i);
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(p_print + j));
        }
        printf("\n");
    }
    printf("\n");
}



#include <stdio.h>

#define MAT_ROWS 4
#define MAT_COLS 4

void ex08(void)  //8. 포인터가 열의 개수만큼 건너띄고 2차원 배열의 홀수 행만 모두 0으로 변경하는 함수
{
    int mat2d[MAT_ROWS][MAT_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int* p_mat2d = (int*)mat2d;
    int* odd_rows = p_mat2d + MAT_COLS;

    for (int i = 1; i < MAT_ROWS; i += 2) {
        for (int j = 0; j < MAT_COLS; j++) {
            *(odd_rows + j) = 0;
        }
        odd_rows += (MAT_COLS * 2);
    }

    printf("Method 8 (Odd rows to 0 using pointer stride):\n");
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            printf("%2d ", *(p_mat2d + (i * MAT_COLS + j)));
        }
        printf("\n");
    }
    printf("\n");
}


#define RANDOM_ARRAY_LENGTH 100 //9. 1부터 100까지 랜덤하게 정의된 다음 배열에 대해 포인터를 이용하여 코드를 작성하시오

void ex09(void) 
{
    int array[RANDOM_ARRAY_LENGTH] = {
        42, 7, 89, 15, 63, 28, 94, 3, 56, 71,
        12, 100, 37, 85, 9, 64, 23, 48, 77, 31,
        5, 92, 18, 74, 60, 11, 36, 81, 25, 50,
        66, 14, 97, 8, 45, 70, 29, 53, 19, 82,
        39, 6, 95, 21, 68, 33, 80, 10, 57, 99,
        2, 27, 73, 41, 88, 16, 61, 34, 46, 20,
        76, 13, 90, 4, 55, 22, 83, 30, 65, 17,
        96, 24, 40, 78, 32, 87, 35, 59, 26, 84,
        1, 44, 75, 38, 62, 28, 93, 47, 67, 49,
        98, 19, 54, 72, 91, 36, 58, 79, 43, 100
    };

    int* p_arr = array;

    printf("3의 배수 출력: ");
    for (int i = 0; i < RANDOM_ARRAY_LENGTH; i++) {
        if (*(p_arr + i) % 3 == 0) {
            printf("%d ", *(p_arr + i));
        }
    }
    printf("\n");
}


#include <stdio.h>

#define RANDOM_ARRAY_LENGTH 100

void print_multiple_of_3(int* arr, int length)
{
    printf("3의 배수 출력: ");
    for (int i = 0; i < length; i++) {
        if (*(arr + i) % 3 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

void ex10(void)   //10.array를 검사하여 3의 배수가 되는 숫자를 출력하는 print_multiple_of_3() 함수를 작성

{
    int array[RANDOM_ARRAY_LENGTH] = {
        42, 7, 89, 15, 63, 28, 94, 3, 56, 71,
        12, 100, 37, 85, 9, 64, 23, 48, 77, 31,
        5, 92, 18, 74, 60, 11, 36, 81, 25, 50,
        66, 14, 97, 8, 45, 70, 29, 53, 19, 82,
        39, 6, 95, 21, 68, 33, 80, 10, 57, 99,
        2, 27, 73, 41, 88, 16, 61, 34, 46, 20,
        76, 13, 90, 4, 55, 22, 83, 30, 65, 17,
        96, 24, 40, 78, 32, 87, 35, 59, 26, 84,
        1, 44, 75, 38, 62, 28, 93, 47, 67, 49,
        98, 19, 54, 72, 91, 36, 58, 79, 43, 100
    };

    print_multiple_of_3(array, RANDOM_ARRAY_LENGTH);
}


#include <stdio.h>                // 11. 2의 배수가 되는 숫자를 검사하여 해당 배열의 값을 1씩 증가하는 함수를 작성

#define RANDOM_ARRAY_LENGTH 100

void add_one(int* value)
{
    *value = *value + 1;
}

void ex11(void)
{
    int array[RANDOM_ARRAY_LENGTH] = {
        42, 7, 89, 15, 63, 28, 94, 3, 56, 71,
        12, 100, 37, 85, 9, 64, 23, 48, 77, 31,
        5, 92, 18, 74, 60, 11, 36, 81, 25, 50,
        66, 14, 97, 8, 45, 70, 29, 53, 19, 82,
        39, 6, 95, 21, 68, 33, 80, 10, 57, 99,
        2, 27, 73, 41, 88, 16, 61, 34, 46, 20,
        76, 13, 90, 4, 55, 22, 83, 30, 65, 17,
        96, 24, 40, 78, 32, 87, 35, 59, 26, 84,
        1, 44, 75, 38, 62, 28, 93, 47, 67, 49,
        98, 19, 54, 72, 91, 36, 58, 79, 43, 100
    };

    int* p_arr = array;

    for (int i = 0; i < RANDOM_ARRAY_LENGTH; i++) {
        if (*(p_arr + i) % 2 == 0) {
            add_one(p_arr + i);
        }
    }

    printf("결과 배열 출력:\n");
    for (int i = 0; i < RANDOM_ARRAY_LENGTH; i++) {
        printf("%d ", *(p_arr + i));
    }
    printf("\n");
}



int main(void)
{
    // ex01();
    // ex02();
    // ex03();
    // ex04();
    // ex05();
    // ex06();
    // ex07();
    // ex08();
    // ex09();
    // ex10();
    // ex11();
    return 0;
}

















