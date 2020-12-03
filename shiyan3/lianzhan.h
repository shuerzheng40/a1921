#ifndef lianzhan_h
#define lianzhan_h

typedef int dataType;
typedef struct node{
	dataType data;
	struct node *next;
}LinkStack;

LinkStack* InitStack();                 					//初始化链栈
int Empty(LinkStack *S);   							//判断栈是否为空
void Push(LinkStack *S, dataType x);   					//元素 x 进栈
void Pop(LinkStack *S);    							//出栈
dataType GetTop(LinkStack *S);
int priority(char x);
double compute(double x, double y, char op);


#endif
