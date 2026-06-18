#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

// [실습 2-1] 1차원 복사 //13주자 실습문제 
int ex01(void) {
    FILE* fp = fopen("dog_275x183_8bits.raw", "rb");
    FILE* fout = fopen("out.raw", "wb");
    unsigned char buffer[275 * 183];
    if (!fp) return 1;
    size_t br = fread(buffer, 1, sizeof(buffer), fp);
    fwrite(buffer, 1, br, fout);
    fclose(fp); fclose(fout);
    return 0;
}

// [실습 2-B] 2차원 복사
int ex02(void) {
    FILE* fp = fopen("dog_275x183_8bits.raw", "rb");
    FILE* fout = fopen("out.raw", "wb");
    unsigned char buffer[183][275];
    if (!fp) return 1;
    size_t br = fread(buffer, 1, 183 * 275, fp);
    fwrite(buffer, 1, br, fout);
    fclose(fp); fclose(fout);
    return 0;
}

// [실습 2-3] 색 반전 코드
int ex03(void) {
    FILE* fp = fopen("dog_275x183_8bits.raw", "rb");
    FILE* fout = fopen("inverted.raw", "wb"); // 반전된 결과는 별도 파일로 저장
    unsigned char buffer[275 * 183];

    if (fp == NULL) {
        printf("[ex03] 파일 열기 실패\n");
        return 1;
    }

    // 1. 파일 읽기
    size_t byte_read = fread(buffer, sizeof(unsigned char), sizeof(buffer), fp);

    // 2. 색 반전 (255 - 픽셀값)
    for (int i = 0; i < byte_read; i++) {
        buffer[i] = 255 - buffer[i];
    }

    // 3. 반전된 데이터 저장
    fwrite(buffer, sizeof(unsigned char), byte_read, fout);

    printf("[ex03] 색 반전 완료! (inverted.raw 생성)\n");
    fclose(fp);
    fclose(fout);
    return 0;
}

int main(void)
{
    // 실행할 문제의 주석(//)을 풀고 실행하세요!
    // ex01(); 
    // ex02(); 
    ex03();    // 색 반전 실행

    return 0;
}