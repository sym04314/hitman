#include <stdio.h> //5주차 반복문 실습문제 

void ex01(void) {
	int fac = 1, i = 1;


	for (i = 1; i <= 6; i++) {
		fac = fac * i;

		printf("%d", fac);


	}
}


	

	



void ex02(void) {
	int a = 10;
	int count = 0;

	// 1부터 a까지 다 나눠보고 약수의 개수를 셉니다.
	for (int i = 1; i <= a; i++) {
		if (a % i == 0)  count++;
	}

	// 약수가 딱 2개(1과 자기자신)면 소수!
	if (count == 2) {
		printf("O\n");
	}

	else {
		printf("X\n");
	}
}
	 
		
			


		
		
		





	

	





	void ex03(void) {


		int a = 12; // 약수를 구할 숫자

		printf("%d의 약수: ", a);

		// 1부터 a까지 모든 숫자로 나누어봅니다.
		for (int i = 1; i <= a; i++) {
			// 나머지가 0이면 i는 a의 약수입니다.
			if (a % i == 0) {
				printf("%d ", i);
			}
		}
	}

		
	 // 1이랑 자기자신인데

void ex04(void) { //12, 27 공약수 찾기
	int a = 12;
	int b = 27;
	int i = 1;

	printf("12, 27의 공약수"); // 공약수는 작은 거 따라가면 됨 12 27이면 공통인 약수는 12보다 클 수 없음
	// i= 1~12 라는 값이 들어가게 됨 
	for (i = 1; i <= a; i++) {

		if (a % i == 0 && b % i == 0) {
			printf("%d ", i);
		}
	}
}








		void ex05(void) {

			int a = 3482;
			int count = 0;

			// a가 0보다 큰 동안 계속 반복합니다.
			// 한 번 돌 때마다 a를 10으로 나눠서 일의 자리를 날려버려요!
			for (; a > 0; a = a / 10) {
				count++; // 숫자를 한 번 깎을 때마다 카운트를 하나씩 올림
				// 정수형 이라서 소수점 버려버림 

				printf("a의 자리수 %d\n", count);
				return 0;
			}
		}
	
 
		void ex06(void) { // 사이 숫자 출력하는 것 


			int num1 = 4;
			int num2 = 10;

			printf("출력\n");

			// num1부터 num2까지 1씩 증가하며 반복합니다.
			for (int i = num1; i <= num2; i++) {
				// 숫자를 출력하고 뒤에 쉼표와 공백을 붙입니다.
				printf("%d ", i);
			}
		}

		void ex07(void) {

			char k;
			char ch1 = 'b';
			char ch2 = 'i';

			for (char k = ch1; k <= ch2; k++) {
				printf("%c ", k);
			}
		}

		
		void ex08(void) { //홀수만 출력 

			int num1 = 4;
			int num2 = 10;
			int i = 1;

			for (i = num1; i <= num2; i++) {
				
				if (i % 2 == 1)
					printf("%d ", i);
			}
		

		}

		void ex09(void) { //짝수만 출력하는거 
			int num1 = 4;
			int num2 = 10;
			int i = 1;

			for (i = num1; i <= num2; i++) {

				if (i % 2 == 0) {
					printf("%d ", i);
				}
			}


		}

		void ex10(void) { // 소수만 출력하는거 
			int num1 = 4, num2 = 10;
		int exist_flag = 0; // 소수를 한 번이라도 찾았는지 체크용

		for (int i = num1; i <= num2; i++) {
			int divisor_count = 0; // i의 약수 개수를 셀 변수

			// 1. i가 소수인지 검사 (약수 개수 세기)
			for (int j = 1; j <= i; j++) {
				if (i % j == 0) divisor_count++;
			}

			// 2. 약수가 2개면 소수니까 출력!
			if (divisor_count == 2) {
				printf("%d ", i);
				exist_flag = 1; // 소수를 찾았다고 표시
			}
		}

		// 3. 반복문 다 돌았는데 flag가 여전히 0이면?
		if (exist_flag == 0) {
			printf("not exist");
		}
    }

		void ex11(void) { // 짝수만 덧셈 하는거 
			int num = 10;
			int sum = 0; // 합계를 담을 바구니 (0으로 시작)

			for (int i = 1; i <= num; i++) {
				if (i % 2 == 0) { // 짝수라면?
					sum = sum + i; // 바구니에 현재 숫자 i를 더해서 다시 저장!
				}
			}

			printf("1부터 %d까지 짝수의 합: %d\n", num, sum);
		}

		void ex12(void) {
			int num = 5;
			int result = 1; // 곱셈 바구니는 반드시 1로 시작!

			for (int i = 1; i <= num; i++) {
				result = result * i; // 계속 곱해서 누적시킴
			}

			printf("%d Factorial: %d\n", num, result);
		}
					
		void ex13(void) {
			// i는 줄 번호 (5줄부터 1줄까지 거꾸로)
			for (int i = 5; i >= 1; i--) {
				// j는 별의 개수 (i의 값만큼 별을 찍음)
				for (int j = 1; j <= i; j++) {
					printf("*");
				}
				printf("\n"); // 한 줄 찍고 줄바꿈
			}
		}

		void ex14(void) {
			

				int
				for (int i = 1; i <= n; i++) {

					for (int j = 1; j <= n - i; j++) {
						printf(" ");
					}

					for (int k = 1; k <= i; k++) {
						printf("*");
					}
					printf("\n");
				}
			}
			

				

				
			
				
			
		   
		void ex15(void) {

				int n = 4;
				for (int i = 1; i <= n; i++) {

					for (int j = 1; j <= n - i; j++) {
						printf(" ");
					}

					for (int k = 1; k <= i; k++) {
						printf("*");
					}
					printf("\n");
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
			//ex12();
			//ex13();
			//ex14();
			//ex15();
			//ex16();
		}