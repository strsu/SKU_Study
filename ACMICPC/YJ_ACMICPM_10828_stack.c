/*
	# 스택(10828번)
		Author	: 박영재
		Date	: 17.9.8, 11:28 am ~
*/

#include <stdio.h>
#include <stdlib.h>

int push(int *stack, int *top, int value);
int pop(int *stack, int *top);
int size(int *top);
int empty(int *top);
int Top(int *stack, int *top);

int main()
{
	int num, value, i;
	int top = -1;
	// stack의 개수만큼만 입력가능
	int count = 0;
	int *stack;
	// 출력할 값을 저장하는 변수
	int *tmp;
	char sel[10];
	scanf("%d", &num);
	if (num < 1 || num > 10000) return;
	stack = (int *)malloc(sizeof(int)*num);
	tmp = (int *)malloc(sizeof(int)*num);
	
	while (count != num) {
		scanf("%s", sel);
		if (strcmp("push", sel) == 0) {
			scanf("%d", &value);
			// push는 원래 반환값이 없으나 출력의 편의를 위해 -2를 리턴
			tmp[count] = push(stack, &top, value);
		}
		else if (strcmp("pop", sel) == 0) {
			tmp[count] = pop(stack, &top);
		}
		else if (strcmp("size", sel) == 0) {
			tmp[count] = size(&top);
		}
		else if (strcmp("empty", sel) == 0) {
			tmp[count] = empty(&top);
		}
		else if (strcmp("top", sel) == 0) {
			tmp[count] = Top(stack, &top);
		}
		count++;
	}

	for (i = 0; i < count; i++) {
		if (tmp[i] == -2) {
			// -2값은 push 명령어 이므로 출력하지 않는다.
		}
		else {
			printf("%d\n", tmp[i]);
		}
	}
	
}

int push(int *stack, int *top, int value)
{
	(*top)++;
	stack[*top] = value;
	// -2를 리턴하여 출력하지 않게끔 한다
	return -2;
}
int pop(int *stack, int *top)
{
	if (*top == -1) {
		return *top;
	}
	else {
		return stack[(*top)--];
	}
}
int size(int *top)
{
	return (*top + 1);
}
int empty(int *top)
{
	if (*top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int Top(int *stack, int *top)
{
	if (*top == -1) {
		return *top;
	}
	else {
		return stack[*top];
	}
}
