#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	struct pointType* prev;
	int num;
	struct pointType* next; //next 라는 필드는 자신을 가리키는 포인터
} PointType;

typedef struct dCLinkedList {
	struct pointType *head;
	int size;
}DCLinkedList;

extern DCLinkedList* createDCLinkedList();
extern int destroyDCLinkedList(DCLinkedList* li);
extern int isEmptyDCLinkedList(DCLinkedList* li);
extern int sizeDCLinkedList(DCLinkedList* li);
extern DCLinkedList* insertFirstDCLinkedList(DCLinkedList* li, int item);
extern DCLinkedList* insertLastDCLinkedList(DCLinkedList* li, int item);
extern DCLinkedList* insertItemDCLinkedList(DCLinkedList* li, PointType* pre, int item);
extern PointType deleteFirstDCLinkedList(DCLinkedList* li);
extern PointType deleteLastDCLinkedList(DCLinkedList* li);
extern PointType deleteItemDCLinkedList(DCLinkedList* li, int pos);
extern DCLinkedList* insertAtDCLinkedList(DCLinkedList* li, int at, int item);
extern DCLinkedList* deleteAtDCLinkedList(DCLinkedList* li, int at);
extern PointType getItemDCLinkedList(DCLinkedList* li, PointType* pos);
extern void replaceItemDCLinkedList(DCLinkedList* li, PointType* pos, int item);
extern PointType nextItemLinkedList(DCLinkedList* li, PointType* pre);
extern int printDCLinkedList(DCLinkedList* li);
