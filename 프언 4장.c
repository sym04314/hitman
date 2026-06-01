#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void ex01(void) {
    int a;
    printf("4비트 10진수: ");
    scanf("%d", &a);

    if (a / 8 % 2)
        printf("1");

    else
        printf("0");

    if (a / 4 % 2)
        printf("1");

    else
        printf("0");

    if (a / 2 % 2)
        printf("1");

    else
        printf("0");

    if (a % 2)
        printf("1");

    else
        printf("0");








}












// [실습 2번]
void ex02(void) {





    double a, b, c, dis;


    printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)

        printf("방정식의 근은 %f입니다.\n", -c / b);


    
  









    else
    
        dis = b * b - 4.0 * a * c;
    if (dis >= 0) {


        printf("방정식의 근은 %.2f입니다.\n", (-b + sqrt(dis)) / (2.0 * a));
        printf("방정식의 근은 %.2f입니다.\n", (-b - sqrt(dis)) / (2.0 * a));

    }
        else if (dis == 0)

           printf("방정식은 중근 %.2f입니다", -b / 2 * a);
        
        else
        
          printf("실근이 존재하지 않습니다\n");
        
    

    return 0;
}
    





void ex03(void) {
    double a, b, c, dis;
    int result;


    printf("result의 값은 근의 공식의 근의 개수 입니다.");
    printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오: ");
    scanf("%f %f %f", &a, &b, &c);

    switch (result) {
        dis = b * b - 4.0 * a * c;

    case 0:
        printf("실근이 존재하지 않습니다.\n");
        break;

    case 1:
        printf("방정식의 근은 중근: %.1f\n", -b /( 2 * a));
        break;




    case 2:
        printf("방정식의 근은: %.1f\n", -b + sqrt(dis) / 2 * a);
        printf("방정식의 근은: %.1f\n", -b - sqrt(dis) / 2 * a);
        break;

    }
}
    









int main(void) {
   
    //ex01();    // 현재 활성화 (실행됨)
    //ex02(); // 현재 주석 처리 (실행 안 됨)
    //ex03()
    return 0;
}