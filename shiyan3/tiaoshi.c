#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "lianzhan.h"

int main(){
	LinkStack *S = InitStack();
	Push(S,80);
	Push(S,90);
	Pop(S);
	Push(S,70);
	printf("%d\n",GetTop(S));


char s2[500], t[1001], op;
        double s1[500];
        int top1=-1, top2=-1;
        double x, y;
        scanf("%s",t);
//      gets(t);
        for (int i=0; i<strlen(t); i++) {
                if (t[i]>='0' && t[i]<='9') {
                        double value = 0;
                        while (t[i]>='0' && t[i]<='9') {
                                value = 10*value + t[i] -'0';
                                i++;
                        }
                        if (t[i] == '.') {
                                int r = 10;
                                i++;
                                while (t[i]>='0' && t[i]<='9') {
                                        value += (t[i]-'0')/r;
                                        r = 10 * r;
                                }
                        }
                        s1[++top1] = value;
                }
                if (t[i] == ')') {
                        while (s2[top2] != '(') {
                                y = s1[top1--];
                                x = s1[top1--];
                                op = s2[top2--];
                                s1[++top1] = compute(x, y, op);
                        }
                        top2--;
                } else {
                        while (top2!=-1 && s2[top2]!='('
                          && priority(t[i])<=priority(s2[top2])) {
                                y = s1[top1--];
                                x = s1[top1--];
                                op = s2[top2--];
                                s1[++top1] = compute(x, y, op);
                        }
                        s2[++top2] = t[i];
                }
        }
        printf("%.2f\n", s1[top1]);
}
