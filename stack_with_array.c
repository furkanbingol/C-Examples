#define MAX 256
#include<stdio.h>
#include<stdlib.h>

struct stack{
	int item[MAX];
	int top;
};
typedef struct stack STACK;

void init(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void pop(STACK*,int*);
void push(STACK*,int);

int main() {
	STACK* s = (STACK*)malloc(sizeof(STACK));
	int x;
	init(s);
	push(s,50);
	push(s,150);
	pop(s,&x);
	printf("popped element: %d\n",x);
	return 0;
}

void init(STACK* s) {
	s->top = 0;
}

int isEmpty(STACK* s) {

	if(s->top == 0) {
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(STACK* s) {

	if(s->top == MAX) {
		return 1;
	}
	else{
		return 0;
	}
}

void pop(STACK* s,int* x) {

	if(isEmpty(s)) {
		printf("Stack is empty.\n");
	}
	else{
		s->top--;
		*x = s->item[s->top];
		printf("POP done.\n");
	}
}

void push(STACK* s, int x) {

	if(isFull(s)) {
		printf("Stack is full.\n");
	}
	else{
		s->item[s->top] = x;
		s->top++;
	}
}
