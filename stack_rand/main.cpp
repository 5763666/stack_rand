#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10 // 스택의 최대 크기

typedef int element; // 데이터의 자료형
element stack[MAX_STACK_SIZE]; // 1차원 배열
int top = -1;  //초기화

// 공백 상태 검출 함수
int is_empty() { return (top == -1); }

// 포화 상태 검출 함수
int is_full() {	return (top == (MAX_STACK_SIZE - 1)); }

// 삽입 함수 : 짝수
void push(element item) { 
	if (is_full()) {
		fprintf(stderr, "Stack Empty!\n");
		return; 
	}
	else stack[++top] = item;
}

// 삭제 함수 : 홀수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "Stack Full!\n");
		return 0;
	}
	else return stack[top--];
}

int main(void) {
	printf("-----Using array-----\n");
	srand((unsigned int)time(NULL));

	for(int i =0; i<=30; i++){
		if (i < 10) printf("[ %d] ", i);
		else printf("[%d] ", i);

		int rand_num = rand() % 100 + 1;
		

		if (rand_num % 2 == 0) {
			push(rand_num);
			printf("Push %d\n",rand_num);
		}
		else {
			printf("Pop %d\n", pop());
		}
	}

	return 0;
}