#include "lianzhan.h"
#include <stdlib.h>
LinkStack* InitStack(){
	LinkStack *t = (LinkStack*)malloc(sizeof(LinkStack));
	t->next = NULL;
	return t;
}

int Empty(LinkStack *S){
	return S->next == NULL;
}

void Push(LinkStack *S, dataType x){
	LinkStack *t = (LinkStack*)malloc(sizeof(LinkStack));
	t->data = x;
	t->next = S->next;
	S->next = t;
}

void Pop(LinkStack *S){
	if(Empty(S)) exit(1);
	LinkStack *p = S->next;
	S->next = p->next;
	free(p);
}

dataType GetTop(LinkStack *S){
	return S->next->data;
}

int priority(char x) {
        switch (x) {
                case'+':
                case'-':
                case'=':return 1;
                case'*':
                case'/': return 2;
                case'(': return 3;
        }
}
double compute (double x, double y, char op) {
        switch (op) {  
                case '+': return x + y;
                case '-': return x - y;
                case '*': return x * y;
                case '/': return x / y;
        }
}

