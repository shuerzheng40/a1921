#include "List.h"

int main(){
	LinkList *list1 = CreateList1();
	Insert(list1,1,10);
	Insert(list1,1,20);
	Delete(list1,2);
	Insert(list1,1,30);
	Insert(list1,1,40);
	printf("链表元素个数：%d\n",Size(list1));
	Print(list1);
	printf("链表的第二个元素：%d\n",GetData(list1,2));

        LinkList *list2 = CreateList2();
	Yuesefu(list2);
	

	return 0;
}
