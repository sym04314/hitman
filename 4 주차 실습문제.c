#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#pragma execution_character_set("utf-8" ) //4 주차 조건문 실습문제 

int ex01(void) {
	int a, b, c;

	printf("input:");
	scanf("%d %d %d", &a, &b, &c);


	if (a > b && a > c)

		printf("%d", a);

	else if (b > a && b > c)
		printf("%d", b);

	else
		printf("%d", c);

}
	
	void ex02(void){
		int a, b, c;

		printf("input:");
		scanf("%d %d %d", &a, &b, &c);

		if (a < b && a < c)
			printf("%d", a);

		else if (b < a && b < c)
			printf("%d", b);

		else
			printf("%d", c);
	}

	void ex03(void) {

		int a, b;

		printf("input:");
		scanf("%d %d", &a, &b); //큰거에서 작은거로

		if (a > b)
			printf("output: %d %d", a, b);
		
		else
			printf("output: %d %d", b, a);
	}

	void ex04(void) {

		int a, b, c;

		printf("input:");
		scanf("%d %d %d", &a, &b, &c); //내림차순 큰거부터 작은거 

		printf("output:");

		if (a > b && a > c) {
			printf("%d ", a);

			if (b > c)
				printf("%d %d", b, c);

			else
				printf("%d%d", c, b);
		}


		if (b > a && b > c) {
			printf("%d ", b);

			if (a > c)
				printf("%d %d", a, c);

			else
				printf("%d%d", c, a);
		}



		if (c > a && c > b) {
			printf("%d ", c);
			
			if (c > a)
				printf("%d %d", c, a);

			else
				printf("%d%d", a, c);
		}



	}


	void ex05(void) {
		int a; //0~15

		printf("입력:");
		scanf("%d", &a);

		printf("값:");


		if ((a / 8) % 2)
			printf("1");

		else
			printf("0");



		if ((a / 4) % 2)
			printf("1");

		else
			printf("0");

		if ((a / 2) % 2)
			printf("1");

		else
			printf("0");

		if (a % 2)
			printf("1");

		else
			printf("0");

	}

	void ex06(void) {

		
		    float a, b, c, dis;

			printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오: ");
			scanf("%f %f %f", &a, &b, &c);

			if (a == 0)
			
				printf("방정식의 근은 %f입니다.", -c / b);
			
			else
			
				dis = b * b - 4.0 * a * c;

			if (dis > 0) {


				printf("방정식의 근은 %.2f입니다.\n", (-b + sqrt(dis)) / (2.0 * a));
				printf("방정식의 근은 %.2f입니다.\n", (-b - sqrt(dis)) / (2.0 * a));

			}


			else if (dis == 0)
				printf("방정식의 근은 중근 %.2f입니다.\n", (-b/(2.0 * a)));
				

			else 

				printf("실근이 존재하지 않습니다\n");
			

			
			
			

			
		}
	
	       
	void ex07(void) {
		float a, b, c, dis;
		int ans;
		 
		scanf("%f %f %f", &a, &b, &c); // %.1 .2 이런건 printf 출력할때나 쓰는거 
		                               // 실수형 f은 숫자 쓸때 2.0 4.0 뭐 이렇게 써야함

		dis = (b * b) - 4.0 * a * c;

		if (a == 0)
			printf("방정식의 근은 %f\n", -c / b);

		else {
			if (dis > 0) ans = 2;
			else if (dis == 0) ans = 1;
			else  ans = 0;


			switch (ans) {



			case 2:
				printf("방정식의 근은 %.1f", (-b + sqrt(dis)) / (2.0 * a)); //sqrt는 애초에 flaot으로 결과가 나오게 만들어졌음
				printf("방정식의 근은 %.1f", (-b - sqrt(dis)) / (2.0 * a));
				break;


			case 1:
				printf("방정식의 근은 %.1f", (-b + sqrt(dis)) / (2.0 * a));
				break;

			case 0:
				printf("방정식의 근은 없습니다");
				break;
			    }

		      }
	       }
		

	void ex08(void) {  //어떤 수를 나누었을 때 0이 되게 하는 수 > 약수
		int a;
		int b;

		printf("수 입력:");
		scanf("%d %d", &a, &b);

		if (a % b == 0)
			printf("약수입니다");

		else
			printf("약수가 아닙니다");

	}
	  

	void ex09(void) {

		int a;
		int b;

		printf("입력값:");
		scanf("%d %d", &a, &b);



		if (a > 0 && b > 0) {
			printf("1사분면");
		}

		if (a < 0 && b > 0) {
			printf("2사분면");
		}

		if (a < 0 && b < 0) {
			printf("3사분면");
		}

		if (a > 0 && b < 0) {
			printf("4사분면");
		}

	}


	void ex10(void) {
		int a;

		printf("input:");
		scanf("%d", &a);

		if (a > 2 && a <= 5)
			 printf("spring");

		if (a > 5 && a <= 8)
			 printf("summer");

		if (a > 8 && a <= 11)
			 printf("fall");

		if (a > 11 || a <= 2)
			 printf("winter");

	}

	void ex11(void) { //switch 문이 시작되고 끝날 때는 반드시 중괄호를 필수로 쳐야함 
		//각 case 문에는 중괄호 칠 필요 없음 어차피 break가 나오기 전까지 한 덩어리임 
		// 딱 한 가지 상황에서는 case 안에서도 중괄호를 써야 함 바로 그 case 안에서만 쓸 새로운 변수를 만들 때
		int a;

		printf("입력:");
		scanf("%d", &a);

		switch (a) { // a를 정수라고만 지정하고 초기화 시키지 않음 변수에 값을 대입해서 나타내 줘야함
			         //switch 문은 값이 정해지지 않은 변수로는 판단 불가 

		case 3: case 4: case 5:
			printf("spring");
			break;


		case 6: case 7: case 8:
			printf("summer");
			break;


		case 9: case 10: case 11:
			printf("fall");
			break;


		case 12: case 1: case 2:
			printf("winter");
			break;
		}

	}
          





	







	












			

		









		   




	



	





	






	int main(void) {
		//ex01();
		//ex02();
		//ex03();
		//ex04();
		//ex05();
		//ex06();
		//ex07();
		//ex08();
		//ex09();
		//ex10();
		//ex11();

	}














