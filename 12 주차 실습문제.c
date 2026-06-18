#include <stdio.h>
// 12주차 실습문제 
// ==========================================================
// 1번 문제: 복소수 구조체 기본 연산 (struct complex1)         // 복소수에 대한 구조체 정의하고 함수 작성
// ==========================================================
struct complex1 {
    double real;
    double imag;
};

struct complex1 complex_add(struct complex1 c1, struct complex1 c2) {
    struct complex1 r; r.real = c1.real + c2.real; r.imag = c1.imag + c2.imag; return r;
}
struct complex1 complex_sub(struct complex1 c1, struct complex1 c2) {
    struct complex1 r; r.real = c1.real - c2.real; r.imag = c1.imag - c2.imag; return r;
}
struct complex1 complex_mul(struct complex1 c1, struct complex1 c2) {
    struct complex1 r;
    r.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    r.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return r;
}
struct complex1 complex_div(struct complex1 c1, struct complex1 c2) {
    struct complex1 r = { 0,0 }; double den = (c2.real * c2.real) + (c2.imag * c2.imag);
    if (den != 0) {
        r.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / den;
        r.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / den;
    }
    return r;
}

void ex01(void) {
    struct complex1 num1 = { 4.0, 3.0 };
    struct complex1 num2 = { 2.0, 1.0 };
    struct complex1 res;
    printf("--- [1번 문제 결과] ---\n");
    res = complex_add(num1, num2); printf("덧셈: %.1f + %.1fi\n", res.real, res.imag);
    res = complex_sub(num1, num2); printf("뺄셈: %.1f + %.1fi\n", res.real, res.imag);
    res = complex_mul(num1, num2); printf("곱셈: %.1f + %.1fi\n", res.real, res.imag);
    res = complex_div(num1, num2); printf("나눗셈: %.1f + %.1fi\n", res.real, res.imag);
}


// ==========================================================
// 2번 문제: typedef를 이용한 복소수 연산 (Complex2)           // 1번 문제를 typedef 이용해서 변경 
// ==========================================================
typedef struct {
    double real;
    double imag;
} Complex2;

void ex02(void) {
    Complex2 num1 = { 4.0, 3.0 };
    Complex2 num2 = { 2.0, 1.0 };
    Complex2 res;
    printf("\n--- [2번 문제 결과] ---\n");
    res.real = num1.real + num2.real; res.imag = num1.imag + num2.imag;
    printf("typedef 덧셈: %.1f + %.1fi\n", res.real, res.imag);
}


// ==========================================================
// 3번 문제: 점의 사분면 판별 (Point3)                            3. 구조체 사용해서 몇 사분면에 속하는지 작성 
// ==========================================================
typedef struct {
    int x;
    int y;
} Point3;

int quadrant(Point3 p) {
    if (p.x > 0 && p.y > 0) return 1;
    else if (p.x < 0 && p.y > 0) return 2;
    else if (p.x < 0 && p.y < 0) return 3;
    else if (p.x > 0 && p.y < 0) return 4;
    return 0;
}

void ex03(void) {
    Point3 my_point = { -3, 5 };
    printf("\n--- [3번 문제 결과] ---\n");
    printf("지정된 좌표: (%d, %d)\n", my_point.x, my_point.y);
    int result = quadrant(my_point);
    if (result != 0) printf("결과: 제 %d 사분면에 속합니다.\n", result);
    else printf("결과: 축 또는 원점입니다.\n");
}


// ==========================================================
// 4번 문제: 원의 둘레 및 면적 리턴 (Point4, Circle4)           4. 구조체 활용해서 둘레와 면적 구하기 
// ==========================================================
typedef struct {
    int x;
    int y;
} Point4;

typedef struct {
    int radius;
    Point4 center;
} Circle4;

int permeter_return(Circle4 c) {
    return (int)(2 * 3.14 * c.radius);
}
int area_return(Circle4 c) {
    return (int)(3.14 * c.radius * c.radius);
}

void ex04(void) {
    Circle4 my_circle = { 5, {2, 3} };
    printf("\n--- [4번 문제 결과] ---\n");
    printf("원 반지름: %d, 중심좌표: (%d, %d)\n", my_circle.radius, my_circle.center.x, my_circle.center.y);
    printf("원의 둘레 (정수 반환): %d\n", permeter_return(my_circle));
    printf("원의 면적 (정수 반환): %d\n", area_return(my_circle));
}


// ==========================================================
// 5번 문제: 포인터 활용 둘레 및 면적 저장 (Point5, Circle5)   
// ==========================================================
typedef struct {
    int x;
    int y;
} Point5;

typedef struct {
    int radius;
    int permeter;
    int area;
    Point5 center;
} Circle5;

int calc_perimeter(Circle5* c) {
    c->permeter = (int)(2 * 3.14 * c->radius);
    return c->permeter;
}
int calc_area(Circle5* c) {
    c->area = (int)(3.14 * c->radius * c->radius);
    return c->area;
}

void ex05(void) {
    Circle5 my_circle = { 5, 0, 0, {2, 6} };
    printf("\n--- [5번 문제 결과] ---\n");
    calc_perimeter(&my_circle);
    calc_area(&my_circle);
    printf("원 반지름: %d, 중심좌표: (%d, %d)\n", my_circle.radius, my_circle.center.x, my_circle.center.y);
    printf("구조체 내부에 저장된 둘레: %d\n", my_circle.permeter);
    printf("구조체 내부에 저장된 면적: %d\n", my_circle.area);
}



// ==========================================================
// 최종 메인 함수 구역 (순서대로 전부 실행)
// ==========================================================
int main(void)
{
   //ex01();
   //ex02();
   //ex03();
   //ex04();
   ex05();

    return 0;
}