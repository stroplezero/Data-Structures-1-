#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdlib.h>

#include "dCLinkedList.h"

int main() {
	printf("[이중 원형 연결리스트 메뉴]\n"
		"-----------------------------------------------------------------------\n"
		"1. 맨 앞에 추가: 정수를 입력받아 리스트의 가장 앞에 삽입\n"
		"2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입\n"
		"3. 특정 위치에 추가 : 위치(index)와 정수를 입력받아 해당 위치에 삽입\n"
		"4. 특정 위치 삭제 : 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력\n"
		"5. 전체 목록 출력 : 현재 리스트에 저장된 모든 정수를 순서대로 출력\n"
		"6. 리스트 크기 확인 : 현재 저장된 노드의 총 개수를 출력\n"
		"-----------------------------------------------------------------------\n"
		"0. 종료 : 모든 메모리를 해제(destroy)하고 프로그램을 종료\n"
		"-----------------------------------------------------------------------\n");

	int menuNum = 0;
	DCLinkedList* myDCLinkedList = createDCLinkedList();

	int check = 1;

	while (check) {
		printf("[이중 원형 연결리스트 메뉴] 번호 입력: ");
		scanf("%d", &menuNum);
		while (getchar() != '\n');

		int newNum = 0;
		int pos = 0;

		if (menuNum < 0 || menuNum > 6) {
			printf("0~6의 정수를 입력해주세요.\n");
		}
		else {
			switch (menuNum) {
			case(1):
				printf("1. [맨 앞에 추가] 정수 입력: ");
				scanf("%d", &newNum);
				while (getchar() != '\n');
				insertFirstDCLinkedList(myDCLinkedList, newNum);

				break;

			case(2):
				printf("2. [맨 뒤에 추가] 정수 입력: ");
				scanf("%d", &newNum);
				while (getchar() != '\n');
				insertLastDCLinkedList(myDCLinkedList, newNum);

				break;

			case(3):
				printf("3. [특정 위치에 추가] 위치, 정수 입력(예: 2, 10): ");
				scanf("%d, %d", &pos, &newNum);
				while (getchar() != '\n');
				insertAtDCLinkedList(myDCLinkedList, pos, newNum);

				break;

			case(4):
				printf("4. [특정 위치 삭제] 위치 입력: ");
				scanf("%d", &pos);
				while (getchar() != '\n');
				deleteAtDCLinkedList(myDCLinkedList, pos);

				break;

			case(5):
				printf("5. [전체 목록 출력]\n");
				printDCLinkedList(myDCLinkedList);

				break;

			case(6):
				printf("6. [리스트 크기 확인]\n");
				printf("size: %d\n", sizeDCLinkedList(myDCLinkedList));

				break;

			case(0):
				printf("0. [종료] ");
				int i = destroyDCLinkedList(myDCLinkedList);

				if (i == 1) {
					printf("모든 메모리 해제 완료.\n");
					check = 0;
				}
				else {
					printf("모든 메모리 해제 실패.\n");
				}

				break;
			}
		}
	}
}
