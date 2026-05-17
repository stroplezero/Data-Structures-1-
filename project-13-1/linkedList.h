#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int num;
	struct pointType* next; //next 라는 필드는 자신을 가리키는 포인터
} PointType;

typedef struct linkedList {
	struct pointType* head;
	int size;
}LinkedList;

extern LinkedList* createLinkedList();
extern int destroyLinkedList(LinkedList* li);
extern int isEmptyLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern LinkedList* insertFirstLinkedList(LinkedList* li, int item);
extern int printLinkedList(LinkedList* li);
extern LinkedList* insertLastLinkedList(LinkedList* li, int item);
extern LinkedList* deleteAtLinkedList(LinkedList* li, int at);
extern LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, int item);
extern PointType deleteFirstLinkedList(LinkedList* li);
extern PointType deleteLastLinkedList(LinkedList* li);
extern PointType deleteItemLinkedList(LinkedList* li, int pos);
extern LinkedList* insertAtlinkedList(LinkedList* li, int at, int item);
extern PointType getItemLinkedList(LinkedList* li, PointType* pos);
extern void replaceItemLinkedList(LinkedList* li, PointType* pos, int item);
extern PointType nextItemLinkedList(LinkedList* li, PointType* pre);
