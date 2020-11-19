#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"List.h"

#define n 11
#define m 3

LinkList* CreateList1(){
              LinkList *head;
              head = (LinkList*)malloc(sizeof(LinkList));
              head->next = NULL;
	      return head;
 }

LinkList* CreateList2(){
	LinkList *p, *q, *r;
	p = q = (LinkList*)malloc(sizeof(LinkList));
	p->data = 1;
	for(int i=2; i<=n; i++){
		r = (LinkList*)malloc(sizeof(LinkList));
		r->data = i;
		q->next = r;
		q = r;
	}
	q->next = p;
}
void Yuesefu(LinkList *L){
	LinkList *p, *q;
	int k = 0;
	q = p = L;
	while(q->next != q){
		k++;
		if(k == m){
			p->next = q->next;
			free(q);
			q = p->next;
			k = 0;
		}else{
			p = q;
			q = q->next;
		}
	}
	printf("最后一个获胜者的编号是：%d\n",q->data);
}


int Size(LinkList *L){
	 LinkList *p = L->next;
	 int k = 0;
	 while(p){
	 k++;
	 p = p->next;
	   }
	 return k;
}

void Insert(LinkList *L, int k, dataType x){
	if(k<1) exit (1) ;
	LinkList *p = L;
	int i = 0;
	while(p && i<k-1){
	p = p->next;
	i++;
	}
	 if(!p) exit(1);
	 LinkList *s = (LinkList*)malloc(sizeof(LinkList));
         s->data = x;
	 s->next = p->next;
	 p->next = s;
}

void Delete(LinkList *L, int k){
	if(k<1) exit(1);
	LinkList *p = L;
	int i =0;
	while(p && i<k-1){
	p = p->next;
	i++;
	}
	if(p->next ==NULL) exit(1);
	LinkList *q;
	q = p->next;
	p = q->next;
	free(q);
}

int Empty(LinkList *L){
	return L->next ==NULL;
}

dataType GetData(LinkList *L, int k){
	if(k<1) exit(1);
	LinkList *p = L;
	int i = 0;
	while(p && i<k){
		p = p->next;
		i++;
	}
	if(!p) exit(1);
	return p->data;
}

LinkList* Find(LinkList *L,dataType x){
	LinkList *p = L->next;
	while(p && p->data!=x)
		p = p->next;
	return p;
}

void Print(LinkList *L){
	LinkList *p = L->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

void ClearList(LinkList *L){
	LinkList *p, *q;
	p = L->next;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
}
